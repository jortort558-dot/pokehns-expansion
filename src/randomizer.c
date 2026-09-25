#include "randomizer.h"

#if RANDOMIZER_AVAILABLE
#include "main.h"
#include "new_game.h"
#include "item.h"
#include "event_data.h"
#include "constants/flags.h"
#include "field_control_avatar.h"
#include "pokemon.h"
#include "script.h"
#include "data.h"
#include "data/randomizer/special_form_tables.h"
#include "constants/abilities.h"
#include "constants/pokedex.h"
#include "data/randomizer/ability_whitelist.h"
#include "move.h"
#include "nuzlocke.h"
#include "constants/opponents.h"
#include "constants/trainers.h"
#include "difficulty.h"

const u16 gStarterAndGiftMonTable[STARTER_AND_GIFT_MON_COUNT] =
{
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_CHIKORITA,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_BELDUM,
    SPECIES_CASTFORM_NORMAL,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
};

const u16 gEggMonTable[EGG_MON_COUNT] =
{
    SPECIES_WYNAUT,
};

static const u16 sPreevolutionBabyMons[] =
{
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TYROGUE,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_AZURILL,
    SPECIES_WYNAUT,
    SPECIES_BUDEW,
    SPECIES_CHINGLING,
    SPECIES_BONSLY,
    SPECIES_MIME_JR,
    SPECIES_HAPPINY,
    SPECIES_MUNCHLAX,
    SPECIES_MANTYKE,
};

bool32 RandomizerFeatureEnabled(enum RandomizerFeature feature)
{
    struct ChallengeSettings *settings = &gSaveBlock3Ptr->challengeSettings;

    switch(feature)
    {
        case RANDOMIZE_WILD_MON:
            #ifdef FORCE_RANDOMIZE_WILD_MON
                return FORCE_RANDOMIZE_WILD_MON;
            #else
                return settings->tx_Random_WildPokemon;
            #endif
        case RANDOMIZE_FIELD_ITEMS:
            #ifdef FORCE_RANDOMIZE_FIELD_ITEMS
                return FORCE_RANDOMIZE_FIELD_ITEMS;
            #else
                return settings->tx_Random_Items && FlagGet(FLAG_RECEIVED_FIRST_BALLS);
            #endif
        case RANDOMIZE_TRAINER_MON:
            #ifdef FORCE_RANDOMIZE_TRAINER_MON
                return FORCE_RANDOMIZE_TRAINER_MON;
            #else
                return settings->tx_Random_Trainer;
            #endif
        case RANDOMIZE_FIXED_MON:
            #ifdef FORCE_RANDOMIZE_FIXED_MON
                return FORCE_RANDOMIZE_FIXED_MON;
            #else
                return settings->tx_Random_Static;
            #endif
        case RANDOMIZE_STARTER_AND_GIFT_MON:
            #ifdef FORCE_RANDOMIZE_STARTER_AND_GIFT_MON
                return FORCE_RANDOMIZE_STARTER_AND_GIFT_MON;
            #else
                return settings->tx_Random_Starter;
            #endif
        case RANDOMIZE_ABILITIES:
            #ifdef FORCE_RANDOMIZE_ABILITIES
                return FORCE_RANDOMIZE_ABILITIES;
            #else
                return settings->tx_Random_Abilities;
            #endif
        case RANDOMIZE_MON_TYPES:
            #ifdef FORCE_RANDOMIZE_MON_TYPES
                return FORCE_RANDOMIZE_MON_TYPES;
            #else
                return settings->tx_Random_Type;
            #endif
        case RANDOMIZE_LEARNSET:
            #ifdef FORCE_RANDOMIZE_LEARNSET
                return FORCE_RANDOMIZE_LEARNSET;
            #else
                return settings->tx_Random_Moves;
            #endif
        case RANDOMIZE_EVOLUTIONS:
            #ifdef FORCE_RANDOMIZE_EVOLUTIONS
                return FORCE_RANDOMIZE_EVOLUTIONS;
            #else
                return settings->tx_Random_Evolutions;
            #endif
        case RANDOMIZE_EVO_METHODS:
            #ifdef FORCE_RANDOMIZE_EVO_METHODS
                return FORCE_RANDOMIZE_EVO_METHODS;
            #else
                return settings->tx_Random_EvolutionMethods;
            #endif
        case RANDOMIZE_TYPE_EFFECTIVENESS:
            #ifdef FORCE_RANDOMIZE_TYPE_EFFECTIVENESS
                return FORCE_RANDOMIZE_TYPE_EFFECTIVENESS;
            #else
                return settings->tx_Random_TypeEffectiveness;
            #endif
        case RANDOMIZE_EGG_MON:
            #ifdef FORCE_RANDOMIZE_EGG_MON
                return FORCE_RANDOMIZE_EGG_MON;
            #else
                return settings->tx_Random_Static;
            #endif
        default:
            return FALSE;
    }
}

static inline bool32 IsChaosMode(void)
{
    return gSaveBlock3Ptr->challengeSettings.tx_Random_Chaos;
}

bool8 IsRandomMovesActivated(void)
{
    return gSaveBlock3Ptr->challengeSettings.tx_Random_Moves;
}

u32 GetRandomizerSeed(void)
{
    #if RANDOMIZER_SEED_IS_TRAINER_ID
        return GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    #else
        u32 result;
        result = ((u32)VarGet(RANDOMIZER_VAR_SEED_H) << 16) | VarGet(RANDOMIZER_VAR_SEED_L);
        return result;
    #endif
}

bool32 SetRandomizerSeed(u32 newSeed)
{
    #if RANDOMIZER_SEED_IS_TRAINER_ID
        return FALSE;
    #else
        VarSet(RANDOMIZER_VAR_SEED_L, (u16)newSeed);
        VarSet(RANDOMIZER_VAR_SEED_H, (u16)(newSeed >> 16));
        return TRUE;
    #endif
}

// Gen scope filter. When tx_Random_GenScope is set, the randomizer may only roll
// species belonging to a Gen 1-3 family: anything with a Gen 1-3 National Dex
// number, plus every form and every evolution reachable from one. That picks up
// the cross-gen evolutions (Sylveon, Weavile, Magnezone, Mamoswine, Annihilape,
// Clodsire...), the cross-gen pre-evolutions (Munchlax, Happiny, Mantyke...) and
// the regional forms listed in this game's obtainable Dex together with their
// evolutions (Perrserker, Obstagoon, Sneasler, Cursola), and — via the backward
// sweep below — the
// cross-gen pre-evolutions whose own Dex number is later than the family they
// evolve into (Munchlax, Happiny, Mantyke, Budew, Chingling, Bonsly, Mime Jr.).
// Families that merely start in a later gen stay out (Kingambit off Pawniard,
// Basculegion off Basculin).
#define GEN_SCOPE_MASK_WORDS ((RANDOMIZER_SPECIES_COUNT + 31) / 32)

// Regional forms carry their own National Dex numbers in this build
// (P_SEPARATE_REGIONAL_FORMS), so a Gen 1-3 counterpart does not drag them in.
// They are seeded separately, gated on the obtainable Dex so only forms this
// game actually offers join the pool.
static inline bool32 IsRegionalForm(u16 species)
{
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[species];
    return speciesInfo->isAlolanForm
        || speciesInfo->isGalarianForm
        || speciesInfo->isHisuianForm
        || speciesInfo->isPaldeanForm;
}

// Only defined when the species tables are built at runtime; the family walk
// wants the same depth bound either way.
#ifndef RANDOMIZER_MAX_EVO_STAGES
#define RANDOMIZER_MAX_EVO_STAGES 5
#endif

EWRAM_DATA static u32 sGenScopeMask[GEN_SCOPE_MASK_WORDS] = {0};
EWRAM_DATA static bool8 sGenScopeMaskInitialized = FALSE;

static inline bool32 GenScopeMaskGet(u16 species)
{
    return (sGenScopeMask[species / 32] & (1u << (species & 31))) != 0;
}

// Marks species and everything downstream of it. Never calls IsSpeciesPermitted:
// that would re-enter the mask build. The already-marked check both keeps this
// linear and terminates any evolution cycle.
static void MarkGenScopeFamily(u16 species, u32 stage)
{
    const struct Evolution *evos;
    const u16 *forms;
    u32 i;

    if (species == SPECIES_NONE || species >= RANDOMIZER_SPECIES_COUNT)
        return;
    if (stage > RANDOMIZER_MAX_EVO_STAGES)
        return;
    if (GenScopeMaskGet(species))
        return;
    // GetSpeciesEvolutions() sanitizes its argument and asserts on species that
    // are disabled in this build, so never walk into one. Enabled-but-not-
    // randomizable species (megas and the like) still propagate the family:
    // IsSpeciesPermitted keeps them out of the pool on its own.
    if (!IsSpeciesEnabled(species))
        return;

    sGenScopeMask[species / 32] |= 1u << (species & 31);

    forms = gSpeciesInfo[species].formSpeciesIdTable;
    if (forms != NULL)
    {
        for (i = 0; forms[i] != FORM_SPECIES_END; i++)
            MarkGenScopeFamily(forms[i], stage);
    }

    evos = GetSpeciesEvolutions(species);
    if (evos != NULL)
    {
        for (i = 0; evos[i].method != 0xFFFF; i++)
            MarkGenScopeFamily(evos[i].targetSpecies, stage + 1);
    }
}

static void BuildGenScopeMask(void)
{
    u16 i;
    bool32 changed;

    memset(sGenScopeMask, 0, sizeof(sGenScopeMask));

    for (i = 1; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        u32 natDexNum = gSpeciesInfo[i].natDexNum;
        if (natDexNum != NATIONAL_DEX_NONE && natDexNum <= NATIONAL_DEX_DEOXYS)
        {
            MarkGenScopeFamily(i, 0);
        }
        // The flag test comes first on purpose: SpeciesToObtainablePokedexNum
        // linearly scans the obtainable Dex, so this must not run per species.
        else if (IsRegionalForm(i) && SpeciesToObtainablePokedexNum(i) != 0)
        {
            MarkGenScopeFamily(i, 0);
        }
    }

    // The walk above only follows evolutions forwards, so it never reaches a
    // pre-evolution that was introduced after the family it evolves into --
    // Munchlax has a Gen 4 Dex number but belongs to Snorlax's family. Sweep
    // backwards to a fixed point: anything evolving into a marked species joins
    // it, along with its own forms and evolutions.
    do
    {
        changed = FALSE;
        for (i = 1; i < RANDOMIZER_SPECIES_COUNT; i++)
        {
            const struct Evolution *evos;
            u32 j;

            if (GenScopeMaskGet(i) || !IsSpeciesEnabled(i))
                continue;

            evos = GetSpeciesEvolutions(i);
            if (evos == NULL)
                continue;

            for (j = 0; evos[j].method != 0xFFFF; j++)
            {
                u16 target = evos[j].targetSpecies;
                if (target < RANDOMIZER_SPECIES_COUNT && GenScopeMaskGet(target))
                {
                    MarkGenScopeFamily(i, 0);
                    changed = TRUE;
                    break;
                }
            }
        }
    } while (changed);

    sGenScopeMaskInitialized = TRUE;
}

static inline bool32 IsGenScopeRestricted(void)
{
    return gSaveBlock3Ptr->challengeSettings.tx_Random_GenScope;
}

bool32 IsSpeciesInGenScope(u16 species)
{
    if (!IsGenScopeRestricted())
        return TRUE;
    if (species >= RANDOMIZER_SPECIES_COUNT)
        return FALSE;
    if (!sGenScopeMaskInitialized)
        BuildGenScopeMask();

    return GenScopeMaskGet(species);
}

// Whether a species can take part in randomization at all. Gates the species
// being *replaced*, so it deliberately ignores the gen scope: a Noivern in a
// trainer party still gets randomized when the pool is restricted to Gen 1-3.
static bool32 IsSpeciesValidForRandomizer(u16 species)
{
    if (species == SPECIES_NONE)
        return FALSE;
    if (gSpeciesInfo[species].baseHP == 0)
        return FALSE;
    if (gSpeciesInfo[species].randomizerMode == MON_RANDOMIZER_INVALID)
        return FALSE;

    return TRUE;
}

// Whether a species may be *produced* by randomization. Everything the
// randomizer can roll has to pass this, so the gen scope applies here.
static bool32 IsSpeciesPermitted(u16 species)
{
    return IsSpeciesValidForRandomizer(species) && IsSpeciesInGenScope(species);
};

u32 GenerateSeedForRandomizer(void)
{
    u32 data;
    const u32 vblankCounter = gMain.vblankCounter1;
    #if HQ_RANDOM == TRUE
        data = Random32();
    #else
        data = _SFC32_Next(&gRngValue);
    #endif
    return data ^ vblankCounter;
}

u16 GetRandomizerOption(enum RandomizerOption option)
{
    switch(option) {
        case RANDOMIZER_OPTION_SPECIES_MODE:
        {
            struct ChallengeSettings *settings = &gSaveBlock3Ptr->challengeSettings;
            if (settings->tx_Random_Similar)
                return MON_EVOLUTION;
            if (settings->tx_Random_IncludeLegendaries)
                return MON_RANDOM;
            return MON_RANDOM_LEGEND_AWARE;
        }
        default:
            return 0;
    }
}

struct Sfc32State RandomizerRandSeed(enum RandomizerReason reason, u32 data1, u32 data2)
{
    struct Sfc32State state;
    u32 i;

    if (IsChaosMode() && reason != RANDOMIZER_REASON_ABILITIES)
    {
        state.a = Random32();
        state.b = Random32();
        state.c = Random32();
        state.ctr = RANDOMIZER_STREAM;

        for (i = 0; i < 10; i++)
            _SFC32_Next_Stream(&state, RANDOMIZER_STREAM);

        return state;
    }

    {
        const u32 randomizerSeed = GetRandomizerSeed();
        state.a = randomizerSeed + (u32)reason;
        state.b = randomizerSeed ^ data2;
        state.c = data1;
        state.ctr = RANDOMIZER_STREAM;

        for (i = 0; i < 10; i++)
            _SFC32_Next_Stream(&state, RANDOMIZER_STREAM);
    }

    return state;
}


u32 RandomizerNextRange(struct Sfc32State* state, u32 range)
{
    u32 next_power_of_two, mask, result;
    if (range < 2)
        return 0;
    else if (range == UINT32_MAX)
        return _SFC32_Next_Stream(state, RANDOMIZER_STREAM);

    next_power_of_two = range;
    --next_power_of_two;
    next_power_of_two |= next_power_of_two >> 1;
    next_power_of_two |= next_power_of_two >> 2;
    next_power_of_two |= next_power_of_two >> 4;
    next_power_of_two |= next_power_of_two >> 8;
    ++next_power_of_two;

    mask = next_power_of_two - 1;

    do
    {
        result = _SFC32_Next_Stream(state, RANDOMIZER_STREAM) & mask;
    } while (result >= range);

    return result;
}

u16 RandomizerRand(enum RandomizerReason reason, u32 data1, u32 data2)
{
    struct Sfc32State state;
    state = RandomizerRandSeed(reason, data1, data2);
    return RandomizerNext(&state);
}

u16 RandomizerRandRange(enum RandomizerReason reason, u32 data1, u32 data2, u16 range)
{
    struct Sfc32State state;
    state = RandomizerRandSeed(reason, data1, data2);
    return RandomizerNextRange(&state, range);
}

static inline bool32 IsItemTMHM(u16 itemId)
{
    return gItemsInfo[itemId].pocket == POCKET_TM_HM;
}

static inline bool32 IsKeyItem(u16 itemId)
{
    return gItemsInfo[itemId].pocket == POCKET_KEY_ITEMS;
}

static inline bool32 ShouldRandomizeItem(u16 itemId)
{
    // ITEM_GS_BALL sits in POCKET_POKE_BALLS rather than POCKET_KEY_ITEMS, so the key-item
    // check below doesn't cover it. It gates Kurt's Celebi chain (checkitem/removeitem in
    // AzaleaTown_KurtsHouse_hns), so rolling it into something else softlocks that quest.
    // Keep every TM/HM in its original location. Randomizing TMs independently
    // can create duplicates and make some moves unobtainable in a playthrough.
    return !(IsItemTMHM(itemId) || IsKeyItem(itemId) || itemId == ITEM_GS_BALL || itemId == ITEM_NONE);
}

#include "data/randomizer/item_tiers.h"

u16 GetRandomizedTM(u16 tmId)
{
    u8 permutation[100];
    u32 i;
    struct Sfc32State state;

    if (tmId < ITEM_TM01 || tmId > ITEM_TM100)
        return tmId;

    // Si el shuffle de MTs está desactivado (1 = NO), devolver la MT original
    if (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_TMShuffle != 0)
        return tmId;

    state = RandomizerRandSeed(RANDOMIZER_REASON_FIELD_ITEM, 0x544D5348 /* "TMSH" */, 0x9E3779B9);
    for (i = 0; i < 100; i++)
        permutation[i] = (u8)i;

    // Fisher-Yates shuffle determinista según la seed
    for (i = 99; i > 0; i--)
    {
        u32 j = RandomizerNextRange(&state, i + 1);
        u8 temp = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = temp;
    }

    return ITEM_TM01 + permutation[tmId - ITEM_TM01];
}

u16 GetRandomizedFieldItem(u16 originalItem, u8 mapGroup, u8 mapNum, u8 localId)
{
    struct Sfc32State state;
    u32 mapSeed;
    u32 roll;
    enum ItemProgressionTier progTier;
    u16 wT1, wT2, wT3, wT4, wT5;
    u16 totalWeight;

    if (originalItem == ITEM_NONE)
        return ITEM_NONE;

    // MTs: barajadas si el shuffle de MTs está activo
    if (originalItem >= ITEM_TM01 && originalItem <= ITEM_TM100)
        return GetRandomizedTM(originalItem);

    // HMs y Objetos Clave / Historia: NUNCA se tocan
    if ((originalItem >= ITEM_HM01 && originalItem <= ITEM_HM08)
     || IsKeyItem(originalItem)
     || originalItem == ITEM_GS_BALL)
    {
        return originalItem;
    }

    // Hash determinista: semilla + grupo mapa + num mapa + id local
    mapSeed = (((u32)mapGroup) << 24) | (((u32)mapNum) << 16) | (((u32)localId) << 8);
    mapSeed ^= (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_Progression << 3)
             | (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_MegaStones << 2)
             | (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_Competitive);

    state = RandomizerRandSeed(RANDOMIZER_REASON_FIELD_ITEM, mapSeed, originalItem);

    progTier = GetMapProgressionTier(mapGroup, mapNum);

    // 1. MEGAPIEDRAS (Pool Separada)
    // Solo post-Lago de la Furia si la opción está en POST-LAGO (0)
    if (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_MegaStones == 0
        && IsLocationPostLakeOfRage(mapGroup, mapNum))
    {
        u32 megaRate;
        if (progTier == ITEM_PROG_POSTGAME)
            megaRate = 120; // 12% en Kanto / Postgame
        else
            megaRate = 100; // 10% en Mid (Lago/Rocket) y Late game

        if (RandomizerNextRange(&state, 1000) < megaRate)
        {
            u32 megaIndex = RandomizerNextRange(&state, ARRAY_COUNT(sMegaStonesPool));
            return sMegaStonesPool[megaIndex];
        }
    }

    // 2. TABLA DE PESOS DE TIERS SEGÚN PROGRESIÓN (O MODO CAÓTICO)
    if (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_Progression != 0)
    {
        // Modo CAÓTICO: distribución plana uniforme
        wT1 = 250;
        wT2 = 250;
        wT3 = 250;
        wT4 = 250;
        wT5 = (progTier >= ITEM_PROG_LATE) ? 5 : 0;
    }
    else
    {
        // Curva de progresión ACTIVADA (items.md)
        switch (progTier)
        {
        case ITEM_PROG_EARLY:
            wT1 = 600; wT2 = 300; wT3 = 90;  wT4 = 10;  wT5 = 0;
            break;
        case ITEM_PROG_EARLY_MID:
            wT1 = 450; wT2 = 320; wT3 = 180; wT4 = 50;  wT5 = 0;
            break;
        case ITEM_PROG_MID:
            wT1 = 300; wT2 = 320; wT3 = 250; wT4 = 120; wT5 = 0;
            break;
        case ITEM_PROG_LATE:
            wT1 = 180; wT2 = 270; wT3 = 300; wT4 = 245; wT5 = 5; // 0.5% Master Ball
            break;
        case ITEM_PROG_POSTGAME:
        default:
            wT1 = 100; wT2 = 200; wT3 = 300; wT4 = 390; wT5 = 10; // 1.0% Master Ball
            break;
        }
    }

    // Modificador de Objetos Competitivos (T4):
    // 0 = NORMAL, 1 = ABUNDANTE (+100 = +10%), 2 = OFF
    if (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_Competitive == 1)
    {
        wT4 += 100;
        if (wT1 >= 50) wT1 -= 50;
        if (wT2 >= 50) wT2 -= 50;
    }
    else if (gSaveBlock3Ptr->challengeSettings.tx_Random_Items_Competitive == 2)
    {
        wT3 += wT4;
        wT4 = 0;
    }

    totalWeight = wT1 + wT2 + wT3 + wT4 + wT5;
    roll = RandomizerNextRange(&state, totalWeight);

    // 3. ELECCIÓN DE OBJETO DENTRO DEL TIER SELECCIONADO
    if (roll < wT1)
        return sItemTier1[RandomizerNextRange(&state, ARRAY_COUNT(sItemTier1))];
    roll -= wT1;

    if (roll < wT2)
        return sItemTier2[RandomizerNextRange(&state, ARRAY_COUNT(sItemTier2))];
    roll -= wT2;

    if (roll < wT3)
        return sItemTier3[RandomizerNextRange(&state, ARRAY_COUNT(sItemTier3))];
    roll -= wT3;

    if (roll < wT4)
        return sItemTier4[RandomizerNextRange(&state, ARRAY_COUNT(sItemTier4))];

    return sItemTier5[0];
}

u16 RandomizeFoundItem(u16 itemId, u8 mapNum, u8 mapGroup, u8 localId)
{
    return GetRandomizedFieldItem(itemId, mapGroup, mapNum, localId);
}

static inline void RandomizeFoundItemScript(u16 *scriptVar)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_FIELD_ITEMS))
    {
        u8 objEvent = gSelectedObjectEvent;
        *scriptVar = GetRandomizedFieldItem(
            *scriptVar,
            gObjectEvents[objEvent].mapGroup,
            gObjectEvents[objEvent].mapNum,
            gObjectEvents[objEvent].localId);
    }
}

void FindItemRandomize_NativeCall(struct ScriptContext *ctx)
{
    RandomizeFoundItemScript(&gSpecialVar_0x8000);
}

void FindHiddenItemRandomize_NativeCall(struct ScriptContext *ctx)
{
    RandomizeFoundItemScript(&gSpecialVar_0x8005);
}

// Items entregados por NPCs (STD_OBTAIN_ITEM / giveitem).
// Según items.md: Regalos ordinarios de NPCs permanecen VANILLA.
// Únicamente las MTs entregadas por líderes y entrenadores entran en el shuffle de MTs.
void ObtainItemRandomize_NativeCall(struct ScriptContext *ctx)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_FIELD_ITEMS))
    {
        if (gSpecialVar_0x8000 >= ITEM_TM01 && gSpecialVar_0x8000 <= ITEM_TM100)
        {
            gSpecialVar_0x8000 = GetRandomizedTM(gSpecialVar_0x8000);
        }
    }
}

static inline bool32 IsRandomizerLegendary(u16 species)
{
    return gSpeciesInfo[species].isRestrictedLegendary
        || gSpeciesInfo[species].isSubLegendary
        || gSpeciesInfo[species].isMythical
        || gSpeciesInfo[species].isUltraBeast;
}

struct SpeciesTable
{
    u16 groupData[RANDOMIZER_SPECIES_COUNT];
    u16 speciesToGroupIndex[RANDOMIZER_SPECIES_COUNT];
    u16 groupIndexToSpecies[RANDOMIZER_SPECIES_COUNT];
};

#define GROUP_INVALID   0xFFFF

static inline u16 GetSpeciesGroup(const struct SpeciesTable* table, u16 species)
{
    return table->groupData[table->speciesToGroupIndex[species]];
}

static void GetGroupRange(u16 group, enum RandomizerSpeciesMode mode, u16 *resultMin, u16 *resultMax)
{
    if (group == GROUP_INVALID)
    {
        *resultMax = *resultMin = group;
        return;
    }

    if (mode == MON_RANDOM_BST)
    {
        s32 base, minScaled, maxScaled;
        base = group * 1024;
        minScaled = (base - group * 100) / 1024;
        maxScaled = (base + group * 100) / 1024;
        *resultMin = (u16)max(minScaled, 0);
        *resultMax =(u16)min(maxScaled, GROUP_INVALID-1);
    }
    else
    {
        *resultMax = *resultMin = group;
    }
}

static void GetIndicesFromGroupRange(const struct SpeciesTable *table, u16 minGroup, u16 maxGroup, u16 *start, u16 *end)
{
    u16 index, leftBound, rightBound, maxRightBound;
    maxRightBound = RANDOMIZER_SPECIES_COUNT-1;
    maxGroup = min(0xFFFEu, maxGroup);
    minGroup = min(0xFFFEu, minGroup);
    leftBound = 0;
    rightBound = RANDOMIZER_SPECIES_COUNT-1;
    while (leftBound < rightBound)
    {
        u16 leftFoundGroup;
        index = (leftBound + rightBound) / 2;
        leftFoundGroup = table->groupData[index];
        if (leftFoundGroup < minGroup)
            leftBound = index + 1;
        else
        {
            if (leftFoundGroup > maxGroup)
                maxRightBound = index;
            rightBound = index;
        }
    }
    *start = leftBound;

    rightBound = maxRightBound;

    while (leftBound < rightBound)
    {
        index = (leftBound + rightBound) / 2;
        if (table->groupData[index] > maxGroup)
            rightBound = index;
        else
            leftBound = index + 1;
    }
    *end = rightBound - 1;
}

#if RANDOMIZER_DYNAMIC_SPECIES

struct RamSpeciesTable
{
    enum RandomizerSpeciesMode mode;
    bool8 tableInitialized;
    bool8 genScopeRestricted;
    struct SpeciesTable speciesTable;
};

EWRAM_DATA static struct RamSpeciesTable sRamSpeciesTable = {0};

static void FillSpeciesGroupsRandom(struct SpeciesTable* entries)
{
    u16 i;
    for (i = 0; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        entries->groupIndexToSpecies[i] = i;
        if (IsSpeciesPermitted(i))
            entries->groupData[i] = 0;
        else
            entries->groupData[i] = GROUP_INVALID;
    }
}

static void FillSpeciesGroupsBST(struct SpeciesTable* entries)
{
    u16 i;
    for(i = 0; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        const struct SpeciesInfo *curSpeciesInfo;
        u16 group;

        entries->groupIndexToSpecies[i] = i;

        if (IsSpeciesPermitted(i))
        {
            curSpeciesInfo = &gSpeciesInfo[i];

            group = curSpeciesInfo->baseAttack;
            group += curSpeciesInfo->baseDefense;
            group += curSpeciesInfo->baseSpAttack;
            group += curSpeciesInfo->baseSpDefense;
            group += curSpeciesInfo->baseHP;
            group += curSpeciesInfo->baseSpeed;

        }
        else
            group = GROUP_INVALID;

        entries->groupData[i] = group;
    }
}

static void FillSpeciesGroupsLegendary(struct SpeciesTable* entries)
{
    u16 i;
    for(i = 0; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        entries->groupIndexToSpecies[i] = i;
        if (!IsSpeciesPermitted(i))
            entries->groupData[i] = GROUP_INVALID;
        else
            entries->groupData[i] = IsRandomizerLegendary(i);
    }
}

static void MarkEvolutions(struct SpeciesTable *entries, u16 species, u16 stage)
{
    const struct Evolution *evos;
    if (stage == RANDOMIZER_MAX_EVO_STAGES)
        return;

    if (!IsSpeciesPermitted(species))
    {
        entries->groupIndexToSpecies[species] = species;
        entries->groupData[species] = GROUP_INVALID;
        return;
    }

    evos = GetSpeciesEvolutions(species);
    if (evos != NULL)
    {
        u32 i;
        for (i = 0; evos[i].method != 0xFFFF; i++)
        {
            if(entries->groupData[species] <= stage)
                MarkEvolutions(entries, evos[i].targetSpecies, stage+1);
        }
    }
    entries->groupIndexToSpecies[species] = species;
    entries->groupData[species] = stage;
}

static void FillSpeciesGroupsEvolution(struct SpeciesTable* entries)
{
    u16 i;
    static const u8 EVO_GROUP_LEGENDARY = 0x81;
    static const u8 EVO_GROUP_NO_EVO = RANDOMIZER_MAX_EVO_STAGES+1;

    memset(entries, 0, sizeof(sRamSpeciesTable.speciesTable));

    for (i = 0; i < ARRAY_COUNT(sPreevolutionBabyMons); i++)
    {
        u16 babyMonIndex = sPreevolutionBabyMons[i];
        entries->groupIndexToSpecies[babyMonIndex] = babyMonIndex;
        if(IsSpeciesPermitted(babyMonIndex))
            entries->groupData[babyMonIndex] = 0;
        else
            entries->groupData[babyMonIndex] = GROUP_INVALID;
    }

    for(i = 0; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        if (entries->groupIndexToSpecies[i] == 0)
        {
            entries->groupIndexToSpecies[i] = i;
            if (!IsSpeciesPermitted(i))
                entries->groupData[i] = GROUP_INVALID;
            else if (IsRandomizerLegendary(i))
                entries->groupData[i] = EVO_GROUP_LEGENDARY;
            else
            {
                const struct Evolution *evos = GetSpeciesEvolutions(i);
                if (evos == NULL || evos->method == 0xFFFF)
                    entries->groupData[i] = EVO_GROUP_NO_EVO;
                else
                    MarkEvolutions(entries, i, 0);
            }
        }
    }
}

static inline u16 LeftChildIndex(u16 index)
{
    return 2*index + 1;
}

static inline void SwapSpeciesAndGroup(struct SpeciesTable* table, u16 indexA, u16 indexB)
{
    u16 temp;
    SWAP(table->groupData[indexA], table->groupData[indexB], temp);
    SWAP(table->groupIndexToSpecies[indexA], table->groupIndexToSpecies[indexB], temp);
}

static void BuildRandomizerSpeciesTable(enum RandomizerSpeciesMode mode)
{
    u16 i, start, end;
    struct SpeciesTable* speciesTable;

    sRamSpeciesTable.tableInitialized = TRUE;
    sRamSpeciesTable.mode = mode;
    sRamSpeciesTable.genScopeRestricted = IsGenScopeRestricted();
    speciesTable = &sRamSpeciesTable.speciesTable;

    switch(mode)
    {
        case MON_RANDOM_LEGEND_AWARE:
            FillSpeciesGroupsLegendary(speciesTable);
            break;
        case MON_RANDOM_BST:
            FillSpeciesGroupsBST(speciesTable);
            break;
        case MON_EVOLUTION:
            FillSpeciesGroupsEvolution(speciesTable);
            break;
        case MON_RANDOM:
        default:
            FillSpeciesGroupsRandom(speciesTable);
    }

    start = RANDOMIZER_SPECIES_COUNT/2;
    end = RANDOMIZER_SPECIES_COUNT;

    while (end > 1)
    {
        u16 root;
        if (start > 0)
            start = start - 1;
        else
        {
            end = end - 1;
            SwapSpeciesAndGroup(speciesTable, end, 0);
        }
        root = start;
        while(LeftChildIndex(root) < end)
        {
            u16 child;
            child = LeftChildIndex(root);

            if (child+1 < end
                && speciesTable->groupData[child] < speciesTable->groupData[child+1])
            {
                child = child + 1;
            }

            if (speciesTable->groupData[root] < speciesTable->groupData[child])
            {
                SwapSpeciesAndGroup(speciesTable, root, child);
                root = child;
            }
            else
                break;
        }
    }

    for (i = 0; i < RANDOMIZER_SPECIES_COUNT; i++)
    {
        u16 targetIndex = speciesTable->groupIndexToSpecies[i];
        speciesTable->speciesToGroupIndex[targetIndex] = i;
    }
}

static const struct SpeciesTable* GetSpeciesTable(enum RandomizerSpeciesMode mode)
{
    if (!sRamSpeciesTable.tableInitialized
        || mode != sRamSpeciesTable.mode
        || sRamSpeciesTable.genScopeRestricted != IsGenScopeRestricted())
        BuildRandomizerSpeciesTable(mode);

    return &sRamSpeciesTable.speciesTable;
}

void PreloadRandomizationTables(void)
{
    GetSpeciesTable(GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE));
}

#endif

static u16 RandomizeMonTableLookup(struct Sfc32State* state, enum RandomizerSpeciesMode mode, u16 species)
{
    u16 minGroup, maxGroup, originalGroup, resultIndex;
    u16 minIndex, maxIndex;
    u16 result;
    u32 attempts;
    const struct SpeciesTable *table;

    table = GetSpeciesTable(mode);
    originalGroup = GetSpeciesGroup(table, species);

    if (originalGroup == GROUP_INVALID)
    {
        // With a restricted gen scope the species being replaced can itself sit
        // outside the pool, so it has no group to be matched against. Draw from
        // the entire in-scope pool instead of leaving it unrandomized; BST and
        // evolution-stage matching are meaningless for a mon that is not in the
        // pool to begin with.
        if (!IsGenScopeRestricted() || !IsSpeciesValidForRandomizer(species))
            return species;

        GetIndicesFromGroupRange(table, 0, GROUP_INVALID - 1, &minIndex, &maxIndex);
    }
    else
    {
        GetGroupRange(originalGroup, mode, &minGroup, &maxGroup);
        GetIndicesFromGroupRange(table, minGroup, maxGroup, &minIndex, &maxIndex);
    }

    if (maxIndex < minIndex)
        return species;

    for (attempts = 0; attempts < 8; attempts++)
    {
        resultIndex = RandomizerNextRange(state, maxIndex - minIndex + 1) + minIndex;
        result = table->groupIndexToSpecies[resultIndex];
        if (IsSpeciesPermitted(result))
            return result;
    }

    return species;
}

static u16 RandomizeMonFromSeed(struct Sfc32State *state, enum RandomizerSpeciesMode mode, u16 species)
{
    if (!IsSpeciesValidForRandomizer(species))
        return species;

    if (mode >= MAX_MON_MODE)
        mode = MON_RANDOM;

    return RandomizeMonTableLookup(state, mode, species);

}

void GetUniqueMonList(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed1, u16 seed2, u8 count, const u16 *originalSpecies, u16 *resultSpecies)
{
    u32 i, curMon;
    u32 seenMonBitVector[(RANDOMIZER_SPECIES_COUNT-1)/32+1] = {};
    struct Sfc32State state = RandomizerRandSeed(reason, seed1, seed2);

    for (i = 0; i < count; i++)
    {
        u16 curOriginal = originalSpecies[i];
        bool32 foundNextMon = FALSE;
        if (!IsSpeciesValidForRandomizer(curOriginal))
        {
            curMon = curOriginal;
            continue;
        }

        while (!foundNextMon)
        {
            u16 wordIndex, adjustedCurMon;
            u32 bitVectorWord;
            u8 bitIndex;

            curMon = RandomizeMonFromSeed(&state, mode, curOriginal);

            adjustedCurMon = curMon - 1;
            wordIndex = adjustedCurMon / 32;
            bitIndex = adjustedCurMon & 31;
            bitVectorWord = seenMonBitVector[wordIndex];

            if (bitVectorWord & (1 << bitIndex))
                continue;

            bitVectorWord |= 1 << bitIndex;
            seenMonBitVector[wordIndex] = bitVectorWord;
            foundNextMon = TRUE;
        }
        resultSpecies[i] = curMon;
    }
}

u16 RandomizeMonBaseForm(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species)
{
    struct Sfc32State state;
    state = RandomizerRandSeed(reason, seed, species);
    return RandomizeMonFromSeed(&state, mode, species);
}

static u16 ChooseRandomForm(struct Sfc32State *state, const u16 baseSpecies)
{
    const u16 *formsTable = gSpeciesInfo[baseSpecies].formSpeciesIdTable;
    if (formsTable)
    {
        u32 formCount = 0;
        while (formsTable[formCount] != FORM_SPECIES_END)
        {
            formCount++;
        }
        return formsTable[RandomizerNextRange(state, formCount)];
    }

    return baseSpecies;
}

static u16 GetFormFromRareFormInfo(struct Sfc32State *state, const struct RandomizerRareFormInfo *info)
{
    if (RandomizerNextRange(state, info->inverseRareFormChance) > 0)
        return info->commonForm;
    else
        return info->rareForm;
}

#define RANDOM_FROM_ARRAY(arr)  (arr[RandomizerNextRange(state, ARRAY_COUNT(arr))])
#define RARE_FORM(infoStruct)   (GetFormFromRareFormInfo(state, &infoStruct))
static u16 ChooseFormSpecial(struct Sfc32State *state, const u16 baseSpecies)
{
    switch (baseSpecies) {
        case SPECIES_FLOETTE:
            return RANDOM_FROM_ARRAY(sFloetteFormChoices);
        case SPECIES_TAUROS_PALDEA_COMBAT:
            return RANDOM_FROM_ARRAY(sPaldeanTaurosFormChoices);
        case SPECIES_MINIOR:
            return RANDOM_FROM_ARRAY(sMiniorFormChoices);
        case SPECIES_MAUSHOLD:
            return RARE_FORM(sMausholdRareFormInfo);
        case SPECIES_SINISTEA:
            return RARE_FORM(sSinisteaRareFormInfo);
        case SPECIES_SINISTCHA:
            return RARE_FORM(sSinistchaRareFormInfo);
        case SPECIES_POLTEAGEIST:
            return RARE_FORM(sPolteageistRareFormInfo);
        case SPECIES_DUDUNSPARCE:
            return RARE_FORM(sDudunsparceRareFormInfo);
        default:
            return baseSpecies;
    }

}
#undef RANDOM_FROM_ARRAY
#undef RARE_FORM

u16 RandomizeMon(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species)
{
    u32 speciesMode;
    u16 resultSpecies;
    struct Sfc32State state;

    if (!IsSpeciesValidForRandomizer(species))
        return species;

    state = RandomizerRandSeed(reason, seed, species);

    resultSpecies = RandomizeMonFromSeed(&state, mode, species);
    speciesMode = gSpeciesInfo[resultSpecies].randomizerMode;

    switch (speciesMode)
    {
        case MON_RANDOMIZER_RANDOM_FORM:
            return ChooseRandomForm(&state, resultSpecies);
        case MON_RANDOMIZER_SPECIAL_FORM:
            return ChooseFormSpecial(&state, resultSpecies);
        case MON_RANDOMIZER_NORMAL:
        default:
            return resultSpecies;
    }
}

#define WILD_RANDOMIZER_T1_MAX_BST 320
#define WILD_SPECIES_POOL_MAX 1200

static const u16 sFinalPseudoLegendaries[] = {
    SPECIES_DRAGONITE,
    SPECIES_TYRANITAR,
    SPECIES_SALAMENCE,
    SPECIES_METAGROSS,
    SPECIES_GARCHOMP,
    SPECIES_HYDREIGON,
    SPECIES_GOODRA,
    SPECIES_GOODRA_HISUI,
    SPECIES_KOMMO_O,
    SPECIES_DRAGAPULT,
    SPECIES_BAXCALIBUR,
};

static const u16 sCoverLegendaries[] = {
    SPECIES_MEWTWO,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_KYOGRE,
    SPECIES_GROUDON,
    SPECIES_RAYQUAZA,
    SPECIES_DIALGA,
    SPECIES_DIALGA_ORIGIN,
    SPECIES_PALKIA,
    SPECIES_PALKIA_ORIGIN,
    SPECIES_GIRATINA_ALTERED,
    SPECIES_GIRATINA_ORIGIN,
    SPECIES_RESHIRAM,
    SPECIES_ZEKROM,
    SPECIES_KYUREM,
    SPECIES_KYUREM_BLACK,
    SPECIES_KYUREM_WHITE,
    SPECIES_XERNEAS,
    SPECIES_YVELTAL,
    SPECIES_ZYGARDE_50,
    SPECIES_ZYGARDE_10,
    SPECIES_ZYGARDE_COMPLETE,
    SPECIES_SOLGALEO,
    SPECIES_LUNALA,
    SPECIES_NECROZMA,
    SPECIES_NECROZMA_DUSK_MANE,
    SPECIES_NECROZMA_DAWN_WINGS,
    SPECIES_NECROZMA_ULTRA,
    SPECIES_ZACIAN_HERO,
    SPECIES_ZACIAN_CROWNED,
    SPECIES_ZAMAZENTA_HERO,
    SPECIES_ZAMAZENTA_CROWNED,
    SPECIES_ETERNATUS,
    SPECIES_ETERNATUS_ETERNAMAX,
    SPECIES_CALYREX,
    SPECIES_CALYREX_ICE,
    SPECIES_CALYREX_SHADOW,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
};

static const u16 sWildProgressionWeights[PROGRESSION_BLOCK_COUNT][7] = {
    /* BLOCK_INICIO */         {650, 280,  60,  10,   0,   0,   0},
    /* BLOCK_EARLY */          {400, 380, 180,  35,   5,   0,   0},
    /* BLOCK_MID */            {200, 320, 300, 120,  50,   9,   1},
    /* BLOCK_LATE_JOHTO */     { 80, 200, 300, 220, 130,  60,  10},
    /* BLOCK_PRE_LIGA */       { 30, 120, 250, 280, 200, 100,  20},
    /* BLOCK_LIGA_JOHTO */     {  0,  50, 150, 250, 250, 250,  50},
    /* BLOCK_KANTO_TEMPRANO */ { 20, 100, 200, 250, 200, 160,  70},
    /* BLOCK_KANTO_TARDIO */   {  0,  30, 120, 200, 250, 300, 100},
    /* BLOCK_POSTGAME */       {  0,   0,  50, 150, 250, 450, 100},
};

struct WildRandomizerPools
{
    bool8 initialized;
    bool8 genScopeRestricted;
    bool8 includeLegendaries;
    u16 counts[7];
    u16 offsets[7];
    u16 species[WILD_SPECIES_POOL_MAX];
};

EWRAM_DATA static struct WildRandomizerPools sWildPools = {0};

static inline u16 GetSpeciesBST(u16 species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];
    return info->baseHP + info->baseAttack + info->baseDefense
         + info->baseSpeed + info->baseSpAttack + info->baseSpDefense;
}

static bool32 IsCoverLegendary(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sCoverLegendaries); i++)
    {
        if (sCoverLegendaries[i] == species)
            return TRUE;
    }
    return FALSE;
}

static bool32 IsFinalPseudoLegendary(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sFinalPseudoLegendaries); i++)
    {
        if (sFinalPseudoLegendaries[i] == species)
            return TRUE;
    }
    return FALSE;
}

enum WildPowerCategory GetWildPowerCategory(u16 species)
{
    if (gSpeciesInfo[species].isMythical)
        return CATEGORY_MYTHICAL;
    if (IsCoverLegendary(species))
        return CATEGORY_T5_L;
    if (gSpeciesInfo[species].isRestrictedLegendary || gSpeciesInfo[species].isSubLegendary || gSpeciesInfo[species].isUltraBeast)
        return CATEGORY_T5_SL;
    if (IsFinalPseudoLegendary(species))
        return CATEGORY_T4_PS;

    u16 bst = GetSpeciesBST(species);
    if (bst <= WILD_RANDOMIZER_T1_MAX_BST)
        return CATEGORY_T1;
    if (bst <= 419)
        return CATEGORY_T2;
    if (bst <= 499)
        return CATEGORY_T3;
    return CATEGORY_T4;
}

static bool32 IsSpeciesValidForWildRandomizer(u16 species)
{
    if (!IsSpeciesValidForRandomizer(species))
        return FALSE;

    if (!IsSpeciesInGenScope(species))
        return FALSE;

    const struct SpeciesInfo *info = &gSpeciesInfo[species];

    if (info->randomizerMode == MON_RANDOMIZER_INVALID)
        return FALSE;

    if (info->isMegaEvolution
     || info->isPrimalReversion
     || info->isUltraBurst
     || info->isGigantamax
     || info->isTeraForm
     || info->isTotem)
        return FALSE;

    if (info->isMythical)
        return FALSE;

    return TRUE;
}

static u8 GetJohtoBadgeCount(void)
{
    u8 count = 0;
    u16 flag;
    for (flag = FLAG_BADGE01_GET; flag <= FLAG_BADGE08_GET; flag++)
    {
        if (FlagGet(flag))
            count++;
    }
    return count;
}

static u8 GetKantoBadgeCount(void)
{
    u8 count = 0;
    u16 flag;
    for (flag = FLAG_BADGE09_GET; flag <= FLAG_BADGE16_GET; flag++)
    {
        if (FlagGet(flag))
            count++;
    }
    return count;
}

static bool32 HasBeatenJohtoLeague(void)
{
    return FlagGet(FLAG_IS_CHAMPION);
}

static bool32 HasBeatenFinalLeague(void)
{
#if IS_HNS
    return FlagGet(FLAG_IS_KANTO_CHAMPION) || FlagGet(TRAINER_FLAGS_START + TRAINER_RED_HNS);
#else
    return FlagGet(FLAG_IS_CHAMPION);
#endif
}

u8 GetWildRandomizerProgressionBlock(void)
{
    if (HasBeatenFinalLeague())
        return BLOCK_POSTGAME;
    if (GetKantoBadgeCount() >= 5)
        return BLOCK_KANTO_TARDIO;
    if (GetKantoBadgeCount() >= 1)
        return BLOCK_KANTO_TEMPRANO;
    if (HasBeatenJohtoLeague())
        return BLOCK_LIGA_JOHTO;

    u8 badges = GetJohtoBadgeCount();
    if (badges == 0)
        return BLOCK_INICIO;
    if (badges <= 2)
        return BLOCK_EARLY;
    if (badges <= 4)
        return BLOCK_MID;
    if (badges <= 6)
        return BLOCK_LATE_JOHTO;
    return BLOCK_PRE_LIGA;
}

static void BuildWildSpeciesPools(void)
{
    u16 i, species;
    u16 currentOffset = 0;
    u16 catCur[7] = {0};
    bool32 includeLegendaries = gSaveBlock3Ptr->challengeSettings.tx_Random_IncludeLegendaries;

    memset(sWildPools.counts, 0, sizeof(sWildPools.counts));

    for (species = 1; species < RANDOMIZER_SPECIES_COUNT; species++)
    {
        enum WildPowerCategory cat;

        if (!IsSpeciesValidForWildRandomizer(species))
            continue;

        cat = GetWildPowerCategory(species);
        if (cat >= 7)
            continue;

        if ((cat == CATEGORY_T5_SL || cat == CATEGORY_T5_L) && !includeLegendaries)
            continue;

        sWildPools.counts[cat]++;
    }

    for (i = 0; i < 7; i++)
    {
        sWildPools.offsets[i] = currentOffset;
        currentOffset += sWildPools.counts[i];
    }

    for (species = 1; species < RANDOMIZER_SPECIES_COUNT; species++)
    {
        enum WildPowerCategory cat;

        if (!IsSpeciesValidForWildRandomizer(species))
            continue;

        cat = GetWildPowerCategory(species);
        if (cat >= 7)
            continue;

        if ((cat == CATEGORY_T5_SL || cat == CATEGORY_T5_L) && !includeLegendaries)
            continue;

        if (sWildPools.offsets[cat] + catCur[cat] < WILD_SPECIES_POOL_MAX)
        {
            sWildPools.species[sWildPools.offsets[cat] + catCur[cat]] = species;
            catCur[cat]++;
        }
    }

    sWildPools.initialized = TRUE;
    sWildPools.genScopeRestricted = IsGenScopeRestricted();
    sWildPools.includeLegendaries = includeLegendaries;
}

static u16 ChooseWildForm(struct Sfc32State *state, u16 baseSpecies)
{
    u32 speciesMode = gSpeciesInfo[baseSpecies].randomizerMode;
    u16 candidate = baseSpecies;

    if (speciesMode == MON_RANDOMIZER_RANDOM_FORM)
    {
        const u16 *formsTable = gSpeciesInfo[baseSpecies].formSpeciesIdTable;
        if (formsTable)
        {
            u16 validForms[32];
            u32 validCount = 0;
            u32 i = 0;
            while (formsTable[i] != FORM_SPECIES_END && validCount < ARRAY_COUNT(validForms))
            {
                u16 f = formsTable[i];
                const struct SpeciesInfo *fInfo = &gSpeciesInfo[f];
                if (!fInfo->isMegaEvolution
                 && !fInfo->isPrimalReversion
                 && !fInfo->isUltraBurst
                 && !fInfo->isGigantamax
                 && !fInfo->isTeraForm
                 && !fInfo->isTotem
                 && fInfo->randomizerMode != MON_RANDOMIZER_INVALID)
                {
                    validForms[validCount++] = f;
                }
                i++;
            }
            if (validCount > 0)
                candidate = validForms[RandomizerNextRange(state, validCount)];
        }
    }
    else if (speciesMode == MON_RANDOMIZER_SPECIAL_FORM)
    {
        candidate = ChooseFormSpecial(state, baseSpecies);
        const struct SpeciesInfo *cstInfo = &gSpeciesInfo[candidate];
        if (cstInfo->isMegaEvolution
         || cstInfo->isPrimalReversion
         || cstInfo->isUltraBurst
         || cstInfo->isGigantamax
         || cstInfo->isTeraForm
         || cstInfo->isTotem
         || cstInfo->randomizerMode == MON_RANDOMIZER_INVALID)
        {
            candidate = baseSpecies;
        }
    }

    return candidate;
}

static enum WildPowerCategory WeightedCategoryRoll(const u16 *weights, struct Sfc32State *state)
{
    u32 roll = RandomizerNextRange(state, 1000);
    u32 accum = 0;
    u32 i;

    for (i = 0; i < 7; i++)
    {
        accum += weights[i];
        if (roll < accum)
            return (enum WildPowerCategory)i;
    }
    return CATEGORY_T1;
}

static u16 ChooseWildSpecies(enum WildPowerCategory category, struct Sfc32State *state, u16 fallbackSpecies)
{
    if (sWildPools.counts[category] == 0)
    {
        s32 c;
        bool32 found = FALSE;

        for (c = (s32)category - 1; c >= 0; c--)
        {
            if (sWildPools.counts[c] > 0)
            {
                category = (enum WildPowerCategory)c;
                found = TRUE;
                break;
            }
        }

        if (!found)
        {
            for (c = (s32)category + 1; c < 7; c++)
            {
                if (sWildPools.counts[c] > 0)
                {
                    category = (enum WildPowerCategory)c;
                    found = TRUE;
                    break;
                }
            }
        }

        if (!found)
            return fallbackSpecies;
    }

    u16 index = RandomizerNextRange(state, sWildPools.counts[category]);
    u16 baseSpecies = sWildPools.species[sWildPools.offsets[category] + index];
    return ChooseWildForm(state, baseSpecies);
}

u16 RandomizeWildEncounter(u16 species, u8 mapNum, u8 mapGroup, enum WildPokemonArea area, u8 slot)
{
    if (!RandomizerFeatureEnabled(RANDOMIZE_WILD_MON) || !IsSpeciesValidForRandomizer(species))
        return species;

    u8 block = GetWildRandomizerProgressionBlock();
    struct Sfc32State state;

    if (gSaveBlock3Ptr->challengeSettings.tx_Random_MapBased)
    {
        u32 slotKey = (((u32)mapGroup) << 24)
                    | (((u32)mapNum) << 16)
                    | (((u32)area) << 10)
                    | (((u32)slot) << 4)
                    | (u32)block;
        state = RandomizerRandSeed(RANDOMIZER_REASON_WILD_ENCOUNTER, slotKey, (u32)species);
    }
    else
    {
        state.a = Random32();
        state.b = Random32();
        state.c = Random32();
        state.ctr = RANDOMIZER_STREAM;
        u32 i;
        for (i = 0; i < 10; i++)
            _SFC32_Next_Stream(&state, RANDOMIZER_STREAM);
    }

    if (!sWildPools.initialized
     || sWildPools.genScopeRestricted != IsGenScopeRestricted()
     || sWildPools.includeLegendaries != gSaveBlock3Ptr->challengeSettings.tx_Random_IncludeLegendaries)
    {
        BuildWildSpeciesPools();
    }

    enum WildPowerCategory category = WeightedCategoryRoll(sWildProgressionWeights[block], &state);
    return ChooseWildSpecies(category, &state, species);
}



bool32 IsRandomizationPossible(u16 originalSpecies, u16 targetSpecies)
{
    const enum RandomizerSpeciesMode mode = GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE);
    if (!IsSpeciesPermitted(targetSpecies) || !IsSpeciesValidForRandomizer(originalSpecies))
    {
        return originalSpecies == targetSpecies;
    }

    if (mode != MON_RANDOM && mode < MAX_MON_MODE)
    {
        u16 minGroupOriginal, maxGroupOriginal, minGroupTarget, maxGroupTarget,
            originalGroup, targetGroup;
        const struct SpeciesTable* table;
        table = GetSpeciesTable(mode);
        originalGroup = GetSpeciesGroup(table, originalSpecies);
        targetGroup = GetSpeciesGroup(table, targetSpecies);
        GetGroupRange(originalGroup, mode, &minGroupOriginal, &maxGroupOriginal);
        GetGroupRange(targetGroup, mode, &minGroupTarget, &maxGroupTarget);

        return maxGroupOriginal >= minGroupTarget && minGroupOriginal <= maxGroupTarget;
    }

    return TRUE;
}

enum TrainerPowerTier
{
    TRAINER_TIER_REGULAR,
    TRAINER_TIER_ACE,
    TRAINER_TIER_BOSS,
};

static const u16 sTrainerBossProgressionWeights[9][7] = {
    /* INICIO */         {300, 500, 180,  20,   0,   0,   0},
    /* EARLY */          {100, 450, 380,  70,  10,   0,   0},
    /* MID */            {  0, 200, 480, 230,  80,   9,   1},
    /* LATE_JOHTO */     {  0,  40, 330, 410, 150,  60,  10},
    /* PRE_LIGA */       {  0,  10, 150, 450, 260, 110,  20},
    /* LIGA_JOHTO */     {  0,   0,  30, 370, 300, 230,  70},
    /* KANTO_TEMPRANO */ {  0,   0,  20, 360, 300, 240,  80},
    /* KANTO_TARDIO */   {  0,   0,   0, 300, 300, 300, 100},
    /* POSTGAME */       {  0,   0,   0, 200, 300, 400, 100},
};

struct MegaPair
{
    u16 species;
    u16 stone;
};

static const struct MegaPair sTrainerMegaPairs[] =
{
    {SPECIES_VENUSAUR, ITEM_VENUSAURITE},
    {SPECIES_CHARIZARD, ITEM_CHARIZARDITE_X},
    {SPECIES_CHARIZARD, ITEM_CHARIZARDITE_Y},
    {SPECIES_BLASTOISE, ITEM_BLASTOISINITE},
    {SPECIES_BEEDRILL, ITEM_BEEDRILLITE},
    {SPECIES_PIDGEOT, ITEM_PIDGEOTITE},
    {SPECIES_ALAKAZAM, ITEM_ALAKAZITE},
    {SPECIES_SLOWBRO, ITEM_SLOWBRONITE},
    {SPECIES_GENGAR, ITEM_GENGARITE},
    {SPECIES_KANGASKHAN, ITEM_KANGASKHANITE},
    {SPECIES_PINSIR, ITEM_PINSIRITE},
    {SPECIES_GYARADOS, ITEM_GYARADOSITE},
    {SPECIES_AERODACTYL, ITEM_AERODACTYLITE},
    {SPECIES_AMPHAROS, ITEM_AMPHAROSITE},
    {SPECIES_STEELIX, ITEM_STEELIXITE},
    {SPECIES_SCIZOR, ITEM_SCIZORITE},
    {SPECIES_HERACROSS, ITEM_HERACRONITE},
    {SPECIES_HOUNDOOM, ITEM_HOUNDOOMINITE},
    {SPECIES_TYRANITAR, ITEM_TYRANITARITE},
    {SPECIES_SCEPTILE, ITEM_SCEPTILITE},
    {SPECIES_BLAZIKEN, ITEM_BLAZIKENITE},
    {SPECIES_SWAMPERT, ITEM_SWAMPERTITE},
    {SPECIES_GARDEVOIR, ITEM_GARDEVOIRITE},
    {SPECIES_SABLEYE, ITEM_SABLENITE},
    {SPECIES_MAWILE, ITEM_MAWILITE},
    {SPECIES_AGGRON, ITEM_AGGRONITE},
    {SPECIES_MEDICHAM, ITEM_MEDICHAMITE},
    {SPECIES_MANECTRIC, ITEM_MANECTITE},
    {SPECIES_SHARPEDO, ITEM_SHARPEDONITE},
    {SPECIES_CAMERUPT, ITEM_CAMERUPTITE},
    {SPECIES_ALTARIA, ITEM_ALTARIANITE},
    {SPECIES_BANETTE, ITEM_BANETTITE},
    {SPECIES_ABSOL, ITEM_ABSOLITE},
    {SPECIES_GLALIE, ITEM_GLALITITE},
    {SPECIES_SALAMENCE, ITEM_SALAMENCITE},
    {SPECIES_METAGROSS, ITEM_METAGROSSITE},
    {SPECIES_LOPUNNY, ITEM_LOPUNNITE},
    {SPECIES_GARCHOMP, ITEM_GARCHOMPITE},
    {SPECIES_LUCARIO, ITEM_LUCARIONITE},
    {SPECIES_ABOMASNOW, ITEM_ABOMASITE},
    {SPECIES_GALLADE, ITEM_GALLADITE},
    {SPECIES_AUDINO, ITEM_AUDINITE},
};

static bool32 IsCustomMegaTrainer(u16 trainerId)
{
    // Hook extensible para que el usuario pueda añadir combates y entrenadores especiales que usen Mega
    return FALSE;
}

static bool32 IsConfiguredMegaBoss(u16 trainerId, u8 trainerClass)
{
    if (IsCustomMegaTrainer(trainerId))
        return TRUE;

    switch (trainerClass)
    {
    case TRAINER_CLASS_LEADER_HNS:
    case TRAINER_CLASS_LEADER_KANTO_HNS:
    case TRAINER_CLASS_ELITE_FOUR_HNS:
    case TRAINER_CLASS_CHAMPION_HNS:
    case TRAINER_CLASS_ROCKET_ADMIN_HNS:
    case TRAINER_CLASS_RIVAL_HNS:
        return TRUE;
    }

    switch (trainerId)
    {
    case TRAINER_RED_HNS:
    case TRAINER_RED_POSTOBC_HNS:
    case TRAINER_GIOVANNI_HNS:
    case TRAINER_EUSINE_HNS:
        return TRUE;
    }

    return FALSE;
}

static enum TrainerPowerTier GetTrainerPowerTier(u16 trainerId, u8 trainerClass)
{
    switch (trainerId)
    {
    case TRAINER_WILL_1_HNS:
    case TRAINER_WILL_2_HNS:
    case TRAINER_WILL_POSTOBC_HNS:
    case TRAINER_KOGA_1_HNS:
    case TRAINER_KOGA_2_HNS:
    case TRAINER_KOGA_POSTOBC_HNS:
    case TRAINER_BRUNO_1_HNS:
    case TRAINER_BRUNO_2_HNS:
    case TRAINER_BRUNO_POSTOBC_HNS:
    case TRAINER_KAREN_1_HNS:
    case TRAINER_KAREN_2_HNS:
    case TRAINER_KAREN_POSTOBC_HNS:
    case TRAINER_LANCE_1_HNS:
    case TRAINER_LANCE_2_HNS:
    case TRAINER_LANCE_3_HNS:
    case TRAINER_LANCE_POSTOBC_HNS:
    case TRAINER_RED_HNS:
    case TRAINER_RED_POSTOBC_HNS:
        return TRAINER_TIER_BOSS;
    }

    if (FlagGet(FLAG_MEGA_SYSTEM_UNLOCKED))
    {
        if (trainerClass == TRAINER_CLASS_LEADER_HNS
         || trainerClass == TRAINER_CLASS_LEADER_KANTO_HNS)
            return TRAINER_TIER_ACE;
    }

    return TRAINER_TIER_REGULAR;
}

static bool32 CanTrainerSpeciesEvolve(u16 species)
{
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);
    return (evolutions != NULL && evolutions[0].method != EVOLUTIONS_END);
}

static u16 PromoteSpeciesForLevel(u16 species, u8 level)
{
    u32 i;
    u16 current = species;

    for (i = 0; i < 2; i++)
    {
        const struct Evolution *evos = GetSpeciesEvolutions(current);
        u16 target = SPECIES_NONE;
        u32 j;

        if (evos == NULL)
            break;

        for (j = 0; evos[j].method != EVOLUTIONS_END; j++)
        {
            if (evos[j].method == EVO_LEVEL || evos[j].method == EVO_LEVEL_BATTLE_ONLY)
            {
                u16 reqLvl = (evos[j].param == 0) ? 16 : evos[j].param;
                if (level >= reqLvl)
                {
                    target = evos[j].targetSpecies;
                    break;
                }
            }
            else if ((evos[j].method == EVO_ITEM || evos[j].method == EVO_TRADE || evos[j].method == EVO_SPLIT_FROM_EVO || evos[j].method == EVO_SPIN) && level >= 30)
            {
                target = evos[j].targetSpecies;
                break;
            }
        }

        if (target != SPECIES_NONE && target < RANDOMIZER_SPECIES_COUNT && IsSpeciesPermitted(target))
            current = target;
        else
            break;
    }

    return current;
}

static u16 RollCompatibleTrainerItem(u16 species, enum TrainerPowerTier tier, u8 block, enum DifficultyLevel difficulty, struct Sfc32State *state)
{
    u32 roll = RandomizerNextRange(state, 100);
    u32 berryChance = 0;
    u32 safeChance = 0;

    switch (tier)
    {
    case TRAINER_TIER_REGULAR:
        if (block <= BLOCK_EARLY)
        {
            berryChance = 0;
            safeChance = 0;
        }
        else if (block == BLOCK_MID)
        {
            berryChance = 20;
            safeChance = 0;
        }
        else if (block == BLOCK_LATE_JOHTO)
        {
            berryChance = 30;
            safeChance = 0;
        }
        else
        {
            berryChance = 0;
            safeChance = 50;
        }
        break;
    case TRAINER_TIER_ACE:
        if (block <= BLOCK_EARLY)
        {
            berryChance = 20;
            safeChance = 0;
        }
        else if (block == BLOCK_MID)
        {
            berryChance = 0;
            safeChance = 50;
        }
        else if (block == BLOCK_LATE_JOHTO)
        {
            berryChance = 0;
            safeChance = 70;
        }
        else
        {
            berryChance = 0;
            safeChance = 100;
        }
        break;
    case TRAINER_TIER_BOSS:
    default:
        if (block <= BLOCK_EARLY)
        {
            berryChance = 100;
            safeChance = 0;
        }
        else
        {
            berryChance = 0;
            safeChance = 100;
        }
        break;
    }

    if (difficulty == DIFFICULTY_EASY)
    {
        safeChance = 0;
        if (berryChance == 0 && tier >= TRAINER_TIER_ACE)
            berryChance = 30;
    }

    if (roll < berryChance)
    {
        static const u16 sTrainerBerries[] = {
            ITEM_SITRUS_BERRY, ITEM_LUM_BERRY, ITEM_ORAN_BERRY, ITEM_CHERI_BERRY, ITEM_CHESTO_BERRY, ITEM_PECHA_BERRY
        };
        return sTrainerBerries[RandomizerNextRange(state, ARRAY_COUNT(sTrainerBerries))];
    }
    else if (roll < (berryChance + safeChance))
    {
        static const u16 sTrainerSafeItems[] = {
            ITEM_LEFTOVERS, ITEM_FOCUS_SASH, ITEM_ROCKY_HELMET, ITEM_LIFE_ORB, ITEM_EXPERT_BELT, ITEM_ASSAULT_VEST
        };
        if (CanTrainerSpeciesEvolve(species))
        {
            if (RandomizerNextRange(state, 100) < 35)
                return ITEM_EVIOLITE;
        }
        return sTrainerSafeItems[RandomizerNextRange(state, ARRAY_COUNT(sTrainerSafeItems))];
    }

    return ITEM_NONE;
}

struct RandomizedTrainerMon RandomizeTrainerPartyMon(u16 trainerId, u8 trainerClass, u8 slot, u8 totalMons, u16 originalSpecies, u16 originalHeldItem, u8 level)
{
    struct RandomizedTrainerMon result;
    result.species = originalSpecies;
    result.heldItem = originalHeldItem;

    if (!RandomizerFeatureEnabled(RANDOMIZE_TRAINER_MON) || !IsSpeciesValidForRandomizer(originalSpecies))
        return result;

    u8 block = GetWildRandomizerProgressionBlock();
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();
    enum TrainerPowerTier tier = GetTrainerPowerTier(trainerId, trainerClass);

    u32 slotKey = (((u32)trainerId) << 16) | (((u32)block) << 8) | (u32)slot;
    struct Sfc32State state = RandomizerRandSeed(RANDOMIZER_REASON_TRAINER_PARTY, slotKey, (u32)originalSpecies);

    if (!sWildPools.initialized
     || sWildPools.genScopeRestricted != IsGenScopeRestricted()
     || sWildPools.includeLegendaries != gSaveBlock3Ptr->challengeSettings.tx_Random_IncludeLegendaries)
    {
        BuildWildSpeciesPools();
    }

    s8 megaSlot = -1;
    s8 specialSlot = -1;

    if (FlagGet(FLAG_MEGA_SYSTEM_UNLOCKED) && IsConfiguredMegaBoss(trainerId, trainerClass) && totalMons > 0)
    {
        megaSlot = totalMons - 1;
    }

    if (tier == TRAINER_TIER_BOSS && totalMons >= 2)
    {
        specialSlot = (megaSlot == totalMons - 1) ? (totalMons - 2) : (totalMons - 1);
    }

    if (slot == megaSlot)
    {
        u32 pairIndex = RandomizerNextRange(&state, ARRAY_COUNT(sTrainerMegaPairs));
        result.species = sTrainerMegaPairs[pairIndex].species;
        result.heldItem = sTrainerMegaPairs[pairIndex].stone;
        return result;
    }

    if (slot == specialSlot)
    {
        bool32 includeLegendaries = gSaveBlock3Ptr->challengeSettings.tx_Random_IncludeLegendaries;
        enum WildPowerCategory cat;
        if (trainerId == TRAINER_LANCE_1_HNS || trainerId == TRAINER_LANCE_2_HNS || trainerId == TRAINER_LANCE_3_HNS || trainerId == TRAINER_LANCE_POSTOBC_HNS)
            cat = includeLegendaries ? CATEGORY_T5_L : CATEGORY_T4_PS;
        else
            cat = includeLegendaries ? CATEGORY_T5_SL : CATEGORY_T4_PS;

        result.species = ChooseWildSpecies(cat, &state, originalSpecies);
        if (tier >= TRAINER_TIER_ACE || level >= 25)
            result.species = PromoteSpeciesForLevel(result.species, level);
        result.heldItem = RollCompatibleTrainerItem(result.species, tier, block, difficulty, &state);
        return result;
    }

    u8 effectiveBlock = block;
    const u16 (*weights)[7] = sWildProgressionWeights;

    if (tier == TRAINER_TIER_ACE)
    {
        effectiveBlock = min(block + 1, BLOCK_POSTGAME);
    }
    else if (tier == TRAINER_TIER_BOSS)
    {
        weights = sTrainerBossProgressionWeights;
        if (trainerClass == TRAINER_CLASS_ELITE_FOUR_HNS || trainerClass == TRAINER_CLASS_CHAMPION_HNS)
            effectiveBlock = max(effectiveBlock, BLOCK_LIGA_JOHTO);
        else if (trainerClass == TRAINER_CLASS_LEADER_KANTO_HNS || trainerId == TRAINER_RED_HNS || trainerId == TRAINER_RED_POSTOBC_HNS)
            effectiveBlock = max(effectiveBlock, BLOCK_KANTO_TARDIO);
    }

    enum WildPowerCategory category = WeightedCategoryRoll(weights[effectiveBlock], &state);
    result.species = ChooseWildSpecies(category, &state, originalSpecies);
    if (tier >= TRAINER_TIER_ACE || level >= 25)
        result.species = PromoteSpeciesForLevel(result.species, level);
    result.heldItem = RollCompatibleTrainerItem(result.species, tier, block, difficulty, &state);

    return result;
}

u16 RandomizeTrainerMon(u16 trainerId, u8 slot, u8 totalMons, u16 species, u8 level)
{
    struct RandomizedTrainerMon randMon = RandomizeTrainerPartyMon(trainerId, 0, slot, totalMons, species, ITEM_NONE, level);
    return randMon.species;
}

u16 RandomizeFixedEncounterMon(u16 species, u8 mapNum, u8 mapGroup, u8 localId)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON))
    {
        u32 seed;
        seed = (u32)mapNum << 16;
        seed |= (u32)mapGroup << 8;
        seed |= localId;

        return RandomizeMon(RANDOMIZER_REASON_FIXED_ENCOUNTER, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE), seed, species);
    }

    return species;
}

EWRAM_DATA static u32 sLastMonRandomizerSeed = 0;
EWRAM_DATA static u16 sRandomizedMons[STARTER_AND_GIFT_MON_COUNT] = {0};

u16 RandomizeStarterAndGiftMon(u16 originalSlot, const u16* originalStarterAndGiftMons)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_STARTER_AND_GIFT_MON))
    {
        if (sLastMonRandomizerSeed != GetRandomizerSeed() || sRandomizedMons[0] == SPECIES_NONE)
        {
            u32 starterHash = 5381;
            u32 i;
            for (i = 0; i < STARTER_AND_GIFT_MON_COUNT; i++)
            {
                u16 originalStarter = originalStarterAndGiftMons[i];
                starterHash = ((starterHash << 5) + starterHash) ^ (u8)originalStarter;
                starterHash = ((starterHash << 5) + starterHash) ^ (u8)(originalStarter >> 8);
            }

            GetUniqueMonList(RANDOMIZER_REASON_STARTER_AND_GIFT_MON, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE),
                starterHash, 0, STARTER_AND_GIFT_MON_COUNT, originalStarterAndGiftMons, sRandomizedMons);
        }
        return sRandomizedMons[originalSlot];
    }

    return originalStarterAndGiftMons[originalSlot];
}

EWRAM_DATA static u32 sLastEggMonRandomizerSeed = 0;
EWRAM_DATA static u16 sRandomizedEggMons[EGG_MON_COUNT] = {0};

u16 RandomizeEggMon(u16 originalSlot, const u16* originalEggMons)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_EGG_MON))
    {
        if (sLastEggMonRandomizerSeed != GetRandomizerSeed() || sRandomizedEggMons[0] == SPECIES_NONE)
        {
            u32 eggHash = 5381;
            u32 i;
            for (i = 0; i < EGG_MON_COUNT; i++)
            {
                u16 originalEgg = originalEggMons[i];
                eggHash = ((eggHash << 5) + eggHash) ^ (u8)originalEgg;
                eggHash = ((eggHash << 5) + eggHash) ^ (u8)(originalEgg >> 8);
            }

            GetUniqueMonList(RANDOMIZER_REASON_EGG, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE),
                eggHash, 0, EGG_MON_COUNT, originalEggMons, sRandomizedEggMons);
        }
        return sRandomizedEggMons[originalSlot];
    }

    return originalEggMons[originalSlot];
}

static inline bool32 IsAbilityIllegal(u16 ability)
{
    if (ability == ABILITY_NONE || ability == ABILITY_WONDER_GUARD)
        return TRUE;
    return FALSE;
}

// Abilities are randomized per (species, ability slot), but a species' empty or
// duplicate slots must not turn into extra distinct abilities: Ability Capsule,
// Ability Patch and the Pokedex all decide how many abilities a species has from
// the base data. Collapse such slots onto the slot the base data actually uses so
// a randomized species keeps the same ability count as it has in vanilla.
static u8 GetEffectiveAbilitySlot(u16 species, u8 abilityNum)
{
    u32 i;

    if (abilityNum < NUM_ABILITY_SLOTS && GetSpeciesAbility(species, abilityNum) != ABILITY_NONE)
    {
        // Matches the Ability Capsule check: a second ability identical to the
        // first is not a separate ability.
        if (abilityNum == 1 && GetSpeciesAbility(species, 1) == GetSpeciesAbility(species, 0))
            return 0;
        return abilityNum;
    }

    // Empty slot: mirror the fallback order GetAbilityBySpecies uses, so the
    // randomized ability lands on the slot the base data actually resolves to.
    if (abilityNum >= NUM_NORMAL_ABILITY_SLOTS)
    {
        for (i = NUM_NORMAL_ABILITY_SLOTS; i < NUM_ABILITY_SLOTS; i++)
        {
            if (GetSpeciesAbility(species, i) != ABILITY_NONE)
                return i;
        }
    }

    for (i = 0; i < NUM_ABILITY_SLOTS; i++)
    {
        if (GetSpeciesAbility(species, i) != ABILITY_NONE)
            return i;
    }

    return 0;
}

u16 RandomizeAbility(u16 species, u8 abilityNum, u16 originalAbility)
{
    if (RandomizerFeatureEnabled(RANDOMIZE_ABILITIES) && originalAbility != ABILITY_NONE)
    {
        struct Sfc32State state;
        u16 result;
        u32 seed;

        abilityNum = GetEffectiveAbilitySlot(species, abilityNum);

        seed = ((u32)species) << 8;
        seed |= abilityNum;

        state = RandomizerRandSeed(RANDOMIZER_REASON_ABILITIES, seed, species);

        do
        {
            result = sRandomizerAbilityWhitelist[RandomizerNextRange(&state, ABILITY_WHITELIST_SIZE)];
        } while(IsAbilityIllegal(result));

        return result;
    }

    return originalAbility;
}

u16 RandomizeMove(u16 move, u16 species)
{
    struct Sfc32State state;
    u16 result;
    u32 seed;

    if (move == MOVE_NONE)
        return MOVE_NONE;

    seed = ((u32)move) + species;
    state = RandomizerRandSeed(RANDOMIZER_REASON_LEARNSET, seed, species);

    do
    {
        result = RandomizerNextRange(&state, MOVES_COUNT_GEN9 - 1) + 1;
        if (IsNuzlockeActive() && (result == MOVE_GUILLOTINE || result == MOVE_HORN_DRILL || result == MOVE_FISSURE || result == MOVE_SHEER_COLD))
            continue;
    } while (result >= MOVES_COUNT_GEN9 || result > MOVE_MALIGNANT_CHAIN || GetMoveRandomizerInvalid(result));

    return result;
}

u16 RandomizeEvolution(u16 targetSpecies, u16 originalSpecies)
{
    struct Sfc32State state;
    u16 result;
    u32 seed;

    if (targetSpecies == SPECIES_NONE)
        return SPECIES_NONE;

    seed = ((u32)targetSpecies) + originalSpecies;
    state = RandomizerRandSeed(RANDOMIZER_REASON_EVOLUTION, seed, originalSpecies);

    do
    {
        result = RandomizerNextRange(&state, RANDOMIZER_MAX_MON) + 1;
    } while (result > RANDOMIZER_MAX_MON || result == SPECIES_NONE || !IsSpeciesPermitted(result));

    return result;
}

static const u8 sShuffleableTypes[] =
{
    TYPE_NORMAL,
    TYPE_FIGHTING,
    TYPE_FLYING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_ROCK,
    TYPE_BUG,
    TYPE_GHOST,
    TYPE_STEEL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_PSYCHIC,
    TYPE_ICE,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_FAIRY,
};

#define NUM_SHUFFLEABLE_TYPES ARRAY_COUNT(sShuffleableTypes)

enum Type RandomizeType(enum Type type)
{
    u8 shuffled[NUM_SHUFFLEABLE_TYPES];
    u8 i, j, temp;
    struct Sfc32State state;

    if (type == TYPE_NONE || type == TYPE_MYSTERY || type == TYPE_STELLAR)
        return type;

    state = RandomizerRandSeed(RANDOMIZER_REASON_TYPE_EFFECTIVENESS, 0, 0);

    for (i = 0; i < NUM_SHUFFLEABLE_TYPES; i++)
        shuffled[i] = sShuffleableTypes[i];

    for (i = NUM_SHUFFLEABLE_TYPES - 1; i > 0; i--)
    {
        j = RandomizerNextRange(&state, i + 1);
        temp = shuffled[j];
        shuffled[j] = shuffled[i];
        shuffled[i] = temp;
    }

    for (i = 0; i < NUM_SHUFFLEABLE_TYPES; i++)
    {
        if (sShuffleableTypes[i] == (u8)type)
            return shuffled[i];
    }

    return type;
}

u16 RandomizeEvoMethod(u16 species)
{
    struct Sfc32State state;
    u16 result;
    u32 seed;

    if (species == SPECIES_NONE)
        return SPECIES_NONE;

    seed = (u32)species;
    state = RandomizerRandSeed(RANDOMIZER_REASON_EVO_METHOD, seed, species);

    do
    {
        result = RandomizerNextRange(&state, RANDOMIZER_MAX_MON) + 1;
    } while (result > RANDOMIZER_MAX_MON || result == SPECIES_NONE || !IsSpeciesPermitted(result));

    return result;
}

#endif // RANDOMIZER_AVAILABLE
