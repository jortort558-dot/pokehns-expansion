# Sistema de Ficha Gimnasio

## Estado

Diseño técnico previo a la implementación. Las reglas funcionales quedan cerradas en este documento para evitar cambios improvisados en el guardado, el Nuzlocke o los intercambios.

## Objetivo

Añadir un recurso excepcional para partidas Nuzlocke que permita corregir una mala situación sin eliminar el riesgo del desafío.

- Se obtiene **1 Ficha Gimnasio por cada medalla**.
- Se pueden llevar como máximo **3 fichas**.
- Solo se usan hablando con un **NPC especial de los Centros Pokémon**.
- Nunca se usan durante un combate.
- Son consumibles permanentes.
- Servicios disponibles:
  - segundo intento de captura en una zona fallida: **1 ficha**;
  - intercambio misterioso: **1 ficha**;
  - resurrección de un Pokémon: **2 fichas**.

El sistema solo estará activo en Nuzlocke normal o fácil. Fuera de esos modos, el NPC explicará que el servicio necesita un desafío Nuzlocke activo.

## Reglas comunes

### Obtención y límite

- Cada una de las 16 medallas de Johto y Kanto puede entregar una sola ficha.
- La entrega se registrará por medalla, no mediante el valor de `VAR_NUM_BADGES`. Así no podrá duplicarse hablando otra vez con un líder, repitiendo scripts o alterando el orden de los gimnasios.
- Si el jugador ya tiene 3 fichas, la recompensa de esa medalla se pierde. El mensaje debe avisarlo expresamente; no habrá un almacén oculto que permita superar el límite.
- Los scripts de depuración que activan medallas no deben conceder fichas salvo que llamen expresamente a la función de entrega.

### NPC y menú

El mismo NPC aparecerá en todos los Centros Pokémon principales y llamará a un script común. El menú mostrará siempre el saldo actual:

1. Segundo intento — 1 ficha.
2. Intercambio misterioso — 1 ficha.
3. Resurrección — 2 fichas.
4. Explicación.
5. Salir.

Una opción sin candidatos válidos debe explicar el motivo y volver al menú sin consumir nada.

### Transacción segura

Todas las operaciones seguirán este orden:

1. comprobar modo, saldo y candidatos;
2. elegir el objetivo;
3. mostrar el resultado exacto o sus condiciones y pedir confirmación;
4. volver a validar el objetivo, por si el menú externo hubiera cambiado el equipo o el PC;
5. aplicar a la vez el efecto, su marca permanente y el gasto;
6. guardar la partida antes de devolver el control o revelar un resultado aleatorio.

Cancelar, cerrar un selector o no tener espacio nunca gastará fichas. La recarga del mapa no repetirá recompensas ni operaciones.

## Segundo intento de captura

### Regla jugable

- Solo puede comprarse para una zona en la que el primer encuentro válido terminó **sin captura**.
- El jugador elige una zona concreta de una lista con nombres legibles.
- La compra habilita el siguiente encuentro válido de esa zona; no genera inmediatamente un Pokémon ni garantiza la misma especie.
- Cada zona admite como máximo un segundo intento durante toda la partida.
- Si el segundo intento también falla, la zona queda cerrada definitivamente.
- Si se captura en el segundo intento, queda cerrada como cualquier captura normal.

### Qué cuenta como fallo

Cuenta como fallo derrotar al Pokémon, huir, que el rival huya o que cualquiera de los dos se teletransporte. Una captura correcta no genera derecho a reintento.

No alteran el estado de la zona los encuentros que el sistema actual ya excluye: cláusula de especie, Pokémon de tipo no permitido, excepción shiny, Safari, Concurso de Captura de Bichos, combates dobles, legendarios, errantes, combates enlazados, tutoriales y demás tipos especiales ya filtrados por el Nuzlocke.

### Cambio de datos necesario

Actualmente `nuzlockeEncounterFlags` solo indica que la zona fue consumida; no distingue éxito de fallo. Se conservará ese registro y se añadirán dos mapas de 96 bits:

- `failedEncounterFlags`: el intento consumido acabó sin captura;
- `retriedEncounterFlags`: esa zona ya compró su segundo intento.

Estados derivados:

| Consumida | Fallida | Reintentada | Significado |
|---:|---:|---:|---|
| 0 | 0 | 0 | Primer intento disponible |
| 1 | 0 | 0/1 | Captura conseguida; zona cerrada |
| 1 | 1 | 0 | Fallo inicial; puede comprar reintento |
| 0 | 0 | 1 | Reintento comprado y pendiente |
| 1 | 1 | 1 | Segundo intento fallido; zona cerrada |

La compra marca primero `retriedEncounterFlags`, limpia el consumo y el fallo de la zona, descuenta la ficha y guarda. El final del siguiente combate vuelve a registrar consumida y distingue `B_OUTCOME_CAUGHT` del resto.

## Intercambio misterioso

### Pokémon entregado

El jugador elige un Pokémon de su equipo o del PC. Debe estar vivo, no ser un Huevo, no estar fusionado ni ser un Pokémon temporal o bloqueado por un evento. No se aceptan Pokémon muertos, corruptos ni el último Pokémon vivo si las reglas del selector pudieran dejar al jugador sin equipo utilizable.

El intercambio sustituye al Pokémon en su misma posición. De este modo no necesita una casilla adicional en el equipo o el PC y la operación puede ser atómica.

### Nivel y calidad del recibido

- El nivel será la **mediana del equipo vivo** en el momento de confirmar, limitado por el tope de nivel vigente y con mínimo 5.
- Se elige una familia distinta de la entregada y disponible en la Pokédex del proyecto.
- Se excluyen legendarios, singulares, Ultraentes, formas temporales, especies desactivadas y Pokémon que no puedan existir de forma estable fuera de combate.
- La comparación se hace por el total de estadísticas base de la evolución final de cada familia. La familia recibida tendrá un total igual o superior al de la entregada y, cuando haya candidatos, no más de 80 puntos por encima.
- Se genera la fase evolutiva que sea legal al nivel concedido. No se entregará una evolución a un nivel al que normalmente no podría existir, salvo evoluciones sin requisito de nivel.
- Tendrá al menos **dos IV perfectos**; el resto, naturaleza, sexo y habilidad serán aleatorios legales.
- No se garantiza shiny, naturaleza competitiva, habilidad oculta ni objeto equipado.
- Se respeta la cláusula de especie: no se escogerá una familia que ya figure como capturada si la cláusula está activa.

“A priori mejor” significa, por tanto, mejor potencial de familia y un suelo razonable de IV, no una ventaja perfecta ni un legendario garantizado.

### Identidad y aleatoriedad

El Pokémon recibido tendrá OT y número de entrenador propios del NPC para que sea un intercambio real, pero su nivel nunca superará el límite de obediencia aplicable a las medallas actuales. Llegará sin objeto y con movimientos legales para su especie y nivel.

El resultado se calculará con una semilla derivada de la partida y un contador persistente de intercambios. Tras confirmar se sustituirá el Pokémon, se incrementará el contador, se gastará la ficha y se guardará **antes** de mostrar la especie. Reiniciar no permitirá obtener otro resultado conservando la ficha.

## Resurrección

### Candidatos

- Solo aparecen Pokémon muertos por las reglas Nuzlocke y conservados en el PC con 0 PS.
- No aparecen Huevos, datos corruptos, Pokémon vivos ni Pokémon que ya hayan sido resucitados.
- En la modalidad de borrado permanente no se puede resucitar un Pokémon que ya fue eliminado: no se recreará a partir de especie, Pokédex ni copias externas.
- El coste es de 2 fichas y se muestra antes de abrir la confirmación final.

### Resultado

- El Pokémon conserva especie, forma, nivel, experiencia, movimientos, PP máximos, EV, IV, naturaleza, habilidad, amistad, mote, OT y cintas.
- Se eliminan sus problemas de estado y recupera todos los PS y PP, igual que una cura completa en el Centro Pokémon.
- Permanece en su casilla del PC; el jugador lo retira después de forma normal.
- El objeto que llevaba al morir no reaparece, porque el sistema Nuzlocke actual lo devuelve a la Bolsa en el momento de la muerte.

### Una sola vez por Pokémon

Se reutilizará uno de los bits sin uso de `BoxPokemon` como marca `hasBeenGymRevived` y se expondrá mediante `MON_DATA_HAS_BEEN_GYM_REVIVED`. La marca viaja con el Pokémon al moverlo, depositarlo o intercambiarlo y no depende de su caja, posición, mote, especie o personalidad. Se asigna antes de curarlo y nunca se limpia.

No debe usarse `modernFatefulEncounter`: ya tiene significado propio y actualmente concede una excepción de captura Nuzlocke.

## Persistencia y migración

Se añadirá al final de `SaveBlock3` una estructura específica, sin desplazar campos existentes:

```c
struct GymTokenState
{
    u8 count;
    u8 mysteryTradeCount;
    u16 awardedBadgeMask;
    u8 failedEncounterFlags[NUZLOCKE_FLAG_BYTES];
    u8 retriedEncounterFlags[NUZLOCKE_FLAG_BYTES];
};
```

Antes de implementarlo se verificará por `STATIC_ASSERT` que `SaveBlock3` continúa dentro de su capacidad. El cambio requiere subir `SAVE_VERSION` y migrar:

- poner a cero los dos mapas y el contador de intercambios;
- construir `awardedBadgeMask` leyendo las 16 banderas reales de medalla;
- conceder a partidas Nuzlocke existentes `min(medallas, 3)` fichas retroactivas;
- interpretar las zonas ya consumidas de una partida antigua como cerradas sin derecho a reintento, porque no existe información fiable para saber si hubo captura o fallo;
- inicializar a cero el nuevo bit de resurrección en todos los Pokémon existentes de equipo, PC y guardería si la representación anterior no garantiza ese valor.

## Integración prevista

La implementación se dividirá en cambios pequeños:

1. `gym_tokens.c/.h`: saldo, entrega por medalla, estados de zona, candidatos y transacciones.
2. Guardado y migración: `global.h`, `save.h`, `save.c` y aserciones de tamaño.
3. Resultado Nuzlocke: sustituir la escritura indiferenciada al final del combate por una función que reciba `gBattleOutcome`.
4. Marca por Pokémon: renombrar el bit libre, añadir `MON_DATA_*` y sus accesores en `pokemon.c`.
5. Selectores de PC/equipo: reutilizar `ChooseMonFromStorage` y las utilidades existentes, sin duplicar una pantalla completa.
6. NPC común: script, textos, menú y colocación en los Centros Pokémon HnS.
7. Entrega de medallas: llamada común después de confirmar cada una de las 16 medallas.
8. Migración y pruebas automatizadas/manuales.

## Pruebas obligatorias

### Fichas y medallas

- Primera obtención, las 16 medallas, orden alternativo y diálogo repetido con el líder.
- Saldo 0, 1, 2 y 3; recompensa recibida con saldo 2 y perdida con saldo 3.
- Scripts de depuración y carga de una partida anterior.

### Captura

- Captura inicial, derrota, huida, Teletransporte y Rugido.
- Compra cancelada, compra confirmada, cambio de mapa, guardado y reinicio.
- Éxito y fallo del segundo intento; comprobar que nunca existe un tercero.
- Cláusulas de especie, shiny y monotipo; Safari, Concurso de Bichos, dobles, estáticos, legendarios y errantes.
- Dos mapas que compartan `regionMapSectionId` deben compartir correctamente el estado de zona.

### Intercambio

- Equipo y todas las cajas; equipo lleno, PC lleno y último Pokémon vivo.
- Huevo, muerto, fusionado, especie excluida y dato corrupto.
- Nivel por debajo y por encima del tope, familias sin candidato superior y cláusula de especie saturada.
- Cancelación en cada pantalla y reinicio antes y después de confirmar.
- Verificar movimientos, obediencia, OT, IV, formas y que nunca conserva el objeto del entregado.

### Resurrección

- Muerto en PC, vivo, Huevo, PC lleno y Pokémon con mote o forma especial.
- Modos Nuzlocke fácil, cementerio y borrado permanente.
- Curación completa, objeto ya devuelto a la Bolsa y retirada posterior del PC.
- Matar de nuevo al resucitado y comprobar que no vuelve a ser candidato.
- Moverlo entre cajas, guardería, equipo e intercambio sin perder la marca.

### Integridad

- Compilar con aserciones de tamaño de los tres bloques de guardado.
- Nueva partida y migración desde una partida de la versión anterior.
- Guardar/cargar en ambos slots, interrupción simulada durante el guardado y comprobación de checksum.
- Auditar los textos del NPC con `docs/utilidades/auditar_textos_gba.ps1`.

## Criterio de finalización

La función no se considerará terminada hasta que las tres operaciones compartan la misma lógica de saldo y confirmación, la migración se haya probado con una partida anterior, no exista una vía para repetir recompensas o reintentos y la ROM resultante se haya publicado conforme al flujo normal del proyecto.
