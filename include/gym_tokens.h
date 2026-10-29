#ifndef GUARD_GYM_TOKENS_H
#define GUARD_GYM_TOKENS_H

#include "global.h"

#define GYM_TOKEN_MAX 99
#define GYM_TOKEN_REVIVE_SLOTS 8
#define GYM_TOKEN_REVIVE_COST 2

bool32 IsGymTokenModeActive(void);
bool32 GymTokenCanTradeMon(struct BoxPokemon *boxMon);
bool32 GymTokenCanReviveMon(struct BoxPokemon *boxMon);
bool32 GiftMonCanTrade(struct BoxPokemon *boxMon);
bool32 IsFossilSpecies(u16 species);
u16 GetRandomSpeciesFossilSimilarFinalBst(u16 fossilSpecies);
u16 GetRandomSpeciesSimilarBst(u16 baseSpecies);
void CheckPlayerHasGiftMon(void);
void UseGiftMonTrade(void);
void BuildMegaStoneExchangeMenu(void);
void TradeDuplicateMegaStone(void);
void ShouldShowMegaStoneExchangeNotice(void);
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
void GymTokenClearEncounterState(u16 mapsec);

#endif
