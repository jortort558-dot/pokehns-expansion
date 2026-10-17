#ifndef GUARD_HNS_LIVE_TELEMETRY_H
#define GUARD_HNS_LIVE_TELEMETRY_H

#include "global.h"

// Publica una instantanea de solo lectura en EWRAM para el cliente web.
// No escribe en Flash ni forma parte del formato del archivo .sav.
void HnsLiveTelemetry_Update(void);

enum HnsLiveEventType
{
    HNS_LIVE_EVENT_NONE,
    HNS_LIVE_EVENT_CAPTURE,
    HNS_LIVE_EVENT_EVOLUTION,
    HNS_LIVE_EVENT_ENCOUNTER_FAILED,
    HNS_LIVE_EVENT_FAINT,
    HNS_LIVE_EVENT_TRADE,
    HNS_LIVE_EVENT_GYM_TOKEN_TRADE,
    HNS_LIVE_EVENT_ENCOUNTER_START,
    HNS_LIVE_EVENT_ENCOUNTER_END,
};

enum HnsLiveEncounterFlags
{
    HNS_LIVE_ENCOUNTER_SHINY                 = (1 << 0),
    HNS_LIVE_ENCOUNTER_FIRST_VALID           = (1 << 1),
    HNS_LIVE_ENCOUNTER_SHINY_EXCEPTION       = (1 << 2),
    HNS_LIVE_ENCOUNTER_DUPLICATE_LINE        = (1 << 3),
    HNS_LIVE_ENCOUNTER_ROUTE_USED            = (1 << 4),
    HNS_LIVE_ENCOUNTER_CAPTURE_SUSPENDED     = (1 << 5),
    HNS_LIVE_ENCOUNTER_SCRIPTED              = (1 << 6),
    HNS_LIVE_ENCOUNTER_OTHER_CHALLENGE_BLOCK = (1 << 7),
};

void HnsLiveTelemetry_RecordMonEvent(u8 type, struct Pokemon *mon, u16 otherSpecies);
void HnsLiveTelemetry_RecordFaint(struct Pokemon *mon, u8 battler);
void HnsLiveTelemetry_RecordEncounterStart(struct Pokemon *mon);
void HnsLiveTelemetry_RecordEncounterEnd(struct Pokemon *mon, u8 outcome);

#endif // GUARD_HNS_LIVE_TELEMETRY_H
