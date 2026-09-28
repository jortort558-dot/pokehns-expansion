#include "global.h"
#include "gym_tokens.h"
#include "event_data.h"
#include "caps.h"
#include "malloc.h"
#include "nuzlocke.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "string_util.h"
#include "trade.h"
#include "region_map.h"
#include "save.h"
#include "script_menu.h"
#include "strings.h"
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

    if (gSaveBlock3Ptr->gymTokens.count > 0)
        return TRUE;

    return settings->tx_Nuzlocke_GymTokens
        && (IsNuzlockeActive() || IsNuzlockeEasyActive());
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
        && GetBoxMonCurrentHp(boxMon) != 0
        && GetBoxMonData(boxMon, MON_DATA_HELD_ITEM) == ITEM_NONE;
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
        u16 mapsec = NuzlockeGetMapsecByZoneId(zone);

        if (mapsec != MAPSEC_NONE
         && NuzlockeFlagGet(mapsec)
         && !(*GetGymTokenRetriedFlagByte(zone) & bit))
        {
            sSelectedRetryZone = zone;
            sRetrySearchStart = zone + 1;
            StringCopy(gStringVar2, gRegionMapEntries[mapsec].name);
            gSpecialVar_Result = 1;
            return;
        }
    }
}

void RollGymTokenGachapon(void)
{
    u32 eligibleZones[NUZLOCKE_NUM_ZONES];
    u32 count = 0;
    u32 zone;
    u32 chosenIndex;
    u32 chosenZone;
    u16 mapsec;

    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0)
        return;

    for (zone = 0; zone < NUZLOCKE_NUM_ZONES; zone++)
    {
        u8 bit = 1 << (zone & 7);
        mapsec = NuzlockeGetMapsecByZoneId(zone);

        if (mapsec != MAPSEC_NONE
         && NuzlockeFlagGet(mapsec)
         && !(*GetGymTokenRetriedFlagByte(zone) & bit))
        {
            eligibleZones[count++] = zone;
        }
    }

    if (count == 0)
        return;

    chosenIndex = Random() % count;
    chosenZone = eligibleZones[chosenIndex];
    mapsec = NuzlockeGetMapsecByZoneId(chosenZone);

    NuzlockeFlagClearByZoneId(chosenZone);
    *GetGymTokenFailedFlagByte(chosenZone) &= ~(1 << (chosenZone & 7));
    *GetGymTokenRetriedFlagByte(chosenZone) |= (1 << (chosenZone & 7));
    gSaveBlock3Ptr->gymTokens.count--;

    StringCopy(gStringVar1, GetActiveRegionMapEntries()[mapsec].name);
    gSpecialVar_Result = 1;
}

void BuildGymTokenRetryMenu(void)
{
    const struct RegionMapLocation *regionMapEntries = GetActiveRegionMapEntries();
    u32 zone;
    u32 count = 0;

    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0)
        return;

    // Count first so the dynamic menu needs a single, exact allocation.  The
    // old repeated reallocations could fragment the small GBA heap and crash
    // before the route selector was drawn.
    for (zone = 0; zone < NUZLOCKE_NUM_ZONES; zone++)
    {
        u8 bit = 1 << (zone & 7);
        u16 mapsec = NuzlockeGetMapsecByZoneId(zone);

        if (mapsec != MAPSEC_NONE
         && NuzlockeFlagGet(mapsec)
         && !(*GetGymTokenRetriedFlagByte(zone) & bit))
            count++;
    }

    if (count == 0)
        return;

    MultichoiceDynamic_InitStack(count + 1);
    for (zone = 0; zone < NUZLOCKE_NUM_ZONES; zone++)
    {
        u8 bit = 1 << (zone & 7);
        u16 mapsec = NuzlockeGetMapsecByZoneId(zone);

        if (mapsec != MAPSEC_NONE
         && NuzlockeFlagGet(mapsec)
         && !(*GetGymTokenRetriedFlagByte(zone) & bit))
        {
            struct ListMenuItem item;
            const u8 *mapName = regionMapEntries[mapsec].name;
            u8 *name = Alloc(StringLength(mapName) + 1);

            if (name == NULL)
                continue;
            StringCopy(name, mapName);
            item.name = name;
            item.id = zone;
            MultichoiceDynamic_PushElement(item);
        }
    }

    if (!MultichoiceDynamic_StackEmpty())
    {
        struct ListMenuItem cancelItem;
        u8 *cancelName = Alloc(StringLength(gText_Cancel2) + 1);

        if (cancelName != NULL)
        {
            StringCopy(cancelName, gText_Cancel2);
            cancelItem.name = cancelName;
            cancelItem.id = NUZLOCKE_NUM_ZONES;
            MultichoiceDynamic_PushElement(cancelItem);
        }
        gSpecialVar_Result = 1;
    }
    else
    {
        MultichoiceDynamic_DestroyStack();
    }
}

void SelectGymTokenRetry(void)
{
    u8 zone = gSpecialVar_0x8004;
    u16 mapsec;

    gSpecialVar_Result = 0;
    if (zone >= NUZLOCKE_NUM_ZONES)
        return;
    mapsec = NuzlockeGetMapsecByZoneId(zone);
    if (mapsec == MAPSEC_NONE || !NuzlockeFlagGet(mapsec))
        return;
    sSelectedRetryZone = zone;
    StringCopy(gStringVar2, GetActiveRegionMapEntries()[mapsec].name);
    gSpecialVar_Result = 1;
}

void UseSelectedGymTokenRetry(void)
{
    u8 zone = sSelectedRetryZone;
    u8 bit;
    u16 mapsec;

    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive() || gSaveBlock3Ptr->gymTokens.count == 0 || zone >= NUZLOCKE_NUM_ZONES)
        return;
    bit = 1 << (zone & 7);
    mapsec = NuzlockeGetMapsecByZoneId(zone);
    if (mapsec == MAPSEC_NONE
     || !NuzlockeFlagGet(mapsec)
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
    u16 selectedSpecies = offeredSpecies;
    u16 eligibleCount = 0;
    u16 species;

    // Choose uniformly among regular species whose base-stat total is at least
    // as high as that of the offered Pokémon.
    for (species = 1; species < NUM_SPECIES; species++)
    {
        const struct SpeciesInfo *info = &gSpeciesInfo[species];

        if (!IsSpeciesEnabled(species) || info->isRestrictedLegendary || info->isSubLegendary
         || info->isMythical || info->isUltraBeast || info->isMegaEvolution
         || info->isPrimalReversion || info->isUltraBurst)
            continue;
        if (GetBaseStatTotal(species) >= offeredBst)
        {
            eligibleCount++;
            if (Random() % eligibleCount == 0)
                selectedSpecies = species;
        }
    }
    return selectedSpecies;
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
     || !GymTokenCanTradeMon(boxMon))
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
    gEnemyParty[0] = received;
    SetCustomInGameTradeScene();
    StringCopy(gStringVar3, gSpeciesInfo[species].speciesName);
    gSpecialVar_Result = 1;
}

void FinishGymTokenTrade(void)
{
    gSpecialVar_Result = 0;
    if (!IsGymTokenModeActive()
     || gSaveBlock3Ptr->gymTokens.count == 0)
        return;
    gSaveBlock3Ptr->gymTokens.count--;
    gSaveBlock3Ptr->gymTokens.mysteryTrades++;
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
