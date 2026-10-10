#ifndef GUARD_HNS_LIVE_TELEMETRY_H
#define GUARD_HNS_LIVE_TELEMETRY_H

// Publica una instantanea de solo lectura en EWRAM para el cliente web.
// No escribe en Flash ni forma parte del formato del archivo .sav.
void HnsLiveTelemetry_Update(void);

#endif // GUARD_HNS_LIVE_TELEMETRY_H
