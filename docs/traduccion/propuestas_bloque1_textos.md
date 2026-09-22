# Propuestas de ajuste de textos — Bloque 1

> Estado: aplicado íntegramente a la ROM el 22/09/2026.

## Objetivo

Reformular los diálogos del Bloque 1 para conservar la estructura visual inglesa, evitar palabras aisladas y mantener cada línea en un máximo aproximado de 34 caracteres.

- Referencia inglesa: commit c9d5bb3985.
- Se mantienen los saltos \\n, scrolls \\l y pausas \\p equivalentes.
- Se conserva el tono cani y agresivo acordado para Silver.
- Cada propuesta puede aprobarse, modificarse o descartarse de forma independiente.

## Criterio de revisión

- [x] Aprobar la propuesta completa.
- [ ] Aprobar solo algunas entradas.
- [ ] Pedir otra redacción para entradas concretas.

## Pueblo Primavera

### 1. NewBarkTown_Text_FatManState2

- Archivo: data/maps/NewBarkTown_hns/scripts.inc
- Líneas inglesas: **2**
- Líneas propuestas: **2**

```asm
.string "¡Vaya, qué POKéGEAR tan chulo!\n"
.string "¿Te lo ha regalado tu madre?$"
```

### 2. NewBarkTown_Text_FatManState3

- Archivo: data/maps/NewBarkTown_hns/scripts.inc
- Líneas inglesas: **3**
- Líneas propuestas: **3**

```asm
.string "¡Ey, {PLAYER}!\p"
.string "Dicen que el PROF. ELM halló\n"
.string "nuevos POKéMON.$"
```

### 3. NewBarkTown_Text_LassState2

- Archivo: data/maps/NewBarkTown_hns/scripts.inc
- Líneas inglesas: **5**
- Líneas propuestas: **5**

```asm
.string "¡Espera, {PLAYER}!\p"
.string "¡Salir sin un POKéMON puede\n"
.string "ser peligroso!\p"
.string "Los POKéMON salvajes salen\n"
.string "de la hierba camino de CEREZO.$"
```

### 4. NewBarkTown_Text_Silver2

- Archivo: data/maps/NewBarkTown_hns/scripts.inc
- Líneas inglesas: **1**
- Líneas propuestas: **1**

```asm
.string "…¿Tú qué miras, pringao?$"
```

La versión actual ocupa cinco líneas; esta conserva el golpe breve del original sin perder personalidad.

## Casa del jugador

### 5. NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou

- Archivo: data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc
- Líneas inglesas: **7**
- Líneas propuestas: **7**

```asm
.string "¡Ah, {PLAYER}! El PROF. ELM,\n"
.string "nuestro vecino, te está buscando.\p"
.string "Dice que necesita pedirte\n"
.string "un favor.\p"
.string "¡Casi lo olvido! Tu POKéGEAR\n"
.string "ya ha vuelto del taller.\p"
.string "¡Aquí tienes!$"
```

### 6. NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear

- Archivo: data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc
- Líneas inglesas: **4**
- Líneas propuestas: **4**

```asm
.string "MAMÁ: Los números se guardan\n"
.string "en la memoria.\p"
.string "Elige a quién quieres llamar.\p"
.string "¿A que es muy cómodo?$"
```

### 7. NewBarkTown_PlayersHouse_1F_Text_MomsFriend

- Archivo: data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc
- Líneas inglesas: **6**
- Líneas propuestas: **6**

```asm
.string "¡Hola, {PLAYER}!\p"
.string "¡He venido de visita!\p"
.string "¿Te has enterado?\p"
.string "Mi hija insiste en ser\n"
.string "ayudante del PROF. ELM.\p"
.string "¡Adora a los POKéMON!$"
```

### 8. NewBarkTown_PlayersHouse_1F_Text_MomLeaving

- Archivo: data/maps/NewBarkTown_PlayersHouse_1F_hns/scripts.inc
- Líneas inglesas: **10**
- Líneas propuestas: **10**

```asm
.string "MAMÁ: ¡Qué POKéMON tan bonito!\n"
.string "¿Dónde lo has conseguido?\p"
.string "…\p"
.string "Así que te vas de aventura…\n"
.string "No va a ser nada fácil…\p"
.string "Ten mucho cuidado.\p"
.string "Los POKéMON son tus amigos.\n"
.string "Debéis trabajar en equipo.\p"
.string "¡Venga, adelante!\n"
.string "¡Siempre contarás conmigo!$"
```

### 9. NewBarkTown_House2_Text_ElmsWife

- Archivo: data/maps/NewBarkTown_House2_hns/scripts.inc
- Líneas inglesas: **5**
- Líneas propuestas: **5**

```asm
.string "¡Hola, {PLAYER}! Mi marido está\n"
.string "muy ocupado… Espero que esté bien.\p"
.string "Cuando se centra en investigar\n"
.string "sobre POKéMON, hasta se\l"
.string "olvida de comer.$"
```

## Laboratorio de Elm

### 10. NewBarkTown_Lab_Text_ElmIntro

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **14**
- Líneas propuestas: **14**

```asm
.string "ELM: ¡{PLAYER}! ¡Ya estás aquí!\p"
.string "Quería pedirte un favor.\p"
.string "Ahora mismo estoy haciendo\n"
.string "un estudio sobre POKéMON. Me\l"
.string "gustaría que me ayudaras\l"
.string "con él, {PLAYER}.\p"
.string "Verás…\p"
.string "Estoy escribiendo un trabajo\n"
.string "para presentarlo en un congreso.\p"
.string "Pero todavía hay cosas\n"
.string "que no logro comprender.\p"
.string "¡Así que…!\p"
.string "Quiero que cuides de un\n"
.string "POKéMON que capturé hace poco.$"
```

### 11. NewBarkTown_Lab_Text_ElmMissionFromMrPokemon

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **14**
- Líneas propuestas: **14**

```asm
.string "Oye, escucha.\p"
.string "Tengo un conocido llamado\n"
.string "SR. POKéMON.\p"
.string "Siempre encuentra cosas raras y\n"
.string "presume de sus hallazgos.\p"
.string "Acaba de mandarme un correo\n"
.string "diciendo que esta vez\l"
.string "va en serio.\p"
.string "Es interesante, pero estamos\n"
.string "ocupados con el estudio…\p"
.string "¡Espera!\n"
.string "¡Ya lo tengo!\p"
.string "{PLAYER}, ¿puedes ir tú\n"
.string "en nuestro lugar?$"
```

### 12. NewBarkTown_Lab_Text_ElmDirections1

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **8**
- Líneas propuestas: **8**

```asm
.string "El SR. POKéMON vive algo más\n"
.string "allá de CEREZO, en la\l"
.string "ciudad siguiente.\p"
.string "El camino es casi recto,\n"
.string "no tiene pérdida.\p"
.string "Por si acaso, tienes mi\n"
.string "número. ¡Llámame si\l"
.string "ocurre cualquier cosa!$"
```

### 13. NewBarkTown_Lab_Text_ElmDirections2

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **6**
- Líneas propuestas: **6**

```asm
.string "Si aparece un POKéMON salvaje,\n"
.string "¡deja que el tuyo luche!\p"
.string "Si resulta herido, cúralo\n"
.string "con la máquina de mi derecha\l"
.string "o en un CENTRO POKéMON.\p"
.string "¡Cuento contigo!$"
```

### 14. NewBarkTown_Lab_Text_ElmAfterTheft4

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **21**
- Líneas propuestas: **21**

```asm
.string "Pero… ¿es un HUEVO POKéMON?\p"
.string "¡Si lo es, será todo\n"
.string "un descubrimiento!\p"
.string "ELM: ¡¿Cómo?!\p"
.string "¿El PROF. OAK te dio una POKéDEX?\p"
.string "{PLAYER}, ¿es verdad?\n"
.string "¡E-es increíble!\p"
.string "Sabe reconocer muy bien\n"
.string "el talento de un entrenador.\p"
.string "Vaya, {PLAYER}. Quizá puedas\n"
.string "llegar a ser CAMPEÓN.\p"
.string "Además, pareces llevarte muy\n"
.string "bien con los POKéMON.\p"
.string "Deberías aceptar el reto\n"
.string "de los GIMNASIOS.\p"
.string "El más cercano está en\n"
.string "CIUDAD MALVA.\p"
.string "…{PLAYER}. Llegar a CAMPEÓN\n"
.string "será un camino muy largo.\p"
.string "Antes de irte, no olvides\n"
.string "hablar con tu madre.$"
```

### 15. NewBarkTown_Lab_Text_ElmAideHasEgg

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **7**
- Líneas propuestas: **7**

```asm
.string "ELM: ¿{PLAYER}? ¿No viste\n"
.string "a mi ayudante?\p"
.string "Debía llevarte el HUEVO en\n"
.string "el CENTRO POKéMON\l"
.string "de CIUDAD MALVA.\p"
.string "Quizá os cruzasteis.\n"
.string "Intenta encontrarlo allí.$"
```

### 16. NewBarkTown_Lab_Text_ElmGiveEverstone2

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **7**
- Líneas propuestas: **7**

```asm
.string "Es una PIEDRAETERNA.\p"
.string "Algunos POKéMON evolucionan\n"
.string "al alcanzar cierto nivel.\p"
.string "Si llevan la PIEDRAETERNA,\n"
.string "no evolucionarán.\p"
.string "Dásela a quien no quieras\n"
.string "que evolucione.$"
```

### 17. NewBarkTown_Lab_Text_AideTheftTestimony

- Archivo: data/maps/NewBarkTown_Lab_hns/scripts.inc
- Líneas inglesas: **10**
- Líneas propuestas: **10**

```asm
.string "Se oyó un ruido muy fuerte\n"
.string "fuera…\p"
.string "Al salir a mirar,\n"
.string "alguien robó un POKéMON.\p"
.string "¡No puedo creer que alguien\n"
.string "hiciera algo así!\p"
.string "…Ese POKéMON robado.\p"
.string "Me pregunto cómo estará.\p"
.string "Dicen que un POKéMON criado\n"
.string "por alguien malo se vuelve malo.$"
```

## Ciudad Cerezo

### 18. CherrygroveCity_Text_GuideGentPokecenter

- Archivo: data/maps/CherrygroveCity_hns/scripts.inc
- Líneas inglesas: **5**
- Líneas propuestas: **5**

```asm
.string "Esto es un CENTRO POKéMON.\p"
.string "Curan a tus POKéMON en\n"
.string "un momento.\p"
.string "Los usarás a menudo,\n"
.string "así que conviene conocerlos.$"
```

### 19. CherrygroveCity_Text_GuideGentMart

- Archivo: data/maps/CherrygroveCity_hns/scripts.inc
- Líneas inglesas: **3**
- Líneas propuestas: **3**

```asm
.string "Esto es una TIENDA POKéMON.\p"
.string "Venden BALLS y otros objetos\n"
.string "que te serán muy útiles.$"
```

### 20. CherrygroveCity_Text_RivalSeen

- Archivo: data/maps/CherrygroveCity_hns/scripts.inc
- Líneas inglesas: **8**
- Líneas propuestas: **8**

```asm
.string "… … … … … … … …\p"
.string "Te dieron un POKéMON en el LAB.\p"
.string "Menudo desperdicio.\n"
.string "Con un pringao como tú.\p"
.string "… … … … … … … …\p"
.string "¿No pillas lo que te digo?\n"
.string "Yo sí tengo un POKéMON bueno.\p"
.string "¡Mira y aprende, payaso!$"
```

### 21. CherrygroveCity_Text_RivalAfter

- Archivo: data/maps/CherrygroveCity_hns/scripts.inc
- Líneas inglesas: **4**
- Líneas propuestas: **4**

```asm
.string "… … … … … … … …\p"
.string "¿Quieres saber quién soy?\p"
.string "Voy a ser el puto amo de\n"
.string "todos los entrenadores.$"
```

### 22. CherrygroveCity_Text_YoungsterHavePokedex

- Archivo: data/maps/CherrygroveCity_hns/scripts.inc
- Líneas inglesas: **5**
- Líneas propuestas: **5**

```asm
.string "Combatí con los entrenadores\n"
.string "del camino.\p"
.string "Mis POKéMON perdieron. ¡Están\n"
.string "hechos polvo! Debo llevarlos\l"
.string "al CENTRO POKéMON.$"
```

### 23. CherryGrove_Pokecenter_Text_Lass

- Archivo: data/maps/CherrygroveCity_PokemonCenter_hns/scripts.inc
- Líneas inglesas: **3**
- Líneas propuestas: **3**

```asm
.string "Dicen que mirar un reloj\n"
.string "ralentiza el tiempo; aquí\l"
.string "¡las horas pasan volando!$"
```

## Ruta 29

### 24. Route29_Text_OldManExplanation

- Archivo: data/maps/Route29_hns/scripts.inc
- Líneas inglesas: **8**
- Líneas propuestas: **8**

```asm
.string "Si antes los debilitas,\n"
.string "será más fácil atraparlos.\p"
.string "¡Luego lánzales una BALL\n"
.string "desde la BOLSA!\p"
.string "Si quieres saber más,\n"
.string "ve a la ACADEMIA de MALVA.\p"
.string "Sus alumnos saben mucho\n"
.string "sobre POKéMON.$"
```

### 25. Route29_Text_Youngster

- Archivo: data/maps/Route29_hns/scripts.inc
- Líneas inglesas: **3**
- Líneas propuestas: **3**

```asm
.string "¡Ey! ¿Cómo están tus POKéMON?\p"
.string "Si están débiles, evita\n"
.string "meterte en la hierba.$"
```

### 26. Route29_Text_Girl

- Archivo: data/maps/Route29_hns/scripts.inc
- Líneas inglesas: **2**
- Líneas propuestas: **2**

```asm
.string "Quería tomarme un descanso,\n"
.string "así que guardé mis avances.$"
```

## Ruta 30

### 27. Route30_BerryHouse_Text_MonEatBerries

- Archivo: data/maps/Route30_House_hns/scripts.inc
- Líneas inglesas: **11**
- Líneas propuestas: **11**

```asm
.string "Siguiendo el camino al norte,\n"
.string "verás la casa del SR. POKéMON.\p"
.string "Pero antes déjame hablarte\n"
.string "de las BAYAS.\p"
.string "Los POKéMON recuperan salud\n"
.string "cuando comen BAYAS.\p"
.string "También pueden comer las que\n"
.string "lleven durante el combate.\p"
.string "CÉSAR fabrica BALLS con BAYAS\n"
.string "en PUEBLO AZALEA.\p"
.string "¡Toma, te regalo una!$"
```

### 28. Route30_BerryHouse_Text_CheckTrees

- Archivo: data/maps/Route30_House_hns/scripts.inc
- Líneas inglesas: **2**
- Líneas propuestas: **2**

```asm
.string "Busca BAYAS en los árboles.\n"
.string "Vuelven a crecer en unas horas.$"
```

## Casa del señor Pokémon

### 29. MrPokemonHouse_Text_GotEgg

- Archivo: data/maps/Route30_MrPokemonsHouse_hns/scripts.inc
- Líneas inglesas: **1**
- Líneas propuestas: **1**

```asm
.string "¡Recibes el HUEVO MISTERIOSO!$"
```

Se elimina {PLAYER} para impedir que un nombre largo desborde la única línea disponible.

### 30. MrPokemonHouse_Text_OakIntro

- Archivo: data/maps/Route30_MrPokemonsHouse_hns/scripts.inc
- Líneas inglesas: **25**
- Líneas propuestas: **25**

```asm
.string "OAK: ¡Ajá! ¡Así que eres {PLAYER}!\p"
.string "¡Soy OAK, investigador POKéMON!\p"
.string "Visitaba a mi viejo amigo,\n"
.string "el SR. POKéMON.\p"
.string "Supe que hacías un recado\n"
.string "para ELM y esperé aquí.\p"
.string "¡Oh! ¡Un POKéMON muy raro!\p"
.string "Veamos…\n"
.string "Mmm, ¡ya entiendo!\p"
.string "Ya sé por qué ELM te dio\n"
.string "un POKéMON para el recado.\p"
.string "Para ELM y para mí,\n"
.string "los POKéMON son amigos.\p"
.string "Vio que tratarías al tuyo\n"
.string "con cariño y atención.\p"
.string "…¡Ah!\p"
.string "Pareces alguien de fiar.\n"
.string "¿Te gustaría ayudarme?\p"
.string "Mira, esta es la última\n"
.string "versión de la POKéDEX.\p"
.string "Registra datos de todos\n"
.string "los POKéMON vistos o atrapados.\p"
.string "¡Es una enciclopedia avanzada!\p"
.string "Muestra dónde viven, cómo\n"
.string "evolucionan y sus movimientos.$"
```

### 31. MrPokemonHouse_Text_OakParting

- Archivo: data/maps/Route30_MrPokemonsHouse_hns/scripts.inc
- Líneas inglesas: **6**
- Líneas propuestas: **6**

```asm
.string "¡Conoce muchos POKéMON y\n"
.string "completa esa POKéDEX!\p"
.string "Pero ya me he entretenido mucho.\p"
.string "Debo ir a CIUDAD TRIGAL\n"
.string "para mi programa de radio.\p"
.string "¡Cuento contigo, {PLAYER}!$"
```

## Resumen

- Propuestas redactadas: **31**.
- Líneas que superan 34 caracteres en este borrador: **0**.
- Propuestas cuyo número de líneas difiere del inglés: **0**.
- Cambios aplicados a los diálogos del Bloque 1: **31 de 31**.

## Resultado

Las 31 propuestas se han aplicado por etiqueta a sus archivos correspondientes.
El lote debe superar la auditoría de saltos, longitud e inglés residual antes de
publicar la siguiente ROM.
