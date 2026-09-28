#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "battle_main.h"
#include "random.h"
#include "config/randomizer.h"
#include "randomizer.h"
#include "overworld.h"
#include "script.h"
#include "challenge_menu.h"
#include "new_game.h"


// =============================================================================
// Submenu (tab) definitions
// =============================================================================

enum {
    TAB_MODE,
    TAB_FEATURES,
    TAB_RANDOMIZER,
    TAB_ITEMS,
    TAB_NUZLOCKE,
    TAB_DIFFICULTY,
    TAB_CHALLENGES,
    TAB_COUNT,
};

// =============================================================================
// Per-tab item enums — placeholder items for skeleton testing
// =============================================================================

enum {
    ITEM_MODE_GAMEMODE,
    ITEM_MODE_MODERN_MOVES,
    ITEM_MODE_SPLIT,
    ITEM_MODE_FAIRY_TYPES,
    ITEM_MODE_INFINITE_TMS,
    ITEM_MODE_MINTS,
    ITEM_MODE_GEN_ONE_RECHARGE,
    ITEM_MODE_SYNCHRONIZE,
    ITEM_MODE_STURDY,
    ITEM_MODE_NEW_CITRUS,
    ITEM_MODE_LEGENDARY_ABILITIES,
    ITEM_MODE_SURVIVE_POISON,
    ITEM_MODE_NEXT,
    ITEM_MODE_COUNT,
};

enum {
    ITEM_FEATURES_RTC_TYPE,
    ITEM_FEATURES_SHINY_CHANCE,
    ITEM_FEATURES_SHINY_COLOR,
    ITEM_FEATURES_ITEM_DROP,
    ITEM_FEATURES_FRONTIER_BANS,
    ITEM_FEATURES_NEXT,
    ITEM_FEATURES_COUNT,
};

enum {
    ITEM_RANDOM_OFF_ON,
    ITEM_RANDOM_STARTER,
    ITEM_RANDOM_WILD_PKMN,
    ITEM_RANDOM_MAP_BASED,
    ITEM_RANDOM_TRAINER,
    ITEM_RANDOM_TRAINER_POWER,
    ITEM_RANDOM_TRAINER_ITEMS,
    ITEM_RANDOM_TRAINER_MEGAS,
    ITEM_RANDOM_STATIC,
    ITEM_RANDOM_SIMILAR,
    ITEM_RANDOM_LEGENDARIES,
    ITEM_RANDOM_GEN_SCOPE,
    ITEM_RANDOM_TYPE,
    ITEM_RANDOM_MOVES,
    ITEM_RANDOM_ABILITIES,
    ITEM_RANDOM_EVOLUTIONS,
    ITEM_RANDOM_EVO_METHODS,
    ITEM_RANDOM_TYPE_EFFEC,
    ITEM_RANDOM_CHAOS,
    ITEM_RANDOM_NEXT,
    ITEM_RANDOM_COUNT,
};

enum {
    ITEM_ITEMS_RANDOMIZE,
    ITEM_ITEMS_PROGRESSION,
    ITEM_ITEMS_TM_SHUFFLE,
    ITEM_ITEMS_MEGA_STONES,
    ITEM_ITEMS_COMPETITIVE,
    ITEM_ITEMS_NEXT,
    ITEM_ITEMS_COUNT,
};

enum {
    ITEM_NUZLOCKE_NUZLOCKE,
    ITEM_NUZLOCKE_SPECIES_CLAUSE,
    ITEM_NUZLOCKE_SHINY_CLAUSE,
    ITEM_NUZLOCKE_NICKNAMING,
    ITEM_NUZLOCKE_DELETION,
    ITEM_NUZLOCKE_RARE_CANDY,
    ITEM_NUZLOCKE_POKE_VIAL,
    ITEM_NUZLOCKE_GYM_TOKENS,
    ITEM_NUZLOCKE_BAN_HEALING_SHOP,
    ITEM_NUZLOCKE_NEXT,
    ITEM_NUZLOCKE_COUNT,
};

enum {
    ITEM_DIFFICULTY_PARTY_LIMIT,
    ITEM_DIFFICULTY_LEVEL_CAP,
    ITEM_DIFFICULTY_EXP_MULTIPLIER,
    ITEM_DIFFICULTY_ITEM_PLAYER,
    ITEM_DIFFICULTY_ITEM_TRAINER,
    ITEM_DIFFICULTY_MAX_PARTY_IVS,
    ITEM_DIFFICULTY_SCALING_IVS,
    ITEM_DIFFICULTY_NO_EVS,
    ITEM_DIFFICULTY_SCALING_EVS,
    ITEM_DIFFICULTY_LESS_ESCAPES,
    ITEM_DIFFICULTY_ESCAPE_ROPE_DIG,
    ITEM_DIFFICULTY_NEXT,
    ITEM_DIFFICULTY_COUNT,
};

enum {
    ITEM_CHALLENGES_POKECENTER,
    ITEM_CHALLENGES_EXPENSIVE,
    ITEM_CHALLENGES_EVO_LIMIT,
    ITEM_CHALLENGES_ONE_TYPE,
    ITEM_CHALLENGES_BST_EQUALIZER,
    ITEM_CHALLENGES_MIRROR,
    ITEM_CHALLENGES_MIRROR_THIEF,
    ITEM_CHALLENGES_SAVE,
    ITEM_CHALLENGES_COUNT,
};

// Maximum items in any single tab
#define MAX_ITEMS_PER_TAB 20
#define ITEMS_VISIBLE 5
#define Y_DIFF 16

// =============================================================================
// Menu item descriptor — one per option row
// =============================================================================

struct ChallengeMenuItem
{
    const u8 *name;
    const u8 *const *descriptions;
    u8 numChoices;
    const u8 *const *choiceNames;
};

// =============================================================================
// EWRAM state
// =============================================================================

struct ChallengeMenuState
{
    u8 currentTab;
    u8 listTaskId;
    u8 arrowTaskId;
    u16 scrollOffset[TAB_COUNT];
    u16 selectedRow[TAB_COUNT];
    u8 selections[TAB_COUNT * MAX_ITEMS_PER_TAB];
};

static EWRAM_DATA struct ChallengeMenuState *sMenu = NULL;
static EWRAM_DATA bool8 sIsInitialSetup = FALSE;

// =============================================================================
// Mid-game lock policies
// =============================================================================

enum {
    LOCK_FREE,
    LOCK_ONEWAY_DOWN,
    LOCK_ONEWAY_UP,
    LOCK_FULL,
};

static const u8 sMidGameLockPolicy[TAB_COUNT * MAX_ITEMS_PER_TAB] = {
    // TAB_MODE — all free
    // TAB_FEATURES — all free
    // TAB_RANDOMIZER
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_OFF_ON]      = LOCK_FREE,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_STARTER]     = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_WILD_PKMN]   = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_TRAINER]     = LOCK_FREE,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_STATIC]      = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_LEGENDARIES] = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_TYPE]        = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_MOVES]       = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_ABILITIES]   = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_EVOLUTIONS]  = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_EVO_METHODS] = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_TYPE_EFFEC]  = LOCK_ONEWAY_DOWN,
    [TAB_RANDOMIZER * MAX_ITEMS_PER_TAB + ITEM_RANDOM_CHAOS]       = LOCK_ONEWAY_DOWN,
    // TAB_ITEMS
    [TAB_ITEMS * MAX_ITEMS_PER_TAB + ITEM_ITEMS_RANDOMIZE]        = LOCK_ONEWAY_DOWN,
    [TAB_ITEMS * MAX_ITEMS_PER_TAB + ITEM_ITEMS_PROGRESSION]      = LOCK_ONEWAY_DOWN,
    [TAB_ITEMS * MAX_ITEMS_PER_TAB + ITEM_ITEMS_TM_SHUFFLE]       = LOCK_ONEWAY_DOWN,
    [TAB_ITEMS * MAX_ITEMS_PER_TAB + ITEM_ITEMS_MEGA_STONES]      = LOCK_ONEWAY_DOWN,
    [TAB_ITEMS * MAX_ITEMS_PER_TAB + ITEM_ITEMS_COMPETITIVE]      = LOCK_ONEWAY_DOWN,
    // MAP_BASED, SIMILAR and GEN_SCOPE are LOCK_FREE (default 0) -- GEN_SCOPE is
    // deliberately adjustable in both directions mid-run.
    // TAB_NUZLOCKE
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_NUZLOCKE]      = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_SPECIES_CLAUSE] = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_SHINY_CLAUSE]   = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_NICKNAMING]     = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_DELETION]       = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_RARE_CANDY]     = LOCK_FULL,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_POKE_VIAL]      = LOCK_ONEWAY_DOWN,
    [TAB_NUZLOCKE * MAX_ITEMS_PER_TAB + ITEM_NUZLOCKE_GYM_TOKENS]     = LOCK_ONEWAY_DOWN,
    // TAB_DIFFICULTY
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_PARTY_LIMIT]    = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_LEVEL_CAP]      = LOCK_FREE,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_EXP_MULTIPLIER] = LOCK_FREE,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_ITEM_PLAYER]    = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_ITEM_TRAINER]   = LOCK_FREE,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_MAX_PARTY_IVS]  = LOCK_FREE,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_SCALING_IVS]    = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_NO_EVS]         = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_SCALING_EVS]    = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_LESS_ESCAPES]   = LOCK_ONEWAY_DOWN,
    [TAB_DIFFICULTY * MAX_ITEMS_PER_TAB + ITEM_DIFFICULTY_ESCAPE_ROPE_DIG]= LOCK_ONEWAY_DOWN,
    // TAB_CHALLENGES
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_POKECENTER]    = LOCK_ONEWAY_DOWN,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_EXPENSIVE]     = LOCK_ONEWAY_DOWN,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_EVO_LIMIT]     = LOCK_ONEWAY_DOWN,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_ONE_TYPE]      = LOCK_FREE,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_BST_EQUALIZER] = LOCK_ONEWAY_DOWN,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_MIRROR]        = LOCK_ONEWAY_DOWN,
    [TAB_CHALLENGES * MAX_ITEMS_PER_TAB + ITEM_CHALLENGES_MIRROR_THIEF]  = LOCK_ONEWAY_DOWN,
};

// =============================================================================
// Window / BG templates
// =============================================================================

enum {
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION,
    WIN_CONFIRM_MSG,
};

static const struct WindowTemplate sWinTemplates[] = {
    [WIN_TOPBAR] = {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2,
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62,
    },
    [WIN_DESCRIPTION] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500,
    },
    [WIN_CONFIRM_MSG] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 20,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 604,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const u16 sBgPal[] = {RGB(14, 20, 24)};
static const u16 sTextPal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

// Frame tile IDs — loaded from window frame tileset at base 0x1A2
#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

// Text color arrays for AddTextPrinterParameterized3/4
#define TEXT_COLOR_OPTIONS_WHITE              1
#define TEXT_COLOR_OPTIONS_GRAY_FG            2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW        3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG      4
#define TEXT_COLOR_OPTIONS_ORANGE_FG          5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW      6
#define TEXT_COLOR_OPTIONS_RED_FG             7
#define TEXT_COLOR_OPTIONS_RED_SHADOW         8
#define TEXT_COLOR_OPTIONS_GREEN_FG           9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW      10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG     11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW 12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG       13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW   14

// =============================================================================
// Placeholder choice strings
// =============================================================================

static const u8 *const sChoices_OffOn[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("SÍ"),
};

static const u8 *const sChoices_OnOff[] = {
    COMPOUND_STRING("SÍ"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_Gamemode[] = {
    COMPOUND_STRING("RECOMENDADO"),
    COMPOUND_STRING("PERSONAL."),
};

static const u8 *const sChoices_OriginalModern[] = {
    COMPOUND_STRING("ORIGINAL"),
    COMPOUND_STRING("MODERNO"),
};

static const u8 sText_TopBar_Left[]   = _("{L_BUTTON}ANTERIOR");
static const u8 sText_TopBar_Right[]  = _("{R_BUTTON}SIGUIENTE");
static const u8 sText_TopBar_Save[]   = _("{R_BUTTON}GUARDAR");
static const u8 sText_TopBar_Cancel[] = _("{B_BUTTON}CANCELAR");

// =============================================================================
// Placeholder choice strings
// =============================================================================

static const u8 *const sDesc_Gamemode[] = {
    COMPOUND_STRING("Ajustes recomendados."),
    COMPOUND_STRING("Elige tus propias reglas."),
};
static const u8 *const sDesc_ModernMoves[] = {
    COMPOUND_STRING("Movimientos por nivel y HUEVO de\nGen 3 sin cambios."),
    COMPOUND_STRING("Movimientos por nivel y HUEVO de\nGen 7 + cambios menores."),
};
static const u8 *const sDesc_Synchronize[] = {
    COMPOUND_STRING("SINCRONÍA como en GEN III.\n50% prob. de copiar naturaleza."),
    COMPOUND_STRING("SINCRONÍA como en GEN VIII+.\n100% prob. de copiar naturaleza."),
};
static const u8 *const sDesc_Sturdy[] = {
    COMPOUND_STRING("ROBUSTEZ como en GEN III. Solo\nevita K.O. directo (GUILLOTINA...)"),
    COMPOUND_STRING("ROBUSTEZ como en GEN V+.\nSobrevive golpes letales con 1 PS."),
};
static const u8 *const sDesc_NewCitrus[] = {
    COMPOUND_STRING("BAYA CAÑA restaura 30 PS.\nIgual que en GEN III."),
    COMPOUND_STRING("BAYA CAÑA restaura 25% de PS.\nIgual que en GEN IV en adelante."),
};
static const u8 *const sDesc_FairyTypes[] = {
    COMPOUND_STRING("No se añade el tipo HADA a los\nPOKéMON que lo recibieron en Gen 6."),
    COMPOUND_STRING("Se añade el tipo HADA a ciertos\nPOKéMON, como en Gen 6."),
};
static const u8 *const sDesc_LegAbilities[] = {
    COMPOUND_STRING("PRESIÓN sigue siendo la habilidad\nprincipal de legendarios."),
    COMPOUND_STRING("Se cambia PRESIÓN en legendarios\npor una habilidad mejor."),
};
static const u8 *const sDesc_InfiniteTMs[] = {
    COMPOUND_STRING("Las MT no son reutilizables.\nComo en el original."),
    COMPOUND_STRING("Las MT son reutilizables."),
};
static const u8 *const sDesc_Mints[] = {
    COMPOUND_STRING("Mentas no disponibles hasta\ncompletar el juego."),
    COMPOUND_STRING("Mentas a la venta en la FLORISTERÍA\ntras la 3.ª medalla."),
};
static const u8 *const sDesc_SurvivePoison[] = {
    COMPOUND_STRING("Tus POKéMON se debilitarán si están\nENVENENADOS."),
    COMPOUND_STRING("Tus POKéMON sobrevivirán al ENVENENAMIENTO con 1 PS."),
};
static const u8 *const sDesc_Split[] = {
    COMPOUND_STRING("Movimientos FÍSICOS y ESPECIALES\ndependen del TIPO del POKéMON."),
    COMPOUND_STRING("Movimientos FÍSICOS y ESPECIALES\ndependen de cada MOVIMIENTO."),
};
static const u8 *const sChoices_Gen3Gen7[] = {
    COMPOUND_STRING("GEN 3"),
    COMPOUND_STRING("GEN 7"),
};
static const u8 *const sChoices_Gen3Gen1[] = {
    COMPOUND_STRING("GEN 3"),
    COMPOUND_STRING("GEN 1"),
};
static const u8 *const sDesc_GenOneRecharge[] = {
    COMPOUND_STRING("Movimientos como HIPERRAYO siempre\nnecesitan turno de recarga."),
    COMPOUND_STRING("Si un movimiento de recarga debilita\nal rival, no necesita recargar."),
};
static const u8 *const sDesc_Next[] = {
    COMPOUND_STRING("Continuar a la siguiente página."),
};

static const struct ChallengeMenuItem sTabItems_Mode[] = {
    [ITEM_MODE_GAMEMODE] = {
        .name         = COMPOUND_STRING("MODO JUEGO"),
        .descriptions = sDesc_Gamemode,
        .numChoices   = 2,
        .choiceNames  = sChoices_Gamemode,
    },
    [ITEM_MODE_MODERN_MOVES] = {
        .name         = COMPOUND_STRING("MOVIMIENTOS"),
        .descriptions = sDesc_ModernMoves,
        .numChoices   = 2,
        .choiceNames  = sChoices_Gen3Gen7,
    },
    [ITEM_MODE_SYNCHRONIZE] = {
        .name         = COMPOUND_STRING("SINCRONÍA"),
        .descriptions = sDesc_Synchronize,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_STURDY] = {
        .name         = COMPOUND_STRING("ROBUSTEZ"),
        .descriptions = sDesc_Sturdy,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_NEW_CITRUS] = {
        .name         = COMPOUND_STRING("BAYA CAÑA"),
        .descriptions = sDesc_NewCitrus,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_FAIRY_TYPES] = {
        .name         = COMPOUND_STRING("TIPO HADA"),
        .descriptions = sDesc_FairyTypes,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_LEGENDARY_ABILITIES] = {
        .name         = COMPOUND_STRING("HABIL. LEGEND."),
        .descriptions = sDesc_LegAbilities,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_INFINITE_TMS] = {
        .name         = COMPOUND_STRING("MT REUTILIZ."),
        .descriptions = sDesc_InfiniteTMs,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_MINTS] = {
        .name         = COMPOUND_STRING("MENTAS NATUR."),
        .descriptions = sDesc_Mints,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_SURVIVE_POISON] = {
        .name         = COMPOUND_STRING("SOBREV. VENENO"),
        .descriptions = sDesc_SurvivePoison,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_SPLIT] = {
        .name         = COMPOUND_STRING("DIV. FÍS/ESP"),
        .descriptions = sDesc_Split,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_GEN_ONE_RECHARGE] = {
        .name         = COMPOUND_STRING("RECARGA MOVS."),
        .descriptions = sDesc_GenOneRecharge,
        .numChoices   = 2,
        .choiceNames  = sChoices_Gen3Gen1,
    },
    [ITEM_MODE_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_Next,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

static const u8 *const sDesc_SaveExit[] = { COMPOUND_STRING("Guardar ajustes y continuar...") };
static const u8 sText_ConfirmSave[] = COMPOUND_STRING("¿Confirmar tu elección?");

// =============================================================================
// Choice strings — shared across tabs
// =============================================================================

static const u8 *const sChoices_OffRandom[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("ALEATORIO"),
};

static const u8 *const sChoices_TrainerPower[] = {
    COMPOUND_STRING("PROG."),
    COMPOUND_STRING("SUAVE"),
    COMPOUND_STRING("DIFÍCIL"),
    COMPOUND_STRING("MÁXIMA"),
};

static const u8 *const sChoices_TrainerItems[] = {
    COMPOUND_STRING("PROG."),
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("BAYAS"),
    COMPOUND_STRING("COMBATE"),
};

static const u8 *const sChoices_TrainerMegas[] = {
    COMPOUND_STRING("TRAMA"),
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("JEFES"),
    COMPOUND_STRING("TODOS"),
};

static const u8 *const sChoices_WildPower[] = {
    COMPOUND_STRING("PROG."),
    COMPOUND_STRING("CAÓTICA"),
};

static const u8 *const sChoices_Progression[] = {
    COMPOUND_STRING("ACTIVADA"),
    COMPOUND_STRING("CAÓTICA"),
};

static const u8 *const sChoices_TMShuffle[] = {
    COMPOUND_STRING("SÍ"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_MegaStones[] = {
    COMPOUND_STRING("POST-LAGO"),
    COMPOUND_STRING("OFF"),
};

static const u8 *const sChoices_Competitive[] = {
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("ABUNDANTE"),
    COMPOUND_STRING("OFF"),
};

static const u8 *const sChoices_GenScope[] = {
    COMPOUND_STRING("GEN 1-9"),
    COMPOUND_STRING("GEN 1-3"),
};

static const u8 *const sChoices_OffChaos[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("CAOS"),
};

static const u8 *const sChoices_YesNo[] = {
    COMPOUND_STRING("SÍ"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_BanUnban[] = {
    COMPOUND_STRING("PROHIBIR"),
    COMPOUND_STRING("PERMITIR"),
};

static const u8 *const sChoices_RtcFake[] = {
    COMPOUND_STRING("RTC"),
    COMPOUND_STRING("RTC FALSO"),
};

static const u8 *const sChoices_ShinyChance[] = {
    COMPOUND_STRING("8192"),
    COMPOUND_STRING("4096"),
    COMPOUND_STRING("2048"),
    COMPOUND_STRING("1024"),
    COMPOUND_STRING("512"),
};

static const u8 *const sChoices_Nuzlocke[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("FÁCIL"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("DIFÍCIL"),
};

static const u8 *const sChoices_CemeteryRelease[] = {
    COMPOUND_STRING("CEMENTERIO"),
    COMPOUND_STRING("SOLTAR"),
};

static const u8 *const sChoices_PartyLimit[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("5"),
    COMPOUND_STRING("4"),
    COMPOUND_STRING("3"),
    COMPOUND_STRING("2"),
    COMPOUND_STRING("1"),
};

static const u8 *const sChoices_LevelCap[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("DIFÍCIL"),
};

static const u8 *const sChoices_ExpMult[] = {
    COMPOUND_STRING("x1.0"),
    COMPOUND_STRING("x1.5"),
    COMPOUND_STRING("x2.0"),
    COMPOUND_STRING("x0.0"),
};

static const u8 *const sChoices_TrainerIVs[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("ESCALA"),
    COMPOUND_STRING("DIFÍCIL"),
};

static const u8 *const sChoices_TrainerEVs[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("ESCALA"),
    COMPOUND_STRING("DIFÍCIL"),
    COMPOUND_STRING("EXTREMO"),
};

static const u8 *const sChoices_PlayerIVs[] = {
    COMPOUND_STRING("SÍ"),
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("NO (PS)"),
};

static const u8 *const sChoices_PkmnCenter[] = {
    COMPOUND_STRING("SÍ"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_Expensive[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("x5"),
    COMPOUND_STRING("x10"),
    COMPOUND_STRING("x50!"),
};

static const u8 *const sChoices_EvoLimit[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("PRIMERA"),
    COMPOUND_STRING("TODAS"),
};

static const u8 *const sChoices_BstEqual[] = {
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("100"),
    COMPOUND_STRING("255"),
    COMPOUND_STRING("500"),
};

// =============================================================================
// FEATURES descriptions + table
// =============================================================================

// FEATURES descriptions + table
// =============================================================================

static const u8 *const sDesc_RtcType[] = {
    COMPOUND_STRING("Usa reloj en tiempo real original."),
    COMPOUND_STRING("Usa un reloj falso en tiempo real.\n1h real = 1 día en el juego."),
};
static const u8 *const sDesc_ShinyChance[] = {
    COMPOUND_STRING("Probabilidad muy baja de variocolor.\nValor por defecto de Gen III."),
    COMPOUND_STRING("Probabilidad baja de variocolor.\nValor por defecto de Gen VI+."),
    COMPOUND_STRING("Probabilidad media de variocolor."),
    COMPOUND_STRING("Probabilidad alta de variocolor."),
    COMPOUND_STRING("Probabilidad muy alta de variocolor."),
};
static const u8 *const sDesc_ItemDrop[] = {
    COMPOUND_STRING("Objetos de salvajes solo con captura\no usando ROBO."),
    COMPOUND_STRING("POKéMON salvajes sueltan su objeto\nequipado al ser derrotados."),
};
static const u8 *const sDesc_FrontierBans[] = {
    COMPOUND_STRING("Legendarios prohibidos en el\nFRENTE BATALLA. Por defecto."),
    COMPOUND_STRING("Todos los legendarios permitidos en\nel FRENTE BATALLA."),
};
static const u8 *const sDesc_ShinyColor[] = {
    COMPOUND_STRING("Paleta variocolor original para todo\nPOKéMON. Por defecto."),
    COMPOUND_STRING("Algunos POKéMON variocolor tienen\nnuevas paletas de color."),
};
static const u8 *const sDesc_FeaturesNext[] = {
    COMPOUND_STRING("Continuar a opciones Randomizer."),
};

static const struct ChallengeMenuItem sTabItems_Features[] = {
    [ITEM_FEATURES_RTC_TYPE] = {
        .name         = COMPOUND_STRING("TIPO DE RELOJ"),
        .descriptions = sDesc_RtcType,
        .numChoices   = 2,
        .choiceNames  = sChoices_RtcFake,
    },
    [ITEM_FEATURES_SHINY_CHANCE] = {
        .name         = COMPOUND_STRING("PROB. VARIOCOLOR"),
        .descriptions = sDesc_ShinyChance,
        .numChoices   = 5,
        .choiceNames  = sChoices_ShinyChance,
    },
    [ITEM_FEATURES_SHINY_COLOR] = {
        .name         = COMPOUND_STRING("PALETAS SHINY"),
        .descriptions = sDesc_ShinyColor,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_FEATURES_ITEM_DROP] = {
        .name         = COMPOUND_STRING("BOTÍN OBJETOS"),
        .descriptions = sDesc_ItemDrop,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_FEATURES_FRONTIER_BANS] = {
        .name         = COMPOUND_STRING("PROHIB. FRENTE"),
        .descriptions = sDesc_FrontierBans,
        .numChoices   = 2,
        .choiceNames  = sChoices_BanUnban,
    },
    [ITEM_FEATURES_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_FeaturesNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// RANDOMIZER descriptions + table
// =============================================================================

static const u8 *const sDesc_RandomOffOn[] = {
    COMPOUND_STRING("El juego no será aleatorizado."),
    COMPOUND_STRING("Jugar en modo aleatorizado.\n¡Ajustes a continuación!"),
};
static const u8 *const sDesc_RandomStarter[] = {
    COMPOUND_STRING("POKéMON iniciales habituales."),
    COMPOUND_STRING("Iniciales aleatorios."),
};
static const u8 *const sDesc_RandomWild[] = {
    COMPOUND_STRING("Encuentros salvajes habituales."),
    COMPOUND_STRING("Aleatoriza solo la especie.\nSlots, nivel y frecuencia no cambian."),
};
static const u8 *const sDesc_RandomMapBased[] = {
    COMPOUND_STRING("Encuentros salvajes totalmente\naleatorios en todo momento."),
    COMPOUND_STRING("Encuentros fijados por mapa.\nMisma zona siempre tiene mismos POKéMON."),
};
static const u8 *const sDesc_RandomTrainer[] = {
    COMPOUND_STRING("Entrenadores con equipos normales."),
    COMPOUND_STRING("Equipos de entrenadores aleatorios."),
};
static const u8 *const sDesc_RandomTrainerPower[] = {
    COMPOUND_STRING("Potencia ajustada al progreso."),
    COMPOUND_STRING("Equipos de una etapa anterior."),
    COMPOUND_STRING("Equipos de una etapa posterior."),
    COMPOUND_STRING("Máxima potencia desde el inicio."),
};
static const u8 *const sDesc_RandomTrainerItems[] = {
    COMPOUND_STRING("Objetos según rival y progreso."),
    COMPOUND_STRING("Sin objetos, salvo Megapiedras."),
    COMPOUND_STRING("Todos llevan una baya útil."),
    COMPOUND_STRING("Todos llevan objetos de combate."),
};
static const u8 *const sDesc_RandomTrainerMegas[] = {
    COMPOUND_STRING("Jefes tras desbloquear las Megas."),
    COMPOUND_STRING("Ningún entrenador usa Megas."),
    COMPOUND_STRING("Los jefes usan Mega desde el inicio."),
    COMPOUND_STRING("Todo equipo tiene una Mega final."),
};
static const u8 *const sDesc_RandomStatic[] = {
    COMPOUND_STRING("Encuentros estáticos normales."),
    COMPOUND_STRING("Aleatoriza especiales, casino,\nerrantes y encuentros estáticos."),
};
static const u8 *const sDesc_RandomSimilar[] = {
    COMPOUND_STRING("Especies acordes al progreso actual."),
    COMPOUND_STRING("Cualquier potencia desde el inicio."),
};
static const u8 *const sDesc_RandomLegendaries[] = {
    COMPOUND_STRING("Legendarios excluidos de aleatorizar."),
    COMPOUND_STRING("¡Incluir POKéMON legendarios en la\naleatorización!"),
};
static const u8 *const sDesc_RandomGenScope[] = {
    COMPOUND_STRING("Aleatorizar con POKéMON de todas\nlas generaciones."),
    COMPOUND_STRING("Solo POKéMON de Gen 1-3 y sus\nevoluciones cruzadas."),
};
static const u8 *const sDesc_RandomType[] = {
    COMPOUND_STRING("Tipos de POKéMON sin cambios."),
    COMPOUND_STRING("Aleatorizar tipos de POKéMON."),
};
static const u8 *const sDesc_RandomMoves[] = {
    COMPOUND_STRING("Movimientos sin cambios."),
    COMPOUND_STRING("Aleatorizar movimientos."),
};
static const u8 *const sDesc_RandomAbilities[] = {
    COMPOUND_STRING("Habilidades sin cambios."),
    COMPOUND_STRING("Aleatorizar habilidades."),
};
static const u8 *const sDesc_RandomEvolutions[] = {
    COMPOUND_STRING("Evoluciones sin cambios."),
    COMPOUND_STRING("Aleatorizar evoluciones."),
};
static const u8 *const sDesc_RandomEvoMethods[] = {
    COMPOUND_STRING("Líneas evolutivas sin cambios."),
    COMPOUND_STRING("Aleatorizar líneas evolutivas.\n¡Permite nuevas evoluciones!"),
};
static const u8 *const sDesc_RandomTypeEffec[] = {
    COMPOUND_STRING("Tabla de tipos sin cambios."),
    COMPOUND_STRING("Aleatorizar la tabla de tipos.\n¡ATENCIÓN: PUEDE TENER FALLOS!"),
};
static const u8 *const sDesc_RandomChaos[] = {
    COMPOUND_STRING("Modo caos desactivado."),
    COMPOUND_STRING("Opciones elegidas muy caóticas.\n¡NO recomendado!"),
};
static const u8 *const sDesc_RandomNext[] = {
    COMPOUND_STRING("Continuar a opciones de Objetos."),
};

static const struct ChallengeMenuItem sTabItems_Randomizer[] = {
    [ITEM_RANDOM_OFF_ON] = {
        .name         = COMPOUND_STRING("RANDOMIZER"),
        .descriptions = sDesc_RandomOffOn,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_STARTER] = {
        .name         = COMPOUND_STRING("INICIALES"),
        .descriptions = sDesc_RandomStarter,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_WILD_PKMN] = {
        .name         = COMPOUND_STRING("SALVAJES"),
        .descriptions = sDesc_RandomWild,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_MAP_BASED] = {
        .name         = COMPOUND_STRING("SEMILLA MAPA"),
        .descriptions = sDesc_RandomMapBased,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_RANDOM_TRAINER] = {
        .name         = COMPOUND_STRING("ENTRENADORES"),
        .descriptions = sDesc_RandomTrainer,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_TRAINER_POWER] = {
        .name         = COMPOUND_STRING("POTENCIA RIVAL"),
        .descriptions = sDesc_RandomTrainerPower,
        .numChoices   = 4,
        .choiceNames  = sChoices_TrainerPower,
    },
    [ITEM_RANDOM_TRAINER_ITEMS] = {
        .name         = COMPOUND_STRING("OBJETOS RIVAL"),
        .descriptions = sDesc_RandomTrainerItems,
        .numChoices   = 4,
        .choiceNames  = sChoices_TrainerItems,
    },
    [ITEM_RANDOM_TRAINER_MEGAS] = {
        .name         = COMPOUND_STRING("MEGAS RIVAL"),
        .descriptions = sDesc_RandomTrainerMegas,
        .numChoices   = 4,
        .choiceNames  = sChoices_TrainerMegas,
    },
    [ITEM_RANDOM_STATIC] = {
        .name         = COMPOUND_STRING("ESTÁTICOS"),
        .descriptions = sDesc_RandomStatic,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_SIMILAR] = {
        .name         = COMPOUND_STRING("POTENCIA SALVAJE"),
        .descriptions = sDesc_RandomSimilar,
        .numChoices   = 2,
        .choiceNames  = sChoices_WildPower,
    },
    [ITEM_RANDOM_LEGENDARIES] = {
        .name         = COMPOUND_STRING("LEGENDARIOS"),
        .descriptions = sDesc_RandomLegendaries,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_RANDOM_GEN_SCOPE] = {
        .name         = COMPOUND_STRING("RANGO GENS"),
        .descriptions = sDesc_RandomGenScope,
        .numChoices   = 2,
        .choiceNames  = sChoices_GenScope,
    },
    [ITEM_RANDOM_TYPE] = {
        .name         = COMPOUND_STRING("TIPOS"),
        .descriptions = sDesc_RandomType,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_MOVES] = {
        .name         = COMPOUND_STRING("MOVIMIENTOS"),
        .descriptions = sDesc_RandomMoves,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_ABILITIES] = {
        .name         = COMPOUND_STRING("HABILIDADES"),
        .descriptions = sDesc_RandomAbilities,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_EVOLUTIONS] = {
        .name         = COMPOUND_STRING("EVOLUCIONES"),
        .descriptions = sDesc_RandomEvolutions,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_EVO_METHODS] = {
        .name         = COMPOUND_STRING("LÍNEAS EVO"),
        .descriptions = sDesc_RandomEvoMethods,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_TYPE_EFFEC] = {
        .name         = COMPOUND_STRING("EFECTIVIDAD"),
        .descriptions = sDesc_RandomTypeEffec,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_CHAOS] = {
        .name         = COMPOUND_STRING("MODO CAOS"),
        .descriptions = sDesc_RandomChaos,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffChaos,
    },
    [ITEM_RANDOM_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_RandomNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// ITEMS descriptions + table
// =============================================================================

static const u8 *const sDesc_Items_Randomize[] = {
    COMPOUND_STRING("Los objetos del suelo no cambian."),
    COMPOUND_STRING("Aleatoriza objetos del suelo.\nObjetos clave y MO se conservan."),
};
static const u8 *const sDesc_Items_Progression[] = {
    COMPOUND_STRING("Mejores objetos según la zona\ny el progreso de la aventura."),
    COMPOUND_STRING("Cualquier objeto puede aparecer\ndesde la primera ruta."),
};
static const u8 *const sDesc_Items_TMShuffle[] = {
    COMPOUND_STRING("Baraja todas las MTs del juego entre sí\nsin repetición."),
    COMPOUND_STRING("Cada MT permanece en su ubicación original."),
};
static const u8 *const sDesc_Items_MegaStones[] = {
    COMPOUND_STRING("Permite encontrar Megapiedras en suelo\ntras los eventos del Lago de la Furia."),
    COMPOUND_STRING("No aparecen Megapiedras en el suelo."),
};
static const u8 *const sDesc_Items_Competitive[] = {
    COMPOUND_STRING("Frecuencia normal de objetos\ncomo Restos o Vidasfera."),
    COMPOUND_STRING("Aumenta los objetos útiles\npara combates exigentes."),
    COMPOUND_STRING("No aparecen objetos competitivos\nen el suelo."),
};
static const u8 *const sDesc_Items_Next[] = {
    COMPOUND_STRING("Continuar a opciones Nuzlocke."),
};

static const struct ChallengeMenuItem sTabItems_Items[] = {
    [ITEM_ITEMS_RANDOMIZE] = {
        .name         = COMPOUND_STRING("RANDOM OBJETOS"),
        .descriptions = sDesc_Items_Randomize,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_ITEMS_PROGRESSION] = {
        .name         = COMPOUND_STRING("PROGRESIÓN"),
        .descriptions = sDesc_Items_Progression,
        .numChoices   = 2,
        .choiceNames  = sChoices_Progression,
    },
    [ITEM_ITEMS_TM_SHUFFLE] = {
        .name         = COMPOUND_STRING("SHUFFLE MT"),
        .descriptions = sDesc_Items_TMShuffle,
        .numChoices   = 2,
        .choiceNames  = sChoices_TMShuffle,
    },
    [ITEM_ITEMS_MEGA_STONES] = {
        .name         = COMPOUND_STRING("MEGAPIEDRAS"),
        .descriptions = sDesc_Items_MegaStones,
        .numChoices   = 2,
        .choiceNames  = sChoices_MegaStones,
    },
    [ITEM_ITEMS_COMPETITIVE] = {
        .name         = COMPOUND_STRING("COMPETITIVOS"),
        .descriptions = sDesc_Items_Competitive,
        .numChoices   = 3,
        .choiceNames  = sChoices_Competitive,
    },
    [ITEM_ITEMS_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_Items_Next,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// NUZLOCKE descriptions + table
// =============================================================================

static const u8 *const sDesc_Nuzlocke[] = {
    COMPOUND_STRING("Modo Nuzlocke desactivado."),
    COMPOUND_STRING("¡POKéMON debilitados no se usan!\nSin más reglas obligatorias."),
    COMPOUND_STRING("¡Una captura por ruta! POKéMON\ndebilitados no se pueden usar."),
    COMPOUND_STRING("Reglas NORMAL y además se BORRA\nla partida si pierdes."),
};
static const u8 *const sDesc_SpeciesClause[] = {
    COMPOUND_STRING("Solo POKéMON no atrapados cuentan\ncomo primer encuentro. ¡RECOMENDADO!"),
    COMPOUND_STRING("Siempre se atrapa el primer POKéMON\nque aparezca por ruta."),
};
static const u8 *const sDesc_ShinyClause[] = {
    COMPOUND_STRING("Siempre se puede atrapar variocolor.\n¡RECOMENDADO!"),
    COMPOUND_STRING("Solo se atrapa variocolor si es el\nprimer encuentro de la ruta."),
};
static const u8 *const sDesc_Nicknaming[] = {
    COMPOUND_STRING("Obliga a poner mote a todo POKéMON.\n¡RECOMENDADO!"),
    COMPOUND_STRING("Poner mote es opcional."),
};
static const u8 *const sDesc_Deletion[] = {
    COMPOUND_STRING("POKéMON debilitados van al PC tras\ncombate y no se pueden sacar."),
    COMPOUND_STRING("¡POKéMON debilitados se liberan\ntras el combate!"),
};
static const u8 *const sDesc_RareCandy[] = {
    COMPOUND_STRING("Carameloraros infinitos en el PC al\nempezar la partida."),
    COMPOUND_STRING("Sin acceso a Carameloraros infinitos."),
};
static const u8 *const sDesc_PokeVial[] = {
    COMPOUND_STRING("Entrega el PokéVial y permite\nrecargarlo en Centros POKéMON."),
    COMPOUND_STRING("No entrega ni permite utilizar\nel PokéVial durante el reto."),
};
static const u8 *const sDesc_GymTokens[] = {
    COMPOUND_STRING("Las medallas dan Fichas Gimnasio\npara canjear ayudas Nuzlocke."),
    COMPOUND_STRING("Las medallas no dan fichas ni se\npueden usar sus servicios."),
};
static const u8 *const sDesc_BanHealingShop[] = {
    COMPOUND_STRING("Las tiendas no venden curas ni pociones\ndurante el reto Nuzlocke."),
    COMPOUND_STRING("Las tiendas venden objetos curativos\ncon normalidad."),
};
static const u8 *const sDesc_NuzlockeNext[] = {
    COMPOUND_STRING("Continuar a opciones de dificultad."),
};

static const struct ChallengeMenuItem sTabItems_Nuzlocke[] = {
    [ITEM_NUZLOCKE_NUZLOCKE] = {
        .name         = COMPOUND_STRING("NUZLOCKE"),
        .descriptions = sDesc_Nuzlocke,
        .numChoices   = 4,
        .choiceNames  = sChoices_Nuzlocke,
    },
    [ITEM_NUZLOCKE_SPECIES_CLAUSE] = {
        .name         = COMPOUND_STRING("CLÁUSULA DUPES"),
        .descriptions = sDesc_SpeciesClause,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_SHINY_CLAUSE] = {
        .name         = COMPOUND_STRING("CLÁUSULA SHINY"),
        .descriptions = sDesc_ShinyClause,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_NICKNAMING] = {
        .name         = COMPOUND_STRING("MOTES OBLIGAT."),
        .descriptions = sDesc_Nicknaming,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_DELETION] = {
        .name         = COMPOUND_STRING("DEBILITAMIENTO"),
        .descriptions = sDesc_Deletion,
        .numChoices   = 2,
        .choiceNames  = sChoices_CemeteryRelease,
    },
    [ITEM_NUZLOCKE_RARE_CANDY] = {
        .name         = COMPOUND_STRING("CARAMELORAROS"),
        .descriptions = sDesc_RareCandy,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_POKE_VIAL] = {
        .name         = COMPOUND_STRING("POKéVIAL"),
        .descriptions = sDesc_PokeVial,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_GYM_TOKENS] = {
        .name         = COMPOUND_STRING("FICHAS GIM."),
        .descriptions = sDesc_GymTokens,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_BAN_HEALING_SHOP] = {
        .name         = COMPOUND_STRING("CURAS TIENDA"),
        .descriptions = sDesc_BanHealingShop,
        .numChoices   = 2,
        .choiceNames  = sChoices_BanUnban,
    },
    [ITEM_NUZLOCKE_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_NuzlockeNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// DIFFICULTY descriptions + table
// =============================================================================

static const u8 sText_Desc_PartyLimit[] = _("Limita cantidad de POKéMON en equipo.\n1 puede dar fallos en DOBLES.");
static const u8 *const sDesc_PartyLimit[] = {
    sText_Desc_PartyLimit, sText_Desc_PartyLimit, sText_Desc_PartyLimit,
    sText_Desc_PartyLimit, sText_Desc_PartyLimit, sText_Desc_PartyLimit,
};
static const u8 *const sDesc_LevelCap[] = {
    COMPOUND_STRING("Sin límite. Posible levelear de más."),
    COMPOUND_STRING("Nivel máx. basado en el POKéMON de\nmás nivel del siguiente gimnasio."),
    COMPOUND_STRING("Nivel máx. basado en el POKéMON de\nmenos nivel del siguiente gimnasio."),
};
static const u8 *const sDesc_ExpMult[] = {
    COMPOUND_STRING("Puntos de EXP normales.\nAcumulable con MODO DIFÍCIL."),
    COMPOUND_STRING("¡50% más de Puntos de EXP!\nAcumulable con MODO DIFÍCIL."),
    COMPOUND_STRING("¡Doble de Puntos de EXP!\nAcumulable con MODO DIFÍCIL."),
    COMPOUND_STRING("¡¡¡CERO Puntos de EXP!!!\nAplica a MODO DIFÍCIL también."),
};
static const u8 *const sDesc_ItemPlayer[] = {
    COMPOUND_STRING("El jugador puede usar objetos."),
    COMPOUND_STRING("NO se pueden usar objetos en combate.\n¡Objetos equipados permitidos!"),
};
static const u8 *const sDesc_ItemTrainer[] = {
    COMPOUND_STRING("Entrenadores usan objetos en combate."),
    COMPOUND_STRING("Entrenadores NO usan objetos en combate."),
};
static const u8 *const sDesc_NoEVs[] = {
    COMPOUND_STRING("POKéMON ganan EVs normalmente."),
    COMPOUND_STRING("¡POKéMON NO ganan ningún EV!"),
};
static const u8 *const sDesc_ScalingIVs[] = {
    COMPOUND_STRING("Entrenadores con IVs normales."),
    COMPOUND_STRING("¡IVs de entrenadores aumentan según\nlas medallas de gimnasio!"),
    COMPOUND_STRING("¡Entrenadores con IVs perfectos!"),
};
static const u8 *const sDesc_ScalingEVs[] = {
    COMPOUND_STRING("Entrenadores sin EVs."),
    COMPOUND_STRING("¡EVs de entrenadores aumentan según\nlas medallas de gimnasio!"),
    COMPOUND_STRING("¡Entrenadores con EVs altos!"),
    COMPOUND_STRING("¡Entrenadores con 252 EVs!\n¡Muy difícil!"),
};
static const u8 *const sDesc_MaxPartyIVs[] = {
    COMPOUND_STRING("IVs habituales (entre 0 y 31)."),
    COMPOUND_STRING("IVs siempre al máximo (31)."),
    COMPOUND_STRING("IVs entre 30 y 31 para permitir\ndiferentes Poderes Ocultos."),
};
static const u8 *const sDesc_LessEscapes[] = {
    COMPOUND_STRING("Huida fácil de combates."),
    COMPOUND_STRING("No se puede huir fácilmente.\n¡Usa repelentes!"),
};
static const u8 *const sDesc_EscapeRopeDig[] = {
    COMPOUND_STRING("CUERDA HUIDA y EXCAVAR utilizables."),
    COMPOUND_STRING("CUERDA HUIDA y EXCAVAR prohibidos."),
};
static const u8 *const sDesc_DifficultyNext[] = {
    COMPOUND_STRING("Continuar a opciones de desafíos."),
};

static const struct ChallengeMenuItem sTabItems_Difficulty[] = {
    [ITEM_DIFFICULTY_PARTY_LIMIT] = {
        .name         = COMPOUND_STRING("LÍMITE EQUIPO"),
        .descriptions = sDesc_PartyLimit,
        .numChoices   = 6,
        .choiceNames  = sChoices_PartyLimit,
    },
    [ITEM_DIFFICULTY_LEVEL_CAP] = {
        .name         = COMPOUND_STRING("LÍMITE NIVEL"),
        .descriptions = sDesc_LevelCap,
        .numChoices   = 3,
        .choiceNames  = sChoices_LevelCap,
    },
    [ITEM_DIFFICULTY_EXP_MULTIPLIER] = {
        .name         = COMPOUND_STRING("MULTI. EXP."),
        .descriptions = sDesc_ExpMult,
        .numChoices   = 4,
        .choiceNames  = sChoices_ExpMult,
    },
    [ITEM_DIFFICULTY_ITEM_PLAYER] = {
        .name         = COMPOUND_STRING("OBJETOS JUGADOR"),
        .descriptions = sDesc_ItemPlayer,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_ITEM_TRAINER] = {
        .name         = COMPOUND_STRING("OBJ. ENTRENADOR"),
        .descriptions = sDesc_ItemTrainer,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_MAX_PARTY_IVS] = {
        .name         = COMPOUND_STRING("IVs JUGADOR"),
        .descriptions = sDesc_MaxPartyIVs,
        .numChoices   = 3,
        .choiceNames  = sChoices_PlayerIVs,
    },
    [ITEM_DIFFICULTY_SCALING_IVS] = {
        .name         = COMPOUND_STRING("IVs ENTRENADOR"),
        .descriptions = sDesc_ScalingIVs,
        .numChoices   = 3,
        .choiceNames  = sChoices_TrainerIVs,
    },
    [ITEM_DIFFICULTY_NO_EVS] = {
        .name         = COMPOUND_STRING("EVs JUGADOR"),
        .descriptions = sDesc_NoEVs,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_SCALING_EVS] = {
        .name         = COMPOUND_STRING("EVs ENTRENADOR"),
        .descriptions = sDesc_ScalingEVs,
        .numChoices   = 4,
        .choiceNames  = sChoices_TrainerEVs,
    },
    [ITEM_DIFFICULTY_LESS_ESCAPES] = {
        .name         = COMPOUND_STRING("HUIDA DIFÍCIL"),
        .descriptions = sDesc_LessEscapes,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_DIFFICULTY_ESCAPE_ROPE_DIG] = {
        .name         = COMPOUND_STRING("CUERDA / EXCAV."),
        .descriptions = sDesc_EscapeRopeDig,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_NEXT] = {
        .name         = COMPOUND_STRING("SIGUIENTE"),
        .descriptions = sDesc_DifficultyNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// CHALLENGES descriptions + table
// =============================================================================

static const u8 *const sDesc_Pokecenter[] = {
    COMPOUND_STRING("Puedes visitar CENTROS POKéMON para\ncurarte."),
    COMPOUND_STRING("NO puedes curarte en CENTROS POKéMON\nni otros lugares."),
};
static const u8 *const sDesc_Expensive[] = {
    COMPOUND_STRING("Todo tiene el coste habitual."),
    COMPOUND_STRING("¡Todo es 5 veces más caro!"),
    COMPOUND_STRING("¡Todo es 10 veces más caro!"),
    COMPOUND_STRING("¡Todo es 50 veces más caro!\n¡Ultra capitalismo!"),
};
static const u8 *const sDesc_EvoLimit[] = {
    COMPOUND_STRING("Evolución normal."),
    COMPOUND_STRING("Solo primera evolución."),
    COMPOUND_STRING("¡NO se puede evolucionar!"),
};
#define NUM_ONE_TYPE_CHOICES 20
#define ONE_TYPE_OFF 31
#define EVO_LINE_TYPE_SEARCH_DEPTH 4 // deepest evolution chain worth walking

static const u8 sText_Desc_OneType[] = _("Permite capturar y usar solo un tipo\nde POKéMON.");
static const u8 *const sDesc_OneType[] = {
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
};
static const u8 *const sDesc_BstEqualizer[] = {
    COMPOUND_STRING("Stats base originales."),
    COMPOUND_STRING("Stats calculadas con 100 de base."),
    COMPOUND_STRING("Stats calculadas con 255 de base."),
    COMPOUND_STRING("Stats calculadas con 500 de base."),
};
static const u8 *const sDesc_Mirror[] = {
    COMPOUND_STRING("Usas tu propio equipo."),
    COMPOUND_STRING("¡En combate contra entrenadores,\nrecibes una copia de su equipo!"),
};
static const u8 *const sDesc_MirrorThief[] = {
    COMPOUND_STRING("Recuperas tu equipo tras combatir."),
    COMPOUND_STRING("¡Te quedas con el equipo rival\ntras el combate!"),
};

static const struct ChallengeMenuItem sTabItems_Challenges[] = {
    [ITEM_CHALLENGES_POKECENTER] = {
        .name         = COMPOUND_STRING("CENTRO POKéMON"),
        .descriptions = sDesc_Pokecenter,
        .numChoices   = 2,
        .choiceNames  = sChoices_PkmnCenter,
    },
    [ITEM_CHALLENGES_EXPENSIVE] = {
        .name         = COMPOUND_STRING("TIENDA CARA"),
        .descriptions = sDesc_Expensive,
        .numChoices   = 4,
        .choiceNames  = sChoices_Expensive,
    },
    [ITEM_CHALLENGES_EVO_LIMIT] = {
        .name         = COMPOUND_STRING("LÍMITE EVO"),
        .descriptions = sDesc_EvoLimit,
        .numChoices   = 3,
        .choiceNames  = sChoices_EvoLimit,
    },
    [ITEM_CHALLENGES_ONE_TYPE] = {
        .name         = COMPOUND_STRING("MONOTIPO"),
        .descriptions = sDesc_OneType,
        .numChoices   = NUM_ONE_TYPE_CHOICES,
        .choiceNames  = NULL,
    },
    [ITEM_CHALLENGES_BST_EQUALIZER] = {
        .name         = COMPOUND_STRING("IGUALAR STATS"),
        .descriptions = sDesc_BstEqualizer,
        .numChoices   = 4,
        .choiceNames  = sChoices_BstEqual,
    },
    [ITEM_CHALLENGES_MIRROR] = {
        .name         = COMPOUND_STRING("MODO ESPEJO"),
        .descriptions = sDesc_Mirror,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_MIRROR_THIEF] = {
        .name         = COMPOUND_STRING("ROBO ESPEJO"),
        .descriptions = sDesc_MirrorThief,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_SAVE] = {
        .name         = COMPOUND_STRING("GUARDAR"),
        .descriptions = sDesc_SaveExit,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// Per-tab metadata
// =============================================================================

struct TabDef
{
    const u8 *tabName;
    const struct ChallengeMenuItem *items;
    u8 count;
};

static const struct TabDef sTabs[TAB_COUNT] = {
    [TAB_MODE]       = { COMPOUND_STRING("MODO"),       sTabItems_Mode,       ITEM_MODE_COUNT },
    [TAB_FEATURES]   = { COMPOUND_STRING("FUNCIONES"),   sTabItems_Features,   ITEM_FEATURES_COUNT },
    [TAB_RANDOMIZER] = { COMPOUND_STRING("RANDOMIZER"), sTabItems_Randomizer, ITEM_RANDOM_COUNT },
    [TAB_ITEMS]      = { COMPOUND_STRING("OBJETOS"),    sTabItems_Items,      ITEM_ITEMS_COUNT },
    [TAB_NUZLOCKE]   = { COMPOUND_STRING("NUZLOCKE"),   sTabItems_Nuzlocke,   ITEM_NUZLOCKE_COUNT },
    [TAB_DIFFICULTY] = { COMPOUND_STRING("DIFICULTAD"),  sTabItems_Difficulty, ITEM_DIFFICULTY_COUNT },
    [TAB_CHALLENGES] = { COMPOUND_STRING("DESAFÍOS"),   sTabItems_Challenges, ITEM_CHALLENGES_COUNT },
};

// =============================================================================
// Forward declarations
// =============================================================================

static void MainCB2(void);
static void VBlankCB(void);
static void Task_FadeIn(u8 taskId);
static void Task_ProcessInput(u8 taskId);
static void Task_Save(u8 taskId);
static void Task_ConfirmSaveYes(u8 taskId);
static void Task_ConfirmSaveNo(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void InitListMenu(void);
static void DestroyCurrentListMenu(void);
static void DrawTopBar(void);
static void DrawDescription(void);
static void DrawBgFrames(void);
static void DrawConfirmWindowFrame(void);
static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex);

// Temporary ListMenuItem storage for building the list each tab switch
static EWRAM_DATA struct ListMenuItem sListItems[MAX_ITEMS_PER_TAB] = {0};

// =============================================================================
// Helpers
// =============================================================================

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex)
{
    return &sMenu->selections[tab * MAX_ITEMS_PER_TAB + itemIndex];
}

static u8 GetCurrentTabItemCount(void)
{
    return sTabs[sMenu->currentTab].count;
}

static const struct ChallengeMenuItem *GetCurrentTabItems(void)
{
    return sTabs[sMenu->currentTab].items;
}

// =============================================================================
// Conditions / presets
// =============================================================================

static u8 GetLockPolicy(u8 tab, u8 itemIndex)
{
    if (sIsInitialSetup)
        return LOCK_FREE;
    return sMidGameLockPolicy[tab * MAX_ITEMS_PER_TAB + itemIndex];
}

static bool8 CheckConditions(u8 tab, u8 itemIndex)
{
    if (GetLockPolicy(tab, itemIndex) == LOCK_FULL)
        return FALSE;

    switch (tab)
    {
    case TAB_MODE:
        switch (itemIndex)
        {
        case ITEM_MODE_GAMEMODE:
        case ITEM_MODE_NEXT:
            return TRUE;
        case ITEM_MODE_FAIRY_TYPES:
            // Lock Fairy Type enabled if Fairy One Type Challenge enabled, otherwise fall through
            if (*GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_ONE_TYPE) == (TYPE_FAIRY - 2))
                return FALSE;
        default:
            return *GetSelectionPtr(TAB_MODE, ITEM_MODE_GAMEMODE) == 1; // CUSTOM
        }
    case TAB_RANDOMIZER:
    {
        u8 masterOn = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON);
        bool8 anyPkmn = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC);
        switch (itemIndex)
        {
        case ITEM_RANDOM_OFF_ON:
        case ITEM_RANDOM_NEXT:
            return TRUE;
        case ITEM_RANDOM_MAP_BASED:
            return masterOn && *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN);
        case ITEM_RANDOM_TRAINER_POWER:
        case ITEM_RANDOM_TRAINER_ITEMS:
        case ITEM_RANDOM_TRAINER_MEGAS:
            return masterOn && *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER);
        case ITEM_RANDOM_SIMILAR:
            return masterOn && *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN)
                && !(*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS));
        case ITEM_RANDOM_LEGENDARIES:
        case ITEM_RANDOM_GEN_SCOPE:
            return masterOn && anyPkmn;
        case ITEM_RANDOM_CHAOS:
            return masterOn && (anyPkmn
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC));
        default:
            return masterOn;
        }
    }
    case TAB_ITEMS:
    {
        u8 itemsOn = *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_RANDOMIZE);
        switch (itemIndex)
        {
        case ITEM_ITEMS_RANDOMIZE:
        case ITEM_ITEMS_NEXT:
            return TRUE;
        default:
            return itemsOn == 1;
        }
    }
    case TAB_NUZLOCKE:
    {
        u8 nuzSel = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE);
        switch (itemIndex)
        {
        case ITEM_NUZLOCKE_NUZLOCKE:
        case ITEM_NUZLOCKE_NEXT:
            return TRUE;
        case ITEM_NUZLOCKE_RARE_CANDY:
        case ITEM_NUZLOCKE_POKE_VIAL:
        case ITEM_NUZLOCKE_GYM_TOKENS:
            return nuzSel > 0;
        default:
            if (nuzSel == 1) // EASY — lock all sub-options except RARE_CANDY
                return FALSE;
            return nuzSel > 0;
        }
    }
    case TAB_CHALLENGES:
        switch (itemIndex)
        {
        case ITEM_CHALLENGES_MIRROR_THIEF:
            return *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR) == 1;
        default:
            return TRUE;
        }
    default:
        return TRUE;
    }
}

static void ApplyRecommendedPresets(void)
{
    // When RECOMMENDED is selected, force all mode options to their "on/new" values
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES)       = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE)        = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY)             = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS)         = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES)        = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES)= 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS)       = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS)              = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON)     = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_SPLIT)              = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_GEN_ONE_RECHARGE)   = 0; // GEN 3
}

// =============================================================================
// Callbacks
// =============================================================================

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// =============================================================================
// Row highlight (hardware window darkening band)
// =============================================================================

static void HighlightRow(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(selectedRow * Y_DIFF + 24, selectedRow * Y_DIFF + 40));
}

// =============================================================================
// Right-side choice drawing
// =============================================================================

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 chosen, bool8 active)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    if (active)
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_FG : TEXT_COLOR_OPTIONS_GRAY_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_FG : TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color, TEXT_SKIP_DRAW, text);
}

static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int widthLeft = GetStringWidth(FONT_NORMAL, txt1, 0);
    int widthMid = GetStringWidth(FONT_NORMAL, txt2, 0);
    int widthRight = GetStringWidth(FONT_NORMAL, txt3, 0);
    widthMid -= (198 - 104);
    return (widthLeft - widthMid - widthRight) / 2 + 104;
}

static void DrawChoices_Two(const u8 *const *strings, int selection, int y, bool8 active, int leftX)
{
    DrawRightSideChoiceText(strings[0], leftX, y + 1, selection == 0, active);
    DrawRightSideChoiceText(strings[1], GetStringRightAlignXOffset(FONT_NORMAL, strings[1], 198), y + 1, selection == 1, active);
}

static void DrawChoices_Three(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][2] = { {0, 1}, {1, 2}, {1, 2} };
    const u8 *order = orders[selection];
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[1]], 198), y + 1, selection == order[1], active);
}

static void DrawChoices_Four(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

static void DrawChoices_Five(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {2, 3, 4} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

static void DrawChoices_Six(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {3, 4, 5} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

// =============================================================================
// ListMenu callbacks
// =============================================================================

static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (!onInit)
        PlaySE(SE_SELECT);

    ListMenuGetScrollAndRow(sMenu->listTaskId, &sMenu->scrollOffset[sMenu->currentTab], &sMenu->selectedRow[sMenu->currentTab]);
    HighlightRow();
    DrawDescription();
}

static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    const struct ChallengeMenuItem *items = GetCurrentTabItems();

    if (itemId >= GetCurrentTabItemCount())
        return;

    bool8 active = CheckConditions(sMenu->currentTab, itemId);

    // Gray out locked item names by overriding the ListMenu text colors
    if (!active)
    {
        u8 color[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG, TEXT_COLOR_OPTIONS_GRAY_SHADOW };
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, 8, y + 1, 0, 0, color, TEXT_SKIP_DRAW, items[itemId].name);
    }

    u8 sel = *GetSelectionPtr(sMenu->currentTab, itemId);

    // ONE_TYPE draws type names dynamically instead of using choiceNames
    if (sMenu->currentTab == TAB_CHALLENGES && itemId == ITEM_CHALLENGES_ONE_TYPE)
    {
        u8 n = sel;
        const u8 *text;
        static const u8 sText_Random[] = _("RANDOM");
        static const u8 sText_Off[] = _("OFF");
        if (n > 18)
            text = sText_Off;
        else if (n == 18)
            text = sText_Random;
        else if (n >= 9)
            text = gTypesInfo[n + 2].name;
        else
            text = gTypesInfo[n + 1].name;
        DrawRightSideChoiceText(text, GetStringRightAlignXOffset(FONT_NORMAL, text, 198), y + 1, TRUE, active);
        return;
    }

    if (items[itemId].numChoices == 0 || items[itemId].choiceNames == NULL)
        return;

    if (sel >= items[itemId].numChoices)
        sel = 0;

    switch (items[itemId].numChoices)
    {
    case 2:
    {
        int leftX = (sMenu->currentTab == TAB_MODE && itemId == ITEM_MODE_GAMEMODE) ? 74 : 104;
        DrawChoices_Two(items[itemId].choiceNames, sel, y, active, leftX);
        break;
    }
    case 3:
        DrawChoices_Three(items[itemId].choiceNames, sel, y, active);
        break;
    case 4:
        DrawChoices_Four(items[itemId].choiceNames, sel, y, active);
        break;
    case 5:
        DrawChoices_Five(items[itemId].choiceNames, sel, y, active);
        break;
    case 6:
        DrawChoices_Six(items[itemId].choiceNames, sel, y, active);
        break;
    default:
    {
        const u8 *choiceStr = items[itemId].choiceNames[sel];
        u8 x = GetStringRightAlignXOffset(FONT_NORMAL, choiceStr, 198);
        DrawRightSideChoiceText(choiceStr, x, y + 1, TRUE, active);
        break;
    }
    }
}

// =============================================================================
// List menu init / teardown
// =============================================================================

static void InitListMenu(void)
{
    struct ListMenuTemplate template;
    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    u8 count = GetCurrentTabItemCount();

    for (u8 i = 0; i < count; i++)
    {
        sListItems[i].name = items[i].name;
        sListItems[i].id = i;
    }

    memset(&template, 0, sizeof(template));
    template.items = sListItems;
    template.moveCursorFunc = ChallengeMenu_MoveCursorFunc;
    template.itemPrintFunc = ChallengeMenu_ItemPrintFunc;
    template.totalItems = count;
    template.maxShowed = (count < ITEMS_VISIBLE) ? count : ITEMS_VISIBLE;
    template.windowId = WIN_OPTIONS;
    template.header_X = 0;
    template.item_X = 8;
    template.cursor_X = 0;
    template.upText_Y = 1;
    template.cursorPal = TEXT_COLOR_OPTIONS_ORANGE_FG;
    template.fillValue = 1;
    template.cursorShadowPal = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    template.lettersSpacing = 0;
    template.itemVerticalPadding = 0;
    template.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    template.fontId = FONT_NORMAL;
    template.cursorKind = CURSOR_INVISIBLE;

    sMenu->listTaskId = ListMenuInit(&template,
        sMenu->scrollOffset[sMenu->currentTab],
        sMenu->selectedRow[sMenu->currentTab]);

    HighlightRow();

    if (count > ITEMS_VISIBLE)
    {
        sMenu->arrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 240 / 2, 20, 110,
            count - ITEMS_VISIBLE,
            110, 110,
            &sMenu->scrollOffset[sMenu->currentTab]);
    }
    else
    {
        sMenu->arrowTaskId = TASK_NONE;
    }
}

static void DestroyCurrentListMenu(void)
{
    DestroyListMenuTask(sMenu->listTaskId,
        &sMenu->scrollOffset[sMenu->currentTab],
        &sMenu->selectedRow[sMenu->currentTab]);

    if (sMenu->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sMenu->arrowTaskId);
        sMenu->arrowTaskId = TASK_NONE;
    }
}

// =============================================================================
// Drawing
// =============================================================================

static void DrawTopBar(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_OPTIONS_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    const u8 *tabName = sTabs[sMenu->currentTab].tabName;
    int width = GetStringWidth(FONT_SMALL, tabName, 0) / 2;
    int right = 240 - GetStringWidth(FONT_SMALL, sText_TopBar_Right, 0) - 5;

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));

    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120 - width, 1, color, 0, tabName);

    if (sMenu->currentTab > 0)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
    if (sMenu->currentTab < TAB_COUNT - 1)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);
    else if (sMenu->currentTab == TAB_COUNT - 1)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Save);
    if (!sIsInitialSetup)
    {
        int cancelX = (120 + width + right) / 2 - GetStringWidth(FONT_SMALL, sText_TopBar_Cancel, 0) / 2;
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, cancelX, 1, color, 0, sText_TopBar_Cancel);
    }

    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawDescription(void)
{
    const u8 color[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_OPTIONS_GRAY_FG, TEXT_COLOR_OPTIONS_GRAY_SHADOW };
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex < GetCurrentTabItemCount() && items[itemIndex].descriptions != NULL)
    {
        u8 sel = *GetSelectionPtr(sMenu->currentTab, itemIndex);
        if (sel >= items[itemIndex].numChoices)
            sel = 0;
        const u8 *desc = items[itemIndex].descriptions[sel];
        if (desc != NULL)
        {
            AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL,
                8, 1, 0, 0, color, TEXT_SKIP_DRAW, desc);
        }
    }

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawBgFrames(void)
{
    // Outer frame — top edge at row 2, shared side edges rows 3-18
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);

    // Horizontal divider between options and description (row 13 bottom / row 14 top)
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);

    // Bottom edge at row 19
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

static void DrawConfirmWindowFrame(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Options box (same as DrawBgWindowFrames)
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 10,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 10,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

    // Confirm message box border (cols 1-22, leaves cols 23-28 for yes/no border)
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 21,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 22, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   22, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 21,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 22, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

// =============================================================================
// Tab switching
// =============================================================================

static void SwitchTab(u8 taskId, s8 direction)
{
    s8 newTab = sMenu->currentTab + direction;

    if (newTab < 0 || newTab > TAB_COUNT)
        return;
    else if (newTab == TAB_COUNT)
    {
        JumpListMenuToBottom(sMenu->listTaskId);
        gTasks[taskId].func = Task_Save;
        return;
    }

    DestroyCurrentListMenu();
    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));

    sMenu->currentTab = newTab;

    InitListMenu();
    DrawTopBar();
    DrawDescription();
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);

    PlaySE(SE_SELECT);
}

// =============================================================================
// Input: cycle selection left/right
// =============================================================================

static void ProcessLeftRight(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex >= GetCurrentTabItemCount())
        return;
    if (items[itemIndex].numChoices == 0)
        return;
    if (!CheckConditions(sMenu->currentTab, itemIndex))
        return;

    u8 *sel = GetSelectionPtr(sMenu->currentTab, itemIndex);
    u8 prev = *sel;

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (*sel < items[itemIndex].numChoices - 1)
            (*sel)++;
        else
            *sel = 0;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (*sel > 0)
            (*sel)--;
        else
            *sel = items[itemIndex].numChoices - 1;
    }

    if (*sel != prev && GetLockPolicy(sMenu->currentTab, itemIndex) == LOCK_ONEWAY_DOWN && *sel > prev)
    {
        *sel = prev;
        PlaySE(SE_FAILURE);
        return;
    }

    if (*sel != prev && GetLockPolicy(sMenu->currentTab, itemIndex) == LOCK_ONEWAY_UP && *sel < prev)
    {
        *sel = prev;
        PlaySE(SE_FAILURE);
        return;
    }

    if (*sel != prev)
    {
        // When GAMEMODE changes to RECOMMENDED, apply presets
        if (sMenu->currentTab == TAB_MODE && itemIndex == ITEM_MODE_GAMEMODE && *sel == 0)
            ApplyRecommendedPresets();

        // Nuzlocke OFF or EASY — reset sub-options to defaults
        if (sMenu->currentTab == TAB_NUZLOCKE && itemIndex == ITEM_NUZLOCKE_NUZLOCKE
            && (*sel == 0 || *sel == 1))
        {
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE) = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE)   = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING)     = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION)       = 0; // CEMETERY
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY)     = 1; // OFF
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_POKE_VIAL)      = 1; // OFF
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_GYM_TOKENS)     = 1; // OFF
        }

        // If Fairy monotype challenge set, force "Add Fairy Type" on
        if (sMenu->currentTab == TAB_CHALLENGES && itemIndex == ITEM_CHALLENGES_ONE_TYPE
            && *sel == (TYPE_FAIRY - 2))
        {
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES) = 1; // ON
        }

        PlaySE(SE_SELECT);
        RedrawListMenu(sMenu->listTaskId);
        HighlightRow();
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        DrawDescription();
    }
}

// =============================================================================
// Tasks
// =============================================================================

static void Task_FadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ProcessInput;
}

static void Task_ProcessInput(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        ProcessLeftRight();
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        SwitchTab(taskId, -1);
        return;
    }

    if (JOY_NEW(R_BUTTON))
    {
        SwitchTab(taskId, +1);
        return;
    }

    s32 input = ListMenu_ProcessInput(sMenu->listTaskId);

    if (input == LIST_NOTHING_CHOSEN)
        return;

    if (input == LIST_CANCEL)
    {
        if (!sIsInitialSetup)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_FadeOut;
        }
        return;
    }

    if (sMenu->currentTab == TAB_CHALLENGES && (u32)input == ITEM_CHALLENGES_SAVE)
    {
        gTasks[taskId].func = Task_Save;
        return;
    }

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if ((u32)input < GetCurrentTabItemCount()
        && items[input].numChoices == 0
        && sMenu->currentTab < TAB_COUNT - 1)
    {
        SwitchTab(taskId, +1);
    }
}

static const struct WindowTemplate sConfirmSaveYesNoTemplate =
{
    .bg          = 1,
    .tilemapLeft = 24,
    .tilemapTop  = 15,
    .width       = 4,
    .height      = 4,
    .paletteNum  = 1,
    .baseBlock   = 688,
};

static const struct YesNoFuncTable sConfirmSaveYesNoFuncs =
{
    Task_ConfirmSaveYes,
    Task_ConfirmSaveNo,
};

static void Task_Save(u8 taskId)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    // Blank description tile data so its tiles appear empty before confirm renders
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

    // Write confirm text char data
    FillWindowPixelBuffer(WIN_CONFIRM_MSG, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_CONFIRM_MSG, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, sText_ConfirmSave);
    PutWindowTilemap(WIN_CONFIRM_MSG);
    CopyWindowToVram(WIN_CONFIRM_MSG, COPYWIN_GFX);

    // Yes/no draws its own border at cols 23-28 and flushes tilemap
    CreateYesNoMenuWithCallbacks(taskId, &sConfirmSaveYesNoTemplate, 1, 0, 0, 0x1A2, 7, &sConfirmSaveYesNoFuncs);

    // Draw confirm box border AFTER yes/no so its tiles aren't overwritten, flush tilemap
    DrawConfirmWindowFrame();
}

static void Task_ConfirmSaveYes(u8 taskId)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

#if IS_HNS
    SeedRngAndSetTrainerId();
#endif

    // Mode tab
    cs->tx_Mode_Modern_Moves       = *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES);
    cs->tx_Mode_Synchronize        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE);
    cs->tx_Mode_Sturdy             = *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY);
    cs->tx_Mode_New_Citrus         = *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS);
    cs->tx_Mode_Fairy_Types        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES);
    cs->tx_Mode_Legendary_Abilities= *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES);
    cs->tx_Mode_InfiniteTMs        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS);
    cs->tx_Mode_Mints              = *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS);
    if (cs->tx_Mode_Mints)
        FlagClear(FLAG_MINTS_DISABLED);
    else
        FlagSet(FLAG_MINTS_DISABLED);
    cs->tx_Mode_PoisonSurvive      = *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON);
    cs->optionStyle                = !*GetSelectionPtr(TAB_MODE, ITEM_MODE_SPLIT);
    cs->genOneRecharge             = *GetSelectionPtr(TAB_MODE, ITEM_MODE_GEN_ONE_RECHARGE);

    // Features tab
    cs->tx_Features_RTCType        = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_RTC_TYPE);
    cs->tx_Features_ShinyChance    = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_CHANCE);
    cs->tx_Features_WildMonDropItems = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_ITEM_DROP);
    cs->tx_Features_FrontierBans   = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_FRONTIER_BANS);
    cs->tx_Features_ShinyColors    = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_COLOR);

    // Randomizer tab — if master toggle is OFF, clear all sub-fields
    if (*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON) == 0)
    {
        cs->tx_Random_Starter          = 0;
        cs->tx_Random_WildPokemon      = 0;
        cs->tx_Random_MapBased         = 0;
        cs->tx_Random_Trainer          = 0;
        cs->tx_Random_TrainerPower     = TRAINER_POWER_PROGRESSIVE;
        cs->tx_Random_TrainerItems     = TRAINER_ITEMS_PROGRESSIVE;
        cs->tx_Random_TrainerMegas     = TRAINER_MEGAS_STORY;
        cs->tx_Random_Static           = 0;
        cs->tx_Random_Similar          = 0;
        cs->tx_Random_IncludeLegendaries = 0;
        // Not cleared to 0 like the rest: 0 means "all generations", so zeroing
        // it here would quietly drop the default the next time the randomizer is
        // switched back on. It is inert while the randomizer is off, and it is
        // not part of the master-toggle derivation on load.
        cs->tx_Random_GenScope         = RANDOMIZER_DEFAULT_GEN_SCOPE_1_3;
        cs->tx_Random_Type             = 0;
        cs->tx_Random_Moves            = 0;
        cs->tx_Random_Abilities        = 0;
        cs->tx_Random_Evolutions       = 0;
        cs->tx_Random_EvolutionMethods = 0;
        cs->tx_Random_TypeEffectiveness= 0;
        cs->tx_Random_Items            = 0;
        cs->tx_Random_Chaos            = 0;
    }
    else
    {
        cs->tx_Random_Starter          = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER);
        cs->tx_Random_WildPokemon      = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN);
        cs->tx_Random_MapBased         = cs->tx_Random_WildPokemon ? *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MAP_BASED) : 0;
        cs->tx_Random_Trainer          = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER);
        cs->tx_Random_TrainerPower     = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_POWER);
        cs->tx_Random_TrainerItems     = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_ITEMS);
        cs->tx_Random_TrainerMegas     = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_MEGAS);
        cs->tx_Random_Static           = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC);
        cs->tx_Random_Similar          = !(*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR));
        cs->tx_Random_IncludeLegendaries = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_LEGENDARIES);
        cs->tx_Random_GenScope         = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_GEN_SCOPE);
        cs->tx_Random_Type             = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE);
        cs->tx_Random_Moves            = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES);
        cs->tx_Random_Abilities        = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES);
        cs->tx_Random_Evolutions       = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS);
        cs->tx_Random_EvolutionMethods = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS);
        cs->tx_Random_TypeEffectiveness= *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC);
        cs->tx_Random_Chaos            = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS);
    }

    // Items tab
    if (*GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_RANDOMIZE) == 0)
    {
        cs->tx_Random_Items             = 0;
        cs->tx_Random_Items_Progression = 0;
        cs->tx_Random_Items_TMShuffle   = 0;
        cs->tx_Random_Items_MegaStones  = 0;
        cs->tx_Random_Items_Competitive = 0;
    }
    else
    {
        cs->tx_Random_Items             = 1;
        cs->tx_Random_Items_Progression = *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_PROGRESSION);
        cs->tx_Random_Items_TMShuffle   = *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_TM_SHUFFLE);
        cs->tx_Random_Items_MegaStones  = *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_MEGA_STONES);
        cs->tx_Random_Items_Competitive = *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_COMPETITIVE);
    }

    // Nuzlocke tab — decompose selection back to 3 bits (matches HnS encoding)
    {
        u8 nuzSel = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE);
        cs->tx_Challenges_Nuzlocke         = (nuzSel >= 2) ? 1 : 0;
        cs->tx_Nuzlocke_EasyMode           = (nuzSel == 1) ? 1 : 0;
        cs->tx_Challenges_NuzlockeHardcore = (nuzSel == 3) ? 1 : 0;
        cs->tx_Nuzlocke_PokeVial           = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_POKE_VIAL));
        cs->tx_Nuzlocke_GymTokens          = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_GYM_TOKENS));
        cs->tx_Nuzlocke_BanHealingShop     = (*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_BAN_HEALING_SHOP) == 0) ? 1 : 0;

        if (nuzSel == 0) // OFF — clear sub-options
        {
            cs->tx_Nuzlocke_SpeciesClause = 0;
            cs->tx_Nuzlocke_ShinyClause   = 0;
            cs->tx_Nuzlocke_Nicknaming    = 0;
        }
        else if (nuzSel == 1) // EASY — save RareCandy, clear clauses
        {
            cs->tx_Nuzlocke_RareCandy     = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY));
            cs->tx_Nuzlocke_SpeciesClause = 0;
            cs->tx_Nuzlocke_ShinyClause   = 0;
            cs->tx_Nuzlocke_Nicknaming    = 0;
        }
        else // NORMAL or HARD — save all sub-options with polarity inversion
        {
            cs->tx_Nuzlocke_SpeciesClause = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE));
            cs->tx_Nuzlocke_ShinyClause   = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE));
            cs->tx_Nuzlocke_Nicknaming    = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING));
            cs->tx_Nuzlocke_Deletion      = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION);
            cs->tx_Nuzlocke_RareCandy     = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY));
        }
    }

    // Difficulty tab
    cs->tx_Challenges_PartyLimit      = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_PARTY_LIMIT);
    cs->tx_Challenges_LevelCap        = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LEVEL_CAP);
    cs->tx_Challenges_ExpMultiplier   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_EXP_MULTIPLIER);
    cs->tx_Challenges_NoItemPlayer    = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_PLAYER);
    cs->tx_Challenges_NoItemTrainer   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_TRAINER);
    cs->tx_Challenges_NoEVs           = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_NO_EVS);
    cs->tx_Challenges_TrainerScalingIVs = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_IVS);
    cs->tx_Challenges_TrainerScalingEVs = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_EVS);
    cs->tx_Challenges_MaxPartyIVs     = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_MAX_PARTY_IVS);
    cs->tx_Challenges_LessEscapes     = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LESS_ESCAPES);
    cs->tx_Difficulty_EscapeRopeDig   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ESCAPE_ROPE_DIG);

    // Challenges tab
    cs->tx_Challenges_PkmnCenter      = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_POKECENTER);
    cs->tx_Challenges_Expensive       = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EXPENSIVE);
    cs->tx_Challenges_EvoLimit        = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EVO_LIMIT);
    // ONE_TYPE: map selection position back to type index
    {
        u8 otSel = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_ONE_TYPE);
        static const u8 sValidTypes[] = {
            TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND,
            TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL, TYPE_FIRE, TYPE_WATER,
            TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC, TYPE_ICE, TYPE_DRAGON,
            TYPE_DARK, TYPE_FAIRY,
        };
        if (otSel > 18)
            cs->tx_Challenges_OneTypeChallenge = ONE_TYPE_OFF;
        else if (otSel == 18)
            cs->tx_Challenges_OneTypeChallenge = sValidTypes[Random() % ARRAY_COUNT(sValidTypes)];
        else if (otSel >= 9)
            cs->tx_Challenges_OneTypeChallenge = otSel + 2;
        else
            cs->tx_Challenges_OneTypeChallenge = otSel + 1;
    }
    cs->tx_Challenges_BaseStatEqualizer = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_BST_EQUALIZER);
    cs->tx_Challenges_Mirror          = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR);
    cs->tx_Challenges_Mirror_Thief    = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR_THIEF);

    // If Fairy monotype challenge set, force "Add Fairy Type" on
    if (!cs->tx_Mode_Fairy_Types)    
        cs->tx_Mode_Fairy_Types = cs->tx_Challenges_OneTypeChallenge == TYPE_FAIRY;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_FadeOut;
}

static void Task_ConfirmSaveNo(u8 taskId)
{
    PutWindowTilemap(WIN_DESCRIPTION);
    DrawDescription();
    DrawBgFrames();
    gTasks[taskId].func = Task_ProcessInput;
}

static void Task_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyCurrentListMenu();
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sMenu);
        SetMainCallback2(gMain.savedCallback);
    }
}

// =============================================================================
// Init
// =============================================================================

void CB2_InitChallengeMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ResetBgPositions();
        InitWindows(sWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, 224));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, 104));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sBgPal, 0, sizeof(sBgPal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sTextPal, 16, sizeof(sTextPal));
        gMain.state++;
        break;
    case 6:
        sMenu = AllocZeroed(sizeof(struct ChallengeMenuState));
        sMenu->currentTab = TAB_MODE;
        sMenu->arrowTaskId = TASK_NONE;

        {
            struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

            // Mode tab — load sub-items, then derive GAMEMODE from whether they match recommended
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES)       = cs->tx_Mode_Modern_Moves;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE)        = cs->tx_Mode_Synchronize;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY)             = cs->tx_Mode_Sturdy;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS)         = cs->tx_Mode_New_Citrus;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES)        = cs->tx_Mode_Fairy_Types;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES)= cs->tx_Mode_Legendary_Abilities;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS)       = cs->tx_Mode_InfiniteTMs;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS)              = cs->tx_Mode_Mints;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON)     = cs->tx_Mode_PoisonSurvive;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_SPLIT)              = !cs->optionStyle;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_GEN_ONE_RECHARGE)   = cs->genOneRecharge;

            if (cs->tx_Mode_Modern_Moves == 1
             && cs->tx_Mode_Synchronize == 1
             && cs->tx_Mode_Sturdy == 1
             && cs->tx_Mode_New_Citrus == 1
             && cs->tx_Mode_Fairy_Types == 1
             && cs->tx_Mode_Legendary_Abilities == 1
             && cs->tx_Mode_InfiniteTMs == 1
             && cs->tx_Mode_Mints == 1
             && cs->tx_Mode_PoisonSurvive == 1
             && cs->optionStyle == 0
             && cs->genOneRecharge == 0)
                *GetSelectionPtr(TAB_MODE, ITEM_MODE_GAMEMODE) = 0; // RECOMMENDED
            else
                *GetSelectionPtr(TAB_MODE, ITEM_MODE_GAMEMODE) = 1; // CUSTOM

            // Features tab
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_RTC_TYPE)     = cs->tx_Features_RTCType;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_CHANCE) = cs->tx_Features_ShinyChance;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_ITEM_DROP)    = cs->tx_Features_WildMonDropItems;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_FRONTIER_BANS)= cs->tx_Features_FrontierBans;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_COLOR)  = cs->tx_Features_ShinyColors;

            // Randomizer tab — derive master toggle from whether any sub-field is active
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON) =
                (cs->tx_Random_Starter || cs->tx_Random_WildPokemon
              || cs->tx_Random_Trainer || cs->tx_Random_Static
              || cs->tx_Random_Type || cs->tx_Random_Moves
              || cs->tx_Random_Abilities || cs->tx_Random_Evolutions
              || cs->tx_Random_EvolutionMethods || cs->tx_Random_TypeEffectiveness) ? 1 : 0;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER)     = cs->tx_Random_Starter;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN)   = cs->tx_Random_WildPokemon;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MAP_BASED)  = cs->tx_Random_MapBased;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER)     = cs->tx_Random_Trainer;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_POWER) = cs->tx_Random_TrainerPower;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_ITEMS) = cs->tx_Random_TrainerItems;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER_MEGAS) = cs->tx_Random_TrainerMegas;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC)      = cs->tx_Random_Static;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR)     = !cs->tx_Random_Similar;
            if (sIsInitialSetup && *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON) == 0)
                *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR) = 0;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_LEGENDARIES) = cs->tx_Random_IncludeLegendaries;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_GEN_SCOPE)   = cs->tx_Random_GenScope;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE)        = cs->tx_Random_Type;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES)       = cs->tx_Random_Moves;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES)   = cs->tx_Random_Abilities;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS)  = cs->tx_Random_Evolutions;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS) = cs->tx_Random_EvolutionMethods;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC)  = cs->tx_Random_TypeEffectiveness;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS)       = cs->tx_Random_Chaos;

            // Items tab
            *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_RANDOMIZE)   = cs->tx_Random_Items;
            *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_PROGRESSION) = cs->tx_Random_Items_Progression;
            *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_TM_SHUFFLE)  = cs->tx_Random_Items_TMShuffle;
            *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_MEGA_STONES) = cs->tx_Random_Items_MegaStones;
            *GetSelectionPtr(TAB_ITEMS, ITEM_ITEMS_COMPETITIVE) = cs->tx_Random_Items_Competitive;

            // Nuzlocke tab — 3 bits → 4 selection states (matches HnS encoding)
            if (cs->tx_Challenges_Nuzlocke && cs->tx_Challenges_NuzlockeHardcore)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 3; // HARD
            else if (cs->tx_Challenges_Nuzlocke)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 2; // NORMAL
            else if (cs->tx_Nuzlocke_EasyMode)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 1; // EASY
            else
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 0; // OFF
            // Polarity inversion: SaveBlock 1 = active, UI 0 = ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE) = !cs->tx_Nuzlocke_SpeciesClause;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE)   = !cs->tx_Nuzlocke_ShinyClause;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING)     = !cs->tx_Nuzlocke_Nicknaming;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION)       = cs->tx_Nuzlocke_Deletion;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY)     = !cs->tx_Nuzlocke_RareCandy;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_POKE_VIAL)      = !cs->tx_Nuzlocke_PokeVial;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_GYM_TOKENS)     = !cs->tx_Nuzlocke_GymTokens;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_BAN_HEALING_SHOP) = cs->tx_Nuzlocke_BanHealingShop ? 0 : 1;

            // Difficulty tab
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_PARTY_LIMIT)    = cs->tx_Challenges_PartyLimit;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LEVEL_CAP)      = cs->tx_Challenges_LevelCap;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_EXP_MULTIPLIER) = cs->tx_Challenges_ExpMultiplier;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_PLAYER)    = cs->tx_Challenges_NoItemPlayer;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_TRAINER)   = cs->tx_Challenges_NoItemTrainer;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_NO_EVS)         = cs->tx_Challenges_NoEVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_IVS)    = cs->tx_Challenges_TrainerScalingIVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_EVS)    = cs->tx_Challenges_TrainerScalingEVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_MAX_PARTY_IVS)  = cs->tx_Challenges_MaxPartyIVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LESS_ESCAPES)   = cs->tx_Challenges_LessEscapes;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ESCAPE_ROPE_DIG)= cs->tx_Difficulty_EscapeRopeDig;

            // Challenges tab
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_POKECENTER)    = cs->tx_Challenges_PkmnCenter;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EXPENSIVE)     = cs->tx_Challenges_Expensive;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EVO_LIMIT)     = cs->tx_Challenges_EvoLimit;
            // ONE_TYPE: map SaveBlock type index to selection position
            {
                u8 typeVal = cs->tx_Challenges_OneTypeChallenge;
                u8 oneTypeSel;
                if (typeVal >= ONE_TYPE_OFF || typeVal == TYPE_NONE || typeVal == TYPE_MYSTERY || typeVal == TYPE_STELLAR)
                    oneTypeSel = 19; // OFF
                else if (typeVal <= TYPE_STEEL)
                    oneTypeSel = typeVal - 1; // types 1-9 → sel 0-8
                else
                    oneTypeSel = typeVal - 2; // types 11-19 → sel 9-17
                *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_ONE_TYPE) = oneTypeSel;
            }
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_BST_EQUALIZER) = cs->tx_Challenges_BaseStatEqualizer;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR)        = cs->tx_Challenges_Mirror;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR_THIEF)  = cs->tx_Challenges_Mirror_Thief;
        }

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        PutWindowTilemap(WIN_OPTIONS);
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawTopBar();
        DrawBgFrames();
        InitListMenu();
        DrawDescription();
        CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
        gMain.state++;
        break;
    case 8:
        CreateTask(Task_FadeIn, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

// =============================================================================
// Script entry point (for callnative)
// =============================================================================

void ChallengeMenu_SetInitialSetup(bool8 isInitial)
{
    sIsInitialSetup = isInitial;
}

void Script_OpenChallengeMenu(struct ScriptContext *ctx)
{
    sIsInitialSetup = FALSE;
    ScriptContext_Stop();
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    SetMainCallback2(CB2_InitChallengeMenu);
}

void Script_CheckPokemitosCupActive(struct ScriptContext *ctx)
{
    gSpecialVar_Result = IsPokemitosCupActive();
}

bool32 HMsOverwriteOptionActive(void)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;
    return (cs->tx_Challenges_Nuzlocke
            || cs->tx_Nuzlocke_EasyMode
            || cs->tx_Challenges_Mirror
            || cs->tx_Random_Moves
            || cs->tx_Challenges_PartyLimit != 0
            || cs->tx_Challenges_OneTypeChallenge != ONE_TYPE_OFF);
}

u8 GetMaxPartySize(void)
{
    return (PARTY_SIZE - gSaveBlock3Ptr->challengeSettings.tx_Challenges_PartyLimit);
}

bool8 IsPartyLimitChallengeActive(void)
{
    return (gSaveBlock3Ptr->challengeSettings.tx_Challenges_PartyLimit != 0);
}

u32 GetBaseStatEqualizerValue(void)
{
    static const u16 sEqualizerValues[] = {0, 100, 255, 500};
    u8 setting = gSaveBlock3Ptr->challengeSettings.tx_Challenges_BaseStatEqualizer;
    if (setting >= ARRAY_COUNT(sEqualizerValues))
        return 0;
    return sEqualizerValues[setting];
}

static u8 GetChallengesBadgeCount(void)
{
    u16 i;
    u8 badgeCount = 0;
    for (i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }
    if (badgeCount > 8)
        badgeCount = 8;
    return badgeCount;
}

static const u8 sTrainerIVTable[] =
{
    [0] = 7,
    [1] = 10,
    [2] = 13,
    [3] = 16,
    [4] = 19,
    [5] = 22,
    [6] = 25,
    [7] = 28,
    [8] = 31,
};

static const u8 sTrainerEVTable[] =
{
    [0] = 12,
    [1] = 24,
    [2] = 36,
    [3] = 48,
    [4] = 60,
    [5] = 72,
    [6] = 80,
    [7] = 100,
    [8] = 128,
};

u8 GetCurrentTrainerIVs(void)
{
    switch (gSaveBlock3Ptr->challengeSettings.tx_Challenges_TrainerScalingIVs)
    {
    case 1:     return sTrainerIVTable[GetChallengesBadgeCount()];
    default:    return MAX_PER_STAT_IVS;
    }
}

u8 GetCurrentTrainerEVs(void)
{
    switch (gSaveBlock3Ptr->challengeSettings.tx_Challenges_TrainerScalingEVs)
    {
    case 1:     return sTrainerEVTable[GetChallengesBadgeCount()];
    case 2:     return 128;
    case 3:     return 252;
    default:    return 0;
    }
}

bool8 IsPokecenterChallengeActivated(void)
{
    return gSaveBlock3Ptr->challengeSettings.tx_Challenges_PkmnCenter;
}

bool8 IsOneTypeChallengeActive(void)
{
    return gSaveBlock3Ptr->challengeSettings.tx_Challenges_OneTypeChallenge != ONE_TYPE_OFF;
}

// Returns TRUE if the species has the given type, or if any species it can
// eventually evolve into has it. Lets pre-evolutions that "grow into" the
// challenge type (e.g. Trapinch for a Dragon run) be used.
static bool8 DoesEvoLineHaveType(u16 species, u8 type, u8 depth)
{
    const struct Evolution *evolutions;
    u32 i;

    if (species == SPECIES_NONE || depth > EVO_LINE_TYPE_SEARCH_DEPTH)
        return FALSE;

    if (GetSpeciesType(species, 0) == type || GetSpeciesType(species, 1) == type)
        return TRUE;

    evolutions = GetSpeciesEvolutions(species);
    if (evolutions == NULL)
        return FALSE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        u16 target = evolutions[i].targetSpecies;

        // An evolution can point at a species this build has compiled out.
        if (target == SPECIES_NONE || target > NUM_SPECIES || !IsSpeciesEnabled(target))
            continue;

        if (DoesEvoLineHaveType(target, type, depth + 1))
            return TRUE;
    }

    return FALSE;
}

bool8 DoesSpeciesPassOneTypeChallenge(u16 species)
{
    if (!IsOneTypeChallengeActive())
        return TRUE;

    return DoesEvoLineHaveType(species, gSaveBlock3Ptr->challengeSettings.tx_Challenges_OneTypeChallenge, 0);
}
