#include "global.h"
#include "gym_tokens.h"
#include "event_data.h"
#include "nuzlocke.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "string_util.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/vars.h"

#define GYM_TOKEN_TRADE_LIMIT 1
#define GYM_TOKEN_REVIVE_COST 2
#define GYM_TOKEN_REVIVE_SLOTS 8

static bool32 IsGymTokenModeActive(void)
{
    return IsNuzlockeActive() || IsNuzlockeEasyActive();
}

static u16 GetBaseStatTotal(u16 species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];
    return info->baseHP + info->baseAttack + info->baseDefense
         + info->baseSpeed + info->baseSpAttack + info->baseSpDefense;
}

static bool32 WasRevived(const struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < GYM_TOKEN_REVIVE_SLOTS; i++)
    {
        if (gSaveBlock3Ptr->gymTokens.revivedPersonalities[i] == boxMon->personality
         && gSaveBlock3Ptr->gymTokens.revivedOtIds[i] == boxMon->otId)
            return TRUE;
    }
    return FALSE;
}

bool32 GymTokenCanTradeMon(struct BoxPokemon *boxMon)
{
    return IsGymTokenModeActive()
        && GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE
        && !GetBoxMonData(boxMon, MON_DATA_IS_EGG)
        && GetBoxMonData(boxMon, MON_DATA_HP) != 0;
}

bool32 GymTokenCanReviveMon(struct BoxPokemon *boxMon)
{
    return IsGymTokenModeActive()
        && GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE
        && !GetBoxMonData(boxMon, MON_DATA_IS_EGG)
        && GetBoxMonData(boxMon, MON_DATA_HP) == 0
        && !WasRevived(boxMon);
}

void AwardGymToken(void)
{
    u16 badgeCount = VarGet(VAR_NUM_BADGES);
    u16 mask;

    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || badgeCount == 0 || badgeCount > 16)
        return;
    mask = 1 << (badgeCount - 1);
    if (gSaveBlock3Ptr->gymTokens.awardedBadgeMask & mask)
        return;
    gSaveBlock3Ptr->gymTokens.awardedBadgeMask |= mask;
    if (gSaveBlock3Ptr->gymTokens.count < GYM_TOKEN_MAX)
    {
        gSaveBlock3Ptr->gymTokens.count++;
        gSpecialVar_Result = 1;
    }
    else
    {
        gSpecialVar_Result = 2;
    }
}

void GetGymTokenCount(void)
{
    gSpecialVar_Result = gSaveBlock3Ptr->gymTokens.count;
    ConvertIntToDecimalStringN(gStringVar1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, 1);
}

void GymTokenRecordFailedEncounter(u16 mapsec)
{
    u8 zone = NuzlockeGetZoneId(mapsec);
    if (zone < NUZLOCKE_NUM_ZONES)
        gSaveBlock3Ptr->gymTokens.failedEncounterFlags[zone / 8] |= 1 << (zone & 7);
}

void UseGymTokenRetry(void)
{
    u32 zone;
    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0)
        return;
    for (zone = 0; zone < NUZLOCKE_NUM_ZONES; zone++)
    {
        u8 bit = 1 << (zone & 7);
        if ((gSaveBlock3Ptr->gymTokens.failedEncounterFlags[zone / 8] & bit)
         && !(gSaveBlock3Ptr->gymTokens.retriedEncounterFlags[zone / 8] & bit))
        {
            NuzlockeFlagClearByZoneId(zone);
            gSaveBlock3Ptr->gymTokens.failedEncounterFlags[zone / 8] &= ~bit;
            gSaveBlock3Ptr->gymTokens.retriedEncounterFlags[zone / 8] |= bit;
            gSaveBlock3Ptr->gymTokens.count--;
            gSpecialVar_Result = 1;
            return;
        }
    }
}

static u16 ChooseMysterySpecies(u16 offeredSpecies)
{
    u16 offeredBst = GetBaseStatTotal(offeredSpecies);
    u32 attempts;
    for (attempts = 0; attempts < 2048; attempts++)
    {
        u16 species = (Random() % (NUM_SPECIES - 1)) + 1;
        u16 bst;
        const struct SpeciesInfo *info = &gSpeciesInfo[species];
        if (!IsSpeciesEnabled(species) || info->isRestrictedLegendary || info->isSubLegendary
         || info->isMythical || info->isUltraBeast || info->isMegaEvolution
         || info->isPrimalReversion || info->isUltraBurst)
            continue;
        bst = GetBaseStatTotal(species);
        if (bst >= offeredBst && bst <= offeredBst + 80)
            return species;
    }
    return offeredSpecies;
}

void UseGymTokenTrade(void)
{
    struct BoxPokemon *boxMon = GetSelectedBoxMonFromPcOrParty();
    struct Pokemon received = {0};
    u16 species;
    u8 level;

    gSpecialVar_Result = 0;
    if (gSaveBlock3Ptr->gymTokens.count == 0
     || gSaveBlock3Ptr->gymTokens.mysteryTrades >= GYM_TOKEN_TRADE_LIMIT
     || !GymTokenCanTradeMon(boxMon)
     || GetBoxMonData(boxMon, MON_DATA_HELD_ITEM) != ITEM_NONE)
        return;
    species = ChooseMysterySpecies(GetBoxMonData(boxMon, MON_DATA_SPECIES));
    level = GetBoxMonData(boxMon, MON_DATA_LEVEL);
    CreateRandomMonWithIVs(&received, species, level, USE_RANDOM_IVS);
    if (gSpecialVar_0x8004 == PC_MON_CHOSEN)
        *boxMon = received.box;
    else
        gPlayerParty[gSpecialVar_0x8004] = received;
    gSaveBlock3Ptr->gymTokens.count--;
    gSaveBlock3Ptr->gymTokens.mysteryTrades++;
    StringCopy(gStringVar1, gSpeciesInfo[species].speciesName);
    gSpecialVar_Result = 1;
}

void UseGymTokenRevive(void)
{
    struct BoxPokemon *boxMon = GetSelectedBoxMonFromPcOrParty();
    u32 i;

    gSpecialVar_Result = 0;
    if (gSaveBlock3Ptr->gymTokens.count < GYM_TOKEN_REVIVE_COST || !GymTokenCanReviveMon(boxMon))
        return;
    for (i = 0; i < GYM_TOKEN_REVIVE_SLOTS; i++)
    {
        if (gSaveBlock3Ptr->gymTokens.revivedPersonalities[i] == 0
         && gSaveBlock3Ptr->gymTokens.revivedOtIds[i] == 0)
        {
            gSaveBlock3Ptr->gymTokens.revivedPersonalities[i] = boxMon->personality;
            gSaveBlock3Ptr->gymTokens.revivedOtIds[i] = boxMon->otId;
            HealBoxPokemon(boxMon);
            gSaveBlock3Ptr->gymTokens.count -= GYM_TOKEN_REVIVE_COST;
            gSpecialVar_Result = 1;
            return;
        }
    }
}
