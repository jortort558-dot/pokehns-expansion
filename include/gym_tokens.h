#ifndef GUARD_GYM_TOKENS_H
#define GUARD_GYM_TOKENS_H

#include "global.h"

#define GYM_TOKEN_MAX 3

bool32 GymTokenCanTradeMon(struct BoxPokemon *boxMon);
bool32 GymTokenCanReviveMon(struct BoxPokemon *boxMon);
void AwardGymToken(void);
void GetGymTokenCount(void);
void UseGymTokenRetry(void);
void UseGymTokenTrade(void);
void UseGymTokenRevive(void);
void GymTokenRecordFailedEncounter(u16 mapsec);

#endif
