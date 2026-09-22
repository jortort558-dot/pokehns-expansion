# Sistema de Megaevoluciones y jefes

## 1. Resumen ejecutivo

Esta propuesta convierte la prueba técnica de Megaevoluciones en una mecánica integrada en la historia de Heart & Soul.

El jugador descubrirá la mecánica mediante un combate nuevo contra el rival en el Lago de la Furia, justo antes del Gyarados rojo. El rival usará la primera Mega vista durante la aventura. Al derrotarlo, entregará un Mega-Aro sobrante y un Pokémon aleatorio capaz de megaevolucionar con su megapiedra equipada.

Desde ese momento, los jefes principales de la aventura tendrán una Mega como último miembro del equipo. En Randomlocke, la Mega del rival y las de los jefes serán selecciones aleatorias válidas y estables para esa partida.

## 2. Objetivos

- Introducir la Megaevolución mediante un acontecimiento narrativo.
- Hacer que el jugador vea primero la mecánica utilizada en su contra.
- Entregar una pareja válida de Pokémon y megapiedra.
- Admitir todas las Megas no legendarias disponibles y estables.
- Garantizar una Mega final a líderes, Alto Mando, Campeón y jefes de trama.
- Mantener resultados aleatorios, pero impedir que cambien al reiniciar.
- Funcionar en partida normal, Nuzlocke y Randomlocke.
- Mantener compatibilidad con partidas de las pruebas `0.12.0` y `0.12.1`.

## 3. Base técnica disponible

La prueba actual ya dispone de:

- Motor de Megaevolución de pokeemerald-expansion.
- Mega-Aro y megapiedras.
- Activación con `START` desde la pantalla de movimientos.
- Descripción de movimientos trasladada a `SELECT`.
- Una Mega como máximo por entrenador y combate.
- Formas, estadísticas, tipos, habilidades y animaciones Mega.
- Gritos optimizados para conservar espacio en la ROM.
- Un investigador temporal en el Centro Pokémon de Ciudad Cerezo.

La versión definitiva deberá retirar o reconvertir al investigador cuando el evento del Lago esté terminado.

## 4. Evento del Lago de la Furia

### 4.1. Ubicación

El rival se situará en la orilla, delante del acceso al Gyarados rojo. Bloqueará temporalmente el paso para asegurar que el combate ocurra antes del encuentro variocolor.

### 4.2. Progresión

La ruta natural pasa por Ciudad Olivo antes del Lago, pero el juego no obliga actualmente a derrotar a Yasmina para llegar hasta allí.

Estructura recomendada:

- Sin la medalla de Olivo, el rival bloquea el paso y pospone el combate.
- Tras derrotar a Yasmina, se activa la escena completa.
- Al superar el evento, el rival desaparece y permite acceder al Gyarados rojo.
- El evento será único y quedará registrado con una bandera propia.

Así la Mega se desbloquea en un punto controlado de la aventura.

### 4.3. Secuencia narrativa

1. El jugador se aproxima al Gyarados rojo.
2. El rival lo intercepta y comenta que también investiga la alteración del lago.
3. Presume de haber conseguido una tecnología de combate desconocida para el jugador.
4. Comienza un combate obligatorio.
5. Su último Pokémon megaevoluciona.
6. Tras perder, resta importancia a la derrota.
7. Explica que consiguió dos Mega-Aros o dos equipos y que no quiere cargar con el sobrante.
8. Entrega el Mega-Aro.
9. Entrega un Pokémon aleatorio no legendario con su megapiedra equipada.
10. Abandona la zona y deja libre el acceso al Gyarados.

### 4.4. Tono

El rival no debe parecer repentinamente amistoso. Justificará la recompensa como desprecio por un objeto repetido.

Texto orientativo:

> No te emociones. No te lo doy por haber ganado. Conseguí dos y no pienso cargar con basura repetida. Si vas a seguir metiéndote en medio, al menos aprende a usarlo.

El texto definitivo deberá adaptarse al límite visual del motor.

## 5. Mega del rival

### 5.1. Partida normal

El último Pokémon será Gengar con Gengarita.

Esto mantiene continuidad con su Haunter, encaja con su estética y presenta una transformación reconocible. El equipo contendrá a Gengar en forma base; Mega-Gengar aparecerá únicamente al activar la mecánica durante el combate.

### 5.2. Randomlocke

Cuando esté activa la aleatorización de entrenadores:

- El último Pokémon se sustituirá por una especie base capaz de megaevolucionar.
- Llevará siempre la megapiedra correcta.
- Nunca será legendario ni mítico.
- La sustitución se realizará después de la aleatorización ordinaria.
- La elección será determinista para que reiniciar no cambie el resultado.

## 6. Recompensa del jugador

### 6.1. Contenido

- Un Mega-Aro como objeto clave.
- Un Pokémon base aleatorio capaz de megaevolucionar.
- Su megapiedra correspondiente ya equipada.

### 6.2. Pool permitido

El pool incluirá cualquier Mega ordinaria no legendaria que esté habilitada y verificada en la ROM:

- Iniciales con Mega.
- Beedrill, Pidgeot, Alakazam, Slowbro, Gengar y Kangaskhan.
- Pinsir, Gyarados, Aerodactyl y Ampharos.
- Scizor, Heracross, Houndoom y Tyranitar.
- Sceptile, Blaziken, Swampert, Gardevoir y Gallade.
- Sableye, Mawile, Aggron, Medicham, Manectric y Sharpedo.
- Camerupt, Altaria, Banette, Absol, Glalie y Salamence.
- Metagross, Lopunny, Garchomp, Lucario y Abomasnow.
- El resto de Megas normales disponibles en la expansión.

### 6.3. Exclusiones

- Mewtwo.
- Latias y Latios.
- Rayquaza.
- Diancie.
- Cualquier otro legendario o mítico.
- Regresiones Primigenias, Ultra Burst, Gigamax y Teracristalización.
- Formas nuevas todavía no verificadas en esta ROM.

### 6.4. Especies con dos Megas

Para no favorecer a especies con varias formas:

1. Se elige primero la especie base de manera uniforme.
2. Si tiene varias Megas, se elige después una de sus piedras.

Charizard tendrá así la misma probabilidad base que Blastoise y solo después se decidirá entre Charizardita X o Y.

### 6.5. Selección estable

La recompensa se calculará con una semilla derivada del identificador del jugador y un identificador fijo del evento. Reiniciar antes de recibirla no permitirá repetir el sorteo.

### 6.6. Equipo y PC llenos

- Con espacio, el Pokémon entra en el equipo.
- Con el equipo lleno, se envía al PC.
- Si tampoco cabe en el PC, la recompensa queda pendiente.
- El jugador podrá reclamarla después.
- El Mega-Aro no se duplicará aunque la entrega del Pokémon quede pendiente.

### 6.7. Nuzlocke

Recomendación definitiva:

- El Pokémon cuenta como regalo.
- No consume la captura del Lago de la Furia.
- No impide capturar al Gyarados rojo.
- Después de recibirlo se somete a las reglas Nuzlocke normales.
- Si existe una opción que prohíba regalos, se respetará o se documentará expresamente esta excepción.

## 7. Megas de jefes posteriores

### 7.1. Desbloqueo

El sistema se activará al completar el evento mediante una bandera específica, por ejemplo `FLAG_MEGA_SYSTEM_UNLOCKED`. Conviene separarla de la posesión física del Mega-Aro para controlar historia, migraciones y depuración.

### 7.2. Entrenadores afectados

- Líderes de Johto y Kanto.
- Alto Mando.
- Campeón.
- Rival en encuentros posteriores.
- Administradores del Team Rocket.
- Jefe Rocket de la Torre Radio.
- Jefes de instalaciones o zonas ligados a la historia.
- Jefes especiales añadidos a una lista explícita.

### 7.3. Identificación

Se combinarán:

- Clases de entrenador: líder, líder de Kanto, Alto Mando, Campeón, rival y administrador Rocket.
- Lista explícita de identificadores para jefes de zona que no usen esas clases.

No se aplicará a entrenadores normales por compartir accidentalmente alguna característica.

### 7.4. Regla del último Pokémon

- El último hueco será la Mega garantizada.
- Mantendrá el nivel previsto para el último Pokémon original.
- Especie y piedra se sustituirán conjuntamente.
- Se generarán movimientos legales para la nueva especie.
- Se conservará el escalado de IV, EV y dificultad.
- La IA activará la Mega al utilizar ese Pokémon.
- Solo habrá una Mega por entrenador y combate.

### 7.5. Normal y Randomlocke

Después del desbloqueo, los jefes tendrán una Mega aleatoria tanto en partida normal como en Randomlocke.

La excepción será el primer combate del Lago:

- Normal: Mega-Gengar fijo.
- Randomlocke: Mega aleatoria.

En Randomlocke, la Mega garantizada se aplicará después del randomizador ordinario para que la especie conserve la piedra correcta.

### 7.6. Determinismo

Cada jefe recibirá una Mega calculada con:

- Semilla de la partida.
- Identificador único del entrenador.
- Identificador del combate o revancha.

La Mega podrá variar entre partidas, pero será siempre la misma al repetir ese combate. Una revancha podrá cambiar si utiliza otro identificador de entrenador.

## 8. Arquitectura técnica propuesta

### 8.1. Tabla central

Se creará una tabla única de parejas válidas:

```c
struct MegaPair
{
    u16 species;
    u16 stone;
};
```

Solo contendrá especies base no legendarias y piedras compatibles. Las especies con dos Megas se agruparán para evitar probabilidades duplicadas.

### 8.2. Responsabilidades

La implementación se dividirá en funciones equivalentes a:

```c
bool32 IsMegaBossTrainer(u16 trainerId, u8 trainerClass);
bool32 ShouldForceBossMega(u16 trainerId, u8 trainerClass);
const struct MegaPair *GetDeterministicMegaPair(u32 seed, u16 trainerId);
void ApplyMegaPairToTrainerMon(struct Pokemon *mon, const struct MegaPair *pair);
void GiveLakeOfRageMegaReward(void);
```

Los nombres finales seguirán el estilo del proyecto.

### 8.3. Orden de creación del equipo enemigo

1. Cargar el equipo original.
2. Aplicar el randomizador ordinario.
3. Comprobar el desbloqueo de las Megas.
4. Determinar si el entrenador es un jefe.
5. Seleccionar una pareja Mega para el último hueco.
6. Crear la especie base.
7. Equipar la piedra correspondiente.
8. Generar movimientos y estadísticas coherentes.

Este orden evita que el randomizador cambie la especie después de asignar la piedra.

### 8.4. IA y mecánicas

Debe verificarse que:

- La IA active la Mega.
- No combine Mega con otra mecánica incompatible.
- No aparezcan dos Megas del mismo entrenador en dobles.
- En combates con dos entrenadores se respete el límite individual.
- La forma vuelva a la normalidad al terminar.

## 9. Compatibilidad con partidas existentes

### 9.1. Versiones de prueba

Quienes jugaron `0.12.0` o `0.12.1` pueden tener ya el Mega-Aro y el Beedrill de prueba.

Migración recomendada:

- Si ya poseen el Mega-Aro, activar la nueva bandera al entrar en el Lago o hablar con el rival.
- No entregar un segundo Mega-Aro.
- Permitir completar la escena narrativa.
- Entregar el Pokémon aleatorio definitivo, salvo que se decida que Beedrill cuenta como recompensa.
- Recomendación: conservar Beedrill y entregar también la recompensa definitiva, al tratarse de versiones de prueba.

### 9.2. Lago ya superado

- Si el Gyarados ya fue derrotado pero el sistema no está desbloqueado, el rival aparecerá en otra posición de la orilla.
- La escena seguirá disponible hasta completarse.
- El Gyarados no reaparecerá ni se duplicará.

## 10. Equilibrio

- La Mega conservará el nivel del último Pokémon original.
- No recibirá además un aumento de nivel automático.
- Los movimientos deberán ser legales y útiles.
- El pool puede incluir Tyranitar, Salamence, Metagross o Garchomp porque el desbloqueo ocurre avanzada la aventura.
- Si las pruebas detectan picos excesivos, el pool podrá dividirse por tramos de medallas.
- Objetos curativos e IA seguirán dependiendo de la dificultad configurada.

## 11. Fases de implementación

### Fase 1. Consolidar el motor

- Confirmar Megas estándar, controles, textos y espacio de ROM.
- Mantener `SELECT` para Mega y `START` para descripciones.

### Fase 2. Crear el pool

- Construir la tabla especie-piedra.
- Excluir legendarios y míticos.
- Resolver especies con dos Megas.
- Implementar selección determinista.

### Fase 3. Crear el evento

- Añadir rival y bloqueo en el Lago.
- Crear su equipo específico.
- Configurar Mega-Gengar normal y Mega aleatoria en Randomlocke.
- Añadir diálogos, movimientos y banderas.

### Fase 4. Entregar la recompensa

- Entregar Mega-Aro sin duplicados.
- Crear el Pokémon con piedra equipada.
- Gestionar equipo lleno, PC lleno y Nuzlocke.

### Fase 5. Aplicar Megas a jefes

- Crear detector central de jefes.
- Integrarlo en la creación de equipos.
- Añadir excepciones de jefes de zona.
- Verificar Randomlocke, dobles y revanchas.

### Fase 6. Retirar la prueba

- Eliminar o reconvertir al investigador de Ciudad Cerezo.
- Migrar partidas con el kit temporal.
- Actualizar documentación y versión.

## 12. Matriz mínima de pruebas

### Evento y recompensa

- Llegar al Lago sin medalla de Olivo.
- Llegar con la medalla.
- Ganar y perder contra el rival.
- Reiniciar y comprobar que la Mega no cambia.
- Intentar repetir el evento.
- Probar una partida con el Gyarados ya derrotado.
- Recibir el regalo con equipo libre, equipo lleno y PC lleno.
- Confirmar que no consume la captura Nuzlocke del Lago.

### Jefes

- Líder de gimnasio.
- Alto Mando y Campeón.
- Rival posterior.
- Administrador Rocket de la Torre Radio.
- Jefe especial de la lista.
- Combate doble.
- Revancha.

### Modos y regresiones

- Partida normal, Nuzlocke, randomizador y Randomlocke.
- Dificultades y límite reducido de equipo.
- Una sola Mega por entrenador.
- Piedra siempre correspondiente a la especie.
- Ningún legendario o mítico.
- Sin conflictos con otras mecánicas.
- ROM por debajo de 32 MiB.

## 13. Criterios de aceptación

La mejora estará terminada cuando:

- El rival bloquee el acceso al Gyarados hasta completar la escena prevista.
- Use Mega-Gengar en normal y una Mega válida aleatoria en Randomlocke.
- El jugador reciba exactamente un Mega-Aro y una pareja válida.
- El regalo no consuma la captura Nuzlocke del Lago.
- Todos los jefes definidos posteriores tengan una Mega final válida.
- Las elecciones sean estables al reiniciar.
- No aparezcan legendarios ni míticos.
- Las partidas de prueba existentes mantengan acceso a la mecánica.
- La ROM compile y permanezca dentro del límite de tamaño.

## 14. Decisiones fijadas

- La introducción ocurre en el Lago de la Furia.
- El rival utiliza Mega-Gengar en partida normal.
- En Randomlocke su última Mega es aleatoria.
- El jugador recibe Mega-Aro, Pokémon y megapiedra.
- El pool admite cualquier Mega no legendaria estable.
- Los jefes posteriores terminan con una Mega aleatoria.
- La implementación de jefes será centralizada.

## 15. Decisiones pendientes

- Texto definitivo de la escena.
- Equipo completo y nivel exacto del rival.
- Tratamiento definitivo del Beedrill de prueba.
- Lista exacta de jefes de zona añadidos manualmente.
- Inclusión futura de Megas de Leyendas Pokémon: Z-A.
- Política exacta cuando el PC también esté lleno.
