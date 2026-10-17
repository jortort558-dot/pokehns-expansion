# Telemetría de encuentros Nuzlocke

La telemetría de encuentros se publica únicamente en el bloque `HNS1` de EWRAM.
No añade campos a `SaveBlock1`, `SaveBlock2` ni `SaveBlock3` y no cambia el
formato del archivo `.sav`.

## Eventos

- `HNS_LIVE_EVENT_ENCOUNTER_START` (`type = 7`): se emite al preparar un
  encuentro salvaje normal, después de ejecutar las comprobaciones Nuzlocke.
- `HNS_LIVE_EVENT_ENCOUNTER_END` (`type = 8`): se emite al terminar ese
  encuentro. `cause` contiene el valor `B_OUTCOME_*`.

Ambos eventos conservan `personality`, `otId`, especie, nivel y sección del
mapa. La pareja `personality + otId` permite relacionar inicio, captura y final
del mismo ejemplar sin depender de la especie aleatoria.

## Bits de `flags`

| Bit | Constante | Significado |
| --- | --- | --- |
| 0 | `HNS_LIVE_ENCOUNTER_SHINY` | El ejemplar es shiny. |
| 1 | `HNS_LIVE_ENCOUNTER_FIRST_VALID` | Primer encuentro normal válido de la zona. |
| 2 | `HNS_LIVE_ENCOUNTER_SHINY_EXCEPTION` | La cláusula shiny permite capturarlo. |
| 3 | `HNS_LIVE_ENCOUNTER_DUPLICATE_LINE` | La línea evolutiva ya fue capturada. |
| 4 | `HNS_LIVE_ENCOUNTER_ROUTE_USED` | La zona ya tenía consumido su encuentro. |
| 5 | `HNS_LIVE_ENCOUNTER_CAPTURE_SUSPENDED` | La regla de captura está suspendida. |
| 6 | `HNS_LIVE_ENCOUNTER_SCRIPTED` | El combate es un encuentro de guion. |
| 7 | `HNS_LIVE_ENCOUNTER_OTHER_CHALLENGE_BLOCK` | Otro reto, como monotipo, bloquea la captura. |

La web debe aceptar una captura automática cuando el evento tenga
`FIRST_VALID` o `SHINY_EXCEPTION`. Una captura con ninguno de esos bits debe
generar una revisión arbitral, no una acusación automática.

Un shiny que aparece en una ruta ya consumida conserva simultáneamente los
bits `SHINY`, `SHINY_EXCEPTION` y `ROUTE_USED`. Por ello puede registrarse como
captura excepcional sin sustituir ni consumir de nuevo el encuentro oficial.

