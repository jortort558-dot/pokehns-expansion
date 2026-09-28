# INFORME TÉCNICO Y GUÍA DE RELEVO: POKÉMON HEART & SOUL (ESPAÑOL)

> **Aviso (22/09/2026): documento histórico.** El proyecto se ha trasladado del NAS a
> `D:\PROYECTOS\heartandsoul_esp`. Las rutas `Y:\` y el flujo de doble repositorio
> NAS/WSL descritos aquí no deben asumirse vigentes. Para nuevas sesiones, empezar por
> `AGENTS.md` y consultar `docs/desarrollo/GUIA_IA_EFICIENTE.md`. Usar este informe solo
> como contexto funcional y contrastar estados con el árbol y los documentos actuales.

Este informe está diseñado específicamente para que otra IA o desarrollador pueda entender de inmediato el funcionamiento, la arquitectura, el estado exacto del código y las tareas pendientes del proyecto.

---

## 1. Visión General del Proyecto
- **Nombre**: Pokémon Heart & Soul (`pokehns-expansion`).
- **Base Técnica**: Descompilación completa de Pokémon Emerald en C y Ensamblador ARM7TDMI (`rh-hideout pokeemerald-expansion`).
- **Objetivo**: Localización profesional y exhaustiva al castellano (terminología oficial española), compatibilidad con generaciones 1 a 9, corrección de desbordamientos de interfaz de usuario (UI), soporte para modo Nuzlocke y expansión de mecánicas modernas.
- **Rama Git de trabajo**: `traduccion-es` (tanto en Windows como en WSL).

---

## 2. Arquitectura de Entornos y Flujo de Trabajo (CRÍTICO)

El proyecto opera con dos repositorios/árboles de trabajo separados que deben mantenerse estrictamente alineados:

```
+-----------------------------------------------------------------------------------------+
|                                    ENTORNO WINDOWS                                      |
|  Ruta base: Y:\heartandsoul_esp                                                         |
|  - Repositorio Git 1: Y:\heartandsoul_esp\pokehns-expansion (rama: traduccion-es)       |
|  - Edición en IDE (VS Code / Antigravity), análisis y documentación                     |
|  - Script de sincronización: Y:\heartandsoul_esp\sync_latest.ps1                        |
|  - Repositorio de entregables finales: releases\pokehns-<version>-es.gba                |
|  - ROM operativa de pruebas: Y:\heartandsoul_esp\pokehns_fase1.gba                      |
|  - Documentos de control: TRADUCCION_HNS.md, bugs.md, mejoras.md                        |
+-----------------------------------------------------------------------------------------+
                                             |   ^
                             sync_latest.ps1 |   | Lectura / Copia UNC
                             (PowerShell)    v   | (\\wsl$\Ubuntu\home\falan\...)
+-----------------------------------------------------------------------------------------+
|                                  ENTORNO WSL (LINUX)                                    |
|  Ruta: /home/falan/pokehns-expansion                                                    |
|  - Repositorio Git 2: /home/falan/pokehns-expansion (rama: traduccion-es)               |
|  - Cadena de compilación ARM bare-metal: arm-none-eabi-gcc, make, tools/preproc        |
|  - Salida compilada: /home/falan/pokehns-expansion/pokehns.gba                          |
+-----------------------------------------------------------------------------------------+
```

### ¿Por qué existen dos repositorios?
- **El compilador ARM (`arm-none-eabi-gcc`) solo funciona en WSL (Linux)**: La compilación de `pokeemerald` en Windows nativo es inestable y lenta.
- **El entorno de desarrollo y visualización de archivos está en Windows (`Y:\`)**: Para no trabajar directamente a través del puente de red de WSL que ralentiza las herramientas de Windows.
- Por tanto, las modificaciones que se compilan y validan en WSL deben transferirse a Windows mediante el script de sincronización, y ambos repositorios de Git deben comitearse.

---

### Paso a paso: Ciclo de trabajo completo para crear una build / release

Cuando se termina de traducir un bloque o corregir un lote de bugs, la IA o desarrollador DEBE seguir este protocolo en orden:

#### Paso 1: Modificar los archivos de código o scripts
Los archivos se editan en WSL (`/home/falan/pokehns-expansion/...`) o mediante acceso directo UNC `\\wsl$\Ubuntu\home\falan\pokehns-expansion\...`.

#### Paso 2: Compilar en WSL
Ejecutar la compilación desde PowerShell invocando WSL:
```powershell
wsl -e bash -c "cd /home/falan/pokehns-expansion && make -j8"
```
*Si hay un error de sintaxis en algún `.string` (como saltos de línea sin escapar o comillas abiertas), `tools/preproc` o `gcc` indicarán la línea exacta.*

#### Paso 3: Registrar nuevos archivos en `sync_latest.ps1`
Si durante el trabajo se han tocado archivos nuevos (por ejemplo nuevos mapas en `data/maps/.../scripts.inc` o archivos de cabecera `.h`), **hay que añadirlos al array `$files` en [sync_latest.ps1](file:///y:/heartandsoul_esp/sync_latest.ps1)**.

#### Paso 4: Definir la versión de la ROM en `sync_latest.ps1`
En las líneas finales de `sync_latest.ps1`, ajustar el nombre de la release siguiendo el estándar del proyecto:
```powershell
# Formato estándar de versión:
# releases/pokehns-<semver>-<fecha>-<hito>-es.gba
Copy-Item "\\wsl$\Ubuntu\home\falan\pokehns-expansion\pokehns.gba" "Y:\heartandsoul_esp\pokehns_fase1.gba" -Force
Copy-Item "\\wsl$\Ubuntu\home\falan\pokehns-expansion\pokehns.gba" "Y:\heartandsoul_esp\releases\pokehns-0.6.3-20260920-items-es.gba" -Force
```

#### Paso 5: Ejecutar la sincronización hacia Windows
Lanzar el script desde PowerShell:
```powershell
powershell -ExecutionPolicy Bypass -File .\sync_latest.ps1
```
Esto copia todos los archivos modificados desde WSL hacia `Y:\heartandsoul_esp\pokehns-expansion\` y genera tanto `pokehns_fase1.gba` como la nueva ROM en `releases/`.

#### Paso 6: Commit y Push en ambos repositorios Git
Para evitar discrepancias entre lo que tiene WSL y lo que tiene Windows:
1. **En el repositorio de WSL (Linux)**:
   ```powershell
   wsl -e bash -c "cd /home/falan/pokehns-expansion && git add -A && git commit -m 'feat: descripcion del cambio' && git push origin traduccion-es"
   ```
2. **En el repositorio de Windows**:
   ```powershell
   git -C Y:\heartandsoul_esp\pokehns-expansion add -A
   git -C Y:\heartandsoul_esp\pokehns-expansion commit -m "feat: sincronizar traduccion con WSL"
   ```

Con este procedimiento, ambos repositorios quedan con `git status` limpio y la build queda disponible inmediatamente para el usuario.

---

## 3. Estado Actual de la Traducción

El seguimiento detallado se gestiona en [TRADUCCION_HNS.md](file:///y:/heartandsoul_esp/TRADUCCION_HNS.md):

| Bloque | Rutas y Contenido Principal | Estado |
| :--- | :--- | :---: |
| **Bloque 1** | Pueblo Primavera, Lab Elm, Ruta 29, Ruta 46, Casa del Jugador, Tutoriales | **100% Traducido** |
| **Bloque 2** | Cerezo, Rutas 30-32, Cueva Oscura, Malva, Torre Bellsprout, Ruinas Alfa, Azalea, Pozo Slowpoke | **100% Traducido y Auditado** |
| **Bloque 3** | Encinar, Ruta 34, Guardería, Trigal, Gimnasio Blanca, Subterráneo, Rutas 35-37, Parque Nacional, Iris, Gimnasio Morti, Torre Quemada | **100% Traducido** |
| **Bloque 4** | Rutas 38-39, Granja Mumu, Olivo, Gimnasio Yasmina, Faro de Amphy, Rutas 40-41, Orquídea, Gimnasio Aníbal | **100% Traducido** |
| **Bloque 5** | Ruta 42, Caoba, Monte Mortero, Ruta 43, Lago de la Furia (Gyarados Rojo y Lance), Guarida Rocket Caoba, Gimnasio Fredo, Torre Radio de Trigal | **100% Traducido** |
| **Bloque 6** | Ruta 44, Ruta Helada, Endrino, Gimnasio Débora, Guarida Dragón, Invocación Lugia/Ho-Oh, Rutas 45-27, Calle Victoria y Liga Pokémon | **Pendiente de Inicio** |
| **Postgame** | Barco S.S. Aqua, 8 Medallas de Kanto, Central Energía, Monte Plateado y Combate contra Rojo | **Pendiente** |

---

## 4. Reglas Estrictas del Motor de Texto GBA

> [!TIP]
> Puedes consultar la guía exhaustiva y detallada con ejemplos prácticos en [docs/desarrollo/consejos_motor_texto_gba.md](file:///y:/heartandsoul_esp/docs/desarrollo/consejos_motor_texto_gba.md).

Cualquier edición de scripts (`.inc`) o cadenas C (`.c`) debe cumplir estas reglas del motor gráfico de Game Boy Advance:

1. **Límite visual de la caja de diálogo: 34 a 35 caracteres por línea**:
   - Superar los 35 caracteres visuales provoca corte o desbordamiento en pantalla.
   - En scripts `.inc`: la primera línea de un párrafo lleva `\n`, las subsecuentes llevan `\l`. Los cambios de caja que esperan pulsación de botón llevan `\p`.
   - Ejemplo de diálogo bien formateado:
     ```assembly
     NombreTexto_Text:
         .string "Primera línea hasta 34 carac.\n"
         .string "Segunda línea del mismo cuadro\l"
         .string "tercera línea con scroll.\p"
         .string "Nuevo párrafo que espera botón\n"
         .string "y limpia la caja de diálogo.$"
     ```
2. **Cero saltos de línea literales en strings `.inc`**:
   - Nunca dejar un salto de línea de archivo dentro de un `.string` sin cerrar comillas. El preprocesador (`tools/preproc`) arrojará el error fatal: `unexpected character U+A in UTF-8 string`.
3. **Variables y macros dinámicas**:
   - Variables como `{PLAYER}`, `{STR_VAR_1}`, `{B_BUFF1}`, `{B_TRAINER1_NAME_WITH_CLASS}` ocupan espacio dinámico en ejecución. Calcular siempre un margen preventivo de 4 a 6 caracteres visuales.
4. **Constantes y strings en código C**:
   - Para textos C (como `src/strings.c`, `src/battle_message.c`), usar la macro `_("Texto aquí")` o `COMPOUND_STRING("Texto aquí")` según el estándar del archivo específico.
   - No utilizar caracteres UTF-8 especiales no soportados por la fuente GBA sin verificar (`á`, `é`, `í`, `ó`, `ú`, `ñ`, `¿`, `¡` sí están soportados en `pokeemerald-expansion`).

---

## 5. Mapa de Arquitectura del Código Fuente (Dónde tocar cada cosa)

Para no perder tiempo buscando en los miles de archivos del motor:

| Componente / Característica | Archivos Clave | Qué contiene / Qué editar |
| :--- | :--- | :--- |
| **Scripts y Diálogos de Mapas** | `data/maps/<NombreMapa>_hns/scripts.inc` | Todos los NPCs, eventos, líderes de gimnasio e historia de Johto (los mapas propios de HnS llevan sufijo `_hns`). |
| **Puestos Fronterizos (Gates)** | `data/maps/Gate_*_hns/scripts.inc` | Puestos entre rutas y ciudades. |
| **Textos del Sistema / Menús** | `src/strings.c` | Cadenas genéricas de interfaz, selección Chico/Chica, menús de guardado, reloj y opciones. |
| **Menú y Bolsa de Objetos** | `src/item_menu.c`, `data/text/item_descriptions.inc` | Interfaz de la mochila, pestañas de bolsillos (TM/MT, Bayas, etc.). |
| **Definición y Nombres de Ítems** | `src/data/items.h`, `include/constants/items.h` | Tabla de objetos con `.name`, `.description`, `.pocket`, etc. |
| **Combates y Mensajes de Batalla** | `src/battle_message.c`, `data/battle_scripts_*.s` | Mensajes de "repartir exp", cambio de Pokémon rival, mensajes de efectividad ("1 golpe", "Derrotaste a..."). |
| **Entrenadores y Clases** | `src/data/trainers_hns.h`, `src/data/trainer_parties.h` | Nombres y clases de entrenadores propios de Heart & Soul. |
| **Muebles, PCs y Bayas** | `data/text/check_furniture.inc`, `data/text/pc.inc`, `data/scripts/berry_tree.inc` | Estanterías, floreros, PCs de centros pokémon y recolección de bayas. |
| **Pokégear** | `src/pokegear.c`, `src/data/pokegear/*.h` | Mapa de la región, teléfono de entrenadores y radio. |
| **Subsistema Nuzlocke** | `src/nuzlocke.c`, `include/nuzlocke.h`, `src/challenge_menu.c` | Lógica de 1 Pokémon por ruta (`sNuzlockeLUT`), cláusula de especies, muerte (`NuzlockeDeleteFaintedPartyPokemon`). |
| **Subsistema Randomizer** | `src/randomizer.c`, `include/randomizer.h` | Tablas de iniciales, encuentros salvajes, pool de movimientos (1 a 847) y habilidades permitidas. |

---

## 6. Tareas Pendientes Inmediatas

### A. Correcciones de Sistema y UI (Reportadas en [bugs.md](file:///y:/heartandsoul_esp/bugs.md)):
1. **Nombres de Objetos Modernos (`src/data/items.h`)**:
   - Traducir sistemáticamente ítems de Generación 5 a 9 que siguen en inglés (ejemplos identificados en `image-1.png`):
     - `GIMMIGHOUL COIN` $\rightarrow$ Moneda Gimmighoul
     - `ELECTRIC SEED` $\rightarrow$ Semilla Electro
     - `GRASSY SEED` $\rightarrow$ Semilla Hierba
     - `PSYCHIC SEED` $\rightarrow$ Semilla Psique
     - `MISTY SEED` $\rightarrow$ Semilla Bruma
     - Plumas (`MUSCLE FEATHER`, `GENIUS FEATHER`, etc.), dulces y objetos evolutivos modernos.
2. **Unificación "TM" $\rightarrow$ "MT"**:
   - Reemplazar "TM" por "MT" en menús de bolsa (`src/item_menu.c`), diálogos de dependientes y descripciones.
3. **Pokégear**:
   - Traducir la interfaz, nombres de ciudades en el mapa del Pokegear, opciones del teléfono y nombres de canales de radio (`src/pokegear.c`).
4. **Entrenadores y Combate**:
   - Traducir clases y nombres de entrenadores en `src/data/trainers_hns.h` y mensajes restantes en `src/battle_message.c` ("1 hit KO", "You defeated...", etc.).

### B. Funcionalidad de Juego (Reportada en [mejoras.md](file:///y:/heartandsoul_esp/mejoras.md)):
- **Objeto REV. ÚNICO**:
  - Implementar un objeto medicinal especial que permita revivir a un Pokémon debilitado en modo Nuzlocke.
  - En `src/nuzlocke.c` (`NuzlockeDeleteFaintedPartyPokemon`) los Pokémon muertos se transfieren al PC (cementerio) o se purgan según la configuración. Se debe conectar con el uso de este objeto para permitir su rescate o evitar su purga si se usa a tiempo.

### C. Bloque 6 de la Historia:
- Iniciar la traducción del Bloque 6 según la lista de mapas en `TRADUCCION_HNS.md`:
  - Ruta 44, Ruta Helada (Ice Path pisos 1 a B3F).
  - Ciudad Endrino, Tienda, Centro Pokémon y Gimnasio de Débora.
  - Guarida Dragón y evento del Maestro Dragón.
  - Invocación de las aves legendarias (Lugia / Ho-Oh).
  - Rutas 45, 46 (tramo sur), Ruta 27, Ruta 26, Calle Victoria y la Liga Pokémon (Meseta Añil).

---

## 7. Historial de Releases Recientes

Todas las ROMs compiladas y operativas se guardan en la carpeta `releases/`:
- `releases/pokehns-0.5.0-20260920-bloque4-es.gba`: Finalización del Bloque 4.
- `releases/pokehns-0.6.0-20260920-bloque5-es.gba`: Finalización del Bloque 5.
- `releases/pokehns-0.6.1-20260920-bugfix1-es.gba`: Corrección de BOY/GIRL, muebles, PC, bayas, combates y textos de Malva.
- `releases/pokehns-0.6.2-20260920-bugfix2-es.gba`: Traducción completa de Ruinas Alfa, tiendas, casas de Malva y Azalea, auditoría estricta de 35 caracteres y sin textos cortados.
- `pokehns_fase1.gba`: Copia en la raíz de la última versión operativa generada.
