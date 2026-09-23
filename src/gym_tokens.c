#include "global.h"
#include "gym_tokens.h"
#include "event_data.h"
#include "caps.h"
#include "nuzlocke.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "string_util.h"
#include "region_map.h"
#include "save.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/vars.h"

#define GYM_TOKEN_TRADE_LIMIT 1
#define GYM_TOKEN_REVIVE_COST 2
#define GYM_TOKEN_REVIVE_SLOTS 8

static EWRAM_DATA u8 sSelectedRetryZone = 0;
static EWRAM_DATA u8 sRetrySearchStart = 0;

static u8 *GetGymTokenFailedFlagByte(u8 zone)
{
    if (zone < 96)
        return &gSaveBlock3Ptr->gymTokens.failedEncounterFlags[zone / 8];
    return &gSaveBlock3Ptr->gymTokens.failedEncounterFlagsExt[(zone - 96) / 8];
}

static u8 *GetGymTokenRetriedFlagByte(u8 zone)
{
    if (zone < 96)
        return &gSaveBlock3Ptr->gymTokens.retriedEncounterFlags[zone / 8];
    return &gSaveBlock3Ptr->gymTokens.retriedEncounterFlagsExt[(zone - 96) / 8];
}

static u16 GetBoxMonCurrentHp(struct BoxPokemon *boxMon)
{
    struct Pokemon mon = {0};

    BoxMonToMon(boxMon, &mon);
    return GetMonData(&mon, MON_DATA_HP);
}

bool32 IsGymTokenModeActive(void)
{
    const struct ChallengeSettings *settings = &gSaveBlock3Ptr->challengeSettings;

    return settings->tx_Nuzlocke_GymTokens
        && (IsNuzlockeActive() || IsNuzlockeEasyActive());
}

static u16 GetBaseStatTotal(u16 species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];
    return info->baseHP + info->baseAttack + info->baseDefense
         + info->baseSpeed + info->baseSpAttack + info->baseSpDefense;
}

static u16 GetFamilyBaseSpecies(u16 species)
{
    u16 previous;
    while ((previous = GetSpeciesPreEvolution(species)) != SPECIES_NONE && previous != species)
        species = previous;
    return species;
}

static bool32 IsCaughtFamily(u16 species)
{
    u16 family = GetFamilyBaseSpecies(species);
    u16 i;
    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i) && GetFamilyBaseSpecies(i) == family
         && GetSetPokedexFlag(SpeciesToNationalPokedexNum(i), FLAG_GET_CAUGHT))
            return TRUE;
    }
    return FALSE;
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
        && GetBoxMonCurrentHp(boxMon) != 0;
}

bool32 GymTokenCanReviveMon(struct BoxPokemon *boxMon)
{
    return IsGymTokenModeActive()
        && GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE
        && !GetBoxMonData(boxMon, MON_DATA_IS_EGG)
        && GetBoxMonCurrentHp(boxMon) == 0
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
    gSpecialVar_Result = IsGymTokenModeActive() ? gSaveBlock3Ptr->gymTokens.count : 0;
    ConvertIntToDecimalStringN(gStringVar1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, 1);
}

void GymTokenRecordFailedEncounter(u16 mapsec)
{
    u8 zone = NuzlockeGetZoneId(mapsec);
    if (IsGymTokenModeActive() && zone < NUZLOCKE_NUM_ZONES)
        *GetGymTokenFailedFlagByte(zone) |= 1 << (zone & 7);
}

void FindNextGymTokenRetry(void)
{
    u32 zone;
    gSpecialVar_Result = 0;
    if (gSpecialVar_0x8005 == 0)
    {
        sRetrySearchStart = 0;
        sSelectedRetryZone = NUZLOCKE_NUM_ZONES;
    }
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0)
        return;
    for (zone = sRetrySearchStart; zone < NUZLOCKE_NUM_ZONES; zone++)
    {
        u8 bit = 1 << (zone & 7);
        if ((*GetGymTokenFailedFlagByte(zone) & bit)
         && !(*GetGymTokenRetriedFlagByte(zone) & bit))
        {
            u16 mapsec = NuzlockeGetMapsecByZoneId(zone);
            if (mapsec == MAPSEC_NONE)
                continue;
            sSelectedRetryZone = zone;
            sRetrySearchStart = zone + 1;
            StringCopy(gStringVar2, gRegionMapEntries[mapsec].name);
            gSpecialVar_Result = 1;
            return;
        }
    }
}

void UseSelectedGymTokenRetry(void)
{
    u8 zone = sSelectedRetryZone;
    u8 bit;
    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0 || zone >= NUZLOCKE_NUM_ZONES)
        return;
    bit = 1 << (zone & 7);
    if (!(*GetGymTokenFailedFlagByte(zone) & bit)
     || (*GetGymTokenRetriedFlagByte(zone) & bit))
        return;
    NuzlockeFlagClearByZoneId(zone);
    *GetGymTokenFailedFlagByte(zone) &= ~bit;
    *GetGymTokenRetriedFlagByte(zone) |= bit;
    gSaveBlock3Ptr->gymTokens.count--;
    sSelectedRetryZone = NUZLOCKE_NUM_ZONES;
    gSpecialVar_Result = 1;
}

static u16 ChooseMysterySpecies(u16 offeredSpecies)
{
    u16 offeredBst = GetBaseStatTotal(offeredSpecies);
    u16 offeredFamily = GetFamilyBaseSpecies(offeredSpecies);
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
        if (GetFamilyBaseSpecies(species) == offeredFamily || IsCaughtFamily(species))
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
    u8 levels[PARTY_SIZE];
    u8 aliveCount = 0;
    u8 level;
    u8 i;
    u8 perfectIv = MAX_PER_STAT_IVS;
    u8 firstPerfect;
    u8 secondPerfect;
    static const enum MonData sIvFields[] = {
        MON_DATA_HP_IV, MON_DATA_ATK_IV, MON_DATA_DEF_IV,
        MON_DATA_SPEED_IV, MON_DATA_SPATK_IV, MON_DATA_SPDEF_IV,
    };
    static const u8 sClerkName[] = _("CANJE");

    gSpecialVar_Result = 0;
    if (gSaveBlock3Ptr->gymTokens.count == 0
     || gSaveBlock3Ptr->gymTokens.mysteryTrades >= GYM_TOKEN_TRADE_LIMIT
     || !GymTokenCanTradeMon(boxMon)
     || GetBoxMonData(boxMon, MON_DATA_HELD_ITEM) != ITEM_NONE)
        return;
    species = ChooseMysterySpecies(GetBoxMonData(boxMon, MON_DATA_SPECIES));
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0
         && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            levels[aliveCount++] = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
    }
    for (i = 1; i < aliveCount; i++)
    {
        u8 j = i;
        u8 value = levels[i];
        while (j > 0 && levels[j - 1] > value)
        {
            levels[j] = levels[j - 1];
            j--;
        }
        levels[j] = value;
    }
    level = aliveCount ? levels[aliveCount / 2] : GetBoxMonData(boxMon, MON_DATA_LEVEL);
    if (level < 5)
        level = 5;
    if (level > GetCurrentLevelCap())
        level = GetCurrentLevelCap();
    CreateMonWithIVs(&received, species, level, Random32(), OTID_STRUCT_PRESET(0x46494348), USE_RANDOM_IVS);
    GiveMonInitialMoveset(&received);
    firstPerfect = Random() % NUM_STATS;
    do
        secondPerfect = Random() % NUM_STATS;
    while (secondPerfect == firstPerfect);
    SetMonData(&received, sIvFields[firstPerfect], &perfectIv);
    SetMonData(&received, sIvFields[secondPerfect], &perfectIv);
    SetMonData(&received, MON_DATA_OT_NAME, sClerkName);
    CalculateMonStats(&received);
    HandleSetPokedexFlagFromMon(&received, FLAG_SET_SEEN);
    HandleSetPokedexFlagFromMon(&received, FLAG_SET_CAUGHT);
    if (gSpecialVar_0x8004 == PC_MON_CHOSEN)
        *boxMon = received.box;
    else
        gPlayerParty[gSpecialVar_0x8004] = received;
    gSaveBlock3Ptr->gymTokens.count--;
    gSaveBlock3Ptr->gymTokens.mysteryTrades++;
    StringCopy(gStringVar3, gSpeciesInfo[species].speciesName);
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

void SaveGymTokenTransaction(void)
{
    gSpecialVar_Result = TrySavingData(SAVE_NORMAL) == SAVE_STATUS_OK;
}
