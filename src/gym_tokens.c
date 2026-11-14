#include "global.h"
#include "gym_tokens.h"
#include "event_data.h"
#include "caps.h"
#include "chooseboxmon.h"
#include "malloc.h"
#include "item.h"
#include "nuzlocke.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "randomizer.h"
#include "string_util.h"
#include "trade.h"
#include "region_map.h"
#include "save.h"
#include "script_menu.h"
#include "strings.h"
#include "hns_live_telemetry.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "constants/region_map_sections.h"
#include "rtc.h"

#define GYM_TOKEN_TRADE_LIMIT 1

static EWRAM_DATA u8 sSelectedRetryZone = 0;
static EWRAM_DATA u8 sRetrySearchStart = 0;

void ShouldShowMegaStoneExchangeNotice(void)
{
    u16 item = gSpecialVar_0x8006;

    gSpecialVar_Result = FALSE;
    if (FlagGet(FLAG_POKEGEAR_MEGA_EXCHANGE_NOTICE)
     || !FlagGet(FLAG_SYS_POKENAV_GET)
     || item >= ITEMS_COUNT)
        return;

    if (gItemsInfo[item].sortType == ITEM_TYPE_MEGA_STONE)
        gSpecialVar_Result = TRUE;
}

static bool32 IsMegaStoneHeldByMon(u16 item)
{
    u32 i;
    u8 box;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (GetBoxMonDataAt(box, i, MON_DATA_HELD_ITEM) == item)
                return TRUE;
        }
    }

    return FALSE;
}

static bool32 PlayerOwnsMegaStone(u16 item)
{
    return CheckBagHasItem(item, 1)
        || CheckPCHasItem(item, 1)
        || IsMegaStoneHeldByMon(item);
}

static bool32 MegaStoneHasTradableDuplicate(u16 item)
{
    u16 bagCount = CountTotalItemQuantityInBag(item);

    if (bagCount >= 2)
        return TRUE;
    return bagCount == 1
        && (CheckPCHasItem(item, 1) || IsMegaStoneHeldByMon(item));
}

static u32 CountMissingMegaStones(void)
{
    u32 count = 0;
    u32 i;

    for (i = 0; i < GetMegaStonePoolCount(); i++)
    {
        if (!PlayerOwnsMegaStone(GetMegaStoneFromPool(i)))
            count++;
    }
    return count;
}

void BuildMegaStoneExchangeMenu(void)
{
    u32 duplicateCount = 0;
    u32 i;

    gSpecialVar_Result = 0;
    if (CountMissingMegaStones() == 0)
    {
        gSpecialVar_Result = 2;
        return;
    }

    for (i = 0; i < GetMegaStonePoolCount(); i++)
    {
        if (MegaStoneHasTradableDuplicate(GetMegaStoneFromPool(i)))
            duplicateCount++;
    }
    if (duplicateCount == 0)
        return;

    MultichoiceDynamic_InitStack(duplicateCount + 1);
    for (i = 0; i < GetMegaStonePoolCount(); i++)
    {
        u16 itemId = GetMegaStoneFromPool(i);

        if (MegaStoneHasTradableDuplicate(itemId))
        {
            const u8 *itemName = GetItemName(itemId);
            u8 *name = Alloc(StringLength(itemName) + 1);

            if (name != NULL)
            {
                struct ListMenuItem item;

                StringCopy(name, itemName);
                item.name = name;
                item.id = itemId;
                MultichoiceDynamic_PushElement(item);
            }
        }
    }

    {
        u8 *cancelName = Alloc(StringLength(gText_Cancel2) + 1);

        if (cancelName != NULL)
        {
            struct ListMenuItem cancelItem;

            StringCopy(cancelName, gText_Cancel2);
            cancelItem.name = cancelName;
            cancelItem.id = ITEM_NONE;
            MultichoiceDynamic_PushElement(cancelItem);
        }
    }
    if (!MultichoiceDynamic_StackEmpty())
        gSpecialVar_Result = 1;
    else
        MultichoiceDynamic_DestroyStack();
}

void TradeDuplicateMegaStone(void)
{
    u16 offeredItem = gSpecialVar_0x8004;
    u32 missingCount = CountMissingMegaStones();
    u32 selectedMissing;
    u32 seen = 0;
    u32 i;
    u16 receivedItem = ITEM_NONE;

    gSpecialVar_Result = 0;
    if (!MegaStoneHasTradableDuplicate(offeredItem) || missingCount == 0)
        return;

    selectedMissing = Random() % missingCount;
    for (i = 0; i < GetMegaStonePoolCount(); i++)
    {
        u16 candidate = GetMegaStoneFromPool(i);

        if (!PlayerOwnsMegaStone(candidate) && seen++ == selectedMissing)
        {
            receivedItem = candidate;
            break;
        }
    }
    if (receivedItem == ITEM_NONE || !RemoveBagItem(offeredItem, 1))
        return;

    if (AddBagItem(receivedItem, 1))
        gSpecialVar_Result = 1;
    else if (AddPCItem(receivedItem, 1))
        gSpecialVar_Result = 2;
    else
    {
        AddBagItem(offeredItem, 1);
        return;
    }

    RandomizerSetItemObtained(receivedItem);
    CopyItemName(offeredItem, gStringVar1);
    CopyItemName(receivedItem, gStringVar2);
}

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

bool32 GiftMonCanTrade(struct BoxPokemon *boxMon)
{
    u16 species;
    u32 otId;
    u8 metLocation;
    u8 metLevel;

    if (boxMon == NULL)
        return FALSE;

    species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    if (species == SPECIES_NONE || GetBoxMonData(boxMon, MON_DATA_IS_EGG))
        return FALSE;

    // Scripted gifts and in-game trades carry a persistent marker that does
    // not depend on their species, evolution, randomization or storage.
    if (GetBoxMonData(boxMon, MON_DATA_GIFT_ORIGIN))
        return TRUE;

    // Compatibility for gifts obtained before the marker was introduced.
    otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
    metLocation = GetBoxMonData(boxMon, MON_DATA_MET_LOCATION);
    metLevel = GetBoxMonData(boxMon, MON_DATA_MET_LEVEL);

    // 1. Kenya
    if (otId == 61225)
        return TRUE;

    // 2. Shuckie
    if (otId == 4336)
        return TRUE;

    // 3. Eevee de Bill
    if (otId == 5231)
        return TRUE;

    // 4. Tentacool de Ciudad Orquídea
    if (metLocation == MAPSEC_CIANWOOD_CITY && metLevel == 25)
        return TRUE;

    // 5. Tyrogue del Maestro Kiyo
    if (FlagGet(FLAG_GOT_TYROGUE))
    {
        if (metLocation == MAPSEC_MT_MORTAR && metLevel == 25)
            return TRUE;
    }

    // 6. Dratini de la Guarida Dragón
    if (FlagGet(FLAG_GOT_DRATINI))
    {
        if (metLocation == MAPSEC_DRAGONS_DEN && metLevel == 15)
            return TRUE;
    }

    // 7. Huevo de Togepi
    if (FlagGet(FLAG_RECEIVED_TOGEPI_EGG))
    {
        if (species == SPECIES_TOGEPI
         || species == SPECIES_TOGETIC
         || species == SPECIES_TOGEKISS)
        {
            if (metLocation == MAPSEC_VIOLET_CITY)
                return TRUE;
        }
    }

    return FALSE;
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
    ConvertIntToDecimalStringN(gStringVar1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, 2);
}


void GymTokenRecordFailedEncounter(u16 mapsec)
{
    u8 zone = NuzlockeGetZoneId(mapsec);
    if (IsGymTokenModeActive() && zone < NUZLOCKE_NUM_ZONES)
        *GetGymTokenFailedFlagByte(zone) |= 1 << (zone & 7);
}

void GymTokenClearEncounterState(u16 mapsec)
{
    u8 zone = NuzlockeGetZoneId(mapsec);
    if (zone < NUZLOCKE_NUM_ZONES)
    {
        u8 bit = 1 << (zone & 7);
        *GetGymTokenFailedFlagByte(zone) &= ~bit;
        *GetGymTokenRetriedFlagByte(zone) &= ~bit;
    }
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

static u16 GetFinalEvolutionSpecies(u16 species)
{
    u32 depth;
    u16 current = species;

    for (depth = 0; depth < 5; depth++)
    {
        const struct Evolution *evos = GetSpeciesEvolutions(current);
        u16 next = SPECIES_NONE;
        u32 i;

        if (evos == NULL || evos[0].method == EVOLUTIONS_END)
            break;

        for (i = 0; evos[i].method != EVOLUTIONS_END; i++)
        {
            u16 target = evos[i].targetSpecies;
            if (target != SPECIES_NONE && IsSpeciesEnabled(target)
             && !gSpeciesInfo[target].isMegaEvolution
             && !gSpeciesInfo[target].isPrimalReversion
             && !gSpeciesInfo[target].isUltraBurst)
            {
                next = target;
                break;
            }
        }

        if (next == SPECIES_NONE || next == current)
            break;

        current = next;
    }

    return current;
}

bool32 IsFossilSpecies(u16 species)
{
    u16 base = species;
    while (GetSpeciesPreEvolution(base) != SPECIES_NONE)
        base = GetSpeciesPreEvolution(base);

    switch (base)
    {
    case SPECIES_OMANYTE:
    case SPECIES_KABUTO:
    case SPECIES_AERODACTYL:
    case SPECIES_LILEEP:
    case SPECIES_ANORITH:
    case SPECIES_CRANIDOS:
    case SPECIES_SHIELDON:
    case SPECIES_TIRTOUGA:
    case SPECIES_ARCHEN:
    case SPECIES_TYRUNT:
    case SPECIES_AMAURA:
    case SPECIES_DRACOZOLT:
    case SPECIES_ARCTOZOLT:
    case SPECIES_DRACOVISH:
    case SPECIES_ARCTOVISH:
        return TRUE;
    default:
        return FALSE;
    }
}

u16 GetRandomSpeciesFossilSimilarFinalBst(u16 fossilSpecies)
{
    u16 finalFossil = GetFinalEvolutionSpecies(fossilSpecies);
    u16 targetFinalBst = GetBaseStatTotal(finalFossil);
    s32 minBst = (s32)targetFinalBst - ((s32)targetFinalBst * 10 / 100);
    s32 maxBst = (s32)targetFinalBst + ((s32)targetFinalBst * 10 / 100);
    u16 eligibleCount = 0;
    u16 selectedSpecies = fossilSpecies;
    u16 species;
    s32 maxDiff;

    if (fossilSpecies == SPECIES_NONE)
        return SPECIES_NONE;

    // First pass: exact ±10% range of the final evolution's BST
    for (species = 1; species < NUM_SPECIES; species++)
    {
        const struct SpeciesInfo *info = &gSpeciesInfo[species];
        u16 finalCandidate;
        s32 candidateFinalBst;

        if (!IsSpeciesEnabled(species) || GET_BASE_SPECIES_ID(species) != species)
            continue;
        if (info->isRestrictedLegendary || info->isSubLegendary
         || info->isMythical || info->isUltraBeast || info->isMegaEvolution
         || info->isPrimalReversion || info->isUltraBurst)
            continue;

        // Must be a base stage (first form of its line)
        if (GetSpeciesPreEvolution(species) != SPECIES_NONE)
            continue;

        finalCandidate = GetFinalEvolutionSpecies(species);
        candidateFinalBst = (s32)GetBaseStatTotal(finalCandidate);

        if (candidateFinalBst >= minBst && candidateFinalBst <= maxBst)
        {
            eligibleCount++;
            if (Random() % eligibleCount == 0)
                selectedSpecies = species;
        }
    }

    if (eligibleCount > 0)
        return selectedSpecies;

    // Fallback: widen BST gap if strict ±10% had 0 candidates
    for (maxDiff = 60; maxDiff <= 500; maxDiff += 40)
    {
        eligibleCount = 0;
        for (species = 1; species < NUM_SPECIES; species++)
        {
            const struct SpeciesInfo *info = &gSpeciesInfo[species];
            u16 finalCandidate;
            s32 diff;

            if (!IsSpeciesEnabled(species) || GET_BASE_SPECIES_ID(species) != species)
                continue;
            if (info->isRestrictedLegendary || info->isSubLegendary
             || info->isMythical || info->isUltraBeast || info->isMegaEvolution
             || info->isPrimalReversion || info->isUltraBurst)
                continue;

            if (GetSpeciesPreEvolution(species) != SPECIES_NONE)
                continue;

            finalCandidate = GetFinalEvolutionSpecies(species);
            diff = (s32)GetBaseStatTotal(finalCandidate) - (s32)targetFinalBst;
            if (diff < 0)
                diff = -diff;

            if (diff <= maxDiff)
            {
                eligibleCount++;
                if (Random() % eligibleCount == 0)
                    selectedSpecies = species;
            }
        }
        if (eligibleCount > 0)
            return selectedSpecies;
    }

    return selectedSpecies;
}

u16 GetRandomSpeciesSimilarBst(u16 baseSpecies)
{
    u16 targetBst = GetBaseStatTotal(baseSpecies);
    u16 selectedSpecies = baseSpecies;
    u16 eligibleCount = 0;
    u16 species;
    s32 maxDiff;

    if (baseSpecies == SPECIES_NONE)
        return SPECIES_NONE;

    // Iteratively widen the BST gap: ±40, ±80, ±120, then any
    for (maxDiff = 40; maxDiff <= 500; maxDiff += 40)
    {
        eligibleCount = 0;
        for (species = 1; species < NUM_SPECIES; species++)
        {
            const struct SpeciesInfo *info = &gSpeciesInfo[species];
            s32 diff;

            if (!IsSpeciesEnabled(species) || info->isRestrictedLegendary || info->isSubLegendary
             || info->isMythical || info->isUltraBeast || info->isMegaEvolution
             || info->isPrimalReversion || info->isUltraBurst)
                continue;

            diff = (s32)GetBaseStatTotal(species) - (s32)targetBst;
            if (diff < 0)
                diff = -diff;

            if (diff <= maxDiff)
            {
                eligibleCount++;
                if (Random() % eligibleCount == 0)
                    selectedSpecies = species;
            }
        }
        if (eligibleCount > 0)
            return selectedSpecies;
    }

    return selectedSpecies;
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

    ResetPcMonSelectionType();
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
    HnsLiveTelemetry_RecordMonEvent(HNS_LIVE_EVENT_GYM_TOKEN_TRADE, &received,
                                    GetBoxMonData(boxMon, MON_DATA_SPECIES));
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

    ResetPcMonSelectionType();
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
            NuzlockeGraveyard_RemoveMon(boxMon->personality, boxMon->otId);
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

void CheckPlayerHasGiftMon(void)
{
    u32 i;
    u8 box;

    gSpecialVar_Result = 0;

    // Check Party
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GiftMonCanTrade(&gPlayerParty[i].box))
        {
            gSpecialVar_Result = 1;
            return;
        }
    }

    // Check PC Boxes
    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            struct BoxPokemon *mon = GetBoxedMonPtr(box, i);
            if (GiftMonCanTrade(mon))
            {
                gSpecialVar_Result = 1;
                return;
            }
        }
    }
}

void UseGiftMonTrade(void)
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
    static const u8 sClerkName[] = _("REGALO");

    ResetPcMonSelectionType();
    gSpecialVar_Result = 0;

    if (!GiftMonCanTrade(boxMon))
        return;

    {
        u16 item = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
        {
            u16 noneItem = ITEM_NONE;
            AddBagItem(item, 1);
            SetBoxMonData(boxMon, MON_DATA_HELD_ITEM, &noneItem);
        }
    }

    species = GetRandomSpeciesSimilarBst(GetBoxMonData(boxMon, MON_DATA_SPECIES));
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

    CreateMonWithIVs(&received, species, level, Random32(), OTID_STRUCT_PRESET(0x47494654), USE_RANDOM_IVS);
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

#define POKEMITOS_BASE_WEEKS 6

u16 GetPokemitosElapsedSaturdays(void)
{
    struct SiiRtcInfo rtc;
    u16 baseDays, currentDays;

    RtcGetDateTime(&rtc);
    if (RtcCheckInfo(&rtc) != 0)
        return POKEMITOS_BASE_WEEKS;

    baseDays = ConvertDateToDayCount(26, 10, 10);
    currentDays = RtcGetDayCount(&rtc);

    if (currentDays < baseDays)
        return POKEMITOS_BASE_WEEKS;

    return 1 + ((currentDays - baseDays) / 7);
}

static u16 CountMonsCapturedInMapsec(u16 mapsec1, u16 mapsec2)
{
    u16 count = 0;
    u32 i;
    u8 box;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            if (GetMonData(mon, MON_DATA_MET_LEVEL) != 0 // Descartar eclosionados de huevo
             && !GetMonData(mon, MON_DATA_GIFT_ORIGIN))   // Descartar regalos
            {
                u16 loc = GetMonData(mon, MON_DATA_MET_LOCATION);
                if (loc == mapsec1 || (mapsec2 != 0 && loc == mapsec2))
                    count++;
            }
        }
    }

    if (gPokemonStoragePtr != NULL)
    {
        for (box = 0; box < TOTAL_BOXES_COUNT; box++)
        {
            for (i = 0; i < IN_BOX_COUNT; i++)
            {
                struct BoxPokemon *boxMon = &gPokemonStoragePtr->boxes[box][i];
                if (GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE && !GetBoxMonData(boxMon, MON_DATA_IS_EGG))
                {
                    if (GetBoxMonData(boxMon, MON_DATA_MET_LEVEL) != 0
                     && !GetBoxMonData(boxMon, MON_DATA_GIFT_ORIGIN))
                    {
                        u16 loc = GetBoxMonData(boxMon, MON_DATA_MET_LOCATION);
                        if (loc == mapsec1 || (mapsec2 != 0 && loc == mapsec2))
                            count++;
                    }
                }
            }
        }
    }

    return count;
}

static u16 GetCleanTicketCount(u16 varId, u16 caught, u16 quota)
{
    u16 cur = VarGet(varId);
    u16 maxAllowed = (quota > caught) ? (quota - caught) : 0;
    if (cur > maxAllowed)
    {
        cur = maxAllowed;
        VarSet(varId, cur);
    }
    return cur;
}

static u16 UpdateSingleTicketCategory(u16 varId, bool8 unlocked, u16 quota, u16 mapsec1, u16 mapsec2)
{
    u16 caught;
    u16 cur;
    u16 maxAllowed;
    u16 newTickets;

    if (!unlocked)
        return 0;

    caught = CountMonsCapturedInMapsec(mapsec1, mapsec2);
    cur = VarGet(varId);
    maxAllowed = (quota > caught) ? (quota - caught) : 0;

    if (cur > maxAllowed)
    {
        cur = maxAllowed;
        VarSet(varId, cur);
        return 0;
    }

    newTickets = maxAllowed - cur;
    if (newTickets > 0)
    {
        VarSet(varId, cur + newTickets);
    }
    return newTickets;
}

void CheckBugContestTickets(void)
{
    u16 weeks = GetPokemitosElapsedSaturdays();
    bool8 unlocked = FlagGet(FLAG_VISITED_GOLDENROD_CITY);
    if (unlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_BUG_CONTEST_TICKETS, TRUE, weeks, MAPSEC_NATIONAL_PARK, 0);
    u16 caught = CountMonsCapturedInMapsec(MAPSEC_NATIONAL_PARK, 0);
    gSpecialVar_Result = GetCleanTicketCount(VAR_POKEMITOS_BUG_CONTEST_TICKETS, caught, weeks);
}

void ConsumeBugContestTicket(void)
{
    u16 t = VarGet(VAR_POKEMITOS_BUG_CONTEST_TICKETS);
    if (t > 0)
        VarSet(VAR_POKEMITOS_BUG_CONTEST_TICKETS, t - 1);
    FlagClear(FLAG_BUG_CONTEST_COMPLETED);
}

void CheckSafariJohtoTickets(void)
{
    u16 weeks = GetPokemitosElapsedSaturdays();
    bool8 unlocked = FlagGet(FLAG_VISITED_CIANWOOD_CITY) || FlagGet(FLAG_VISITED_SAFARI_ZONE_GATE);
    if (unlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, TRUE, weeks, MAPSEC_SAFARI_ZONE, MAPSEC_SAFARI_ZONE_GATE);
    u16 caught = CountMonsCapturedInMapsec(MAPSEC_SAFARI_ZONE, MAPSEC_SAFARI_ZONE_GATE);
    gSpecialVar_Result = GetCleanTicketCount(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, caught, weeks);
}

void ConsumeSafariJohtoTicket(void)
{
    u16 t = VarGet(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS);
    if (t > 0)
        VarSet(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, t - 1);
    FlagClear(FLAG_SAFARI_ZONE_COMPLETED);
}

void CheckSafariKantoTickets(void)
{
    u16 weeks = GetPokemitosElapsedSaturdays();
    bool8 unlocked = FlagGet(FLAG_VISITED_FUCHSIA_CITY);
    if (unlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, TRUE, weeks, MAPSEC_KANTO_SAFARI_ZONE, MAPSEC_FUCHSIA_CITY);
    u16 caught = CountMonsCapturedInMapsec(MAPSEC_KANTO_SAFARI_ZONE, MAPSEC_FUCHSIA_CITY);
    gSpecialVar_Result = GetCleanTicketCount(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, caught, weeks);
}

void ConsumeSafariKantoTicket(void)
{
    u16 t = VarGet(VAR_POKEMITOS_SAFARI_KANTO_TICKETS);
    if (t > 0)
        VarSet(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, t - 1);
    FlagClear(FLAG_KANTO_SAFARI_ZONE_COMPLETED);
}

static void FormatAuditResult(u8 *dest, bool8 unlocked, u16 newTickets, u16 currentTickets, const u8 *blockNotice)
{
    u8 numBuf1[8];
    u8 numBuf2[8];

    if (!unlocked)
    {
        StringCopy(dest, blockNotice);
        return;
    }

    ConvertIntToDecimalStringN(numBuf1, newTickets, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(numBuf2, currentTickets, STR_CONV_MODE_LEFT_ALIGN, 2);

    if (newTickets > 0)
    {
        StringCopy(dest, (const u8[])_("+"));
        StringAppend(dest, numBuf1);
        StringAppend(dest, (const u8[])_(" ("));
        StringAppend(dest, numBuf2);
        StringAppend(dest, (const u8[])_(" en carnet)"));
    }
    else
    {
        StringCopy(dest, (const u8[])_("Al día ("));
        StringAppend(dest, numBuf2);
        StringAppend(dest, (const u8[])_(" en carnet)"));
    }
}

void UpdateAndClaimPokemitosTickets(void)
{
    u16 weeks = GetPokemitosElapsedSaturdays();
    u16 newBug = 0, newSafariJohto = 0, newSafariKanto = 0;
    bool8 bugUnlocked = FlagGet(FLAG_VISITED_GOLDENROD_CITY);
    bool8 safariJohtoUnlocked = FlagGet(FLAG_VISITED_CIANWOOD_CITY) || FlagGet(FLAG_VISITED_SAFARI_ZONE_GATE);
    bool8 safariKantoUnlocked = FlagGet(FLAG_VISITED_FUCHSIA_CITY);

    // 1. Concurso de Bichos (1 por semana)
    newBug = UpdateSingleTicketCategory(VAR_POKEMITOS_BUG_CONTEST_TICKETS, bugUnlocked, weeks, MAPSEC_NATIONAL_PARK, 0);

    // 2. Safari Johto (1 por semana)
    newSafariJohto = UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, safariJohtoUnlocked, weeks, MAPSEC_SAFARI_ZONE, MAPSEC_SAFARI_ZONE_GATE);

    // 3. Safari Kanto (1 por semana)
    newSafariKanto = UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, safariKantoUnlocked, weeks, MAPSEC_KANTO_SAFARI_ZONE, MAPSEC_FUCHSIA_CITY);

    FormatAuditResult(gStringVar1, bugUnlocked, newBug, VarGet(VAR_POKEMITOS_BUG_CONTEST_TICKETS), (const u8[])_("Bloqueado (Trigal)"));
    FormatAuditResult(gStringVar2, safariJohtoUnlocked, newSafariJohto, VarGet(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS), (const u8[])_("Bloqueado (Orquídea)"));
    FormatAuditResult(gStringVar3, safariKantoUnlocked, newSafariKanto, VarGet(VAR_POKEMITOS_SAFARI_KANTO_TICKETS), (const u8[])_("Bloqueado (Fucsia)"));

    gSpecialVar_Result = newBug + newSafariJohto + newSafariKanto;
}

static void FormatPassesLine(u8 *dest, u16 caught, bool8 unlocked, u16 tickets)
{
    u8 buf1[8];
    u8 buf2[8];

    ConvertIntToDecimalStringN(buf1, caught, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringCopy(dest, (const u8[])_("Capturas: "));
    StringAppend(dest, buf1);
    StringAppend(dest, (const u8[])_("\lPases: "));

    if (unlocked)
    {
        ConvertIntToDecimalStringN(buf2, tickets, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(dest, buf2);
    }
    else
    {
        StringAppend(dest, (const u8[])_("Bloqueado"));
    }
}

void BufferPokemitosTicketsSummary(void)
{
    u16 weeks = GetPokemitosElapsedSaturdays();
    u16 caught;
    u16 tickets;
    bool8 bugUnlocked = FlagGet(FLAG_VISITED_GOLDENROD_CITY);
    bool8 johtoUnlocked = FlagGet(FLAG_VISITED_CIANWOOD_CITY) || FlagGet(FLAG_VISITED_SAFARI_ZONE_GATE);
    bool8 kantoUnlocked = FlagGet(FLAG_VISITED_FUCHSIA_CITY);

    // Bichos
    if (bugUnlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_BUG_CONTEST_TICKETS, TRUE, weeks, MAPSEC_NATIONAL_PARK, 0);
    caught = CountMonsCapturedInMapsec(MAPSEC_NATIONAL_PARK, 0);
    tickets = GetCleanTicketCount(VAR_POKEMITOS_BUG_CONTEST_TICKETS, caught, weeks);
    FormatPassesLine(gStringVar1, caught, bugUnlocked, tickets);

    // Safari Johto
    if (johtoUnlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, TRUE, weeks, MAPSEC_SAFARI_ZONE, MAPSEC_SAFARI_ZONE_GATE);
    caught = CountMonsCapturedInMapsec(MAPSEC_SAFARI_ZONE, MAPSEC_SAFARI_ZONE_GATE);
    tickets = GetCleanTicketCount(VAR_POKEMITOS_SAFARI_JOHTO_TICKETS, caught, weeks);
    FormatPassesLine(gStringVar2, caught, johtoUnlocked, tickets);

    // Safari Kanto
    if (kantoUnlocked)
        UpdateSingleTicketCategory(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, TRUE, weeks, MAPSEC_KANTO_SAFARI_ZONE, MAPSEC_FUCHSIA_CITY);
    caught = CountMonsCapturedInMapsec(MAPSEC_KANTO_SAFARI_ZONE, MAPSEC_FUCHSIA_CITY);
    tickets = GetCleanTicketCount(VAR_POKEMITOS_SAFARI_KANTO_TICKETS, caught, weeks);
    FormatPassesLine(gStringVar3, caught, kantoUnlocked, tickets);
}

void BufferPokemitosStatusSummary(void)
{
    u8 tokenCount = gSaveBlock3Ptr->gymTokens.count;
    u16 badgeCount = VarGet(VAR_NUM_BADGES);
    u16 weeks = GetPokemitosElapsedSaturdays();

    ConvertIntToDecimalStringN(gStringVar1, tokenCount, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, badgeCount, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, weeks, STR_CONV_MODE_LEFT_ALIGN, 2);
}
