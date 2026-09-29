#ifndef GUARD_NUZLOCKE_TRACKER_H
#define GUARD_NUZLOCKE_TRACKER_H

#include "global.h"

/*
 * nuzlocke_tracker.h
 * ------------------
 * Telemetria del Nuzlocke Tracker para Heart & Soul.
 * Emite eventos al canal de depuracion de mGBA (MgbaPrintf) que un script
 * puente local captura y reenvía a la API del tracker en tiempo real.
 *
 * Solo activo en builds de depuracion (LOG_HANDLER_MGBA_PRINT).
 * En RELEASE todas las funciones son no-op.
 */

/* Emite el estado completo del equipo (hasta 6 Pokemon). */
void Tracker_DumpParty(void);

/* Emite un evento de muerte para gPlayerParty[position].
 * Llamar ANTES de borrar el slot en NuzlockeDeleteFaintedPartyPokemon. */
void Tracker_EmitFaint(u8 position);

/* Emite un evento de captura para gPlayerParty[position]. */
void Tracker_EmitCapture(u8 position);

/* Emite el mapa actual del jugador. */
void Tracker_EmitMapChange(void);

#endif /* GUARD_NUZLOCKE_TRACKER_H */
