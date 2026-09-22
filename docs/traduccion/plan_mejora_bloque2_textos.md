# Plan de mejora de textos — Bloque 2

> Estado: preparado para ejecución. Este documento define el alcance y los
> criterios de revisión del recorrido entre Ruta 31, Ciudad Malva, Ruinas Alfa,
> Cueva Unión y Pueblo Azalea.

## Objetivo

Revisar el Bloque 2 con las reglas aprendidas durante la localización completa
de Johto. La revisión no consiste solo en eliminar inglés: debe mejorar la
naturalidad, conservar la intención de cada personaje y garantizar que los
textos funcionen dentro de las cajas de diálogo de GBA.

## Nuevas reglas obligatorias

1. Usar **BOLSA**, nunca `MOCHILA`, en toda la interfaz y los diálogos.
2. Mantener un máximo de **34 caracteres visibles** por línea; 35 solo cuando
   la composición visual haya sido comprobada expresamente.
3. Usar un único `\n` por párrafo. Las líneas posteriores usan `\l`; `\p`
   limpia la caja e inicia un nuevo párrafo.
4. Reservar entre cinco y siete caracteres para variables como `{PLAYER}` y
   `{STR_VAR_1}`. No contar el nombre de la macro como anchura real.
5. Conservar macros, etiquetas, terminadores `$`, flags y lógica de eventos.
6. Usar nombres oficiales españoles de movimientos y objetos, asociados por
   identificador; nunca traducir listas por posición.
7. Las descripciones técnicas de movimientos y objetos permanecen en inglés
   cuando así lo determine la regla general del proyecto.
8. Mantener `MT` y `MO` en los textos españoles. No traducir identificadores C.
9. Usar terminología estable: `Entrenador`, `LÍDER`, `GIMNASIO`, `CENTRO
   POKéMON`, `TIENDA POKéMON`, `Team Rocket`, `Bonguri` y nombres oficiales de
   lugares.
10. Conservar el tono macarra y agresivo del Rival, sin trasladarlo a otros
    personajes.
11. Evitar traducciones literales, palabras huérfanas después de un salto y
    repeticiones innecesarias. Priorizar frases naturales en castellano.
12. Auditar cada grupo con `docs/utilidades/auditar_textos_gba.ps1` antes de
    integrarlo.

## Alcance por grupos

### Grupo 1 — Ruta 31 y accesos a Malva

- [ ] `data/maps/Route31_hns/scripts.inc`
- [ ] `data/maps/Gate_Route31_VioletCity_hns/scripts.inc`

Revisar entrenadores, Wade, entrega de MT, carteles y continuidad con Cueva
Oscura. Confirmar que llamadas y revanchas conservan la misma voz.

### Grupo 2 — Ciudad Malva e interiores

- [ ] `data/maps/VioletCity_hns/scripts.inc`
- [ ] `data/maps/VioletCity_PokemonCenter_hns/scripts.inc`
- [ ] `data/maps/VioletCity_Mart_hns/scripts.inc`
- [ ] `data/maps/VioletCity_House1_hns/scripts.inc`
- [ ] `data/maps/VioletCity_House2_hns/scripts.inc`
- [ ] `data/maps/VioletCity_TrainerSchool_hns/scripts.inc`
- [ ] `data/maps/VioletCity_Gym_hns/scripts.inc`

Revisar la Academia, el intercambio de Onix, Pegaso, entrenadores del gimnasio,
Medalla Céfiro y recompensas. Unificar el tratamiento de profesor, alumno,
LÍDER y guía de gimnasio.

### Grupo 3 — Torre Bellsprout

- [ ] `data/maps/SproutTower_1F_hns/scripts.inc`
- [ ] `data/maps/SproutTower_2F_hns/scripts.inc`
- [ ] `data/maps/SproutTower_3F_hns/scripts.inc`

Mantener el tono sereno de los monjes y diferenciarlo claramente del Rival.
Revisar el discurso del Sabio Li y la entrega de la MT.

### Grupo 4 — Ruta 32 y accesos a Ruinas Alfa

- [ ] `data/maps/Route32_hns/scripts.inc`
- [ ] `data/maps/Route32_PokemonCenter_hns/scripts.inc`
- [ ] `data/maps/Gate_RuinsOfAlph_Route32_hns/scripts.inc`
- [ ] `data/maps/Gate_RuinsOfAlph_Route36_hns/scripts.inc`

Revisar al vendedor de Colaslowpoke, pescadores, Viki, la Caña Vieja y los
puestos fronterizos. Confirmar `BOLSA`, `MT`, nombres de objetos y precios.

### Grupo 5 — Ruinas Alfa

- [ ] `data/maps/RuinsOfAlph_Outside_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_Lab_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_B1F_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_PuzzleAndRewardChambers_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_WordsRoom1_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_WordsRoom2_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_WordsRoom3_hns/scripts.inc`
- [ ] `data/maps/RuinsOfAlph_WordsRoom4_hns/scripts.inc`

Mantener un registro arqueológico y misterioso. No traducir símbolos o claves
que formen parte de puzles sin verificar su efecto en el evento.

### Grupo 6 — Cueva Unión y Ruta 33

- [ ] `data/maps/UnionCave_1F_hns/scripts.inc`
- [ ] `data/maps/UnionCave_B1F_hns/scripts.inc`
- [ ] `data/maps/UnionCave_B2F_hns/scripts.inc`
- [ ] `data/maps/Route33_hns/scripts.inc`

Revisar Montañeros, Pescadores, revanchas, referencias a Lapras y transiciones
entre plantas. Evitar que las llamadas repitan textos de encuentro inicial.

### Grupo 7 — Pueblo Azalea

- [ ] `data/maps/AzaleaTown_hns/scripts.inc`
- [ ] `data/maps/AzaleaTown_PokemonCenter_hns/scripts.inc`
- [ ] `data/maps/AzaleaTown_Mart_hns/scripts.inc`
- [ ] `data/maps/AzaleaTown_House1_hns/scripts.inc`
- [ ] `data/maps/AzaleaTown_KurtsHouse_hns/scripts.inc`
- [ ] `data/maps/AzaleaTown_Gym_hns/scripts.inc`
- [ ] `data/maps/Gate_AzaleaTown_IlexForest_hns/scripts.inc`

Unificar `CÉSAR`, `Bonguri`, `Slowpoke`, `Team Rocket`, `ANTÓN`, Medalla
Colmena y MT Ida y Vuelta. Revisar especialmente el Rival antes del Encinar.

### Grupo 8 — Pozo Slowpoke

- [ ] `data/maps/SlowpokeWell_B1F_hns/scripts.inc`
- [ ] `data/maps/SlowpokeWell_B2F_hns/scripts.inc`

Mantener el tono amenazante de los Rocket sin mezclarlo con el registro del
Rival. Revisar a César herido, el corte de colas y el combate con Protón.

## Método de ejecución

Para cada grupo:

1. Comparar los textos actuales con su intención y con los personajes vecinos.
2. Registrar únicamente las entradas que requieren cambio.
3. Redactar la propuesta manteniendo el número de cajas cuando sea posible.
4. Aplicar cambios por etiqueta, nunca mediante reemplazos posicionales.
5. Ejecutar el auditor sobre las rutas del grupo.
6. Revisar el diff antes de pasar al grupo siguiente.

## Criterios de aceptación

- [ ] Cero inglés residual no intencionado.
- [ ] Cero segmentos de más de 35 caracteres; objetivo habitual de 34.
- [ ] Cero párrafos con más de un `\n`.
- [ ] Cero apariciones visibles de `MOCHILA`.
- [ ] Objetos y movimientos con nombre oficial y descripción correspondiente.
- [ ] Rival, Rocket, monjes, científicos y líderes con voces diferenciadas.
- [ ] Build completa correcta y ROM publicada en `releases/`.

## Resultado esperado

Un documento de propuestas por etiqueta, equivalente al del Bloque 1, seguido
de su aplicación, auditoría y publicación en una release propia del Bloque 2.

