# Configuración de extras Nuzlocke

## Objetivo

Las ayudas añadidas por Heart & Soul no deben formar parte obligatoria de un
Nuzlocke. La pestaña `NUZLOCKE` permite activar o desactivar cada sistema
independiente antes de empezar la partida.

## Opciones actuales

| Opción | Activada | Desactivada |
|---|---|---|
| PokéVial | Se entrega al inicio, aparece en START, puede usarse y se recarga en Centros Pokémon. | No se entrega; si ya existía, queda oculto, sin uso y sin recarga. |
| Fichas Gimnasio | Las medallas conceden fichas y se habilitan sus tres servicios. | No se conceden fichas, no se registran encuentros recuperables y los servicios no ofrecen saldo. |

Ambas opciones están activadas por defecto. La migración a `SAVE_VERSION 8`
también conserva ese comportamiento en partidas existentes.

Durante una partida solo pueden apagarse. No pueden reactivarse para evitar la
obtención retroactiva de recursos o ventajas.

## Regla para futuras mecánicas

Todo nuevo extra que afecte a la dificultad o conceda recursos debe:

1. Tener un bit persistente en `ChallengeSettings`.
2. Aparecer como opción `SÍ/NO` en la pestaña relacionada con la mecánica.
3. Tener una única función de consulta usada por entrega, interfaz y efecto.
4. Permanecer completamente inerte al desactivarse, incluso si sus datos
   proceden de una versión anterior.
5. Definir un valor por defecto y una migración para partidas previas.
6. Permitir como máximo su desactivación durante la partida, salvo que una
   activación posterior no pueda conceder ninguna ventaja retroactiva.

## Puntos de implementación

- Menú y persistencia: `src/challenge_menu.c`, `include/global.h`.
- PokéVial: `src/item_use.c`, `src/start_menu.c` y el evento de la madre.
- Fichas: `src/gym_tokens.c`.
- Compatibilidad: `src/save.c`, `include/save.h`.

