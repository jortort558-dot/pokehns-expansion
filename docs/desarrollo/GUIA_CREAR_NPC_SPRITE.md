# Guía para crear un NPC con sprite propio

Esta guía describe el flujo real de `pokehns-expansion`. Sirve para añadir un
personaje visible en el mapa, asignarle diálogos y, opcionalmente, convertirlo
en entrenador.

## 1. Decidir qué tipo de personaje se necesita

Antes de crear gráficos, elegir uno de estos casos:

1. **NPC con sprite existente**: solo hay que añadir el objeto al mapa y crear
   su script. Es la opción más sencilla.
2. **NPC con overworld nuevo**: requiere PNG, paleta, constante y registros en
   las tablas de eventos.
3. **Entrenador con overworld existente**: además del objeto y el script,
   requiere una entrada de entrenador y su equipo.
4. **Entrenador completamente nuevo**: suma al caso anterior un retrato frontal
   de combate y, si corresponde, un retrato trasero.

El **overworld** es el personaje pequeño que camina por el mapa. El **front
pic** es la ilustración grande que aparece al comenzar un combate. Son recursos
independientes.

## 2. Elegir un identificador estable

Usar un nombre ASCII en mayúsculas para las constantes y `snake_case` para los
archivos. Ejemplo ficticio:

```text
Constante: OBJ_EVENT_GFX_MARIA_HNS
Símbolo C: gObjectEventPic_Maria_hns
PNG:       maria_hns.png
Paleta:    maria_hns.pal
Script:    GoldenrodCity_EventScript_Maria
Texto:     GoldenrodCity_Text_Maria
```

No reutilizar un número o símbolo de otro personaje. Buscar primero:

```powershell
rg -n "MARIA_HNS|Maria_hns|maria_hns" include src data graphics
```

## 3. Preparar el sprite overworld

### Formato recomendado para una persona normal

Usar como plantilla un NPC HnS de `16×32`, por ejemplo:

```text
graphics/object_events/pics/people/rockets/ariana_hns.png
```

Ese archivo mide **144×32 píxeles**: nueve frames de **16×32** colocados en una
sola fila. El motor refleja horizontalmente los frames laterales cuando lo
necesita.

La forma más segura de mantener el orden correcto de las animaciones es:

1. Copiar una hoja de un NPC con el mismo tamaño y tipo de movimiento.
2. Redibujar cada frame sin cambiar su posición ni las dimensiones del lienzo.
3. Mantener los pies en la misma altura para evitar saltos al caminar.

Requisitos del PNG:

- Imagen indexada, no RGB verdadero.
- Máximo de **16 colores**, incluyendo la transparencia.
- El color del índice 0 es transparente.
- Dimensiones múltiplo de 8.
- Para el caso estándar: `144×32`, nueve frames de `16×32`.
- Sin suavizado, semitransparencias ni colores creados accidentalmente al
  escalar.

Guardar el archivo en una carpeta coherente, por ejemplo:

```text
graphics/object_events/pics/people/custom/maria_hns.png
```

No crear manualmente el `.4bpp`: la build lo genera desde el PNG. Sin embargo,
una hoja horizontal de frames necesita una regla de empaquetado por frame; la
conversión genérica no basta. Añadir en `graphics_file_rules.mk`:

```make
graphics/object_events/pics/people/custom/maria_hns.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4
```

`-mwidth 2 -mheight 4` indica que cada frame ocupa 2×4 tiles de 8 píxeles, es
decir, `16×32`. Sin esta regla, `gbagfx` recorre primero las filas de tiles de
toda la imagen de `144×32`; después, cada `overworld_frame` lee 256 bytes que
mezclan trozos de varios frames. El síntoma en juego es un NPC desordenado.

## 4. Preparar la paleta

Hay dos opciones.

### Reutilizar una paleta existente

Es apropiado cuando el sprite fue dibujado exactamente con una paleta ya
registrada. En `ObjectEventGraphicsInfo` se usará su `OBJ_EVENT_PAL_TAG_*`.

### Crear una paleta nueva

Crear:

```text
graphics/object_events/palettes/maria_hns.pal
```

El formato es JASC-PAL con 16 colores:

```text
JASC-PAL
0100
16
R G B
...
```

Reglas importantes:

- Debe haber exactamente 16 líneas de color.
- No puede quedar texto, espacios especiales o caracteres después del último
  color. `gbagfx` fallará con `Garbage after color data` si ocurre.
- El primer color corresponde a la transparencia.
- Los colores deben coincidir con los índices utilizados por el PNG.

No crear manualmente el `.gbapal`: lo genera la build.

## 5. Declarar el gráfico y la paleta

Editar:

```text
src/data/object_events/object_event_graphics.h
```

Añadir las inclusiones siguiendo los ejemplos HnS existentes:

```c
const u32 gObjectEventPic_Maria_hns[] =
    INCBIN_U32("graphics/object_events/pics/people/custom/maria_hns.4bpp");

const u16 gObjectEventPal_Maria_hns[] =
    INCBIN_U16("graphics/object_events/palettes/maria_hns.gbapal");
```

Si se reutiliza una paleta existente, solo hace falta declarar el gráfico.

## 6. Registrar una paleta nueva

Si se ha creado una paleta propia:

1. Añadir un tag único en:

   ```text
   include/constants/event_objects.h
   ```

   Ejemplo:

   ```c
   #define OBJ_EVENT_PAL_TAG_MARIA_HNS 0xXXXX
   ```

   Buscar antes el rango utilizado y no repetir valores:

   ```powershell
   rg -n "OBJ_EVENT_PAL_TAG_.*HNS" include/constants/event_objects.h
   ```

2. Registrar la relación paleta/tag en la tabla de `src/event_object_movement.c`:

   ```c
   {gObjectEventPal_Maria_hns, OBJ_EVENT_PAL_TAG_MARIA_HNS},
   ```

Si se reutiliza una paleta, omitir este paso y usar directamente su tag.

## 7. Crear la tabla de frames

Editar:

```text
src/data/object_events/object_event_pic_tables.h
```

Para una hoja estándar de nueve frames de `16×32`:

```c
static const struct SpriteFrameImage sPicTable_Maria_hns[] = {
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 0),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 1),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 2),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 3),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 4),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 5),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 6),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 7),
    overworld_frame(gObjectEventPic_Maria_hns, 2, 4, 8),
};
```

Los valores `2, 4` representan el ancho y alto en bloques de 8 píxeles. Para
sprites de otro tamaño hay que copiar un objeto existente con esas mismas
dimensiones y ajustar también OAM, tamaño, sombra y animaciones.

La tabla de C y la regla de conversión deben coincidir: `2, 4` en
`overworld_frame` exige `-mwidth 2 -mheight 4` al generar el `.4bpp`. Repetir un
único índice en la tabla no arregla un `.4bpp` mal empaquetado; solo repite el
frame corrupto.

## 8. Crear la información gráfica

Editar:

```text
src/data/object_events/object_event_graphics_info.h
```

Para el NPC estándar:

```c
const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Maria_hns = {
    TAG_NONE,
    OBJ_EVENT_PAL_TAG_MARIA_HNS,
    OBJ_EVENT_PAL_TAG_NONE,
    256,
    16,
    32,
    3,
    SHADOW_SIZE_M,
    FALSE,
    FALSE,
    TRACKS_FOOT,
    &gObjectEventBaseOam_16x32,
    sOamTables_16x32,
    sAnimTable_Standard,
    sPicTable_Maria_hns,
    gDummySpriteAffineAnimTable,
};
```

En este proyecto muchas entradas están escritas en una sola línea. Se puede
copiar el formato vecino. Los campos que normalmente se ajustan son:

- tag de paleta;
- tamaño del gráfico en bytes (`256` para un frame de `16×32` a 4 bpp);
- ancho y alto;
- prioridad/palette slot usado por el ejemplo;
- tipo de sombra y huellas;
- tablas OAM, animación y frames.

Para evitar errores, copiar la entrada de un NPC con el mismo tamaño y
comportamiento y cambiar únicamente símbolos y paleta.

## 9. Crear el ID del objeto

Editar:

```text
include/constants/event_objects.h
```

Añadir el nuevo ID antes de `NUM_OBJ_EVENT_GFX`:

```c
#define OBJ_EVENT_GFX_MARIA_HNS 548
#define NUM_OBJ_EVENT_GFX       549
```

Los números son solo ilustrativos. Hay que usar el siguiente valor libre real y
aumentar `NUM_OBJ_EVENT_GFX`. No insertar un ID en medio renumerando los demás:
los mapas guardan estas constantes y una renumeración innecesaria aumenta el
riesgo de errores.

## 10. Conectar el ID con la información gráfica

Editar:

```text
src/data/object_events/object_event_graphics_info_pointers.h
```

### Declaración externa

En la zona de declaraciones:

```c
extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Maria_hns;
```

### Entrada de la tabla

En `gObjectEventGraphicsInfoPointers`:

```c
[OBJ_EVENT_GFX_MARIA_HNS] = &gObjectEventGraphicsInfo_Maria_hns,
```

Si falta esta entrada, el ID existe pero el motor no sabe qué gráfico cargar.

## 11. Añadir el NPC al mapa

La forma recomendada es usar **Porymap**:

1. Abrir el mapa HnS correspondiente, normalmente con sufijo `_hns`.
2. Ir a la pestaña de eventos.
3. Crear un `Object Event`.
4. Elegir `OBJ_EVENT_GFX_MARIA_HNS` como sprite.
5. Configurar posición, elevación y movimiento.
6. Asignar un `local_id` libre si Porymap lo solicita.
7. Indicar la etiqueta del script.
8. Elegir una flag si el personaje debe desaparecer o aparecer según la
   historia.
9. Guardar el mapa.

La entrada resultante en `data/maps/<Mapa>/map.json` tendrá esta forma:

```json
{
  "graphics_id": "OBJ_EVENT_GFX_MARIA_HNS",
  "x": 10,
  "y": 8,
  "elevation": 0,
  "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
  "movement_range_x": 1,
  "movement_range_y": 1,
  "trainer_type": "TRAINER_TYPE_NONE",
  "trainer_sight_or_berry_tree_id": "0",
  "script": "GoldenrodCity_EventScript_Maria",
  "flag": "0"
}
```

Significado de los campos principales:

- `graphics_id`: sprite que se dibuja.
- `x`, `y`: casilla inicial.
- `elevation`: nivel de colisión; normalmente `0` o el usado por NPC vecinos.
- `movement_type`: quieto, mirando alrededor, caminando, etc.
- `movement_range_x/y`: radio permitido para movimientos errantes.
- `trainer_type`: `TRAINER_TYPE_NONE` para un NPC normal.
- `trainer_sight_or_berry_tree_id`: radio de visión si es entrenador.
- `script`: etiqueta ejecutada al hablar o al detectar al jugador.
- `flag`: controla si existe; `0` significa que siempre aparece.

Evitar editar `map.json` a mano si Porymap está disponible: un error de coma,
coordenadas o ID puede impedir cargar el mapa.

## 12. Crear el script y el diálogo

Editar:

```text
data/maps/<Mapa>_hns/scripts.inc
```

Ejemplo de NPC sencillo:

```asm
GoldenrodCity_EventScript_Maria::
    lock
    faceplayer
    msgbox GoldenrodCity_Text_Maria, MSGBOX_DEFAULT
    release
    end

GoldenrodCity_Text_Maria:
    .string "¡Hola! Este es mi primer diálogo.$"
```

Para los textos HnS:

- máximo aproximado de 34 caracteres visibles por línea;
- usar un único `\n` por página y `\l` para las líneas siguientes;
- terminar con `$`;
- conservar correctamente variables como `{PLAYER}` y `{STR_VAR_1}`;
- ejecutar `docs/utilidades/auditar_textos_gba.ps1` sobre el archivo.

## 13. Controlar aparición, desaparición y movimientos

Si el NPC forma parte de una escena, reservar una flag en el sistema de flags y
usarla en `map.json`. Comandos habituales:

```asm
setflag FLAG_HIDE_MARIA
clearflag FLAG_HIDE_MARIA
addobject LOCALID_MARIA
removeobject LOCALID_MARIA
applymovement LOCALID_MARIA, GoldenrodCity_Movement_Maria
waitmovement LOCALID_MARIA
```

El `LOCALID_MARIA` debe corresponder al objeto del mapa. No reutilizar una flag
de historia existente sin comprobar todos sus usos:

```powershell
rg -n "FLAG_HIDE_MARIA|LOCALID_MARIA" data include src
```

## 14. Convertirlo en entrenador

Un overworld nuevo no crea automáticamente un entrenador. Hay que añadir:

1. Una constante `TRAINER_*` en el sistema de constantes de entrenadores.
2. Una entrada en la fuente usada por HnS: `src/data/trainers_hns.party`.
   `src/data/trainers_hns.h` es generado por `trainerproc` durante la build y
   no debe editarse como fuente. No usar `src/data/trainers.party`: ese archivo
   pertenece a la build base y una entrada añadida allí queda vacía en HnS,
   provocando un sprite y un equipo inválidos.
3. Su nombre, clase, género, música, retrato de combate y equipo.
4. Las cadenas de encuentro, derrota y diálogo posterior.
5. Un `trainerbattle_*` en el script del mapa.

Ejemplo conceptual:

```asm
GoldenrodCity_EventScript_Maria::
    trainerbattle_single TRAINER_MARIA_HNS, \
        GoldenrodCity_Text_MariaSeen, \
        GoldenrodCity_Text_MariaBeaten
    msgbox GoldenrodCity_Text_MariaAfter, MSGBOX_AUTOCLOSE
    end
```

En el objeto del mapa hay que usar el `trainer_type` apropiado y configurar el
radio de visión. Para entrenadores que deban funcionar con el Buscapelea,
revisar también `vsseeker_rematchid` y los ejemplos de entrenadores vecinos.

## 15. Añadir un retrato de combate nuevo

Si el personaje no puede reutilizar un retrato existente, seguir la guía ya
incluida en el repositorio:

```text
docs/tutorials/how_to_trainer_front_pic.md
```

Resumen de piezas afectadas:

- PNG en `graphics/trainers/front_pics/`;
- paleta en `graphics/trainers/palettes/`;
- constante `TRAINER_PIC_FRONT_*` en `include/constants/trainers.h`;
- datos gráficos y registro en `src/data/graphics/trainers.h`;
- referencia `.trainerPic` en `src/data/trainers_hns.h`.

Los retratos también están limitados a 16 colores incluyendo transparencia.
No confundir su paleta con la del overworld: pueden ser distintas.

Para un retrato trasero existe:

```text
docs/tutorials/how_to_trainer_back_pic.md
```

Normalmente solo es necesario para personajes que combaten desde el lado del
jugador o como protagonistas.

## 16. Nombre visible y caja de nombre

Si se desea mostrar el nombre del personaje sobre el diálogo, consultar:

```text
docs/tutorials/how_to_namebox.md
```

Para entrenadores NPC puede usarse la modalidad
`OW_NAME_BOX_NPC_TRAINER`, siguiendo los ejemplos existentes. Esto es
independiente del nombre interno del script y del nombre mostrado en combate.

## 17. NPC acompañante opcional

Si debe seguir al jugador, no basta con un movimiento de mapa. Consultar:

```text
docs/tutorials/how_to_follower_npc.md
```

El objeto debe tener una flag y puede necesitar frames alternativos para correr,
nadar o montar en bici. Un NPC normal no necesita nada de esta sección.

## 18. Validación paso a paso

### Antes de compilar

```powershell
rg -n "OBJ_EVENT_GFX_MARIA_HNS|Maria_hns|maria_hns" include src data graphics
```

Comprobar que aparecen, como mínimo:

- constante gráfica;
- declaración `INCBIN` del PNG;
- tabla de frames;
- `ObjectEventGraphicsInfo`;
- declaración externa y puntero;
- objeto del mapa;
- script y textos;
- paleta y tag, si son nuevos.

Auditar el texto del mapa:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File \
  .\docs\utilidades\auditar_textos_gba.ps1 \
  .\data\maps\GoldenrodCity_hns
```

### Compilar

Desde la raíz local del proyecto:

```powershell
wsl.exe -e bash -lc 'cd /mnt/d/PROYECTOS/heartandsoul_esp/pokehns-expansion && make hns -j8'
```

### Probar en juego

Comprobar:

1. El mapa carga sin pantalla negra.
2. El sprite conserva sus colores.
3. Las cuatro direcciones y pasos usan el frame correcto.
4. No tiembla verticalmente al caminar.
5. Mira al jugador al hablar.
6. Respeta colisiones, elevación y radio de movimiento.
7. El diálogo no desborda la caja.
8. Las flags lo muestran u ocultan en el momento adecuado.
9. Si es entrenador: visión, combate, derrota y diálogo posterior funcionan.
10. Al volver a entrar en el mapa, su estado sigue siendo correcto.

## 19. Errores habituales

| Síntoma | Causa probable |
|---|---|
| `Garbage after color data` | La `.pal` tiene caracteres o líneas sobrantes |
| Colores incorrectos | PNG y `.pal` no comparten los mismos índices |
| Fondo opaco | El color transparente no ocupa el índice 0 |
| Sprite cortado o deformado | Tamaño, OAM o `overworld_frame` no coinciden |
| Frames mezclados | Orden o dimensiones de la hoja incorrectos |
| Tiles de varios frames mezclados | Falta `-mwidth`/`-mheight` en la regla específica de `graphics_file_rules.mk` |
| NPC invisible | Flag activada, ID sin puntero o evento fuera del mapa |
| Crasheo al cargar el mapa | Puntero gráfico nulo, tabla corta o JSON inválido |
| No mira al jugador | Falta `faceplayer` o el movimiento lo impide |
| No inicia combate | Entrada de entrenador, script o `trainer_type` incorrectos |
| Porymap no muestra el sprite | Falta recompilar/actualizar constantes o reiniciar Porymap |

## 20. Lista de control final

- [ ] Nombre interno elegido y sin colisiones.
- [ ] PNG indexado, dimensiones correctas y máximo 16 colores.
- [ ] Siluetas con escala coherente entre direcciones; comparar la caja ocupada
      por cada frame y mantener los pies en la misma fila.
- [ ] Regla `.4bpp` con metatile igual al frame (`-mwidth 2 -mheight 4` para `16×32`).
- [ ] Paleta válida o paleta existente elegida.
- [ ] `object_event_graphics.h` actualizado.
- [ ] `object_event_pic_tables.h` actualizado.
- [ ] `object_event_graphics_info.h` actualizado.
- [ ] `event_objects.h` actualizado sin renumerar IDs previos.
- [ ] `object_event_graphics_info_pointers.h` actualizado.
- [ ] Paleta registrada en `event_object_movement.c`, si es nueva.
- [ ] Objeto añadido al mapa mediante Porymap.
- [ ] Script, diálogo y flags creados.
- [ ] Datos de entrenador y retrato añadidos, si corresponde.
- [ ] Textos auditados.
- [ ] Build HnS correcta.
- [ ] Prueba visual y funcional realizada en juego.

## Referencia rápida del proyecto

Para un NPC HnS estándar puede usarse Ariana como ejemplo completo:

```text
OBJ_EVENT_GFX_ARIANA_HNS
graphics/object_events/pics/people/rockets/ariana_hns.png
graphics/object_events/palettes/rocket_3_hns.pal
gObjectEventPic_Ariana_hns
sPicTable_Ariana_hns
gObjectEventGraphicsInfo_Ariana_hns
```

Buscar esas referencias muestra todos los puntos que debe conectar un personaje
nuevo.
