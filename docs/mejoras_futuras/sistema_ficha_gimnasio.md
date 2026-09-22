# Sistema de Ficha Gimnasio

## Estado actual

Implementación jugable experimental incluida en la versión 0.18.0. El punto de
prueba está en el Centro Pokémon de Ciudad Trigal. La entrega de fichas sí está
conectada a los 16 gimnasios de Johto y Kanto.

La prueba permite validar el guardado, el selector compartido de equipo/PC y las
tres transacciones antes de extender el recepcionista a todos los Centros
Pokémon. No debe confundirse este primer interfaz con el diseño final: el segundo
intento recupera por ahora la zona fallida más antigua, sin mostrar aún una lista
de rutas.

## Reglas

- Solo funciona con un Nuzlocke normal o fácil activo.
- Cada medalla concede una Ficha Gimnasio una sola vez.
- El jugador puede llevar un máximo de 3 fichas.
- Si se obtiene una medalla con el saldo al máximo, esa ficha se pierde.
- Segundo intento de captura: 1 ficha.
- Intercambio misterioso: 1 ficha y un uso máximo por partida.
- Resurrección: 2 fichas y una sola vez por Pokémon.
- Cancelar un selector o fallar una validación no consume fichas.

## Cómo se usa en esta prueba

1. Iniciar un reto Nuzlocke normal o fácil.
2. Conseguir una medalla para recibir una ficha.
3. Hablar con el caballero situado en el Centro Pokémon de Ciudad Trigal.
4. El NPC muestra el saldo y pregunta en orden por los tres servicios.
5. Intercambio y resurrección abren el selector conjunto del equipo y el PC.

El NPC usa preguntas consecutivas durante la prueba. El menú definitivo tendrá
las opciones visibles a la vez, explicación y salida.

## Obtención y protección contra duplicados

Los 16 scripts que incrementan `VAR_NUM_BADGES` llaman después a
`AwardGymToken`. La función utiliza un mapa de 16 bits, por lo que repetir el
diálogo del líder o ejecutar de nuevo una parte del script no duplica la ficha.

La llamada no concede nada si el Nuzlocke ya terminó, todavía no empezó o el
modo no es compatible. La máscara de la medalla sí queda registrada cuando el
saldo ya es 3: no existe una cola oculta de recompensas.

## Segundo intento de captura

Al terminar un encuentro salvaje válido, el sistema Nuzlocke continúa marcando
la zona como consumida. Si el resultado no fue una captura, además marca la zona
como fallida. Se respetan las exclusiones existentes: cláusula de especie,
monotipo, Safari, Concurso de Bichos, dobles, legendarios, errantes, enlaces y
otros combates especiales no crean un derecho de reintento.

Al pagar una ficha, la prueba busca la primera zona fallida que todavía no haya
usado su segundo intento:

1. marca permanentemente que esa zona ya reintentó;
2. limpia el consumo y el fallo del primer encuentro;
3. descuenta una ficha;
4. deja disponible el siguiente encuentro válido de la zona.

Si el segundo encuentro falla, la zona se registra otra vez como consumida y no
puede comprarse un tercero. Si se captura, queda cerrada de la forma habitual.

### Mejora pendiente del interfaz

El estado ya distingue las 96 zonas, pero falta la lista dinámica con nombres
legibles para que el jugador elija una concreta. Hasta incorporarla, el NPC de
Trigal recupera el fallo más antiguo según el orden interno de zonas. Este límite
es de interfaz, no del formato de guardado.

## Intercambio misterioso

El selector solo acepta Pokémon vivos y que no sean Huevos. Puede elegirse un
Pokémon del equipo o de cualquier caja. El candidato no puede llevar un objeto,
evitando que se pierda de forma silenciosa.

La especie recibida:

- está habilitada en el proyecto;
- no es legendaria, singular, Ultraente ni una forma temporal de combate;
- tiene un total de estadísticas base entre el del Pokémon entregado y 80 puntos
  por encima;
- conserva el nivel del Pokémon entregado;
- se crea con personalidad, IV, naturaleza, sexo y habilidad legales al azar;
- llega con sus movimientos iniciales legales y sin objeto.

El nuevo Pokémon sustituye al anterior en la misma posición, por lo que no hace
falta hueco adicional. Si estaba en el equipo se sustituyen sus datos completos;
si estaba en el PC se reemplaza su `BoxPokemon`. El saldo y el contador del único
intercambio permitido se actualizan en la misma operación.

La prueba usa al jugador como OT, igual que la rutina estándar de creación. Para
la versión definitiva quedan pendientes un OT propio del recepcionista, dos IV
perfectos garantizados, nivel basado en la mediana del equipo y guardado forzado
antes de revelar el resultado.

## Resurrección

El selector especial permite ver los Pokémon muertos que el Nuzlocke conserva
en el PC con 0 PS, aunque el selector normal los oculta. Rechaza Pokémon vivos,
Huevos y ejemplares ya resucitados.

Al confirmar:

- se gastan 2 fichas;
- se restauran PS, PP y estado con `HealBoxPokemon`;
- el Pokémon permanece en su misma casilla;
- se registra su pareja de personalidad y OT para impedir otra resurrección.

Hay ocho registros persistentes, más que las ocho resurrecciones máximas que
permiten las 16 fichas teóricas. En modos que borran al Pokémon al morir no hay
nada que seleccionar y el sistema no intenta reconstruirlo.

## Guardado y migración

`SaveBlock3` incorpora al final el siguiente estado, sin desplazar los campos
anteriores:

```c
u8 count;
u8 mysteryTrades;
u16 awardedBadgeMask;
u8 failedEncounterFlags[12];
u8 retriedEncounterFlags[12];
u32 revivedPersonalities[8];
u32 revivedOtIds[8];
```

`SAVE_VERSION` pasa de 5 a 6. Al cargar una partida anterior se inicializa todo
el estado a cero. Esta migración deliberadamente no concede fichas retroactivas:
evita inferir recompensas o fallos que la versión anterior nunca registró. Las
medallas futuras sí entregarán fichas normalmente.

## Archivos principales

- `src/gym_tokens.c` y `include/gym_tokens.h`: reglas y transacciones.
- `include/global.h`: estado persistente.
- `src/save.c` e `include/save.h`: migración de versión.
- `src/battle_main.c` y `src/nuzlocke.c`: resultado de encuentro y reapertura.
- `src/chooseboxmon.c`: filtros de intercambio y resurrección.
- `data/maps/GoldenrodCity_PokemonCenter_hns/`: NPC piloto y textos.
- scripts de los 16 gimnasios HnS: entrega de ficha.

## Prueba manual recomendada

1. Guardar una partida de versión 0.17.0 y cargarla en la nueva ROM.
2. Verificar que continúa sin corrupción y que el NPC muestra 0 fichas.
3. Obtener una medalla en Nuzlocke y comprobar saldo 1.
4. Perder un encuentro, comprar el segundo intento y volver a esa ruta.
5. Fallar otra vez y comprobar que el NPC no concede un tercer intento.
6. Intercambiar desde equipo y PC; comprobar sustitución y límite de un uso.
7. Con 2 fichas, resucitar un muerto del PC, volver a debilitarlo y comprobar
   que ya no es seleccionable.
8. Alcanzar 3 fichas, obtener otra medalla y comprobar que el saldo no supera 3.

## Trabajo restante antes de declararlo definitivo

- Selector dinámico de zonas fallidas con nombres legibles.
- Menú único de servicios y despliegue del NPC en los Centros principales.
- Aviso visible al recibir o perder una ficha tras cada medalla.
- Guardado obligatorio dentro de cada transacción aleatoria.
- Reglas avanzadas del intercambio: OT propio, mediana/tope de nivel, dos IV
  perfectos, familias evolutivas y cláusula de especie.
- Pruebas de migración con una partida real y pruebas manuales en emulador.

Hasta completar esos puntos, el sistema se considera una prueba funcional y no
una característica cerrada para una versión estable.
