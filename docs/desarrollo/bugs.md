### 📦 Versión `v0.64.3`

- **Fecha:** 13/11/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Solución al bloqueo de acceso en sábado y regularización retroactiva de pases (Zona Safari y Concurso de Bichos)**:
    - **Causa raíz del bug**: En `src/clock.c`, las flags de entrada completada (`FLAG_SAFARI_ZONE_COMPLETED`, `FLAG_KANTO_SAFARI_ZONE_COMPLETED` y `FLAG_BUG_CONTEST_COMPLETED`) solo se reseteaban al cruzar la medianoche del viernes al sábado fuera de un Centro Pokémon. Al iniciar partida directamente en sábado, `VAR_DAYS` se inicializaba con el día actual y el reseteo no se disparaba, manteniendo el recinto cerrado.
    - **Sistema de Pases y Regularización Retroactiva**:
      - Se implementaron 3 variables de pases independientes: `VAR_POKEMITOS_BUG_CONTEST_TICKETS`, `VAR_POKEMITOS_SAFARI_JOHTO_TICKETS` y `VAR_POKEMITOS_SAFARI_KANTO_TICKETS`.
      - **Auditoría en C**: El juego computa los sábados transcurridos desde el inicio del torneo (10 de octubre de 2026) con fallback seguro de 5 semanas si el RTC falla o está desincronizado.
      - **Protección de partidas e inmunidad de huevos/regalos**: La rutina en C audita todas las cajas del PC y el equipo descartando expresamente huevos (`MON_DATA_IS_EGG`), Pokémon eclosionados (`metLevel == 0`) y regalos (`MON_DATA_GIFT_ORIGIN`).
      - Quienes ya capturaron en esas zonas no reciben tickets redundantes, mientras que los afectados por el bug reciben sus pases compensatorios acumulados.
      - Desbloqueo por hitos de ciudad: Parque Nacional/Trigal para Bichos, Orquídea/Safari para Johto, y Fucsia para Kanto.
    - **Ampliación interactiva del CARNET COPA**:
      - Al usar el `CARNET COPA` en la bolsa o con `SELECT`, se despliega un submenú interactivo con 4 opciones: *Pases y Capturas* (recuento en tiempo real de capturas y tickets disponibles), *Estado del Torneo*, *Reglas de la Copa* y *Cerrar Carnet*.
    - **Asistente del Locke**:
      - En todos los Centros Pokémon se añadió la opción `"Pases Torneo Pokémicos"`, que entrega el Carnet si no se tenía, audita la partida y acredita los pases pendientes.
    - **Puertas de entrada**:
      - Encargados de Parque Nacional, Safari Johto y Safari Kanto verifican el saldo de pases del carnet y descuentan 1 ticket al entrar, permitiendo jugar cualquier día.

### 📦 Versión `v0.64.2`

- **Fecha:** 13/11/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Solución al bucle de eclosión de huevos en Nuzlocke (reseteo a 256 pasos)**:
    - **Causa raíz**: En `src/daycare.c` (`TryProduceOrHatchEgg`), persistía una condición heredada de RHE que abortaba la eclosión (`return FALSE`) si el modo Nuzlocke estaba activo y la sección de mapa actual figuraba como consumida/gastada (`NuzlockeFlagGet`).
    - Al alcanzar los 0 pasos restantes, el contador interno de pasos de guardería se reseteaba a 0 y la función retornaba sin ejecutar la cinemática de eclosión, provocando que la interfaz del sumario volviera a mostrar de inmediato 256 pasos restantes en un ciclo infinito cada 256 pasos.
    - Se eliminó la comprobación obsoleta en `src/daycare.c`, alineándola con la regla oficial de Heart & Soul según la cual la eclosión de huevos no consume la captura de la ruta ni está condicionada por ella.

### 📦 Versión `v0.63.12`

- **Fecha:** 11/11/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Combate contra Los Papis en Monte Plateado (Giuseppe y Pilarito): opción de revancha interactiva tras perder**:
    - **Solución al bloqueo de revancha**: Si el jugador perdía el combate en la cinemática inicial, Giuseppe y Pilarito ejecutaban scripts estáticos con un único diálogo sin ofrecer revancha ni iniciar combate.
    - Se implementaron los flujos de revancha interactiva (`MSGBOX_YESNO`) tanto al interactuar con Giuseppe como con Pilarito, adaptados a sus respectivas personalidades.
    - Se añadió validación previa de combate doble (`special HasEnoughMonsForDoubleBattle`) para asegurar que el jugador cuente con al menos dos Pokémon conscientes.
    - Se incluyó recuperación automática del equipo (`special HealPlayerParty`) al aceptar el reto para mantener la coherencia narrativa de Los Papis (*"No queremos excusas"*).
    - Se unificó el desenlace victorioso hacia `MtSilver_Outside_EventScript_PapisDefeated`, garantizando la activación de `FLAG_JOHTO_LOS_PAPIS_DEFEATED`, la cinemática de marcha y el diálogo final con el Gran Sabio de Ciudad Orquídea.
  - [x] **Corrección de persistencia de sprites en la cumbre del Monte Plateado**:
    - En `MtSilver_Outside_EventScript_CheckPapis`, la recarga del mapa reasignaba por error los sprites de científicos (`OBJ_EVENT_GFX_SCIENTIST_*`). Ahora se preservan correctamente sus apariencias reveladas (`OBJ_EVENT_GFX_GENTLEMAN_HNS` y `OBJ_EVENT_GFX_WOMAN_1_HNS`) al reentrar a la zona.

### 📦 Versión `v0.63.11`

- **Fecha:** 08/11/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Nuzlocke: los Pokémon estáticos/legendarios con encuentro predestinado no consumen la ruta (Islas Espuma)**:
    - En `src/nuzlocke.c`, `SyncNuzlockeCaughtRoutes()` ahora filtra los Pokémon que poseen el flag `MON_DATA_MODERN_FATEFUL_ENCOUNTER` además de `MON_DATA_GIFT_ORIGIN`. Esto evita que al capturar un Pokémon estático (como Articuno o Groudon en Islas Espuma) se marque la ruta como gastada en el PC o equipo.
    - Se añadió protección adicional en `src/battle_main.c` para no marcar la ruta como consumida en combate si el Pokémon salvaje tiene `MON_DATA_MODERN_FATEFUL_ENCOUNTER`.
    - **Migración de partidas existentes (SAVE_VERSION 21)**: en `src/save.c`, se limpia la flag de encuentro de `MAPSEC_SEAFOAM_ISLANDS` y el estado de fichas de gimnasio para reactivar la zona en partidas existentes o en la siguiente run.
  - [x] **Regresión Primigenia de Groudon y Kyogre habilitada**:
    - Se activó `#define P_PRIMAL_REVERSIONS TRUE` en `include/config/species_enabled.h`.
    - Con esto se compilan las especies `SPECIES_GROUDON_PRIMAL` y `SPECIES_KYOGRE_PRIMAL`, sus tablas de cambio de forma en `src/data/pokemon/form_change_tables.h` asociadas al Prisma Rojo (`ITEM_RED_ORB`) y Prisma Azul (`ITEM_BLUE_ORB`), sus habilidades (Tierra del Ocaso, Mar del Albor), estadísticas y animaciones de reversión.
  - [x] **Solución a pantallazo azul por Cerrojo Feérico (Fairy Lock)**:
    - La animación de Cerrojo Feérico lanzaba múltiples tareas concurrentes de `AnimTask_VoltTackleBolt`, instanciando cadenas de 64x32 con una duración de 25 frames cada una. Esto desbordaba rápidamente el límite de 64 sprites del hardware de GBA (`SRC/SPRITE.C:434: OUT OF SPRITE SLOTS`).
    - En `src/battle_anim_electric.c`, se cambió la llamada de `CreateSprite` a `CreateSpriteUnchecked` para que la degradación sea segura sin provocar aserciones críticas si los slots están ocupados, y se redujo la vida útil de los sprites de las cadenas a 12 frames (consistente con Placaje Eléctrico / Choque Supremo) para evitar la acumulación excesiva en pantalla.

### 📦 Versión `v0.63.8`

- **Fecha:** 02/11/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Arca de Zygarde: forma completa accesible + submenús en castellano**:
    - El menú del Arca de Zygarde ahora muestra 4 opciones: **FORMA 10%**, **FORMA 50%**, **FORMA COMPLETA** y **CAMB. HABILIDAD** (antes sólo tenía 2 genéricas sin traducir).
    - `sZygardeCompleteFormChangeTable` ampliada con entradas `FORM_CHANGE_ITEM_USE_MULTICHOICE` para índices 0 y 1, permitiendo transformar la Forma Completa en 10% o 50% directamente desde el ítem.
    - Todas las tablas de forma de Zygarde actualizadas con los índices correspondientes al nuevo menú (0=10%, 1=50%, 2=Completa, 3=Habilidad).
    - Ventana del selector ampliada (`width=14, height=10`) para acomodar las 4+1 entradas sin desbordes.
    - Nuevas callbacks `CursorCb_Zygarde10`, `CursorCb_Zygarde50`, `CursorCb_ZygardeComplete` en [`src/party_menu.c`](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/party_menu.c); entradas de menú en [`src/data/party_menu.h`](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/data/party_menu.h).
  - [x] **Bug fix: los encuentros estáticos (legendarios y singulares) desaparecen si huyes**:
    - Si el jugador huye del combate o se teletransporta (`B_OUTCOME_RAN` o `B_OUTCOME_PLAYER_TELEPORTED`), el Pokémon estático desaparece definitivamente del mapa del supramundo (`removeobject` + `setflag` + fundido en negro + mensaje de huida) en lugar de permanecer en el mapa permitiendo reintentar el combate indefinidamente.
    - Aplicado a todos los mapas con combates legendarios y estáticos: Mewtwo (Cueva Celeste B2F), Rayquaza (Torre Oculta), Regis y Arceus (Ruinas de Sinjoh), Kyogre (Cueva Ruta 19), Groudon (Cueva Secreta Islas Espuma), Articuno (Islas Espuma B1F), Zapdos (Ruta 10), Moltres (Monte Plateado), Suicune (Ruta 25), Jirachi (Monte Moon), Celebi (Encinar), Latios y Latias (Isla del Sur), Ho-Oh (Torre Hojalata), Lugia (Islas Remolino), Tapu Lele (Akala), Tapu Koko (Melemele), Tapu Fini (Poni), Tapu Bulu (Ula-Ula), Lapras (Cueva Unión), Snorlax (Ciudad Carmín) y Pichu Picoreja (Bosque Verde).
  - [x] **Randomizer: encuentros fijos con semilla determinista**:
    - `CreateEnemyEventMon()` y `CreateScriptedWildMon()` usan ahora `RandomizeFixedEncounterMon()` (semilla por mapa+localId) en lugar de `RandomizeMon()` aleatorio puro, garantizando que el Pokémon estático randomizado sea siempre el mismo al reentrar a la sala si aún no se ha combatido.

### 📦 Versión `v0.58.2`

- **Fecha:** 16/10/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Corrección de nombres e iconos de vuelo en el Mapa de la Región / Menú de Vuelo**:
    - Se tradujeron todas las cadenas de las localidades y rutas de Kanto en `sRegionMapEntries_Johto[]` en `src/region_map.c`.
    - **Solución al bug de puntos de vuelo fantasma**: En el motor base de Emerald, los destinos no visitados se dibujaban con una animación (`shape += 3`), lo cual dibujaba puntos descolocados/incoherentes sobre el mapa en las posiciones aún no descubiertas. Se modificó `CreateFlyDestIcons()` para que únicamente instancie los sprites de las localidades ya visitadas (`FlagGet(sFlyLocations[i].flag)`), eliminando todos los puntos erráticos.
  - [x] **Disponibilidad completa del Ayudante de Nuzlocke en todos los Centros Pokémon**:
    - Se auditó y colocó al Ayudante de Nuzlocke/Fichas Pokemitos (`GoldenrodCity_PokemonCenter_EventScript_GymTokenClerk`) en los Centros Pokémon donde faltaba: Acceso a la Zona Safari de Johto, Pueblo Lavanda, Ruta 32, Ruta 4, Ruta 9, Monte Plateado, Nuevo Sinjoh y Frente de Batalla 1F.
    - Se verificaron sus coordenadas libres y transitables mediante el auditor de mapas.

### 📦 Versión `pokehns-v0.55.0-20261016-manolin-gimnasios-kanto-es.gba`

- **Fecha:** 16/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Integración de Manolín ("El Bate Mágico") en los 8 Gimnasios de Kanto**:
    - Manolín aparece en todos los gimnasios de Kanto creyendo por confusión que ha llegado a los gimnasios de la región de Hoenn.
    - Cura al equipo del jugador (`special HealPlayerParty`, `MUS_HEAL`) y entrega un objeto de cura (Poción Máxima en Carmín, Restaura Todo en los demás).
    - Ofrece un menú de elección exclusiva (`multichoice`) entre dos objetos competitivos/estratégicos:
      - Carmín (Malvalona/Erico): Seguro Debilidad vs Baya Pomar.
      - Azafrán (Algaria/Vito y Leti): Toxisfera vs Hierba Mental.
      - Azulona (Arborada/Alana): Llamasfera vs Roca Calor.
      - Fucsia (Lavacalda/Candela): Lodo Negro vs Baya Payapa.
      - Celeste (Arrecípolis/Plubio): Roca Lluvia vs Baya Gualot.
      - Plateada (Férrica/Petra): Botas Gruesas vs Roca Suave (sin caramelos raros ni elixires máximos).
      - Islas Espuma (Monte Cenizo): Botón Escape vs Roca Helada.
      - Ciudad Verde (Petalia/Norman): Baya Zidra vs Baya Aslac.
    - Se agregaron las flags correspondientes de curación e ítem en [flags_hns.h](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/include/constants/flags_hns.h) y las opciones en [script_menu.h](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/data/script_menu.h).
    - Coordenadas de los 8 eventos auditadas y verificadas con `auditar_posicion_mapa.ps1`.
  - [x] **Publicación**: Generada la release `releases/pokehns-v0.55.0-20261016-manolin-gimnasios-kanto-es.gba`, actualizada la versión en pantalla a `v0.55.0` (`HNS_VERSION_STRING`) y sincronizado con `pokehns_fase1.gba` y `pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.48.0-20261012-fix-rocket-safari-es.gba`

- **Fecha:** 12/10/2026
- **Mejoras y correcciones incluidas:**
  - [x] **Corrección del bloqueo por combate contra entrenadores inválidos en la Guarida Rocket de Pueblo Caoba (B1F)**:
    - En el evento de las estatuas de vigilancia Persian, el motor del script invocaba la macro `trainerbattle_no_intro` pasando variables de script (`VAR_TEMP_3` = 0x4003 y `VAR_TEMP_4` = 0x4004). Como dicha macro ensambla el byte literal en tiempo de compilación sin desreferenciar variables dinámicas, la ID del entrenador se interpretaba como 16387 (`0x4003`), superando `TRAINERS_COUNT` y disparando la pantalla azul de aserción `INCLUDE/DATA.H:248: INVALID TRAINER: 16387`.
    - Se refactorizaron las 5 rutinas de estatuas en ramas dedicadas con las constantes numéricas exactas (`TRAINER_GRUNT_13_HNS` a `TRAINER_GRUNT_18_HNS`), garantizando combates estables contra los reclutas con su equipo correspondiente.
  - [x] **Límite de participación única en la Zona Safari de Johto (Ruta 48 / Ciudad Orquídea)**:
    - Se implementó la flag `FLAG_SAFARI_ZONE_COMPLETED` (análoga a `FLAG_BUG_CONTEST_COMPLETED` del Concurso del Parque Nacional).
    - El mostrador de acceso en `SafariZoneGate_SafariZoneEntrance_hns` comprueba la flag antes de cobrar la entrada. Si el jugador ya ha participado, la recepcionista avisa amablemente de que la normativa del recinto solo permite una incursión en toda la aventura y cancela el paso.
    - La flag queda activada permanentemente al salir del recinto voluntariamente, por fin del contador de pasos o al quedarse sin Safari Balls.

### 📦 Versión `pokehns-0.46.0-20261011-nombres-entrenadores-y-mejoras-es.gba`

- **Fecha:** 11/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Localización canónica oficial en castellano de los entrenadores de Oro/Plata/Cristal**:
    - Joey -> Chano, Mikey -> Mauro, Albert -> Alberto, Gordon -> Gori, Don -> Rafa, Wade -> Tomy, Rod -> Rony, Abe -> Abel, Ralph -> Joserra, Liz -> Lisi, Anthony -> Luis, Todd -> Gorka, Irwin -> Rafi, Arnie -> Ángel, Alan -> Arturo, Dana -> Sara, Chad -> Javier, Derek -> Jonay, Tully -> Óscar, Brent -> Julio, Tiffany -> Vera, Vance -> Vidal, Wilton -> David, Kenji -> Leuco, Parry -> Ángelo, Erin -> Elisa, Jack -> Aitor, Beverly -> Julia, Huey -> Ken, Gaven -> Galo, Beth -> Tina, José -> José, Reena -> Tara (tanto en sus apariciones base como en todos sus niveles de revancha Pokégear).
  - [x] **Traducción del acertijo de la Guardería (Ruta 34)**:
    - Diálogos y ventana de ayuda traducidos íntegramente al castellano.
  - [x] **Textos de combate al despertar o descongelar**:
    - Mensajes traducidos al castellano (`STRINGID_PKMNWOKEUP`, `STRINGID_TARGETWOKEUP`, `STRINGID_PKMNWASDEFROSTED`).
  - [x] **Protección Nuzlocke en Prólogo**:
    - Muerte permanente y cementerio bloqueados hasta recibir las primeras Poké Balls (`FLAG_RECEIVED_FIRST_BALLS`).
  - [x] **Niños Rata Overworld**:
    - Incorporados en Pueblo Primavera, Ciudad Cerezo, Ciudad Malva (entrega Superpoción) y Pueblo Azalea (fan de Mohedano).
  - [x] **Turistas de Luminalia en Ciudad Malva**:
    - Ocultos hasta que se recibe la llamada del Pokégear (`FLAG_VIOLET_KALOS_CALL_TRIGGERED`).
  - [x] **El Piedras en el Centro Comercial de Trigal 2F**:
    - Permite rechazar la compra sin iniciar combate y cura al equipo Pokémon del jugador antes de la pelea si decides enfrentarte a él.
  - [x] **Científico de las Auroras Boreales en Trigal 7F**:
    - Añadido científico loco en la azotea del Centro Comercial buscando auroras boreales creyendo que está en Noruega.
  - [x] **Compatibilidad Universal con Randomlocke/Nuzlocke en Eventos de Especies**:
    - **Huevo de Elm (Pueblo Primavera)**: Elm reconoce si has eclosionado cualquier huevo (`PlayerHasHatchedAnyEgg`) además de la línea de Togepi, entregando la Piedraeterna sin bloqueos.
    - **Entrega de Carta en Ruta 31 (Kenya)**: Permite entregar a Kenya O entregar cualquier carta de la mochila/equipo (`PlayerHasAnyMail`), recibiendo la MT Descanso y **sin quitar nunca al Pokémon del equipo**.
    - **Paneles secretos de Ruinas Alfa**: Se abren teniendo al Pokémon en el equipo O si se ha combatido/capturado a Ho-Oh (`FLAG_CAUGHT_HO_OH` / `FLAG_DEFEATED_HO_OH`) o recogido los fósiles correspondientes (`FLAG_ITEM_OLD_AMBER`, `FLAG_ITEM_DOME_FOSSIL`, `FLAG_ITEM_HELIX_FOSSIL`).
    - **Sensores de Ruinas Sinjoh**: Reconocen a los Regis en el equipo O el despeje de sus salas de combate (`FLAG_HIDE_SINJOHRUINS_REGI*`).
    - **Elizabeth en Nueva Sinjoh**: Recompensa con Wooper de Paldea al llevar a Celebi O al haber capturado/vencido a Celebi en el Encinar (`FLAG_CAUGHT_CELEBI`).
  - [x] **Baneo Completo de la Habilidad Reflejar Daño (Innards Out) en Nuzlocke y Randomizer**:
    - **Randomizer**: Añadida a `IsAbilityIllegal` en [randomizer.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/randomizer.c) y eliminada de `ability_whitelist.h` para que nunca se asigne aleatoriamente a ningún Pokémon.
    - **Combate Nuzlocke**: En [battle_util.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/battle_util.c), si el modo Nuzlocke está activo (`IsNuzlockeActive()`), el efecto de daño pasivo de contragolpe de `ABILITY_INNARDS_OUT` queda completamente neutralizado para evitar muertes injustas e inevitables.


### 📦 Versión `pokehns-0.45.5-20261010-starters-overworld-es.gba`

- **Fecha:** 10/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Elección de Iniciales con Sprites Overworld en la mesa del Prof. Elm**:
    - Cada Pokéball en `NewBarkTown_Lab_hns` libera al Pokémon sobre la mesa al interactuar con ella (`SE_BALL_OPEN`), permitiendo tener a los tres iniciales fuera a la vez antes de decidir.
    - Los iniciales permanecen en el overworld hasta confirmar la elección; los no elegidos vuelven a sus Pokéballs tras la entrega.
    - Soporte completo y unificado para **Randomlocke** (`RANDOMIZE_STARTER_AND_GIFT_MON`) y **Monotipo**:
      - Conexión con `GetUniqueMonList` para garantizar que los 3 iniciales aleatorios sean siempre únicos y diferentes entre sí.
      - Eliminada la doble randomización en `showmonpic`, garantizando correspondencia 1:1 exacta entre el sprite overworld en la mesa, la ventana 2D, el grito y el Pokémon recibido.
  - [x] **Publicación**: publicada como `releases/pokehns-0.45.5-20261010-starters-overworld-es.gba` y sincronizada en `pokehns_fase1.gba` y `pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.44.4-20261009-persistencia-rocas-mareas-es.gba`

- **Fecha:** 09/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Persistencia de posición de rocas de Fuerza en el Santuario de las Tres Mareas**:
    - Al empujar cualquier roca en `CianwoodThreeTidesPuzzle_hns`, sus coordenadas se sincronizan de forma permanente en la plantilla del mapa mediante `OverrideTemplateCoordsForObjectEvent` dentro de `HandleBoulderActivateVictoryRoadSwitch` en [field_control_avatar.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/field_control_avatar.c).
    - La posición de las rocas **no se reinicia** al abrir la mochila, guardar la partida, combatir o cambiar de Pokémon mientras permanezcas en la cueva; únicamente vuelven a su posición inicial si decides abandonar la sala cruzando el warp exterior.
  - [x] **Claridad en la Inscripción de las Tres Mareas**:
    - Actualizado el texto del cartel para especificar explícitamente:
      > _“El orden no altera el flujo: guía cada peso a su vacío y cuando las tres descansen a la vez, el guardián romperá su velo.”_
  - [x] **Total compatibilidad con partidas guardadas anteriores (.sav)**:
    - No se han modificado estructuras de guardado (`SaveBlock1`, `SaveBlock2` o `SaveBlock3`), por lo que cualquier partida anterior `.sav` sigue siendo 100% compatible y funcional con esta ROM.
  - [x] **Publicación**: publicada como `releases/pokehns-0.44.4-20261009-persistencia-rocas-mareas-es.gba` y sincronizada en `pokehns_fase1.gba` y `pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.44.3-20261008-sprite-climax-los-papis-es.gba`

- **Fecha:** 08/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Sprite de batalla personalizado para el combate clímax (Los Papis: Giuseppe y Pilarito)**:
    - Integrado el sprite frontal propio `graphics/trainers/front_pics/los_papis_hns.png` (Giuseppe y Pilarito con el carrito de bebé) indexado fielmente a 16 colores compatibles con GBA y comprimido mediante `compresSmol` en `graphics/trainers/front_pics/los_papis_hns.4bpp.smol`.
    - Generada y vinculada su paleta dedicada `graphics/trainers/palettes/los_papis_hns.gbapal` (32 bytes).
    - Definida la constante `TRAINER_PIC_FRONT_LOS_PAPIS_HNS` en `include/constants/trainers.h` y registrada en la tabla `gTrainerSprites` en `src/data/graphics/trainers.h`.
    - Actualizado `src/data/trainers_hns.party` para que el entrenador `TRAINER_LOS_PAPIS_HNS` cargue `Pic: Los Papis Hns` en lugar del sprite genérico de Gentleman.
  - [x] **SAV de prueba sincronizado**: publicado como `releases/pokehns-0.44.3-20261008-sprite-climax-los-papis-es.sav` y vinculado a `pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.43.4-20261008-avatares-tormenta-bosque-dragon-es.gba`

- **Fecha:** 08/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **Arco de los Avatares Ancestrales - Progresión y encadenamiento**:
    - **Gran Sabio de las Mareas en Ciudad Orquídea (`(18, 19)`)**: Ahora verifica secuencialmente tus victorias frente a los avatares y va desbloqueando sus pistas y apariciones una por una.
    - **Avatar de la Tormenta (`TRAINER_AVATAR_TORMENTA_HNS`)**: Aparece en `LakeOfRage_hns` en `(16, 5)` tras vencer a la Marea. Equipo de nivel 41-43 (Raichu, Electivire, Magnezone, Gyarados, Mega-Ampharos).
    - **Avatar del Bosque (`TRAINER_AVATAR_BOSQUE_HNS`)**: Aparece en `IlexForest_hns` en `(30, 37)` junto al santuario tras vencer a la Tormenta. Equipo de nivel 43-45 (Roserade, Breloom, Trevenant, Tangrowth, Mega-Venusaur).
    - **Avatar del Dragón Primigenio (`TRAINER_AVATAR_DRAGON_HNS`)**: Aparece en `DragonsDen_Cavern_hns` en `(21, 13)` tras vencer al Bosque. Equipo de nivel 46-48 (Flygon, Altaria, Kingdra, Haxorus, Dragonite).
    - Cada avatar permanece oculto hasta que su predecesor ha sido derrotado y el Gran Sabio te guía hacia su paradero. Todas las casillas han sido auditadas estáticamente en colisiones y aproximaciones libres.

### 📦 Versión `pokehns-0.43.3-20261008-daraotaku-habilidades-es.gba`

- **Fecha:** 08/10/2026
- **Mejoras y contenido incluidos:**
  - [x] **DaraOtaku y Mori en la azotea del Centro Comercial de Azulona**:
    - Nuevo personaje ubicado en `(3, 5, elev: 3)` junto a su Growlithe Mori `(2, 5, elev: 3)` tanto en la versión diurna como nocturna del mapa (`RoofDay_hns` y `RoofNight_hns`), auditados estáticamente para libre acceso frontal.
    - Servicio de cambio de habilidades por **30.000¥**: permite despertar la habilidad secundaria ordinaria o la habilidad oculta de cualquier Pokémon elegible del equipo. Si un Pokémon ya posee la habilidad oculta, permite revertirla a su habilidad base.
  - [x] **Ajuste de dificultad en Randomizer de Entrenadores**: los entrenadores comunes de ruta (`TRAINER_TIER_REGULAR`) nunca reciben objetos equipados (`ITEM_NONE`), reservando los objetos competitivos y bayas exclusivamente para combates importantes (Líderes de Gimnasio, Alto Mando, Campeón, Rivales y Jefes).

### 📦 Versión `pokehns-0.40.22-20261001-megapiedras-items-comp-es.gba`

- **Fecha:** 01/10/2026
- **Arreglos y mejoras incluidos:**
  - [x] **Renderizado de Sprites de Megapiedras en Tienda**:
    - Corregido `BuyMenuAddItemIcon()` en `src/shop.c` para soportar `MART_TYPE_MEGA_STONES` cargando sus sprites de objeto adecuadamente mediante `AddItemIconSprite` en vez de tratarlas como decoraciones de base secreta.
    - Corregido glitch visual de fondo/marcos tras cerrar el modal informativo `{SELECT} Más info...` mediante `BuyMenuDrawGraphics()` en `CloseShopItemPopupInfo()`.
  - [x] **Singularidad de Objetos Competitivos en Randomizer (Item Clause)**:
    - Definido pool cerrado de 24 objetos competitivos de élite (`sCompetitiveItemsPool` en `src/data/randomizer/item_tiers.h`).
    - Implementado algoritmo de permutación determinista Fisher-Yates por semilla de partida (`GetRandomizedCompetitiveItem()` en `src/randomizer.c`).
    - Cada objeto competitivo aparece **exactamente una vez** en el mundo en los spawns competitivos sin posibilidad de duplicados, garantizando la equidad de cara al torneo.
    - Los drops de campo estándar que caen en Tier 4 se nutren de la lista `sItemTier4General` (Chupitos de IVs, PP Max, Sacred Ash, Pepitas gigantes y Chapas).

### 📦 Versión `pokehns-0.34.0-20260928-bar-subterraneo-trigal-es.gba`

- **Fecha:** 28/09/2026
- **Contenido y mejoras incluidas:**
  - [x] **Bar subterráneo de Ciudad Trigal**:
    - **Bartender Igor** (`OBJ_EVENT_GFX_ALOLA_OAK_HNS`): diálogo misterioso y guasón estilo Persona Velvet Room. Menú interactivo para cambiar Vales de Fiesta por Chupitos y Cubatas.
    - **Combates contra los guardias del bar**: dos nuevos entrenadores (Héctor y Darío) con 3 Pokémon temáticos de nivel 19-20.
    - **Pokéball de recompensa**: integrada en la pool de objetos de campo (`FLAG_ITEM_GOLDENROD_UNDERGROUND_BAR`) con Pepita.
  - [x] **Sistema de progresión de IVs**:
    - **Vale de Fiesta** (`ITEM_FESTIVAL_TICKET`): moneda de canje.
    - **6 Chupitos de IVs**: aumentan a 31 el IV individual seleccionado (`ITEM_CHUPITO_PS`, `ATK`, `DEF`, `SPATK`, `SPDEF`, `SPEED`).
    - **Cubata**: copa definitiva que maximiza de golpe las 6 estadísticas a 31 IVs (`ITEM_CUBATA`).
    - Lógica nativa completa en menú de equipo C (`Task_Chupito` / `ItemUseCB_Chupito`).
  - [x] Compilación y verificación limpias en WSL.

### 📦 Versión `pokehns-0.33.1-20260927-el-piedras-apariciones-es.gba`

- **Fecha:** 27/09/2026
- **Arreglos incluidos:**
  - [x] **Posición en el Lago de la Furia**: El Piedras se desplaza una casilla a la izquierda para quedar correctamente situado junto a la cabaña.
  - [x] **Continuidad entre apariciones**: al hablar con El Piedras en el centro comercial de Ciudad Trigal, deja de aparecer en la Escuela de Entrenadores de Ciudad Malva.
  - [x] Auditoría de textos y compilación completa verificadas correctamente.

### 📦 Versión `pokehns-0.33.0-20260926-randomizer-6cats-es.gba`

- **Fecha:** 26/09/2026
- **Mejoras incluidas:**
  - [x] **Rebalanceo de Randomizer Progresivo (6 categorías)**: se eliminó la categoría separada de pseudolegendarios (`CATEGORY_T4_PS`), pasando a computar de forma natural en `T4` por BST (>= 500) junto al resto de Pokémon fuertes.
  - [x] **Reducción de legendarios**: probabilidad de sublegendarios (`T5-SL`) reducida significativamente y legendarios mayores (`T5-L`) ajustados a porcentajes testimoniales en progresión ordinaria (0% hasta la 4ª medalla, 0.1% a 0.5% a mitad de juego y máximo 1-2% en postgame).

### 📦 Versión `pokehns-0.32.3-20260926-gyarados-activa-silver-es.gba`

- **Fecha:** 26/09/2026
- **Arreglo incluido:**
  - [x] **Activación garantizada de la historia**: interactuar con el Gyarados Rojo lanza el evento de Silver antes del encuentro si todavía no se recibió el Mega-Aro y el Pokémon con megapiedra. El trigger del camino se conserva como activación anticipada.

### 📦 Versión `pokehns-0.32.2-20260926-silver-lago-es.gba`

- **Fecha:** 26/09/2026
- **Arreglos incluidos:**
  - [x] **Silver visible antes de tiempo**: el mapa inicializa su flag de ocultación durante `MAP_SCRIPT_ON_TRANSITION`, también en partidas creadas antes de añadir el evento.
  - [x] **Activación de respaldo**: si Silver ya estaba cargado en el mapa por un save anterior, hablar con él inicia la escena en vez de mostrar un diálogo inerte.

### 📦 Versión `pokehns-0.32.1-20260926-trigger-megaevolucion-es.gba`

- **Fecha:** 26/09/2026
- **Arreglo incluido:**
  - [x] **Evento de Silver compatible con partidas existentes**: el trigger ya no exige que `VAR_MAHOGANY_TOWN_STATE` sea exactamente `1`; se activa mientras la historia de Caoba haya comenzado, el Gyarados siga presente y la recompensa no se haya recibido.

### 📦 Versión `pokehns-0.32.0-20260926-historia-megaevolucion-es.gba`

- **Fecha:** 26/09/2026
- **Contenido incluido:**
  - [x] **Evento de Silver en el Lago de la Furia**: escena narrativa previa al Gyarados Rojo con entrada, diálogo contemplativo y desafío obligatorio.
  - [x] **Primera Megaevolución de la historia**: tres equipos adaptados al inicial del jugador y Mega-Houndoom como último Pokémon de Silver.
  - [x] **Recompensas**: entrega del Mega-Aro y de un Pokémon aleatorio no legendario con su megapiedra equipada, compatible con envío al PC y reintento sin espacio.
  - [x] **Investigador de Ciudad Cerezo**: reconvertido en anticipo narrativo y retirado tras completar el evento.
  - [x] Auditoría de textos y compilación completa verificadas correctamente.

### 📦 Versión `pokehns-0.31.2-20260926-mt-shiny-random-es.gba`

- **Fecha:** 26/09/2026
- **Arreglos incluidos:**
  - [x] **MT/MO más amarillas**: los objetos del suelo usan el gráfico de la Level Ball, con mayor presencia de amarillo.
  - [x] **Persistencia tras combate**: el gráfico amarillo se recarga con un identificador propio al regresar al mapa y ya no vuelve a la Poké Ball roja.
  - [x] **Shiny aleatorio en Randomlocke**: los encuentros que son shiny por guion, como el Gyarados del Lago de la Furia, conservan el shiny pero aleatorizan su especie de forma determinista según la seed y el evento.
  - [x] Compilación completa verificada correctamente.

### 📦 Versión `pokehns-0.31.1-20260926-potencia-mt-amarillas-es.gba`

- **Fecha:** 26/09/2026
- **Commit:** `e8928fa9cd`
- **Arreglos incluidos:**
  - [x] **Potencia efectiva en combate**: ya no se presenta `potencia anterior>potencia nueva`. Se muestra únicamente la potencia resultante, en verde si aumenta y en rojo si disminuye.
  - [x] **Poké Ball amarillas para MT/MO**: ampliada la detección a `OBJ_EVENT_GFX_POKE_BALL`, utilizado por numerosos objetos de suelo de Heart & Soul, tanto al entrar en el mapa como al regresar a él.
  - [x] Las Poké Ball con objetos que no pertenecen al bolsillo MT/MO conservan su gráfico normal.
  - [x] Compilación completa verificada correctamente.

### 📦 Versión `pokehns-0.31.0-20260926-panel-combate-es.gba`

- **Fecha:** 26/09/2026
- **Commits:** `f82ea81157`, `09871be2fa`, `19f3443492`, `3aa9f0d18c`
- **Arreglos incluidos:**
  - Activado en la ROM el panel ampliado de información de combate, que estaba implementado pero excluido por configuración.
  - Al pulsar `START` sobre un movimiento se muestra su descripción y la potencia efectiva; desde esa pantalla, `L` abre el panel con cambios de estadísticas, clima y pantallas activas.
  - Corregida la integración que impedía compilar el sistema al activarlo: declaraciones auxiliares restauradas, cadenas dinámicas válidas y separadores compatibles con el motor de texto.
  - Compilación completa y limpia verificada correctamente.

# REGISTRO DE BUGS Y CONTROL DE VERSIONES

Este documento recopila las incidencias reportadas, clasificadas por su estado y agrupadas según la versión de la ROM (`.gba`) y el commit de GitHub donde fueron solventadas.

---

## 🟢 BUGS RESUELTOS POR VERSIÓN Y COMMITS

### 📦 Versión `pokehns-0.30.1-20260925-mt-amarillas-es.gba`

- **Fecha**: 25/09/2026
- **Commits**: `b7c1fab3b7` (preset bloqueado de PokemitosCup II),
  `04736b1430` (movimientos aleatorios al evolucionar), `1470dfbed7`
  (Poké Balls de MT y zonas Nuzlocke) y `817f6a2083` (carga efectiva de
  tiles y paleta amarillos en VRAM)

**Incidencias resueltas en esta build:**

- [x] **Poké Balls de MT**: el sprite amarillo se asigna según el objeto
      definitivo del suelo, incluido el resultado determinista del randomizador;
      los demás objetos conservan la Poké Ball normal.
- [x] **Zonas Nuzlocke falsas**: el selector de Fichas Gimnasio deja de reconstruir
      rutas a partir de todo el PC y usa exclusivamente las capturas registradas por
      el combate. También se ha limpiado el save distribuido que arrastraba bits
      espurios de una utilidad anterior.
- [x] **Ataques al evolucionar**: los movimientos aprendidos durante una
      evolución pasan por el randomizador igual que los aprendidos al subir de nivel;
      ya no se entregan los ataques oficiales de la especie evolucionada.
- [x] **Límite de nivel**: vuelve a poder activarse o cambiarse desde el menú
      de desafíos de una partida ya iniciada.
- [x] **PokemitosCup II**: Oak pregunta al confirmar el nombre si el jugador va
      a participar y, al aceptar, carga automáticamente el preset de referencia.
- [x] **Reglas bloqueadas**: las partidas de PokemitosCup no pueden modificar
      después el menú de desafíos desde ningún PC.
- [x] **Depuración bloqueada**: el modo Copa impide abrir el menú debug del
      mapa, el acceso integrado en el menú de inicio y el debug de combate.
- [x] **Compatibilidad de guardado**: añadida una marca persistente sin aumentar
      el tamaño de los ajustes y migración segura de las partidas anteriores.
- [x] **Save solicitado**: aplicado el preset al `.sav` de la versión 0.27,
      conservando el progreso de rutas Nuzlocke y regenerando ambos checksums.

### 📦 Versión `pokehns-0.27.0-20260925-randomizers-configurables-es.gba`

- **Fecha**: 25/09/2026
- **Commits**: `42b7355017` (opciones y lógica) y `82cb8b8803`
  (compatibilidad del layout de guardado)

**Incidencias resueltas en esta build:**

- [x] **Partidas antiguas**: el menú del PC permite activar el randomizer maestro
      y el de entrenadores aunque estuvieran desactivados en el `.sav` original.
- [x] **Entrenadores configurables**: añadidas opciones independientes para
      potencia de especies, objetos equipados y uso de Megaevoluciones.
- [x] **Progresión final**: el bloque postgame se activa al derrotar cualquiera
      de las dos variantes de Red, no al convertirse en Campeón de Kanto.
- [x] **Pokémon salvajes**: `POTENCIA SALVAJE` permite elegir progresión por
      aventura o distribución caótica sin alterar slots, niveles ni frecuencias.
- [x] **Objetos**: revisados los textos y el funcionamiento de progresión, MT,
      Megapiedras y objetos competitivos del menú inicial.
- [x] **Guardado**: migración a versión 10 sin aumentar los 32 bytes de ajustes;
      los nuevos campos conservan el comportamiento progresivo en saves antiguos.
- [x] **ROM y save**: publicada la ROM junto a un `.sav` compatible con objetos
      del suelo, Pokémon salvajes y entrenadores aleatorios activados.

### 📦 Versión `pokehns-0.25.0-20260925-bloques4-5-revision-es.gba`

- **Fecha**: 25/09/2026
- **Commits**: `32ea69b6c2` (revisión integral), `69d9cfdf5a` (estructura del
  ermitaño de Orquídea) y `d7ef0b4bb8` (caracteres compatibles con GBA)

**Incidencias resueltas en esta build:**

- [x] **Bloque 4**: rehechos y contrastados con la referencia inglesa todos los
      NPC, entrenadores, carteles, ramas y textos contiguos de sus 59 mapas.
- [x] **Bloque 5**: revisados Ruta 42, Monte Mortero, Ruta 43, Lago de la Furia,
      Pueblo Caoba, Guarida Rocket, Gimnasio Caoba, invasión de Trigal, Torre Radio
      y subterráneo.
- [x] **Formato GBA**: corregidos desbordes, saltos de línea defectuosos,
      fragmentos aislados y signos no admitidos por el mapa de caracteres.
- [x] **Casa del ermitaño de Orquídea**: restaurada la estructura de scripts que
      impedía ensamblar `event_scripts.o`.
- [x] **Nombres propios**: sustituido el nombre incorrecto «Euskadi» por
      **Eusine** en todos los textos y documentos afectados.
- [x] **Validación**: 92 archivos superan la auditoría de textos; build HnS
      completa con código 0.
- [x] **ROM**: publicada como
      `releases/pokehns-0.25.0-20260925-bloques4-5-revision-es.gba` y actualizada
      `pokehns_fase1.gba`.

### 📦 Versión `pokehns-0.23.0-20260923-fichas-iris-textos-es.gba`

- **Fecha**: 23/09/2026
- **Commit**: `f6bdce7f05` (`fix: corregir fichas y completar textos de Iris`)

**Incidencias resueltas en esta build:**

- [x] **Crash al canjear una captura**: el selector de rutas reserva una única lista del tamaño exacto, usa los nombres del mapa activo y deja de fragmentar la memoria antes de abrirse.
- [x] **Intercambio con Fichas Gimnasio**: la partida se guarda antes de iniciar la escena de intercambio y vuelve a guardarse al completarla.
- [x] **Encuentros estáticos**: los combates salvajes iniciados por script, incluido Sudowoodo, ya no consumen la captura de la ruta.
- [x] **Textos puntuales**: traducidos la niña de la floristería y el mensaje «¿Usar otro Pokémon?» tras una derrota.
- [x] **Descripciones de objetos**: las 860 entradas conservan su frase completa y respetan ahora un máximo de 6 líneas de 25 caracteres; corregido el recorte visible de Tecno-ROM y casos equivalentes.
- [x] **Ciudad Iris**: revisados y reformateados la ciudad, sus edificios, Torre Quemada, Torre Hojalata y rutas próximas; 28 archivos superan la auditoría de longitud, saltos e inglés residual.
- [x] **Pokégear y acompañante**: traducidos los 156 textos de llamadas y revanchas y las 138 reacciones del Pokémon acompañante.
- [x] **Validación**: auditorías de textos y descripciones sin incidencias; build HnS completa con código 0.
- [x] **ROM**: publicada como `releases/pokehns-0.23.0-20260923-fichas-iris-textos-es.gba` y actualizada `pokehns_fase1.gba`.

### 📦 Versión `pokehns-0.22.0-20260923-descripciones-oficiales-objetos-es.gba`

- **Fecha**: 23/09/2026
- **Commit**: `84d8b576a8` (`fix: restaurar descripciones oficiales de objetos`)

**Incidencias resueltas en esta build:**

- [x] **Descripciones oficiales recuperadas**: sustituidas las traducciones compactadas de la versión 0.21.0 por textos oficiales castellanos completos siempre que existe fuente oficial.
- [x] **Objetos de expansión y HNS**: adaptados desde su función completa cuando no existe descripción oficial, sin suprimir frases ni efectos.
- [x] **Espacio ampliado sin recortes**: mochila, tiendas, PC, Pirámide Batalla y almacenamiento usan la fuente compacta; cada descripción admite hasta 6 líneas de 29 caracteres.
- [x] **Auditoría final**: 860/860 descripciones presentes, 0 fuera de los nuevos límites y compilación completa correcta.

### 📦 Versión `pokehns-0.21.0-20260923-descripciones-objetos-completas-es.gba`

- **Fecha**: 23/09/2026
- **Commit**: `277a7d82e5` (`feat: completar descripciones de objetos en espanol`)

**Incidencias resueltas en esta build:**

> Sustituida por la versión 0.22.0: la compactación de esta build eliminaba información o producía textos poco naturales.

- [x] **Descripciones de objetos completas**: adaptadas al castellano las 860 entradas de `src/data/items.h`.
- [x] **Espacio original respetado**: ninguna descripción supera el número de líneas ni los caracteres por línea de su equivalente inglés.
- [x] **Ramas condicionales**: traducidas también las descripciones alternativas de Balls, medicinas, objetos X, auxiliares, MT de Hielo, Rocío Bondad y Hierba Mental.
- [x] **Auditoría final**: `Pendientes idénticas al inglés: 0` y `0 incidencias`.

### 📦 Versión `pokehns-0.20.4-20260923-descripciones-objetos-es.gba`

- **Fecha**: 23/09/2026
- **Commit**: `5047d9ac71` (`fix: ajustar descripciones de objetos al espacio ingles`)

**Incidencias resueltas en esta build:**

- [x] **Descripciones de objetos**: corregidos 110 desbordes de línea en textos ya traducidos, manteniendo el efecto de cada objeto.
- [x] **Textos híbridos**: eliminados restos como `but` y `one.` en Caramelo Raro y objetos de entrenamiento de EV.
- [x] **Auditoría automática**: las 860 descripciones respetan como máximo las líneas y caracteres de su equivalente inglés; el PokéVial usa límites explícitos al ser propio del proyecto.
- [x] **Estado medible**: el auditor informa también de las descripciones todavía idénticas al inglés para abordar la traducción restante por lotes seguros.

### 📦 Versión `pokehns-0.9.0-20260920-bloque6-endrino-es.gba`

- **Fecha**: 20/09/2026
- **Commit**: `2552c7f702` (`feat: indicador nuzlocke en start menu, capturas, evolucion, veto OHKO y fixes Azalea`)

**Contenido traducido en esta build:**

- [x] **Ruta 44 y Ruta Helada**: Entrenadores, carteles, Chica Kimono, puzles y eventos de Pokémon.
- [x] **Ciudad Endrino**: Exterior, casas, tienda, Centro Pokémon y servicios Quita/Recuerda-Movimientos.
- [x] **Gimnasio Endrino**: Entrenadores dragón, Débora, rechazo inicial de la medalla, revancha y guía.
- [x] **Guarida Dragón**: Entrenadores, Rival, prueba del Maestro, Medalla Dragón y entrega de Dratini.
- [x] **Auditoría técnica**: 16 mapas revisados sin cadenas inglesas detectadas, concatenaciones defectuosas ni líneas superiores a 35 caracteres.

### 📦 Versión `pokehns-0.8.1-20260920-bloque2-revision-es.gba`

- **Fecha**: 20/09/2026
- **Commit**: `2552c7f702` (incluye la revisión de mapas y el lote de Endrino)

**Incidencias resueltas en esta build:**

- [x] **Ruta 33**: Traducidos el Montañero Anthony, sus revanchas y la entrenadora situada tras Cueva Unión.
- [x] **Cueva Unión**: Revisadas las tres plantas, corregida terminología y reformulados diálogos incoherentes.
- [x] **Ruinas Alfa y Pueblo Azalea**: Traducidas las cadenas inglesas restantes en B1F, laboratorio, cámaras, Casa de César, carbonería y eventos del Encinar.
- [x] **Formato del Bloque 2**: Corregidas cadenas concatenadas y textos de más de 35 caracteres en Ruta 32, Torre Bellsprout, Ruinas Alfa, Cueva Unión y Azalea.
- [x] **Sincronización**: Añadidos Ruta 33 y Ruinas Alfa B1F a `sync_latest.ps1` y corregida una coma ausente en la lista de archivos.

### 📦 Versión `pokehns-0.8.0-20260920-nuzlocke-ui-bugfix-es.gba`

- **Fecha**: 20/09/2026
- **Commit**: `2552c7f702`

**Incidencias resueltas en esta build:**

- [x] **Indicador Nuzlocke por zona**: El popup del nombre muestra una Poké Ball cuando la oportunidad de captura de la zona ya está consumida.
- [x] **Chica de la Ruta 36**: Corregido el salto de diálogo de Growlithe.
- [x] **Objetos modernos reportados**: Traducidos plumas, cápsulas y parches de habilidad, mentas, caramelos, chapas, confites, semillas, Moneda Gimmighoul, teralitos y mochis.
- [x] **MT y MO**: Renombradas las MT visibles y traducidos sus mensajes de uso.
- [x] **Pokégear**: Traducidos menús, ayudas, teléfono, nombres del mapa, emisoras y programas de radio.
- [x] **Clases de entrenador**: Traducidas las clases visibles; los nombres propios se conservan.
- [x] **Combate y captura**: Traducidos los mensajes reportados de victoria, derrota, empate, captura, Pokédex y petición de mote.
- [x] **Pantalla de motes**: Traducidos títulos y controles.
- [x] **Movimientos de campo**: Traducidos avisos de Corte, Golpe Roca, Golpe Cabeza, Fuerza, Cascada, Buceo, Torbellino y Treparrocas.
- [x] **Cueva Unión**: Traducidos los entrenadores de las tres plantas.

### 📦 Versión `pokehns-0.6.2-20260920-bugfix2-es.gba`

- **Commit WSL / GitHub**: `c15764d` (`traduccion-es`)
- **Commit Windows**: `65050f37de` (`Completar traduccion de Ruinas Alfa, casas y tiendas de Malva y Azalea, y ajustar lineas de dialogo`)
- **Fecha**: 20/09/2026

**Incidencias resueltas en esta build:**

- [x] **Ruinas Alfa sin traducir**: Traducidos todos los científicos, entrenadores, textos de fósiles y cámaras de puzles (`RuinsOfAlph_Outside_hns`, `RuinsOfAlph_Lab_hns`, `RuinsOfAlph_PuzzleAndRewardChambers_hns`).
- [x] **NPCs pendientes en Ciudad Malva**: Traducida la chica ("She uses the names of her favorite things to eat"), habitantes de casas y dependientes de tiendas y centro pokémon.
- [x] **Pueblo Azalea y Ruta 32**: Traducidos carbonería, casa de César, pescadores y tiendas.
- [x] **Auditoría de textos cortados / incompletos del Bloque 2**: Revisadas y reajustadas todas las frases que desbordaban la caja de diálogo (0 líneas superiores a 35 caracteres en todo el Bloque 2).

---

### 📦 Versión `pokehns-0.6.1-20260920-bugfix1-es.gba`

- **Commit WSL / GitHub**: `30b768a` (`traduccion-es`)
- **Commit Windows**: `5404e1c075` (`Corregir bugs reportados: BOY/GIRL, muebles, PC, items, bayas, combates y textos de Ciudad Malva y Bloque 2`)
- **Fecha**: 20/09/2026

**Incidencias resueltas en esta build:**

- [x] **Selección Chico/Chica**: `BOY` y `GIRL` cambiados a `CHICO` y `CHICA` al iniciar nueva partida (`src/strings.c`).
- [x] **Muebles y PC**: Librerías, estanterías y floreros en español (`data/text/check_furniture.inc`); menús y opciones de PC en español (`data/text/pc.inc`, `src/player_pc.c`).
- [x] **Árboles de bayas**: Cadenas completas de recolección y brote de bayas traducidas (`data/scripts/berry_tree.inc`).
- [x] **Combates y Repartir Exp.**: Mensaje de aviso de cambio de Pokémon del rival y texto del Repartir Exp. traducidos (`src/battle_message.c`).
- [x] **Corrección en Ciudad Malva**: Corregido error tipográfico `PEGABLO` $\rightarrow$ `PEGASO` y textos de la Academia Pokémon (`Route31_hns/scripts.inc`).
- [x] **Lote 1 de objetos**: Antiparalizador, Shalour Sable y Muscle Feather traducidos en `src/data/items.h`.

---

### 📦 Versión `pokehns-0.5.0-20260920-bloque4-es.gba`

- **Commit Windows**: `287bb0c47f` (`quitados movs mega y gigamax de la pool`) y `93ee5eb305`
- **Fecha**: 20/09/2026

**Incidencias resueltas en esta build:**

- [x] **Randomizer**: Quitar ataques Z y ataques Max de la pool de movimientos del Randomizer (acotado estrictamente a Gen 9 estándar, 1 hasta 847 en `src/randomizer.c`).

---

### 📦 Versiones Iniciales y Fase 1 (`pokehns_fase1.gba` / Commits Base)

- **Commits**: `1b1838c4d2`, `d04b772790`, `501577b488`, `de13653c95`, `0d6be416da`, `074c9e0a58`

**Incidencias resueltas:**

- [x] Primer diálogo para poner la hora en el reloj.
- [x] Información del reloj tras configurar la hora.
- [x] Mensajes previos del menú Nuzlocke.
- [x] Texto en inglés inicial del Profesor Oak.
- [x] Carteles flotantes de ciudades y rutas.
- [x] Categoría de especie del inicial (ej. "POKéMON HOJA" en vez de "LEAF").
- [x] Mensajes de obtención de objetos ("recibes la poción...").
- [x] Interfaz y menús base de combate.
- [x] Mensajes de la televisión.
- [x] Diálogos de compra/venta de las Tiendas Pokémon.
- [x] Diálogos de enfermeras en Centros Pokémon.
- [x] Diálogo de cura de la madre en casa del jugador.
- [x] Mensaje de guardado de partida.
- [x] Bolsa durante el combate.
- [x] Mensaje al recibir el dinero tras vencer en combate.
- [x] Mensaje al registrar a un entrenador en el Pokénav.
- [x] Opciones "SÍ" y "NO" (sustituyendo "YES" y "NO").
- [x] Puestos fronterizos entre rutas (Gates del Bloque 1 y 2).
- [x] Diálogos de la Ruta 46 junto a Cueva Oscura.
- [x] Ajuste visual de solapamiento en ficha de datos ("PODER").

### Versión 0.10.0 (2026-09-20 - Nuzlocke, Combates, Evolución y Ajustes Azalea)

- **Commit**: `2552c7f702`

- [x] **Indicador Nuzlocke en el menú START**: Retirada la Poké Ball del popup de mapa y añadido indicador de zona (`ZONA: LIBRE` en verde / `ZONA: GASTADA` en rojo) en la ventana superior del reloj al abrir el menú START.
- [x] **Capturas y fallos de Poké Ball**: Traducido `¡Ya está! ¡{STR_VAR_1} atrapado!` (`GOTCHA!`), y mensajes de captura fallida (`¡Casi lo consigues!`, `¡Vaya! ¡El POKéMON se ha escapado!`, etc.).
- [x] **Combates dobles traducidos**: Mensajes de salida simultánea al combate y retirada traducidos al castellano.
- [x] **Evolución Pokémon traducida**: Mensajes de inicio (`¿Eh? ¡{STR_VAR_1} está evolucionando!`) y finalización (`¡Enhorabuena! ¡Tu {STR_VAR_1} ha evolucionado a {STR_VAR_2}!`) completamente en español.
- [x] **Team Rocket y César en el Pozo Slowpoke**: Textos corregidos y refactorizados a <= 34 caracteres por línea sin desbordes.
- [x] **Rival en Pueblo Azalea**: Textos ajustados sin cortes de caja.
- [x] **Gimnasio de Pueblo Azalea (Antón / Bugsy)**: Nombres corregidos y formateo de diálogos de batalla y medalla ajustados.
- [x] **Filtro OHKO en Nuzlocke**: Prohibidos los movimientos de KO en un golpe (`Guillotina`, `Perforador`, `Fisura`, `Frío Polar`) en la ruleta del randomizer de movimientos cuando el modo Nuzlocke está activo (sin eliminarlos del juego base).

---

- [ ] **Auditoría completa de expansión**: Todavía existen cadenas inglesas no reportadas en sistemas secundarios y mensajes modernos. Se tratarán por bloques para poder revisarlas dentro del juego.

### Lote de sistemas auditados — commit `a70c7e43ee`

- [x] **Mensajes de combate secundarios**: Auditadas y traducidas 475 cadenas de estadísticas, habilidades, climas, terrenos, objetos, mecánicas residuales y sistemas modernos.
- [x] **Almacenamiento y flujo posterior de captura**: Traducidos el envío al PC, el cambio automático de CAJA, las CAJAS llenas y la elección entre equipo y PC.
- [x] **Menú del Pokégear**: Rótulos gráficos sustituidos por MAPA y PERFIL POKéMON; ayudas, marcas, cintas y descripciones traducidas.
- [x] **Mapas de los Centros Pokémon**: Interfaz común traducida y acción {R_BUTTON} FLY sustituida por {R_BUTTON} VOLAR.
- [x] **Aprendizaje de movimientos**: Traducidos Uno, dos, y... ¡tachán!, el olvido, sustitución, rechazo y confirmación del nuevo movimiento.
- [x] **Alineación del menú de combate**: MOCHILA y HUIR desplazados cuatro píxeles a la izquierda para evitar el recorte.
- [x] **Efectos de combate básicos**: Traducidos retroceso, Púas, Drenadoras, clima, objetos dañinos, congelación y Salazón.
- [x] **Huevos y capturas Nuzlocke**: Eclosionar un huevo ya no consume la captura de la zona ni altera el indicador del menú.

- [x] **Menú de combate — MOCHILA/HUIR**: Restaurada la separación original de la columna derecha para que el cursor no tape la H.
- [x] **Madre del jugador**: Traducidos los diálogos del sistema de curación, ahorros, depósitos y retiradas.
- [x] **PC del dormitorio**: Traducido el arranque del PC y las opciones restantes del buzón.
- [x] **Orden del panel START**: POKéVIAL aparece encima del estado de captura de la zona; fuera de Nuzlocke ya no queda un hueco sobre el contador.
- [x] **Controles de combate**: SELECT activa la Mega, START vuelve a mostrar la descripción del movimiento y se desactiva la reordenación de movimientos durante el combate.

### PokéVial — commit `64acf3d547`

- [x] **Cargas del PokéVial en START**: Ampliado el panel superior y añadido el contador visible VIAL: actual/máximo.

### Traducción general y aleatorizador — commits `c5e9635c5e` y `6dc957770b`

- [x] **Nombres de movimientos**: corregida la desalineación desde
      `MOVE_SHORE_UP`; Campo Psíquico y otros 260 movimientos vuelven a corresponder
      con su identificador y descripción.
- [x] **BOLSA**: sustituido todo el texto visible `MOCHILA` por `BOLSA` para
      evitar problemas de espacio.
- [x] **Nombres de objetos**: traducidos los objetos estándar que seguían en
      inglés, incluidos FulgoROM, Blanco, Disco Psíquico y Caña Vieja.
- [x] **MT/MO aleatorias**: excluidas del aleatorizador de objetos de campo;
      permanecen en sus ubicaciones originales y todas siguen siendo obtenibles.
- [x] **Mejora del Bloque 1**: aplicadas las 31 propuestas y superada la
      auditoría de longitud, saltos e inglés residual.

- [x] **Bloque 3 — tutores de movimientos**: traducidos los once tutores y
      todas sus ramas, incluidos Golpe Cabeza y Cortefuria.
- [x] **Bloque 3 — Guardería**: traducidos el encargado, las ramas restantes
      y las cuatro fichas de Pokémon bebé; el criador exterior ya estaba correcto.
- [x] **Bloque 3 — conexión**: traducidos el Rincón de Conexión y el archivo
      compartido `data/text/cable_club.inc` completo.
- [x] **Bloque 3 — Ciudad Trigal**: revisados calles, Centro Pokémon, Centro
      Comercial, Casino, Voltorb Flip, Torre Radio y subterráneo.

Validación: auditoría de **67 archivos** del Bloque 3 sin incidencias.

Propuestas y alcance: `docs/traduccion/propuestas_bloque3_textos.md`.

## BUGS para más tarde

Rediseñar a KNEKRO ya que al hacerlo más pequeño se ha quedado bastante regular.

- [ ] **Auditoría completa de expansión**: todavía pueden quedar cadenas inglesas no reportadas en sistemas secundarios y contenido moderno. Se revisarán por bloques.

- [x] **Ayudante del Locke en Centros Pokémon**: encargado reconvertido en asistente integral de servicios con: - Recordador de movimientos gratuito (por nivel, preevoluciones y MT obtenidas; sin movimientos huevo ni tutores exclusivos). - Menú de Fichas Gimnasio integrado. - Información de líderes de gimnasio y límites de nivel dinámicos (`BufferLevelCapSummary`). - Diálogo placeholder para futuras recompensas por logros en retos Locke.
- [x] **Selector de rutas de la ficha de gimnasio**: resuelta la causa por la que no aparecían rutas disponibles. Añadida la función `SyncNuzlockeCaughtRoutes` que recorre el equipo y las cajas del PC leyendo `MON_DATA_MET_LOCATION` de todos los Pokémon atrapados para registrarlos en `nuzlockeEncounterFlags`. Además, se garantiza el acceso al canje si el jugador posee fichas (`gymTokens.count > 0`).
- [x] **Prohibición de comprar objetos curativos en tiendas (Nuzlocke)**: añadida la opción `CURAS TIENDA` (PROHIBIR / PERMITIR) en el menú de retos (pestaña Nuzlocke) en `ChallengeSettings.tx_Nuzlocke_BanHealingShop`. En las tiendas normales, si la opción está activa y se juega en Nuzlocke, se filtran automáticamente todos los artículos del bolsillo medicina (`GetItemPocket(item) == POCKET_MEDICINE`).
- [x] **Traducción de MOs en el overworld**: traducidos los textos de interacción con agua de `data/text/surf.inc` al español ("El agua es de un azul intenso… ¿Quieres usar SURF?"). Corregido en `data/scripts/field_move_scripts_hns.inc` el texto de Buceo que erróneamente mostraba "TORBELLINO".

### Análisis técnico: Descripciones de objetos (5 líneas vs 6 líneas y ventana de expansión)

En la interfaz de la Bolsa (`src/item_menu.c`), la ventana de descripción `WIN_DESCRIPTION` está acotada físicamente a:

- Ancho: 14 tiles (112 píxeles).
- Alto: 6 tiles (48 píxeles), situada en `tilemapTop = 13` (hasta el borde inferior de la pantalla a 160 px).
- Tipografía: `FONT_SMALL_NARROWER`, que requiere ~9-10 píxeles por línea con interlineado.
- En 48 píxeles verticales solo caben cómodamente 5 líneas de texto (5 x 9 = 45 px). Al llegar a 6 líneas, el texto se corta o se solapa con el marco inferior de la ventana.

**Cómo lo resuelven otros proyectos (CFRU / pokeemerald-expansion)**:

1. **Ventana emergente (Info Box / Pop-up Window)**: Al pulsar un botón de ayuda (ej. `SELECT` o botón `A` sobre la opción "INFO" del menú contextual), el juego suspende la lista del inventario y abre una ventana modal de gran tamaño (28x14 tiles = 224x112 px) sobre el fondo de la pantalla. Allí se imprime la descripción completa y extendida (efectos en combate, fuera de combate, compatibilidades, etc.) y se cierra al pulsar `A` o `B`.

- [x] **Crash / Freeze en 2º intento de captura (Fichas Gimnasio)**:
  - **Causa raíz identificada**: El macro `dynmultistack` en `asm/macros/event.inc` emitía una palabra NULL (`.4byte 0`) al final del bytecode del script. En `src/scrcmd.c` (`ScrCmd_dynmultichoice`), si el siguiente elemento era NULL, la función no lo consumía con `ScriptReadWord(ctx)`. Al reanudar el script, el motor intentaba interpretar esos 4 bytes de ceros como opcodes, desalineando los argumentos subsiguientes y provocando un salto fatal a memoria corrupta (`Jumped to invalid address: E55EC002`).
  - **Solución aplicada**: Se añadió `ScriptReadWord(ctx);` en la rama de `dynmultistack` en `src/scrcmd.c` para consumir limpiamente la palabra de terminación, restableciendo la alineación del intérprete de scripts tras seleccionar la ruta.
- [x] **Ventana modal emergente de descripción de objetos (Botón R)**:
  - **Comportamiento en Bolsa**: En `WIN_DESCRIPTION` (esquina inferior izquierda), las descripciones largas se truncan a 4 líneas y en la 5ª línea se añade el indicador `"{R_BUTTON} Ver detalles..."`, garantizando que nunca se desborden ni corten las 5 líneas útiles de la ventana estándar.
  - **Ventana emergente modal (`ITEMWIN_POPUP_INFO`)**: Al pulsar `{R_BUTTON}` en cualquier objeto de la lista, se abre una ventana modal centrada de 26x16 tiles (208x128 px) que muestra el nombre del objeto resaltado, la categoría del bolsillo, una línea separadora decorativa, la descripción completa y extendida formateada a lo ancho (`WrapFontIdToFit` a 194 px), y el pie de navegación `"{A_BUTTON}/{B_BUTTON}/{R_BUTTON} VOLVER"`. Se ocultan temporalmente los sprites de la bolsa para evitar solapamientos y se reanuda la navegación estándar al cerrarla.
  - **Botón asignado**: Se liberó `{R_BUTTON}` del cambio de bolsillos (el cambio de bolsillo sigue operando cómodamente mediante `{DPAD_LEFT}` y `{DPAD_RIGHT}`, además de `{L_BUTTON}`), evitando cualquier colisión o interferencia con las funciones de ordenar (`START`), intercambiar (`SELECT`) o acciones de objetos (`A`).

- [x] **2º Intento de captura -> Modalidad Gachapón aleatorio con guardado anti-exploit**:
  - **Problema previo**: El selector dinámico de rutas congelaba el intérprete de scripts tras seleccionar una ruta.
  - **Solución implementada**: Se sustituyó el menú manual por el sistema de ruleta/gachapón (`RollGymTokenGachapon`). El encargado busca todas las zonas del Nuzlocke marcadas como gastadas sin reintento previo y selecciona una al azar. Se descuenta 1 ficha de gimnasio, se limpia la bandera de la zona, se marca el reintento y se informa con `"¡Has ganado una captura gratis en {STR_VAR_1}!"`.
  - **Medida anti-exploit**: Es obligatorio guardar la partida antes de girar la ruleta (`Common_EventScript_SaveGame`). Si el jugador cancela el guardado, la operación se cancela y no se consume la ficha.

- [x] **Ajuste de formato de descripciones en bolsa y corrección de solapamiento en Pop-up**:
  - **Solapamiento en Pop-up**: Corregido en `src/item_menu.c` implementando un formateador dinámico de saltos de línea (`WordWrapDescription`) que mide el ancho real de las palabras con `GetStringWidth` e inserta caracteres `CHAR_NEWLINE` donde corresponde dentro del límite de 194 píxeles, eliminando el solapamiento de líneas al abrir la ventana modal.
  - **Formato en Bolsa**: La ventana de descripción estándar vuelve al formato conciso de 2-3 líneas en español (longitud idéntica al original en inglés) y añade limpiamente el aviso `"\n{SELECT_BUTTON} Más info..."`.

- [x] **Sistema Unificado de Pop-up Modal con Botón SELECT (Bolsa, Habilidades y Movimientos)**:
  - **Unificación de botón SELECT**: Se asignó universalmente el botón `{SELECT_BUTTON}` para consultar la información extendida en todos los menús del juego.
  - **Bolsa (`src/item_menu.c`)**: `{SELECT}` abre el pop-up modal del objeto. Se desactiva el reordenado manual a mano (innecesario teniendo ordenación por categorías con `{START}`) y se restaura el botón `{R}` para el cambio rápido de bolsillos.
  - **Habilidades (`src/pokemon_summary_screen.c`)**: En la pestaña INFO, la caja de la habilidad muestra la descripción corta y el aviso `"{SELECT_BUTTON} Más info..."`. Al pulsar `{SELECT}` se despliega una ventana modal (24x13 tiles) con el nombre de la habilidad, categoría y descripción extendida formateada con `WordWrapDescription`.
  - **Movimientos (`src/pokemon_summary_screen.c`)**: Tanto desde la vista general de ataques como en el cursor de selección de ataque, pulsar `{SELECT}` abre la ficha técnica del movimiento (nombre, potencia, precisión, PP actuales/máximos, categoría física/especial/estado y descripción completa).
  - **Navegación fluida dentro del panel de movimientos**: Con la cruceta (`{DPAD_LEFT}` / `{DPAD_RIGHT}` o `{DPAD_UP}` / `{DPAD_DOWN}`) se rota entre los ataques aprendidos mostrando un indicador `(X/Y)`. Al cerrar el pop-up, el cursor en la pantalla queda posicionado automáticamente en el ataque inspeccionado.

- [x] **Corrección de Pokémon semitransparentes en Resurrección y Guardado Anti-exploit**:
  - **Causa raíz de la transparencia**: En el Sistema de Almacenamiento Pokémon (`src/pokemon_storage_system.c`), la lógica de Nuzlocke atenuaba incondicionalmente a los Pokémon debilitados (`HP == 0`). Como el selector de resurrección (`SELECT_PC_MON_GYM_TOKEN_REVIVE`) excluía a los vivos (`HP > 0`), el 100% de los Pokémon en las cajas aparecían semitransparentes.
  - **Solución**: Se añadió la condición `GetPcMonSelectionType() != SELECT_PC_MON_GYM_TOKEN_REVIVE` en las rutinas de sombreado/atenuado (`ShouldBoxmonSpriteBeTransparent`, `UpdatePartyMonSprite`, `CreatePartyMonsSprites`), mostrando a los Pokémon debilitados totalmente opacos y seleccionables, y a los vivos atenuados.
  - **Medida anti-exploit**: Se exige guardar la partida de forma obligatoria antes de abrir la pantalla de resurrección. Si se cancela el guardado, se aborta la resurrección.

- [x] **Corrección en Intercambio Pokémon por Ficha (Held item check, límite y Guardado Anti-exploit)**:
  - **Causa del bloqueo de intercambio**: `GYM_TOKEN_TRADE_LIMIT` estaba definido a 1 en `src/gym_tokens.c`, bloqueando permanentemente futuros intercambios en la partida. Se eliminó esta restricción permitiendo intercambios siempre que haya fichas.
  - **Comprobación de objeto equipado**: Se incorporó la validación obligatoria de que el Pokémon a entregar no tenga ningún objeto equipado (`GetBoxMonData(boxMon, MON_DATA_HELD_ITEM) == ITEM_NONE`). Si tiene objeto o está debilitado, no permite su entrega.
  - **Medida anti-exploit**: Se exige guardar la partida antes de acceder a la selección de intercambio. Si no se guarda, no se realiza el intercambio.

- [x] **Coste de resurrección aumentado a 2 Fichas de Gimnasio**:
  - `GYM_TOKEN_REVIVE_COST` establecido en `2` en `src/gym_tokens.c`.
  - En `data/maps/GoldenrodCity_PokemonCenter_hns/scripts.inc`: añadida verificación previa mediante `special GetGymTokenCount` que rechaza la operación si el jugador tiene menos de 2 fichas, y actualizados todos los textos oficiales de la dependienta para reflejar "2 FICHAS GIMNASIO".

- [x] **Solución a la corrupción gráfica de fondos/menús por el Pop-up de Resumen (`pokemon_summary_screen.c`)**:
  - **Causa raíz de los artefactos basura y fondo roto**: La ventana modal de Resumen se configuró inicialmente con un tamaño de 24x13 tiles (312 tiles) en `baseBlock = 720`. En GBA, CharBase 1 llega hasta el tile 1023 (0x06007FFF), y el tile 1024 (0x06008000, CharBase 2) aloja los gráficos de fondo `gSummaryScreen_Gfx` (BG1/BG2/BG3). Al asignar 312 tiles a partir del 720, el buffer llegaba al tile 1032, destruyendo los primeros tiles de los fondos de la pantalla de resumen.
  - **Solución implementada**:
    1. Se redujo la altura de la ventana a 12 tiles (`PSS_POPUP_WINDOW_HEIGHT = 12`, 24x12 = 288 tiles). Con `720 + 288 = 1008 tiles`, queda con 16 tiles de margen de seguridad sin rozar CharBase 2.
    2. Se implementó una copia de respaldo completa de la VRAM de BG0 en un buffer EWRAM (`sSummaryBg0TilemapBackup`), respaldándolo con `CpuCopy16` al abrir el pop-up y restaurándolo exactamente al cerrarlo, garantizando que ninguna ventana previa quede desfigurada.
    3. Se oculta limpiamente el sprite del Pokémon activo (`SPRITE_ARR_ID_MON`) enviando temporalmente su coordenada `y = 240` fuera de pantalla mientras el pop-up esté visible, previniendo que animaciones en segundo plano pinten tiles sobre la modal.

- [x] **Corrección de solapamiento de textos en el Pop-up de Movimientos**:
  - Se reestructuró la maquetación vertical de la ventana modal:
    - Nombre del movimiento en `y = 3` (con ajuste dinámico a fuente estrecha si supera los 140 píxeles para no colisionar con el indicador de página `(X/Y)` en `x = 160`).
    - Estadísticas (Potencia, Precisión, PP, Tipo y Categoría) reubicadas limpiamente en `y = 15`.
    - Línea divisoria en `y = 25`.
    - Descripción multilínea canónica a partir de `y = 28` con interlineado legible de 1px.
    - Leyenda inferior de controles en `y = 83`.

- [x] **Actualización masiva de descripciones de movimientos a Español Canónico (`src/data/moves_info.h`)**:
  - Se incorporaron las descripciones oficiales en castellano de más de 480 movimientos de la franquicia Pokémon, respetando escrupulosamente la sintaxis de `COMPOUND_STRING` y la totalidad de directivas de preprocesador condicionales (`#if`, `#else`, `#endif`).

- [x] **Ventana modal de información extendida con {SELECT_BUTTON} en las tiendas (`src/shop.c`)**:
  - Homogeneizado con el sistema de la bolsa: la descripción de compra muestra las 3 primeras líneas con indicador `{SELECT_BUTTON} Más info...`.
  - Al pulsar `SELECT`, se despliega una ventana modal informativa (`WIN_POPUP_INFO`, 26x16 tiles) que imprime el nombre del objeto, bolsillo de destino, línea separadora y descripción completa con auto-wordwrap. Se cierra fluidamente pulsando A, B o SELECT.

- [x] **Traducción íntegra de diálogos y eventos de Don Baoba**:
  - Traducidos al español canónico todos sus guiones:
    - Encuentro de la Ruta 39 (`Route39_Text_BaobaIntro`, `Route39_Text_ChooseLegend`).
    - Puerta y recepción de la Zona Safari (`SafariZoneGate_SafariZoneEntrance_hns/scripts.inc`): tutorial de Pokécubos, todas las misiones (Playa, Matorral, Montaña, Cueva), recompensas y NPCs asociados.
    - Llamadas PokéGear y apariciones en Kanto (Azafrán y Fucsia).
    - Letrero de apertura de Cliff Edge Gate y entradas de Match Call (`match_call.inc`).

- [x] **Soporte de Randomizer / Randomlocke en el Recordador de Movimientos (`src/move_relearner.c`)**:
  - Se vinculó `RandomizeMove(move, species)` en `GetRelearnerLevelUpMoves` y `HasRelearnerLevelUpMoves`. Cuando la opción `RANDOMIZE_LEARNSET` está activa en la partida, el ayudante enseña exactamente los movimientos asignados por la seed de la run en lugar del learnset estático vanilla.

- [x] **Retirada temporal del NPC de Knekro en el Casino de Trigal**:
  - Eliminado el object event correspondiente en `data/maps/GoldenrodCity_GameCorner_hns/map.json` hasta definir e implementar su combate y diálogos finales.

- [x] **Auditoría: Motivo de descripciones en inglés en ataques y habilidades**:
  - **Ataques**: El motor base `pokeemerald-expansion` cuenta con más de 900 movimientos. Se tradujeron en primera fase los 484 más frecuentes (Gen 1 a 4). Los movimientos restantes (variantes de mecánicas como Frostbite, movimientos de Gen 8-9, Dinamax y Z-Moves) provienen del repositorio upstream en inglés y se incorporarán en lotes sucesivos.
  - **Habilidades**: En `src/data/abilities.h`, la expansión original solo tenía traducidos los nombres (`.name`), mientras que la totalidad de los campos `.description` (más de 310 habilidades) estaban originalmente definidos en inglés en upstream. Se planifica una pasada integral para volcar las descripciones oficiales de todas las habilidades a castellano.

  Hay que darle un repaso a los diálogos y a todos los textos del bloque 4. Ya he hablado con varias personas y no respetan las directrices estipuladas. Meten palabras sueltas, textos incompletos, etc. Por cierto el rival en esta zona está actualizado con las directrices que dijimos? (Esto está corregido ya)

  CUando llueve el mensaje sale en inglés, convendría comprobar todos los mensajes de ese estilo. (Esto está corregido ya)

- [x] **Relocalización del NPC de Sito en Ciudad Olivo (`data/maps/OlivineCity_hns/map.json`)**:
  - Reposicionado el evento objeto a la plaza central de Ciudad Olivo (`x: 23, y: 43`), en zona exterior totalmente abierta y transitable entre la Tienda y el Centro Pokémon, fuera de la colisión de la torre/faro.

- [x] **Corrección de indicador Nuzlocke `ZONA: GASTADA` en interiores y zonas no mapeadas (`src/nuzlocke.c`)**:
  - `NuzlockeFlagGet`, `NuzlockeFlagSet` y `NuzlockeFlagClear` validan ahora `IsNuzlockeEncounterArea(mapsec)` antes de consultar el mapeo de la zona. Se corrige el fallo por el cual mapas de interiores, Centros Pokémon, tiendas, gimnasios o mapas sin sección propia caían por defecto al índice 0 (Ruta 1) y marcaban falsamente la zona como gastada tras capturar en Ruta 1.

- [x] **Ajuste del Recordador de Movimientos por nivel y pre-evoluciones (`include/config/summary_screen.h`)**:
  - Ajustado `P_PRE_EVO_MOVES` a `FALSE`. El recordador limita la lista estrictamente a los movimientos por nivel aprendidos por la especie actual hasta su nivel actual (evaluando los movimientos aleatorizados de la seed cuando la opción de Randomlocke está activa).

- [x] **Preservación del Límite de Nivel en migración de partidas (`docs/utilidades/activar_randomizers_sav.ps1`)**:
  - Eliminadas las operaciones de enmascaramiento de bits innecesarias sobre el sector de ajustes del guardado (`$settings + 12`), previniendo que se borren los bits correspondientes a `tx_Challenges_LevelCap`. El límite de nivel puede volver a reactivarse en cualquier momento desde la pestaña **Dificultad** del menú de **Ajustes de Reto / Nuzlocke**.

- [x] Las Poké Ball del suelo que contienen MT/MO usan ahora el gráfico de la Level Ball, con una presencia amarilla más clara y cercana a los juegos modernos.

- [x] Las Poké Ball de MT/MO conservan el gráfico amarillo al regresar al mapa después de un combate.

- [x] No deberían aparecer tantos pseudologendarios tras la 6 medalla, por qué pasa? Y vamos a bajar mucho más el % de legendarios mayores y menores y de cualquier tipo. Recuérdame las tablas establecidas y vamos a cambiar algunas cosas.

### 📦 Versión `pokehns-0.32.4-20260927-personajes-posicion-es.gba`

- **Fecha:** 27/09/2026
- **Contenido incluido:**
  - [x] **Silver en el Lago de la Furia**: espera frente al lago y la escena de la Megaevolución comienza únicamente al hablar con él; eliminados los triggers y la entrada caminando.
  - [x] **El Piedras en Trigal**: recolocado en la zona pública de la segunda planta del Centro Comercial, fuera del mostrador.
  - [x] **El Piedras en el Lago de la Furia**: trasladado desde el interior de la cabaña al exterior, junto a la casa, conservando su progresión y diálogo adaptado.
  - [x] Auditoría focalizada y compilación completa verificadas correctamente.

## 🔴 BUGS PENDIENTES (EN COLA DE RESOLUCIÓN)

- [ ] **Etapas intermedias demasiado pronto en encuentros aleatorios**: el ajuste evolutivo previo al nivel 30 solo identifica una familia de tres etapas cuando la especie sorteada es la evolución final. Las etapas intermedias, como Grotle, no detectan que todavía tienen una evolución posterior y pueden aparecer en rutas iniciales. El filtro debe analizar la familia completa y convertir también estas especies a su primera etapa.

- [x] **Learnsets aleatorios equilibrados y movimientos iniciales desproporcionados**: sustituida la tirada independiente por movimiento por un learnset virtual completo y determinista para cada especie y semilla. Cada learnset reserva aproximadamente un 40% de ataques STAB, un 25% de movimientos de estado y un 35% de cobertura ofensiva no STAB; reparte el STAB entre ambos tipos, garantiza un primer ataque STAB, evita duplicados y conserva la afinidad física/especial. La potencia queda limitada también cuando el movimiento original era de estado, impidiendo casos como Lotad con Hidrobomba al inicio. Creación, subida de nivel, evolución y recordador consultan el mismo resultado.

- [x] **Cajas de descripción de tiendas**: corregida la restauración tras cerrar el panel de `SELECT`. La tienda de Megapiedras ya se redibuja como tienda de dinero y no como tienda BP, y las ventanas de dinero, lista y descripción se copian explícitamente de nuevo a VRAM para evitar restos, cajas incorrectas y solapamientos.

- [x] **El Piedras completo**: corregido el cierre al abrir su tienda usando un pool persistente en EWRAM, desplazado una casilla a la derecha en la quinta planta de Trigal, añadida su aparición intermedia en Ruta 39 y extendida su tienda a los Poké Marts tras la Torre Radio. El catálogo rota diariamente y mantiene el desbloqueo progresivo por medallas.

- [x] **Salida del bar de Igor**: la barrera mantiene al jugador dentro hasta canjear el vale de prueba por su primer Chupito.
- [x] **Canjes accidentales en el bar de Igor**: cada Chupito y el Cubata requieren confirmación explícita antes de descontar vales.
- [x] **Contador de Vales de Fiesta**: Igor muestra la cantidad disponible cada vez que abre el menú de canje.
- [x] **Pool aleatoria de objetos festivos**: añadidos los Vales de Fiesta y los seis Chupitos; el Cubata queda excluido y solo aparece en ubicaciones o eventos programados.
- [x] **Combates de las estatuas del Team Rocket**: las cinco alarmas de la guarida de Caoba usan combinaciones distintas de reclutas y equipos.
- [x] **Contraseñas del Team Rocket**: sustituidas por `CLARO CABRÓN` y `MBAPPE MBAPPE`.
- [x] **Contraseña de Murkrow**: Petrel y Murkrow dicen `VIVA ER BETI` en toda la secuencia de reconocimiento de voz.
- [x] **Combate doble de la guarida Rocket**: Atenea y el recluta usan textos de derrota traducidos propios en lugar de las cadenas inglesas de depuración.
- [x] **Electrode estáticos de la guarida Rocket**: pueden capturarse aunque la captura ordinaria de la zona ya esté gastada; se mantienen las demás cláusulas Nuzlocke.
- [x] **Diálogos de Silver**: revisadas sus apariciones y recuperado el tono cani, agresivo y vacilón en los encuentros tardíos que habían quedado neutros.
- [x] **Modal de información de tiendas**: centrada la leyenda inferior para impedir que escriba fuera del buffer y corrompa la ventana.
- [x] **Descripción breve de tiendas**: aplicada envoltura por píxeles y límite de cuatro líneas antes del aviso de `SELECT`.
- [x] **Ayuda de efectividad e Ilusión**: mientras Ilusión siga activa, la ayuda calcula contra los tipos del Pokémon imitado y no revela los tipos reales de Zoroark.
- [x] **Escalado excesivo tras la séptima medalla**: los entrenadores normales ya no saltan automáticamente al límite vigente menos dos. El sistema usa como suelo suave el límite de la medalla anterior menos dos, nunca reduce niveles originales, conserva las diferencias internas de cada equipo y mantiene exentos a líderes, Alto Mando, campeones, rivales e instalaciones especiales. Kanto y postgame conservan por ahora sus niveles diseñados al no disponer de una tabla específica aprobada para sus ocho medallas.
- [x] **Secretos exteriores de Malva y Caoba**: añadida la Expedición Malva 33 con tres parisinos de Kalos, pistas y secuencia de lámparas bloqueada hasta obtener Surf; añadida también la persecución permanente de los cuatro Aipom de Caoba, entrega de Llave Secreta y consumo irreversible al abrir la nueva casa.
- [x] **Lámparas gemelas de Ciudad Malva sin respuesta**: vinculados ambos lados de las parejas de la Academia y Torre Bellsprout al mismo paso del puzle, evitando que una de las dos luces idénticas quede sin interacción.

- [x] **Descripciones breves de tiendas**: reducidas a dos líneas de resumen y una tercera línea fija con `SELECT Más info...`; la descripción completa permanece accesible pulsando `SELECT`.
- [x] **Mensaje al encontrar MT/MO**: traducidas las cadenas singular y plural que todavía mostraban `found one`/`found` en inglés.
- [x] **Pasadizo entre rocas de Pueblo Azalea**: eliminado el objeto sin script situado en `(35, 34)`, que ocupaba la casilla transitable y bloqueaba el paso pese a que el bloque del mapa no tenía colisión.
- [x] **Cuadro breve de tiendas solapado**: ajustado el recorte de la descripción a dos líneas exactas y añadido soporte de resumen y pop-up para las Megapiedras de El Piedras (`MART_TYPE_MEGA_STONES`); la leyenda `{SELECT} Más info...` queda limpia e independiente.
- [x] **Textos de Ciudad Cerezo**: auditados y corregidos todos los mapas de Ciudad Cerezo (`CherrygroveCity_hns` y sus interiores). Eliminado un residuo de texto huérfano en el Centro Pokémon y corregidos los saltos de línea y scroll (`\l`) en la Casa 1.
- [x] **Bug de traducción al aplicar una Menta**: traducidos al español en `src/party_menu.c` los textos de confirmación y efecto de las Mentas (`"Afectará a las características..."` y `"¡Las características de {STR_VAR_1} han cambiado por la {STR_VAR_2}!"`), además de los textos de Cápsula Habilidad, Parche Habilidad y reinicio de puntos base.
- [x] **Excepción Nuzlocke exclusiva de Juanra**: restaurada la inmunidad a las muertes únicamente durante su combate. La eliminación general de Pokémon debilitados no consulta esta bandera, por lo que las bajas posteriores siguen aplicando normalmente las reglas Nuzlocke.

- [x] El tutor mantiene seleccionado al mismo Pokémon después de enseñarle un movimiento y vuelve a mostrar sus movimientos disponibles. Solo regresa al menú general al cancelar o cuando ya no quedan movimientos de esa categoría.

- [x] Ajustada al 50% la preferencia STAB del randomizador de movimientos por nivel. El perfil ofensivo se calcula desde las estadísticas base: físico o especial cuando una supera a la otra al menos un 20% (reparto 70/30), mixto en caso contrario (50/50), y utilidad si ambos ataques son inferiores a 60 (60% de preferencia por estado). Los movimientos de estado no se excluyen en los perfiles ofensivos y el filtro se relaja tras 80 intentos para garantizar un resultado válido.

- [x] Traducidas las quince respuestas de los cinco menús de la prueba del anciano en la Guarida Dragón; las preguntas y el resto de la escena ya estaban en español.

- [x] **Revisión editorial integral del Bloque 1**: revisados los 16 mapas completos desde Pueblo Primavera hasta la casa del Sr. Pokémon, sustituyendo la comprobación parcial anterior de 31 cadenas. Corregidos textos poco naturales, terminología, ubicación del Sr. Pokémon, explicación de Bonguris y secuencias defectuosas de saltos/scroll; auditoría específica final con 0 incidencias.

- [x] La compatibilidad aleatoria de MT amplía un 10% el número original de MT compatibles de cada especie, redondeando hacia arriba para añadir al menos una cuando ya existía compatibilidad. La selección es determinista por semilla y está ponderada por STAB (75), estado (45), categoría ofensiva principal (40), perfil mixto (35) y categoría secundaria (20). Las MO mantienen su compatibilidad original y los tutores conservan el comportamiento previo.

- [x] Traducidos los 20 nombres oficiales de los Pokémon Paradoja al castellano, incluidos los del DLC, y cambiada su categoría de Pokédex de `Paradox` a `Paradoja`.

- [x] Auditadas las 100 MT y traducidas todas las descripciones pendientes de las MT51 a MT92, incluida MT64 Explosión. La auditoría final no detecta descripciones inglesas en ninguna MT.

- [x] **Panel de cambios de estadísticas**: compactadas las siete estadísticas en una tabla de tres líneas para que ATK, DEF, At. Esp., Def. Esp., Velocidad, Precisión y Evasión de ambos bandos entren completas en la ventana disponible; el clima queda en una cuarta línea.

- [x] **Crash y diseño de El Piedras en los Poké Marts**: retirada completamente su oferta del script del dependiente. El Piedras aparece ahora como NPC físico independiente en la casilla libre `(9, 2)` del sector noreste, junto a los frigoríficos, en los trece Poké Marts de Johto y Kanto. Su tienda especial ya no registra el retorno al menú del tendero y vuelve exclusivamente a su propio diálogo.
- [x] **Pantalla negra al abrir la tienda de El Piedras**: `BuyMenuSetListEntry` trataba las Megapiedras como índices de decoración al construir la lista, provocando una lectura fuera de rango durante el fundido. `MART_TYPE_MEGA_STONES` usa ahora nombres y datos de objetos en todo el flujo de inicialización.

- [x] **Formato de descripciones de tiendas**: restaurada la impresión original del commit `167aa6d537b109bb229c231ddce4616974c4da71`, respetando los saltos ya traducidos de cada descripción, y reservada únicamente la última línea para `SELECT Más info...`.

- [x] **Icono físico/especial sobre el panel de estadísticas**: el sprite de categoría se destruye al cambiar desde la descripción del movimiento al panel de estadísticas y solo vuelve a crearse al mostrar de nuevo potencia, precisión y descripción.

- [x] **Resumen de objetos en tiendas**: la descripción breve conserva la fuente original, se envuelve por píxeles y se recorta exactamente a dos líneas; la tercera queda reservada exclusivamente para `SELECT Más info...`.

- [x] **Fondo gris tras cerrar `SELECT Más info...`**: la ventana modal y su marco se limpian y copian a VRAM antes de restaurar dinero, lista y descripción, evitando residuos gráficos sobre la tienda.

### 📦 Versión `pokehns-0.40.20-20261001-revision-bloque1-es.gba`

- **Fecha:** 01/10/2026
- **Contenido incluido:**
  - [x] Revisión editorial integral de los 16 mapas del Bloque 1, desde Pueblo Primavera hasta la casa del Sr. Pokémon.
  - [x] Corrección de redacción, terminología y secuencias de salto/scroll en Primavera, laboratorio de Elm, Ruta 29, Cerezo y Ruta 30.
  - [x] Auditoría focalizada sin incidencias y compilación completa verificada.
  - [x] Publicada con `pokehns-0.40.20-20261001-revision-bloque1-es.sav` y sincronizada como `pokehns_fase1.gba`/`pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.40.21-20261001-ajuste-movimientos-es.gba`

- **Fecha:** 01/10/2026
- **Contenido incluido:**
  - [x] Preferencia STAB del randomizador de movimientos por nivel aumentada del 40% al 50%.
  - [x] Cupo aleatorio de MT compatibles ampliado un 10% sobre la compatibilidad original, con redondeo hacia arriba.
  - [x] Conservadas las ponderaciones de afinidad, las MO originales y las demás protecciones de potencia y Nuzlocke.
  - [x] Compilación completa verificada y publicación acompañada por un `.sav` compatible.

### 📦 Versión `pokehns-0.40.23-20261002-caramelos-lote-es.gba`

- **Fecha:** 02/10/2026
- **Contenido incluido:**
  - [x] Selector para usar varios Caramelos Raros seguidos sobre el Pokémon elegido.
  - [x] Cantidad limitada por existencias, nivel 100 y límite de nivel activo.
  - [x] Procesamiento por tramos evolutivos para conservar movimientos y evoluciones intermedias.
  - [x] Continuación automática del lote después de aceptar o cancelar una evolución.
  - [x] Compilación focalizada y build completa verificadas correctamente; revisión funcional en emulador pendiente.

- [x] ~~Los sprites de las megapiedras están mal, no sé si hay algo con respecto a esto en el código.~~ _(Resuelto en v0.40.22)_
- [x] ~~Me encanta que los items se aleatoricen como lo hacemos, pero hay ciertos items que es mejor que únicamente aparezcan una vez, me refiero a los items competitivos, sobre todo porque solamente se podrá equipar uno de ellos durante el torneo, me sigues?~~ _(Resuelto en v0.40.22)_
- [x] ~~Cuando entras en el menú de descripcion SELECT de la tienda se sigue rompiendo algo ![alt text](image-6.png)~~ _(Resuelto en v0.40.22)_
- [x] ~~En el mapa pone ciudad MALVALONA no MALVA.~~ _(Resuelto en v0.40.23: corregida entrada de mapa de Johto para Violet City como "CIUDAD MALVA")_
- [x] ~~Algunos líderes de gimnasio tienen los nombres en inglés no en castellano.~~ _(Resuelto en v0.40.23: traducidos a castellano Pegaso, Antón, Blanca, Morti, Fredo, Yasmina, Aníbal, Débora, Lt. Surge, Sachiko, Azul y Mento tanto en combates como en scripts/estatuas)_
- [x] ~~Los combates contra las chicas Kimono están modificados?~~ _(Aclarado en v0.40.23: Sí, están modificados en el Teatro de Ciudad Iris mediante boosts de tótem a sus Eeveelutions nvl 48 con IVs perfectos: Zuki +1 SpA/+2 SpD, Naoko +1 Atk/+1 SpA/+1 SpD, Miki +1 SpA/+2 SpD, Sayo +2 Def/+1 SpA, Kuni +2 Atk/+1 SpD)_
- [x] ~~Hay muchas MTs en las que no pone nada![alt text](image-7.png)~~ _(Resuelto en v0.40.23: completada la definición de MT93 a MT100 en FOREACH_TM con sus respectivos movimientos asignados e indexados, solucionando el bug de MTs que mostraban "№00 -" en el bolsillo de MTs/MOs)_

### 📦 Versión `pokehns-0.40.23-20261002-correcciones-varias-es.gba`

- **Fecha:** 02/10/2026
- **Contenido incluido:**
  - [x] Corrección del nombre en el mapa de Johto: "CIUDAD MALVA" (sustituyendo el error "CIUDAD MALVALONA").
  - [x] Traducción completa de los nombres en combate y diálogos/estatuas de todos los líderes de gimnasio y Alto Mando (Pegaso, Antón, Blanca, Morti, Fredo, Yasmina, Aníbal, Débora, Lt. Surge, Sachiko, Azul, Mento).
  - [x] Verificación de la mecánica de combate de las Chicas Kimono en Ciudad Iris (Eeveelutions con boosts de tótem e IVs 31).
  - [x] Corrección integral del visualizador de MTs en la mochila: añadidas las MT93-MT100 a `FOREACH_TM` y enlazadas a sus movimientos en `src/data/items.h`, eliminando el problema de MTs sin número ni nombre (`№00 -`).
  - [x] Compilación y verificación exitosa de la ROM.

- [x] ~~Select no funciona en la pantalla de aprender movimientos.~~ _(Resuelto en v0.40.24: añadido soporte para `{SELECT}` en `Task_HandleReplaceMoveInput`, actualización de `ShowUtilityPrompt` para mostrar `{SELECT} Info` en vez de `Cambio` al aprender movimiento, y navegación completa por el popup modal para el nuevo movimiento a aprender)_

### 📦 Versión `pokehns-0.40.24-20261002-liga-items-select-es.gba`

- **Fecha:** 02/10/2026
- **Contenido incluido:**
  - [x] **Metacaballero en Liga Pokémon**: cambiado su sprite en `data/maps/IndigoPlateau_PokemonCenter_hns/map.json` a `OBJ_EVENT_GFX_OLD_MAN_2_HNS` ("otro tipo de señor"). Actualizado su documento en `docs/personajes/metacaballero.md`.
  - [x] **Ayudante del Locke en Liga Pokémon**: añadido el NPC dependiente de Gym Tokens en el Centro Pokémon de la Meseta Añil (`IndigoPlateau_PokemonCenter_hns`) con sprite de `OBJ_EVENT_GFX_GENTLEMAN_HNS` y script de canje.
  - [x] **Revisión global de objetos en `src/data/items.h`**:
    - Normalizados nombres en mayúsculas faltantes.
    - Traducidas descripciones residuales en inglés (inciensos, MT67/MT70 fallback, plumas EV, etc.).
  - [x] **Soporte de `{SELECT}` en la pantalla de aprender/reemplazar movimientos**:
    - Habilitado `{SELECT}` para abrir el popup de información detallada tanto para los 4 movimientos existentes como para el nuevo ataque a aprender (`MAX_MON_MOVES`).
    - Navegación bidireccional continua `{DPAD}` dentro del modal incluyendo el nuevo movimiento.
    - Restauración correcta del selector y detalles al cerrar el modal.
    - Prompt dinámico `{SELECT} Info` en vez de `Cambio` durante el aprendizaje de movimientos.
  - [x] Compilación y verificación limpia de la ROM.

- [x] ~~Textos de los pokemon que te acompañan siguen en inglés.~~ _(Resuelto en v0.40.25: traducidos al castellano oficial los 51 mensajes de reacción de Pokémon acompañantes en `src/follower_helper.c` y `data/scripts/follower.inc` con formateo GBA $\le 34$ car/línea)_
- [x] ~~Los tipos de los pokemon aparecen en inglés, no en castellano.~~ _(Resuelto en v0.40.25: traducidos los tipos a nombres en castellano oficial en `src/data/types_info.h` y ampliado `TYPE_NAME_LENGTH` a 10 en `include/constants/global.h`)_

### 📦 Versión `pokehns-0.40.25-20261005-sinjoh-follower-tipos-es.gba`

- **Fecha:** 05/10/2026
- **Contenido incluido:**
  - [x] **Traducción y auditoría completa de Sinjoh (12 mapas)**:
    - 100% de diálogos traducidos al castellano oficial.
    - Todos los textos auditados sin exceder 34 caracteres por línea y con saltos correctos (`SinjohRuins_House1_hns`, templos, exteriores y casas de Nuevo Sinjoh).
  - [x] **Traducción de seguidores (Follower)**:
    - 51 mensajes de interacción de Pokémon acompañantes localizados al español oficial en `src/follower_helper.c` y `data/scripts/follower.inc`.
  - [x] **Traducción de tipos de Pokémon**:
    - Tipos normalizados a castellano oficial (ACERO, AGUA, BICHO, DRAGÓN, ELÉCTRICO, FANTASMA, FUEGO, HADA, HIELO, LUCHA, NORMAL, PLANTA, PSÍQUICO, ROCA, SINIESTRO, TIERRA, VENENO, MISTERIO).
    - `TYPE_NAME_LENGTH` ampliado a 10 en `include/constants/global.h` para soportar longitudes sin truncado de memoria ni overflow de buffer.
  - [x] **Auditoría de textos GBA**: 0 incidencias en todos los bloques. Compilación limpia y ROM publicada.

- [x] ~~La sintonía de la radio del pokegear de la expedición de ciudad malva no funciona, donde hay que buscarla?~~ _(Resuelto en v0.40.26: ahora tras obtener la 4ª medalla se dispara una llamada de aviso al PokéGear y la radio de Oak/Mary difunde prioritariamente los rumores sobre los viajeros de Ciudad Luminalia en Ciudad Malva y el misterio del 33)_

### 📦 Versión `pokehns-0.40.27-20261005-secretos-johto-radio-es.gba`

- **Fecha:** 05/10/2026
- **Contenido incluido:**
  - [x] **Nueva Emisora Oficial: "Secretos de Johto"**:
    - Situada al final exacto del dial de sintonización (posición máxima / 63).
    - Canal dedicado a difundir los misterios y rumores de la región de Johto.
    - Emite la crónica y solución de la Expedición Malva 33 (Ciudad Luminalia) al desbloquear la 4ª medalla.
    - Llamada del PokéGear tras derrotar a Morti adaptada para indicar sintonizar "SECRETOS DE JOHTO" al final del dial.
  - [x] Compilación y verificación limpia en WSL. Publicada con `.sav` sincronizado.

- [x] **Texto del recordador tras enseñar un movimiento**: al regresar al mismo Pokémon se restaura en `STR_VAR_3` la categoría correspondiente (`movimiento`, `movimiento huevo`, `movimiento MT` o `movimiento tutor`) en lugar de conservar el nombre del ataque olvidado.

- [x] **Descripción cortada al obtener objetos**: ampliado el panel superior de tres a ocho bloques de altura y aplicada la fuente estrecha para mostrar la descripción completa reformateada sin recortarla. Validación visual final pendiente en emulador.

- [x] **Salida del jardín secreto de Pueblo Primavera**: añadido un segundo punto de interacción en `(14, 35)`, delante del seto original inaccesible, que devuelve al jugador al pueblo mediante el mismo script de salida.

- [x] **Mayor presencia de objetos curativos**: reservado un 20% de los objetos ordinarios aleatorizados para medicinas de PS, estado o PP acordes al tramo de progreso. La selección excluye Revivir y Máx. Revivir y respeta las anclas de Megapiedras, MT, objetos competitivos únicos y objetos clave.

- [x] **Secretos de Johto revelaba la solución**: la emisora ya no indica el orden de las farolas de Malva. Ahora informa de los viajeros de Ciudad Luminalia, su ubicación por las calles, que cada uno guarda una pista y que existe una entrada relacionada con Surf.

### 📦 Versión `pokehns-0.40.28-20261005-correcciones-pendientes-es.gba`

- **Fecha:** 05/10/2026
- **Contenido incluido:**
  - [x] Restauración correcta del texto de categoría al repetir con el recordador.
  - [x] Panel ampliado para descripciones completas al obtener objetos.
  - [x] Salida accesible del jardín secreto de Pueblo Primavera.
  - [x] Probabilidad global del 20% de curación progresiva en objetos ordinarios aleatorizados.
  - [x] Emisora Secretos de Johto convertida en sistema de avisos sin revelar soluciones.
  - [x] JSON, auditoría focalizada y compilación completa verificadas; comprobación visual y funcional en emulador pendiente.

- [x] **Panel de descripción al obtener objetos**: restaurada la presentación original con `FONT_NORMAL`, cuatro bloques interiores y separación de 16 px. Las descripciones largas se muestran en páginas de dos líneas controladas con `A`; el panel se cierra antes de presentar el mensaje inferior.

- [x] **Indicadores de `SELECT` invasivos en Bolsa, habilidades y movimientos**: restauradas las dimensiones, fuentes y posiciones originales. Se han generado dos variantes comparables sin solapamientos: una conserva las descripciones completas y muestra `SELECT` fuera de sus cajas; la otra reserva la última línea original para `{SELECT_BUTTON} Más info...`.

### 📦 Versión `0.40.29` — comparativa de interfaz `SELECT`

- **Fecha:** 06/10/2026
- **Build principal recomendada:** `pokehns-0.40.29-20261006-ui-select-independiente-es.gba`.
  - Bolsa: descripción original completa y aviso independiente en la zona izquierda.
  - Habilidades y movimientos: descripción original completa y `{SELECT_BUTTON} INFO` en el área superior de controles.
- **Build alternativa:** `pokehns-0.40.29-20261006-ui-select-ultima-linea-es.gba`.
  - Bolsa: dos líneas descriptivas y aviso en la tercera.
  - Movimientos: una línea descriptiva y aviso en la segunda.
  - Habilidades: la línea descriptiva se sustituye por el aviso de información ampliada.
- Ambas ROM incluyen un `.sav` compatible con el mismo nombre base.
- Las dos variantes compilan y enlazan correctamente. La comparación visual y funcional final queda pendiente de prueba en emulador.

- [x] **Texto cortado por la derecha en la Bolsa independiente**: las descripciones se recomponen ahora palabra a palabra usando la anchura real de `FONT_NORMAL` y los 106 píxeles disponibles. Se muestran como máximo tres líneas y la información completa permanece accesible con `SELECT`.

- [x] **Paginado incompleto al obtener objetos**: sustituido el cálculo fijo de 32 caracteres por medición real en píxeles. Cada dos líneas visuales se inserta una pausa y `A` continúa en la página siguiente; la flecha final cierra el panel únicamente cuando ya no queda texto.

- [x] **Avisos de repelente agotado en inglés**: traducidos la finalización del efecto, la pregunta para usar otro repelente, la selección de uno diferente y la confirmación de uso.

### 📦 Versión `pokehns-0.40.30-20261006-ajuste-descripciones-repelente-es.gba`

- **Fecha:** 06/10/2026
- [x] Conserva como base el diseño recomendado con `SELECT` independiente.
- [x] Ajuste por anchura real en la descripción resumida de la Bolsa.
- [x] Paginado funcional de dos líneas al obtener objetos.
- [x] Traducción completa de los avisos automáticos de repelentes y cebos.
- [x] Auditoría focalizada sin incidencias y compilación completa correcta; comprobación visual final pendiente en emulador.

### 🧪 Prototipo de información mecánica con `SELECT`

- [x] El panel ampliado deja de repetir la descripción breve en seis movimientos: Lanzallamas, Danza Lluvia, Acróbata, Protección, Semilladora y Psíquico.
- [x] Las fichas muestran probabilidades, duración, multiplicadores, prioridad, contacto, distribución de golpes y objetos o habilidades relacionados según el motor actual de HnS.
- [x] Técnico, Intimidación, Sequía y Velo Acuático disponen de una explicación avanzada con umbrales, niveles de estadísticas, inmunidades y duración exacta.
- [x] Los movimientos y habilidades todavía no cubiertos conservan su descripción normal como fallback; este lote sirve para validar el diseño antes de extender el sistema.
- [ ] Validar visualmente en emulador que las fichas de cuatro líneas no invaden el pie del modal.

### 📦 Versión `pokehns-0.40.31-20261006-fichas-mecanicas-piloto-es.gba`

- **Fecha:** 06/10/2026
- [x] Incluye las cinco fichas avanzadas de movimientos y las tres de habilidades del prototipo.
- [x] Mantiene el fallback de descripción normal para el resto del contenido.
- [x] Auditoría focalizada y compilación completa correctas; validación visual y funcional pendiente en emulador.

- [x] **La descripción de objetos aún perdía un píxel por la derecha**: reducido de 106 a 105 píxeles el ancho útil del ajuste de palabras, manteniendo la fuente y dimensiones originales.
- [x] **El paginado al obtener objetos cerraba el panel al pulsar `A`**: el texto se imprimía con velocidad `0`, que procesa el contenido de una vez sin registrar un impresor activo. Se usa velocidad `1` para conservar el estado en `CHAR_PROMPT_CLEAR`, esperar la pulsación y continuar con la siguiente página.

### 📦 Versión `pokehns-0.40.32-20261006-paginado-fichas-ampliadas-es.gba`

- **Fecha:** 06/10/2026
- [x] Margen derecho de la descripción resumida de Bolsa ajustado un píxel.
- [x] Paginado persistente y controlado con `A` en el panel de obtención de objetos.
- [x] Fichas avanzadas añadidas para Psíquico y Velo Acuático.
- [x] Auditoría focalizada y compilación completa correctas; validación visual y funcional pendiente en emulador.

### 📚 Ampliación progresiva de fichas mecánicas

- [x] Creada `docs/desarrollo/GUIA_FICHAS_MECANICAS_SELECT.md` con la ruta mínima de investigación, fuentes, plantilla, límites visuales, validación y publicación.
- [x] Extraído el catálogo de textos fuera de `pokemon_summary_screen.c` a `src/data/advanced_summary_info.h`, usando tablas dispersas con fallback automático.
- [x] Primer lote ampliado a **29 movimientos** y **25 habilidades** con datos contrastados contra el motor actual.
- [x] Familias iniciadas: clima, velocidad, STAB, daño indirecto, supervivencia, estados, retroceso, multigolpe, potencia variable y cambios de estadísticas.
- [x] Cobertura universal activada para todos los identificadores de movimientos y habilidades: ninguna entrada vuelve a repetir simplemente su descripción breve al pulsar `SELECT`.
- [x] Los movimientos no manuales muestran objetivo, prioridad, efecto adicional, multigolpe o crítico, contacto, familia e interacción con Protección, Sustituto y habilidades.
- [x] Las habilidades no manuales muestran si Rompemoldes las ignora y si pueden copiarse, rastrearse, intercambiarse, anularse o sobrescribirse.
- [ ] Seguir refinando manualmente movimientos de recuperación, trampas, daño variable y habilidades de terreno o cambio de forma cuando necesiten excepciones adicionales.
- [ ] Validar visualmente en emulador las fichas que el ajuste automático pueda recomponer en una quinta línea.

### 📦 Versión `pokehns-0.40.33-20261006-catalogo-fichas-lote1-es.gba`

- **Fecha:** 06/10/2026
- [x] Catálogo escalable separado de la lógica de interfaz.
- [x] Cobertura inicial de 29 movimientos y 25 habilidades.
- [x] Guía de implementación y ampliación documentada.
- [x] Auditoría focalizada y compilación completa correctas; validación visual y funcional pendiente en emulador.

### 📦 Versión `pokehns-0.40.34-20261006-fichas-universales-es.gba`

- **Fecha:** 06/10/2026
- [x] Todos los movimientos y habilidades disponen de ficha mecánica con `SELECT`.
- [x] Las 29 fichas manuales de movimientos y 25 de habilidades conservan sus explicaciones específicas.
- [x] El resto se genera directamente desde `gMovesInfo` y `gAbilitiesInfo`, evitando cientos de textos duplicados y reduciendo el coste de mantenimiento.
- [ ] Validación visual y funcional pendiente en emulador.

### 🧹 Resúmenes `SELECT` centrados en efectos jugables

- [x] Eliminada la ficha automática de metadatos internos que mostraba objetivo, contacto, Protección, Sustituto, Rompemoldes, copia, intercambio o supresión sin explicar el efecto real.
- [x] Los movimientos y habilidades todavía no revisados usan su descripción funcional original, sin inventar una falsa ficha avanzada ni rellenar el panel con información irrelevante.
- [x] Las fichas manuales conservan porcentajes, turnos, multiplicadores, cambios de estadísticas, condiciones e interacciones que sí afectan a una decisión de combate.
- [x] Depuradas las fichas piloto para retirar prioridad neutra, contacto irrelevante y referencias genéricas a Protección.
- [ ] Validación visual y funcional pendiente en emulador.

### 📦 Versión `pokehns-0.40.35-20261006-resumenes-select-utiles-es.gba`

- **Fecha:** 06/10/2026
- [x] Cobertura universal sin mostrar información técnica que no describa un efecto jugable.
- [x] Fallback seguro a la descripción funcional para movimientos y habilidades sin ficha manual.
- [x] Guía de ampliación actualizada con el criterio de utilidad táctica.
- [x] Auditoría focalizada y compilación completa correctas; validación visual final pendiente en emulador.

### ⚠️ Corrección del criterio de las fichas `SELECT`

- [x] La versión `0.40.35` eliminó el ruido técnico, pero dejó como fallback la descripción normal y no cumplía el objetivo de ofrecer información avanzada. Queda sustituida por esta revisión.
- [x] El generador interpreta ahora consecuencias reales: prioridad no neutra, estados y retroceso con porcentaje, cambios de estadísticas, multigolpe, críticos, daño fijo, recuperación y recoil.
- [x] Las etiquetas de movimientos se convierten en sinergias concretas: Técnico, Puño Férreo, Guante de Boxeo, Mandíbula Fuerte, Megalanzador, Punk Rock, Filo, Antibalas, Insonorización, Bailarín y Triaje.
- [x] Puño Bala dispone de una ficha explícita con prioridad `+1`, Técnico `x1,5`, Puño Férreo `x1,2` y Guante de Boxeo `x1,1` con anulación del contacto.
- [x] Añadidas doce fichas avanzadas de habilidades relacionadas con estas familias para mostrar cifras y efectos exactos en lugar de su texto corto.
- [ ] Validación visual y funcional pendiente en emulador.

### 📦 Versión `pokehns-0.40.36-20261006-fichas-tacticas-select-es.gba`

- **Fecha:** 06/10/2026
- [x] Generación táctica basada en datos efectivos del movimiento.
- [x] Caso de referencia de Puño Bala cubierto explícitamente.
- [x] Compilación aislada de `pokemon_summary_screen.c` correcta.
- [x] Auditoría focalizada y compilación completa correctas; validación visual final pendiente en emulador.

- Las descripciones de los items cuando los obtienes ahora cortan directamente le mensaje en mitad. peor que antes.

### ✅ Corrección del corte en descripciones al obtener objetos

- [x] La causa era un límite fijo de 256 bytes compartido con `gStringVar1`/`gStringVar3`; las descripciones largas se truncaban aunque todavía quedasen páginas por mostrar.
- [x] Añadido un búfer EWRAM dedicado de 512 bytes y convertido el reformateador para respetar explícitamente su tamaño, reservar el final de cadena y no escribir fuera del límite.
- [x] Corregida una regresión posterior que detenía el reformateador al alcanzar la tercera línea y descartaba el resto de la descripción.
- [x] El panel vuelve a insertar una pausa cada dos líneas, continúa mediante `A` y espera otra pulsación al terminar la última página.
- [ ] Validación visual pendiente con una descripción superior a 256 bytes.

### 📊 Cobertura real de habilidades avanzadas

- [x] Total definido en HnS: **311 habilidades**.
- [x] Fichas avanzadas revisadas: **37 habilidades**.
- [x] Cobertura actual: **11,90%**; quedan **274 habilidades**.
- [x] Fuentes adoptadas: mecánicas de Pokémon Showdown, sección `Efecto` de la API de WikiDex y código efectivo de HnS como autoridad final.
- [ ] Completar las 274 fichas restantes por familias mecánicas, sin importar automáticamente textos no verificados.

### 📊 Segundo lote de habilidades avanzadas

- [x] Añadidas 39 fichas de inmunidades, absorciones, contacto, clima y modificadores ofensivos.
- [x] Cobertura acumulada: **76 de 311 habilidades (24,44%)**; quedan **235**.
- [x] El almacén de objetos del PC reajusta ahora las descripciones a tres líneas con la fuente normal usada en la bolsa, manteniendo `SELECT` para ordenar.
- [x] Restaurado el panel original al obtener objetos y ampliado únicamente de cuatro a seis tiles para admitir una tercera línea.

### 📦 Versión `pokehns-0.41.7-20261007-descripciones-pc-habilidades-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría focalizada de textos correcta.
- [x] Compilación completa correcta; validación visual pendiente en emulador.

### 📊 Tercer lote de habilidades avanzadas

- [x] Añadidas 82 fichas tácticas nuevas con porcentajes, multiplicadores, inmunidades y condiciones de activación.
- [x] Cobertura acumulada: **158 de 311 habilidades (50,80%)**; quedan **153**.
- [x] El panel al obtener objetos recupera sus dimensiones originales de ocho tiles.
- [x] Sustituida la fuente estrecha solapada por `FONT_NORMAL`, con ajuste por píxeles y hasta cuatro líneas aprovechando la altura original.

### 📦 Versión `pokehns-0.41.8-20261007-habilidades-50-panel-objetos-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría focalizada y compilación completa correctas.
- [ ] Validación visual pendiente en emulador.

### 📦 Versión `pokehns-0.41.1-20261007-paginado-objetos-largos-es.gba`

- **Fecha:** 07/10/2026
- [x] Eliminado el truncado a 256 bytes de las descripciones obtenidas.
- [x] Búfer dedicado de 512 bytes con límites seguros.
- [x] Catálogo de habilidades medido y ruta de fuentes externas documentada.
- [x] Compilación completa correcta; validación visual final pendiente en emulador.

### 📦 Versión `pokehns-0.41.5-20261007-paginado-objetos-reparado-es.gba`

- **Fecha:** 07/10/2026
- [x] **Versión descartada:** seguía dependiendo de `CHAR_PROMPT_CLEAR`, compartiendo entrada y estado con el cuadro de diálogo inferior; en ejecución continuaba cerrando el panel sin mostrar las páginas restantes.
- [x] Eliminado el corte introducido al limitar el banner a dos líneas: el texto restante ya no se descarta.
- [x] Restaurado el paginado mediante `CHAR_PROMPT_CLEAR` después de cada pareja de líneas.
- [x] La última página permanece visible hasta una nueva pulsación de `A` o `B`.
- [x] Compilación completa correcta; validación visual final pendiente en emulador.

### 📦 Versión `pokehns-0.41.6-20261007-paginado-objetos-independiente-es.gba`

- **Fecha:** 07/10/2026
- [x] Eliminada la dependencia de `CHAR_PROMPT_CLEAR` en el panel superior.
- [x] Las descripciones se dividen en páginas independientes de dos líneas con offsets propios.
- [x] Cada página limpia y actualiza únicamente la ventana superior; una pulsación nueva avanza de página y la última cierra el panel.
- [x] Compilación completa correcta; validación visual final pendiente en emulador.

### 📦 Versión `pokehns-0.41.2-20261007-anticheat-graveyard-fix-es.gba`

- **Fecha:** 07/10/2026
- [x] **Cementerio en PC con 0 PS:** Se ajusta tanto `MON_DATA_HP = 0` como `MON_DATA_HP_LOST = maxHp` antes de copiar a la caja del PC para que aparezcan debilitados de forma persistente.
- [x] **Rescate contra equipo vacío:** Al aplicar el cementerio tras reset/recarga, si el equipo se queda con 0 Pokémon o todos debilitados, se rescata un Pokémon vivo del PC (o genera uno de emergencia) y se cura, evitando crasheos o reinicios al pisar hierba o iniciar combates.
- [x] **Estabilidad de Flash mid-battle:** Se detiene el DMA de sonido (`m4aSoundVSyncOff`), se restablece `SwitchFlashBank(0)` y se restauran los waitstates de SRAM en [save.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/save.c) para evitar saltos a direcciones inválidas (`04EE1A18`) por conmutación del bus.

### 📦 Versión `pokehns-0.41.3-20261007-anticheat-pc-itemdesc-fix-es.gba`

- **Fecha:** 07/10/2026
- [x] **Bajas Nuzlocke sacadas del PC sin guardar:** Al cargar la partida, las bajas del cementerio que no se encuentren en el equipo (por haber sido extraídas del PC sin guardar antes del combate) se buscan en todas las cajas de almacenamiento (`gPokemonStoragePtr->boxes`) y se marcan con 0 PS (`hpLost = maxHp`) o se eliminan según las reglas activas.
- [x] **Render y paginado de descripciones de objetos superior:**
  - En [text.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/text.c), `RENDER_STATE_CLEAR` ahora fuerza `CopyWindowToVram` al limpiar para refrescar la pantalla de inmediato al pulsar `A`.
  - En [overworld.c](file:///d:/PROYECTOS/heartandsoul_esp/pokehns-expansion/src/overworld.c), se ejecuta `RunTextPrinters()` en el bucle nativo de espera, se elimina el `CHAR_PROMPT_CLEAR` espurio final y se espera la pulsación de `A`/`B` para que el jugador pueda leer la última página antes de cerrar el panel superior.

- Las descripciones extendidas de los movimientos, podrías hacer la letra un poco más pequeña? Que a veces solapa por debajo.
- Cuando se muestran los tipos en el combate, deberían estar por encima de todo, se quedan por detrás --> ![alt text](image-8.png)
- ![alt text](image-9.png) --> Que en el panel extra de los movimientos. Todo aparezca con una fuente más pequeña. Y debajo del todo que ponga el desglose de donde viene el PWR.
- Crash peligroso --> ![alt text](image-10.png)

### ✅ Corrección de fichas, tipos y crash de ventanas

- [x] Las fichas extendidas de habilidades y movimientos usan `FONT_SMALL_NARROWER` y admiten hasta cinco líneas sin invadir el pie.
- [x] Los iconos de tipos en combate usan prioridad OAM 0 para quedar delante de barras, indicadores y gráficos superpuestos.
- [x] El panel de movimientos en combate usa fuente pequeña en todo su contenido y añade al final un desglose `PWR` con potencia base, STAB, objeto, clima, eficacia y resultado efectivo.
- [x] El popup de resumen baja de 24×12 a 22×11 tiles: la reserva dinámica pasa de 9.216 a 7.744 bytes.
- [x] Si `AddWindow` no dispone de memoria, el popup restaura los sprites y vuelve al resumen sin acceder a `WINDOW_NONE`, evitando el crash de `src/window.c`.

### 📊 Cuarto lote de habilidades avanzadas

- [x] Añadidas 78 fichas tácticas nuevas.
- [x] Cobertura acumulada: **236 de 311 habilidades (75,88%)**; quedan **75**.

### 📦 Versión `pokehns-0.41.9-20261007-habilidades-75-bugs-ui-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría focalizada y compilación completa correctas.
- [ ] Validación visual y reproducción del crash pendientes en emulador.

- Mismo error que antes --> ![alt text](image-11.png) Las líneas deben estar más separadas en el eje Y, sino se solapan entre ellas.

### ✅ Corrección del interlineado en fichas avanzadas

- [x] La causa era mantener solo 1 píxel de interlineado después de cambiar a `FONT_SMALL_NARROWER`.
- [x] El cuerpo de habilidades, movimientos y concursos usa ahora 4 píxeles de interlineado.
- [x] El contenido se limita a cuatro líneas para conservar separación respecto al pie del modal.

### 📦 Versión `pokehns-0.42.0-20261007-interlineado-fichas-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría focalizada y compilación completa correctas.
- [ ] Validación visual pendiente en emulador.

- Bug gordo, al resucitar un pokémon con las fichas, el resto de pokémon de la caja ya no se ven semitransparentes (aunque siguen sin poder usarse.)

### ✅ Corrección final de habilidades, objetos y selección del PC

- [x] Completadas las **311 de 311 fichas avanzadas de habilidades**: 310 habilidades reales y la entrada informativa `ABILITY_NONE`.
- [x] El cuadro inferior de obtención o recepción usa una altura compacta de tres tiles cuando el mensaje cabe en una línea; los mensajes de dos líneas y el resto de diálogos conservan las dimensiones originales.
- [x] Los **35 movimientos Z** y los **52 movimientos Max/Gigamax** ya estaban fuera de la pool por sus rangos internos.
- [x] Excluidos explícitamente de toda randomización los cuatro ataques temáticos de Dinamax que sí podían aparecer: Cañón Dinamax, Tajo Supremo, Embate Supremo y Rayo Infinito.
- [x] Tras canjear o resucitar con fichas se restablece el modo normal de selección del PC; los Pokémon debilitados vuelven a mostrarse semitransparentes sin alterar el Pokémon revivido.

### 📦 Versión `pokehns-0.42.1-20261007-habilidades-panel-items-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría focalizada sin incidencias y cobertura avanzada 311/311.
- [x] Compilación completa correcta y ROM publicada con `.sav` compatible.
- [ ] Validación visual pendiente en emulador del cuadro compacto y la semitransparencia del PC.

### ✅ Ajuste visual del panel superior al obtener objetos

- [x] Corregida la interpretación del panel: el ajuste afecta a la descripción superior con icono, no al texto descriptivo de la Bolsa.
- [x] La altura se calcula según el contenido: 4 tiles para una o dos líneas, 6 para tres y 8 únicamente para cuatro líneas.
- [x] Texto e icono se centran verticalmente usando la altura real de la ventana, eliminando el espacio sobrante superior e inferior.

### 📦 Versión `pokehns-0.42.2-20261007-panel-objetos-dinamico-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría y compilación completa correctas.
- [x] ROM y `.sav` compatible publicados localmente.
- [ ] Validación visual pendiente en emulador.

![alt text](image-12.png) Algunos movimientos tienen la fuente más pequeña. Deberían ser todos como la de abajo a la derecha.

- Hay que revisar los niveles de los entrenadores en cuanto acabas la liga y vas a coger el ferry. hay algunos entrenadores con pokémon al 55 y otros al 61. Si yo no hubiera tocado nada, en qué nivel estarían? ![alt text](image-13.png)

### ✅ Progresión dinámica post-Liga y Kanto

- [x] El CAP normal progresa tras la Liga por medallas de Kanto: **60, 62, 63, 64, 65, 66, 67, 68 y 70**.
- [x] El modo difícil usa la progresión equivalente **58, 60, 61, 62, 63, 64, 65, 66 y 68**.
- [x] El mismo CAP limita la experiencia y los Caramelos Raros del equipo del jugador mediante `GetCurrentLevelCap()`.
- [x] Los entrenadores normales de Kanto, incluido el ferry, se ajustan a `CAP - 2`; con cero medallas de Kanto su máximo normal es 58.
- [x] Los líderes de Kanto escalan dinámicamente hasta el CAP vigente, independientemente del orden elegido.
- [x] El escalado post-Liga puede reducir equipos escritos por encima del objetivo, conservando sus diferencias internas.
- [x] La revancha avanzada de la Liga (`66–70`) exige las 16 medallas; antes se conservan los equipos de Johto y no se activan los desbloqueos de Campeón de Kanto.

### 📦 Versión `pokehns-0.42.3-20261007-caps-dinamicos-kanto-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría de scripts y compilación completa correctas.
- [x] ROM y `.sav` compatible publicados y sincronizados con `pokehns_fase1`.
- [ ] Validación jugable pendiente desde el ferry hasta la primera medalla de Kanto.
- Los mensajes del pokegear de mamá están en inglés.

### ✅ Corrección de fuentes de movimientos y llamadas de Mamá

- [x] Las cuatro posiciones del menú de movimientos en combate usan `FONT_NARROW`, igualando el aspecto de la posición inferior derecha.
- [x] Traducidas las llamadas del Pokégear de Mamá al comprar objetos, bayas o adornos con los ahorros.

### 📦 Versión `pokehns-0.42.4-20261007-fuentes-movimientos-pokegear-es.gba`

- **Fecha:** 07/10/2026
- [x] Auditoría textual y compilación completa correctas.
- [x] ROM y `.sav` compatible publicados y sincronizados con `pokehns_fase1`.
- [ ] Validación visual pendiente en combate y llamada real del Pokégear.

- [x] Corregido el centrado del icono en el panel superior de objetos: el ajuste anterior lo desplazaba 8 píxeles hacia arriba; ahora se mueve 8 píxeles hacia abajo dentro de la altura dinámica.
- [x] Ajuste visual adicional: el icono baja otros 8 píxeles para compensar la reducción real del panel superior.

- [x] Corregidos los diálogos del Sr. Pokémon (Ruta 30) y 24 saltos de línea huérfanos en scripts de Johto (Ruta 30, Parque Nacional, Trigal, Encinar, Rutas 34-36).
- [x] Añadida regla de detección `HUERFANO` en `docs/utilidades/auditar_textos_gba.ps1`.
- [x] Integrados ajustes de escenarios en Ciudad Orquídea y Gruta de las Tres Mareas.

### 📦 Versión `pokehns-0.43.8-20261008-mrpokemon-orquidea-es.gba`

- **Fecha:** 08/10/2026
- [x] Auditoría textual de Johto y compilación completa en WSL sin errores.
- [x] ROM y `.sav` compatible publicados en `releases/` y sincronizados con `pokehns_fase1`.
- [x] Cambios subidos a `origin/traduccion-es`.

### 📦 Versión `pokehns-0.43.9-20261008-ajuste-marea-orquidea-es.gba`

- **Fecha:** 08/10/2026
- [x] Ajustadas coordenadas de triggers y carteles de retorno en Gruta Tres Mareas.
- [x] Compilación limpia en WSL y publicación de ROM y `.sav` en `releases/` y raíz.

### 📦 Versión `pokehns-0.44.0-20261008-puzzle-mareas-fuerza-es.gba`

- **Fecha:** 08/10/2026
- [x] Nuevo mapa amplio cavernoso de 30×30 (`CianwoodThreeTidesPuzzle_hns`) para el Santuario de las Tres Mareas.
- [x] Puzle mecánico de Fuerza con 3 monolitos/rocas desplazables y 3 hendiduras con triggers (`Calma`, `Eco`, `Brío`).
- [x] Efectos de temblor de pantalla y sonidos de asentamiento al encajar cada roca y al desbloquear al Sabio Anciano.
- [x] Conexión directa desde Ciudad Orquídea al santuario y warp de salida funcional.
- [x] Auditoría textual limpia, compilación completa en WSL y cambios subidos a `origin/traduccion-es`.
- [x] ROM y `.sav` sincronizados tanto en `releases/` como en `pokehns_fase1.gba` y `pokehns_fase1.sav`.

### 📦 Versión `pokehns-0.44.1-20261008-acertijo-mareas-orquidea-es.gba`

- **Fecha:** 08/10/2026
- [x] Integradas las nuevas posiciones de rocas y hendiduras editadas en Porymap.
- [x] Redactado acertijo en el cartel indicando con claridad cada destino (Norte para Calma, Centro para Eco, y rincón Sureste/abajo a la derecha para Brío).
- [x] Incorporada la frase de confirmación _“Has elegido... sabiamente”_ al encajar cada una de las rocas.
- [x] Ajustado el tileset primario del layout a `gTileset_Johto_General_Hns` para resolver la referencia indefinida de FRLG.
- [x] Compilación limpia en WSL, cambios subidos a `origin/traduccion-es` y ROM / `.sav` sincronizados.

### 📦 Versión `pokehns-0.44.2-20261008-puzzle-3rocas-simultaneas-es.gba`

- **Fecha:** 08/10/2026
- [x] Corregida la activación del puzle de las mareas: pisar el agujero ya no cuenta; ahora se exige que las 3 rocas de Fuerza estén colocadas simultáneamente.
- [x] Añadida la rutina de control `IsBoulderAtCoords` y soporte en el motor (`HandleBoulderActivateVictoryRoadSwitch`) para activar triggers al terminar el movimiento de la roca.
- [x] Nuevo mensaje misterioso al colocar las 3 rocas: _“Sientes que una presencia sabia ha aparecido en el norte.”_
- [x] Documentación actualizada en `docs/mejoras_futuras/secretos_ocultos_johto.md`.
- [x] Compilación limpia en WSL, cambios subidos a `origin/traduccion-es` y ROM / `.sav` sincronizados.

### ✅ Corrección de nombres de entrenadores, guardería, combate y Centro Comercial

- **Nombres oficiales en castellano**: El Joven de la Ruta 30 (y sus revanchas) pasa de `JOEY` a su nombre oficial en castellano: `CHANO` en `src/data/trainers_hns.party`.
- **Acertijo de palabras en la Guardería (Ruta 34)**:
  - Los 4 tomos de la enciclopedia de Pokémon bebé en las estanterías de la guardería están en castellano en `src/data/help_window.h`.
  - El sistema de selección de palabras (Easy Chat) utiliza el diccionario nativo del motor; los diálogos del chico del Huevo Raro y sus respuestas están localizados al castellano en `data/maps/Route34_DayCare_hns/scripts.inc`.
- **Mensajes de despertar y descongelar en combate**:
  - `STRINGID_PKMNWOKEUP`: Traducido a *“¡{B_ATK_NAME_WITH_PREFIX} se despertó!”*.
  - `STRINGID_TARGETWOKEUP`: Traducido a *“¡{B_DEF_NAME_WITH_PREFIX} se despertó!”*.
  - `STRINGID_PKMNWASDEFROSTED`: Traducido a *“¡{B_SCR_NAME_WITH_PREFIX} se descongeló!”*.
- **Turistas de Ciudad Luminalia (Puzle de Kalos en Ciudad Malva)**:
  - Asignada la flag `FLAG_HIDE_VIOLET_KALOS_TOURISTS` a Gustal, Maelle y Verson en `data/maps/VioletCity_hns/map.json`.
  - En `VioletCity_OnTransition`, permanecen ocultos hasta que se recibe la llamada del PokéGear (`FLAG_VIOLET_KALOS_CALL_TRIGGERED`).
- **El Piedras en el Centro Comercial de Trigal (2.ª Planta)**:
  - Ahora es posible rechazar su oferta inicial de la Piedra Inútil y volver más tarde a comprársela sin que fuerce el combate de inmediato.
  - Al cerrar el trato o proceder al combate, ejecuta una curación completa del equipo (`special HealPlayerParty` y fanfarria `MUS_HEAL`) antes de iniciar la batalla.


- Hay que anular las máquinas expendedoras o cualquier cosa ue venda objetos de cura.

### ✅ Sabio de las Tres Mareas — versión 0.52.5

- [x] Corregida la aparición del sabio tras colocar simultáneamente las tres
      piedras en el santuario de Ciudad Orquídea.
- [x] El puzle usa ahora `FLAG_CIANWOOD_THREE_TIDES_PUZZLE_COMPLETE` en vez de
      reutilizar `FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE`, que podía estar activa por
      el progreso anterior y anulaba la comprobación de la versión 0.52.4.
- [x] Las partidas que ya tengan las tres piedras colocadas vuelven a comprobar
      la solución al caminar por el mapa, sin tener que reiniciar el puzle.



- [x] Dara te dice mal la habilidad que va a cambiar de tu pokémon. Vamos a meterle una funcionalidad que permite, por 100000, recuperar una habilidad que tuviera un pokémon de la línea evolutiva.
  - Corregido el buffer de previsualización `{STR_VAR_3}` en las opciones estándar para que refleje de forma exacta la habilidad destino seleccionada (tanto normal como oculta).
  - Añadido servicio de consulta ancestral por 100.000¥: rastrea el árbol de preevoluciones directas (`GetPreEvolutionAbilities`), extrae las habilidades que poseía la línea evolutiva y las presenta dinámicamente mediante `dynmultistack` para permitir recuperar habilidades previas (ej. *Levitación* en Gengar u otras de preevolución).
  - Incluidos diálogos de confirmación, cobro estricto de 100.000¥ y comprobación de saldo con fallbacks limpios.

- [x] Los diálogos de Kanto están fatal. No sé si el error viene porque se tradujeron mal y luego ya la auditoría no funcionara o qué, pero hay que revisarlos. Ciudad Azulona y Azafrán ya están teóricamente arregladas, ponte con el resto de Kanto de una pasada.
  - Auditoría exhaustiva automatizada sobre los 132 mapas activos de Kanto (`gMapGroup_Outdoor_Hns`, interiores y mazmorras `_hns`).
  - Corregidos cortes prematuros de texto (`\n$`, `\l$`, `\p$`) y terminadores ausentes que hacían sangrar diálogos entre NPCs en Ciudad Azulona, Ciudad Azafrán y el resto de Kanto.
  - Verificados y traducidos los textos pendientes en inglés en casas de paso, rutas exteriores y dojo de combate de Azafrán.
  - Verificación final de integridad de strings y compilación de ROM limpia en WSL.

- [x] Pantalla azul al abrir las formas de Kyurem en la Pokédex.
  - `sKyuremFormSpeciesIdTable` anunciaba Kyurem Blanco y Negro aunque
    `P_FUSION_FORMS` estuviera desactivado y sus datos no se compilaran.
  - Las formas fusionadas quedan condicionadas por `P_FUSION_FORMS` en
    `src/data/pokemon/form_species_tables.h`.

- [x] Crash / Reinicio del juego al consultar el Recordador de Movimientos con Rayquaza.
  - **Causa:** En `src/move_relearner.c`, al listar las MTs compatibles de la bolsa junto con los movimientos por nivel, `GetRelearnerTMMoves` llenaba el array de la pila `tmTempMoves[MAX_RELEARNER_MOVES]`. Dado que en HNS hay 114 máquinas y Rayquaza puede aprender más de 60 MTs que el jugador acumula en la mochila, se producía un desbordamiento de búfer en la pila (Stack Buffer Overflow), pisando la dirección de retorno y provocando un reinicio hardware.
  - **Solución:** Aumentado `MAX_RELEARNER_MOVES` de 60 a 150 en `include/constants/move_relearner.h` e implementadas comprobaciones estrictas de límite (`numMoves < MAX_RELEARNER_MOVES`) en `GetRelearnerTMMoves`, `GetRelearnerLevelUpMoves`, `GetRelearnerEggMoves` y `GetRelearnerTutorMoves`.
  - **NPC Legendarios de Hoenn en Pueblo Paleta:** Incorporado un sabio en Pueblo Paleta (`PalletTown_hns`, coordenadas 13, 15) que entrega el Prisma Azul (`ITEM_BLUE_ORB`) al llevar a Kyogre, el Prisma Rojo (`ITEM_RED_ORB`) al llevar a Groudon, y enseña Ascenso Draco (`MOVE_DRAGON_ASCENT`) a Rayquaza como tutor para desbloquear la Megaevolución en combate.
