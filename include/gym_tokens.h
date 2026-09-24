#ifndef GUARD_GYM_TOKENS_H
#define GUARD_GYM_TOKENS_H

#include "global.h"

#define GYM_TOKEN_MAX 3

bool32 IsGymTokenModeActive(void);
bool32 GymTokenCanTradeMon(struct BoxPokemon *boxMon);
bool32 GymTokenCanReviveMon(struct BoxPokemon *boxMon);
void AwardGymToken(void);
void GetGymTokenCount(void);
void FindNextGymTokenRetry(void);
void RollGymTokenGachapon(void);
void BuildGymTokenRetryMenu(void);
void SelectGymTokenRetry(void);
void UseSelectedGymTokenRetry(void);
void UseGymTokenTrade(void);
void FinishGymTokenTrade(void);
void UseGymTokenRevive(void);
void SaveGymTokenTransaction(void);
void GymTokenRecordFailedEncounter(u16 mapsec);

#endif
