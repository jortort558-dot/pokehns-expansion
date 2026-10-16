#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "caps.h"
#include "constants/battle.h"
#include "constants/global.h"
#include "constants/moves.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "challenge_menu.h"
#include "event_data.h"
#include "starter_choose.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "ow_synchronize.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "randomizer.h"
#include "gym_tokens.h"
#include "nuzlocke.h"
#include "script.h"
#include "script_menu.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "tv.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/pokemon.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);
static void HealPlayerBoxes(void);

void HealPlayerParty(void)
{
    u32 i;
    for (i = 0; i < gPlayerPartyCount; i++)
        HealPokemon(&gPlayerParty[i]);
    if (OW_PC_HEAL >= GEN_8)
        HealPlayerBoxes();

    // Recharge Tera Orb, if possible.
    if (B_FLAG_TERA_ORB_CHARGED != 0 && CheckBagHasItem(ITEM_TERA_ORB, 1))
        FlagSet(B_FLAG_TERA_ORB_CHARGED);

}

static bool8 IsBoxMonDead(u8 boxId, u8 boxPosition)
{
    struct Pokemon tempMon;
    BoxMonAtToMon(boxId, boxPosition, &tempMon);
    return GetMonData(&tempMon, MON_DATA_HP, NULL) == 0;
}

static void HealPlayerBoxes(void)
{
    int boxId, boxPosition;
    struct BoxPokemon *boxMon;
    bool8 nuzlocke = IsNuzlockeActive() || IsNuzlockeEasyActive();

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            boxMon = &gPokemonStoragePtr->boxes[boxId][boxPosition];
            if (!GetBoxMonData(boxMon, MON_DATA_SANITY_HAS_SPECIES))
                continue;
            if (nuzlocke && IsBoxMonDead(boxId, boxPosition))
                continue;
            HealBoxPokemon(boxMon);
        }
    }
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    if (IsNuzlockeActive() || IsNuzlockeEasyActive() || RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON))
        species = GetRandomSpeciesSimilarBst(species);

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    // tx_randomizer_and_challenges: with a party limit of 1 the only party slot is
    // always taken, and handing the Egg over would leave the player with a party of
    // just an Egg. Send it straight to the PC instead of refusing the gift.
    if (GetMaxPartySize() == 1)
    {
        SetMonData(&mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
        SetMonData(&mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
        SetMonData(&mon, MON_DATA_OT_ID, gSaveBlock2Ptr->playerTrainerId);
        return CopyMonToPC(&mon);
    }

    return GiveCapturedMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool32 CheckPartyMonHasHeldItem(enum Item item)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY_E_READER);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY_E_READER), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, enum Item item)
{
    u8 heldItem[2];

    #if RANDOMIZER_AVAILABLE
    if (RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON) && !FlagGet(FLAG_SPARRING_NO_EVS))
        species = RandomizeMon(RANDOMIZER_REASON_FIXED_ENCOUNTER, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE), Random32(), species);
    #endif

    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

// Builds a shiny personality that also honors Synchronize/Cute Charm. Rerolling blindly
// until a personality is both shiny and the right nature would take ~200k tries, so the
// upper half is derived from the lower half instead: every candidate is shiny by
// construction and only the nature/gender constraints have to be rerolled.
static u32 GenerateShinyPersonalityForOtId(u32 otId, u16 species, u8 gender, u8 nature)
{
    u32 otXor = HIHALF(otId) ^ LOHALF(otId);
    u32 personality;

    do {
        u32 lo = Random();
        u32 hi = (otXor ^ lo ^ (Random() % SHINY_ODDS)) & 0xFFFF;
        personality = (hi << 16) | lo;
    } while ((nature != NATURE_RANDOM && nature != GetNatureFromPersonality(personality))
          || (gender != MON_GENDER_RANDOM && gender != GetGenderFromSpeciesAndPersonality(species, personality)));

    return personality;
}

void CreateShinyScriptedMon(u16 species, u8 level, enum Item item)
{
    u8 heldItem[2];

    #if RANDOMIZER_AVAILABLE
    if (RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON))
        species = RandomizeFixedEncounterMon(species,
            gSaveBlock1Ptr->location.mapNum,
            gSaveBlock1Ptr->location.mapGroup,
            gObjectEvents[gSelectedObjectEvent].localId);
    #endif

    // TODO: item randomization (HnS randomized the held item under tx_Random_Items)

    ZeroEnemyPartyMons();

    u32 otId = gSaveBlock2Ptr->playerTrainerId[0]
             | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
             | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
             | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

    u32 shinyPersonality = GenerateShinyPersonalityForOtId(otId, species,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species));

    CreateMonWithIVs(&gEnemyParty[0], species, level, shinyPersonality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
    SetNuzlockeChecks();
}

void CreateScriptedWildBossMon(u16 species, u8 level, enum Item item, enum Move moves[MAX_MON_MOVES])
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species, GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species),
                                        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species), RANDOM_UNOWN_LETTER);

    struct Pokemon *mon = &gEnemyParty[0];

    CreateMonWithIVs(mon, species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);

    if (moves[0] == MOVE_NONE) {
        GiveBoxMonInitialMoveset(&mon->box);
    }
    else {

        for (u32 i = 0; i < MAX_MON_MOVES; i++) {
            SetBoxMonData(&mon->box, MON_DATA_MOVE1 + i, &moves[i]);
            u32 pp = GetMovePP(moves[i]);
            SetBoxMonData(&mon->box, MON_DATA_PP1 + i, &pp);
        }
    }
    if (item) {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void CreateScriptedDoubleWildBossMon(u16 species1, u8 level1, enum Item item1, enum Move moves1[MAX_MON_MOVES],
                                     u16 species2, u8 level2, enum Item item2, enum Move moves2[MAX_MON_MOVES])
{
    u8 heldItem1[2];
    u8 heldItem2[2];
    struct Pokemon *mon;
    u32 personality;
    ZeroEnemyPartyMons();

    personality = GetMonPersonality(species1, GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species1),
                                    GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species1), RANDOM_UNOWN_LETTER);

    mon = &gEnemyParty[0];
    CreateMonWithIVs(mon, species1, level1, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);

    if (moves1[0] == MOVE_NONE) {
        GiveBoxMonInitialMoveset(&mon->box);
    }
    else {

        for (u32 i = 0; i < MAX_MON_MOVES; i++) {
            SetBoxMonData(&mon->box, MON_DATA_MOVE1 + i, &moves1[i]);
            u32 pp = GetMovePP(moves1[i]);
            SetBoxMonData(&mon->box, MON_DATA_PP1 + i, &pp);
        }
    }

    if (item1) {
        heldItem1[0] = item1;
        heldItem1[1] = item1 >> 8;
        SetMonData(mon, MON_DATA_HELD_ITEM, heldItem1);
    }

    personality = GetMonPersonality(species2, GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species2),
                                    GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species2), RANDOM_UNOWN_LETTER);

    mon = &gEnemyParty[1];
    CreateMonWithIVs(mon, species2, level2, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);

    if (moves2[0] == MOVE_NONE) {
        GiveBoxMonInitialMoveset(&mon->box);
    }
    else {

        for (u32 i = 0; i < MAX_MON_MOVES; i++) {
            SetBoxMonData(&mon->box, MON_DATA_MOVE1 + i, &moves2[i]);
            u32 pp = GetMovePP(moves2[i]);
            SetBoxMonData(&mon->box, MON_DATA_PP1 + i, &pp);
        }
    }

    if (item2) {
        heldItem2[0] = item2;
        heldItem2[1] = item2 >> 8;
        SetMonData(mon, MON_DATA_HELD_ITEM, heldItem2);
    }
}

void CreateScriptedDoubleWildMon(u16 species1, u8 level1, enum Item item1, u16 species2, u8 level2, enum Item item2)
{
    u8 heldItem1[2];
    u8 heldItem2[2];

    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species1,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species1),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species1),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species1, level1, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    if (item1)
    {
        heldItem1[0] = item1;
        heldItem1[1] = item1 >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem1);
    }

    personality = GetMonPersonality(species2,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species2),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species2),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[1], species2, level2, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[1]);
    if (item2)
    {
        heldItem2[0] = item2;
        heldItem2[1] = item2 >> 8;
        SetMonData(&gEnemyParty[1], MON_DATA_HELD_ITEM, heldItem2);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, enum Move move, u8 slot)
{
// Allows monIndex to go out of bounds of gPlayerParty. Doesn't occur in vanilla
#ifdef BUGFIX
    if (monIndex >= PARTY_SIZE)
#else
    if (monIndex > PARTY_SIZE)
#endif
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected Pokémon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}

void CanHyperTrain(struct ScriptContext *ctx)
{
    u32 stat = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    assertf(stat < NUM_STATS, "invalid stat: %d", stat)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    CalculatePlayerPartyCount();
    assertf(partyIndex < gPlayerPartyCount, "invalid party index: %d", partyIndex)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    if (!GetMonData(&gPlayerParty[partyIndex], MON_DATA_HYPER_TRAINED_HP + stat)
     && GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP_IV + stat) < MAX_PER_STAT_IVS)
    {
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void HyperTrain(struct ScriptContext *ctx)
{
    u32 stat = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    assertf(stat < NUM_STATS, "invalid stat: %d", stat)
    {
        return;
    }

    CalculatePlayerPartyCount();
    assertf(partyIndex < gPlayerPartyCount, "invalid party index: %d", partyIndex)
    {
        return;
    }

    bool32 data = TRUE;
    SetMonData(&gPlayerParty[partyIndex], MON_DATA_HYPER_TRAINED_HP + stat, &data);
    CalculateMonStats(&gPlayerParty[partyIndex]);
}

void HasGigantamaxFactor(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR);
    else
        gSpecialVar_Result = FALSE;
}

void ToggleGigantamaxFactor(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    gSpecialVar_Result = FALSE;

    if (partyIndex < PARTY_SIZE)
    {
        bool32 gigantamaxFactor;

        if (gSpeciesInfo[SanitizeSpeciesId(GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES))].isMythical)
            return;

        gigantamaxFactor = GetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR);
        gigantamaxFactor = !gigantamaxFactor;
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR, &gigantamaxFactor);
        gSpecialVar_Result = TRUE;
    }
}

void CheckTeraType(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    gSpecialVar_Result = TYPE_NONE;

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_TERA_TYPE);
}

void SetTeraType(struct ScriptContext *ctx)
{
    enum Type type = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (type < NUMBER_OF_MON_TYPES && partyIndex < PARTY_SIZE)
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_TERA_TYPE, &type);
}

/* Creates a Pokemon via script
 * if side/slot are assigned, it will create the mon at the assigned party location
 * if slot == PARTY_SIZE, it will give the mon to first available party or storage slot
 */
static u32 ScriptGiveMonParameterized(u8 side, u8 slot, u16 species, u8 level, enum Item item, enum PokeBall ball, u8 nature, u8 abilityNum, u8 gender, u16 *evs, u16 *ivs, enum Move *moves, enum ShinyMode shinyMode, bool8 gmaxFactor, enum Type teraType, u8 dmaxLevel)
{
    struct Pokemon mon;
    u32 i;
    bool32 isShiny;

    u32 personality = GetMonPersonality(species, gender, nature, RANDOM_UNOWN_LETTER);
    CreateMon(&mon, species, level, personality, OTID_STRUCT_PLAYER_ID);

    // shininess
    if (shinyMode == SHINY_MODE_ALWAYS || (P_FLAG_FORCE_SHINY != 0 && FlagGet(P_FLAG_FORCE_SHINY)))
        isShiny = TRUE;
    else if (shinyMode == SHINY_MODE_NEVER || (P_FLAG_FORCE_NO_SHINY != 0 && FlagGet(P_FLAG_FORCE_NO_SHINY)))
        isShiny = FALSE;
    else
        isShiny = GetMonData(&mon, MON_DATA_IS_SHINY);

    SetMonData(&mon, MON_DATA_IS_SHINY, &isShiny);

    // gigantamax factor
    SetMonData(&mon, MON_DATA_GIGANTAMAX_FACTOR, &gmaxFactor);

    // Dynamax Level
    SetMonData(&mon, MON_DATA_DYNAMAX_LEVEL, &dmaxLevel);

    // tera type
    if (teraType == TYPE_NONE || teraType == TYPE_MYSTERY || teraType >= NUMBER_OF_MON_TYPES)
        teraType = GetTeraTypeFromPersonality(&mon);
    SetMonData(&mon, MON_DATA_TERA_TYPE, &teraType);

    // EV and IV
    for (i = 0; i < NUM_STATS; i++)
    {
        // EV
        if (evs[i] <= MAX_PER_STAT_EVS)
            SetMonData(&mon, MON_DATA_HP_EV + i, &evs[i]);

        // IV
        if (ivs[i] <= MAX_PER_STAT_IVS && gSaveBlock3Ptr->challengeSettings.tx_Challenges_MaxPartyIVs == 0)
            SetMonData(&mon, MON_DATA_HP_IV + i, &ivs[i]);
    }
    if (gSaveBlock3Ptr->challengeSettings.tx_Challenges_MaxPartyIVs != 0)
        SetBoxMonIVs(&mon.box, USE_RANDOM_IVS);
    CalculateMonStats(&mon);

    // moves
    bool32 all_default_flag = TRUE;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_DEFAULT)
        {
            all_default_flag = FALSE;
            break;
        }
    }
    if (all_default_flag)
    {
        GiveMonInitialMoveset(&mon);
    }
    else
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moves[i] == MOVE_NONE)
                break;
            if (moves[i] < MOVES_COUNT)
            {
                SetMonMoveSlot(&mon, moves[i], i);
            }
            else if (moves[i] == MOVE_DEFAULT)
            {
                GiveMonDefaultMove(&mon, i);
                continue;
            }
            else
            {
                assertf(FALSE, "invalid move: %d", moves[i]) {}
            }
        }
    }

    // ability
    if (abilityNum != NUM_ABILITY_PERSONALITY)
    {
        assertf(abilityNum < NUM_ABILITY_SLOTS && GetAbilityBySpecies(species, abilityNum) != ABILITY_NONE,
                "invalid ability num %d for species %d", abilityNum, species)
        {
            // If the ability num is invalid, we loop to find a valid one
            do {
                abilityNum = Random() % NUM_ABILITY_SLOTS; // includes hidden abilities
            } while (GetAbilityBySpecies(species, abilityNum) == ABILITY_NONE);
        }
        SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    }

    // ball
    if (ball > POKEBALL_COUNT)
        ball = BALL_POKE;
    SetMonData(&mon, MON_DATA_POKEBALL, &ball);

    // held item
    SetMonData(&mon, MON_DATA_HELD_ITEM, &item);

    // In case a mon with a form changing item is given. Eg: SPECIES_ARCEUS_NORMAL with ITEM_SPLASH_PLATE will transform into SPECIES_ARCEUS_WATER upon gifted.
    TryFormChange(&mon, FORM_CHANGE_ITEM_HOLD);

    if (side == B_SIDE_PLAYER)
        return GiveScriptedMonToPlayer(&mon, slot);

    assertf(slot < PARTY_SIZE, "invalid slot: %d", slot)
    {
        return MON_CANT_GIVE;
    }
    CopyMon(&gEnemyParty[slot], &mon, sizeof(struct Pokemon));
    return MON_GIVEN_TO_PARTY;
}


struct MegaGiftPair
{
    u16 species;
    u16 item;
};

static const struct MegaGiftPair sMegaGiftPairs[] =
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

void GiveRandomMegaGift(void)
{
    const struct MegaGiftPair *pair = &sMegaGiftPairs[Random() % ARRAY_COUNT(sMegaGiftPairs)];
    u16 evs[NUM_STATS] = {0};
    u16 ivs[NUM_STATS];
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};
    u32 i;

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    StringCopy(gStringVar1, GetSpeciesName(pair->species));
    for (i = 0; i < NUM_STATS; i++)
        ivs[i] = Random() % (MAX_PER_STAT_IVS + 1);

    gSpecialVar_Result = ScriptGiveMonParameterized(
        B_SIDE_PLAYER, PARTY_SIZE, pair->species, 15, pair->item, BALL_POKE,
        GetSynchronizedNature(GIFTMON_ORIGIN, pair->species),
        NUM_ABILITY_PERSONALITY,
        GetSynchronizedGender(GIFTMON_ORIGIN, pair->species),
        evs, ivs, moves, SHINY_MODE_RANDOM, FALSE, NUMBER_OF_MON_TYPES, 0);
}

u32 ScriptGiveMon(u16 species, u8 level, enum Item item)
{
    struct Pokemon mon;
    u8 heldItem[2];

#if RANDOMIZER_AVAILABLE
    if (!FlagGet(FLAG_SYS_POKEMON_GET))
    {
        if (RandomizerFeatureEnabled(RANDOMIZE_STARTER_AND_GIFT_MON))
            species = RandomizeMon(RANDOMIZER_REASON_STARTER_MON, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE), Random32(), species);
    }
    else
    {
        if (RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON))
            species = RandomizeMon(RANDOMIZER_REASON_FIXED_ENCOUNTER, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE), Random32(), species);
    }
#endif
    if (IsOneTypeChallengeActive() && !FlagGet(FLAG_SYS_POKEMON_GET))
        species = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    CreateRandomMon(&mon, species, level);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    }

    return GiveScriptedMonToPlayer(&mon, PARTY_SIZE);
}

#define PARSE_FLAG(n, default_) (flags & (1 << (n))) ? VarGet(ScriptReadHalfword(ctx)) : (default_)

#define ADD_MOVE_IF_NOT_DEFAULT(i, move)               \
    if (move && move != MOVE_DEFAULT)                  \
    {                                                  \
        moves[i] = move;                               \
        i++;                                           \
    }

#define ADD_MOVE_IF_DEFAULT(i, move)                   \
    if (moves[i] == MOVE_NONE && move == MOVE_DEFAULT) \
    {                                                  \
        moves[i] = MOVE_DEFAULT;                       \
        i++;                                           \
    }

/* Give or create a mon to either player or opponent
 */


void ScrCmd_createmon(struct ScriptContext *ctx)
{
    u8 side            = ScriptReadByte(ctx);
    u8 slot            = ScriptReadByte(ctx);
    u16 species        = VarGet(ScriptReadHalfword(ctx));
    u8 level           = VarGet(ScriptReadHalfword(ctx));

    u32 flags          = ScriptReadWord(ctx);
    enum Item item     = PARSE_FLAG(0, ITEM_NONE);
    enum PokeBall ball = PARSE_FLAG(1, BALL_POKE);
    u8 nature          = PARSE_FLAG(2, NATURE_RANDOM);
    u8 abilityNum      = PARSE_FLAG(3, NUM_ABILITY_PERSONALITY);
    u8 gender          = PARSE_FLAG(4, MON_GENDER_RANDOM);

    u32 i;
    u16 evs[NUM_STATS];
    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = PARSE_FLAG(5 + i, 0);
        assertf(evs[i] <= MAX_PER_STAT_EVS, "invalid ev value of %d above maximum of %d", evs[i], MAX_PER_STAT_EVS)
        {
            evs[i] = MAX_PER_STAT_EVS;
        }
    }

    u16 ivs[NUM_STATS];
    u32 nonFixedIvCount = 0;
    enum Stat availableIVs[NUM_STATS];
    enum Stat selectedIvs[NUM_STATS];
    for (i = 0; i < NUM_STATS; i++)
    {
        ivs[i] = PARSE_FLAG(11 + i, USE_RANDOM_IVS);
        assertf(ivs[i] <= USE_RANDOM_IVS, "invalid iv value of %d above maximum of %d", ivs[i], MAX_PER_STAT_IVS)
        {
            ivs[i] = MAX_PER_STAT_IVS;
        }
        if (ivs[i] == USE_RANDOM_IVS)
        {
            availableIVs[nonFixedIvCount] = i;
            ivs[i] = Random() % (MAX_PER_STAT_IVS + 1);
            nonFixedIvCount++;
        }
    }

    // Perfect IV calculation
    if (gSpeciesInfo[species].perfectIVCount != 0)
    {
        // Select the IVs that will be perfected.
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            u8 index = Random() % (nonFixedIvCount - i);
            selectedIvs[i] = availableIVs[index];
            RemoveIVIndexFromList(availableIVs, index);
        }
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            ivs[selectedIvs[i]] = MAX_PER_STAT_IVS;
        }
    }

    enum Move move1          = PARSE_FLAG(17, MOVE_DEFAULT);
    enum Move move2          = PARSE_FLAG(18, MOVE_DEFAULT);
    enum Move move3          = PARSE_FLAG(19, MOVE_DEFAULT);
    enum Move move4          = PARSE_FLAG(20, MOVE_DEFAULT);
    enum ShinyMode shinyMode = PARSE_FLAG(21, SHINY_MODE_RANDOM);
    bool8 gmaxFactor         = PARSE_FLAG(22, FALSE);
    enum Type teraType       = PARSE_FLAG(23, NUMBER_OF_MON_TYPES);
    u8 dmaxLevel             = PARSE_FLAG(24, 0);

    enum Move moves[MAX_MON_MOVES];
    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = MOVE_NONE;

    i = 0;
    //Reorder moves to put non-default moves first, default moves second and empty moves last
    ADD_MOVE_IF_NOT_DEFAULT(i, move1)
    ADD_MOVE_IF_NOT_DEFAULT(i, move2)
    ADD_MOVE_IF_NOT_DEFAULT(i, move3)
    ADD_MOVE_IF_NOT_DEFAULT(i, move4)
    ADD_MOVE_IF_DEFAULT(i, move1)
    ADD_MOVE_IF_DEFAULT(i, move2)
    ADD_MOVE_IF_DEFAULT(i, move3)
    ADD_MOVE_IF_DEFAULT(i, move4)

    enum GeneratedMonOrigin origin;
    if (side == 0)
    {
        Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
        origin = GIFTMON_ORIGIN;
        if (FlagGet(FLAG_SYS_POKEMON_GET) && (IsNuzlockeActive() || IsNuzlockeEasyActive() || RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON)))
            species = GetRandomSpeciesSimilarBst(species);
    }
    else
    {
        Script_RequestEffects(SCREFF_V1);
        origin = STATIC_WILDMON_ORIGIN;
    }

#if RANDOMIZER_AVAILABLE
    if (FlagGet(FLAG_SYS_POKEMON_GET) && origin != GIFTMON_ORIGIN)
    {
        if (RandomizerFeatureEnabled(RANDOMIZE_FIXED_MON))
            species = RandomizeMon(RANDOMIZER_REASON_FIXED_ENCOUNTER, GetRandomizerOption(RANDOMIZER_OPTION_SPECIES_MODE), Random32(), species);
    }
#endif

    if (gender == MON_GENDER_MAY_CUTE_CHARM)
        gender = GetSynchronizedGender(origin, species);
    if (nature == NATURE_MAY_SYNCHRONIZE)
        nature = GetSynchronizedNature(origin, species);

    gSpecialVar_Result = ScriptGiveMonParameterized(side, slot, species, level, item, ball, nature, abilityNum, gender, evs, ivs, moves, shinyMode, gmaxFactor, teraType, dmaxLevel);
}

#undef PARSE_FLAG

void Script_GetChosenMonOffensiveEVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonDefensiveEVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonOffensiveIVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonDefensiveIVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_SetStatus1(struct ScriptContext *ctx)
{
    u32 status1 = VarGet(ScriptReadHalfword(ctx));
    u32 slot = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (slot >= PARTY_SIZE)
    {
        u16 species;

        for (slot = 0; slot < PARTY_SIZE; slot++)
        {
            species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
             && species != SPECIES_EGG
             && GetMonData(&gPlayerParty[slot], MON_DATA_HP) != 0)
                SetMonData(&gPlayerParty[slot], MON_DATA_STATUS, &status1);
        }
    }
    else
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_STATUS, &status1);
    }
}

void Script_SetKO(struct ScriptContext *ctx)
{
    u32 slot = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (slot < PARTY_SIZE)
    {
        u32 hp = 0;
        SetMonData(&gPlayerParty[slot], MON_DATA_HP, &hp);
    }
}

// Superentrenamiento de Yami
// gSpecialVar_0x8004: Slot del Pokémon en el equipo (0 a 5)
// gSpecialVar_0x8005: Stat a entrenar (0=HP, 1=ATK, 2=DEF, 3=SPEED, 4=SPATK, 5=SPDEF)
// Retorna en gSpecialVar_Result: TRUE si se puede entrenar, FALSE si ya está al máximo (252 o 510 total)
void YamiSuperTraining_CanTrainStat(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 stat = gSpecialVar_0x8005;

    if (slot >= gPlayerPartyCount || stat >= NUM_STATS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 evField;
    switch (stat)
    {
    case 0: evField = MON_DATA_HP_EV; break;
    case 1: evField = MON_DATA_ATK_EV; break;
    case 2: evField = MON_DATA_DEF_EV; break;
    case 3: evField = MON_DATA_SPEED_EV; break;
    case 4: evField = MON_DATA_SPATK_EV; break;
    case 5: evField = MON_DATA_SPDEF_EV; break;
    default:
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 currentStatEv = GetMonData(mon, evField);
    if (currentStatEv >= MAX_PER_STAT_EVS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u32 totalEvs = GetMonData(mon, MON_DATA_HP_EV)
                 + GetMonData(mon, MON_DATA_ATK_EV)
                 + GetMonData(mon, MON_DATA_DEF_EV)
                 + GetMonData(mon, MON_DATA_SPEED_EV)
                 + GetMonData(mon, MON_DATA_SPATK_EV)
                 + GetMonData(mon, MON_DATA_SPDEF_EV);

    if (totalEvs >= MAX_TOTAL_EVS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    gSpecialVar_Result = TRUE;
}

void YamiSuperTraining_AddEVs(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 stat = gSpecialVar_0x8005;

    if (slot >= gPlayerPartyCount || stat >= NUM_STATS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 evField;
    switch (stat)
    {
    case 0: evField = MON_DATA_HP_EV; break;
    case 1: evField = MON_DATA_ATK_EV; break;
    case 2: evField = MON_DATA_DEF_EV; break;
    case 3: evField = MON_DATA_SPEED_EV; break;
    case 4: evField = MON_DATA_SPATK_EV; break;
    case 5: evField = MON_DATA_SPDEF_EV; break;
    default:
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 currentStatEv = GetMonData(mon, evField);
    if (currentStatEv >= MAX_PER_STAT_EVS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u32 totalEvs = GetMonData(mon, MON_DATA_HP_EV)
                 + GetMonData(mon, MON_DATA_ATK_EV)
                 + GetMonData(mon, MON_DATA_DEF_EV)
                 + GetMonData(mon, MON_DATA_SPEED_EV)
                 + GetMonData(mon, MON_DATA_SPATK_EV)
                 + GetMonData(mon, MON_DATA_SPDEF_EV);

    if (totalEvs >= MAX_TOTAL_EVS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 addAmount = 64;
    if (currentStatEv + addAmount > MAX_PER_STAT_EVS)
        addAmount = MAX_PER_STAT_EVS - currentStatEv;

    if (totalEvs + addAmount > MAX_TOTAL_EVS)
        addAmount = MAX_TOTAL_EVS - totalEvs;

    if (addAmount == 0)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 newEv = currentStatEv + addAmount;
    SetMonData(mon, evField, &newEv);
    CalculateMonStats(mon);
    gSpecialVar_Result = TRUE;
}

void YamiSuperTraining_ResetEVs(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 zero = 0;
    SetMonData(mon, MON_DATA_HP_EV, &zero);
    SetMonData(mon, MON_DATA_ATK_EV, &zero);
    SetMonData(mon, MON_DATA_DEF_EV, &zero);
    SetMonData(mon, MON_DATA_SPEED_EV, &zero);
    SetMonData(mon, MON_DATA_SPATK_EV, &zero);
    SetMonData(mon, MON_DATA_SPDEF_EV, &zero);
    CalculateMonStats(mon);
    gSpecialVar_Result = TRUE;
}

static u8 GetPreEvolutionAbilities(u16 targetSpecies, enum Ability currentAbility, enum Ability *outAbilities, u8 maxAbilities)
{
    u16 queue[8];
    u8 queueCount = 0;
    u8 head = 0;
    u8 abilityCount = 0;
    u32 i, j;

    targetSpecies = SanitizeSpeciesId(targetSpecies);
    queue[queueCount++] = targetSpecies;

    // Recorrer árbol de ancestros buscando especies que evolucionen a las de la cola
    while (head < queueCount && queueCount < ARRAY_COUNT(queue))
    {
        u16 curr = queue[head++];
        for (j = 1; j < NUM_SPECIES; j++)
        {
            if (!IsSpeciesEnabled(j))
                continue;
            const struct Evolution *evos = GetSpeciesEvolutions(j);
            if (evos == NULL)
                continue;
            for (i = 0; evos[i].method != EVOLUTIONS_END; i++)
            {
                if (IsSpeciesEnabled(evos[i].targetSpecies) && SanitizeSpeciesId(evos[i].targetSpecies) == curr)
                {
                    u16 pre = SanitizeSpeciesId(j);
                    // Comprobar si ya está en la cola para evitar bucles
                    bool32 alreadyQueued = FALSE;
                    u32 q;
                    for (q = 0; q < queueCount; q++)
                    {
                        if (queue[q] == pre)
                        {
                            alreadyQueued = TRUE;
                            break;
                        }
                    }
                    if (!alreadyQueued && queueCount < ARRAY_COUNT(queue))
                        queue[queueCount++] = pre;
                    break;
                }
            }
        }
    }

    // Para cada ancestro (excluyendo la especie actual queue[0]), extraer sus habilidades
    for (i = 1; i < queueCount; i++)
    {
        u16 ancSpecies = queue[i];
        u8 slot;
        for (slot = 0; slot < NUM_ABILITY_SLOTS; slot++)
        {
            enum Ability ab = GetSpeciesAbility(ancSpecies, slot);
            if (ab != ABILITY_NONE && ab != currentAbility)
            {
                // Comprobar si ya está en outAbilities
                bool32 duplicate = FALSE;
                u32 a;
                for (a = 0; a < abilityCount; a++)
                {
                    if (outAbilities[a] == ab)
                    {
                        duplicate = TRUE;
                        break;
                    }
                }
                if (!duplicate && abilityCount < maxAbilities)
                    outAbilities[abilityCount++] = ab;
            }
        }
    }

    return abilityCount;
}

void DaraOtaku_CheckAndPrepareAbilities(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = 0;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = 0;
        return;
    }

    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);

    // Buffering species nickname
    GetMonNickname(mon, gStringVar1);

    // Current ability name -> gStringVar2
    enum Ability currentAbility = GetMonAbility(mon);
    StringCopy(gStringVar2, gAbilitiesInfo[currentAbility].name);

    enum Ability ab0 = GetSpeciesAbility(species, 0);
    enum Ability ab1 = GetSpeciesAbility(species, 1);
    enum Ability abHidden = GetSpeciesAbility(species, 2);

    bool32 hasSecondary = (ab1 != ABILITY_NONE && ab1 != ab0);
    bool32 hasHidden = (abHidden != ABILITY_NONE && abHidden != ab0 && abHidden != ab1);

    // Mode determination:
    // If current is normal (0 or 1):
    u8 targetNormalSlot = (currentAbilityNum == 0) ? 1 : 0;
    enum Ability targetNormalAbility = GetSpeciesAbility(species, targetNormalSlot);
    bool32 canSwitchNormal = (hasSecondary && targetNormalAbility != ABILITY_NONE && targetNormalAbility != currentAbility);
    bool32 canSwitchHidden = (hasHidden && currentAbilityNum != 2);

    // If currently at hidden ability (slot 2):
    // Can revert to normal slot 0
    if (currentAbilityNum == 2)
    {
        canSwitchNormal = (ab0 != ABILITY_NONE);
        targetNormalSlot = 0;
        targetNormalAbility = ab0;
        canSwitchHidden = FALSE;
    }

    // Buffering target ability names for single-choice confirmation
    if (canSwitchNormal && !canSwitchHidden)
        StringCopy(gStringVar3, gAbilitiesInfo[targetNormalAbility].name);
    else if (!canSwitchNormal && canSwitchHidden)
        StringCopy(gStringVar3, gAbilitiesInfo[abHidden].name);
    else if (canSwitchNormal && canSwitchHidden)
        StringCopy(gStringVar3, gAbilitiesInfo[targetNormalAbility].name);
    else
        StringCopy(gStringVar3, gText_None);

    // Results:
    // 0: Cannot change any standard ability
    // 1: Can change to normal only
    // 2: Can change to hidden only
    // 3: Can change to both
    if (canSwitchNormal && canSwitchHidden)
        gSpecialVar_Result = 3;
    else if (canSwitchNormal)
        gSpecialVar_Result = 1;
    else if (canSwitchHidden)
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}

void DaraOtaku_PrepareChoiceAbility(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 choice = gSpecialVar_0x8005; // 1 = Normal, 2 = Hidden

    if (slot >= gPlayerPartyCount)
        return;

    struct Pokemon *mon = &gPlayerParty[slot];
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);

    if (choice == 1)
    {
        u8 targetNormalSlot = (currentAbilityNum == 0) ? 1 : 0;
        if (currentAbilityNum == 2)
            targetNormalSlot = 0;
        enum Ability targetNormalAbility = GetSpeciesAbility(species, targetNormalSlot);
        StringCopy(gStringVar3, gAbilitiesInfo[targetNormalAbility].name);
    }
    else if (choice == 2)
    {
        enum Ability abHidden = GetSpeciesAbility(species, 2);
        StringCopy(gStringVar3, gAbilitiesInfo[abHidden].name);
    }
}

void DaraOtaku_ApplyAbilityChange(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 choice = gSpecialVar_0x8005; // 1 = Normal, 2 = Hidden

    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    u8 targetSlot = 0;

    if (choice == 1) // Normal ability
    {
        if (currentAbilityNum == 2)
            targetSlot = 0;
        else
            targetSlot = (currentAbilityNum == 0) ? 1 : 0;
    }
    else if (choice == 2) // Hidden ability
    {
        targetSlot = 2;
    }
    else
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    SetMonData(mon, MON_DATA_ABILITY_NUM, &targetSlot);
    GetMonNickname(mon, gStringVar1);
    enum Ability newAbility = GetMonAbility(mon);
    StringCopy(gStringVar2, gAbilitiesInfo[newAbility].name);
    gSpecialVar_Result = TRUE;
}

void DaraOtaku_CheckAndPrepareEvolutionAbilities(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = 0;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = 0;
        return;
    }

    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    enum Ability currentAbility = GetMonAbility(mon);
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[currentAbility].name);

    enum Ability candidateAbilities[8];
    u8 count = GetPreEvolutionAbilities(species, currentAbility, candidateAbilities, ARRAY_COUNT(candidateAbilities));

    if (count == 0)
    {
        gSpecialVar_Result = 0;
        return;
    }

    MultichoiceDynamic_InitStack(count + 1);

    u8 i;
    for (i = 0; i < count; i++)
    {
        enum Ability ab = candidateAbilities[i];
        const u8 *abName = gAbilitiesInfo[ab].name;
        u8 *nameBuffer = Alloc(StringLength(abName) + 1);
        if (nameBuffer != NULL)
        {
            struct ListMenuItem item;
            StringCopy(nameBuffer, abName);
            item.name = nameBuffer;
            item.id = ab;
            MultichoiceDynamic_PushElement(item);
        }
    }

    // Cancel option
    {
        u8 *cancelName = Alloc(StringLength(gText_Cancel2) + 1);
        if (cancelName != NULL)
        {
            struct ListMenuItem cancelItem;
            StringCopy(cancelName, gText_Cancel2);
            cancelItem.name = cancelName;
            cancelItem.id = ABILITY_NONE;
            MultichoiceDynamic_PushElement(cancelItem);
        }
    }

    if (!MultichoiceDynamic_StackEmpty())
        gSpecialVar_Result = count;
    else
    {
        MultichoiceDynamic_DestroyStack();
        gSpecialVar_Result = 0;
    }
}

void DaraOtaku_PrepareChosenEvoAbilityName(void)
{
    enum Ability chosenAbility = (enum Ability)gSpecialVar_0x8005;
    if (chosenAbility < ABILITIES_COUNT)
        StringCopy(gStringVar3, gAbilitiesInfo[chosenAbility].name);
    else
        StringCopy(gStringVar3, gText_None);
}

void DaraOtaku_ApplyEvolutionAbilityChange(void)
{
    u8 slot = gSpecialVar_0x8004;
    enum Ability chosenAbility = (enum Ability)gSpecialVar_0x8005;

    if (slot >= gPlayerPartyCount || chosenAbility == ABILITY_NONE)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 targetSlot = 0;
    u8 s;
    bool32 foundSlot = FALSE;

    for (s = 0; s < NUM_ABILITY_SLOTS; s++)
    {
        if (GetSpeciesAbility(species, s) == chosenAbility)
        {
            targetSlot = s;
            foundSlot = TRUE;
            break;
        }
    }

    if (foundSlot)
    {
        SetMonData(mon, MON_DATA_ABILITY_NUM, &targetSlot);
    }
    else
    {
        // En caso de especies donde la preevolución tiene una habilidad distinta y no está en los slots actuales,
        // asignamos el slot disponible más coherente
        SetMonData(mon, MON_DATA_ABILITY_NUM, &targetSlot);
    }

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[chosenAbility].name);
    gSpecialVar_Result = TRUE;
}

#include "data/regional_form_families.h"

static const u8 sText_MaleGenderName[] = _("MACHO");
static const u8 sText_FemaleGenderName[] = _("HEMBRA");

void DoctoriniBea_CheckGender(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 genderRatio = gSpeciesInfo[species].genderRatio;

    // Reject genderless or single-gender species
    if (genderRatio == MON_MALE || genderRatio == MON_FEMALE || genderRatio == MON_GENDERLESS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 currentGender = GetMonGender(mon);
    GetMonNickname(mon, gStringVar1);

    if (currentGender == MON_MALE)
    {
        StringCopy(gStringVar2, sText_MaleGenderName);
        StringCopy(gStringVar3, sText_FemaleGenderName);
    }
    else
    {
        StringCopy(gStringVar2, sText_FemaleGenderName);
        StringCopy(gStringVar3, sText_MaleGenderName);
    }

    gSpecialVar_Result = TRUE;
}

void DoctoriniBea_ApplyGenderChange(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 genderRatio = gSpeciesInfo[species].genderRatio;
    if (genderRatio == MON_MALE || genderRatio == MON_FEMALE || genderRatio == MON_GENDERLESS)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u8 currentGender = GetMonGender(mon);
    u8 targetGender = (currentGender == MON_MALE) ? MON_FEMALE : MON_MALE;
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    bool32 isShiny = IsMonShiny(mon);
    u32 originalNature = personality % NUM_NATURES;
    u32 newPersonality = personality;

    // Search for a personality value with the exact same nature that yields targetGender
    u32 i;
    for (i = 0; i < 20000; i++)
    {
        // Try shifting personality by multiples of NUM_NATURES (25)
        u32 candidate = (targetGender == MON_FEMALE) ? (originalNature + i * NUM_NATURES) : (originalNature + (i + 15) * NUM_NATURES);
        if (GetGenderFromSpeciesAndPersonality(species, candidate) == targetGender)
        {
            newPersonality = candidate;
            break;
        }
    }

    SetMonData(mon, MON_DATA_PERSONALITY, &newPersonality);
    SetMonData(mon, MON_DATA_IS_SHINY, &isShiny);
    CalculateMonStats(mon);

    GetMonNickname(mon, gStringVar1);
    if (targetGender == MON_MALE)
        StringCopy(gStringVar2, sText_MaleGenderName);
    else
        StringCopy(gStringVar2, sText_FemaleGenderName);

    gSpecialVar_Result = TRUE;
}

static bool32 IsExcludedBattleForm(u16 species)
{
    if (species == SPECIES_NONE)
        return TRUE;

    // Check mega, primal, totem or gmax
    if (gSpeciesInfo[species].isMegaEvolution
        || gSpeciesInfo[species].isPrimalReversion
        || gSpeciesInfo[species].isTotem
        || gSpeciesInfo[species].isGigantamax)
        return TRUE;

    // Check battle-only / in-battle forms
    switch (species)
    {
    case SPECIES_DARMANITAN_ZEN:
    case SPECIES_DARMANITAN_GALAR_ZEN:
    case SPECIES_CASTFORM_SUNNY:
    case SPECIES_CASTFORM_RAINY:
    case SPECIES_CASTFORM_SNOWY:
    case SPECIES_CHERRIM_SUNSHINE:
    case SPECIES_AEGISLASH_BLADE:
    case SPECIES_XERNEAS_ACTIVE:
    case SPECIES_WISHIWASHI_SCHOOL:
    case SPECIES_MIMIKYU_BUSTED:
    case SPECIES_CRAMORANT_GULPING:
    case SPECIES_CRAMORANT_GORGING:
    case SPECIES_EISCUE_NOICE:
    case SPECIES_MORPEKO_HANGRY:
    case SPECIES_PALAFIN_HERO:
    case SPECIES_TERAPAGOS_TERASTAL:
    case SPECIES_TERAPAGOS_STELLAR:
        return TRUE;
    default:
        return FALSE;
    }
}

static const u8 sText_FormRed[] = _("ROJO");
static const u8 sText_FormYellow[] = _("AMARILLO");
static const u8 sText_FormOrange[] = _("NARANJA");
static const u8 sText_FormBlue[] = _("AZUL");
static const u8 sText_FormWhite[] = _("BLANCO");
static const u8 sText_FormGreen[] = _("VERDE");
static const u8 sText_FormIndigo[] = _("AÑIL");
static const u8 sText_FormViolet[] = _("VIOLETA");
static const u8 sText_FormEternal[] = _("ETERNA");

static const u8 sText_FormVanillaCream[] = _("FRESA VAINILLA");
static const u8 sText_FormRubyCream[] = _("FRESA RUBÍ");
static const u8 sText_FormMatchaCream[] = _("FRESA MATCHA");
static const u8 sText_FormMintCream[] = _("FRESA MENTA");
static const u8 sText_FormLemonCream[] = _("FRESA LIMÓN");
static const u8 sText_FormSaltedCream[] = _("FRESA SALADA");
static const u8 sText_FormRubySwirl[] = _("FRESA REMOLINO");
static const u8 sText_FormCaramelSwirl[] = _("FRESA CARAMELO");
static const u8 sText_FormRainbowSwirl[] = _("FRESA ARCOÍRIS");

static const u8 sText_FormBaile[] = _("APASIONADO");
static const u8 sText_FormPomPom[] = _("ANIMADO");
static const u8 sText_FormPau[] = _("PLÁCIDO");
static const u8 sText_FormSensu[] = _("REFINADO");

static const u8 sText_FormIcySnow[] = _("VENTISCA");
static const u8 sText_FormPolar[] = _("POLAR");
static const u8 sText_FormTundra[] = _("TUNDRA");
static const u8 sText_FormContinental[] = _("CONTINENTAL");
static const u8 sText_FormGarden[] = _("VERGEL");
static const u8 sText_FormElegant[] = _("ORIENTAL");
static const u8 sText_FormMeadow[] = _("FLORAL");
static const u8 sText_FormModern[] = _("MODERNO");
static const u8 sText_FormMarine[] = _("MARINO");
static const u8 sText_FormArchipelago[] = _("ISLEÑO");
static const u8 sText_FormHighPlains[] = _("ESTEPA");
static const u8 sText_FormSandstorm[] = _("DESIERTO");
static const u8 sText_FormRiver[] = _("FLUVIAL");
static const u8 sText_FormMonsoon[] = _("MONZÓN");
static const u8 sText_FormSavanna[] = _("SABANA");
static const u8 sText_FormSun[] = _("SOL");
static const u8 sText_FormOcean[] = _("OCÉANO");
static const u8 sText_FormJungle[] = _("SELVA");
static const u8 sText_FormFancy[] = _("FANTASÍA");
static const u8 sText_FormPokeball[] = _("POKÉBALL");

static const u8 sText_FormNatural[] = _("SALVAJE");
static const u8 sText_FormHeart[] = _("CORAZÓN");
static const u8 sText_FormStar[] = _("ESTRELLA");
static const u8 sText_FormDiamond[] = _("DIAMANTE");
static const u8 sText_FormDebutante[] = _("SEÑORITA");
static const u8 sText_FormMatron[] = _("DAMA");
static const u8 sText_FormDandy[] = _("CABALLERO");
static const u8 sText_FormLaReine[] = _("REINA");
static const u8 sText_FormKabuki[] = _("KABUKI");
static const u8 sText_FormPharaoh[] = _("FARAÓNICO");

static const u8 sText_FormNormal[] = _("NORMAL");
static const u8 sText_FormHeat[] = _("CALOR");
static const u8 sText_FormWash[] = _("LAVADO");
static const u8 sText_FormFrost[] = _("FRÍO");
static const u8 sText_FormFan[] = _("VENTILADOR");
static const u8 sText_FormMow[] = _("CORTE");

static const u8 sText_FormMidday[] = _("DIURNO");
static const u8 sText_FormMidnight[] = _("NOCTURNO");
static const u8 sText_FormDusk[] = _("CREPUSCULAR");

static const u8 sText_FormBloodmoon[] = _("LUNA CARMESÍ");

static const u8 sText_FormAttack[] = _("ATAQUE");
static const u8 sText_FormDefense[] = _("DEFENSA");
static const u8 sText_FormSpeed[] = _("VELOCIDAD");

static const u8 sText_FormWestSea[] = _("MAR OESTE");
static const u8 sText_FormEastSea[] = _("MAR ESTE");

static const u8 sText_FormSpring[] = _("PRIMAVERA");
static const u8 sText_FormSummer[] = _("VERANO");
static const u8 sText_FormAutumn[] = _("OTOÑO");
static const u8 sText_FormWinter[] = _("INVIERNO");

static const u8 sText_FormRedStriped[] = _("RAYAS ROJAS");
static const u8 sText_FormBlueStriped[] = _("RAYAS AZULES");
static const u8 sText_FormWhiteStriped[] = _("RAYAS BLANCAS");

static const u8 sText_FormCurly[] = _("CURVADA");
static const u8 sText_FormDroopy[] = _("LÁNGUIDA");
static const u8 sText_FormStretchy[] = _("RECTA");

static const u8 sText_FormTwoSegment[] = _("2 SEGMENTOS");
static const u8 sText_FormThreeSegment[] = _("3 SEGMENTOS");

static const u8 sText_FormPhony[] = _("ARCAICA");
static const u8 sText_FormAntique[] = _("GENUINA");
static const u8 sText_FormCounterfeit[] = _("FRAUDULENTA");
static const u8 sText_FormArtisan[] = _("ARTESANAL");
static const u8 sText_FormUnremarkable[] = _("MEDIOCRIDAD");
static const u8 sText_FormMasterpiece[] = _("OBRA MAESTRA");

static const u8 *GetFormDescriptionName(u16 targetSpecies)
{
    switch (targetSpecies)
    {
    // Florges
    case SPECIES_FLORGES_RED:    return sText_FormRed;
    case SPECIES_FLORGES_YELLOW: return sText_FormYellow;
    case SPECIES_FLORGES_ORANGE: return sText_FormOrange;
    case SPECIES_FLORGES_BLUE:   return sText_FormBlue;
    case SPECIES_FLORGES_WHITE:  return sText_FormWhite;
    // Flabébé
    case SPECIES_FLABEBE_RED:    return sText_FormRed;
    case SPECIES_FLABEBE_YELLOW: return sText_FormYellow;
    case SPECIES_FLABEBE_ORANGE: return sText_FormOrange;
    case SPECIES_FLABEBE_BLUE:   return sText_FormBlue;
    case SPECIES_FLABEBE_WHITE:  return sText_FormWhite;
    // Floette
    case SPECIES_FLOETTE_RED:     return sText_FormRed;
    case SPECIES_FLOETTE_YELLOW:  return sText_FormYellow;
    case SPECIES_FLOETTE_ORANGE:  return sText_FormOrange;
    case SPECIES_FLOETTE_BLUE:    return sText_FormBlue;
    case SPECIES_FLOETTE_WHITE:   return sText_FormWhite;
    case SPECIES_FLOETTE_ETERNAL: return sText_FormEternal;
    // Alcremie
    case SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM: return sText_FormVanillaCream;
    case SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM:    return sText_FormRubyCream;
    case SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM:  return sText_FormMatchaCream;
    case SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM:    return sText_FormMintCream;
    case SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM:   return sText_FormLemonCream;
    case SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM:  return sText_FormSaltedCream;
    case SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL:    return sText_FormRubySwirl;
    case SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL: return sText_FormCaramelSwirl;
    case SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL: return sText_FormRainbowSwirl;
    // Oricorio
    case SPECIES_ORICORIO_BAILE:   return sText_FormBaile;
    case SPECIES_ORICORIO_POM_POM: return sText_FormPomPom;
    case SPECIES_ORICORIO_PAU:     return sText_FormPau;
    case SPECIES_ORICORIO_SENSU:   return sText_FormSensu;
    // Vivillon
    case SPECIES_VIVILLON_ICY_SNOW:     return sText_FormIcySnow;
    case SPECIES_VIVILLON_POLAR:        return sText_FormPolar;
    case SPECIES_VIVILLON_TUNDRA:       return sText_FormTundra;
    case SPECIES_VIVILLON_CONTINENTAL:  return sText_FormContinental;
    case SPECIES_VIVILLON_GARDEN:       return sText_FormGarden;
    case SPECIES_VIVILLON_ELEGANT:      return sText_FormElegant;
    case SPECIES_VIVILLON_MEADOW:       return sText_FormMeadow;
    case SPECIES_VIVILLON_MODERN:       return sText_FormModern;
    case SPECIES_VIVILLON_MARINE:       return sText_FormMarine;
    case SPECIES_VIVILLON_ARCHIPELAGO:  return sText_FormArchipelago;
    case SPECIES_VIVILLON_HIGH_PLAINS:  return sText_FormHighPlains;
    case SPECIES_VIVILLON_SANDSTORM:    return sText_FormSandstorm;
    case SPECIES_VIVILLON_RIVER:        return sText_FormRiver;
    case SPECIES_VIVILLON_MONSOON:      return sText_FormMonsoon;
    case SPECIES_VIVILLON_SAVANNA:      return sText_FormSavanna;
    case SPECIES_VIVILLON_SUN:          return sText_FormSun;
    case SPECIES_VIVILLON_OCEAN:        return sText_FormOcean;
    case SPECIES_VIVILLON_JUNGLE:       return sText_FormJungle;
    case SPECIES_VIVILLON_FANCY:        return sText_FormFancy;
    case SPECIES_VIVILLON_POKEBALL:     return sText_FormPokeball;
    // Minior
    case SPECIES_MINIOR_CORE_RED:    return sText_FormRed;
    case SPECIES_MINIOR_CORE_ORANGE: return sText_FormOrange;
    case SPECIES_MINIOR_CORE_YELLOW: return sText_FormYellow;
    case SPECIES_MINIOR_CORE_GREEN:  return sText_FormGreen;
    case SPECIES_MINIOR_CORE_BLUE:   return sText_FormBlue;
    case SPECIES_MINIOR_CORE_INDIGO: return sText_FormIndigo;
    case SPECIES_MINIOR_CORE_VIOLET: return sText_FormViolet;
    // Furfrou
    case SPECIES_FURFROU_NATURAL:   return sText_FormNatural;
    case SPECIES_FURFROU_HEART:     return sText_FormHeart;
    case SPECIES_FURFROU_STAR:      return sText_FormStar;
    case SPECIES_FURFROU_DIAMOND:   return sText_FormDiamond;
    case SPECIES_FURFROU_DEBUTANTE: return sText_FormDebutante;
    case SPECIES_FURFROU_MATRON:    return sText_FormMatron;
    case SPECIES_FURFROU_DANDY:     return sText_FormDandy;
    case SPECIES_FURFROU_LA_REINE:  return sText_FormLaReine;
    case SPECIES_FURFROU_KABUKI:    return sText_FormKabuki;
    case SPECIES_FURFROU_PHARAOH:   return sText_FormPharaoh;
    // Rotom
    case SPECIES_ROTOM:       return sText_FormNormal;
    case SPECIES_ROTOM_HEAT:  return sText_FormHeat;
    case SPECIES_ROTOM_WASH:  return sText_FormWash;
    case SPECIES_ROTOM_FROST: return sText_FormFrost;
    case SPECIES_ROTOM_FAN:   return sText_FormFan;
    case SPECIES_ROTOM_MOW:   return sText_FormMow;
    // Lycanroc
    case SPECIES_LYCANROC_MIDDAY:   return sText_FormMidday;
    case SPECIES_LYCANROC_MIDNIGHT: return sText_FormMidnight;
    case SPECIES_LYCANROC_DUSK:     return sText_FormDusk;
    // Ursaluna
    case SPECIES_URSALUNA:           return sText_FormNormal;
    case SPECIES_URSALUNA_BLOODMOON: return sText_FormBloodmoon;
    // Deoxys
    case SPECIES_DEOXYS_NORMAL:  return sText_FormNormal;
    case SPECIES_DEOXYS_ATTACK:  return sText_FormAttack;
    case SPECIES_DEOXYS_DEFENSE: return sText_FormDefense;
    case SPECIES_DEOXYS_SPEED:   return sText_FormSpeed;
    // Shellos & Gastrodon
    case SPECIES_SHELLOS_WEST:  return sText_FormWestSea;
    case SPECIES_SHELLOS_EAST:  return sText_FormEastSea;
    case SPECIES_GASTRODON_WEST: return sText_FormWestSea;
    case SPECIES_GASTRODON_EAST: return sText_FormEastSea;
    // Deerling & Sawsbuck
    case SPECIES_DEERLING_SPRING: return sText_FormSpring;
    case SPECIES_DEERLING_SUMMER: return sText_FormSummer;
    case SPECIES_DEERLING_AUTUMN: return sText_FormAutumn;
    case SPECIES_DEERLING_WINTER: return sText_FormWinter;
    case SPECIES_SAWSBUCK_SPRING: return sText_FormSpring;
    case SPECIES_SAWSBUCK_SUMMER: return sText_FormSummer;
    case SPECIES_SAWSBUCK_AUTUMN: return sText_FormAutumn;
    case SPECIES_SAWSBUCK_WINTER: return sText_FormWinter;
    // Basculin
    case SPECIES_BASCULIN_RED_STRIPED:   return sText_FormRedStriped;
    case SPECIES_BASCULIN_BLUE_STRIPED:  return sText_FormBlueStriped;
    case SPECIES_BASCULIN_WHITE_STRIPED: return sText_FormWhiteStriped;
    // Squawkabilly
    case SPECIES_SQUAWKABILLY_GREEN:  return sText_FormGreen;
    case SPECIES_SQUAWKABILLY_BLUE:   return sText_FormBlue;
    case SPECIES_SQUAWKABILLY_YELLOW: return sText_FormYellow;
    case SPECIES_SQUAWKABILLY_WHITE:  return sText_FormWhite;
    // Tatsugiri
    case SPECIES_TATSUGIRI_CURLY:    return sText_FormCurly;
    case SPECIES_TATSUGIRI_DROOPY:   return sText_FormDroopy;
    case SPECIES_TATSUGIRI_STRETCHY: return sText_FormStretchy;
    // Dudunsparce
    case SPECIES_DUDUNSPARCE_TWO_SEGMENT:   return sText_FormTwoSegment;
    case SPECIES_DUDUNSPARCE_THREE_SEGMENT: return sText_FormThreeSegment;
    // Sinistea & Polteageist
    case SPECIES_SINISTEA_PHONY:      return sText_FormPhony;
    case SPECIES_SINISTEA_ANTIQUE:    return sText_FormAntique;
    case SPECIES_POLTEAGEIST_PHONY:   return sText_FormPhony;
    case SPECIES_POLTEAGEIST_ANTIQUE: return sText_FormAntique;
    // Poltchageist & Sinistcha
    case SPECIES_POLTCHAGEIST_COUNTERFEIT: return sText_FormCounterfeit;
    case SPECIES_POLTCHAGEIST_ARTISAN:    return sText_FormArtisan;
    case SPECIES_SINISTCHA_UNREMARKABLE:  return sText_FormUnremarkable;
    case SPECIES_SINISTCHA_MASTERPIECE:   return sText_FormMasterpiece;
    default:
        return GetSpeciesName(targetSpecies);
    }
}

void DoctoreFernan_CheckAndPrepareForms(void)
{
    u8 slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = 0;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = 0;
        return;
    }

    u16 currentSpecies = GetMonData(mon, MON_DATA_SPECIES);
    GetMonNickname(mon, gStringVar1);

    // Get table: either custom regional family table or species formSpeciesIdTable
    const u16 *formTable = GetRegionalFamilyTable(currentSpecies);
    if (formTable == NULL)
        formTable = GetSpeciesFormTable(currentSpecies);

    if (formTable == NULL)
    {
        gSpecialVar_Result = 0;
        return;
    }

    // Count valid available target forms (excluding currentSpecies and battle-only forms)
    u32 count = 0;
    u32 i;
    for (i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        u16 targetSpecies = formTable[i];
        if (targetSpecies != currentSpecies && !IsExcludedBattleForm(targetSpecies))
            count++;
    }

    if (count == 0)
    {
        gSpecialVar_Result = 0;
        return;
    }

    MultichoiceDynamic_InitStack(count + 1);

    for (i = 0; formTable[i] != FORM_SPECIES_END; i++)
    {
        u16 targetSpecies = formTable[i];
        if (targetSpecies != currentSpecies && !IsExcludedBattleForm(targetSpecies))
        {
            const u8 *formName = GetFormDescriptionName(targetSpecies);
            u8 *nameBuffer = Alloc(StringLength(formName) + 1);
            if (nameBuffer != NULL)
            {
                struct ListMenuItem item;
                StringCopy(nameBuffer, formName);
                item.name = nameBuffer;
                item.id = targetSpecies;
                MultichoiceDynamic_PushElement(item);
            }
        }
    }

    // Push cancel option
    {
        u8 *cancelName = Alloc(StringLength(gText_Cancel2) + 1);
        if (cancelName != NULL)
        {
            struct ListMenuItem cancelItem;
            StringCopy(cancelName, gText_Cancel2);
            cancelItem.name = cancelName;
            cancelItem.id = SPECIES_NONE;
            MultichoiceDynamic_PushElement(cancelItem);
        }
    }

    if (!MultichoiceDynamic_StackEmpty())
        gSpecialVar_Result = count;
    else
    {
        MultichoiceDynamic_DestroyStack();
        gSpecialVar_Result = 0;
    }
}

void DoctoreFernan_ShowPreview(void)
{
    u8 slot = gSpecialVar_0x8004;
    u16 targetSpecies = gSpecialVar_0x8005;

    if (slot >= gPlayerPartyCount || targetSpecies == SPECIES_NONE)
        return;

    struct Pokemon *mon = &gPlayerParty[slot];
    bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);

    if (isShiny)
        ScriptMenu_ShowShinyPokemonPic(targetSpecies, 10, 3);
    else
        ScriptMenu_ShowPokemonPic(targetSpecies, 10, 3);
}

void DoctoreFernan_HidePreview(void)
{
    ScriptMenu_HidePokemonPic();
}

void DoctoreFernan_ApplyFormChange(void)
{
    u8 slot = gSpecialVar_0x8004;
    u16 newSpecies = gSpecialVar_0x8005;

    if (slot >= gPlayerPartyCount || newSpecies == SPECIES_NONE)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    u16 oldSpecies = GetMonData(mon, MON_DATA_SPECIES);
    SetMonData(mon, MON_DATA_SPECIES, &newSpecies);
    CalculateMonStats(mon);
    EvolutionRenameMon(mon, oldSpecies, newSpecies);

    GetSetPokedexFlag(SpeciesToNationalPokedexNum(newSpecies), FLAG_SET_SEEN);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(newSpecies), FLAG_SET_CAUGHT);

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, GetFormDescriptionName(newSpecies));
    gSpecialVar_Result = TRUE;
}

