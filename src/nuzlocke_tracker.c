/*
 * nuzlocke_tracker.c
 * ------------------
 * Modulo de telemetria para el Nuzlocke Tracker de Heart & Soul.
 *
 * Usa el canal de depuracion de mGBA (MgbaPrintf, LOG_HANDLER_MGBA_PRINT).
 * Un proceso Node.js local lee el log de mGBA y hace POST al tracker web.
 *
 * Formato de mensaje:
 *   TRACKER:PARTY_SYNC:{n}|{slot},{speciesId},{level},{hp},{maxHp},{nickname},{status}|...
 *   TRACKER:FAINT:{slot},{speciesId},{level},{nickname}
 *   TRACKER:CAPTURE:{slot},{speciesId},{level},{nickname}
 *   TRACKER:MAP:{mapsecId}
 *
 * La cabecera publica esta en include/nuzlocke_tracker.h.
 */

#include "global.h"
#include "nuzlocke_tracker.h"
#include "mini_printf.h"
#include "party_menu.h"
#include "pokemon.h"
#include "overworld.h"
#include "constants/party_menu.h"
#include "constants/species.h"
#include "constants/pokemon.h"

/* Solo compilar en builds de depuracion con mGBA activo. */
#ifndef NDEBUG
#if (LOG_HANDLER == LOG_HANDLER_MGBA_PRINT)

#include "config/general.h"

/* MgbaPrintf esta declarada en libisagbprn.c.
 * No tiene header propio: la declaramos extern aqui para no incluir
 * todo libisagbprn.h (que no existe) y minimizar dependencias. */
extern void MgbaPrintf(s32 level, const char *ptr, ...);

#define TRACKER_LOG_LEVEL   MGBA_LOG_INFO

/* Buffer auxiliar para construir el string de una linea de equipo.
 * 256 bytes son suficientes para 6 Pokemon con todos los campos. */
#define TRACKER_BUF_SIZE 256

static s32 TrackerSnprintf(char *buffer, u32 bufferSize, const char *format, ...)
{
    s32 result;
    va_list args;

    va_start(args, format);
    result = mini_vsnprintf(buffer, bufferSize, format, args);
    va_end(args);
    return result;
}

/* Codigos de estado de ailment a texto corto. */
static const char *AilmentToStr(u32 ailment)
{
    switch (ailment)
    {
    case AILMENT_PSN:   return "PSN";
    case AILMENT_PRZ:   return "PAR";
    case AILMENT_BRN:   return "BRN";
    case AILMENT_FRZ:   return "FRZ";
    case AILMENT_SLP:   return "SLP";
    case AILMENT_PKRS:  return "PKRS";
    case AILMENT_FNT:   return "FNT";
    case AILMENT_FRB:   return "FRB";
    default:            return "";
    }
}

/* -------------------------------------------------------------------------
 * Tracker_DumpParty
 * Emite el estado de los hasta 6 Pokemon del equipo en un mensaje unico.
 * Formato: TRACKER:PARTY_SYNC:{n}|{slot},{speciesId},{level},{hp}/{maxHp},{status}|...
 * ------------------------------------------------------------------------- */
void Tracker_DumpParty(void)
{
    u8 i;
    char buf[TRACKER_BUF_SIZE];
    s32 offset = 0;
    u8 partyCount = CalculatePlayerPartyCount();

    /* Cabecera */
    offset += TrackerSnprintf(buf + offset, TRACKER_BUF_SIZE - offset, "TRACKER:PARTY_SYNC:%d", partyCount);

    for (i = 0; i < PARTY_SIZE && i < partyCount; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        if (species == SPECIES_NONE)
            continue;

        u8  level   = GetMonData(mon, MON_DATA_LEVEL, NULL);
        u16 hp      = GetMonData(mon, MON_DATA_HP, NULL);
        u16 maxHp   = GetMonData(mon, MON_DATA_MAX_HP, NULL);
        u32 ailment = GetMonAilment(mon);

        /* Mote (hasta 10 chars) */
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        GetMonData(mon, MON_DATA_NICKNAME, nickname);
        nickname[POKEMON_NAME_LENGTH] = '\0';

        offset += TrackerSnprintf(buf + offset, TRACKER_BUF_SIZE - offset,
            "|%d,%d,%d,%d,%d,%s,%s",
            i, (int)species, (int)level, (int)hp, (int)maxHp,
            (const char *)nickname,
            AilmentToStr(ailment));

        if (offset >= TRACKER_BUF_SIZE - 32)
            break; /* seguridad */
    }

    MgbaPrintf(TRACKER_LOG_LEVEL, "%s", buf);
}

/* -------------------------------------------------------------------------
 * Tracker_EmitFaint
 * Emite un evento de muerte ANTES de que el motor Nuzlocke borre el slot.
 * Formato: TRACKER:FAINT:{slot},{speciesId},{level},{nickname}
 * ------------------------------------------------------------------------- */
void Tracker_EmitFaint(u8 position)
{
    struct Pokemon *mon = &gPlayerParty[position];
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    if (species == SPECIES_NONE)
        return;

    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    nickname[POKEMON_NAME_LENGTH] = '\0';

    MgbaPrintf(TRACKER_LOG_LEVEL,
        "TRACKER:FAINT:%d,%d,%d,%s",
        (int)position, (int)species, (int)level, (const char *)nickname);

    /* Despues de emitir la muerte, actualizamos el equipo completo */
    Tracker_DumpParty();
}

/* -------------------------------------------------------------------------
 * Tracker_EmitCapture
 * Emite un evento de captura del slot indicado.
 * Formato: TRACKER:CAPTURE:{slot},{speciesId},{level},{nickname}
 * ------------------------------------------------------------------------- */
void Tracker_EmitCapture(u8 position)
{
    struct Pokemon *mon = &gPlayerParty[position];
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    if (species == SPECIES_NONE)
        return;

    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    nickname[POKEMON_NAME_LENGTH] = '\0';

    MgbaPrintf(TRACKER_LOG_LEVEL,
        "TRACKER:CAPTURE:%d,%d,%d,%s",
        (int)position, (int)species, (int)level, (const char *)nickname);

    Tracker_DumpParty();
}

/* -------------------------------------------------------------------------
 * Tracker_EmitMapChange
 * Emite el ID del mapsec actual (MAPSEC_*).
 * Formato: TRACKER:MAP:{mapsecId}
 * ------------------------------------------------------------------------- */
void Tracker_EmitMapChange(void)
{
    u16 mapsec = GetCurrentRegionMapSectionId();
    MgbaPrintf(TRACKER_LOG_LEVEL, "TRACKER:MAP:%d", (int)mapsec);
}

#else  /* LOG_HANDLER != LOG_HANDLER_MGBA_PRINT -> stubs vacios */
void Tracker_DumpParty(void)     {}
void Tracker_EmitFaint(u8 p)     { (void)p; }
void Tracker_EmitCapture(u8 p)   { (void)p; }
void Tracker_EmitMapChange(void) {}
#endif /* LOG_HANDLER */

#else  /* NDEBUG -> stubs vacios en release */
void Tracker_DumpParty(void)     {}
void Tracker_EmitFaint(u8 p)     { (void)p; }
void Tracker_EmitCapture(u8 p)   { (void)p; }
void Tracker_EmitMapChange(void) {}
#endif /* NDEBUG */
