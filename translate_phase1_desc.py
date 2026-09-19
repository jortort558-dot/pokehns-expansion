#!/usr/bin/env python3
"""
translate_phase1_desc.py - Traducciones Fase 1 (Descripciones + Mensajes de Combate)
Traduce descripciones de movimientos, habilidades, objetos y mensajes de batalla.

Uso:
    python3 translate_phase1_desc.py [ruta_proyecto] [--dry-run]

IMPORTANTE sobre límites de caja de texto GBA:
    - Cada línea: ~22-26 caracteres (fuente proporcional, orientativo)
    - Salto de línea: \\n (dentro del mismo cuadro)
    - Nueva caja: \\p (espera pulsación de A)
    - Scroll: \\l
    - Descripciones de movimientos: 2 líneas
    - Descripciones de habilidades: 2-3 líneas
    - Descripciones de objetos: 3 líneas
"""

import re
import os
import sys
import shutil
from datetime import datetime


def backup_file(filepath):
    bak = filepath + ".bak_desc_" + datetime.now().strftime("%Y%m%d_%H%M%S")
    shutil.copy2(filepath, bak)
    return bak



# =====================================================================
# DESCRIPCIONES DE MOVIMIENTOS
# Formato: 2 líneas separadas por \\n, ~22 chars por línea
# =====================================================================
MOVE_DESCRIPTIONS = {
    # ── GEN 1 ──
    "Attack that makes the\\nfoe flinch.":
        "Ataca y puede hacer\\nretroceder al rival.",
    "A karate chop that has\\na high critical-hit ratio.":
        "Golpe karate con alta\\ntasa de golpe crítico.",
    "Repeatedly slaps the foe\\n2 to 5 times.":
        "Abofetea al rival\\nde 2 a 5 veces.",
    "Repeatedly punches the foe\\n2 to 5 times.":
        "Golpea al rival\\nde 2 to 5 veces.",
    "A powerful punch that is\\nthrown without mercy.":
        "Puñetazo potente lanzado\\nsin piedad.",
    "Throws coins at the foe.\\nMoney is recovered after.":
        "Lanza monedas. El dinero\\nse recupera al ganar.",
    "A powerful fire punch\\nthat may burn the foe.":
        "Puñetazo de fuego que\\npuede quemar al rival.",
    "A powerful ice punch\\nthat may freeze the foe.":
        "Puñetazo de hielo que\\npuede congelar al rival.",
    "A powerful punch that may\\nparalyze the foe.":
        "Puñetazo poderoso que\\npuede paralizar al rival.",
    "Scratches the foe with\\nsharp claws.":
        "Araña al rival con\\nlas garras afiladas.",
    "Grips the foe hard with\\npincers to inflict pain.":
        "Agarra al rival con\\npinzas para hacerle daño.",
    "One-hit-KO move that\\ndrops the foe's HP to 0.":
        "Movimiento de 1 golpe\\nque deja los PS a 0.",
    "Whips up a whirlwind to\\nhit the foe in 2 turns.":
        "Crea un vendaval para\\ngolpear en 2 turnos.",
    "Raises the user's Attack\\nby sharply waving swords.":    
        "Sube el Ataque al\\nagitar espadas rápido.",
    "Cuts the foe with sharp\\nscales or claws.":
        "Corta al rival con\\nescamas o garras.",
    "Strikes the foe with a\\ngust of wind.":
        "Golpea al rival con\\nuna ráfaga de viento.",
    "Slams the foe with wings\\nor a tail.":
        "Golpea al rival con\\nalas o cola.",
    "Blows away the foe with\\na gust of wind.":
        "Expulsa al rival con\\nun fuerte vendaval.",
    "Flies up on the first\\nturn, then strikes next.":
        "Vuela en el 1er turno\\ny ataca en el 2º.",
    "Binds and squeezes the\\nfoe for 4 to 5 turns.":
        "Inmoviliza y aprieta al\\nrival de 4 a 5 turnos.",
    "Slams the foe with a long\\ntail, vines, etc.":
        "Golpea al rival con\\ncola, enredaderas, etc.",
    "Strikes the foe with\\nleafy vines.":
        "Golpea al rival con\\nenredaderas de hojas.",
    "Stomps the foe with a\\nbig foot. May cause flinch.":
        "Pisotea al rival. Puede\\nhacerle retroceder.",
    "Double-kicks the foe.":
        "Patea al rival\\ndos veces seguidas.",
    "A powerful kick that has\\na high critical-hit ratio.":
        "Potente patada con alta\\ntasa de golpe crítico.",
    "Jumps up high, then drops\\non the foe on the 2nd turn.":
        "Salta alto y cae sobre\\nel rival en el 2º turno.",
    "A fast kick. If it misses,\\nthe user is hurt instead.":
        "Patada giratoria. Si falla,\\nel usuario recibe daño.",
    "Reduces the foe's accuracy\\nby throwing sand in its eyes.":
        "Tira arena a los ojos\\ndel rival reduciendo precisión.",
    "Charges the foe and may\\nmake it flinch.":
        "Embiste al rival y puede\\nhacerle retroceder.",
    "A horn attack that has a\\nhigh critical-hit ratio.":
        "Cornada con alta tasa\\nde golpe crítico.",
    "Jabs the foe with a horn\\n2 to 5 times.":
        "Pincha al rival con un\\ncuerno de 2 a 5 veces.",
    "One-hit KO attack. Fails\\nif the foe is faster.":
        "Ataque de 1 golpe KO.\\nFalla si el rival es más rápido.",
    "A physical attack in which\\nthe user charges the foe.":
        "Ataque físico en el que\\nel usuario embiste al rival.",
    "Slams the foe with the\\nbody to cause damage.":
        "Golpea al rival con el\\ncuerpo causando daño.",
    "Wraps and squeezes the foe\\n4 to 5 turns.":
        "Envuelve y aprieta al\\nrival de 4 a 5 turnos.",
    "An attack that also hurts\\nthe user a little.":
        "Ataque que también daña\\nligeramente al usuario.",
    "An all-out attack that\\ncauses severe damage.":
        "Ataque furibundo que\\ncausa daño severo.",
    "A reckless charge that also\\nhurts the user a little.":
        "Ataque reckless que\\ntambién daña al usuario.",
    "Whips the foe with a\\nslender, long tail.":
        "Azota al rival con una\\ncola larga y fina.",
    "Jabs the foe with a\\npoisonous barb.":
        "Pincha al rival con\\nun aguijón venenoso.",
    "Hits the foe twice in one\\nturn with stingers.":
        "Golpea al rival dos\\nveces con aguijones.",
    "Fires pins at the foe\\n2 to 5 times.":
        "Lanza pinchos al rival\\nde 2 a 5 veces.",
    "Intimidates the foe by\\nglaring dauntingly.":
        "Intimida al rival con\\nuna mirada feroz.",
    "Bites the foe with\\nvice-like fangs.":
        "Muerde al rival con\\ncolmillos muy fuertes.",
    "Growls in a cute way\\nthat makes the foe less wary.":
        "Gruñe con ternura para\\nbajar la guardia rival.",
    "Makes a huge roar that\\nmakes the foe flee.":
        "Ruge para hacer que el\\nrival huya o retroceda.",
    "Uses a soothing melody\\nto put the foe to sleep.":
        "Usa una melodía para\\ndormir al rival.",
    "Emits ultrasonic waves\\nthat confuse the foe.":
        "Emite ultrasonidos que\\nconfunden al rival.",
    "Launches a ball of sound\\nthat always hits.":
        "Lanza una onda de sonido\\nque siempre impacta.",
    "Disables the last move\\nused by the foe.":
        "Anula el último\\nmovimiento del rival.",
    "Sprays a hide-melting\\nacid on the foe.":
        "Rocía ácido corrosivo\\nsobre el rival.",
    "Attacks by shooting fiery\\nsparks at the foe.":
        "Ataca lanzando chispas\\nde fuego al rival.",
    "Shoots a stream of fire\\nthat may inflict a burn.":
        "Lanza llamas que pueden\\nquemar al rival.",
    "Cloaks the user in a\\nprotective mist.":
        "Rodea al usuario con una\\nniebla protectora.",
    "Squirts water to attack\\nthe foe.":
        "Lanza un chorro de agua\\ncontra el rival.",
    "Blasts water at high\\npressure to strike the foe.":
        "Lanza agua a alta presión\\ncontra el rival.",
    "Rushes the foe with\\na strong water current.":
        "Embiste al rival con una\\nfuerte corriente de agua.",
    "Fires a cold beam of\\nenergy at the foe.":
        "Dispara un rayo helado\\ncontra el rival.",
    "Hits the foe with an\\nintense blast of all-out cold.":
        "Golpea al rival con una\\nintensa ventisca gélida.",
    "Attacks the foe with\\na peculiar ray.":
        "Ataca al rival con un\\nrayo de luz peculiar.",
    "Shoots bubbles at the\\nfoe. May lower Speed.":
        "Lanza burbujas al rival.\\nPuede bajar Velocidad.",
    "Fires a rainbow-colored\\nbeam at the foe.":
        "Dispara un haz de luz\\nde colores al rival.",
    "Powerful, but leaves the\\nuser immobile the next turn.":
        "Potente, pero deja al\\nusuario inmóvil un turno.",
    "Attacks the foe with a\\nbeak or a bill.":
        "Ataca al rival con\\nun pico afilado.",
    "Drills the foe with a\\nbeak rotating at high speed.":
        "Perfora al rival con\\nun pico giratorio rápido.",
    "The user attacks wildly,\\nthen becomes confused.":
        "El usuario ataca frenético\\ny luego se confunde.",
    "A full-power attack that\\ncauses the user to faint.":
        "Ataque a máxima potencia\\nque desmaya al usuario.",
    "Attack that makes the\\nfoe flinch if it hits.":
        "Ataca y puede hacer\\nretroceder al rival.",
    "Drains the foe's HP over\\nup to 4 to 5 turns.":
        "Drena los PS del rival\\ndurante 4 a 5 turnos.",
    "Attacks by looming over\\nthe foe. May cause flinch.":
        "Ataca sobrevolando al\\nrival. Puede hacerle retroceder.",
    "A kick that inflicts more\\ndamage when injured.":
        "Patada que hace más daño\\ncuando el usuario está herido.",
    "Sends sand blowing at\\nthe foe's face.":
        "Sopla arena a la cara\\ndel rival.",
    "Attacks with the impact\\nof a thunderbolt.":
        "Ataca con el impacto\\nde un rayo.",
    "A strong electric attack\\nthat may paralyze the foe.":
        "Ataque eléctrico fuerte\\nque puede paralizar.",
    "A weak jolt of electricity\\nthat paralyzes the foe.":
        "Sacudida débil que siempre\\nparaliza al rival.",
    "A brutal electric attack\\nthat may paralyze the foe.":
        "Potente ataque eléctrico\\nque puede paralizar.",
    "Throws a rock at the\\nfoe. High critical-hit ratio.":
        "Lanza una roca al rival.\\nAlta tasa de crítico.",
    "The user levitates and\\nstomps down on the foe.":
        "El usuario levita y\\ncae sobre el rival.",
    "One-hit KO attack. Splits\\nthe ground to drop the foe.":
        "Ataque de 1 golpe KO.\\nAbre el suelo bajo el rival.",
    "Digs underground on the\\n1st turn, then strikes next.":
        "Se entierra en el 1er\\nturno y ataca en el 2º.",
    "Badly poisons the foe.\\nPoison damage worsens each turn.":
        "Envenena gravemente al rival.\\nEl daño aumenta cada turno.",
    "Attacks with a peculiar\\nwave that confuses the foe.":
        "Ataca con una onda que\\nconfunde al rival.",
    "Attacks with a powerful\\npsychic force.":
        "Ataca con una poderosa\\nfuerza psíquica.",
    "Puts the foe to sleep by\\nusing a hypnotic pattern.":
        "Hipnotiza al rival con\\nun patrón hipnótico.",
    "The user meditates to\\nsharp its fighting spirit.":
        "El usuario medita para\\nafilar su espíritu de lucha.",
    "Sharply raises the Speed\\nof the user.":
        "Aumenta mucho la\\nVelocidad del usuario.",
    "Allows the user to attack\\nbefore the foe.":
        "Permite al usuario atacar\\nantes que el rival.",
    "Works up a rage that\\nboosts Attack.":
        "Aumenta el Ataque del\\nusuario cuanto más enfadado.",
    "Teleports to escape from\\nwild Pokémon instantly.":
        "Teletransporta al usuario\\npara escapar de salvajes.",
    "Attacks with power equal\\nto the user's level.":
        "Ataca con poder igual\\nal nivel del usuario.",
    "Mimics the last move used\\nby the foe.":
        "Imita el último movimiento\\nusado por el rival.",
    "A screech that sharply\\nlowers the foe's Defense.":
        "Chillido que baja mucho\\nla Defensa del rival.",
    "Evades attack by creating\\nimages. Raises evasiveness.":
        "Crea imágenes para evadir\\nataques. Sube Evasión.",
    "Recovers up to half the\\nuser's maximum HP.":
        "Recupera hasta la mitad\\nde los PS máximos.",
    "Stiffens all the muscles\\naround its body.":
        "Endurece los músculos\\nde su cuerpo.",
    "The user minimizes its\\nbody to raise evasiveness.":
        "El usuario se encoge\\npara subir su Evasión.",
    "Releases a cloud of smoke\\nthat reduces the foe's accuracy.":
        "Suelta una nube de humo\\nque baja la precisión rival.",
    "Confuses the foe with a\\nsinister, odd light.":
        "Confunde al rival con\\nuna luz extraña y siniestra.",
    "Withdraws into the shell\\nto raise Defense.":
        "Se retrae en el caparazón\\npara subir la Defensa.",
    "Curls up to conceal weak\\nspots and raises Defense.":
        "Se encuruca para subir\\nla Defensa.",
    "Raises a barrier to sharply\\nboost Defense.":
        "Levanta una barrera que\\naumenta mucho la Defensa.",
    "Erects a reflective wall\\nthat halves Sp. Atk damage.":
        "Erect una pantalla que\\nreduce daño Especial a la mitad.",
    "Eliminates weather and\\nresets all stat changes.":
        "Elimina el clima y\\nrestablece los cambios de stat.",
    "Creates a reflective wall\\nthat halves Atk damage.":
        "Crea una pantalla que\\nreduce daño Físico a la mitad.",
    "Focuses the user's mind\\nbefore attacking next turn.":
        "Concentra la mente del\\nusuario antes de atacar.",
    "Endures the foe's attack,\\nthen strikes back double.":
        "Aguanta el ataque rival\\ny responde con el doble.",
    "Randomly uses any move\\nof the user and other Pokémon.":
        "Usa aleatoriamente cualquier\\nmovimiento conocido.",
    "Counters the foe's move,\\nwhich is then reflected back.":
        "Contraataca el movimiento\\nrival con el doble.",
    "The user blows itself up\\nto inflict damage.":
        "El usuario se autodestruye\\npara dañar al rival.",
    "Flings eggs at the foe\\nfrom a distance.":
        "Lanza huevos al rival\\ndesde la distancia.",
    "Licks with a long tongue\\nto injure and cause paralysis.":
        "Lame al rival para dañarle\\ny causarle parálisis.",
    "Shoots a sinister, toxic\\ngas at the foe.":
        "Dispara un gas tóxico\\ny siniestro al rival.",
    "Hurls a blob of sludge\\nat the foe.":
        "Lanza un pegote de\\nbarro al rival.",
    "Clubs the foe with a\\nsolid bone.":
        "Golpea al rival con\\nun hueso sólido.",
    "Spouts intense fire that\\nthe foe can't escape.":
        "Lanza fuego intenso del\\nque el rival no puede escapar.",
    "Charges at the foe with\\ngreat power.":
        "Carga contra el rival\\ncon gran potencia.",
    "Clamps and squeezes the\\nfoe with a claw.":
        "Agarra y aprieta al\\nrival con una pinza.",
    "Swift, sure, star-shaped\\nrays hit the foe.":
        "Rayos en forma de estrella\\nque siempre impactan.",
    "Lowers the head to boost\\nDefense, then tackles.":
        "Baja la cabeza para subir\\nDefensa y luego embiste.",
    "Launches spikes at the\\nfoe. High critical-hit ratio.":
        "Lanza pinchos al rival.\\nAlta tasa de crítico.",
    "Constricts the foe to\\nlower its Speed.":
        "Contrae al rival para\\nbajarle la Velocidad.",
    "Lowers the mental energy\\nused for Sp. Atk.":
        "Vacía la mente del usuario\\nsubiéndole el Sp. Atk.",
    "Attacks the foe using\\nkinesis to deform its body.":
        "Ataca usando kinesis para\\ndeformar el cuerpo rival.",
    "Restores the user's HP\\nby half of its maximum HP.":
        "Restaura los PS del usuario\\nen la mitad de su máximo.",
    "A high jump kick that\\nif it misses, hurts the user.":
        "Patada en salto. Si falla,\\nel usuario recibe daño.",
    "Fixes the foe in place\\nto prevent it from fleeing.":
        "Paraliza al rival para\\nimpedir que huya.",
    "While the foe is asleep,\\nthe user eats its dream.":
        "Come los sueños del rival\\nmientras está dormido.",
    "Poisons the foe with a\\nnoxious gas.":
        "Envenena al rival con\\nun gas nocivo.",
    "Hurls round objects\\nat the foe.":
        "Lanza objetos redondos\\ncontra el rival.",
    "Absorbs half the damage\\ninflicted to restore HP.":
        "Absorbe la mitad del\\ndaño infligido para curar PS.",
    "Plants a kiss on the foe\\nthat causes sleep.":
        "Da un beso al rival\\nque lo hace dormir.",
    "Charges at the foe\\non the first turn, then dives.":
        "Carga en el primer turno,\\nluego se lanza en picado.",
    "Reverts to normal type\\nand loses a random condition.":
        "Vuelve al tipo Normal\\ny pierde una condición.",
    "A two-turn attack that\\nspins the user to attack.":
        "Ataque de 2 turnos que\\nhace girar al usuario.",
    "Lays a trap of spores to\\npoison the foe.":
        "Pone una trampa de esporas\\npara envenenar al rival.",
    "Uses a flash of light to\\nreduce the foe's accuracy.":
        "Usa un destello de luz\\npara bajar la precisión rival.",
    "Attacks the foe with\\nan odd, hot wind.":
        "Ataca al rival con un\\nviento extraño y cálido.",
    "Flops around to attack,\\nbut may cause confusion.":
        "Se retuerce para atacar\\npero puede confundirse.",
    "The user explodes to inflict\\ndamage on all Pokémon nearby.":
        "El usuario explota causando\\ndaño a todos los cercanos.",
    "Repeatedly slashes the foe\\nwith sharp claws, etc.":
        "Arañas repetidamente al\\nrival con garras afiladas.",
    "Rampages and slashes at\\nthe foe 2 to 5 times.":
        "Rasguña al rival de\\n2 a 5 veces furiosamente.",
    "Reduces the foe's HP\\nby half of the max HP.":
        "Reduce los PS del rival a\\nla mitad de su máximo.",
    "Slashes with a sharp\\nblade. High critical-hit ratio.":
        "Corta con una hoja afilada.\\nAlta tasa de crítico.",
    "Creates a decoy to take\\nhits and reduce damage.":
        "Crea un señuelo que absorbe\\ngolpes en lugar del usuario.",
    "An attack that is used\\nin desperation.":
        "Un ataque usado en\\nuna situación desesperada.",
    "Asks a wild Pokémon to\\nlearn a move.":
        "Copia el movimiento de\\nun Pokémon salvaje.",
    # ── GEN 2 ──
    "Kicks the foe three times\\nin a row.":
        "Patea al rival tres veces\\nconsecutivas.",
    "Runs up to the foe and\\nsteals an item.":
        "Se acerca al rival y\\nle roba un objeto.",
    "Ensnares the foe with an\\nultrathin thread.":
        "Atrapa al rival con\\nun hilo ultrafino.",
    "Attacks after the user\\nsenses the target's moves.":
        "Ataca después de prever\\nlos movimientos del rival.",
    "Puts the foe in a night-\\nmare that causes damage.":
        "Mete al rival en una\\npesadilla que le daña.",
    "Wraps the user in flames\\nthat may burn the foe.":
        "Envuelve al usuario en\\nllamas que pueden quemar.",
    "Attacks while sleeping\\nwithout waking up.":
        "Ataca mientras duerme\\nsin despertarse.",
    "An odd move that is\\na swap of stat changes.":
        "Movimiento raro que\\nusa una maldición.",
    "Attacks desperately.\\nThe weaker, the stronger.":
        "Ataca con desesperación.\\nMás fuerza si tiene menos PS.",
    "Converts the user to\\na type that resists the move.":
        "Cambia al tipo que resiste\\nel último movimiento rival.",
    "A purified-air blast\\nwith a chance of a critical hit.":
        "Ráfaga de aire puro con\\nalta tasa de crítico.",
    "Sprays cotton spores\\nto sharply reduce Speed.":
        "Suelta esporas de algodón\\nque bajan mucho la Velocidad.",
    "Counters the foe's special\\nthat hurts the most.":
        "Contrarresta el ataque\\nespecial más fuerte del rival.",
    "Spites the foe to reduce\\nthe PP of the last move used.":
        "Reduce los PP del último\\nmovimiento usado por el rival.",
    "Attacks with a chilling\\nbreath. May lower Speed.":
        "Ataca con aliento gélido.\\nPuede bajar la Velocidad.",
    "Evades attack, then strikes\\nnext turn. No flinching.":
        "Evade ataques y golpea\\nel siguiente turno.",
    "Throws a punch before\\nthe foe can react.":
        "Lanza un puñetazo antes\\nde que el rival reaccione.",
    "Makes a frightening face\\nto sharply lower the foe's Speed.":
        "Hace una cara aterradora\\nque baja mucho la Velocidad.",
    "Draws the foe close with\\nits tail, then slaps.":
        "Atrae al rival con la cola\\ny luego le abofetea.",
    "An attack that also\\nfills the user with love.":
        "Beso que transmite amor\\nal usuario.",
    "Maximizes Attack but\\nlowers HP.":
        "Maximiza el Ataque pero\\nbaja los PS del usuario.",
    "Hurls a black, toxic mud\\nball at the foe.":
        "Lanza una bola de barro\\ntóxico y negro al rival.",
    "Attacks by throwing\\ndirty mud at the foe.":
        "Ataca lanzando barro\\nsucia al rival.",
    "Sprays a giant ball of\\nwater at the foe.":
        "Lanza una gran bola de\\nagua al rival.",
    "Creates a jolt of\\nelectricity that paralyzes.":
        "Genera un impulso eléctrico\\nque paraliza al rival.",
    "Foretells the future, then\\nattacks 2 turns later.":
        "Presagia el futuro y ataca\\n2 turnos después.",
    "Uses a seeing technique\\nto prevent foe from hiding.":
        "Técnica de visión para evitar\\nque el rival se oculte.",
    "A rampaging attack that\\nlasts 2 to 3 turns.":
        "Ataque furioso que dura\\nde 2 a 3 turnos.",
    "Raises a sandstorm for\\n5 turns.":
        "Levanta una tormenta de\\narena durante 5 turnos.",
    "An attack that absorbs\\nhalf the damage inflicted.":
        "Absorbe la mitad del\\ndaño infligido.",
    "Endures any attack, leaving\\nat least 1 HP.":
        "Aguanta cualquier ataque\\ndejando al menos 1 PS.",
    "Lowers the foe's Defense\\nand Sp. Def by making it cute.":
        "Encanta al rival bajando\\nsu Defensa y Defensa Especial.",
    "Constantly rolls to raise\\nDefense and Attack.":
        "Rueda constantemente para\\nsubir Defensa y Ataque.",
    "Hits without fail if the\\nfoe has been hit once already.":
        "No falla si el rival\\nya ha recibido un golpe.",
    "Makes the foe boastful\\nand confused.":
        "Hace al rival fanfarrón\\ny confundido.",
    "Gives milk to the user\\nto restore HP.":
        "El usuario bebe leche\\npara recuperar PS.",
    "A fast and electric\\nattack. May cause paralysis.":
        "Ataque eléctrico rápido.\\nPuede causar parálisis.",
    "Cuts repeatedly using\\nboth arms. High critical-hit.":
        "Corta repetidamente. Alta\\ntasa de golpe crítico.",
    "Hits with hard-edged wings.\\nMay lower the foe's Defense.":
        "Golpea con alas duras.\\nPuede bajar la Defensa.",
    "Stares at the foe to\\nprevent it from escaping.":
        "Mira fijamente al rival para\\nimpedir que escape.",
    "Makes the foe fall in\\nlove with the user.":
        "Hace que el rival se\\nenamore del usuario.",
    "While asleep, the user\\nrandomly uses a move.":
        "Dormido, el usuario usa\\nun movimiento al azar.",
    "Chimes for 5 turns to\\nheal all status problems.":
        "Repica 5 turnos para curar\\nproblemas de estado.",
    "An attack that is stronger\\nif the user has bonded.":
        "Ataque más fuerte cuanto\\nmás vínculo tiene el usuario.",
    "Randomly gives the foe a\\npresent of varying power.":
        "Da al rival un regalo\\nde potencia variable.",
    "Power increases the less\\nthe user likes the trainer.":
        "Más potente cuanto menos\\nquiere el usuario al entrenador.",
    "Prevents stat reductions\\nand blocks weather effects.":
        "Evita bajas de stats y\\nbloquea efectos del clima.",
    "Shares the user's pain\\nwith the foe to even out HP.":
        "Comparte el dolor del usuario\\npara igualar los PS.",
    "Using its mystic power,\\nthe user does huge damage.":
        "Usa poder místico para\\ncausar un daño inmenso.",
    "An attack with a large\\nquantity of power.":
        "Ataque con una enorme\\ncantidad de potencia.",
    "Breathes a powerful blast\\nof fire in the foe's face.":
        "Lanza un potente soplo\\nde fuego al rival.",
    "An attack that has a\\nhigh critical-hit ratio.":
        "Ataque con alta tasa\\nde golpe crítico.",
    "Breathes dragon energy\\nat the foe.":
        "Exhala energía dragón\\nhacia el rival.",
    "Restores HP by 1/2 of\\nthe user's maximum HP.":
        "Restaura la mitad de\\nlos PS máximos del usuario.",
    "Shoots small rocks to\\nhit the foe.":
        "Dispara pequeñas rocas\\nhacia el rival.",
    "Steals the foe's held\\nitem if the user holds none.":
        "Roba el objeto del rival\\nsi el usuario no tiene ninguno.",
    "Lures a foe with a\\nsweet scent. Raises wild rate.":
        "Atrae con un aroma dulce.\\nAumenta encuentros salvajes.",
    "A powerful punch that\\nalways strikes last.":
        "Poderoso puñetazo que\\nsiempre golpea el último.",
    "If a Pokémon faints, the\\nuser gains its stat changes.":
        "Si un Pokémon se desmaya,\\nel usuario gana sus cambios.",
    "A Normal-type move that\\nbecomes the terrain's type.":
        "Movimiento Normal que\\ncambia según el terreno.",
    "Charges the body with\\nelectricity. Raises Sp. Atk.":
        "Carga el cuerpo con\\nelectricidad. Sube Sp. Atk.",
    "Confronts the foe and\\nconfuses it.":
        "Enfrenta al rival y\\nlo confunde.",
    "A helping hand enables\\na friend to attack first.":
        "Ayuda al compañero a\\natacar primero.",
    "Swaps the user's held\\nitem with the foe's.":
        "Intercambia el objeto del\\nusuario con el del rival.",
    "Copies the foe's Ability.":
        "Copia la Habilidad\\ndel rival.",
    "Restores the HP of a\\nPokémon that switches in.":
        "Restaura los PS del\\nPokémon que entre al campo.",
    "Randomly uses a move\\nknown by a party Pokémon.":
        "Usa aleatoriamente un\\nmovimiento de tu equipo.",
    "The user sinks roots\\nthat restore HP each turn.":
        "El usuario echa raíces que\\nrestauran PS cada turno.",
    "Boosts Attack and Sp. Atk\\nbut sharply lowers Defense.":
        "Sube Ataque y Sp. Atk pero\\nbaja mucho la Defensa.",
    "Bounces back the effects\\nof status-changing moves.":
        "Devuelve los efectos de\\nmovimientos de estado.",
    "Recycles a used held item\\nfor one more use.":
        "Recicla el objeto usado\\npara usarlo una vez más.",
    "Attack that moves last\\nand gains power if hit.":
        "Ataca el último y gana\\npotencia si fue golpeado.",
    "Destroys the foe's barrier,\\nthen does double damage.":
        "Destruye la pantalla rival\\ny hace el doble de daño.",
    "The user feigns sleep\\nfor 1 turn, then attacks.":
        "El usuario finge dormir\\n1 turno y luego ataca.",
    "Knocks away the foe's\\nheld item.":
        "Golpea y hace caer el\\nobjeto del rival.",
    "The user makes a great\\neffort to inflict damage.":
        "El usuario hace un gran\\nesfuerzo para hacer daño.",
    "The user erupts with power,\\ndoing more damage at full HP.":
        "El usuario erupciona, más\\npotente con PS llenos.",
    "Switches the Ability of\\nthe user and the foe.":
        "Intercambia la Habilidad del\\nusuario con la del rival.",
    "Prevents the foe from\\nusing a move the user knows.":
        "Impide al rival usar un\\nmovimiento que el usuario sabe.",
    "Heals any status problem\\nthe user has inflicted on a foe.":
        "Cura un problema de estado\\ninfligido por el usuario.",
    "Snatch the item and\\nbenefit from the move.":
        "Roba los beneficios del\\nmovimiento del rival.",
    "A secret power that varies\\nby location.":
        "Poder secreto que varía\\nsegún la ubicación.",
    "Dives underwater on turn\\n1, then strikes next turn.":
        "Bucea en el 1er turno\\ny ataca en el 2º.",
    "Quickly attacks the foe\\nwith both arms.":
        "Ataca rápidamente al rival\\ncon ambos brazos.",
    "The user fakes having\\na different color.":
        "El usuario finge tener\\nun color diferente.",
    "A powerful glow from\\nthe tail paralyzes the foe.":
        "Un brillo poderoso de la\\ncola paraliza al rival.",
    "Purifies the air and\\nheals all status problems.":
        "Purifica el aire y cura\\ntodos los problemas de estado.",
    "A coiling move that causes\\nconfusion.":
        "Movimiento en espiral que\\ncausa confusión.",
    "Fires a glowing ball that\\nburns the foe.":
        "Lanza una bola brillante\\nque quema al rival.",
    "Fires a beam of shining\\nlight that lowers Sp. Atk.":
        "Dispara un haz de luz\\nque baja el Sp. Atk.",
    "A burst of dancing flames\\nthat scorches the foe.":
        "Explosión de llamas que\\nchamusca al rival.",
    "Ice-cold energy is scattered\\nto damage all Pokémon.":
        "Energía gélida dispersada\\nque daña a todos.",
    "Burns up the foe without\\nloss of power.":
        "Quema al rival sin pérdida\\nde potencia.",
    # ── GEN 3 ──
    "Attacks the foe without\\nwarning.":
        "Ataca al rival sin previo\\naviso.",
    "An upbeat cry that\\nconfuses those in the area.":
        "Un grito animado que\\nconfunde a los cercanos.",
    "A restoring move that\\nalso raises a stat.":
        "Movimiento restaurador que\\ntambién sube un stat.",
    "Spits out the stockpiled\\nenergy in one burst.":
        "Suelta la energía acumulada\\nde golpe.",
    "Swallows any stockpiled\\nenergy to restore HP.":
        "Traga la energía acumulada\\npara recuperar PS.",
    "A fiery heat that scorches\\nall Pokémon in battle.":
        "Calor abrasador que quema\\na todos los Pokémon en combate.",
    "Summons a hailstorm that\\nlasts for 5 turns.":
        "Invoca un granizo que\\ndura 5 turnos.",
    "Torments and enrages the\\nfoe, preventing move reuse.":
        "Atormenta al rival impidiendo\\nque use el mismo movimiento.",
    "Flatters the foe to confuse\\nit, but raises its Sp. Atk.":
        "Lisonjea al rival para\\nconfundirlo, pero sube su Sp. Atk.",
    "Burns the foe with a\\nwill-o'-the-wisp fireball.":
        "Quema al rival con una\\nllama de fuego fatuo.",
    "Falls before the foe\\nto raise two of the user's stats.":
        "Cae ante el rival para\\nsubir dos stats del usuario.",
    "Toughens the body's defense\\nto prevent ailments.":
        "Endurece la defensa del\\ncuerpo para evitar males.",
    "Concentrates the user's\\nmind before attacking.":
        "Concentra la mente del\\nusuario antes de atacar.",
    "Boosts its smell to restore\\nHP. It also heals an ally.":
        "El aroma restaura PS\\ny también cura al aliado.",
    "Draws attacks to the user\\nto spare its partner.":
        "Atrae los ataques al usuario\\npara proteger al aliado.",
    "Uses natural energy to\\ncharge up an attack.":
        "Usa energía natural para\\ncargarse antes de atacar.",
    "Angers the foe into\\na confused rage.":
        "Enfurece al rival hasta\\nconfundirlo.",
    "Gives an item to the foe\\non the next turn.":
        "Da al rival el objeto\\nportado en el siguiente turno.",
    "Saps the user's power to\\nbreak one barrier move.":
        "Usa el poder del usuario\\npara romper una pantalla.",
    "Launches the foe into\\nthe air and nails it down.":
        "Lanza al rival al aire y\\nluego lo clava al suelo.",
    "Enables a Ghost-type attack\\nto hit a Normal-type foe.":
        "Permite a ataques Fantasma\\ngolpear a tipos Normal.",
    "Draws in the foe with a\\nsweet scent.":
        "Atrae al rival con\\nun aroma dulce.",
    "A strong charge. Makes\\nthe user more powerful.":
        "Una fuerte carga que hace\\nal usuario más poderoso.",
    "A kick that has great\\npure power.":
        "Patada con un gran\\npoder puro.",
    "Has a 30% chance of\\ncausing various status problems.":
        "30% de probabilidad de\\ncausar varios problemas de estado.",
    "Uses a strange leaf that\\nincreases evasiveness.":
        "Usa una hoja extraña que\\naumenta la Evasión.",
    "Hurls a heavy bone at\\nthe foe.":
        "Lanza un hueso pesado\\ncontra el rival.",
    "An all-out punch that\\nnever misses.":
        "Puñetazo a fondo que\\nnunca falla.",
    "Rams a giant horn into\\nthe foe.":
        "Emplace un cuerno gigante\\ncontra el rival.",
    "A very strong breath\\nof fire.":
        "Un soplo de fuego\\nextremadamente potente.",
    "A very strong blast of\\nwater.":
        "Un disparo de agua\\nextremadamente potente.",
    "A meteor attack that\\nalso raises Attack.":
        "Ataque meteórico que también\\nsube el Ataque.",
    "Startles the foe,\\nmaking it unable to attack.":
        "Sobresalta al rival,\\nimposibilitando que ataque.",
    "A weather ball changes\\ntype and power with weather.":
        "La Bola Tiempo cambia de tipo\\ny potencia según el clima.",
    "Heals all party Pokémon's\\nstatus problems.":
        "Cura los problemas de estado\\nde todo el equipo.",
    "Feigns crying to sharply\\nlower the foe's Sp. Def.":
        "Finge llorar para bajar\\nmucho la Defensa Especial rival.",
    "Launches a weak jolt\\nof electricity at the foe.":
        "Lanza un pequeño impulso\\neléctrico al rival.",
    "An intense fire that also\\nleaves the user with a burn.":
        "Fuego intenso que también\\nquema al usuario.",
    "Aids in exposing the foe\\nif it is hiding.":
        "Ayuda a descubrir al rival\\nsi está oculto.",
    "Drops rocks on the foe.\\nMay also lower the foe's Speed.":
        "Cae rocas sobre el rival.\\nPuede bajar la Velocidad.",
    "Whips up a whirlwind of\\nsilver-colored powder.":
        "Levanta un torbellino de\\npolvo color plata.",
    "Emits a horrible screech\\nthat lowers Steel-type Defense.":
        "Emite un chirrido horrible que\\nbaja la Defensa de tipo Acero.",
    "Lets loose a pleasing note\\nthat confuses the foe.":
        "Suelta una nota que\\nconfunde al rival.",
    "Tickles the foe to lower\\nboth its Attack and Defense.":
        "Hace cosquillas al rival para\\nbajar Ataque y Defensa.",
    "Draws in cosmic power\\nto boost Defense and Sp. Def.":
        "Absorbe poder cósmico para\\nsubir Defensa y Def. Especial.",
    "An extremely powerful\\nwhirlpool of water.":
        "Torbellino de agua\\nextremadamente potente.",
    "A charged light that\\nrandomly confuses the foe.":
        "Luz cargada que puede\\nconfundir aleatoriamente.",
    "Throws a punch from\\nthe shadows.":
        "Lanza un puñetazo desde\\nlas sombras.",
    "A 6th sense is used to\\nprevent evasion.":
        "Usa el 6º sentido para\\nevitar que el rival evada.",
    "Lands an uppercut from\\nbelow on a flying foe.":
        "Da un gancho de abajo a\\narriba al rival en vuelo.",
    "Creates a whirlwind of\\nsand around the foe.":
        "Crea un torbellino de arena\\nalrededor del rival.",
    "Strikes the foe with\\nan intense blast of cold.":
        "Golpea al rival con una\\nráfaga de frío intenso.",
    "A muddy vortex that hits\\nthe foe. May lower Speed.":
        "Un vórtice de barro que\\ngolpea. Puede bajar Velocidad.",
    "Fires seeds at the foe,\\nhitting 2 to 5 times.":
        "Dispara semillas al rival,\\ngolpeando de 2 a 5 veces.",
    "A swift attack that never\\nmisses.":
        "Ataque veloz que\\nnunca falla.",
    "Hurls icicles at the foe.\\nHits 2 to 5 times.":
        "Lanza carámbanos al rival.\\nGolpea de 2 a 5 veces.",
    "Tenses each muscle\\nto sharply raise Defense.":
        "Tensa los músculos para\\nsubir mucho la Defensa.",
    "Blocks the foe to prevent\\nit from moving.":
        "Bloquea al rival para\\nimpedir su movimiento.",
    "The user howls loudly\\nto raise its Attack.":
        "El usuario aúlla fuerte\\npara subir su Ataque.",
    "Slashes at the foe with\\na huge, sharp claw.":
        "Arañaza al rival con\\nuna garra enorme y afilada.",
    "An all-out attack that\\ndoes huge damage to the foe.":
        "Ataque a tope que causa\\nenorme daño al rival.",
    "Tenses the muscles\\nto boost Attack and Sp. Atk.":
        "Tensa los músculos para\\nsubir Ataque y Ataque Especial.",
    "Fires a barrage of small\\nboulders at the foe.":
        "Dispara una andanada de\\nroca pequeñas al rival.",
    "Always-hitting electric\\nattack that never misses.":
        "Ataque eléctrico que\\nnunca falla.",
    "Attacks the foe with a\\nshot of pulsing water.":
        "Ataca al rival con un\\nchorro de agua pulsante.",
    "Strikes the foe with\\nancient power. May raise stats.":
        "Golpea con poder ancestral.\\nPuede subir todos los stats.",
    # ── GEN 4 ──
    "The user lands and\\nrestores its own HP.":
        "El usuario aterriza y\\nrestaurar sus propios PS.",
    "Gravity is intensified\\nfor 5 turns.":
        "La gravedad aumenta de\\nintensidad durante 5 turnos.",
    "Enables Ghost-type moves\\nto hit any type.":
        "Permite a los movimientos\\nFantasma golpear a cualquier tipo.",
    "Wakes the foe then attacks.\\nStrong if the foe sleeps.":
        "Despierta al rival y ataca.\\nMás fuerte si dormía.",
    "Hits with a strong arm. \\nLowers Speed on the same turn.":
        "Golpea con un brazo fuerte.\\nBaja la Velocidad del usuario.",
    "A spinning attack that\\nalways goes last.":
        "Ataque giratorio que\\nsiempre actúa el último.",
    "The user faints, and the\\nnext Pokémon is fully healed.":
        "El usuario se desmaya y\\nel siguiente Pokémon se cura.",
    "Sea water attack that\\nis super effective on the foe.":
        "Agua marina que es súper\\neficaz si el rival sufre daño.",
    "Power varies by the held\\nberry and other effects.":
        "La potencia varía según\\nla baya portada y otros efectos.",
    "An attack that makes\\nthe foe flinch.":
        "Un ataque que hace\\nretroceder al rival.",
    "Plucks the foe's held berry\\nif any, then eats it.":
        "Coge la baya del rival\\ny luego la come.",
    "Creates a tailwind that\\nboosts Speed for 4 turns.":
        "Crea una ráfaga de viento\\nque sube la Velocidad 4 turnos.",
    "Sharply raises a random\\nstat.":
        "Sube mucho un stat\\naleatoriamente.",
    "The user attacks, then\\nswitches out.":
        "El usuario ataca y\\nluego se retira.",
    "An all-out attack on the\\nfoe. Lowers the user's defenses.":
        "Ataque total al rival.\\nBaja las defensas del usuario.",
    "The user attacks next\\nturn, dealing double the damage.":
        "Ataca el turno siguiente\\ncausando el doble de daño.",
    "Attacks the foe in a\\nway that makes it less wary.":
        "Ataca al rival haciéndolo\\nmenos precavido.",
    "The user strikes back\\ndoubling the damage received.":
        "El usuario contraataca con\\nel doble del daño recibido.",
    "The foe becomes unable to\\nuse its held item.":
        "El rival no puede usar\\nsu objeto portado.",
    "Flings the user's held\\nitem at the foe.":
        "Lanza el objeto del usuario\\ncontra el rival.",
    "The user is\\nreadied to switch with a move.":
        "Prepara al usuario para\\ncambiar junto a un movimiento.",
    "The last move used becomes\\na trump card that powers up.":
        "El último movimiento se\\nvuelve un triunfo más potente.",
    "Prevents the foe from\\nusing healing moves.":
        "Impide al rival usar\\nmovimientos de curación.",
    "The higher the foe's HP\\nthe more damage caused.":
        "Más daño cuanto más PS\\ntenga el rival.",
    "Swaps Attack and Defense\\nfor the duration of the move.":
        "Intercambia Ataque y Defensa\\ndel usuario.",
    "Swaps Sp. Atk and Sp. Def\\nfor the duration of the move.":
        "Intercambia Sp. Atk y Sp. Def\\ndel usuario.",
    "Attacks the foe with an\\nunfair move.":
        "Ataca al rival con\\nun movimiento desleal.",
    "Uses its last remaining\\neffort to inflict damage.":
        "Usa su último esfuerzo\\npara infligir daño.",
    "Plants a seed on the foe\\nthat changes its Ability to Worry Seed.":
        "Planta una semilla que cambia\\nla Habilidad del rival.",
    "An ambush attack that\\nhits foes switching out.":
        "Ataque de emboscada que\\ngolpea al rival al entrar.",
    "Lays spikes to poison\\nfoes entering the field.":
        "Coloca clavos que envenenan\\na los Pokémon que entren.",
    "Swaps the user's emotions\\nwith the foe's.":
        "Intercambia las emociones\\ndel usuario con las del rival.",
    "The user coats itself with\\na veil of water.":
        "El usuario se recubre\\ncon un velo de agua.",
    "The user floats using\\nmagnetic force. Evades Ground.":
        "El usuario flota usando fuerza\\nmagnética. Evita ataques Tierra.",
    "The user charges with\\nreckless abandon.":
        "El usuario carga con\\ntotal abandono.",
    "The user delivers a\\npunishing one-two.":
        "El usuario propina un\\ncastigador golpe de palma.",
    "Throws a sphere of\\naura at the foe.":
        "Lanza una esfera de\\naura al rival.",
    "Hardens the body surface\\nlike a rock.":
        "Endurece la superficie del\\ncuerpo como una roca.",
    "An attack that always\\ncauses one-hit KO.":
        "Un ataque que siempre\\ncausa 1 golpe KO.",
    "Jabs a barb coated\\nwith poison.":
        "Hinca una púa recubierta\\nde veneno.",
    "Shoots a sinister beam\\nof darkness.":
        "Dispara un siniestro\\nhaz de oscuridad.",
    "Attacks with a shadow\\nclaw.":
        "Ataca con una\\ngarra de sombra.",
    "Fires a steel ball\\nthat always strikes.":
        "Dispara una bola de acero\\nque siempre impacta.",
    "Fires a Hyper Beam at\\nfoes using the same language.":
        "Dispara un Hiperrayo a los\\nrival del mismo tipo.",
    "Attacks on the turn after\\nbeing used.":
        "Ataca en el turno siguiente\\nal ser usado.",
    "Moves on the turn after\\nbeing used.":
        "Se mueve en el turno siguiente\\nal ser usado.",
    "Creates a room that swaps\\nfoes' and allies' Defense and Sp. Def.":
        "Crea una sala que cambia\\nDefensa y Def. Especial.",
    "Comets strike the foe.\\nLowers the user's Sp. Atk.":
        "Cometas golpean al rival.\\nBaja el Sp. Atk del usuario.",
    "The user discharges\\na powerful burst of electricity.":
        "El usuario descarga una\\npoderosa explosión eléctrica.",
    "A fiery lava plume that\\nhits everyone around.":
        "Una columna de lava ardiente\\nque golpea a todos.",
    "Causes the foe to use\\na move randomly for 4 turns.":
        "Hace al rival usar un\\nmovimiento al azar 4 turnos.",
    "A powerful whipping attack\\nthat may lower Sp. Def.":
        "Potente latigazo que puede\\nbajar la Defensa Especial.",
    "Hurls a boulder at the\\nfoe.":
        "Lanza un pedrusco\\ncontra el rival.",
    "Strikes the foe with\\na cross slash of poison.":
        "Golpea al rival con una\\ncruz venenosa.",
    "Shoots filthy garbage\\nat the foe to attack.":
        "Dispara basura sucia\\nal rival.",
    "Attacks with a steel-\\ncovered head.":
        "Ataca con la cabeza\\ncubierta de acero.",
    "Attacks with a magnet.\\nAlways strikes.":
        "Ataca con un imán.\\nSiempre impacta.",
    "A slashing attack with\\na sharp stone.":
        "Ataque de corte con\\nuna piedra afilada.",
    "Steals the foe's attention\\nto raise one's evasiveness.":
        "Capta la atención del rival\\npara subir la Evasión.",
    "Attacks with full power\\non the 2nd turn.":
        "Ataca a plena potencia\\nen el 2º turno.",
    "Uses the foe's Ability\\nto deal damage.":
        "Usa la Habilidad del rival\\npara hacerle daño.",
    "Sets a trap on the field\\nthat hurts foes switching in.":
        "Pone una trampa que daña\\na los Pokémon entrantes.",
    "Attacks with a blade\\nof grass.":
        "Ataca con una hoja\\nde hierba.",
    "The user enthralls the\\nfoe to attack.":
        "El usuario hechiza al rival\\npara atacar.",
    "Stops any Pokémon on\\nthe field from moving.":
        "Impide a cualquier Pokémon\\nmoverse en el campo.",
    "Sends the foe back in\\ntime to attack in 2 turns.":
        "Manda al rival atrás en el\\ntiempo para atacar en 2 turnos.",
    "The user tears the target\\nusing its psychic power.":
        "El usuario desgarra al rival\\nusando poder psíquico.",
    "Creates darkness and\\ndrags the foe into it.":
        "Crea oscuridad y arrastra\\nal rival dentro de ella.",
    "Summons a powerful storm\\nlasting 2 to 5 turns.":
        "Invoca una poderosa tormenta\\nque dura de 2 a 5 turnos.",
    "Combines the power of\\nthe user and its allies.":
        "Combina el poder del usuario\\ny de sus aliados.",
    "A rampaging attack that\\nbuilds power over 10 turns.":
        "Ataque furioso que acumula\\npoder durante 10 turnos.",
}

# =====================================================================
# DESCRIPCIONES DE HABILIDADES
# Formato: 2-3 líneas, ~22 chars por línea
# =====================================================================
ABILITY_DESCRIPTIONS = {
    "No special ability.":
        "Sin habilidad especial.",
    "May cause a foe to flinch.":
        "Puede hacer retroceder\\nal rival.",
    "Summons rain in battle.":
        "Invoca lluvia al entrar\\nen combate.",
    "Gradually boosts Speed.":
        "Aumenta la Velocidad\\ngradualmente en batalla.",
    "Blocks critical hits.":
        "Bloquea los\\ngolpes críticos.",
    "Negates 1-hit KO attacks.":
        "Niega los ataques\\nde 1 golpe KO.",
    "Prevents additional\\neffects of moves.":
        "Evita los efectos\\nadicionales de los movimientos.",
    "Prevents the status\\nproblems of allies.":
        "Previene los problemas\\nde estado de los aliados.",
    "Has a high chance of\\nacting first.":
        "Alta probabilidad de\\nactuar primero.",
    "Prevents stat reductions.":
        "Previene la reducción\\nde estadísticas.",
    "Makes the Pokémon prone\\nto wild battles.":
        "Hace al Pokémon\\npropensión a batallas salvajes.",
    "Prevents the Pokémon\\nfrom being poisoned.":
        "Evita que el Pokémon\\nsea envenenado.",
    "Powers up Fire-type moves\\nif the Pokémon is hit.":
        "Potencia movimientos Fuego\\nsi recibe un golpe.",
    "Neutralizes the power of\\nsome abilities.":
        "Neutraliza el poder de\\nalgunas habilidades.",
    "Makes the Pokémon\\ngrow stronger.":
        "Hace al Pokémon\\ncrecer más fuerte.",
    "Summons sunlight in battle.":
        "Invoca luz solar al\\nentrar en combate.",
    "Prevents Ground-type\\nmoves from striking.":
        "Evita que los movimientos\\nde tipo Tierra impacten.",
    "Raises allies' moves in\\nthe same category.":
        "Mejora los movimientos\\nde los aliados del mismo tipo.",
    "Has a 30% chance of\\nparalyzing on contact.":
        "30% de probabilidad de\\nparalizar al contacto.",
    "Absorbs Electric moves\\nand nullifies damage.":
        "Absorbe movimientos Eléctrico\\ny anula el daño.",
    "Absorbs Water-type moves,\\nrestoring HP.":
        "Absorbe movimientos Agua\\ny restaura los PS.",
    "Prevents attraction and\\nconfusion from moves.":
        "Evita seducción y confusión\\nde movimientos.",
    "Eliminates the weather in\\nbattle.":
        "Elimina el clima\\ndurante la batalla.",
    "Raises accuracy by\\ncompound eyes.":
        "Aumenta la precisión\\ncon ojos compuestos.",
    "Prevents sleep.":
        "Previene el sueño.",
    "Changes type to match\\nthe opponent's.":
        "Cambia de tipo para\\nigualar al del rival.",
    "Prevents all poison\\neffects.":
        "Previene todos los\\nefectos de veneno.",
    "Raises the power of\\nFire-type moves.":
        "Aumenta la potencia de\\nlos movimientos de tipo Fuego.",
    "Prevents damage from\\nweather conditions.":
        "Evita el daño de\\ncondiciones climáticas.",
    "Prevents the Pokémon from\\nbeing controlled.":
        "Evita que el Pokémon\\nsea controlado.",
    "Boosts Speed when struck\\nby a Water-type move.":
        "Aumenta Velocidad al ser\\ngolpeado por movimiento Agua.",
    "Boosts Speed in sunshine.":
        "Aumenta la Velocidad\\nbajo la luz solar.",
    "Raises the encounter rate\\nof wild Pokémon.":
        "Aumenta la tasa de encuentros\\ncon Pokémon salvajes.",
    "Copies the foe's Ability.":
        "Copia la Habilidad\\ndel rival.",
    "Doubles the Attack stat.":
        "Duplica la estadística\\nde Ataque.",
    "Contact with the Pokémon\\nmay poison the attacker.":
        "El contacto puede envenenar\\nal atacante.",
    "Prevents flinching.":
        "Previene el retroceso\\ndel Pokémon.",
    "Prevents burns.":
        "Previene las quemaduras.",
    "Enables sure retreat from\\nwild Pokémon.":
        "Permite escapar de Pokémon\\nsalvajes sin fallar.",
    "Prevents accuracy drops\\nand ignores evasiveness.":
        "Evita bajadas de precisión\\ne ignora la evasión.",
    "Raises the critical-hit\\nratio.":
        "Aumenta la tasa de\\ngolpes críticos.",
    "Picks up items.":
        "Recoge objetos\\ndel suelo.",
    "The Pokémon loafs on every\\nother turn.":
        "El Pokémon holgazanea\\ncada dos turnos.",
    "Boosts the Speed stat in\\nbattle.":
        "Aumenta la estadística\\nde Velocidad en batalla.",
    "May attract Pokémon of\\nthe opposite gender.":
        "Puede atraer Pokémon\\ndel género contrario.",
    "The same type as another\\nability.":
        "Del mismo tipo que otra\\nhabilidad.",
    "Reverses stat changes.":
        "Invierte los cambios\\nde estadísticas.",
    "Changes with the weather.":
        "Cambia según\\nel clima.",
    "Prevents loss of held\\nitem.":
        "Evita la pérdida\\ndel objeto portado.",
    "Sheds the skin to recover\\nfrom status problems.":
        "Muda la piel para recuperarse\\nde problemas de estado.",
    "Raises Attack when\\nhurt by a status problem.":
        "Sube el Ataque al sufrir\\nun problema de estado.",
    "Raises Defense when\\nhurt by a status problem.":
        "Sube la Defensa al sufrir\\nun problema de estado.",
    "Passes on poison and\\nburn to the attacker.":
        "Transmite veneno y quemadura\\nal atacante.",
    "Boosts the power of\\nGrass-type moves.":
        "Potencia los movimientos\\nde tipo Planta.",
    "Boosts the power of\\nFire-type moves.":
        "Potencia los movimientos\\nde tipo Fuego.",
    "Boosts the power of\\nWater-type moves.":
        "Potencia los movimientos\\nde tipo Agua.",
    "Boosts the power of\\nBug-type moves.":
        "Potencia los movimientos\\nde tipo Bicho.",
    "Takes no recoil damage.":
        "No recibe daño\\nde retroceso.",
    "Summons sandstorm in\\nbattle.":
        "Invoca tormenta de arena\\nal entrar en combate.",
    "Puts heavy pressure on the\\nfoe, lowering its PP usage.":
        "Presiona al rival bajando\\nel uso de sus PP.",
    "Halves damage from Fire\\nand Ice-type moves.":
        "Reduce a la mitad el daño\\nde movimientos Fuego y Hielo.",
    "Enables the Pokémon to\\nalways act first.":
        "Permite al Pokémon actuar\\nsiempre en primer lugar.",
    "Burns the foe on contact.":
        "Quema al rival\\nal contacto.",
    "Makes fleeing from wild\\nPokémon easier.":
        "Facilita escapar de\\nPokémon salvajes.",
    "Prevents weakening of\\nthe Attack, Sp. Atk, or accuracy.":
        "Evita la bajada de Ataque,\\nAtk Especial o Precisión.",
    "Raises Attack when the\\nAbility Hyper Cutter is used.":
        "Sube el Ataque cuando\\nse usa Hipercorte.",
    "Enables the Pokémon to\\nfind items everywhere.":
        "Permite al Pokémon encontrar\\nobjetos en cualquier lugar.",
    "Raises SP. ATK when hit\\nby a Special Attack.":
        "Sube el Sp. Atk al ser\\ngolpeado por un Ataque Especial.",
    "Raises evasiveness in\\nsandstorms.":
        "Sube la Evasión durante\\nlas tormentas de arena.",
    "Raises evasiveness in\\nhailstorms.":
        "Sube la Evasión durante\\nlas tormentas de granizo.",
    "Eats held Berries earlier\\nthan usual.":
        "Come las Bayas portadas\\nantes de lo normal.",
    "Doubles the effect of\\na stat change.":
        "Duplica el efecto de\\nun cambio de estadística.",
    "Damage dealt to an\\nafflicted foe is doubled.":
        "El daño a un rival con\\nproblemas de estado se duplica.",
    "Passes on the held item\\neffect to an ally.":
        "Transmite el efecto del\\nobjeto portado a un aliado.",
    "Prevents the Pokémon\\nfrom being confused.":
        "Previene que el Pokémon\\nse confunda.",
    "Prevents other Pokémon\\nfrom lowering its stats.":
        "Evita que otros Pokémon\\nbajen sus estadísticas.",
    "Raises evasiveness\\nin rainy weather.":
        "Sube la Evasión\\nbajo la lluvia.",
    "Changes type based\\non the terrain.":
        "Cambia de tipo según\\nel terreno.",
    "Copies a fainted ally's\\nAbility.":
        "Copia la Habilidad de\\nun aliado desmayado.",
    "Passes on the Pokémon's\\nAbility when the Pokémon is hit.":
        "Transmite la Habilidad del\\nPokémon al ser golpeado.",
    "Boosts the power of\\nsuper effective moves.":
        "Potencia los movimientos\\nsúper eficaces.",
    "Negates all damage from\\nweather.":
        "Niega todo el daño\\ndel clima.",
    "Prevents all move\\nside effects.":
        "Previene todos los efectos\\nsecundarios de los movimientos.",
    "Boosts speed in harsh\\nsunlight.":
        "Aumenta la Velocidad\\nbajo luz solar intensa.",
    "Raises Defense and\\nSp. Def in a pinch.":
        "Sube Defensa y Def. Especial\\ncuando los PS son bajos.",
}

# =====================================================================
# DESCRIPCIONES DE OBJETOS
# Formato: 3 líneas, ~22 chars por línea
# =====================================================================
ITEM_DESCRIPTIONS = {
    "Heals all the\\nstatus problems of\\none Pokémon.":
        "Cura todos los problemas\\nde estado de un\\nsolo Pokémon.",
    "Use to flee from\\nany battle with\\na wild Pokémon.":
        "Úsalo para escapar de\\ncualquier combate con un\\nPokémon salvaje.",
    "Revives a fainted\\nPokémon with all\\nits HP.":
        "Revive a un Pokémon\\ndesmayado con todos\\nsus PS.",
    "An item that raises\\nthe base HP of\\na Pokémon.":
        "Objeto que sube los\\nPS base de\\nun Pokémon.",
    "An item that raises\\nthe base Attack of\\na Pokémon.":
        "Objeto que sube el\\nAtaque base de\\nun Pokémon.",
    "An item that raises\\nthe base Defense\\nof a Pokémon.":
        "Objeto que sube la\\nDefensa base de\\nun Pokémon.",
    "An item that raises\\nthe base Sp. Atk.\\nof a Pokémon.":
        "Objeto que sube el\\nAtk. Especial base\\nde un Pokémon.",
    "An item that raises\\nthe base Sp. Def.\\nof a Pokémon.":
        "Objeto que sube la\\nDef. Especial base\\nde un Pokémon.",
    "An item that raises\\nthe base Speed of\\na Pokémon.":
        "Objeto que sube la\\nVelocidad base de\\nun Pokémon.",
    "Restores the HP of\\none Pokémon by\\n20 points.":
        "Restaura los PS de\\nun Pokémon en\\n20 puntos.",
    "Restores the HP of\\none Pokémon by\\n50 points.":
        "Restaura los PS de\\nun Pokémon en\\n50 puntos.",
    "Restores the HP of\\none Pokémon by\\n200 points.":
        "Restaura los PS de\\nun Pokémon en\\n200 puntos.",
    "Fully restores the\\nHP of one\\nPokémon.":
        "Restaura completamente\\nlos PS de un\\nPokémon.",
    "Fully restores the\\nHP and PP of\\none Pokémon.":
        "Restaura completamente los\\nPS y PP de un\\nPokémon.",
    "Cures paralysis.":
        "Cura la parálisis.",
    "Cures a burn.":
        "Cura una quemadura.",
    "Thaws a frozen\\nPokémon.":
        "Descongela a un\\nPokémon congelado.",
    "Wakes the sleeping\\nPokémon.":
        "Despierta al Pokémon\\ndormido.",
    "Cures poison.":
        "Cura el veneno.",
    "Revives a fainted\\nPokémon with half\\nits max HP.":
        "Revive a un Pokémon\\ndesmayado con la mitad\\nde sus PS máximos.",
    "Raises the base\\nAttack stat of\\na Pokémon.":
        "Sube la estadística\\nbase de Ataque de\\nun Pokémon.",
    "Raises the base\\nDefense stat of\\na Pokémon.":
        "Sube la estadística\\nbase de Defensa de\\nun Pokémon.",
    "Raises the base\\nSpeed stat of\\na Pokémon.":
        "Sube la estadística\\nbase de Velocidad\\nde un Pokémon.",
    "Raises the base\\nSp. Atk stat of\\na Pokémon.":
        "Sube la estadística\\nbase de Atk. Especial\\nde un Pokémon.",
    "Raises the base\\nSp. Def stat of\\na Pokémon.":
        "Sube la estadística\\nbase de Def. Especial\\nde un Pokémon.",
    "Raises the base\\nHP stat of\\na Pokémon.":
        "Sube la estadística\\nbase de PS de\\nun Pokémon.",
    "Raises the level\\nof one Pokémon\\nby 1.":
        "Sube el nivel de\\nun Pokémon en\\n1 punto.",
    "Restores the PP of\\none move by\\n10 points.":
        "Restaura los PP de\\nun movimiento en\\n10 puntos.",
    "Fully restores the\\nPP of one\\nselected move.":
        "Restaura completamente los\\nPP de un movimiento\\nseleccionado.",
    "Restores the PP of\\none move by\\n10 points.":
        "Restaura los PP de\\nun movimiento en\\n10 puntos.",
    "Raises the PP of\\none move to\\nthe max.":
        "Eleva los PP de\\nun movimiento al\\nmáximo.",
    "Restores the HP of\\none Pokémon by\\n100 points.":
        "Restaura los PS de\\nun Pokémon en\\n100 puntos.",
    "A beverage that\\nrestores HP by\\n50 points.":
        "Bebida que restaura\\nlos PS en\\n50 puntos.",
    "A soda that\\nrestores HP by\\n60 points.":
        "Refresco que restaura\\nlos PS en\\n60 puntos.",
    "A drink that\\nrestores HP by\\n80 points.":
        "Bebida que restaura\\nlos PS en\\n80 puntos.",
    "A drink that\\nrestores HP by\\n100 points.":
        "Bebida que restaura\\nlos PS en\\n100 puntos.",
    "A spicy powder that\\nrestores HP but\\ncauses confusion.":
        "Polvo picante que\\nrestaurar PS pero\\ncausa confusión.",
    "A plant root that\\nrestores HP but\\ncauses confusion.":
        "Raíz que restaura\\nPS pero causa\\nconfusión.",
    "A bitter powder that\\ncures status problems.":
        "Polvo amargo que\\ncura problemas de\\nestado.",
    "A plant root that\\nrestores HP but\\ncauses confusion.":
        "Raíz que revive\\nPokémon desmayados pero\\ncausa confusión.",
    "Restores all the PP\\nof one move.":
        "Restaura todos los PP\\nde un movimiento.",
    "Restores all moves'\\nPP by 10.":
        "Restaura los PP de\\ntodos los movimientos\\nen 10.",
    "Restores all moves'\\nPP.":
        "Restaura los PP de\\ntodos los movimientos\\ncompletamente.",
    "A gift that warms\\nthe heart.":
        "Un regalo que\\ncalienta el corazón.",
    "A juice made from\\nberries. Slightly restores HP.":
        "Zumo hecho de bayas.\\nRestaurar ligeramente\\nlos PS.",
    "Sacred ash that\\nrevives all fainted\\nPokémon.":
        "Ceniza sagrada que\\nrevive a todos los\\nPokémon desmayados.",
}

# =====================================================================
# MENSAJES DE COMBATE (battle_message.c)
# =====================================================================
BATTLE_MESSAGES = {
    # Mensajes básicos de turno
    "What will\\n{B_PLAYER_NAME} do?":
        "¿Qué hará\\n{B_PLAYER_NAME}?",
    "{B_ATK_NAME_WITH_PREFIX}\\nused {B_CURRENT_MOVE}!":
        "{B_ATK_NAME_WITH_PREFIX}\\nusó {B_CURRENT_MOVE}!",
    "It's super effective!":
        "¡Es muy eficaz!",
    "It's not very effective...":
        "No es muy eficaz...",
    "It doesn't affect\\n{B_DEF_NAME_WITH_PREFIX}...":
        "No afecta a\\n{B_DEF_NAME_WITH_PREFIX}...",
    "{B_DEF_NAME_WITH_PREFIX}\\nfainted!":
        "{B_DEF_NAME_WITH_PREFIX}\\nse ha debilitado.",
    "{B_PLAYER_NAME} sent\\nout {B_ATK_NAME}!":
        "{B_PLAYER_NAME} envía a\\n{B_ATK_NAME}.",
    "Go! {B_ATK_NAME}!":
        "¡Adelante, {B_ATK_NAME}!",
    "{B_PLAYER_NAME} won\\nthe battle!":
        "¡{B_PLAYER_NAME} ha ganado\\nel combate!",
    "{B_PLAYER_NAME} is\\nout of usable Pokémon!":
        "¡{B_PLAYER_NAME} se ha\\nquedado sin Pokémon!",
    "A critical hit!":
        "¡Un golpe crítico!",
    "The wild {B_DEF_NAME}\\nfled!":
        "¡El {B_DEF_NAME} salvaje\\nha huido!",
    "Got away safely!":
        "¡Has escapado con éxito!",
    "Can't escape!":
        "¡No puedes escapar!",
    "{B_ATK_NAME_WITH_PREFIX}\\nhit itself in its\\nconfusion!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha dañado en\\nsu confusión.",
    "{B_ATK_NAME_WITH_PREFIX}\\nbecame confused!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha confundido.",
    "{B_ATK_NAME_WITH_PREFIX}\\nis confused!":
        "{B_ATK_NAME_WITH_PREFIX}\\nestá confundido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nconfusion wore off!":
        "La confusión de\\n{B_ATK_NAME_WITH_PREFIX}\\nha desaparecido.",
    "{B_DEF_NAME_WITH_PREFIX}\\nwas poisoned!":
        "{B_DEF_NAME_WITH_PREFIX}\\nha sido envenenado.",
    "{B_DEF_NAME_WITH_PREFIX}\\nwas badly poisoned!":
        "{B_DEF_NAME_WITH_PREFIX}\\nha sido gravemente\\nenvenenado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas burned!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sido quemado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas paralyzed!\\nIt may be unable to move!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sido paralizado.\\n¡Puede que no pueda moverse!",
    "{B_ATK_NAME_WITH_PREFIX}\\nfell asleep!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha dormido.",
    "{B_ATK_NAME_WITH_PREFIX}\\nis fast asleep.":
        "{B_ATK_NAME_WITH_PREFIX}\\nestá profundamente dormido.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwoke up!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha despertado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas frozen solid!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha congelado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nis frozen solid!":
        "{B_ATK_NAME_WITH_PREFIX}\\nestá congelado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nthawed out!":
        "{B_ATK_NAME_WITH_PREFIX}\\nse ha descongelado.",
    "{B_ATK_NAME_WITH_PREFIX}\\nis paralyzed! It\\ncan't move!":
        "{B_ATK_NAME_WITH_PREFIX}\\nestá paralizado. ¡No\\npuede moverse!",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas hurt by its\\nburn!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sufrido daño por\\nla quemadura.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas hurt by\\npoison!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sufrido daño por\\nel veneno.",
    "{B_ATK_NAME_WITH_PREFIX}\\nused {B_LAST_USED_MOVE}!":
        "{B_ATK_NAME_WITH_PREFIX}\\nusó {B_LAST_USED_MOVE}.",
    "But it failed!":
        "¡Pero ha fallado!",
    "But nothing happened!":
        "¡Pero no ha pasado nada!",
    "It had no effect!":
        "¡No ha tenido efecto!",
    "The attack missed!":
        "¡El ataque ha fallado!",
    "{B_ATK_NAME_WITH_PREFIX}\\navoided the attack!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha evitado el ataque.",
    "{B_ATK_NAME_WITH_PREFIX}\\nflinched and couldn't\\nmove!":
        "{B_ATK_NAME_WITH_PREFIX}\\nretrocedió y no ha\\npodido moverse.",
    "Trainer {B_TRAINER_CLASS}\\n{B_TRAINER_NAME}\\nwants to battle!":
        "¡El/la {B_TRAINER_CLASS}\\n{B_TRAINER_NAME} quiere\\ncombatir!",
    "Wild {B_DEF_NAME}\\nappeared!":
        "¡Apareció un {B_DEF_NAME}\\nsalvaje!",
    "{B_PLAYER_NAME} used\\n{B_LAST_ITEM}!":
        "{B_PLAYER_NAME} usó\\n{B_LAST_ITEM}.",
    "{B_ATK_NAME_WITH_PREFIX}\\ngained {B_EXP_POINTS}\\nExp. Points!":
        "{B_ATK_NAME_WITH_PREFIX} ganó\\n{B_EXP_POINTS} puntos\\nde Exp.",
    "{B_ATK_NAME_WITH_PREFIX}\\ngrew to Lv. {B_ATK_LV}!":
        "{B_ATK_NAME_WITH_PREFIX}\\nsubió al Nv. {B_ATK_LV}.",
    "{B_PLAYER_NAME}\\nthrew a {B_LAST_ITEM}!":
        "{B_PLAYER_NAME}\\nlanzó una {B_LAST_ITEM}.",
    "Gotcha! {B_CAPTURED_MON_NAME}\\nwas caught!":
        "¡Atrapado! ¡{B_CAPTURED_MON_NAME}\\nha sido capturado!",
    "Oh no! The Pokémon\\nbroke free!":
        "¡Oh no! ¡El Pokémon\\nse ha liberado!",
    "Aww! It appeared to\\ncatch the Pokémon!":
        "¡Estuvo a punto de\\ncapturar al Pokémon!",
    "Shoot! It was so\\nclose, too!":
        "¡Casi! ¡Estaba tan\\ncerca!",
    "It dodged the Ball!\\nThis Pokémon can't\\nbe caught!":
        "¡Ha esquivado la Ball!\\n¡Este Pokémon no puede\\nser capturado!",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAttack rose!":
        "El Ataque de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAttack sharply rose!":
        "El Ataque de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAttack fell!":
        "El Ataque de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAttack sharply fell!":
        "El Ataque de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nDefense rose!":
        "La Defensa de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nDefense sharply rose!":
        "La Defensa de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nDefense fell!":
        "La Defensa de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nDefense sharply fell!":
        "La Defensa de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSpeed rose!":
        "La Velocidad de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSpeed sharply rose!":
        "La Velocidad de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSpeed fell!":
        "La Velocidad de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSpeed sharply fell!":
        "La Velocidad de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Atk rose!":
        "El Atq. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Atk sharply rose!":
        "El Atq. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Atk fell!":
        "El Atq. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Def rose!":
        "La Def. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Def sharply rose!":
        "La Def. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido mucho.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nSp. Def fell!":
        "La Def. Esp. de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAccuracy rose!":
        "La Precisión de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nAccuracy fell!":
        "La Precisión de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nEvasiveness rose!":
        "La Evasión de\\n{B_ATK_NAME_WITH_PREFIX}\\nha subido.",
    "{B_ATK_NAME_WITH_PREFIX}'s\\nEvasiveness fell!":
        "La Evasión de\\n{B_ATK_NAME_WITH_PREFIX}\\nha bajado.",
    "Hail is falling!":
        "¡Está granizando!",
    "It's raining!":
        "¡Está lloviendo!",
    "The sandstorm is raging!":
        "¡La tormenta de arena\\nsigue en curso!",
    "The sunlight is strong!":
        "¡La luz solar es\\nmuy intensa!",
    "The hail continues to\\nfall!":
        "¡El granizo sigue\\ncayendo!",
    "The rain continues!":
        "¡La lluvia continúa!",
    "The sandstorm blows!":
        "¡La tormenta de\\narena arrecia!",
    "The harsh sunlight\\ncontinues!":
        "¡La intensa luz solar\\ncontinúa!",
    "The hail stopped!":
        "¡El granizo ha parado!",
    "The rain stopped!":
        "¡La lluvia ha parado!",
    "The sandstorm subsided!":
        "¡La tormenta de arena\\nha cesado!",
    "The sunlight faded!":
        "¡La luz solar ha\\ndesaparecido!",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas buffeted by\\nthe hail!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sufrido daño por\\nel granizo.",
    "{B_ATK_NAME_WITH_PREFIX}\\nwas buffeted by\\nthe sandstorm!":
        "{B_ATK_NAME_WITH_PREFIX}\\nha sufrido daño por\\nla tormenta de arena.",
}

# =====================================================================
# FUNCIONES DE APLICACIÓN
# =====================================================================

def backup_file(filepath):
    bak = filepath + ".bak_desc_" + datetime.now().strftime("%Y%m%d_%H%M%S")
    shutil.copy2(filepath, bak)
    return bak


def replace_compound_strings(content, translations, field="description"):
    """Reemplaza descripciones en bloques COMPOUND_STRING para un campo dado."""
    count = 0
    for en, es in translations.items():
        # Escapa el texto inglés para usarlo en regex
        en_escaped = re.escape(en).replace(r'\\n', r'\\\\n')
        # Patrón: .description = COMPOUND_STRING(\n    "linea1\\n"\n    "linea2"),
        # Simplificamos: buscamos COMPOUND_STRING("...texto...")
        pattern = r'(COMPOUND_STRING\s*\(\s*"' + en_escaped + r'"\s*\))'
        repl = 'COMPOUND_STRING("' + es + '")'
        new_content, n = re.subn(pattern, repl, content)
        if n > 0:
            count += n
            content = new_content
    return content, count


def replace_descriptions_multiline(content, translations, field=None):
    """
    Reemplaza descripciones en formato:
    .description = COMPOUND_STRING(...)
    .description = COMPOUND_STRING("line1\\n" "line2"),
    static const u8 sDesc[] = _("line1\\n" "line2");
    """
    count = 0
    for en, es in translations.items():
        en_parts = en.split("\\n")
        inner_pat = r'\\n"\s*\n?\s*"'.join(re.escape(p) for p in en_parts)

        # Si field está definido (ej. field='description' para structs)
        if field:
            pattern = (
                r'(\.' + re.escape(field) + r'\s*=\s*(?:COMPOUND_STRING|_)\s*\(\s*\n?\s*)'
                r'"' + inner_pat + r'"'
                r'(\s*\))'
            )
        else:
            pattern = (
                r'((?:COMPOUND_STRING|_)\s*\(\s*\n?\s*)'
                r'"' + inner_pat + r'"'
                r'(\s*\))'
            )

        es_parts = es.split("\\n")
        if len(es_parts) == 1:
            repl_inner = '"' + es_parts[0] + '"'
        elif len(es_parts) == 2:
            repl_inner = '"' + es_parts[0] + '\\\\n"\n        "' + es_parts[1] + '"'
        elif len(es_parts) == 3:
            repl_inner = (
                '"' + es_parts[0] + '\\\\n"\n        "' +
                es_parts[1] + '\\\\n"\n        "' +
                es_parts[2] + '"'
            )
        else:
            repl_inner = ('\\\\n"\n        "').join('"' + p for p in es_parts) + '"'

        repl = r'\g<1>' + repl_inner + r'\g<2>'
        new_content, n = re.subn(pattern, repl, content, flags=re.MULTILINE)
        if n > 0:
            count += n
            content = new_content
    return content, count


def apply_description_translations(filepath, translations, field=None, dry_run=False):
    """Aplica traducciones de descripciones."""
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    content, count = replace_descriptions_multiline(content, translations, field=field)

    if not dry_run and count > 0:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
    return count



def apply_simple_replacements(filepath, translations, dry_run=False):
    """Reemplaza strings simples en el archivo."""
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    for en, es in translations.items():
        if en in content:
            content = content.replace(en, es)
            count += 1

    if not dry_run and count > 0:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
    return count


def main():
    project_dir = sys.argv[1] if len(sys.argv) > 1 else "."
    dry_run = "--dry-run" in sys.argv

    if dry_run:
        print("[MODO SIMULACIÓN - No se escriben cambios]")

    moves_file     = os.path.join(project_dir, "src", "data", "moves_info.h")
    abilities_file = os.path.join(project_dir, "src", "data", "abilities.h")
    items_file     = os.path.join(project_dir, "src", "data", "items.h")
    battle_msg_file = os.path.join(project_dir, "src", "battle_message.c")

    print("=" * 60)
    print("  TRADUCCIONES FASE 1 - Descripciones y Mensajes de Combate")
    print("=" * 60)

    for label, filepath, func, trans, kwargs in [
        ("Descripciones de Movimientos", moves_file,
         apply_description_translations, MOVE_DESCRIPTIONS,
         {"field": "description"}),
        ("Descripciones de Habilidades", abilities_file,
         apply_description_translations, ABILITY_DESCRIPTIONS,
         {"field": "description"}),
        ("Descripciones de Objetos", items_file,
         apply_description_translations, ITEM_DESCRIPTIONS,
         {"field": None}),
        ("Mensajes de Combate", battle_msg_file,
         apply_simple_replacements, BATTLE_MESSAGES,
         {}),
    ]:
        if not os.path.exists(filepath):
            print(f"\n  [SKIP] {label}: archivo no encontrado")
            continue

        if not dry_run:
            bak = backup_file(filepath)
            print(f"\n  [BAK] {os.path.basename(bak)}")

        if kwargs:
            n = func(filepath, trans, dry_run=dry_run, **kwargs)
        else:
            n = func(filepath, trans, dry_run=dry_run)

        status = "OK" if n > 0 else "SIN CAMBIOS"
        print(f"  [{status}] {label}: {n} sustituciones")

    print("\n" + "=" * 60)
    print("  LISTO - Ejecuta 'make modern' para compilar")
    print("=" * 60)


if __name__ == "__main__":
    main()
