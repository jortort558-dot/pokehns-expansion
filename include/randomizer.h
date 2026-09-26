#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

#include "config/randomizer.h"
#if RANDOMIZER_AVAILABLE

#define RANDOMIZER_MAX_MON  (SPECIES_EGG-1)
#define RANDOMIZER_SPECIES_COUNT (RANDOMIZER_MAX_MON+1)

#include "global.h"
#include "random.h"
#include "script.h"
#include "wild_encounter.h"

#define RANDOMIZER_STREAM 17
#define STARTER_AND_GIFT_MON_COUNT 11
#define EGG_MON_COUNT 2

extern const u16 gStarterAndGiftMonTable[];
extern const u16 gEggMonTable[];

enum RandomizerFeature
{
    RANDOMIZE_WILD_MON,
    RANDOMIZE_TRAINER_MON,
    RANDOMIZE_FIELD_ITEMS,
    RANDOMIZE_BASE_STATS,
    RANDOMIZE_MON_TYPES,
    RANDOMIZE_LEARNSET,
    RANDOMIZE_FIXED_MON,
    RANDOMIZE_STARTER_AND_GIFT_MON,
    RANDOMIZE_EGG_MON,
    RANDOMIZE_ABILITIES,
    RANDOMIZE_EVOLUTIONS,
    RANDOMIZE_EVO_METHODS,
    RANDOMIZE_TYPE_EFFECTIVENESS,
};

enum RandomizerReason
{
    RANDOMIZER_REASON_WILD_ENCOUNTER,
    RANDOMIZER_REASON_FIXED_ENCOUNTER,
    RANDOMIZER_REASON_TRAINER_PARTY,
    RANDOMIZER_REASON_BASE_STATS,
    RANDOMIZER_REASON_SPECIES_TYPE,
    RANDOMIZER_REASON_LEARNSET,
    RANDOMIZER_REASON_FIELD_ITEM,
    RANDOMIZER_REASON_STARTER_AND_GIFT_MON,
    RANDOMIZER_REASON_EGG,
    RANDOMIZER_REASON_ABILITIES,
    RANDOMIZER_REASON_EVOLUTION,
    RANDOMIZER_REASON_EVO_METHOD,
    RANDOMIZER_REASON_TYPE_EFFECTIVENESS,
};

enum RandomizerOption {
    RANDOMIZER_OPTION_SPECIES_MODE,
};

enum RandomizerSpeciesMode {
    MON_RANDOM,
    MON_RANDOM_LEGEND_AWARE,
    MON_RANDOM_BST,
    MON_EVOLUTION,
    MAX_MON_MODE
};

enum WildPowerCategory {
    CATEGORY_T1,
    CATEGORY_T2,
    CATEGORY_T3,
    CATEGORY_T4,
    CATEGORY_T4_PS,
    CATEGORY_T5_SL,
    CATEGORY_T5_L,
    CATEGORY_MYTHICAL,
    CATEGORY_COUNT
};

enum ProgressionBlock {
    BLOCK_INICIO,           // 0 medallas de Johto
    BLOCK_EARLY,            // 1-2 medallas de Johto
    BLOCK_MID,              // 3-4 medallas de Johto
    BLOCK_LATE_JOHTO,       // 5-6 medallas de Johto
    BLOCK_PRE_LIGA,         // 7-8 medallas, Liga de Johto no superada
    BLOCK_LIGA_JOHTO,       // Liga de Johto superada, antes del avance efectivo en Kanto
    BLOCK_KANTO_TEMPRANO,   // 1-4 medallas de Kanto
    BLOCK_KANTO_TARDIO,     // 5-8 medallas de Kanto
    BLOCK_POSTGAME,         // contenido final superado
    PROGRESSION_BLOCK_COUNT
};

enum TrainerRandomizerPower {
    TRAINER_POWER_PROGRESSIVE,
    TRAINER_POWER_GENTLE,
    TRAINER_POWER_CHALLENGING,
    TRAINER_POWER_MAXIMUM,
};

enum TrainerRandomizerItems {
    TRAINER_ITEMS_PROGRESSIVE,
    TRAINER_ITEMS_NONE,
    TRAINER_ITEMS_BERRIES,
    TRAINER_ITEMS_COMPETITIVE,
};

enum TrainerRandomizerMegas {
    TRAINER_MEGAS_STORY,
    TRAINER_MEGAS_OFF,
    TRAINER_MEGAS_BOSSES,
    TRAINER_MEGAS_ALL,
};

struct RandomizerGroupSet {
    u16 species;
    u16 minGroup;
    u16 maxGroup;
};

u8 GetWildRandomizerProgressionBlock(void);
enum WildPowerCategory GetWildPowerCategory(u16 species);


bool8 IsRandomMovesActivated(void);
u32 GetRandomizerSeed(void);
bool32 RandomizerFeatureEnabled(enum RandomizerFeature feature);
u16 GetRandomizerOption(enum RandomizerOption option);

struct Sfc32State RandomizerRandSeed(enum RandomizerReason reason, u32 data1, u32 data2);

static inline u16 RandomizerNext(struct Sfc32State* state)
{
    return _SFC32_Next_Stream(state, RANDOMIZER_STREAM) >> 16;
}
u32 RandomizerNextRange(struct Sfc32State* state, u32 range);

u16 RandomizerRand(enum RandomizerReason reason, u32 data1, u32 data2);
u16 RandomizerRandRange(enum RandomizerReason reason, u32 data1, u32 data2, u16 range);

static inline u8 RandomizeMonType(u16 species, u8 typeNum)
{
    u8 type;
    struct Sfc32State state = RandomizerRandSeed(RANDOMIZER_REASON_SPECIES_TYPE, species, typeNum);
    do {
        type = (u8)RandomizerNextRange(&state, NUMBER_OF_MON_TYPES);
    } while (type == TYPE_NONE || type == TYPE_MYSTERY || type == TYPE_STELLAR);
    return type;
}

u16 GetRandomizedFieldItem(u16 originalItem, u8 mapGroup, u8 mapNum, u8 localId);
u16 GetRandomizedTM(u16 tmId);
u16 RandomizeFoundItem(u16 itemId, u8 mapNum, u8 mapGroup, u8 localId);
void FindItemRandomize_NativeCall(struct ScriptContext *ctx);
void FindHiddenItemRandomize_NativeCall(struct ScriptContext *ctx);
void ObtainItemRandomize_NativeCall(struct ScriptContext *ctx);

u16 RandomizeMon(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species);
u16 RandomizeMonBaseForm(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species);

u16 RandomizeWildEncounter(u16 species, u8 mapNum, u8 mapGroup, enum WildPokemonArea area, u8 slot, u8 level);

bool32 IsRandomizationPossible(u16 tableSpecies, u16 matchSpecies);

struct RandomizedTrainerMon
{
    u16 species;
    u16 heldItem;
};

struct RandomizedTrainerMon RandomizeTrainerPartyMon(u16 trainerId, u8 trainerClass, u8 slot, u8 totalMons, u16 originalSpecies, u16 originalHeldItem, u8 level);
u16 RandomizeTrainerMon(u16 trainerId, u8 slot, u8 totalMons, u16 species, u8 level);

u16 RandomizeFixedEncounterMon(u16 species, u8 mapNum, u8 mapGroup, u8 localId);

u16 RandomizeStarterAndGiftMon(u16 originalSlot, const u16* originalStarterAndGiftMons);

u16 RandomizeEggMon(u16 originalSlot, const u16* originalEggMons);

u16 RandomizeAbility(u16 species, u8 abilityNum, u16 originalAbility);

u16 RandomizeMove(u16 move, u16 species);

u16 RandomizeEvolution(u16 targetSpecies, u16 originalSpecies);

u16 RandomizeEvoMethod(u16 species);

enum Type RandomizeType(enum Type type);

static inline bool32 GroupSetsIntersect(struct RandomizerGroupSet* originalCache, struct RandomizerGroupSet* targetCache)
{
    return originalCache->maxGroup >= targetCache->minGroup
        && originalCache->minGroup <= targetCache->maxGroup;
}

// TRUE when the Gen 1-3 scope is off, or when the species belongs to a
// Gen 1-3 family. Also used to scope the One Type Challenge starter pool.
bool32 IsSpeciesInGenScope(u16 species);

#if RANDOMIZER_DYNAMIC_SPECIES
void PreloadRandomizationTables(void);
#endif

#endif // RANDOMIZER_AVAILABLE

#endif // GUARD_RANDOMIZER_H
