#!/usr/bin/env python3
"""Importa traducciones oficiales de Crystal en los textos telefónicos de HnS.

El importador compara cada párrafo inglés de HnS con los bloques equivalentes
del disassembly inglés y recupera la traducción del disassembly español.
"""

from __future__ import annotations

import argparse
import difflib
import re
import subprocess
import textwrap
from pathlib import Path


LABEL_RE = re.compile(r"^([A-Za-z0-9_]+):$")
TEXT_RE = re.compile(r'\s*(text|line|cont|para)\s+"(.*)"')
HNS_BLOCK_RE = re.compile(
    r"^(MatchCall_HNS_[A-Za-z0-9_]+)::\n(.*?)(?=^MatchCall_HNS_|\Z)",
    re.MULTILINE | re.DOTALL,
)


def parse_crystal_blocks(path: Path) -> dict[str, list[str]]:
    blocks: dict[str, list[str]] = {}
    label: str | None = None
    paragraphs: list[str] = []
    current = ""

    for raw_line in path.read_text(encoding="utf-8").splitlines() + ["__END__:"]:
        match = LABEL_RE.match(raw_line)
        if match:
            if label is not None:
                if current.strip():
                    paragraphs.append(current.strip())
                blocks[label] = paragraphs
            label = match.group(1)
            paragraphs = []
            current = ""
            continue
        if label is None:
            continue

        match = TEXT_RE.match(raw_line)
        if match:
            operation, value = match.groups()
            if operation == "para":
                if current.strip():
                    paragraphs.append(current.strip())
                current = value
            elif operation in ("line", "cont"):
                current += " " + value
            else:
                current += value
        elif "text_ram wStringBuffer4" in raw_line:
            current += "{STR_VAR_3}"
        elif "text_ram wStringBuffer5" in raw_line:
            current += "{STR_VAR_5}"

    return blocks


def parse_hns_blocks(contents: str) -> dict[str, list[str]]:
    blocks: dict[str, list[str]] = {}
    for match in HNS_BLOCK_RE.finditer(contents):
        text = "".join(re.findall(r'\.string "(.*)"', match.group(2)))
        text = text.rstrip("$").replace(r"\n", " ").replace(r"\l", " ")
        blocks[match.group(1)] = text.split(r"\p")
    return blocks


def normalize(text: str) -> str:
    replacements = {
        "#mon": "pokemon",
        "<player>": "player",
        "<play_g>": "player",
        "{player}": "player",
        "{str_var_3}": "pokemon",
        "{str_var_5}": "place",
    }
    text = text.lower()
    for source, target in replacements.items():
        text = text.replace(source, target)
    return re.sub(r"[^a-z0-9]+", " ", text).strip()


def candidate_ranges(paragraphs: list[str]):
    for start in range(len(paragraphs)):
        for length in range(1, min(5, len(paragraphs) - start + 1)):
            yield start, length, " ".join(paragraphs[start : start + length])


def split_sentences(text: str) -> list[str]:
    return [
        sentence.strip()
        for sentence in re.split(r"(?<=[.!?…])\s+", text.strip())
        if sentence.strip()
    ]


def sentence_catalog(
    english: dict[str, list[str]], spanish: dict[str, list[str]]
) -> list[tuple[str, str, str]]:
    catalog: list[tuple[str, str, str]] = []
    for label, source_paragraphs in english.items():
        if label not in spanish:
            continue
        source_sentences = split_sentences(" ".join(source_paragraphs))
        translated_sentences = split_sentences(" ".join(spanish[label]))
        if len(source_sentences) != len(translated_sentences):
            continue
        catalog.extend(zip([label] * len(source_sentences), source_sentences, translated_sentences))
    return catalog


def load_tree(root: Path) -> dict[str, list[str]]:
    blocks: dict[str, list[str]] = {}
    for path in (root / "data" / "phone" / "text").glob("*.asm"):
        blocks.update(parse_crystal_blocks(path))
    return blocks


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--english", type=Path, required=True)
    parser.add_argument("--spanish", type=Path, required=True)
    parser.add_argument("--hns", type=Path, required=True)
    parser.add_argument("--limit", type=int, default=0)
    parser.add_argument("--only-below", type=float, default=1.01)
    parser.add_argument("--write", action="store_true")
    parser.add_argument("--threshold", type=float, default=0.84)
    parser.add_argument("--source-revision")
    parser.add_argument("--pending", action="store_true")
    args = parser.parse_args()

    english = load_tree(args.english)
    spanish = load_tree(args.spanish)
    if args.source_revision:
        source_contents = subprocess.check_output(
            ["git", "show", f"{args.source_revision}:data/text/match_call_hns.inc"],
            cwd=args.hns.parents[2],
            text=True,
            encoding="utf-8",
        )
    else:
        source_contents = args.hns.read_text(encoding="utf-8")
    hns = parse_hns_blocks(source_contents)
    catalog = sentence_catalog(english, spanish)
    shown = 0
    untranslated: list[tuple[str, str, float]] = []
    translated_blocks: dict[str, list[str]] = {}

    for hns_label, paragraphs in hns.items():
        trainer = hns_label.removeprefix("MatchCall_HNS_").split("_", 1)[0]
        trainer_catalog = [entry for entry in catalog if entry[0].startswith(trainer)]
        heading_printed = False
        translated_paragraphs = []
        for paragraph in paragraphs:
            translated_parts = []
            for hns_sentence in split_sentences(paragraph):
                generic = translate_generic(hns_sentence)
                if generic is not None:
                    translated_parts.append(generic)
                    continue
                candidates = []
                for label, source, translated in trainer_catalog or catalog:
                    score = difflib.SequenceMatcher(
                        None, normalize(hns_sentence), normalize(source)
                    ).ratio()
                    candidates.append((score, label, source, translated))
                score, label, source, translated = max(candidates)
                if score >= args.threshold:
                    translated_parts.append(clean_translation(translated))
                else:
                    translated_parts.append(hns_sentence)
                    untranslated.append((hns_label, hns_sentence, score))
                if score >= args.only_below:
                    continue
                if not heading_printed:
                    print(f"\n{hns_label}")
                    heading_printed = True
                print(f"  {score:.3f} {label}")
                print(f"    HNS: {hns_sentence}")
                print(f"    EN : {source}")
                print(f"    ES : {translated}")
            translated_paragraphs.append(" ".join(translated_parts))
        translated_blocks[hns_label] = translated_paragraphs
        shown += 1
        if args.limit and shown >= args.limit:
            break

    if args.write:
        contents = source_contents
        contents = HNS_BLOCK_RE.sub(
            lambda match: render_hns_block(
                match.group(1), translated_blocks[match.group(1)]
            ),
            contents,
        )
        contents = contents.rstrip() + "\n"
        args.hns.write_text(contents, encoding="utf-8", newline="\n")
        print(f"\nImportados: {sum(len(v) for v in translated_blocks.values())} párrafos")
        print(f"Pendientes de traducción manual: {len(untranslated)} frases")
    if args.pending:
        for label, sentence, score in untranslated:
            print(f"{label}\t{score:.3f}\t{sentence}")


def translate_generic(text: str) -> str | None:
    exact = {
        "Hi, {PLAYER}!": "¡Hola, {PLAYER}!",
        "Hey, {PLAYER}!": "¡Hola, {PLAYER}!",
        "Hey there, {PLAYER}!": "¡Hola, {PLAYER}!",
        "Hello, {PLAYER}!": "¡Hola, {PLAYER}!",
        "Hello, {PLAYER}.": "Hola, {PLAYER}.",
        "Uh, hello, {PLAYER}?": "Eh, ¿hola, {PLAYER}?",
        "I was waiting for you.": "Te estaba esperando.",
        "Let's battle!": "¡Luchemos!",
        "How are your POKéMON doing?": "¿Qué tal están tus POKéMON?",
        "How're you doing?": "¿Qué tal estás?",
        "Oh yeah, we KO'd a wild {STR_VAR_3} with one hit a while back.": "Hace poco derrotamos de un golpe a un {STR_VAR_3} salvaje.",
        "It went down so easily, I felt a little sorry for the poor thing.": "Cayó con tanta facilidad que sentí pena por el pobre.",
        "I'll be waiting on ROUTE 31.": "Te esperaré en la RUTA 31.",
        "How's the fishing?": "¿Qué tal va la pesca?",
        "Listen to this!": "¡Escucha esto!",
        "Me, I take my {STR_VAR_3} to the POKéMON CENTER in VIOLET every day,": "Yo llevo cada día a mi {STR_VAR_3} al CENTRO POKéMON de CIUDAD MALVA,",
        "so it's doing just fantastic!": "¡así que está fenomenal!",
        "Don't you think FALKNER of VIOLET GYM is cool and handsome?": "¿No te parece que PEGASO, del GIMNASIO de CIUDAD MALVA, es guapo y genial?",
        "But they say his dad, who's out training on the road, is even more cool and handsome than FALKNER.": "Pero dicen que su padre, que está entrenando por ahí, es aún más guapo y genial que PEGASO.",
        "I wish I could meet him!": "¡Ojalá pudiera conocerlo!",
        "What's up?": "¿Qué tal?",
        "I do all sorts of things, like leaving them in DAY-CARE and": "Hago de todo, como dejarlos en la GUARDERÍA y",
        "toughening them up with items.": "fortalecerlos con objetos.",
        "It's your pal, IRWIN!": "¡Soy tu amigo IRWIN!",
        "I saw the most amazing battle the other day!": "¡El otro día vi un combate increíble!",
        "I wish I could battle like that.": "Ojalá pudiera combatir así.",
        "Oh wait, I can!": "¡Un momento, sí puedo!",
        "I just need someone to battle!": "¡Solo necesito un rival!",
        "How's it going?": "¿Qué tal va todo?",
        "{PLAYER}, are you raising your POKéMON properly?": "{PLAYER}, ¿estás criando bien a tus POKéMON?",
        "I read in a book that you should raise any POKéMON you catch with love and care.": "He leído que debes criar con cariño y cuidado a todos los POKéMON que captures.",
        "I'm waiting on ROUTE 38!": "¡Te espero en la RUTA 38!",
        "Why don't you come to ROUTE 36 and pick it up?": "¿Por qué no vienes a la RUTA 36 y te lo llevas?",
        "You know PROF.": "Ya conoces al PROF.",
        "OAK, so of course your POKéMON are fine!": "OAK, ¡así que seguro que tus POKéMON están bien!",
        "My POKéMON are doing well too.": "Los míos también están bien.",
        "But then, I am trying to become a POKéMON professor.": "Claro que intento convertirme en profesor POKéMON.",
        "I recently began observing wild {STR_VAR_3}.": "Hace poco empecé a observar a los {STR_VAR_3} salvajes.",
        "I've been learning all sorts of new things through my observations.": "Gracias a mis observaciones estoy aprendiendo todo tipo de cosas.",
        "I wish I could become a POKéMON researcher like PROF.": "Ojalá pronto pueda ser investigador POKéMON como el PROF.",
        "OAK soon.": "OAK.",
        "I'm going to study hard so PROF.": "¡Voy a estudiar mucho para que el PROF.",
        "OAK will make me his assistant!": "OAK me haga su ayudante!",
        "I'm on ROUTE 39.": "Estoy en la RUTA 39.",
        "Come pick it up!": "¡Ven a recogerlo!",
        "I'll be waiting on ROUTE 42.": "Te esperaré en la RUTA 42.",
        "Oh yeah, I saw you coming out of a POKéMON CENTER the other day.": "El otro día te vi salir de un CENTRO POKéMON.",
        "You heal your POKéMON regularly, don't you?": "Curas a tus POKéMON a menudo, ¿verdad?",
        "I'm impressed.": "Me has impresionado.",
        "Heh, my {STR_VAR_3} is so tough, it doesn't need to go to POKéMON CENTERS often.": "Je, mi {STR_VAR_3} es tan fuerte que apenas necesita ir al CENTRO POKéMON.",
        "Heheh!": "¡Je, je!",
        "My {STR_VAR_3} looks like it will get tough enough": "Parece que mi {STR_VAR_3} será lo bastante fuerte",
        "to face and beat the legendary bird POKéMON!": "¡para enfrentarse a las aves legendarias y vencerlas!",
        "We beat a wild {STR_VAR_3}…": "Hemos vencido a un {STR_VAR_3} salvaje…",
        "You know, I have more fun fishing than beating wild POKéMON.": "La verdad, me divierte más pescar que vencer POKéMON salvajes.",
        "Come pick it up on ROUTE 44.": "Ven a recogerlo en la RUTA 44.",
        "Catch up to me on ROUTE 27, and I'll let you have it.": "Búscame en la RUTA 27 y te lo daré.",
        "This is KENJI!": "¡Soy KENJI!",
        "I'm taking a break!": "¡Estoy descansando!",
        "I'm taking a break from training.": "Estoy descansando del entrenamiento.",
        "I found something good.": "He encontrado algo bueno.",
        "Come get it if you want!": "¡Ven a por ello si lo quieres!",
        "I'll be at NATIONAL PARK.": "Estaré en el PARQUE NACIONAL.",
        "My regal POKéMON grow sharper by the day.": "Mis majestuosos POKéMON mejoran cada día.",
        "{STR_VAR_3} is getting really tough!": "¡{STR_VAR_3} se está volviendo muy fuerte!",
        "I heard other regions have kings and queens.": "He oído que otras regiones tienen reyes y reinas.",
        "Why doesn't KANTO have": "¿Por qué KANTO no tiene",
        "any royalty?": "realeza?",
        "My regal POKéMON are ready for a rematch!": "¡Mis majestuosos POKéMON están listos para la revancha!",
        "Come to ROUTE 13!": "¡Ven a la RUTA 13!",
        "CYCLING ROAD is the best.": "La RUTA CICLISTA es lo mejor.",
        "Nothing beats the wind in your face.": "No hay nada como sentir el viento en la cara.",
        "{STR_VAR_3} loves the speed too!": "¡A {STR_VAR_3} también le encanta la velocidad!",
        "You JOHTO kids aren't bad.": "Los chavales de JOHTO no sois malos.",
        "Maybe I misjudged you.": "Quizá te juzgué mal.",
        "Don't let it go to your head though!": "¡Pero no dejes que se te suba a la cabeza!",
        "Get down to CYCLING ROAD!": "¡Ven a la RUTA CICLISTA!",
        "I want a rematch!": "¡Quiero la revancha!",
        "Did you know POKéMON get friendlier when you train in memorable places?": "¿Sabías que los POKéMON se encariñan más si entrenáis en lugares memorables?",
        "{STR_VAR_3} seems to like it here.": "Parece que a {STR_VAR_3} le gusta este lugar.",
        "Some POKéMON moves are stronger when your": "Algunos movimientos son más fuertes cuando tu",
        "POKéMON feels more friendly toward you!": "¡POKéMON siente más cariño por ti!",
        "My friends are ready for battle!": "¡Mis amigos están listos para combatir!",
        "Come see on ROUTE 14!": "¡Ven a vernos a la RUTA 14!",
        "Who is this?!": "¡¿Quién eres?!",
        "I called you?": "¿Te he llamado yo?",
        "This is KYLE.": "Soy KYLE.",
        "Don't forget!": "¡No lo olvides!",
        "The secrets of fishing?": "¿Los secretos de la pesca?",
        "I've reeled in some tough new POKéMON!": "¡He pescado nuevos POKéMON muy fuertes!",
        "Come to ROUTE 12 for a battle!": "¡Ven a combatir a la RUTA 12!",
        "Hi there, {PLAYER}!": "¡Hola, {PLAYER}!",
        "I've been collecting rare starter POKéMON.": "He estado reuniendo POKéMON iniciales raros.",
        "My {STR_VAR_3} is my newest pride and joy!": "¡Mi {STR_VAR_3} es mi nuevo orgullo!",
        "Did you know there are starter POKéMON from many different regions?": "¿Sabías que hay POKéMON iniciales de muchas regiones?",
        "I want to collect them all!": "¡Quiero reunirlos a todos!",
        "I have new starters to show off!": "¡Tengo nuevos iniciales que enseñarte!",
        "Come to ROUTE 14!": "¡Ven a la RUTA 14!",
        "It's TEACHER HILLARY.": "Soy la PROFESORA HILLARY.",
        "Why aren't you in school?": "¿Por qué no estás en clase?",
        "Are you playing games instead of doing homework?": "¿Estás jugando en vez de hacer los deberes?",
        "My POKéMON have graduated to the next level!": "¡Mis POKéMON han pasado al siguiente nivel!",
        "Come test us on ROUTE 15!": "¡Ven a ponernos a prueba en la RUTA 15!",
        "VIRIDIAN FOREST is full of cool bugs!": "¡El BOSQUE VERDE está lleno de BICHOS geniales!",
        "I saw a BUG TYPE GYM LEADER in VIRIDIAN FOREST!": "¡Vi a un LÍDER de tipo BICHO en el BOSQUE VERDE!",
        "My bug team is stronger than ever!": "¡Mi equipo de tipo BICHO es más fuerte que nunca!",
        "Come to ROUTE 2 for a rematch!": "¡Ven a la RUTA 2 para la revancha!",
        "The waves are great today!": "¡Hoy hay unas olas estupendas!",
        "My POKéMON love swimming in the open sea.": "A mis POKéMON les encanta nadar en alta mar.",
        "{STR_VAR_3} is getting so fast!": "¡{STR_VAR_3} se está volviendo rapidísimo!",
        "Swimming with POKéMON is the best exercise.": "Nadar con POKéMON es el mejor ejercicio.",
        "My water POKéMON are raring to battle!": "¡Mis POKéMON de tipo AGUA están deseando combatir!",
        "Come to ROUTE 20!": "¡Ven a la RUTA 20!",
        "I've been studying battle strategies in class.": "He estudiado estrategias de combate en clase.",
        "{STR_VAR_3} and I have been practicing them!": "¡{STR_VAR_3} y yo las hemos practicado!",
        "Tests are coming up, but I'd rather be battling.": "Se acercan los exámenes, pero prefiero combatir.",
        "Book smarts aren't everything, right?": "Saber de libros no lo es todo, ¿verdad?",
        "I learned some new tricks!": "¡He aprendido algunos trucos nuevos!",
        "Come to ROUTE 15!": "¡Ven a la RUTA 15!",
        "Were all mountains really shaped by oceans and rivers?": "¿De verdad los mares y los ríos dieron forma a todas las montañas?",
        "It's KENNY here.": "Soy KENNY.",
        "I visited the PEWTER museum!": "¡He visitado el museo de CIUDAD PLATEADA!",
        "Did you know the entire KANTO region was once under water?": "¿Sabías que toda la región de KANTO estuvo bajo el agua?",
        "I've trained hard in the mountains!": "¡He entrenado duro en las montañas!",
        "Come to ROUTE 13 for a battle!": "¡Ven a combatir a la RUTA 13!",
        "I've been working on looking cool in battle.": "He practicado para lucirme en combate.",
        "{STR_VAR_3} has some flashy new moves!": "¡{STR_VAR_3} tiene nuevos movimientos muy vistosos!",
        "There was an accident on CYCLING ROAD.": "Ha habido un accidente en la RUTA CICLISTA.",
        "Being safe is the coolest thing you can be.": "No hay nada más genial que ir con cuidado.",
        "I look AND fight cool now!": "¡Ahora luzco bien Y combato con estilo!",
        "Come to CYCLING ROAD!": "¡Ven a la RUTA CICLISTA!",
        "I was something of a heartbreaker in UNOVA.": "En TESELIA era todo un rompecorazones.",
        "Now I'm a highway star!": "¡Ahora soy la estrella de la carretera!",
        "CYCLING ROAD at night is something else.": "La RUTA CICLISTA de noche es otra cosa.",
        "The streetlights and the wind…": "Las farolas y el viento…",
        "it's freedom!": "¡eso es libertad!",
        "The highway stars want revenge!": "¡Las estrellas de la carretera quieren revancha!",
    }
    if text in exact:
        return exact[text]
    match = re.fullmatch(r"It's ([A-Z]+)([!.])", text)
    if match:
        punctuation = "!" if match.group(2) == "!" else "."
        return f"¡Soy {match.group(1)}{punctuation}" if punctuation == "!" else f"Soy {match.group(1)}."
    match = re.fullmatch(r"(?:This is )?([A-Z]+) here([.!])", text)
    if match:
        return f"Soy {match.group(1)}{match.group(2)}"
    return None


def clean_translation(text: str) -> str:
    text = text.replace("Â", "")
    text = re.sub(r"(?<=\w)- (?=\w)", "", text)
    text = text.replace("@{STR_VAR_3}", "{STR_VAR_3}")
    text = text.replace("@{STR_VAR_5}", "{STR_VAR_5}")
    text = text.replace("#- MON", "POKéMON").replace("#MON", "POKéMON")
    text = text.replace("<PLAYER>", "{PLAYER}").replace("<PLAY_G>", "{PLAYER}")
    return text.replace("@", "").strip()


def render_hns_block(label: str, paragraphs: list[str]) -> str:
    output = [f"{label}::"]
    for paragraph_index, paragraph in enumerate(paragraphs):
        lines = textwrap.wrap(
            paragraph,
            width=32,
            break_long_words=False,
            break_on_hyphens=False,
        ) or [""]
        for line_index, line in enumerate(lines):
            is_last_line = line_index == len(lines) - 1
            is_last_paragraph = paragraph_index == len(paragraphs) - 1
            if is_last_line:
                suffix = "$" if is_last_paragraph else r"\p"
            elif line_index == 0:
                suffix = r"\n"
            else:
                suffix = r"\l"
            output.append(f'\t.string "{line}{suffix}"')
        if paragraph_index != len(paragraphs) - 1:
            output.append("")
    return "\n".join(output) + "\n\n"


if __name__ == "__main__":
    main()
