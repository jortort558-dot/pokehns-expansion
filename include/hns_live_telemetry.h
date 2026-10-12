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
};

void HnsLiveTelemetry_RecordMonEvent(u8 type, struct Pokemon *mon, u16 otherSpecies);
void HnsLiveTelemetry_RecordFaint(struct Pokemon *mon, u8 battler);

#endif // GUARD_HNS_LIVE_TELEMETRY_H
