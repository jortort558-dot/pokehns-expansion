# Recordador de movimientos en Centros Pokémon

## Estado

Propuesta pendiente de implementación. El motor necesario ya está incluido en
`pokeemerald-expansion`, pero HnS no ofrece actualmente este servicio desde los
Centros Pokémon.

## Objetivo

Ofrecer una comodidad similar a Pokémon Añil: permitir recordar movimientos
desde un asistente de los Centros Pokémon sin invalidar las MT, los tutores ni
los movimientos huevo como elementos de progresión.

## Diseño recomendado

- Reutilizar al encargado que actualmente gestiona las Fichas Gimnasio y
  convertirlo en un asistente de servicios.
- Mostrar `RECORDAR MOV.` aunque no haya un Nuzlocke activo.
- Mantener los servicios de Fichas Gimnasio condicionados a un Nuzlocke
  compatible y a que la opción correspondiente esté activada.
- Permitir recordar gratuitamente movimientos aprendidos por nivel hasta el
  nivel actual.
- Incluir movimientos disponibles en las preevoluciones del Pokémon.
- Incluir únicamente movimientos de MT cuya máquina esté ya en la Bolsa.
- No incluir movimientos huevo ni movimientos exclusivos de tutor.
- Mantener el Recuerda-Movimientos de Endrino hasta decidir si se conserva,
  se especializa en movimientos huevo/tutor o se sustituye por otro servicio.

## Configuración prevista

En `include/config/summary_screen.h`:

```c
#define P_ENABLE_MOVE_RELEARNERS         FALSE
#define P_PRE_EVO_MOVES                  TRUE
#define P_TM_MOVES_RELEARNER             TRUE
#define P_ENABLE_ALL_TM_MOVES            FALSE
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  FALSE
#define P_PARTY_MOVE_RELEARNER           FALSE
```

`P_ENABLE_MOVE_RELEARNERS` debe permanecer desactivado. Activarlo desbloquearía
a la vez movimientos huevo, MT y tutor, independientemente del diseño de
progresión de HnS.

La propuesta usa el NPC y no la ficha Pokémon ni el menú del equipo. El script
común ya disponible es `Common_EventScript_MoveRelearner`, definido en
`data/scripts/move_relearner.inc`.

## Integración con el asistente

El menú general del NPC debería separar el recordador de los servicios
Nuzlocke. Una estructura orientativa sería:

```text
RECORDAR MOV.
FICHAS GIM.
EXPLICACIÓN
SALIR
```

Si las Fichas Gimnasio no están disponibles, esa entrada puede ocultarse. El
recordador no debe depender de `IsNuzlockeActive()` ni consumir fichas.

La alternativa mínima consiste en añadir la opción únicamente a los
encargados ya colocados en ciudades con gimnasio. Para reproducir exactamente
la disponibilidad de Añil habría que colocar o reutilizar un asistente en todos
los Centros Pokémon de HnS, lo que aumenta el número de mapas que deben
editarse y probarse.

## Decisiones pendientes

1. Disponibilidad en todos los Centros Pokémon o solo en los principales.
2. Función definitiva del Recuerda-Movimientos de Endrino.
3. Tratamiento de las MO: permitir recordarlas como cualquier MT obtenida o
   excluirlas del servicio general.
4. Nombre y diálogo del asistente cuando no hay un Nuzlocke activo.
5. Posible servicio avanzado de pago para movimientos huevo en una versión
   posterior.

## Compatibilidad

- No requiere ampliar el guardado ni migrar partidas.
- No modifica el randomizer de movimientos o de MT. La lista debe continuar
  dependiendo de las máquinas que el jugador posea y de la compatibilidad real
  calculada por el motor.
- Debe funcionar fuera de Nuzlocke y no alterar encuentros, muertes ni reglas
  del reto.
- El selector existente admite equipo y PC, pero debe comprobarse que los
  Pokémon debilitados bloqueados por Nuzlocke no puedan producir una ruta de
  acceso no deseada.

## Validación necesaria

- Pokémon del equipo y de las cajas.
- Pokémon sin movimientos disponibles y Huevos.
- Movimientos de nivel, nivel 1 y preevoluciones.
- MT poseída frente a MT todavía no obtenida.
- Compatibilidad y restricciones de MO.
- Sustitución de un movimiento cuando ya se conocen cuatro.
- Cancelación en cada selector sin modificar el Pokémon.
- Uso consecutivo sin abandonar el menú del asistente.
- Funcionamiento con Nuzlocke desactivado, fácil, normal y difícil.
- Build completa de HnS y prueba visual de todos los textos añadidos.

