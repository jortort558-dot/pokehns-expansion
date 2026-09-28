#!/usr/bin/env python3
"""Sustituye descripciones por el texto oficial completo y lo ajusta sin omitir palabras."""

import json
import re
import subprocess
import sys
import textwrap
from pathlib import Path

from auditar_descripciones_objetos import ITEM_START_RE, extract_parenthesized

REPO = Path(__file__).resolve().parents[1]
WIDTH = 25
ABBREVIATIONS = {
    "antigua": "ant.", "antiguo": "ant.", "valiente": "val.",
    "cataclismo": "catacl.", "lamentable": "lament.",
    "Pokémon": "Pok.", "movimientos": "movs.", "movimiento": "mov.",
    "características": "caract.", "característica": "caract.",
    "aumenta": "aum.", "restaura": "rest.", "permite": "perm.",
    "utilizar": "usar", "utilizarse": "usarse", "determinados": "dets.",
    "determinado": "det.", "especialmente": "espec.",
    "elaboradas": "elab.", "entregaban": "entreg.", "ofrenda": "ofr.",
    "Cosechas": "Cosech.", "gratitud": "grat.",
    "construido": "constr.", "construida": "constr.", "Dinamax": "Dinam.",
    "Vespiquen": "Vespiq.", "suaviza": "suav.", "También": "Tb.",
    "también": "tb.", "efecto": "ef.", "Revivir": "Rev.", "Máximo": "Máx.",
    "restaura": "rest.", "completamente": "compl.", "problemas": "probl.",
    "medicinal": "med.", "medicinales": "med.", "rendimiento": "rend.",
    "especial": "esp.", "especiales": "esp.", "durante": "dur.",
    "combate": "comb.", "Pokécubos": "Pokéc.", "caramelos": "caram.",
    "probabilidad": "prob.", "fragmento": "frag.", "cristal": "crist.",
    "debilitarse": "debil.", "Teracristal": "Terac.",
    "resistente": "resist.", "general": "gral.", "Puede": "P.",
    "puede": "p.", "veces": "vcs.", "quiera": "qra.",
    "cambiar": "camb.", "aspecto": "asp.", "dinamaxizarse": "dinamax.",
    "todas": "todas", "características": "caract.",
    "fertilizante": "fert.", "cultivo": "cult.", "Parece": "Parece",
    "asienta": "asent.", "región": "reg.",
    "llamado": "llam.", "determinadas": "dets.", "accesorios": "acces.",
    "cierto": "cto.",
}


def wrap(text: str) -> list[str]:
    lines = textwrap.wrap(text, width=WIDTH, break_long_words=False, break_on_hyphens=False)
    if len(lines) <= 6:
        return lines
    words = text.split()
    for source, target in ABBREVIATIONS.items():
        words = [target + word[len(source):] if word.startswith(source) else word for word in words]
        lines = textwrap.wrap(" ".join(words), width=WIDTH, break_long_words=False, break_on_hyphens=False)
        if len(lines) <= 6:
            return lines
    # Último recurso: abrevia, de una en una, las palabras más largas. No se
    # elimina ninguna parte de la frase ni ningún concepto.
    for index in sorted(range(len(words)), key=lambda i: len(words[i]), reverse=True):
        word = words[index]
        suffix = ""
        while word and word[-1] in ".,;:!?":
            suffix = word[-1] + suffix
            word = word[:-1]
        if len(word) > 8:
            words[index] = word[:6] + "." + suffix
            lines = textwrap.wrap(" ".join(words), width=WIDTH, break_long_words=False, break_on_hyphens=False)
            if len(lines) <= 6:
                return lines
    for index in sorted(range(len(words)), key=lambda i: len(words[i]), reverse=True):
        word = words[index]
        suffix = ""
        while word and word[-1] in ".,;:!?":
            suffix = word[-1] + suffix
            word = word[:-1]
        if len(word) > 5:
            words[index] = word[:3] + "." + suffix
            lines = textwrap.wrap(" ".join(words), width=WIDTH, break_long_words=False, break_on_hyphens=False)
            if len(lines) <= 6:
                return lines
    return lines


def expression(text: str) -> str:
    lines = wrap(text)
    if len(lines) > 6:
        raise ValueError(f"La descripción necesita {len(lines)} líneas: {text}")
    body = "\n".join(f'            "{line}{"\\n" if i + 1 < len(lines) else ""}"' for i, line in enumerate(lines))
    return f"COMPOUND_STRING(\n{body})"


def main() -> None:
    path = REPO / "src/data/items.h"
    if "--restore-from-head" in sys.argv:
        files = [
            "src/data/items.h", "src/item_menu.c", "src/shop.c", "src/player_pc.c",
            "src/battle_pyramid_bag.c", "src/pokemon_storage_system.c",
        ]
        for relative in files:
            original = subprocess.run(
                ["git", "show", f"HEAD:{relative}"], cwd=REPO, check=True, capture_output=True
            ).stdout
            (REPO / relative).write_bytes(original)
        print("Archivos de la prueba restaurados desde HEAD")
        return
    source = path.read_text(encoding="utf-8")
    official = json.loads((REPO / "tools/item_descriptions_official_es.json").read_text(encoding="utf-8"))
    starts = list(ITEM_START_RE.finditer(source))
    replacements = []
    for index, match in enumerate(starts):
        item = match.group(1)
        if item not in official:
            continue
        end = starts[index + 1].start() if index + 1 < len(starts) else len(source)
        block = source[match.end():end]
        found = re.search(r"\.description\s*=\s*", block)
        if not found:
            continue
        value_start = match.end() + found.end()
        remainder = source[value_start:end]
        compound = re.match(r"COMPOUND_STRING\s*\(", remainder)
        if compound:
            open_pos = value_start + compound.end() - 1
            inner = extract_parenthesized(source, open_pos)
            if inner is None:
                raise ValueError(item)
            value_end = open_pos + len(inner) + 2
        else:
            ref = re.match(r"\w+", remainder)
            if not ref:
                raise ValueError(item)
            value_end = value_start + ref.end()
        replacements.append((value_start, value_end, expression(official[item])))
    for start, end, value in reversed(replacements):
        source = source[:start] + value + source[end:]
    path.write_text(source, encoding="utf-8")
    print(f"Descripciones oficiales aplicadas: {len(replacements)}")


if __name__ == "__main__":
    main()
