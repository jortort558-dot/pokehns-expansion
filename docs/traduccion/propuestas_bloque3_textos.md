# Propuestas de ajuste de textos — Bloque 3

> Estado: borrador para revisión. Ninguno de estos textos se ha aplicado todavía a la ROM.

## Objetivo

Revisar el Bloque 3 real —Encinar, Ruta 34 y Ciudad Trigal— con el mismo criterio
empleado en el Bloque 1: traducción natural, estructura visual equivalente al
inglés y un máximo aproximado de 34 caracteres por línea.

- Se conservan variables, comandos y finales `\n`, `\l`, `\p` y `$`.
- Solo se permite un `\n` antes de cada `\p` o `$`; las líneas siguientes usan `\l`.
- Se emplean los nombres españoles oficiales de movimientos: `CONTONEO`,
  `DESENROLLAR`, `CORTEFURIA`, `MIMÉTICO`, `METRÓNOMO`, `SONÁMBULO`,
  `SUSTITUTO`, `PUÑO DINÁMICO`, `DOBLE FILO`, `EXPLOSIÓN` y `GOLPE CABEZA`.
- `BOLSA` sustituye siempre a `MOCHILA` y a `BAG`.
- Cada propuesta puede aprobarse, modificarse o descartarse de forma independiente.

## Criterio de revisión

- [ ] Aprobar la propuesta completa.
- [ ] Aprobar solo algunos apartados.
- [ ] Pedir otra redacción para entradas concretas.

## Hallazgos confirmados

La marca histórica del 100 % no era correcta. Se han confirmado estos bloques
visibles todavía en inglés:

| Zona | Fuente | Alcance confirmado |
|---|---|---|
| Tutores de movimientos | `data/text/move_tutors.inc` | Archivo compartido completo: 11 tutores y 45 mensajes |
| Guardería | `data/maps/Route34_DayCare_hns/scripts.inc` | Encargado, huevo, estados de recogida y reto de límite de equipo |
| Enciclopedia bebé | `src/data/help_window.h` | Cuatro ventanas completas |
| Cable Club | `data/text/cable_club.inc` y Centro Pokémon de Trigal | Flujo de conexión, combate, intercambio y explicaciones |
| Calles de Trigal | `GoldenrodCity_hns` | NPC junto al gimnasio y otros diálogos residuales |
| Centro Comercial | `GoldenrodCity_DepartmentStore_*_hns` | Plantas 2F–7F y sótano |
| Casino | `GoldenrodCity_GameCorner_hns` | Premios, NPC y tutorial de Voltorb Flip |
| Torre Radio | `GoldenrodCity_RadioTower_1F_hns` | Lotería, premios y diálogos Rocket residuales |

## Tutores de movimientos

Estas propuestas cubren primero los dos tutores detectados durante la partida.
Al aplicar el lote se traducirá también el resto del archivo compartido para que
ningún tutor conserve respuestas en inglés.

### 1. MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce

- Archivo: `data/text/move_tutors.inc`

```asm
.string "Este movimiento solo puede\n"
.string "aprenderse una vez. ¿De acuerdo?$"
```

### 2. MoveTutor_Text_FuryCutterTeach

- Archivo: `data/text/move_tutors.inc`

```asm
.string "Hay un movimiento que se vuelve\n"
.string "más fuerte si se usa seguido.\p"
.string "Es de tipo BICHO y mola un montón.\p"
.string "Se llama CORTEFURIA.\n"
.string "¿Quieres que se lo enseñe a uno?$"
```

### 3. MoveTutor_Text_FuryCutterDeclined

```asm
.string "No estamos en la misma onda.$"
```

### 4. MoveTutor_Text_FuryCutterWhichMon

```asm
.string "¡Bien!\n"
.string "¿A qué POKéMON se lo enseño?$"
```

### 5. MoveTutor_Text_FuryCutterTaught

```asm
.string "¡Me emociona ver si CORTEFURIA\n"
.string "sigue acertando una y otra vez!$"
```

### 6. MoveTutor_Text_HeadbuttTeach

- Archivo: `data/text/move_tutors.inc`

```asm
.string "¿Qué estoy haciendo?\p"
.string "Sacudo árboles con GOLPE CABEZA.\p"
.string "¿Tu POKéMON también querrá\n"
.string "dar cabezazos?\p"
.string "Puedo enseñarle GOLPE CABEZA.\n"
.string "¡Es divertido!$"
```

### 7. MoveTutor_Text_HeadbuttWhichMon

```asm
.string "¡Je, je! ¿A qué POKéMON quieres\n"
.string "que se lo enseñe?$"
```

### 8. MoveTutor_Text_HeadbuttDeclined

```asm
.string "No seas tímido.\n"
.string "¡Vamos a darnos cabezazos!$"
```

### 9. MoveTutor_Text_HeadbuttTaught

```asm
.string "Sacude árboles con GOLPE CABEZA.\n"
.string "A veces caerán POKéMON dormidos.$"
```

### 10. Cobertura obligatoria del archivo compartido

Se traducirán las cuatro respuestas de cada tutor, no solo el saludo inicial:

| Tutor | Etiquetas |
|---|---|
| Contoneo | `SwaggerTeach`, `SwaggerDeclined`, `SwaggerWhichMon`, `SwaggerTaught` |
| Desenrollar | `RolloutTeach`, `RolloutDeclined`, `RolloutWhichMon`, `RolloutTaught` |
| Cortefuria | `FuryCutterTeach`, `FuryCutterDeclined`, `FuryCutterWhichMon`, `FuryCutterTaught` |
| Mimético | `MimicTeach`, `MimicDeclined`, `MimicWhichMon`, `MimicTaught` |
| Metrónomo | `MetronomeTeach`, `MetronomeDeclined`, `MetronomeWhichMon`, `MetronomeTaught` |
| Sonámbulo | `SleepTalkTeach`, `SleepTalkDeclined`, `SleepTalkWhichMon`, `SleepTalkTaught` |
| Sustituto | `SubstituteTeach`, `SubstituteDeclined`, `SubstituteWhichMon`, `SubstituteTaught` |
| Puño Dinámico | `DynamicPunchTeach`, `DynamicPunchDeclined`, `DynamicPunchWhichMon`, `DynamicPunchTaught` |
| Doble Filo | `DoubleEdgeTeach`, `DoubleEdgeDeclined`, `DoubleEdgeWhichMon`, `DoubleEdgeTaught` |
| Explosión | `ExplosionTeach`, `ExplosionDeclined`, `ExplosionWhichMon`, `ExplosionTaught` |
| Golpe Cabeza | `HeadbuttTeach`, `HeadbuttDeclined`, `HeadbuttWhichMon`, `HeadbuttTaught` |

## Ruta 34 y Guardería

El criador situado fuera es `Route34_Text_PokefanBrandon_*` y ya aparece en
español en el código actual. El personaje que sigue en inglés es el encargado
de la Guardería, cuyo flujo comienza en `Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon`.

### 11. Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon

```asm
.string "Soy el ENCARGADO de la GUARDERÍA.\p"
.string "Cuido con mimo los POKéMON de\n"
.string "otros ENTRENADORES.\p"
.string "Si quieres que cuide del tuyo,\n"
.string "habla con mi mujer.$"
```

### 12. Route34_Text_DoYouWantEgg

```asm
.string "¡Ah, eres tú!\p"
.string "Estábamos cuidando de tus POKéMON\n"
.string "y nos llevamos una gran sorpresa.\p"
.string "¡Tus POKéMON tenían un HUEVO!\p"
.string "No sabemos cómo llegó hasta allí,\n"
.string "pero era de tus POKéMON.\p"
.string "Lo quieres, ¿verdad?$"
```

### 13. Route34_Text_YourMonIsDoingFine

```asm
.string "¡Ah, eres tú! Me alegro de verte.\n"
.string "Tu {STR_VAR_1} está de maravilla.$"
```

### 14. Route34_Text_FriendlyWithOtherTrainersMon

```asm
.string "Por cierto, tu {STR_VAR_1} parece\n"
.string "llevarse bien con el {STR_VAR_3}\l"
.string "de {STR_VAR_2}.\p"
.string "Creo que incluso recibió una\n"
.string "CARTA suya.$"
```

### 15. Route34_DayCare_Text_ClosedForChallenge

```asm
.string "Lo siento, durante un reto con\n"
.string "límite de equipo no podemos cuidar\l"
.string "de tus POKéMON.$"
```

### 16. HELP_DAYCARE1_WINDOW — Habilidades

- Archivo: `src/data/help_window.h`

```c
.header = COMPOUND_STRING("HABILIDADES DE POKéMON BEBÉ"),
.desc = COMPOUND_STRING("PICHU tiene ELECTRICIDAD ESTÁTICA.\n"
                        "CLEFFA tiene GRAN ENCANTO.\n"
                        "IGGLYBUFF tiene GRAN ENCANTO.\n"
                        "TYROGUE tiene AGALLAS.\n"
                        "SMOOCHUM tiene DESPISTE.\n"
                        "ELEKID tiene ELECTRICIDAD ESTÁTICA.\n"
                        "MAGBY tiene CUERPO LLAMA.")
```

### 17. HELP_DAYCARE2_WINDOW — Tipos

```c
.header = COMPOUND_STRING("TIPOS DE POKéMON BEBÉ"),
.desc = COMPOUND_STRING("PICHU es de tipo ELÉCTRICO.\n"
                        "CLEFFA es de tipo NORMAL.\n"
                        "IGGLYBUFF es de tipo NORMAL.\n"
                        "TYROGUE es de tipo LUCHA.\n"
                        "SMOOCHUM es de tipo HIELO.\n"
                        "ELEKID es de tipo ELÉCTRICO.\n"
                        "MAGBY es de tipo FUEGO.")
```

### 18. HELP_DAYCARE3_WINDOW — Gritos

```c
.header = COMPOUND_STRING("GRITOS DE POKéMON BEBÉ"),
.desc = COMPOUND_STRING("PICHU grita: ¡BUAAA!\n"
                        "CLEFFA grita: ¡IIIC!\n"
                        "IGGLYBUFF canta: ¡LALALA!\n"
                        "TYROGUE grita: ¡HIIIA!\n"
                        "SMOOCHUM ríe: ¡JE, JE!\n"
                        "ELEKID grita: ¡OI, OI, OI!\n"
                        "MAGBY hace: ¡TCH!")
```

### 19. HELP_DAYCARE4_WINDOW — Acciones

```c
.header = COMPOUND_STRING("ACCIONES DE POKéMON BEBÉ"),
.desc = COMPOUND_STRING("PICHU juega todo el día.\n"
                        "CLEFFA mira la luna.\n"
                        "IGGLYBUFF los duerme.\n"
                        "TYROGUE entrena sin parar.\n"
                        "SMOOCHUM presume encantado.\n"
                        "ELEKID acumula electricidad.\n"
                        "MAGBY se enfada a menudo.")
```

## Centro Pokémon y zona de conexión

### 20. GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro

```asm
.string "RINCÓN DE CONEXIÓN\p"
.string "ELIGE EL TIPO DE CONEXIÓN.$"
```

### 21. GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode

```asm
.string "ELIGE EL TIPO DE COMBATE.$"
```

### 22. GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye

```asm
.string "HASTA PRONTO.$"
```

### 23. GoldenrodCity_PokemonCenter_Text_LinkExplainer

```asm
.string "Esta máquina permite intercambiar\n"
.string "o combatir con jugadores cercanos.\p"
.string "¡La tecnología es increíble!$"
```

### 24. Cable Club compartido

- Archivo: `data/text/cable_club.inc`
- Alcance: traducir el flujo completo, no solo la recepcionista de Trigal.
- Incluye bienvenida, selección de servicio, guardado, errores de conexión,
  intercambio, combate individual/doble, Sala Unión, mezcla de récords y despedida.
- Se preservarán todas las etiquetas porque son consumidas por código común.

## Ciudad Trigal

### 25. GoldenrodCity_Text_Beauty

```asm
.string "¡Este es el GIMNASIO de TRIGAL!\p"
.string "BLANCA no está ahora mismo.\n"
.string "Quizá esté en la TORRE RADIO.$"
```

### 26. GoldenrodCity_Text_Woman

```asm
.string "Antes entrenaba en el GIMNASIO\n"
.string "de BLANCA, pero tanto llanto me\l"
.string "daba dolor de cabeza.$"
```

### 27. GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText

```asm
.string "Tú eres {PLAYER}, ¿verdad?\p"
.string "¡Enhorabuena!\p"
.string "Como regalo especial, han enviado\n"
.string "una GS BALL solo para ti.\p"
.string "¡Acéptala, por favor!$"
```

### 28. GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText

```asm
.string "¡Esperamos volver a verte!$"
```

## Subbloques que deben revisarse antes de aplicar

No se considerará terminado el Bloque 3 tras corregir únicamente los textos
anteriores. La pasada integral debe incluir:

1. `GoldenrodCity_DepartmentStore_2F_hns` a `7F_hns` y el sótano.
2. `GoldenrodCity_GameCorner_hns`, incluido el tutorial completo de Voltorb Flip.
3. `GoldenrodCity_RadioTower_1F_hns`, especialmente lotería y premios.
4. Todos los NPC de `GoldenrodCity_hns` y `GoldenrodCity_PokemonCenter_hns`.
5. `data/text/cable_club.inc` completo.
6. `data/text/move_tutors.inc` completo.
7. Los textos del resto del Bloque 3 que fallen la auditoría por inglés,
   longitud o saltos de línea, aunque no hayan sido señalados durante la partida.

## Criterio de aceptación

- Cero texto visible en inglés en los archivos del Bloque 3.
- Cero líneas de más de 34 caracteres, salvo macros cuyo ancho se compruebe aparte.
- Cero párrafos con más de un `\n` antes de `\p` o `$`.
- Todos los tutores muestran en español introducción, elección, rechazo y cierre.
- Guardería, enciclopedia bebé y flujo de conexión revisados en todas sus ramas.
- Compilación `make hns -j8` correcta tras la aplicación.

## Resumen

- Propuestas concretas redactadas en esta primera revisión: **28**.
- Fallos sistémicos confirmados: tutores, Guardería, enciclopedia bebé y Cable Club.
- Zonas amplias que requieren pasada completa: calles, Centro Comercial, Casino y Torre Radio de Trigal.
- Cambios aplicados a la ROM: **ninguno**.
