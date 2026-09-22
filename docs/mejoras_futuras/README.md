# Mejoras futuras de Heart & Soul

Registro de mejoras futuras, pruebas e implementaciones añadidas al proyecto.

## Ficha Gimnasio

El diseño completo del recurso, sus tres usos, persistencia, migración y pruebas está en [Sistema de Ficha Gimnasio](sistema_ficha_gimnasio.md).

### Estado

Diseño cerrado y pendiente de implementación.

## REV. ÚNICO (propuesta sustituida)

### Objetivo

Esta propuesta inicial queda conservada como antecedente. Ha sido sustituida por el diseño de Ficha Gimnasio enlazado arriba.

### Recompensas

- Entregar un uso al derrotar a cada líder de gimnasio.
- Permitir acumular los usos obtenidos.
- Impedir que hablar de nuevo con el líder duplique la recompensa.

### Funcionamiento actual del Nuzlocke

- Un Pokémon muerto conservado en el PC se identifica porque tiene 0 PS.
- Los Centros Pokémon no curan esos Pokémon.
- El sistema de almacenamiento impide retirarlos del PC.
- Con borrado permanente el Pokémon se elimina y ya no puede recuperarse.

### Propuesta

- Mostrar únicamente Pokémon con 0 PS almacenados en el PC.
- Restaurar los PS del Pokémon elegido y consumir un uso.
- No permitir su uso sobre debilitados normales fuera del Nuzlocke.
- Decidir la compatibilidad con el borrado permanente.
- Pendiente decidir PS, PP, estados y lugar de uso.

## Indicador de captura por ruta

- Mostrar en la interfaz si ya se ha realizado la captura permitida en la zona actual.
- Determinar la ubicación y formato del indicador.
- Reutilizar el registro de encuentros por zona que ya mantiene el sistema Nuzlocke.

## PokéViales

### Estado actual

Implementado en la versión **0.11.0** y pulido en la **0.11.2**.

### Diseño implementado

- Objeto clave reutilizable (`ITEM_POKE_VIAL`) en el bolsillo de objetos clave.
- Cura los PS y problemas de estado de todo el equipo que esté con vida.
- **Regla Nuzlocke**: No revive ni cura a los Pokémon caídos (con 0 PS).
- Comienza con 1 carga máxima al recibirlo de Mamá al inicio de la aventura.
- Obtiene 1 carga máxima adicional cada 2 medallas de Johto (hasta 5 cargas con las 8 medallas).
- Se recarga automáticamente al curar en cualquier Centro Pokémon.
- Las partidas anteriores pueden obtenerlo hablando con Mamá si todavía no lo tienen.
- Notifica las cargas restantes (ej: `Cargas: 1/2`) y previene su uso si el equipo ya está sano o si no quedan cargas.
- Se puede registrar para acceso rápido con el botón Select y utilizar desde la mochila.

## Megaevoluciones

La especificación completa del evento del rival, la recompensa y las Megas de jefes está en [Sistema de Megaevoluciones y jefes](sistema_megaevoluciones_jefes.md).

### Estado actual

Implementadas como prueba jugable en la versión **0.12.0**, optimizadas en la **0.12.1** y corregidas en la **0.13.1**.

### Implementación técnica

- Están activadas las Megaevoluciones estándar de pokeemerald-expansion.
- Las nuevas Megaevoluciones de Leyendas Pokémon: Z-A permanecen desactivadas.
- El jugador necesita el objeto clave Mega-Aro en la mochila.
- El Pokémon debe llevar equipada su megapiedra correspondiente.
- Solo se permite una Megaevolución por entrenador y combate.
- No puede activarse si ese Pokémon ya tiene otra mecánica especial activa.
- La forma Mega se revierte al terminar el combate o cuando corresponda restaurar la forma base.
- Las estadísticas, tipos y habilidades usados son los definidos por las formas Mega de la expansión.

### Controles

- En la pantalla de movimientos se pulsa **START** para marcar o cancelar la Megaevolución.
- Después se elige el movimiento con normalidad y la transformación ocurre antes de atacar.
- La descripción de movimientos se consulta con **START** y la Mega se activa con **SELECT**.
- El icono de la mecánica indica visualmente si la Megaevolución está seleccionada.

### Prueba en Ciudad Cerezo

- Hay un investigador temporal en el primer Centro Pokémon, el de Ciudad Cerezo.
- Entrega un Mega-Aro y un Pokémon aleatorio de nivel 15 entre 42 parejas Mega no legendarias.
- Cada Pokémon lleva siempre equipada su megapiedra correspondiente.
- Si el equipo está lleno, el Pokémon se envía al PC.
- El kit se entrega una sola vez por partida mediante FLAG_RECEIVED_MEGA_TEST_KIT.
- Funciona con partidas ya comenzadas; no requiere iniciar una partida nueva.

### Objetos traducidos para la prueba

- ITEM_MEGA_RING: Mega-Aro.
- ITEM_BEEDRILLITE: Beedrillita.
- Ambos incluyen descripciones en español.

### Gritos y capacidad de ROM

- Se han eliminado los gritos exclusivos de las formas Mega.
- Las 96 formas afectadas reutilizan el grito de su especie base con el tratamiento de tono del motor.
- Con gritos Mega exclusivos, la ROM ocupaba el **98,82 %**.
- Sin esos gritos, la ROM ocupa el **95,18 %**.
- La optimización recupera aproximadamente **1,17 MiB** y deja alrededor de **1,54 MiB** libres.
- Antes de activar las Megas la ROM ocupaba el **94,56 %**, por lo que la mecánica optimizada añade aproximadamente 203 KiB.

### Pendiente para versión definitiva

- Decidir en qué punto de la historia se obtiene el Mega-Aro.
- Diseñar la distribución de todas las megapiedras.
- Retirar o reconvertir al investigador temporal tras finalizar las pruebas.
- Traducir los nombres y descripciones del resto de megapiedras.
- Probar combates dobles, entrenadores enemigos y el límite de una Mega por combate.
