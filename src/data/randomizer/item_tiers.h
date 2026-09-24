#ifndef GUARD_DATA_RANDOMIZER_ITEM_TIERS_H
#define GUARD_DATA_RANDOMIZER_ITEM_TIERS_H

#include "global.h"
#include "constants/items.h"
#include "constants/map_groups.h"

enum ItemProgressionTier
{
    ITEM_PROG_EARLY,
    ITEM_PROG_EARLY_MID,
    ITEM_PROG_MID,
    ITEM_PROG_LATE,
    ITEM_PROG_POSTGAME,
};

// =============================================================================
// TIER 1: Común / Consumible Básico
// =============================================================================
static const u16 sItemTier1[] =
{
    // Poké Balls
    ITEM_POKE_BALL,
    ITEM_PREMIER_BALL,
    ITEM_HEAL_BALL,

    // Curación y Estado
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_FRESH_WATER,
    ITEM_SWEET_HEART,

    // Campo
    ITEM_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_POKE_DOLL,
    ITEM_FLUFFY_TAIL,

    // Combate consumible
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_X_SP_ATK,
    ITEM_X_SP_DEF,
    ITEM_X_SPEED,
    ITEM_X_ACCURACY,
    ITEM_DIRE_HIT,
    ITEM_GUARD_SPEC,
};

// =============================================================================
// TIER 2: Útil / Consumible Medio / Potenciador Tipo Básico
// =============================================================================
static const u16 sItemTier2[] =
{
    // Poké Balls
    ITEM_GREAT_BALL,
    ITEM_NEST_BALL,
    ITEM_NET_BALL,
    ITEM_REPEAT_BALL,
    ITEM_TIMER_BALL,
    ITEM_LUXURY_BALL,
    ITEM_DUSK_BALL,
    ITEM_DIVE_BALL,
    ITEM_QUICK_BALL,

    // Curación y Recuperación
    ITEM_SUPER_POTION,
    ITEM_SODA_POP,
    ITEM_LEMONADE,
    ITEM_MOOMOO_MILK,
    ITEM_ENERGY_POWDER,
    ITEM_HEAL_POWDER,
    ITEM_FULL_HEAL,
    ITEM_REVIVE,
    ITEM_ETHER,
    ITEM_BERRY_JUICE,
    ITEM_LAVA_COOKIE,
    ITEM_OLD_GATEAU,
    ITEM_CASTELIACONE,
    ITEM_BIG_MALASADA,
    ITEM_RAGECANDYBAR,

    // Campo
    ITEM_SUPER_REPEL,
    ITEM_LURE,

    // Potenciadores de Tipo (Held Básico)
    ITEM_SILK_SCARF,
    ITEM_CHARCOAL,
    ITEM_MYSTIC_WATER,
    ITEM_MAGNET,
    ITEM_MIRACLE_SEED,
    ITEM_NEVER_MELT_ICE,
    ITEM_BLACK_BELT,
    ITEM_POISON_BARB,
    ITEM_SOFT_SAND,
    ITEM_SHARP_BEAK,
    ITEM_TWISTED_SPOON,
    ITEM_SILVER_POWDER,
    ITEM_HARD_STONE,
    ITEM_SPELL_TAG,
    ITEM_DRAGON_FANG,
    ITEM_BLACK_GLASSES,
    ITEM_METAL_COAT,
    ITEM_FAIRY_FEATHER,

    // Inciensos
    ITEM_SEA_INCENSE,
    ITEM_WAVE_INCENSE,
    ITEM_ROSE_INCENSE,
    ITEM_ODD_INCENSE,
    ITEM_ROCK_INCENSE,

    // Held Items menores / Utilidad
    ITEM_SOOTHE_BELL,
    ITEM_CLEANSE_TAG,
    ITEM_SMOKE_BALL,
    ITEM_EVERSTONE,
    ITEM_METRONOME,
    ITEM_FLOAT_STONE,
    ITEM_RING_TARGET,
    ITEM_BINDING_BAND,

    // Dinero T2
    ITEM_STARDUST,
    ITEM_PEARL,
    ITEM_TINY_MUSHROOM,
};

// =============================================================================
// TIER 3: Valioso / Evolutivo / Competitivo Intermedio
// =============================================================================
static const u16 sItemTier3[] =
{
    // Poké Balls
    ITEM_ULTRA_BALL,
    ITEM_FAST_BALL,
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_HEAVY_BALL,
    ITEM_LOVE_BALL,
    ITEM_FRIEND_BALL,
    ITEM_MOON_BALL,
    ITEM_DREAM_BALL,
    ITEM_SPORT_BALL,

    // Curación Superior
    ITEM_HYPER_POTION,
    ITEM_MAX_POTION,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_REVIVAL_HERB,
    ITEM_ENERGY_ROOT,
    ITEM_MAX_ETHER,
    ITEM_ELIXIR,
    ITEM_MAX_ELIXIR,

    // Campo
    ITEM_MAX_REPEL,
    ITEM_SUPER_LURE,
    ITEM_MAX_LURE,

    // Piedras y Objetos Evolutivos
    ITEM_FIRE_STONE,
    ITEM_WATER_STONE,
    ITEM_THUNDER_STONE,
    ITEM_LEAF_STONE,
    ITEM_ICE_STONE,
    ITEM_SUN_STONE,
    ITEM_MOON_STONE,
    ITEM_SHINY_STONE,
    ITEM_DUSK_STONE,
    ITEM_DAWN_STONE,
    ITEM_OVAL_STONE,
    ITEM_LINKING_CORD,
    ITEM_DRAGON_SCALE,
    ITEM_UPGRADE,
    ITEM_DUBIOUS_DISC,
    ITEM_PROTECTOR,
    ITEM_ELECTIRIZER,
    ITEM_MAGMARIZER,
    ITEM_REAPER_CLOTH,
    ITEM_PRISM_SCALE,
    ITEM_WHIPPED_DREAM,
    ITEM_SACHET,
    ITEM_SWEET_APPLE,
    ITEM_TART_APPLE,
    ITEM_SYRUPY_APPLE,
    ITEM_CRACKED_POT,
    ITEM_CHIPPED_POT,
    ITEM_BLACK_AUGURITE,
    ITEM_PEAT_BLOCK,
    ITEM_METAL_ALLOY,
    ITEM_UNREMARKABLE_TEACUP,
    ITEM_MASTERPIECE_TEACUP,

    // Vitaminas y Plumas
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CALCIUM,
    ITEM_ZINC,
    ITEM_CARBOS,
    ITEM_PP_UP,
    ITEM_HEALTH_FEATHER,
    ITEM_MUSCLE_FEATHER,
    ITEM_RESIST_FEATHER,
    ITEM_GENIUS_FEATHER,
    ITEM_CLEVER_FEATHER,
    ITEM_SWIFT_FEATHER,

    // Mentas
    ITEM_ADAMANT_MINT,
    ITEM_MODEST_MINT,
    ITEM_TIMID_MINT,
    ITEM_JOLLY_MINT,
    ITEM_BOLD_MINT,
    ITEM_CALM_MINT,
    ITEM_IMPISH_MINT,
    ITEM_CAREFUL_MINT,
    ITEM_BRAVE_MINT,
    ITEM_QUIET_MINT,

    // Mochi
    ITEM_HEALTH_MOCHI,
    ITEM_MUSCLE_MOCHI,
    ITEM_RESIST_MOCHI,
    ITEM_GENIUS_MOCHI,
    ITEM_CLEVER_MOCHI,
    ITEM_SWIFT_MOCHI,
    ITEM_FRESH_START_MOCHI,

    // Held Items T3 (Tácticos / Clásicos)
    ITEM_SCOPE_LENS,
    ITEM_WIDE_LENS,
    ITEM_ZOOM_LENS,
    ITEM_QUICK_CLAW,
    ITEM_SHELL_BELL,
    ITEM_KINGS_ROCK,
    ITEM_FOCUS_BAND,
    ITEM_MUSCLE_BAND,
    ITEM_WISE_GLASSES,
    ITEM_EXPERT_BELT,
    ITEM_LIGHT_CLAY,
    ITEM_POWER_HERB,
    ITEM_WHITE_HERB,
    ITEM_MENTAL_HERB,
    ITEM_BIG_ROOT,
    ITEM_RAZOR_CLAW,
    ITEM_RAZOR_FANG,
    ITEM_AIR_BALLOON,
    ITEM_SHED_SHELL,
    ITEM_AMULET_COIN,
    ITEM_LUCKY_EGG,

    // Climas y Terrenos
    ITEM_DAMP_ROCK,
    ITEM_HEAT_ROCK,
    ITEM_SMOOTH_ROCK,
    ITEM_ICY_ROCK,
    ITEM_TERRAIN_EXTENDER,
    ITEM_ELECTRIC_SEED,
    ITEM_PSYCHIC_SEED,
    ITEM_MISTY_SEED,
    ITEM_GRASSY_SEED,

    // Especie
    ITEM_LIGHT_BALL,
    ITEM_THICK_CLUB,
    ITEM_LEEK,
    ITEM_LUCKY_PUNCH,
    ITEM_QUICK_POWDER,
    ITEM_METAL_POWDER,
    ITEM_DEEP_SEA_SCALE,
    ITEM_DEEP_SEA_TOOTH,

    // Dinero T3
    ITEM_BIG_PEARL,
    ITEM_NUGGET,
    ITEM_BIG_MUSHROOM,
    ITEM_STAR_PIECE,
    ITEM_HEART_SCALE,
};

// =============================================================================
// TIER 4: Competitivo / Élite / Raro
// =============================================================================
static const u16 sItemTier4[] =
{
    // Held Items Élite
    ITEM_LEFTOVERS,
    ITEM_LIFE_ORB,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SPECS,
    ITEM_CHOICE_SCARF,
    ITEM_ASSAULT_VEST,
    ITEM_EVIOLITE,
    ITEM_ROCKY_HELMET,
    ITEM_FOCUS_SASH,
    ITEM_HEAVY_DUTY_BOOTS,
    ITEM_BLACK_SLUDGE,
    ITEM_WEAKNESS_POLICY,
    ITEM_CLEAR_AMULET,
    ITEM_COVERT_CLOAK,
    ITEM_LOADED_DICE,
    ITEM_PUNCHING_GLOVE,
    ITEM_ABILITY_SHIELD,
    ITEM_EJECT_BUTTON,
    ITEM_EJECT_PACK,
    ITEM_RED_CARD,
    ITEM_THROAT_SPRAY,
    ITEM_BLUNDER_POLICY,
    ITEM_FLAME_ORB,
    ITEM_TOXIC_ORB,

    // Consumibles de Élite
    ITEM_SACRED_ASH,
    ITEM_PP_MAX,
    ITEM_RARE_CANDY,
    ITEM_ABILITY_CAPSULE,
    ITEM_ABILITY_PATCH,

    // Dinero T4
    ITEM_BIG_NUGGET,
    ITEM_COMET_SHARD,
    ITEM_BALM_MUSHROOM,
    ITEM_PEARL_STRING,
    ITEM_RARE_BONE,
    ITEM_BOTTLE_CAP,
    ITEM_GOLD_BOTTLE_CAP,
};

// =============================================================================
// TIER 5: Singular Excepcional (Master Ball)
// =============================================================================
static const u16 sItemTier5[] =
{
    ITEM_MASTER_BALL,
};

// =============================================================================
// MEGAPROUNDS: Pool Separada de Megapiedras HnS
// =============================================================================
static const u16 sMegaStonesPool[] =
{
    ITEM_VENUSAURITE,
    ITEM_CHARIZARDITE_X,
    ITEM_CHARIZARDITE_Y,
    ITEM_BLASTOISINITE,
    ITEM_BEEDRILLITE,
    ITEM_PIDGEOTITE,
    ITEM_ALAKAZITE,
    ITEM_SLOWBRONITE,
    ITEM_GENGARITE,
    ITEM_KANGASKHANITE,
    ITEM_PINSIRITE,
    ITEM_GYARADOSITE,
    ITEM_AERODACTYLITE,
    ITEM_AMPHAROSITE,
    ITEM_STEELIXITE,
    ITEM_SCIZORITE,
    ITEM_HERACRONITE,
    ITEM_HOUNDOOMINITE,
    ITEM_TYRANITARITE,
    ITEM_SCEPTILITE,
    ITEM_BLAZIKENITE,
    ITEM_SWAMPERTITE,
    ITEM_GARDEVOIRITE,
    ITEM_SABLENITE,
    ITEM_MAWILITE,
    ITEM_AGGRONITE,
    ITEM_MEDICHAMITE,
    ITEM_MANECTITE,
    ITEM_SHARPEDONITE,
    ITEM_CAMERUPTITE,
    ITEM_ALTARIANITE,
    ITEM_BANETTITE,
    ITEM_ABSOLITE,
    ITEM_GLALITITE,
    ITEM_SALAMENCITE,
    ITEM_METAGROSSITE,
    ITEM_LOPUNNITE,
    ITEM_GARCHOMPITE,
    ITEM_LUCARIONITE,
    ITEM_ABOMASITE,
    ITEM_GALLADITE,
    ITEM_AUDINITE,
};

// =============================================================================
// Mapeo de Mapas a Tier de Progresión
// =============================================================================

static inline enum ItemProgressionTier GetMapProgressionTier(u8 mapGroup, u8 mapNum)
{
    if (mapGroup == MAP_GROUP(MAP_ROUTE29_HNS)) // Towns & Routes
    {
        switch (mapNum)
        {
        // EARLY: Johto inicial
        case MAP_NUM(MAP_NEW_BARK_TOWN_HNS):
        case MAP_NUM(MAP_CHERRYGROVE_CITY_HNS):
        case MAP_NUM(MAP_VIOLET_CITY_HNS):
        case MAP_NUM(MAP_AZALEA_TOWN_HNS):
        case MAP_NUM(MAP_ROUTE29_HNS):
        case MAP_NUM(MAP_ROUTE30_HNS):
        case MAP_NUM(MAP_ROUTE31_HNS):
        case MAP_NUM(MAP_ROUTE32_HNS):
            return ITEM_PROG_EARLY;

        // EARLY_MID: Trigal y alrededores
        case MAP_NUM(MAP_GOLDENROD_CITY_HNS):
        case MAP_NUM(MAP_ROUTE33_HNS):
        case MAP_NUM(MAP_ROUTE34_HNS):
        case MAP_NUM(MAP_ROUTE35_HNS):
        case MAP_NUM(MAP_ROUTE36_HNS):
        case MAP_NUM(MAP_ROUTE37_HNS):
            return ITEM_PROG_EARLY_MID;

        // MID: Iris, Olivo, Orquídea, Caoba y Lago
        case MAP_NUM(MAP_ECRUTEAK_CITY_HNS):
        case MAP_NUM(MAP_OLIVINE_CITY_HNS):
        case MAP_NUM(MAP_CIANWOOD_CITY_HNS):
        case MAP_NUM(MAP_SAFARI_ZONE_GATE_HNS):
        case MAP_NUM(MAP_MAHOGANYTOWN_HNS):
        case MAP_NUM(MAP_ROUTE38_HNS):
        case MAP_NUM(MAP_ROUTE39_HNS):
        case MAP_NUM(MAP_ROUTE40_HNS):
        case MAP_NUM(MAP_ROUTE41_HNS):
        case MAP_NUM(MAP_ROUTE42_HNS):
        case MAP_NUM(MAP_ROUTE43_HNS):
        case MAP_NUM(MAP_ROUTE47_HNS):
        case MAP_NUM(MAP_ROUTE48_HNS):
            return ITEM_PROG_MID;

        // LATE: Endrino, Calle Victoria y Liga Johto
        case MAP_NUM(MAP_BLACKTHORN_CITY_HNS):
        case MAP_NUM(MAP_ROUTE44_HNS):
        case MAP_NUM(MAP_ROUTE45_HNS):
        case MAP_NUM(MAP_ROUTE46_HNS):
        case MAP_NUM(MAP_ROUTE26_HNS):
        case MAP_NUM(MAP_ROUTE26NORTH_HNS):
        case MAP_NUM(MAP_ROUTE27_HNS):
        case MAP_NUM(MAP_INDIGO_PLATEAU_HNS):
            return ITEM_PROG_LATE;

        // POSTGAME: Kanto completo
        default:
            return ITEM_PROG_POSTGAME;
        }
    }
    else if (mapGroup == MAP_GROUP(MAP_DARK_CAVE_SOUTH_SIDE_HNS)) // Dungeons
    {
        switch (mapNum)
        {
        // EARLY
        case MAP_NUM(MAP_DARK_CAVE_SOUTH_SIDE_HNS):
        case MAP_NUM(MAP_SPROUT_TOWER_1F_HNS):
        case MAP_NUM(MAP_SPROUT_TOWER_2F_HNS):
        case MAP_NUM(MAP_SPROUT_TOWER_3F_HNS):
        case MAP_NUM(MAP_RUINS_OF_ALPH_OUTSIDE_HNS):
        case MAP_NUM(MAP_RUINS_OF_ALPH_B1F_HNS):
        case MAP_NUM(MAP_RUINS_OF_ALPH_PUZZLE_AND_REWARD_CHAMBERS_HNS):
        case MAP_NUM(MAP_UNION_CAVE_1F_HNS):
        case MAP_NUM(MAP_UNION_CAVE_B1F_HNS):
        case MAP_NUM(MAP_SLOWPOKE_WELL_B1F_HNS):
        case MAP_NUM(MAP_SLOWPOKE_WELL_B2F_HNS):
            return ITEM_PROG_EARLY;

        // EARLY_MID
        case MAP_NUM(MAP_UNION_CAVE_B2F_HNS):
        case MAP_NUM(MAP_ILEX_FOREST_HNS):
        case MAP_NUM(MAP_NATIONAL_PARK_NORMAL_HNS):
        case MAP_NUM(MAP_NATIONAL_PARK_BUG_CONTEST_HNS):
            return ITEM_PROG_EARLY_MID;

        // MID
        case MAP_NUM(MAP_BURNED_TOWER_1F_HNS):
        case MAP_NUM(MAP_BURNED_TOWER_B1F_HNS):
        case MAP_NUM(MAP_CLIFF_EDGE_GATE_HNS):
        case MAP_NUM(MAP_MT_MORTAR_1F_SOUTH_HNS):
        case MAP_NUM(MAP_MT_MORTAR_1F_NORTH_HNS):
        case MAP_NUM(MAP_MT_MORTAR_2F_HNS):
        case MAP_NUM(MAP_MT_MORTAR_B1F_HNS):
        case MAP_NUM(MAP_LAKE_OF_RAGE_HNS):
        case MAP_NUM(MAP_LAKE_OF_RAGE_LOW_TIDE_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_1F_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_B1F_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_B1F_INNER_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_B2F_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_B3F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_1F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_2F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_3F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_4F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_5F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_6F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_7F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_8F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_9F_HNS):
        case MAP_NUM(MAP_TIN_TOWER_ROOF_DAY_HNS):
        case MAP_NUM(MAP_TIN_TOWER_ROOF_NIGHT_HNS):
        case MAP_NUM(MAP_CLIFF_EDGE_CAVE_HNS):
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B1F_HNS):
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B2F_HNS):
            return ITEM_PROG_MID;

        // LATE
        case MAP_NUM(MAP_DARK_CAVE_NORTH_SIDE_HNS):
        case MAP_NUM(MAP_ICE_PATH_1F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B1F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B2F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B3F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B4F_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_ENTRANCE_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_CAVERN_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_SHRINE_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_DESCENT_HNS):
        case MAP_NUM(MAP_WHIRL_ISLANDS_LUGIA_CHAMBER_HNS):
        case MAP_NUM(MAP_TOHJO_FALLS_CAVERN_HNS):
        case MAP_NUM(MAP_TOHJO_FALLS_GIOVANNI_ROOM_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_B2F_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_B1F_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_1F_HNS):
            return ITEM_PROG_LATE;

        // POSTGAME: Mt. Silver, cuevas de Kanto
        default:
            return ITEM_PROG_POSTGAME;
        }
    }

    // Interiores mapeados según su ciudad
    if (mapGroup == MAP_GROUP(MAP_NEW_BARK_TOWN_LAB_HNS)
     || mapGroup == MAP_GROUP(MAP_CHERRYGROVE_CITY_POKEMON_CENTER_HNS)
     || mapGroup == MAP_GROUP(MAP_VIOLET_CITY_POKEMON_CENTER_HNS)
     || mapGroup == MAP_GROUP(MAP_AZALEA_TOWN_POKEMON_CENTER_HNS))
        return ITEM_PROG_EARLY;

    if (mapGroup == MAP_GROUP(MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS))
        return ITEM_PROG_EARLY_MID;

    if (mapGroup == MAP_GROUP(MAP_ECRUTEAK_CITY_HNS)
     || mapGroup == MAP_GROUP(MAP_OLIVINE_CITY_HNS)
     || mapGroup == MAP_GROUP(MAP_CIANWOOD_CITY_HNS)
     || mapGroup == MAP_GROUP(MAP_MAHOGANYTOWN_HNS))
        return ITEM_PROG_MID;

    if (mapGroup == MAP_GROUP(MAP_BLACKTHORN_CITY_HNS)
     || mapGroup == MAP_GROUP(MAP_INDIGO_PLATEAU_POKEMON_CENTER_HNS))
        return ITEM_PROG_LATE;

    return ITEM_PROG_POSTGAME;
}

// Comprueba si la ubicación es posterior al evento del Lago de la Furia
static inline bool8 IsLocationPostLakeOfRage(u8 mapGroup, u8 mapNum)
{
    // Si la historia ya superó el evento del Gyarados Rojo
    if (FlagGet(FLAG_HIDE_LAKE_OF_RAGE_GYARADOS))
        return TRUE;

    // O si estamos en zonas geográficamente post-Lago
    if (mapGroup == MAP_GROUP(MAP_ROUTE29_HNS))
    {
        switch (mapNum)
        {
        case MAP_NUM(MAP_ROUTE43_HNS):
        case MAP_NUM(MAP_ROUTE44_HNS):
        case MAP_NUM(MAP_ROUTE45_HNS):
        case MAP_NUM(MAP_ROUTE46_HNS):
        case MAP_NUM(MAP_BLACKTHORN_CITY_HNS):
        case MAP_NUM(MAP_ROUTE26_HNS):
        case MAP_NUM(MAP_ROUTE26NORTH_HNS):
        case MAP_NUM(MAP_ROUTE27_HNS):
        case MAP_NUM(MAP_INDIGO_PLATEAU_HNS):
            return TRUE;
        default:
            if (mapNum >= MAP_NUM(MAP_PALLET_TOWN_HNS)) // Kanto
                return TRUE;
            return FALSE;
        }
    }
    else if (mapGroup == MAP_GROUP(MAP_DARK_CAVE_SOUTH_SIDE_HNS))
    {
        switch (mapNum)
        {
        case MAP_NUM(MAP_LAKE_OF_RAGE_HNS):
        case MAP_NUM(MAP_LAKE_OF_RAGE_LOW_TIDE_HNS):
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B1F_HNS):
        case MAP_NUM(MAP_ROCKET_HIDEOUT_B2F_HNS):
        case MAP_NUM(MAP_ICE_PATH_1F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B1F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B2F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B3F_HNS):
        case MAP_NUM(MAP_ICE_PATH_B4F_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_ENTRANCE_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_CAVERN_HNS):
        case MAP_NUM(MAP_DRAGONS_DEN_SHRINE_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_B2F_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_B1F_HNS):
        case MAP_NUM(MAP_VICTORY_ROAD_KANTO_1F_HNS):
        case MAP_NUM(MAP_MT_SILVER_OUTSIDE_HNS):
        case MAP_NUM(MAP_MT_SILVER_1F_ITEM_ROOM_HNS):
        case MAP_NUM(MAP_MT_SILVER_1F_WATERFALL_ROOM_HNS):
        case MAP_NUM(MAP_MT_SILVER_1F_MOLTRES_ROOM_HNS):
        case MAP_NUM(MAP_MT_SILVER_MOUNTAIN_SIDE_HNS):
        case MAP_NUM(MAP_MT_SILVER_2F_HNS):
        case MAP_NUM(MAP_MT_SILVER_3F_HNS):
        case MAP_NUM(MAP_MT_SILVER_SNOW_HNS):
        case MAP_NUM(MAP_MT_SILVER_SUMMIT_DAY_HNS):
        case MAP_NUM(MAP_MT_SILVER_SUMMIT_NIGHT_HNS):
            return TRUE;
        default:
            return FALSE;
        }
    }

    return FALSE;
}

#endif // GUARD_DATA_RANDOMIZER_ITEM_TIERS_H
