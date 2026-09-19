#include "battle_dynamax.h"
#include "battle_anim_scripts.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/contest.h"

// The Gen. 4+ contest data comes from urpg's contest movedex.

#if B_BINDING_TURNS >= GEN_5
#define BINDING_TURNS "4 or 5"
#else
#define BINDING_TURNS "2 to 5"
#endif

// Shared Move Description entries

const u8 gNotDoneYetDescription[] = _(
    "This move can't be used. Its\n"
    "effect is in development.");

static const u8 sNullDescription[] = _("");

static const u8 sMegaDrainDescription[] = _(
    "Ataque que absorbe la\n"
    "mitad del daño causado.");

#if B_SKIP_RECHARGE != GEN_1
static const u8 sHyperBeamDescription[] = _(
    "Potente ataque, pero el\n"
    "usuario reposa un turno.");
#else
static const u8 sHyperBeamDescription[] = _(
    "Potente ataque, pero el\n"
    "usuario reposa un turno.");
#endif

static const u8 sRevengeDescription[] = _(
    "Ataque que actúa al final\n"
    "y gana fuerza si es dañado.");

static const u8 sPluckDescription[] = _(
    "Come la baya del rival\n"
    "y obtiene su efecto.");

static const u8 sHealingWishDescription[] = _(
    "El usuario se debilita\n"
    "para curar al relevo.");

static const u8 sWringOutDescription[] = _(
    "Causa más daño cuantos\n"
    "más PS tenga el rival.");

static const u8 sUTurnDescription[] = _(
    "Causa daño y después\n"
    "regresa al equipo.");

static const u8 sStormThrowDescription[] = _(
    "Ataque que siempre resulta\n"
    "en un impacto crítico.");

static const u8 sCircleThrowDescription[] = _(
    "Lanza al rival fuera para\n"
    "forzar el relevo.");

static const u8 sChipAwayDescription[] = _(
    "Golpea ignorando los\n"
    "cambios de stats rivales.");

static const u8 sHeavySlamDescription[] = _(
    "Causa más daño cuanto\n"
    "más pese el usuario.");

static const u8 sPsyshockDescription[] = _(
    "Ataque con onda psíquica\n"
    "que causa daño físico.");

static const u8 sLavaPlumeDescription[] = _(
    "Llamas escarlata que dañan\n"
    "a todos alrededor.");

static const u8 sShadowForceDescription[] = _(
    "Desaparece en turno 1 y\n"
    "golpea en el turno 2.");

static const u8 sFalseSwipeDescription[] = _(
    "Ataque que deja al rival\n"
    "con al menos 1 PS.");

static const u8 sDrainingKissDescription[] = _(
    "Ataque que absorbe más de\n"
    "la mitad del daño.");

static const u8 sCloseCombatDescription[] = _(
    "Ataque fuerte pero reduce\n"
    "las defensas propias.");

static const u8 sHyperspaceHoleDescription[] = _(
    "Usa un agujero espacial;\n"
    "no puede ser esquivado.");

static const u8 sSuckerPunchDescription[] = _(
    "Golpea primero si el rival\n"
    "iba a atacar.");

static const u8 sFeintDescription[] = _(
    "Ataque que golpea a rivales\n"
    "que usen Protección.");

static const u8 sProtectDescription[] = _(
    "Evade ataques; puede fallar\n"
    "si se usa sin cesar.");

static const u8 sGMaxOneBlowDescription[] = _(
    "Ataque Gigamax de Urshifu.\n"
    "Ignora Maxibarrera.");

const struct MoveInfo gMovesInfo[MOVES_COUNT_ALL] =
{
    [MOVE_NONE] =
    {
        .name = COMPOUND_STRING("-"),
        .description = COMPOUND_STRING(""),
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .sketchBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_None,
    },

    [MOVE_POUND] =
    {
        .name = COMPOUND_STRING("Destructor"),
        .description = COMPOUND_STRING(
            "Golpea con las patas o la\n"
        "cola."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_POUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pound,
    },

    [MOVE_KARATE_CHOP] =
    {
        .name = COMPOUND_STRING("Golpe Kárate"),
        .description = COMPOUND_STRING(
            "Golpe cortante con alta\n"
        "probabilidad de crítico."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FIGHTING : TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_KarateChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .name = COMPOUND_STRING("Doble Bofetón"),
        .description = COMPOUND_STRING(
            "Abofetea repetidamente\n"
        "al rival de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_DoubleSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COMET_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Cometa"),
        .description = COMPOUND_STRING(
            "Golpea repetidamente\n"
        "al rival de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CometPunch,
    },

    [MOVE_MEGA_PUNCH] =
    {
        .name = COMPOUND_STRING("Megapuño"),
        .description = COMPOUND_STRING(
            "Un puñetazo de gran\n"
        "potencia."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAY_DAY] =
    {
        .name = COMPOUND_STRING("Día de Pago"),
        .description = COMPOUND_STRING(
            "Arroja monedas al objetivo\n"
        "y las recupera al final\n"
        "del combate."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PayDay,
    },

    [MOVE_FIRE_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Fuego"),
        .description = COMPOUND_STRING(
            "Puñetazo ardiente que\n"
        "puede causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_ICE_PUNCH, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_FirePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Hielo"),
        .description = COMPOUND_STRING(
            "An icy punch that may\n"
        #if B_USE_FROSTBITE == TRUE
            "leave the foe with frostbite."),
        #else
            "freeze the foe."),
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_ICE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_IcePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Trueno"),
        .description = COMPOUND_STRING(
            "Puñetazo eléctrico que\n"
        "puede paralizar al\n"
        "adversario."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
        .battleAnimScript = gBattleAnimMove_ThunderPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCRATCH] =
    {
        .name = COMPOUND_STRING("Arañazo"),
        .description = COMPOUND_STRING(
            "Araña con afiladas garras."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCRATCH,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Scratch,
    },

    [MOVE_VISE_GRIP] =
    {
        .name = COMPOUND_STRING("Agarre"),
        .description = COMPOUND_STRING(
            "Atrapa y atenaza al\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_VICE_GRIP,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ViseGrip,
    },

    [MOVE_GUILLOTINE] =
    {
        .name = COMPOUND_STRING("Guillotina"),
        .description = COMPOUND_STRING(
            "Ataque cortante que\n"
        "debilita al oponente de un\n"
        "golpe si acierta."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Guillotine,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_WIND] =
    {
        .name = COMPOUND_STRING("Viento Cortante"),
        #if B_UPDATED_MOVE_DATA == GEN_3 || B_UPDATED_MOVE_DATA == GEN_1
            .description = COMPOUND_STRING(
                "Carga un turno y ataca\n"
        "con viento al siguiente."),
        #else
            .description = COMPOUND_STRING(
                "Carga un turno y ataca\n"
        "con viento al siguiente."),
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 75,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .criticalHitStage = 1,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .criticalHitStage = 2,
        #else
            .criticalHitStage = 0,
        #endif
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNWHIPPEDWHIRLWIND },
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorWind,
    },

    [MOVE_SWORDS_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Espada"),
        .description = COMPOUND_STRING(
            "Baile frenético que\n"
        "aumenta mucho el Ataque."),
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SwordsDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CUT] =
    {
        .name = COMPOUND_STRING("Corte"),
        .description = COMPOUND_STRING(
            "Corta al adversario con\n"
        "garras, guadañas, etc."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Cut,
    },

    [MOVE_GUST] =
    {
        .name = COMPOUND_STRING("Tornado"),
        .description = COMPOUND_STRING(
            "Crea un tornado con las\n"
        "alas y lo lanza contra el\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FLYING : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .damagesAirborneDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .windMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gust,
    },

    [MOVE_WING_ATTACK] =
    {
        .name = COMPOUND_STRING("Ataque Ala"),
        .description = COMPOUND_STRING(
            "Golpea al objetivo con\n"
        "unas grandes alas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 60 : 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WingAttack,
    },

    [MOVE_WHIRLWIND] =
    {
        .name = COMPOUND_STRING("Remolino"),
        .description = COMPOUND_STRING(
            "Se lleva al objetivo, que\n"
        "es cambiado por otro\n"
        "Pokémon. Si es un Pokémon"),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .accuracy = 100,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .accuracy = 100,
            .priority = -1,
        #else
            .accuracy = 85,
            .priority = 0,
        #endif
        .pp = 20,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .windMove = TRUE,
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Whirlwind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLY] =
    {
        .name = COMPOUND_STRING("Vuelo"),
        .description = COMPOUND_STRING(
            "El usuario vuela en el\n"
        "primer turno y ataca en el\n"
        "segundo."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNFLEWHIGH, .status = STATE_ON_AIR },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Fly,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIND] =
    {
        .name = COMPOUND_STRING("Atadura"),
        .description = COMPOUND_STRING(
            "Ata y oprime de cuatro a\n"
        "cinco turnos."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_BIND,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Bind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLAM] =
    {
        .name = COMPOUND_STRING("Atizar"),
        .description = COMPOUND_STRING(
            "Golpea con la cola o con\n"
        "lianas, por ejemplo, para\n"
        "causar daño al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_Slam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VINE_WHIP] =
    {
        .name = COMPOUND_STRING("Látigo Cepa"),
        .description = COMPOUND_STRING(
            "Azota al objetivo con\n"
        "ramas finas."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 45 : 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_VineWhip,
    },

    [MOVE_STOMP] =
    {
        .name = COMPOUND_STRING("Pisotón"),
        .description = COMPOUND_STRING(
            "Tremendo pisotón que puede\n"
        "hacer que el objetivo se\n"
        "amedrente."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Stomp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .name = COMPOUND_STRING("Doble Patada"),
        .description = COMPOUND_STRING(
            "Una patada doble. Golpea\n"
        "dos veces."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGA_KICK] =
    {
        .name = COMPOUND_STRING("Megapatada"),
        .description = COMPOUND_STRING(
            "Patada de extrema fuerza."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_JUMP_KICK] =
    {
        .name = COMPOUND_STRING("Patada Salto"),
        .description = COMPOUND_STRING(
            "Patada con salto potente.\n"
        "Daña al usuario si falla."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 85,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_JumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLING_KICK] =
    {
        .name = COMPOUND_STRING("Patada Giro"),
        .description = COMPOUND_STRING(
            "Patada giratoria rápida.\n"
        "Puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RollingKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_ATTACK] =
    {
        .name = COMPOUND_STRING("Ataque Arena"),
        .description = COMPOUND_STRING(
            "Arroja arena a la cara y\n"
        "baja la Precisión."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_GROUND : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SAND_ATTACK,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEADBUTT] =
    {
        .name = COMPOUND_STRING("Golpe Cabeza"),
        .description = COMPOUND_STRING(
            "Potente cabezazo que puede\n"
        "amedrentar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_Headbutt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HORN_ATTACK] =
    {
        .name = COMPOUND_STRING("Cornada"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo con una\n"
        "cornada."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_HORN_ATTACK,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_HornAttack,
    },

    [MOVE_FURY_ATTACK] =
    {
        .name = COMPOUND_STRING("Ataque Furia"),
        .description = COMPOUND_STRING(
            "Cornea al objetivo de dos\n"
        "a cinco veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_FuryAttack,
    },

    [MOVE_HORN_DRILL] =
    {
        .name = COMPOUND_STRING("Perforador"),
        .description = COMPOUND_STRING(
            "Ataque con un cuerno\n"
        "giratorio que fulmina de\n"
        "un solo golpe al objetivo"),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK},
        .battleAnimScript = gBattleAnimMove_HornDrill,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TACKLE] =
    {
        .name = COMPOUND_STRING("Placaje"),
        .description = COMPOUND_STRING(
            "Embestida con todo el\n"
        "cuerpo."),
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 50,
        #else
            .power = 35,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Tackle,
    },

    [MOVE_BODY_SLAM] =
    {
        .name = COMPOUND_STRING("Golpe Cuerpo"),
        .description = COMPOUND_STRING(
            "Salta sobre el objetivo\n"
        "con todo su peso y puede\n"
        "llegar a paralizarlo."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodySlam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WRAP] =
    {
        .name = COMPOUND_STRING("Constricción"),
        .description = COMPOUND_STRING(
            "Oprime al objetivo de\n"
        "cuatro a cinco turnos con\n"
        "ramas o con su cuerpo."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wrap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAKE_DOWN] =
    {
        .name = COMPOUND_STRING("Derribo"),
        .description = COMPOUND_STRING(
            "Carga desmedida que\n"
        "también hiere al agresor."),
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_TakeDown,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THRASH] =
    {
        .name = COMPOUND_STRING("Saña"),
        .description = COMPOUND_STRING(
            "Ataque de dos a tres\n"
        "turnos que acaba\n"
        "confundiendo al agresor."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_Thrash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .name = COMPOUND_STRING("Doble Filo"),
        .description = COMPOUND_STRING(
            "Ataque arriesgado que\n"
        "también hiere al agresor."),
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 120 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = B_UPDATED_MOVE_DATA >= GEN_3 ? 33 : 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_DoubleEdge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_WHIP] =
    {
        .name = COMPOUND_STRING("Agitacola"),
        .description = COMPOUND_STRING(
            "Agita la cola para bajar\n"
        "la Defensa del equipo\n"
        "rival."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_TailWhip,
    },

    [MOVE_POISON_STING] =
    {
        .name = COMPOUND_STRING("Picotazo Veneno"),
        .description = COMPOUND_STRING(
            "Lanza un aguijón tóxico\n"
        "que puede envenenar al\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 20,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonSting,
    },

    [MOVE_TWINEEDLE] =
    {
        .name = COMPOUND_STRING("Doble Ataque"),
        .description = COMPOUND_STRING(
            "Aguijonea dos veces seguidas.\n"
        "Puede envenenar al rival."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .strikeCount = 2,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twineedle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PIN_MISSILE] =
    {
        .name = COMPOUND_STRING("Pin Misil"),
        .description = COMPOUND_STRING(
            "Lanza finas púas que\n"
        "hieren de dos a cinco\n"
        "veces."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 14,
        .type = TYPE_BUG,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PinMissile,
    },

    [MOVE_LEER] =
    {
        .name = COMPOUND_STRING("Malicioso"),
        .description = COMPOUND_STRING(
            "Intimida a los rivales\n"
        "para bajar su Defensa."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_LEER,
        .contestComboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Leer,
    },

    [MOVE_BITE] =
    {
        .name = COMPOUND_STRING("Mordisco"),
        .description = COMPOUND_STRING(
            "Un voraz bocado que puede\n"
        "amedrentar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_DARK : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Bite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWL] =
    {
        .name = COMPOUND_STRING("Gruñido"),
        .description = COMPOUND_STRING(
            "Dulce gruñido que reduce\n"
        "el Ataque del equipo\n"
        "rival."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Growl,
    },

    [MOVE_ROAR] =
    {
        .name = COMPOUND_STRING("Rugido"),
        .description = COMPOUND_STRING(
            "Se lleva al objetivo, que\n"
        "es cambiado por otro\n"
        "Pokémon. Si es un Pokémon"),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        #if B_UPDATED_MOVE_DATA >= GEN_3
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .priority = -1,
        #else
            .priority = 0,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .soundMove = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Roar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SING] =
    {
        .name = COMPOUND_STRING("Canto"),
        .description = COMPOUND_STRING(
            "Cancioncilla que hace\n"
        "dormir profundamente al\n"
        "objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SING,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERSONIC] =
    {
        .name = COMPOUND_STRING("Supersónico"),
        .description = COMPOUND_STRING(
            "Raras ondas sónicas que\n"
        "confunden al objetivo."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Supersonic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SONIC_BOOM] =
    {
        .name = COMPOUND_STRING("Bomba Sónica"),
        .description = COMPOUND_STRING(
            "Ondas de choque que causan\n"
        "siempre 20 PS de daño."),
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .fixedDamage = 20 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SonicBoom,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DISABLE] =
    {
        .name = COMPOUND_STRING("Anulación"),
        .description = COMPOUND_STRING(
        #if B_DISABLE_TURNS >= GEN_5
            "For 4 turns, prevents foe\n"
        #elif B_DISABLE_TURNS == GEN_4
            "For 4-7 turns, prevents foe\n"
        #else
            "For 2-5 turns, prevents foe\n"
        #endif
            "from using last used move."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Disable,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ACID] =
    {
        .name = COMPOUND_STRING("Ácido"),
        .description = COMPOUND_STRING(
            "Sprays a hide-melting acid.\n"
        #if B_UPDATED_MOVE_DATA >= GEN_4
            "May lower Sp. Def."),
        #else
            "May lower Defense."),
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_EFFECT_SP_DEF_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acid,
    },

    [MOVE_EMBER] =
    {
        .name = COMPOUND_STRING("Ascuas"),
        .description = COMPOUND_STRING(
            "Ataca con llamas pequeñas\n"
        "que pueden causar\n"
        "quemaduras."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Ember,
    },

    [MOVE_FLAMETHROWER] =
    {
        .name = COMPOUND_STRING("Lanzallamas"),
        .description = COMPOUND_STRING(
            "Ataca con una gran ráfaga\n"
        "de fuego que puede causar\n"
        "quemaduras."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Flamethrower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST] =
    {
        .name = COMPOUND_STRING("Neblina"),
        .description = COMPOUND_STRING(
            "Rodea de fina niebla al\n"
        "usuario y protege las\n"
        "características de su"),
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_GUN] =
    {
        .name = COMPOUND_STRING("Pistola Agua"),
        .description = COMPOUND_STRING(
            "Ataca disparando agua con\n"
        "gran potencia."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_WaterGun,
    },

    [MOVE_HYDRO_PUMP] =
    {
        .name = COMPOUND_STRING("Hidrobomba"),
        .description = COMPOUND_STRING(
            "Lanza una gran masa de\n"
        "agua a presión para\n"
        "atacar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroPump,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SURF] =
    {
        .name = COMPOUND_STRING("Surf"),
        .description = COMPOUND_STRING(
            "Creates a huge wave, then\n"
        #if B_UPDATED_MOVE_DATA >= GEN_4
            "crashes it down on the field."),
        #else
            "crashes it down on the foes."),
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_FOES_AND_ALLY : TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesUnderwater = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SURF,
        .contestComboMoves = {COMBO_STARTER_DIVE, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Surf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Hielo"),
        .description = COMPOUND_STRING(
            "Blasts the foe with an icy\n"
        #if B_USE_FROSTBITE == TRUE
            "beam. May cause frostbite."),
        #else
            "beam that may freeze it."),
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            // The following effect is also relevant in battle_Pike.c
            // If you cherry-pick this to use something other than the config, make sure to update it there too
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLIZZARD] =
    {
        .name = COMPOUND_STRING("Ventisca"),
        .description = COMPOUND_STRING(
            "Hits the foes with an icy\n"
        #if B_USE_FROSTBITE == TRUE
            "storm. May cause frostbite."),
        #else
            "storm that may freeze it."),
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 70 : 90,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInHailSnow = B_BLIZZARD_HAIL >= GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_POWDER_SNOW},
        .battleAnimScript = gBattleAnimMove_Blizzard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYBEAM] =
    {
        .name = COMPOUND_STRING("Psicorrayo"),
        .description = COMPOUND_STRING(
            "Extraño rayo que puede\n"
        "causar confusión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psybeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Burbuja"),
        .description = COMPOUND_STRING(
            "Diluvio de burbujas que\n"
        "puede bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_BubbleBeam,
    },

    [MOVE_AURORA_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Aurora"),
        .description = COMPOUND_STRING(
            "Rayo multicolor que puede\n"
        "reducir el Ataque."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraBeam,
    },

    [MOVE_HYPER_BEAM] =
    {
        .name = COMPOUND_STRING("Hiperrayo"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PECK] =
    {
        .name = COMPOUND_STRING("Picotazo"),
        .description = COMPOUND_STRING(
            "Ensarta al objetivo con un\n"
        "cuerno o pico punzante."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PECK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Peck,
    },

    [MOVE_DRILL_PECK] =
    {
        .name = COMPOUND_STRING("Pico Taladro"),
        .description = COMPOUND_STRING(
            "Picotazo giratorio y\n"
        "perforador muy potente."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_DrillPeck,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBMISSION] =
    {
        .name = COMPOUND_STRING("Sumisión"),
        .description = COMPOUND_STRING(
            "El usuario se lanza al\n"
        "suelo con el oponente en\n"
        "brazos y también se hace"),
        .effect = EFFECT_RECOIL,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = { .recoilPercentage = 25 },
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Submission,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LOW_KICK] =
    {
        .name = COMPOUND_STRING("Patada Baja"),
        #if B_UPDATED_MOVE_DATA >= GEN_3
            .description = COMPOUND_STRING(
                "Patada baja que derriba al\n"
        "oponente. Cuanto más pesa\n"
        "el objetivo, más daño le"),
            .effect = EFFECT_LOW_KICK,
        #else
            .description = COMPOUND_STRING(
                "Patada baja que derriba al\n"
        "oponente. Cuanto más pesa\n"
        "el objetivo, más daño le"),
            .effect = EFFECT_HIT,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .power = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COUNTER] =
    {
        .name = COMPOUND_STRING("Contraataque"),
        .description = COMPOUND_STRING(
            "Devuelve un golpe físico\n"
        "por duplicado."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Counter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .name = COMPOUND_STRING("Sísmico"),
        .description = COMPOUND_STRING(
            "Aprovecha la gravedad para\n"
        "derribar al objetivo. Le\n"
        "resta tantos PS como nivel"),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SeismicToss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRENGTH] =
    {
        .name = COMPOUND_STRING("Fuerza"),
        .description = COMPOUND_STRING(
            "Propina un potente\n"
        "puñetazo con todas sus\n"
        "fuerzas."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Strength,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ABSORB] =
    {
        .name = COMPOUND_STRING("Absorber"),
        .description = COMPOUND_STRING(
            "Un ataque que absorbe\n"
        "nutrientes. Quien lo usa\n"
        "recupera la mitad de los"),
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 25 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Absorb,
    },

    [MOVE_MEGA_DRAIN] =
    {
        .name = COMPOUND_STRING("Megaagotar"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .zMove = { .powerOverride = 120 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MegaDrain,
    },

    [MOVE_LEECH_SEED] =
    {
        .name = COMPOUND_STRING("Drenadoras"),
        .description = COMPOUND_STRING(
            "Planta semillas que\n"
        "absorben PS del objetivo\n"
        "en cada turno y que le"),
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LEECH_SEED,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_WORRY_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_LeechSeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWTH] =
    {
        .name = COMPOUND_STRING("Desarrollo"),
        .description = COMPOUND_STRING(
        #if B_GROWTH_STAT_RAISE >= GEN_5
            "Forces the body to grow,\n"
            "raising Attack and Sp. Atk."),
        #else
            "Forces the body to grow\n"
            "and heightens Sp. Atk."),
        #endif
        .effect = B_GROWTH_STAT_RAISE >= GEN_5 ? EFFECT_GROWTH : EFFECT_SPECIAL_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GROWTH,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Growth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_LEAF] =
    {
        .name = COMPOUND_STRING("Hoja Afilada"),
        .description = COMPOUND_STRING(
            "Corta con hojas afiladas.\n"
        "Un ataque que suele ser\n"
        "crítico."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_RazorLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Solar"),
        .description = COMPOUND_STRING(
            "El usuario absorbe luz en\n"
        "el primer turno y en el\n"
        "segundo lanza un potente"),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_POWDER] =
    {
        .name = COMPOUND_STRING("Polvo Veneno"),
        .description = COMPOUND_STRING(
            "Polvo tóxico que envenena\n"
        "al objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_PoisonPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STUN_SPORE] =
    {
        .name = COMPOUND_STRING("Paralizador"),
        .description = COMPOUND_STRING(
            "Esparce polvo que paraliza\n"
        "al objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_StunSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_POWDER] =
    {
        .name = COMPOUND_STRING("Somnífero"),
        .description = COMPOUND_STRING(
            "Esparce polvo que duerme\n"
        "al objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SLEEP_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_SleepPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PETAL_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Pétalo"),
        .description = COMPOUND_STRING(
            "Lanza pétalos de dos a\n"
        "tres turnos y acaba\n"
        "confundiendo al atacante."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PetalDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRING_SHOT] =
    {
        .name = COMPOUND_STRING("Disparo Demora"),
        .description = COMPOUND_STRING(
            "Lanza seda a los rivales y\n"
        "reduce mucho su Velocidad."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_SPEED_DOWN_2 : EFFECT_SPEED_DOWN,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_STRING_SHOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StringShot,
    },

    [MOVE_DRAGON_RAGE] =
    {
        .name = COMPOUND_STRING("Furia Dragón"),
        .description = COMPOUND_STRING(
            "Ondas de choque que siempre\n"
        "causan 40 PS de daño."),
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .argument = { .fixedDamage = 40 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FIRE_SPIN] =
    {
        .name = COMPOUND_STRING("Giro Fuego"),
        .description = COMPOUND_STRING(
            "Un aro de fuego que atrapa\n"
        "al objetivo de cuatro a\n"
        "cinco turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_FIRE_SPIN,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .name = COMPOUND_STRING("Impactrueno"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico que puede\n"
        "paralizar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderShock,
    },

    [MOVE_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("Rayo"),
        .description = COMPOUND_STRING(
            "Potente ataque eléctrico\n"
        "que puede paralizar al\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Thunderbolt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_WAVE] =
    {
        .name = COMPOUND_STRING("Onda Trueno"),
        .description = COMPOUND_STRING(
            "Una ligera descarga que\n"
        "paraliza al objetivo si lo\n"
        "alcanza."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 90 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_WAVE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER] =
    {
        .name = COMPOUND_STRING("Trueno"),
        .description = COMPOUND_STRING(
            "Un poderoso rayo que daña\n"
        "al objetivo y puede\n"
        "paralizarlo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesAirborne = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Thunder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_THROW] =
    {
        .name = COMPOUND_STRING("Lanzarrocas"),
        .description = COMPOUND_STRING(
            "Tira una pequeña roca al\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 90 : 65,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_THROW,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockThrow,
    },

    [MOVE_EARTHQUAKE] =
    {
        .name = COMPOUND_STRING("Terremoto"),
        .description = COMPOUND_STRING(
            "Un terremoto que afecta a\n"
        "todos los Pokémon que\n"
        "estén a su alrededor."),
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderground = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_EARTHQUAKE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Earthquake,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FISSURE] =
    {
        .name = COMPOUND_STRING("Fisura"),
        .description = COMPOUND_STRING(
            "Abre una grieta en el\n"
        "suelo y mete al objetivo\n"
        "en ella. Fulmina en un"),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE},
        .battleAnimScript = gBattleAnimMove_Fissure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIG] =
    {
        .name = COMPOUND_STRING("Excavar"),
        .description = COMPOUND_STRING(
            "El usuario cava durante el\n"
        "primer turno y ataca en el\n"
        "segundo."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .power = 60,
        #else
            .power = 100,
        #endif
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNDUGHOLE, .status = STATE_UNDERGROUND },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Dig,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TOXIC] =
    {
        .name = COMPOUND_STRING("Tóxico"),
        .description = COMPOUND_STRING(
            "Envenena gravemente al\n"
        "objetivo y causa un daño\n"
        "mayor en cada turno."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_TOXIC },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .alwaysHitsOnSameType = B_TOXIC_NEVER_MISS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Toxic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSION] =
    {
        .name = COMPOUND_STRING("Confusión"),
        .description = COMPOUND_STRING(
            "Débil ataque telequinético\n"
        "que puede causar\n"
        "confusión."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CONFUSION,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Confusion,
    },

    [MOVE_PSYCHIC] =
    {
        .name = COMPOUND_STRING("Psíquico"),
        .description = COMPOUND_STRING(
            "Fuerte ataque\n"
        "telequinético que puede\n"
        "bajar la Defensa Especial"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS},
        .battleAnimScript = gBattleAnimMove_Psychic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPNOSIS] =
    {
        .name = COMPOUND_STRING("Hipnosis"),
        .description = COMPOUND_STRING(
            "Ataque hipnótico que hace\n"
        "dormir profundamente al\n"
        "objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPNOSIS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Hypnosis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEDITATE] =
    {
        .name = COMPOUND_STRING("Meditación"),
        .description = COMPOUND_STRING(
            "Meditación tranquila que\n"
        "aumenta el Ataque."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Meditate,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AGILITY] =
    {
        .name = COMPOUND_STRING("Agilidad"),
        .description = COMPOUND_STRING(
            "Relaja el cuerpo para\n"
        "ganar mucha Velocidad."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_AGILITY,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_Agility,
        .validApprenticeMove = TRUE,
    },

    [MOVE_QUICK_ATTACK] =
    {
        .name = COMPOUND_STRING("Ataque Rápido"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo a gran\n"
        "velocidad. Este movimiento\n"
        "tiene prioridad alta."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_QuickAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAGE] =
    {
        .name = COMPOUND_STRING("Furia"),
        .description = COMPOUND_STRING(
            "Sube el Ataque cada vez\n"
        "que el usuario es golpeado."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAGE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_RAGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rage,
    },

    [MOVE_TELEPORT] =
    {
        .name = COMPOUND_STRING("Teletransporte"),
        #if B_TELEPORT_BEHAVIOR >= GEN_8
        .description = COMPOUND_STRING(
            "Permite al usuario\n"
        "cambiarse por otro Pokémon\n"
        "del equipo, si es posible."),
        #else
        .description = COMPOUND_STRING(
            "Permite al usuario\n"
        "cambiarse por otro Pokémon\n"
        "del equipo, si es posible."),
        #endif
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_8 ? -6 : 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Teleport,
    },

    [MOVE_NIGHT_SHADE] =
    {
        .name = COMPOUND_STRING("Tinieblas"),
        .description = COMPOUND_STRING(
            "Produce un espejismo ante\n"
        "el objetivo, que pierde\n"
        "tantos PS como nivel tenga"),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightShade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIMIC] =
    {
        .name = COMPOUND_STRING("Mimético"),
        .description = COMPOUND_STRING(
            "Copia el último movimiento\n"
        "usado por el objetivo, y\n"
        "puede utilizarlo mientras"),
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresSubstitute = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mimic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCREECH] =
    {
        .name = COMPOUND_STRING("Chirrido"),
        .description = COMPOUND_STRING(
            "Alarido agudo que reduce\n"
        "mucho la Defensa del\n"
        "objetivo."),
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Screech,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .name = COMPOUND_STRING("Doble Equipo"),
        .description = COMPOUND_STRING(
            "Crea copias de sí mismo\n"
        "para mejorar la Evasión."),
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleTeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECOVER] =
    {
        .name = COMPOUND_STRING("Recuperación"),
        .description = COMPOUND_STRING(
            "Restaura hasta la mitad de\n"
        "los PS máximos."),
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recover,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HARDEN] =
    {
        .name = COMPOUND_STRING("Fortaleza"),
        .description = COMPOUND_STRING(
            "Tensa la musculatura del\n"
        "usuario para aumentar la\n"
        "Defensa."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HARDEN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Harden,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MINIMIZE] =
    {
        .name = COMPOUND_STRING("Reducción"),
        .description = COMPOUND_STRING(
            "Minimizes the user's size to\n"
        #if B_MINIMIZE_EVASION >= GEN_5
            "sharply raise evasiveness."),
        #else
            "raise evasiveness."),
        #endif
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Minimize,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOKESCREEN] =
    {
        .name = COMPOUND_STRING("Pantalla de Humo"),
        .description = COMPOUND_STRING(
            "Baja la Precisión del\n"
        "objetivo con una nube de\n"
        "humo o tinta."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SMOG},
        .battleAnimScript = gBattleAnimMove_Smokescreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSE_RAY] =
    {
        .name = COMPOUND_STRING("Rayo Confuso"),
        .description = COMPOUND_STRING(
            "Rayo siniestro que\n"
        "confunde al objetivo."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ConfuseRay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WITHDRAW] =
    {
        .name = COMPOUND_STRING("Refugio"),
        .description = COMPOUND_STRING(
            "El usuario se resguarda en\n"
        "su coraza, por lo que le\n"
        "sube la Defensa."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Withdraw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DEFENSE_CURL] =
    {
        .name = COMPOUND_STRING("Rizo Defensa"),
        .description = COMPOUND_STRING(
            "Se enrosca para ocultar\n"
        "sus puntos débiles y\n"
        "aumentar la Defensa."),
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DefenseCurl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BARRIER] =
    {
        .name = COMPOUND_STRING("Barrera"),
        .description = COMPOUND_STRING(
            "Crea una barrera que sube\n"
        "mucho la Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrier,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .name = COMPOUND_STRING("Pantalla de Luz"),
        .description = COMPOUND_STRING(
            "Pared de luz que reduce\n"
        "durante cinco turnos el\n"
        "daño producido por los"),
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LightScreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAZE] =
    {
        .name = COMPOUND_STRING("Niebla"),
        .description = COMPOUND_STRING(
            "Neblina que elimina los\n"
        "cambios de características\n"
        "de todos los Pokémon en"),
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Haze,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFLECT] =
    {
        .name = COMPOUND_STRING("Reflejo"),
        .description = COMPOUND_STRING(
            "Pared de luz que reduce\n"
        "durante cinco turnos el\n"
        "daño producido por los"),
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Reflect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .name = COMPOUND_STRING("Foco Energía"),
        .description = COMPOUND_STRING(
            "Concentra energía para\n"
        "aumentar las posibilidades\n"
        "de asestar un golpe"),
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .argument = { .status = VOLATILE_FOCUS_ENERGY },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FocusEnergy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIDE] =
    {
        .name = COMPOUND_STRING("Venganza"),
        .description = COMPOUND_STRING(
            "Aguanta 2 turnos y devuelve\n"
        "el doble del daño recibido."),
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .accuracy = 100,
            .priority = 0,
        #else
            .accuracy = 0,
            .priority = 0,
        #endif
        .pp = 10,
        .target = TARGET_USER,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bide,
    },

    [MOVE_METRONOME] =
    {
        .name = COMPOUND_STRING("Metrónomo"),
        .description = COMPOUND_STRING(
            "Mueve un dedo y estimula\n"
        "su cerebro para usar al\n"
        "azar casi cualquier"),
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Metronome,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_MOVE] =
    {
        .name = COMPOUND_STRING("Espejo"),
        .description = COMPOUND_STRING(
            "Devuelve al rival el último\n"
        "movimiento que usó."),
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorMove,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .name = COMPOUND_STRING("Autodestrucción"),
        .description = COMPOUND_STRING(
            "El atacante explota y\n"
        "hiere a todos a su\n"
        "alrededor. El usuario se"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 200 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_SelfDestruct,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EGG_BOMB] =
    {
        .name = COMPOUND_STRING("Bomba Huevo"),
        .description = COMPOUND_STRING(
            "Lanza un huevo con fuerza\n"
        "contra el objetivo."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SOFT_BOILED},
        .battleAnimScript = gBattleAnimMove_EggBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LICK] =
    {
        .name = COMPOUND_STRING("Lengüetazo"),
        .description = COMPOUND_STRING(
            "Una lengua ataca al\n"
        "objetivo. Puede causar\n"
        "parálisis."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOG] =
    {
        .name = COMPOUND_STRING("Polución"),
        .description = COMPOUND_STRING(
            "Lanza un ataque con gases\n"
        "tóxicos que pueden llegar\n"
        "a envenenar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SMOG,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Smog,
    },

    [MOVE_SLUDGE] =
    {
        .name = COMPOUND_STRING("Residuos"),
        .description = COMPOUND_STRING(
            "Arroja residuos al\n"
        "objetivo. Puede llegar a\n"
        "envenenar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE,
        .contestComboMoves = {COMBO_STARTER_SLUDGE_BOMB},
        .battleAnimScript = gBattleAnimMove_Sludge,
    },

    [MOVE_BONE_CLUB] =
    {
        .name = COMPOUND_STRING("Hueso Palo"),
        .description = COMPOUND_STRING(
            "Golpea con un hueso.\n"
        "Puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_CLUB,
        .contestComboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneClub,
    },

    [MOVE_FIRE_BLAST] =
    {
        .name = COMPOUND_STRING("Llamarada"),
        .description = COMPOUND_STRING(
            "Llama intensa que chamusca\n"
        "y puede causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireBlast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATERFALL] =
    {
        .name = COMPOUND_STRING("Cascada"),
        .description = COMPOUND_STRING(
            "Embiste con un gran\n"
        "impulso que puede llegar a\n"
        "amedrentar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Waterfall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CLAMP] =
    {
        .name = COMPOUND_STRING("Tenaza"),
        .description = COMPOUND_STRING(
            "Agarra al rival con sus conchillas\n"
        "durante varios turnos."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_CLAMP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Clamp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWIFT] =
    {
        .name = COMPOUND_STRING("Meteoros"),
        .description = COMPOUND_STRING(
            "Lanza rayos en forma de\n"
        "estrella que no fallan\n"
        "nunca."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swift,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKULL_BASH] =
    {
        .name = COMPOUND_STRING("Cabezazo"),
        .description = COMPOUND_STRING(
            "El usuario se prepara y\n"
        "sube su Defensa en el\n"
        "primer turno y en el"),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNLOWEREDHEAD },
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
                .self = TRUE,
                .onChargeTurnOnly = TRUE,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkullBash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKE_CANNON] =
    {
        .name = COMPOUND_STRING("Clavo Cañón"),
        .description = COMPOUND_STRING(
            "Dispara púas afiladas que\n"
        "golpean de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikeCannon,
    },

    [MOVE_CONSTRICT] =
    {
        .name = COMPOUND_STRING("Restricción"),
        .description = COMPOUND_STRING(
            "Estruja al rival causando\n"
        "daño. Puede bajar Velocidad."),
        .effect = EFFECT_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Constrict,
    },

    [MOVE_AMNESIA] =
    {
        .name = COMPOUND_STRING("Amnesia"),
        .description = COMPOUND_STRING(
            "El usuario olvida sus\n"
        "preocupaciones y aumenta\n"
        "mucho la Defensa Especial."),
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_AMNESIA,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Amnesia,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KINESIS] =
    {
        .name = COMPOUND_STRING("Kinético"),
        .description = COMPOUND_STRING(
            "Dobla una cuchara para\n"
        "distraer al objetivo y\n"
        "bajar su nivel de"),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_KINESIS,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Kinesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOFT_BOILED] =
    {
        .name = COMPOUND_STRING("Ovocuración"),
        .description = COMPOUND_STRING(
            "Restaura la mitad de los\n"
        "PS máximos del usuario."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SOFT_BOILED,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SoftBoiled,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
        .name = COMPOUND_STRING("Patada Salto Alta"),
        .description = COMPOUND_STRING(
            "El usuario salta muy alto\n"
        "y da un rodillazo. Si\n"
        "falla, se hará daño."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
        #else
            .power = 85,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_HighJumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GLARE] =
    {
        .name = COMPOUND_STRING("Deslumbrar"),
        .description = COMPOUND_STRING(
            "Intimida y asusta al\n"
        "objetivo con la mirada\n"
        "para dejarlo paralizado."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_GLARE,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Glare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DREAM_EATER] =
    {
        .name = COMPOUND_STRING("Comesueños"),
        .description = COMPOUND_STRING(
            "Restaura al usuario la\n"
        "mitad del daño causado a\n"
        "un objetivo dormido."),
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_DreamEater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_GAS] =
    {
        .name = COMPOUND_STRING("Gas Venenoso"),
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_5
            "Envelops the foes in a toxic\n"
        #else
            "Envelops the foe in a toxic\n"
        #endif
            "gas that may poison."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 90,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_GAS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonGas,
    },

    [MOVE_BARRAGE] =
    {
        .name = COMPOUND_STRING("Bombardeo"),
        .description = COMPOUND_STRING(
            "Lanza objetos redondos al\n"
        "rival de 2 a 5 veces."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrage,
    },

    [MOVE_LEECH_LIFE] =
    {
        .name = COMPOUND_STRING("Chupavidas"),
        .description = COMPOUND_STRING(
            "Restaura al usuario la\n"
        "mitad del daño causado al\n"
        "objetivo."),
        .effect = EFFECT_ABSORB,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeechLife,
    },

    [MOVE_LOVELY_KISS] =
    {
        .name = COMPOUND_STRING("Beso Amoroso"),
        .description = COMPOUND_STRING(
            "Intimida al objetivo con\n"
        "una cara que asusta y le\n"
        "da un beso que lo deja"),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_LOVELY_KISS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LovelyKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_ATTACK] =
    {
        .name = COMPOUND_STRING("Ataque Aéreo"),
        .description = COMPOUND_STRING(
            "Ataca durante dos turnos y\n"
        "suele asestar un golpe\n"
        "crítico. También puede"),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = B_UPDATED_MOVE_DATA >= GEN_4 ? STRINGID_CLOAKEDINAHARSHLIGHT : STRINGID_PKMNISGLOWING },
    #if B_UPDATED_MOVE_DATA >= GEN_3
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
    #endif
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkyAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRANSFORM] =
    {
        .name = COMPOUND_STRING("Transformación"),
        .description = COMPOUND_STRING(
            "El usuario se transforma\n"
        "en una copia del objetivo,\n"
        "con los mismos"),
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Transform,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE] =
    {
        .name = COMPOUND_STRING("Burbuja"),
        .description = COMPOUND_STRING(
            "Ataque con burbujas que\n"
        "puede bajar la Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 40 : 20,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Bubble,
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Mareo"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Puñetazo rítmico que puede\n"
        "confundir al objetivo."),
        #else
            .description = COMPOUND_STRING(
                "Puñetazo rítmico que puede\n"
        "confundir al objetivo."),
        #endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_CONFUSION,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DizzyPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPORE] =
    {
        .name = COMPOUND_STRING("Espora"),
        .description = COMPOUND_STRING(
            "Esparce esporas que\n"
        "inducen al sueño."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SPORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLASH] =
    {
        .name = COMPOUND_STRING("Destello"),
        .description = COMPOUND_STRING(
            "Destello cegador que baja\n"
        "la Precisión del rival."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Flash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYWAVE] =
    {
        .name = COMPOUND_STRING("Psicoonda"),
        .description = COMPOUND_STRING(
            "Ataque psíquico de\n"
        "intensidad variable."),
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psywave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPLASH] =
    {
        .name = COMPOUND_STRING("Salpicadura"),
        .description = COMPOUND_STRING(
            "No tiene ningún efecto.\n"
        "Solo salpica."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_3 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Splash,
    },

    [MOVE_ACID_ARMOR] =
    {
        .name = COMPOUND_STRING("Armadura Ácida"),
        .description = COMPOUND_STRING(
            "Transforma la estructura\n"
        "celular para hacerse\n"
        "líquido y aumenta mucho la"),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidArmor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRABHAMMER] =
    {
        .name = COMPOUND_STRING("Martillazo"),
        .description = COMPOUND_STRING(
            "Golpea con fuerza con una\n"
        "pinza enorme. Suele\n"
        "asestar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Crabhammer,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXPLOSION] =
    {
        .name = COMPOUND_STRING("Explosión"),
        .description = COMPOUND_STRING(
            "El atacante causa una\n"
        "grandísima explosión y\n"
        "hiere a todos a su"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 250 : 170,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Explosion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FURY_SWIPES] =
    {
        .name = COMPOUND_STRING("Golpes Furia"),
        .description = COMPOUND_STRING(
            "Araña rápidamente de dos a\n"
        "cinco veces."),
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH},
        .battleAnimScript = gBattleAnimMove_FurySwipes,
    },

    [MOVE_BONEMERANG] =
    {
        .name = COMPOUND_STRING("Huesomerang"),
        .description = COMPOUND_STRING(
            "Lanza un hueso a modo de\n"
        "bumerán que golpea dos\n"
        "veces."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONEMERANG,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_Bonemerang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REST] =
    {
        .name = COMPOUND_STRING("Descanso"),
        .description = COMPOUND_STRING(
            "Restaura todos los PS y\n"
        "cura todos los problemas\n"
        "de estado del usuario, que"),
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_REST,
        .contestComboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
        .battleAnimScript = gBattleAnimMove_Rest,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SLIDE] =
    {
        .name = COMPOUND_STRING("Avalancha"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Lanza grandes pedruscos.\n"
        "Puede amedrentar al\n"
        "objetivo."),
        #else
            .description = COMPOUND_STRING(
                "Lanza grandes pedruscos.\n"
        "Puede amedrentar al\n"
        "objetivo."),
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockSlide,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_FANG] =
    {
        .name = COMPOUND_STRING("Hipercolmillo"),
        .description = COMPOUND_STRING(
            "Ataca con agudos\n"
        "colmillos. Puede\n"
        "amedrentar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHARPEN] =
    {
        .name = COMPOUND_STRING("Afilar"),
        .description = COMPOUND_STRING(
            "Afila el cuerpo para subir\n"
        "el Ataque propio."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sharpen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION] =
    {
        .name = COMPOUND_STRING("Conversión"),
        .description = COMPOUND_STRING(
            "Changes the user's type\n"
        #if B_UPDATED_CONVERSION >= GEN_6
            "into first known move's type."),
        #else
            "into a known move's type."),
        #endif
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRI_ATTACK] =
    {
        .name = COMPOUND_STRING("Triataque"),
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .description = COMPOUND_STRING(
                "Fires three types of beams.\n"
                #if B_USE_FROSTBITE == TRUE
                    "May burn/para/frostbite."),
                #else
                    "May burn/paralyze/freeze."),
                #endif
        #else
            .description = COMPOUND_STRING(
                "A triangular field of energy\n"
                "is created and launched."),
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_TRI_ATTACK,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_TriAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPER_FANG] =
    {
        .name = COMPOUND_STRING("Superdiente"),
        .description = COMPOUND_STRING(
            "Finos colmillos que\n"
        "reducen a la mitad los PS\n"
        "del objetivo."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .damagePercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_SuperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLASH] =
    {
        .name = COMPOUND_STRING("Cuchillada"),
        .description = COMPOUND_STRING(
            "Ataca con cuchillas o con\n"
        "pinzas. Suele asestar un\n"
        "golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Slash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBSTITUTE] =
    {
        .name = COMPOUND_STRING("Sustituto"),
        .description = COMPOUND_STRING(
            "Utiliza parte de los PS\n"
        "propios para crear un\n"
        "sustituto que actúa como"),
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Substitute,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRUGGLE] =
    {
        .name = COMPOUND_STRING("Forcejeo"),
        .description = COMPOUND_STRING(
            "Solo se usa como último\n"
        "recurso al acabarse los\n"
        "PP. Hiere un poco al"),
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_STRUGGLE,
            .accuracy = 0,
            .pp = 1,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_RECOIL_HP_25,
                .self = TRUE,
            }),
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 1,
            .argument = { .recoilPercentage = 25 },
        #else
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 10,
            .argument = { .recoilPercentage = 50 },
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .battleAnimScript = gBattleAnimMove_Struggle,
        .validApprenticeMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_TOUGH,
    },

    [MOVE_SKETCH] =
    {
        .name = COMPOUND_STRING("Esquema"),
        .description = COMPOUND_STRING(
            "Aprende de forma\n"
        "permanente el último\n"
        "movimiento utilizado por"),
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sketch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRIPLE_KICK] =
    {
        .name = COMPOUND_STRING("Triple Patada"),
        .description = COMPOUND_STRING(
            "Patea hasta tres veces\n"
        "seguidas y cada vez más\n"
        "fuerte."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_TripleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THIEF] =
    {
        .name = COMPOUND_STRING("Ladrón"),
        .description = COMPOUND_STRING(
            "El agresor ataca y le\n"
        "quita el objeto al\n"
        "objetivo siempre y cuando"),
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thief,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIDER_WEB] =
    {
        .name = COMPOUND_STRING("Telaraña"),
        .description = COMPOUND_STRING(
            "Red que atrapa al rival,\n"
        "impidiéndole huir o cambiar."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_SpiderWeb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIND_READER] =
    {
        .name = COMPOUND_STRING("Telépata"),
        .description = COMPOUND_STRING(
            "El usuario adivina los\n"
        "movimientos del objetivo\n"
        "para hacer que su"),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_MIND_READER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindReader,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("Pesadilla"),
        .description = COMPOUND_STRING(
            "El rival dormido pierde\n"
        "1/4 de PS cada turno."),
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_Nightmare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .name = COMPOUND_STRING("Rueda Fuego"),
        .description = COMPOUND_STRING(
            "Ataca envuelto en fuego.\n"
        "Puede causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlameWheel,
    },

    [MOVE_SNORE] =
    {
        .name = COMPOUND_STRING("Ronquido"),
        .description = COMPOUND_STRING(
            "Fuerte ronquido que solo\n"
        "puede usarse dormido.\n"
        "Puede amedrentar al"),
        .effect = EFFECT_SNORE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_Snore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CURSE] =
    {
        .name = COMPOUND_STRING("Maldición"),
        .description = COMPOUND_STRING(
            "Un movimiento que tiene\n"
        "efectos distintos si el\n"
        "usuario es de tipo"),
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_5 ? TYPE_GHOST : TYPE_MYSTERY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_CURSE },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_CURSE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Curse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAIL] =
    {
        .name = COMPOUND_STRING("Azote"),
        .description = COMPOUND_STRING(
            "Ataque frenético. Cuantos\n"
        "menos PS tenga el usuario,\n"
        "más daño producirá."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Flail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION_2] =
    {
        .name = COMPOUND_STRING("Conversión 2"),
        .description = COMPOUND_STRING(
            "El usuario cambia de tipo\n"
        "para hacerse resistente al\n"
        "último tipo de movimiento"),
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_SELECTED : TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion2,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AEROBLAST] =
    {
        .name = COMPOUND_STRING("Aerochorro"),
        .description = COMPOUND_STRING(
            "Lanza un chorro de aire\n"
        "que suele asestar un golpe\n"
        "crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aeroblast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COTTON_SPORE] =
    {
        .name = COMPOUND_STRING("Esporagodón"),
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_6
            "Spores cling to the foes,\n"
        #else
            "Spores cling to the foe,\n"
        #endif
            "sharply reducing Speed."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_6 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVERSAL] =
    {
        .name = COMPOUND_STRING("Inversión"),
        .description = COMPOUND_STRING(
            "Ataque desesperado que\n"
        "causa más daño cuantos\n"
        "menos PS tenga el usuario."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Reversal,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPITE] =
    {
        .name = COMPOUND_STRING("Rencor"),
        .description = COMPOUND_STRING(
            "Spitefully cuts the PP\n"
        #if B_PP_REDUCED_BY_SPITE >= GEN_4
            "of the foe's last move by 4."),
        #else
            "of foe's last move by 2-5."),
        #endif
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Spite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POWDER_SNOW] =
    {
        .name = COMPOUND_STRING("Nieve Polvo"),
        .description = COMPOUND_STRING(
            "Blasts the foes with a snowy\n"
        #if B_USE_FROSTBITE == TRUE
            "gust. May cause frostbite."),
        #else
            "gust. May cause freezing."),
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_POWDER_SNOW,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_PowderSnow,
    },

    [MOVE_PROTECT] =
    {
        .name = COMPOUND_STRING("Protección"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Protect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MACH_PUNCH] =
    {
        .name = COMPOUND_STRING("Ultrapuño"),
        .description = COMPOUND_STRING(
            "Puñetazo de velocidad\n"
        "fulminante. Este\n"
        "movimiento tiene prioridad"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MachPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCARY_FACE] =
    {
        .name = COMPOUND_STRING("Cara Susto"),
        .description = COMPOUND_STRING(
            "Asusta al objetivo para\n"
        "reducir mucho su\n"
        "Velocidad."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCARY_FACE,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_ScaryFace,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEINT_ATTACK] =
    {
        .name = COMPOUND_STRING("Finta"),
        .description = COMPOUND_STRING(
            "Se acerca al rival y golpea\n"
        "sin que pueda esquivar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_FeintAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_KISS] =
    {
        .name = COMPOUND_STRING("Beso Dulce"),
        .description = COMPOUND_STRING(
            "Da un beso con tal dulzura\n"
        "que causa confusión."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_SweetKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BELLY_DRUM] =
    {
        .name = COMPOUND_STRING("Tambor"),
        .description = COMPOUND_STRING(
            "Reduce la mitad de los PS\n"
        "máximos para mejorar al\n"
        "máximo el Ataque."),
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BELLY_DRUM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BellyDrum,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .name = COMPOUND_STRING("Bomba Lodo"),
        .description = COMPOUND_STRING(
            "Arroja residuos al\n"
        "objetivo. Puede llegar a\n"
        "envenenar."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .contestComboMoves = {COMBO_STARTER_SLUDGE},
        .battleAnimScript = gBattleAnimMove_SludgeBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SLAP] =
    {
        .name = COMPOUND_STRING("Bofetón Lodo"),
        .description = COMPOUND_STRING(
            "Echa lodo en la cara para\n"
        "bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SLAP,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OCTAZOOKA] =
    {
        .name = COMPOUND_STRING("Pulpocañón"),
        .description = COMPOUND_STRING(
            "Dispara tinta a la cara.\n"
        "Puede bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Octazooka,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKES] =
    {
        .name = COMPOUND_STRING("Púas"),
        .description = COMPOUND_STRING(
            "Esparce púas alrededor del\n"
        "equipo rival que hieren a\n"
        "los Pokémon rivales que"),
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spikes,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ZAP_CANNON] =
    {
        .name = COMPOUND_STRING("Electrocañón"),
        .description = COMPOUND_STRING(
            "Dispara una descarga\n"
        "eléctrica que causa daño y\n"
        "parálisis."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_ZapCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FORESIGHT] =
    {
        .name = COMPOUND_STRING("Profecía"),
        .description = COMPOUND_STRING(
            "Anula los esfuerzos del rival\n"
        "por subir su Evasión."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Foresight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DESTINY_BOND] =
    {
        .name = COMPOUND_STRING("Mismo Destino"),
        .description = COMPOUND_STRING(
            "Si el usuario se debilita\n"
        "por un ataque rival antes\n"
        "de usar otro movimiento,"),
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_DestinyBond,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PERISH_SONG] =
    {
        .name = COMPOUND_STRING("Canto Mortal"),
        .description = COMPOUND_STRING(
            "Si un Pokémon escucha este\n"
        "canto y no es cambiado por\n"
        "otro en tres turnos, acaba"),
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_PerishSong,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICY_WIND] =
    {
        .name = COMPOUND_STRING("Viento Hielo"),
        .description = COMPOUND_STRING(
            "Ataque con aire helado que\n"
        "baja la Velocidad de los\n"
        "rivales."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcyWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DETECT] =
    {
        .name = COMPOUND_STRING("Detección"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
        .battleAnimScript = gBattleAnimMove_Detect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BONE_RUSH] =
    {
        .name = COMPOUND_STRING("Ataque Óseo"),
        .description = COMPOUND_STRING(
            "Hueso en ristre, aporrea\n"
        "al objetivo de dos a cinco\n"
        "veces."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_RUSH,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneRush,
    },

    [MOVE_LOCK_ON] =
    {
        .name = COMPOUND_STRING("Fijar Blanco"),
        .description = COMPOUND_STRING(
            "Fija el blanco para que el\n"
        "siguiente ataque no falle."),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LOCK_ON,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LockOn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OUTRAGE] =
    {
        .name = COMPOUND_STRING("Enfado"),
        .description = COMPOUND_STRING(
            "Ataca de dos a tres turnos\n"
        "y acaba confundiendo al\n"
        "agresor."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Outrage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SANDSTORM] =
    {
        .name = COMPOUND_STRING("Tormenta de Arena"),
        .description = COMPOUND_STRING(
            "Tormenta de arena que dura\n"
        "cinco turnos y hiere a\n"
        "todos, excepto a los de"),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .windMove = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SANDSTORM },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SANDSTORM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sandstorm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GIGA_DRAIN] =
    {
        .name = COMPOUND_STRING("Gigadrenado"),
        .description = COMPOUND_STRING(
            "Un ataque que absorbe\n"
        "nutrientes. Quien lo usa\n"
        "recupera la mitad de los"),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_GigaDrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDURE] =
    {
        .name = COMPOUND_STRING("Aguante"),
        .description = COMPOUND_STRING(
            "Resiste cualquier ataque y\n"
        "deja al menos 1 PS. Puede\n"
        "fallar si se usa"),
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NONE },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ENDURE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Endure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARM] =
    {
        .name = COMPOUND_STRING("Encanto"),
        .description = COMPOUND_STRING(
            "Engatusa al objetivo y\n"
        "reduce mucho su Ataque."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CHARM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLOUT] =
    {
        .name = COMPOUND_STRING("Rodar"),
        .description = COMPOUND_STRING(
            "El atacante rueda contra\n"
        "el objetivo durante cinco\n"
        "turnos, cada vez con mayor"),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Rollout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FALSE_SWIPE] =
    {
        .name = COMPOUND_STRING("Falso Tortazo"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FalseSwipe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWAGGER] =
    {
        .name = COMPOUND_STRING("Fanfarronear"),
        .description = COMPOUND_STRING(
            "Provoca confusión en el\n"
        "objetivo, pero también\n"
        "sube mucho su Ataque."),
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 85 : 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        //.ignoresSubstitute = TRUE, In Gen4+, the attack raise will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swagger,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MILK_DRINK] =
    {
        .name = COMPOUND_STRING("Batido"),
        .description = COMPOUND_STRING(
            "Restaura la mitad de los\n"
        "PS máximos del usuario."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MilkDrink,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPARK] =
    {
        .name = COMPOUND_STRING("Chispa"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico que puede\n"
        "llegar a paralizar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Spark,
    },

    [MOVE_FURY_CUTTER] =
    {
        .name = COMPOUND_STRING("Corte Furia"),
        .description = COMPOUND_STRING(
            "Ataque con garras o\n"
        "guadaña que crece en\n"
        "intensidad si se usa"),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FuryCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STEEL_WING] =
    {
        .name = COMPOUND_STRING("Ala de Acero"),
        .description = COMPOUND_STRING(
            "Alas macizas que golpean\n"
        "al objetivo y pueden subir\n"
        "la Defensa del usuario."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelWing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEAN_LOOK] =
    {
        .name = COMPOUND_STRING("Mal de Ojo"),
        .description = COMPOUND_STRING(
            "Mal de ojo que impide al\n"
        "objetivo huir del combate."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MEAN_LOOK,
        .contestComboMoves = {COMBO_STARTER_CURSE},
        .battleAnimScript = gBattleAnimMove_MeanLook,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ATTRACT] =
    {
        .name = COMPOUND_STRING("Atracción"),
        .description = COMPOUND_STRING(
            "Si el objetivo es del sexo\n"
        "opuesto, se enamorará y\n"
        "bajará la posibilidad de"),
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Attract,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_TALK] =
    {
        .name = COMPOUND_STRING("Sonámbulo"),
        .description = COMPOUND_STRING(
            "Mientras duerme, usa uno\n"
        "de sus movimientos elegido\n"
        "al azar."),
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_SleepTalk,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAL_BELL] =
    {
        .name = COMPOUND_STRING("Cascabel Cura"),
        .description = COMPOUND_STRING(
            "Tañido que cura los\n"
        "problemas de estado de\n"
        "todos los Pokémon del"),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HEAL_BELL,
        .contestComboMoves = {COMBO_STARTER_LUCKY_CHANT},
        .battleAnimScript = gBattleAnimMove_HealBell,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RETURN] =
    {
        .name = COMPOUND_STRING("Retribución"),
        .description = COMPOUND_STRING(
            "Ataque más poderoso cuanto\n"
        "más se quiera al usuario."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Return,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PRESENT] =
    {
        .name = COMPOUND_STRING("Presente"),
        .description = COMPOUND_STRING(
            "Quien lo usa ataca al\n"
        "objetivo dándole un regalo\n"
        "con una bomba trampa. Sin"),
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Present,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRUSTRATION] =
    {
        .name = COMPOUND_STRING("Frustración"),
        .description = COMPOUND_STRING(
            "Ataque más potente cuanto\n"
        "menos quiera al Entrenador."),
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Frustration,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAFEGUARD] =
    {
        .name = COMPOUND_STRING("Velo Sagrado"),
        .description = COMPOUND_STRING(
            "Un escudo que protege de\n"
        "problemas de estado, como\n"
        "el sueño o la parálisis,"),
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Safeguard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAIN_SPLIT] =
    {
        .name = COMPOUND_STRING("Divide Dolor"),
        .description = COMPOUND_STRING(
            "Suma los PS del usuario a\n"
        "los del objetivo y los\n"
        "reparte a partes iguales."),
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_PainSplit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SACRED_FIRE] =
    {
        .name = COMPOUND_STRING("Fuego Sagrado"),
        .description = COMPOUND_STRING(
            "Fuego místico de gran\n"
        "intensidad que puede\n"
        "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SacredFire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGNITUDE] =
    {
        .name = COMPOUND_STRING("Magnitud"),
        .description = COMPOUND_STRING(
            "Terremoto de intensidad\n"
        "aleatoria que afecta a todos."),
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Magnitude,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Dinámico"),
        .description = COMPOUND_STRING(
            "Puñetazo con toda la\n"
        "fuerza concentrada. Causa\n"
        "confusión si atina."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_DynamicPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGAHORN] =
    {
        .name = COMPOUND_STRING("Megacuerno"),
        .description = COMPOUND_STRING(
            "Violenta embestida con\n"
        "cuernos imponentes."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Megahorn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_BREATH] =
    {
        .name = COMPOUND_STRING("Dragoaliento"),
        .description = COMPOUND_STRING(
            "Poderosa ráfaga de aliento\n"
        "que golpea al objetivo y\n"
        "puede paralizarlo."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonBreath,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BATON_PASS] =
    {
        .name = COMPOUND_STRING("Relevo"),
        .description = COMPOUND_STRING(
            "Cambia el puesto con otro\n"
        "miembro del equipo y le\n"
        "pasa los cambios de"),
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_BatonPass,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENCORE] =
    {
        .name = COMPOUND_STRING("Otra Vez"),
        .description = COMPOUND_STRING(
            "El objetivo repite su\n"
        "último movimiento durante\n"
        "tres turnos."),
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .encoreBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENCORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Encore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PURSUIT] =
    {
        .name = COMPOUND_STRING("Persecución"),
        .description = COMPOUND_STRING(
            "Inflige más daño si el rival\n"
        "estaba cambiando de Pokémon."),
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pursuit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAPID_SPIN] =
    {
        .name = COMPOUND_STRING("Giro Rápido"),
        .description = COMPOUND_STRING(
            "User spins and removes some\n"
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
            "effects, while upping speed."),
        #else
            "effects."),
        #endif
        .effect = EFFECT_RAPID_SPIN,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 50 : 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RapidSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_SCENT] =
    {
        .name = COMPOUND_STRING("Dulce Aroma"),
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_6
            "Allures the foes to harshly\n"
            "reduce evasiveness."),
        #else
            "Allures the foes to reduce\n"
            "evasiveness."),
        #endif
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SWEET_SCENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SweetScent,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IRON_TAIL] =
    {
        .name = COMPOUND_STRING("Cola Férrea"),
        .description = COMPOUND_STRING(
            "Ataca con una cola férrea\n"
        "y puede bajar la Defensa\n"
        "del objetivo."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_CLAW] =
    {
        .name = COMPOUND_STRING("Garra Metal"),
        .description = COMPOUND_STRING(
            "Ataque con garras de acero\n"
        "que puede aumentar el\n"
        "Ataque del usuario."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND},
        .battleAnimScript = gBattleAnimMove_MetalClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VITAL_THROW] =
    {
        .name = COMPOUND_STRING("Llave Vital"),
        .description = COMPOUND_STRING(
            "El usuario ataca el\n"
        "último, pero no falla."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_VitalThrow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MORNING_SUN] =
    {
        .name = COMPOUND_STRING("Sol Matinal"),
        .description = COMPOUND_STRING(
            "Restaura PS del usuario.\n"
        "La cantidad varía según el\n"
        "tiempo que haga."),
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MorningSun,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SYNTHESIS] =
    {
        .name = COMPOUND_STRING("Fotosíntesis"),
        .description = COMPOUND_STRING(
            "Restaura PS del usuario.\n"
        "La cantidad varía según el\n"
        "tiempo que haga."),
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Synthesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MOONLIGHT] =
    {
        .name = COMPOUND_STRING("Luz Lunar"),
        .description = COMPOUND_STRING(
            "Restaura PS del usuario.\n"
        "La cantidad varía según el\n"
        "tiempo que haga."),
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Moonlight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIDDEN_POWER] =
    {
        .name = COMPOUND_STRING("Poder Oculto"),
        .description = COMPOUND_STRING(
        #if B_HIDDEN_POWER_DMG >= GEN_6
            "The type varies\n"
            "with the user."),
        #else
            "The type and effectiveness\n"
            "vary with the user."),
        #endif
        .power = B_HIDDEN_POWER_DMG >= GEN_6 ? 60 : 1,
        .effect = EFFECT_HIDDEN_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HiddenPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CROSS_CHOP] =
    {
        .name = COMPOUND_STRING("Tajo Cruzado"),
        .description = COMPOUND_STRING(
            "Corte doble que suele\n"
        "propinar un golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_CrossChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TWISTER] =
    {
        .name = COMPOUND_STRING("Ciclón"),
        .description = COMPOUND_STRING(
            "Crea un violento tornado\n"
        "para hacer trizas al\n"
        "objetivo. Puede"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesAirborneDoubleDamage = TRUE,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twister,
    },

    [MOVE_RAIN_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Lluvia"),
        .description = COMPOUND_STRING(
            "Genera una fuerte lluvia\n"
        "que refuerza los\n"
        "movimientos de tipo Agua"),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType =  BATTLE_WEATHER_RAIN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_RAIN_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RainDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUNNY_DAY] =
    {
        .name = COMPOUND_STRING("Día Soleado"),
        .description = COMPOUND_STRING(
            "Hace que se intensifique\n"
        "el efecto del sol durante\n"
        "cinco turnos, lo que"),
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SUNNY_DAY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunnyDay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRUNCH] =
    {
        .name = COMPOUND_STRING("Triturar"),
        .description = COMPOUND_STRING(
            "Crunches with sharp fangs.\n"
        #if B_UPDATED_MOVE_DATA >= GEN_4
            "May lower Defense."),
        #else
            "May lower Sp. Def."),
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
            .additionalEffects = ADDITIONAL_EFFECTS({
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
        #else
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        #endif
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Crunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_COAT] =
    {
        .name = COMPOUND_STRING("Manto Espejo"),
        .description = COMPOUND_STRING(
            "Responde a un ataque\n"
        "especial ocasionando el\n"
        "doble del daño recibido."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS <= GEN_8,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MirrorCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCH_UP] =
    {
        .name = COMPOUND_STRING("Autosugestión"),
        .description = COMPOUND_STRING(
            "Quien lo usa se sume en un\n"
        "trance y copia cualquier\n"
        "cambio que haya en las"),
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTREME_SPEED] =
    {
        .name = COMPOUND_STRING("Velocidad Extrema"),
        .description = COMPOUND_STRING(
            "Ataque de una velocidad\n"
        "extrema. Este movimiento\n"
        "tiene prioridad alta."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 2 : 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ExtremeSpeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ANCIENT_POWER] =
    {
        .name = COMPOUND_STRING("Poder Pasado"),
        .description = COMPOUND_STRING(
            "Ataque prehistórico que\n"
        "puede subir todas las\n"
        "características."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AncientPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_BALL] =
    {
        .name = COMPOUND_STRING("Bola Sombra"),
        .description = COMPOUND_STRING(
            "Lanza una bola oscura que\n"
        "puede bajar la Defensa\n"
        "Especial del objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .name = COMPOUND_STRING("Premonición"),
        .description = COMPOUND_STRING(
            "Concentra energía psíquica\n"
        "para golpear al objetivo\n"
        "dos turnos después."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_FutureSight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SMASH] =
    {
        .name = COMPOUND_STRING("Golpe Roca"),
        .description = COMPOUND_STRING(
            "Ataque con los puños.\n"
        "Puede bajar la Defensa del\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 40 : 20,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockSmash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WHIRLPOOL] =
    {
        .name = COMPOUND_STRING("Torbellino"),
        .description = COMPOUND_STRING(
            "Una tromba de agua atrapa\n"
        "al objetivo durante cuatro\n"
        "o cinco turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderwater = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WHIRLPOOL,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Whirlpool,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BEAT_UP] =
    {
        .name = COMPOUND_STRING("Paliza"),
        .description = COMPOUND_STRING(
            "Ataque de todo el equipo\n"
        "Pokémon. Cuantos más haya,\n"
        "más veces se atacará."),
        .effect = EFFECT_BEAT_UP,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 1 : 10,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BEAT_UP_MESSAGE,
            .preAttackEffect = TRUE,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeatUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_OUT] =
    {
        .name = COMPOUND_STRING("Sorpresa"),
        .description = COMPOUND_STRING(
            "Amedrenta al objetivo con\n"
        "este movimiento de\n"
        "prioridad alta. Solo sirve"),
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 3 : 1,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_FAKE_OUT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeOut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_UPROAR] =
    {
        .name = COMPOUND_STRING("Alboroto"),
        .description = COMPOUND_STRING(
        #if B_UPROAR_TURNS >= GEN_5
            "Causes an uproar for 3\n"
        #else
            "Causes an uproar for 2 to 5\n"
        #endif
            "turns and prevents sleep."),
        .effect = EFFECT_UPROAR,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_UPROAR,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Uproar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STOCKPILE] =
    {
        .name = COMPOUND_STRING("Reserva"),
        .description = COMPOUND_STRING(
            "Acumula energía y sube la\n"
        "Defensa y la Defensa\n"
        "Especial. Puede utilizarse"),
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 20 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_STOCKPILE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Stockpile,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIT_UP] =
    {
        .name = COMPOUND_STRING("Escupir"),
        .description = COMPOUND_STRING(
            "Libera de una vez la\n"
        "energía acumulada con\n"
        "Reserva. La potencia del"),
        .effect = EFFECT_SPIT_UP,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_SpitUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWALLOW] =
    {
        .name = COMPOUND_STRING("Tragar"),
        .description = COMPOUND_STRING(
            "Absorbe la energía\n"
        "acumulada con Reserva para\n"
        "recobrar salud. Cuanta más"),
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_Swallow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAT_WAVE] =
    {
        .name = COMPOUND_STRING("Onda Ígnea"),
        .description = COMPOUND_STRING(
            "Provoca un viento\n"
        "abrasador que puede quemar\n"
        "al objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 100,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_HeatWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAIL] =
    {
        .name = COMPOUND_STRING("Granizo"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
            .description = COMPOUND_STRING(
                "Tormenta de granizo que\n"
        "dura cinco turnos. Hiere a\n"
        "todos los Pokémon excepto"),
        #else
            .description = COMPOUND_STRING(
                "Tormenta de granizo que\n"
        "dura cinco turnos. Hiere a\n"
        "todos los Pokémon excepto"),
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HAIL,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? gBattleAnimMove_Snowscape : gBattleAnimMove_Hail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TORMENT] =
    {
        .name = COMPOUND_STRING("Tormento"),
        .description = COMPOUND_STRING(
            "Atormenta y enfurece al\n"
        "objetivo, que no puede\n"
        "usar dos veces seguidas el"),
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_TORMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Torment,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLATTER] =
    {
        .name = COMPOUND_STRING("Camelo"),
        .description = COMPOUND_STRING(
            "Halaga al objetivo y lo\n"
        "confunde, pero también\n"
        "sube su Ataque Especial."),
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Flatter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WILL_O_WISP] =
    {
        .name = COMPOUND_STRING("Fuego Fatuo"),
        .description = COMPOUND_STRING(
            "Siniestra llama morada que\n"
        "produce quemaduras."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_BURN },
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WILL_O_WISP,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WillOWisp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEMENTO] =
    {
        .name = COMPOUND_STRING("Legado"),
        .description = COMPOUND_STRING(
            "El usuario se debilita,\n"
        "pero baja mucho tanto el\n"
        "Ataque como el Ataque"),
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Memento,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FACADE] =
    {
        .name = COMPOUND_STRING("Fachada"),
        .description = COMPOUND_STRING(
            "Si el usuario está\n"
        "quemado, paralizado o\n"
        "envenenado, ataca con el"),
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Facade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Certero"),
        .description = COMPOUND_STRING(
            "Se concentra para dar un\n"
        "puñetazo. Falla si se\n"
        "sufre un golpe antes de su"),
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = TRUE,
        .punchingMove = TRUE,
        .meFirstBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMELLING_SALTS] =
    {
        .name = COMPOUND_STRING("Estímulo"),
        .description = COMPOUND_STRING(
            "Muy potente contra rivales\n"
        "paralizados, pero los cura."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PARALYSIS },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_SmellingSalts,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOLLOW_ME] =
    {
        .name = COMPOUND_STRING("Señuelo"),
        .description = COMPOUND_STRING(
            "Llama la atención para\n"
        "concentrar todos los\n"
        "ataques de todos los del"),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FollowMe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NATURE_POWER] =
    {
        .name = COMPOUND_STRING("Adaptación"),
        .description = COMPOUND_STRING(
            "Usa el poder de la\n"
        "naturaleza para atacar. Su\n"
        "efecto varía según el"),
        .effect = EFFECT_NATURE_POWER,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_FLAGS >= GEN_6 ? TARGET_SELECTED : TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturePower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARGE] =
    {
        .name = COMPOUND_STRING("Carga"),
        .description = COMPOUND_STRING(
            "Recarga energía para\n"
        "potenciar el siguiente\n"
        "movimiento de tipo"),
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CHARGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAUNT] =
    {
        .name = COMPOUND_STRING("Mofa"),
        .description = COMPOUND_STRING(
            "Enfurece al objetivo para\n"
        "que solo use movimientos\n"
        "de ataque durante tres"),
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TAUNT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Taunt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HELPING_HAND] =
    {
        .name = COMPOUND_STRING("Refuerzo"),
        .description = COMPOUND_STRING(
            "El usuario ayuda a un\n"
        "aliado reforzando la\n"
        "potencia de su ataque."),
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_ALLY : TARGET_USER,
        .priority = 5,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HelpingHand,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRICK] =
    {
        .name = COMPOUND_STRING("Truco"),
        .description = COMPOUND_STRING(
            "Engaña al objetivo\n"
        "desprevenido e intercambia\n"
        "objetos."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLE_PLAY] =
    {
        .name = COMPOUND_STRING("Imitación"),
        .description = COMPOUND_STRING(
            "Imita al objetivo por\n"
        "completo y copia su\n"
        "habilidad."),
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RolePlay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WISH] =
    {
        .name = COMPOUND_STRING("Deseo"),
        .description = COMPOUND_STRING(
            "Restaura en el siguiente\n"
        "turno la mitad de los PS\n"
        "máximos del usuario o se"),
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASSIST] =
    {
        .name = COMPOUND_STRING("Ayuda"),
        .description = COMPOUND_STRING(
            "Usa al azar uno de los\n"
        "movimientos de un compañero."),
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Assist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_INGRAIN] =
    {
        .name = COMPOUND_STRING("Arraigo"),
        .description = COMPOUND_STRING(
            "Echa raíces para recuperar\n"
        "PS en cada turno, pero\n"
        "impide el relevo."),
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ingrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERPOWER] =
    {
        .name = COMPOUND_STRING("Fuerza Bruta"),
        .description = COMPOUND_STRING(
            "Ataque de gran potencia,\n"
        "pero que reduce el Ataque\n"
        "y la Defensa del agresor."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_DEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Superpower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGIC_COAT] =
    {
        .name = COMPOUND_STRING("Capa Mágica"),
        .description = COMPOUND_STRING(
            "Barrera capaz de devolver\n"
        "al agresor movimientos\n"
        "como Drenadoras y otros"),
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECYCLE] =
    {
        .name = COMPOUND_STRING("Reciclaje"),
        .description = COMPOUND_STRING(
            "Recicla y así recupera un\n"
        "objeto equipado de un solo\n"
        "uso que ya haya sido"),
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recycle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVENGE] =
    {
        .name = COMPOUND_STRING("Desquite"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_REVENGE,
        .contestComboMoves = {COMBO_STARTER_PAYBACK},
        .battleAnimScript = gBattleAnimMove_Revenge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BRICK_BREAK] =
    {
        .name = COMPOUND_STRING("Demolición"),
        .description = COMPOUND_STRING(
            "Potente ataque que también\n"
        "es capaz de destruir\n"
        "barreras como Pantalla de"),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BrickBreak,
        .validApprenticeMove = TRUE,
    },

    [MOVE_YAWN] =
    {
        .name = COMPOUND_STRING("Bostezo"),
        .description = COMPOUND_STRING(
            "Gran bostezo que induce al\n"
        "sueño al objetivo en el\n"
        "siguiente turno."),
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_YAWN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Yawn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KNOCK_OFF] =
    {
        .name = COMPOUND_STRING("Desarme"),
        .description = COMPOUND_STRING(
            "Impide al objetivo usar el\n"
        "objeto que lleva durante\n"
        "el combate. La potencia"),
        .effect = EFFECT_KNOCK_OFF,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
        .battleAnimScript = gBattleAnimMove_KnockOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDEAVOR] =
    {
        .name = COMPOUND_STRING("Esfuerzo"),
        .description = COMPOUND_STRING(
            "Reduce los PS del objetivo\n"
        "para que igualen a los del\n"
        "atacante."),
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Endeavor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ERUPTION] =
    {
        .name = COMPOUND_STRING("Estallido"),
        .description = COMPOUND_STRING(
            "Furia explosiva. Cuanto\n"
        "menor sea el número de PS\n"
        "del usuario, menos daño"),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_ENDURE, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Eruption,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKILL_SWAP] =
    {
        .name = COMPOUND_STRING("Intercambio"),
        .description = COMPOUND_STRING(
            "Usa el poder psíquico para\n"
        "intercambiar habilidades\n"
        "con el objetivo."),
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkillSwap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IMPRISON] =
    {
        .name = COMPOUND_STRING("Sellar"),
        .description = COMPOUND_STRING(
            "Impide a los contrincantes\n"
        "usar ataques conocidos por\n"
        "el usuario durante el"),
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_DONT_EXCITE_AUDIENCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Imprison,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFRESH] =
    {
        .name = COMPOUND_STRING("Alivio"),
        .description = COMPOUND_STRING(
            "Cura el envenenamiento,\n"
        "la parálisis o la quemadura."),
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SING, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_Refresh,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRUDGE] =
    {
        .name = COMPOUND_STRING("Rabia"),
        .description = COMPOUND_STRING(
            "Si el usuario se debilita\n"
        "al recibir un ataque,\n"
        "todos los PP de este"),
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Grudge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SNATCH] =
    {
        .name = COMPOUND_STRING("Robo"),
        .description = COMPOUND_STRING(
            "Roba el efecto del próximo\n"
        "movimiento del objetivo."),
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .forcePressure = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snatch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SECRET_POWER] =
    {
        .name = COMPOUND_STRING("Daño Secreto"),
        .description = COMPOUND_STRING(
            "Ataque con efectos que\n"
        "varían según la localización."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SECRET_POWER,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIVE] =
    {
        .name = COMPOUND_STRING("Buceo"),
        .description = COMPOUND_STRING(
            "El usuario se sumerge en\n"
        "el primer turno y ataca en\n"
        "el segundo."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 80 : 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNHIDUNDERWATER, .status = STATE_UNDERWATER },
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_DIVE,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
        .battleAnimScript = gBattleAnimMove_Dive,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ARM_THRUST] =
    {
        .name = COMPOUND_STRING("Empujón"),
        .description = COMPOUND_STRING(
            "Fuertes empujones que\n"
        "golpean de dos a cinco\n"
        "veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ArmThrust,
    },

    [MOVE_CAMOUFLAGE] =
    {
        .name = COMPOUND_STRING("Camuflaje"),
        .description = COMPOUND_STRING(
            "Cambia el tipo del Pokémon\n"
        "según el terreno actual."),
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Camouflage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_GLOW] =
    {
        .name = COMPOUND_STRING("Luminicola"),
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_5
            "Flash light that drastically\n"
        #else
            "Flashes a light that sharply\n"
        #endif
            "raises Sp. Atk."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_5 ? EFFECT_SPECIAL_ATTACK_UP_3 : EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailGlow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LUSTER_PURGE] =
    {
        .name = COMPOUND_STRING("Resplandor"),
        .description = COMPOUND_STRING(
            "Fogonazo de luz que puede\n"
        "bajar la Defensa Especial\n"
        "del objetivo."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LusterPurge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST_BALL] =
    {
        .name = COMPOUND_STRING("Bola Neblina"),
        .description = COMPOUND_STRING(
            "Banco de niebla que puede\n"
        "bajar el Ataque Especial\n"
        "del objetivo."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_MistBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEATHER_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Pluma"),
        .description = COMPOUND_STRING(
            "Envuelve al objetivo con\n"
        "un manto de plumas para\n"
        "reducir mucho su Ataque."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FeatherDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TEETER_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Caos"),
        .description = COMPOUND_STRING(
            "Danza histérica que\n"
        "confunde a los Pokémon que\n"
        "están alrededor del"),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .danceMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TeeterDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAZE_KICK] =
    {
        .name = COMPOUND_STRING("Patada Ígnea"),
        .description = COMPOUND_STRING(
            "Patada que suele ser un\n"
        "golpe crítico y puede\n"
        "causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BlazeKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SPORT] =
    {
        .name = COMPOUND_STRING("Chapoteo Lodo"),
        .description = COMPOUND_STRING(
            "Se cubre de barro para debilitar\n"
        "todos los ataques Eléctricos."),
        // in theory this should mention 5 turns (gen 6+)
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_MudSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BALL] =
    {
        .name = COMPOUND_STRING("Bola Hielo"),
        .description = COMPOUND_STRING(
            "Ataque de 5 turnos que gana\n"
        "fuerza en cada impacto."),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_DEFENSE_CURL},
        .battleAnimScript = gBattleAnimMove_IceBall,
    },

    [MOVE_NEEDLE_ARM] =
    {
        .name = COMPOUND_STRING("Brazo Pincho"),
        .description = COMPOUND_STRING(
            "Ataca con brazos espinosos.\n"
        "Puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NeedleArm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLACK_OFF] =
    {
        .name = COMPOUND_STRING("Relajo"),
        .description = COMPOUND_STRING(
            "El usuario se relaja y\n"
        "restaura la mitad de sus\n"
        "PS máximos."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SlackOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_VOICE] =
    {
        .name = COMPOUND_STRING("Vozarrón"),
        .description = COMPOUND_STRING(
            "Grito desgarrador que\n"
        "inflige daño al objetivo."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperVoice,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_FANG] =
    {
        .name = COMPOUND_STRING("Colmillo Veneno"),
        .description = COMPOUND_STRING(
            "Colmillos tóxicos que\n"
        "pueden envenenar\n"
        "gravemente al objetivo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonFang,
    },

    [MOVE_CRUSH_CLAW] =
    {
        .name = COMPOUND_STRING("Garra Brutal"),
        .description = COMPOUND_STRING(
            "Hace trizas al objetivo\n"
        "con garras afiladas y\n"
        "puede bajar su Defensa."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_CrushClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAST_BURN] =
    {
        .name = COMPOUND_STRING("Anillo Ígneo"),
        .description = COMPOUND_STRING(
            "Explosión de fuego. El\n"
        "atacante debe descansar el\n"
        "siguiente turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BlastBurn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYDRO_CANNON] =
    {
        .name = COMPOUND_STRING("Hidrocañón"),
        .description = COMPOUND_STRING(
            "Disparo de agua. El\n"
        "atacante debe descansar el\n"
        "siguiente turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METEOR_MASH] =
    {
        .name = COMPOUND_STRING("Puño Meteoro"),
        .description = COMPOUND_STRING(
            "Puñetazo que impacta como\n"
        "un meteorito y puede subir\n"
        "el Ataque del agresor."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 100,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorMash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASTONISH] =
    {
        .name = COMPOUND_STRING("Impresionar"),
        .description = COMPOUND_STRING(
            "Lanza un grito tan\n"
        "tremendo que impresiona y\n"
        "puede amedrentar al"),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Astonish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WEATHER_BALL] =
    {
        .name = COMPOUND_STRING("Meteorobola"),
        .description = COMPOUND_STRING(
            "El tipo y fuerza del\n"
        "ataque varían según el\n"
        "tiempo que haga."),
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SANDSTORM, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WeatherBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AROMATHERAPY] =
    {
        .name = COMPOUND_STRING("Aromaterapia"),
        .description = COMPOUND_STRING(
            "Cura todos los problemas\n"
        "de estado del equipo con\n"
        "un suave aroma."),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aromatherapy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_TEARS] =
    {
        .name = COMPOUND_STRING("Llanto Falso"),
        .description = COMPOUND_STRING(
            "Lágrimas de cocodrilo que\n"
        "bajan mucho la Defensa\n"
        "Especial del objetivo."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeTears,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AIR_CUTTER] =
    {
        .name = COMPOUND_STRING("Aire Afilado"),
        .description = COMPOUND_STRING(
            "Viento cortante que azota.\n"
        "Suele ser un golpe\n"
        "crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 55,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OVERHEAT] =
    {
        .name = COMPOUND_STRING("Sofoco"),
        .description = COMPOUND_STRING(
            "Ataque en toda regla que\n"
        "baja mucho el Ataque\n"
        "Especial de quien lo usa."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Overheat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        .name = COMPOUND_STRING("Rastreo"),
        .description = COMPOUND_STRING(
            "Anula la evasión y las\n"
        "inmunidades del tipo Fantasma."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OdorSleuth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_TOMB] =
    {
        .name = COMPOUND_STRING("Tumba Rocas"),
        .description = COMPOUND_STRING(
            "Tira rocas que detienen al\n"
        "objetivo y bajan su\n"
        "Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SILVER_WIND] =
    {
        .name = COMPOUND_STRING("Viento Plata"),
        .description = COMPOUND_STRING(
            "Ataque de polvo que puede\n"
        "subir todas las estadísticas."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SilverWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_SOUND] =
    {
        .name = COMPOUND_STRING("Eco Metálico"),
        .description = COMPOUND_STRING(
            "Horrible chirrido metálico\n"
        "que baja mucho la Defensa\n"
        "Especial del objetivo."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_METAL_SOUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MetalSound,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .name = COMPOUND_STRING("Silbato"),
        .description = COMPOUND_STRING(
            "Melodía agradable que\n"
        "duerme al objetivo."),
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_GRASS_WHISTLE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassWhistle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TICKLE] =
    {
        .name = COMPOUND_STRING("Cosquillas"),
        .description = COMPOUND_STRING(
            "Hace reír al objetivo para\n"
        "bajar su Ataque y Defensa."),
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_4,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tickle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COSMIC_POWER] =
    {
        .name = COMPOUND_STRING("Masa Cósmica"),
        .description = COMPOUND_STRING(
            "Sube la Defensa y la\n"
        "Defensa Especial propias\n"
        "con energía mística."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CosmicPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPOUT] =
    {
        .name = COMPOUND_STRING("Salpicar"),
        .description = COMPOUND_STRING(
            "Chorro de agua. Cuantos\n"
        "menos PS tenga el usuario,\n"
        "menos dañino será."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSpout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Señal"),
        .description = COMPOUND_STRING(
            "Rayo extraño que puede\n"
        "confundir al rival."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SignalBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Sombra"),
        .description = COMPOUND_STRING(
            "Puñetazo ineludible\n"
        "procedente de las sombras."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTRASENSORY] =
    {
        .name = COMPOUND_STRING("Paranormal"),
        .description = COMPOUND_STRING(
            "Emite una energía muy\n"
        "extraña que puede\n"
        "amedrentar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Extrasensory,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .name = COMPOUND_STRING("Gancho Alto"),
        .description = COMPOUND_STRING(
            "Gancho lanzado como si se\n"
        "saltara hacia el cielo."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .damagesAirborne = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_SkyUppercut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_TOMB] =
    {
        .name = COMPOUND_STRING("Bucle Arena"),
        .description = COMPOUND_STRING(
            "Enreda al objetivo en un\n"
        "remolino de arena de\n"
        "cuatro a cinco turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SAND_TOMB,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHEER_COLD] =
    {
        .name = COMPOUND_STRING("Frío Polar"),
        .description = COMPOUND_STRING(
            "Debilita al objetivo de un\n"
        "solo golpe. Si lo usa un\n"
        "Pokémon que no sea de tipo"),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .noAffectOnSameTypeTarget = B_SHEER_COLD_IMMUNITY >= GEN_7,
        .accIncreaseByTenOnSameType = B_SHEER_COLD_ACC >= GEN_7,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_SheerCold,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUDDY_WATER] =
    {
        .name = COMPOUND_STRING("Agua Lodosa"),
        .description = COMPOUND_STRING(
            "Ataque con agua lodosa que\n"
        "puede bajar la Precisión\n"
        "del equipo rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_MuddyWater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULLET_SEED] =
    {
        .name = COMPOUND_STRING("Semilladora"),
        .description = COMPOUND_STRING(
            "Dispara rápido de dos a\n"
        "cinco ráfagas de semillas\n"
        "de manera consecutiva."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_BulletSeed,
    },

    [MOVE_AERIAL_ACE] =
    {
        .name = COMPOUND_STRING("Golpe Aéreo"),
        .description = COMPOUND_STRING(
            "El usuario lanza un ataque\n"
        "muy rápido e ineludible."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AerialAce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        .name = COMPOUND_STRING("Carámbano"),
        .description = COMPOUND_STRING(
            "Ataca lanzando de dos a\n"
        "cinco ráfagas consecutivas\n"
        "de carámbanos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IcicleSpear,
    },

    [MOVE_IRON_DEFENSE] =
    {
        .name = COMPOUND_STRING("Defensa Férrea"),
        .description = COMPOUND_STRING(
            "Fortalece el cuerpo como\n"
        "si fuera de hierro y sube\n"
        "mucho la Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronDefense,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLOCK] =
    {
        .name = COMPOUND_STRING("Bloqueo"),
        .description = COMPOUND_STRING(
            "Le corta el paso al\n"
        "objetivo para que no pueda\n"
        "escapar."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BLOCK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Block,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HOWL] =
    {
        .name = COMPOUND_STRING("Aullido"),
        .description = COMPOUND_STRING(
            "Aullido que sube el ánimo\n"
        "y aumenta el Ataque del\n"
        "equipo."),
        .power = 0,
        .effect = EFFECT_ATTACK_UP,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_8 ? TARGET_USER_AND_ALLY: TARGET_USER ,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Howl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_CLAW] =
    {
        .name = COMPOUND_STRING("Garra Dragón"),
        .description = COMPOUND_STRING(
            "Araña al objetivo con\n"
        "garras afiladas."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRENZY_PLANT] =
    {
        .name = COMPOUND_STRING("Planta Feroz"),
        .description = COMPOUND_STRING(
            "Golpea con una enorme\n"
        "planta. Quien lo usa no\n"
        "puede moverse en el"),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_FrenzyPlant,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULK_UP] =
    {
        .name = COMPOUND_STRING("Corpulencia"),
        .description = COMPOUND_STRING(
            "Robustece el cuerpo para\n"
        "subir el Ataque y la\n"
        "Defensa."),
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulkUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BOUNCE] =
    {
        .name = COMPOUND_STRING("Bote"),
        .description = COMPOUND_STRING(
            "El usuario bota en el\n"
        "primer turno y golpea al\n"
        "objetivo en el segundo y"),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNSPRANGUP, .status = STATE_ON_AIR },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bounce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SHOT] =
    {
        .name = COMPOUND_STRING("Disparo Lodo"),
        .description = COMPOUND_STRING(
            "El usuario lanza lodo al\n"
        "objetivo y reduce su\n"
        "Velocidad."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudShot,
    },

    [MOVE_POISON_TAIL] =
    {
        .name = COMPOUND_STRING("Cola Veneno"),
        .description = COMPOUND_STRING(
            "Puede envenenar y dar un\n"
        "golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_PoisonTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COVET] =
    {
        .name = COMPOUND_STRING("Antojo"),
        .description = COMPOUND_STRING(
            "Se acerca con ternura al\n"
        "objetivo, pero le ataca y\n"
        "le roba el objeto que"),
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 60 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_COVET,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Covet,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VOLT_TACKLE] =
    {
        .name = COMPOUND_STRING("Placaje Eléctrico"),
        #if B_UPDATED_MOVE_DATA >= GEN_4
        .description = COMPOUND_STRING(
            "Quien lo usa electrifica\n"
        "su cuerpo para luego\n"
        "atacar. Se hiere mucho a"),
        #else
        .description = COMPOUND_STRING(
            "Quien lo usa electrifica\n"
        "su cuerpo para luego\n"
        "atacar. Se hiere mucho a"),
        #endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_PARALYSIS,
                .chance = 10,
            }),
        #endif
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltTackle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .name = COMPOUND_STRING("Hoja Mágica"),
        .description = COMPOUND_STRING(
            "Esparce extrañas hojas que\n"
        "persiguen al objetivo. No\n"
        "se puede esquivar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MagicalLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPORT] =
    {
        .name = COMPOUND_STRING("Hidrochorro"),
        .description = COMPOUND_STRING(
            "El usuario se empapa para debilitar\n"
        "todos los ataques Fuego."),
        // in theory this should mention 5 turns (gen6+)
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WATER_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CALM_MIND] =
    {
        .name = COMPOUND_STRING("Paz Mental"),
        .description = COMPOUND_STRING(
            "Aumenta la concentración y\n"
        "calma el espíritu para\n"
        "subir el Ataque Especial y"),
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CALM_MIND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CalmMind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LEAF_BLADE] =
    {
        .name = COMPOUND_STRING("Hoja Aguda"),
        .description = COMPOUND_STRING(
            "Acuchilla con una hoja\n"
        "fina. Suele dar un golpe\n"
        "crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafBlade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Dragón"),
        .description = COMPOUND_STRING(
            "Danza mística que sube el\n"
        "Ataque y la Velocidad."),
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_BLAST] =
    {
        .name = COMPOUND_STRING("Pedrada"),
        .description = COMPOUND_STRING(
            "Lanza pedruscos al\n"
        "objetivo de dos a cinco\n"
        "veces consecutivas."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockBlast,
    },

    [MOVE_SHOCK_WAVE] =
    {
        .name = COMPOUND_STRING("Onda Voltio"),
        .description = COMPOUND_STRING(
            "Ataque eléctrico muy\n"
        "rápido e ineludible."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ShockWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_PULSE] =
    {
        .name = COMPOUND_STRING("Hidropulso"),
        .description = COMPOUND_STRING(
            "Ataca con un potente\n"
        "chorro de agua. Puede\n"
        "confundir al objetivo."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterPulse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOOM_DESIRE] =
    {
        .name = COMPOUND_STRING("Deseo Oculto"),
        .description = COMPOUND_STRING(
            "Concentra un haz de luz y\n"
        "ataca dos turnos después."),
        .effect = EFFECT_FUTURE_SIGHT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 120,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoomDesire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .name = COMPOUND_STRING("Psicoataque"),
        .description = COMPOUND_STRING(
            "Ataque a máxima potencia\n"
        "que baja mucho el At. Esp."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_PsychoBoost,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROOST] =
    {
        .name = COMPOUND_STRING("Respiro"),
        .description = COMPOUND_STRING(
            "Aterriza sobre la\n"
        "superficie para descansar.\n"
        "Recupera hasta la mitad"),
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_BRAVE_BIRD},
        .battleAnimScript = gBattleAnimMove_Roost,
    },

    [MOVE_GRAVITY] =
    {
        .name = COMPOUND_STRING("Gravedad"),
        .description = COMPOUND_STRING(
            "Durante cinco turnos, se\n"
        "anulan los movimientos que\n"
        "alzan el vuelo y los"),
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gravity,
    },

    [MOVE_MIRACLE_EYE] =
    {
        .name = COMPOUND_STRING("Gran Ojo"),
        .description = COMPOUND_STRING(
            "Anula la evasión e inmunidades\n"
        "del tipo Siniestro."),
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MiracleEye,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .name = COMPOUND_STRING("Espabila"),
        .description = COMPOUND_STRING(
            "Muy potente contra dormidos,\n"
        "pero los despierta."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_SLEEP },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_WakeUpSlap,
    },

    [MOVE_HAMMER_ARM] =
    {
        .name = COMPOUND_STRING("Machada"),
        .description = COMPOUND_STRING(
            "Gira con fuerza el puño y\n"
        "da un gran golpe. No\n"
        "obstante, baja la"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_HammerArm,
    },

    [MOVE_GYRO_BALL] =
    {
        .name = COMPOUND_STRING("Giro Bola"),
        .description = COMPOUND_STRING(
            "Embiste al objetivo con un\n"
        "potente ataque giratorio.\n"
        "Cuanto más lento es el"),
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GyroBall,
    },

    [MOVE_HEALING_WISH] =
    {
        .name = COMPOUND_STRING("Deseo Cura"),
        .description = sHealingWishDescription,
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealingWish,
    },

    [MOVE_BRINE] =
    {
        .name = COMPOUND_STRING("Salmuera"),
        .description = COMPOUND_STRING(
            "Si al objetivo le queda la\n"
        "mitad o menos de sus PS,\n"
        "el ataque será el doble de"),
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Brine,
    },

    [MOVE_NATURAL_GIFT] =
    {
        .name = COMPOUND_STRING("Don Natural"),
        .description = COMPOUND_STRING(
            "La efectividad varía según\n"
        "la baya que se lleve."),
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturalGift,
    },

    [MOVE_FEINT] =
    {
        .name = COMPOUND_STRING("Amago"),
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 30 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Feint,
    },

    [MOVE_PLUCK] =
    {
        .name = COMPOUND_STRING("Picoteo"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pluck,
    },

    [MOVE_TAILWIND] =
    {
        .name = COMPOUND_STRING("Viento Afín"),
        .description = COMPOUND_STRING(
            "Whips up a breeze, doubling\n"
        #if B_TAILWIND_TURNS >= GEN_5
            "ally Speed for 4 turns."),
        #else
            "ally Speed for 3 turns."),
        #endif
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .snatchAffected = TRUE,
        .windMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tailwind,
    },

    [MOVE_ACUPRESSURE] =
    {
        .name = COMPOUND_STRING("Acupresión"),
        .description = COMPOUND_STRING(
            "Aplica presión en puntos\n"
        "clave del cuerpo para\n"
        "potenciar mucho una de sus"),
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER_OR_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acupressure,
    },

    [MOVE_METAL_BURST] =
    {
        .name = COMPOUND_STRING("Represión Metal"),
        .description = COMPOUND_STRING(
            "Devuelve al rival el\n"
        "último ataque recibido,\n"
        "pero con mucha más fuerza."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .meFirstBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MetalBurst,
    },

    [MOVE_U_TURN] =
    {
        .name = COMPOUND_STRING("Ida y Vuelta"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_UTurn,
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .name = COMPOUND_STRING("A Bocajarro"),
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_CloseCombat,
    },

    [MOVE_PAYBACK] =
    {
        .name = COMPOUND_STRING("Vendetta"),
        .description = COMPOUND_STRING(
            "El usuario contraataca con\n"
        "el doble de fuerza si el\n"
        "objetivo usa un movimiento"),
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PAYBACK,
        .contestComboMoves = {COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Payback,
    },

    [MOVE_ASSURANCE] =
    {
        .name = COMPOUND_STRING("Buena Baza"),
        .description = COMPOUND_STRING(
            "Si el objetivo ya ha\n"
        "sufrido daño en ese turno,\n"
        "la fuerza del ataque se"),
        .effect = EFFECT_ASSURANCE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PAYBACK, COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Assurance,
    },

    [MOVE_EMBARGO] =
    {
        .name = COMPOUND_STRING("Embargo"),
        .description = COMPOUND_STRING(
            "Impide al rival usar\n"
        "cualquier objeto."),
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Embargo,
    },

    [MOVE_FLING] =
    {
        .name = COMPOUND_STRING("Lanzamiento"),
        .description = COMPOUND_STRING(
            "El usuario lanza contra el\n"
        "objetivo el objeto que\n"
        "lleva. La fuerza del"),
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Fling,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        .name = COMPOUND_STRING("Psicocambio"),
        .description = COMPOUND_STRING(
            "Usa su poder mental para\n"
        "transferir al objetivo sus\n"
        "problemas de estado."),
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoShift,
    },

    [MOVE_TRUMP_CARD] =
    {
        .name = COMPOUND_STRING("As Oculto"),
        .description = COMPOUND_STRING(
            "Cuantos menos PP tiene,\n"
        "más daño causa este movimiento."),
        .effect = EFFECT_TRUMP_CARD,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrumpCard,
    },

    [MOVE_HEAL_BLOCK] =
    {
        .name = COMPOUND_STRING("Anticura"),
        .description = COMPOUND_STRING(
            "Impide al rival recuperar\n"
        "PS durante 5 turnos."),
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealBlock,
    },

    [MOVE_WRING_OUT] =
    {
        .name = COMPOUND_STRING("Estrujón"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WringOut,
    },

    [MOVE_POWER_TRICK] =
    {
        .name = COMPOUND_STRING("Truco Fuerza"),
        .description = COMPOUND_STRING(
            "El usuario intercambia su\n"
        "Ataque y su Defensa."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrick,
    },

    [MOVE_GASTRO_ACID] =
    {
        .name = COMPOUND_STRING("Bilis"),
        .description = COMPOUND_STRING(
            "Ácido que anula la\n"
        "habilidad del rival."),
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GastroAcid,
    },

    [MOVE_LUCKY_CHANT] =
    {
        .name = COMPOUND_STRING("Conjuro"),
        .description = COMPOUND_STRING(
            "Canto que previene que el\n"
        "rival aseste críticos."),
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_LUCKY_CHANT,
        .contestComboMoves = {COMBO_STARTER_HEAL_BELL},
        .battleAnimScript = gBattleAnimMove_LuckyChant,
    },

    [MOVE_ME_FIRST] =
    {
        .name = COMPOUND_STRING("Yo Primero"),
        .description = COMPOUND_STRING(
            "Ejecuta el ataque del rival\n"
        "con mayor potencia."),
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENT,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeFirst,
    },

    [MOVE_COPYCAT] =
    {
        .name = COMPOUND_STRING("Copión"),
        .description = COMPOUND_STRING(
            "Imita el último movimiento\n"
        "usado por cualquiera."),
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Copycat,
    },

    [MOVE_POWER_SWAP] =
    {
        .name = COMPOUND_STRING("Cambiafuerza"),
        .description = COMPOUND_STRING(
            "Intercambia mejoras de\n"
        "Ataque y At. Esp. rival."),
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSwap,
    },

    [MOVE_GUARD_SWAP] =
    {
        .name = COMPOUND_STRING("Cambiadefensa"),
        .description = COMPOUND_STRING(
            "Intercambia mejoras de\n"
        "Defensa y Def. Esp. rival."),
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSwap,
    },

    [MOVE_PUNISHMENT] =
    {
        .name = COMPOUND_STRING("Castigo"),
        .description = COMPOUND_STRING(
            "Más daño cuantas más mejoras\n"
        "de stats tenga el rival."),
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Punishment,
    },

    [MOVE_LAST_RESORT] =
    {
        .name = COMPOUND_STRING("Última Baza"),
        .description = COMPOUND_STRING(
            "Solo puede usarse tras haber\n"
        "usado los demás ataques."),
        .effect = EFFECT_LAST_RESORT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LastResort,
    },

    [MOVE_WORRY_SEED] =
    {
        .name = COMPOUND_STRING("Abatidoras"),
        .description = COMPOUND_STRING(
            "Siembra una semilla que cambia\n"
        "la habilidad a Insomnio."),
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_INSOMNIA },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WORRY_SEED,
        .contestComboMoves = {COMBO_STARTER_LEECH_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_WorrySeed,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        .name = COMPOUND_STRING("Golpe Bajo"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 70 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SuckerPunch,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        .name = COMPOUND_STRING("Púas Tóxicas"),
        .description = COMPOUND_STRING(
            "Lanza púas que envenenan al\n"
        "rival al entrar al campo."),
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ToxicSpikes,
    },

    [MOVE_HEART_SWAP] =
    {
        .name = COMPOUND_STRING("Cambiaalmas"),
        .description = COMPOUND_STRING(
            "Intercambia todos los cambios\n"
        "de stats con el rival."),
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartSwap,
    },

    [MOVE_AQUA_RING] =
    {
        .name = COMPOUND_STRING("Acua Aro"),
        .description = COMPOUND_STRING(
            "Crea un velo de agua que cura\n"
        "PS al final de cada turno."),
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AquaRing,
    },

    [MOVE_MAGNET_RISE] =
    {
        .name = COMPOUND_STRING("Levitón"),
        .description = COMPOUND_STRING(
            "El usuario levita gracias al\n"
        "electromagnetismo."),
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetRise,
    },

    [MOVE_FLARE_BLITZ] =
    {
        .name = COMPOUND_STRING("Envite Ígneo"),
        .description = COMPOUND_STRING(
            "Carga ígnea que puede quemar\n"
        "pero daña al usuario."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlareBlitz,
    },

    [MOVE_FORCE_PALM] =
    {
        .name = COMPOUND_STRING("Palmeo"),
        .description = COMPOUND_STRING(
            "Onda de choque que puede\n"
        "paralizar al rival."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FORCE_PALM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForcePalm,
    },

    [MOVE_AURA_SPHERE] =
    {
        .name = COMPOUND_STRING("Esfera Aural"),
        .description = COMPOUND_STRING(
            "Lanza una ráfaga de aura que\n"
        "nunca puede fallar."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 90,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraSphere,
    },

    [MOVE_ROCK_POLISH] =
    {
        .name = COMPOUND_STRING("Pulimento"),
        .description = COMPOUND_STRING(
            "Pule el cuerpo para subir\n"
        "mucho la Velocidad."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_POLISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockPolish,
    },

    [MOVE_POISON_JAB] =
    {
        .name = COMPOUND_STRING("Puya Nociva"),
        .description = COMPOUND_STRING(
            "Pinchazo venenoso que puede\n"
        "envenenar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonJab,
    },

    [MOVE_DARK_PULSE] =
    {
        .name = COMPOUND_STRING("Pulso Umbrío"),
        .description = COMPOUND_STRING(
            "Aura oscura que puede hacer\n"
        "retroceder al rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkPulse,
    },

    [MOVE_NIGHT_SLASH] =
    {
        .name = COMPOUND_STRING("Tajo Umbrío"),
        .description = COMPOUND_STRING(
            "Cuchillada veloz con alta\n"
        "tasa de golpes críticos."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_NightSlash,
    },

    [MOVE_AQUA_TAIL] =
    {
        .name = COMPOUND_STRING("Acua Cola"),
        .description = COMPOUND_STRING(
            "Golpea con la cola como si\n"
        "fuera una gran ola."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaTail,
    },

    [MOVE_SEED_BOMB] =
    {
        .name = COMPOUND_STRING("Bomba Germen"),
        .description = COMPOUND_STRING(
            "Dispara una ráfaga de duras\n"
        "semillas al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_SeedBomb,
    },

    [MOVE_AIR_SLASH] =
    {
        .name = COMPOUND_STRING("Tajo Aéreo"),
        .description = COMPOUND_STRING(
            "Cuchilla de viento que puede\n"
        "hacer retroceder al rival."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirSlash,
    },

    [MOVE_X_SCISSOR] =
    {
        .name = COMPOUND_STRING("Tijera X"),
        .description = COMPOUND_STRING(
            "Tijera cruzada con garras\n"
        "o guadañas al rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_XScissor,
    },

    [MOVE_BUG_BUZZ] =
    {
        .name = COMPOUND_STRING("Zumbido"),
        .description = COMPOUND_STRING(
            "Onda sonora vibrante que puede\n"
        "bajar la Def. Especial."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTIFUL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBuzz,
    },

    [MOVE_DRAGON_PULSE] =
    {
        .name = COMPOUND_STRING("Pulso Dragón"),
        .description = COMPOUND_STRING(
            "Genera una onda de choque de\n"
        "dragón que daña al rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonPulse,
    },

    [MOVE_DRAGON_RUSH] =
    {
        .name = COMPOUND_STRING("Carga Dragón"),
        .description = COMPOUND_STRING(
            "Embestida brutal de dragón\n"
        "que puede amedrentar."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RUSH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRush,
    },

    [MOVE_POWER_GEM] =
    {
        .name = COMPOUND_STRING("Joya de Luz"),
        .description = COMPOUND_STRING(
            "Rayo de gemas brillantes que\n"
        "resplandecen como joyas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerGem,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Drenaje"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrainPunch,
    },

    [MOVE_VACUUM_WAVE] =
    {
        .name = COMPOUND_STRING("Onda Vacío"),
        .description = COMPOUND_STRING(
            "Gira los puños creando una\n"
        "onda que ataca primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VacuumWave,
    },

    [MOVE_FOCUS_BLAST] =
    {
        .name = COMPOUND_STRING("Onda Certera"),
        .description = COMPOUND_STRING(
            "Ataque a tope de poder que\n"
        "puede bajar Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusBlast,
    },

    [MOVE_ENERGY_BALL] =
    {
        .name = COMPOUND_STRING("Energibola"),
        .description = COMPOUND_STRING(
            "Concentra energía natural;\n"
        "puede bajar Def. Especial."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_EnergyBall,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .name = COMPOUND_STRING("Pájaro Osado"),
        .description = COMPOUND_STRING(
            "Carga a baja altura que causa\n"
        "daño de retroceso."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BRAVE_BIRD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BraveBird,
    },

    [MOVE_EARTH_POWER] =
    {
        .name = COMPOUND_STRING("Tierra Viva"),
        .description = COMPOUND_STRING(
            "Erupción de tierra que puede\n"
        "reducir la Def. Especial."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EarthPower,
    },

    [MOVE_SWITCHEROO] =
    {
        .name = COMPOUND_STRING("Trapicheo"),
        .description = COMPOUND_STRING(
            "Intercambia objetos con el\n"
        "rival rápidamente."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Switcheroo,
    },

    [MOVE_GIGA_IMPACT] =
    {
        .name = COMPOUND_STRING("Gigaimpacto"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GigaImpact,
    },

    [MOVE_NASTY_PLOT] =
    {
        .name = COMPOUND_STRING("Maquinación"),
        .description = COMPOUND_STRING(
            "Maquila planes malvados para\n"
        "subir mucho el At. Esp."),
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_NASTY_PLOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NastyPlot,
    },

    [MOVE_BULLET_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Bala"),
        .description = COMPOUND_STRING(
            "Puñetazo veloz como una bala\n"
        "que ataca con prioridad."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulletPunch,
    },

    [MOVE_AVALANCHE] =
    {
        .name = COMPOUND_STRING("Alud"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Avalanche,
    },

    [MOVE_ICE_SHARD] =
    {
        .name = COMPOUND_STRING("Esquirla Helada"),
        .description = COMPOUND_STRING(
            "Lanza fragmentos de hielo que\n"
        "siempre golpean primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceShard,
    },

    [MOVE_SHADOW_CLAW] =
    {
        .name = COMPOUND_STRING("Garra Umbría"),
        .description = COMPOUND_STRING(
            "Zarpazo de sombras con alta\n"
        "probabilidad de crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ShadowClaw,
    },

    [MOVE_THUNDER_FANG] =
    {
        .name = COMPOUND_STRING("Colmillo Rayo"),
        .description = COMPOUND_STRING(
            "Mordisco eléctrico que puede\n"
        "paralizar o amedrentar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_THUNDER_FANG,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_FANG, COMBO_STARTER_ICE_FANG},
        .battleAnimScript = gBattleAnimMove_ThunderFang,
    },

    [MOVE_ICE_FANG] =
    {
        .name = COMPOUND_STRING("Colmillo Hielo"),
        .description = COMPOUND_STRING(
            "May cause flinching or\n"
        #if B_USE_FROSTBITE == TRUE
            "leave the foe with frostbite."),
        #else
            "leave the foe frozen."),
        #endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_ICE_FANG,
        .contestComboMoves = {COMBO_STARTER_FIRE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_IceFang,
    },

    [MOVE_FIRE_FANG] =
    {
        .name = COMPOUND_STRING("Colmillo Ígneo"),
        .description = COMPOUND_STRING(
            "Mordisco ígneo que puede\n"
        "quemar o amedrentar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_FANG,
        .contestComboMoves = {COMBO_STARTER_ICE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_FireFang,
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .name = COMPOUND_STRING("Sombra Vil"),
        .description = COMPOUND_STRING(
            "Extiende su sombra para\n"
        "golpear siempre primero."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowSneak,
    },

    [MOVE_MUD_BOMB] =
    {
        .name = COMPOUND_STRING("Bomba Fango"),
        .description = COMPOUND_STRING(
            "Dispara una bola de lodo que\n"
        "puede reducir la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MudBomb,
    },

    [MOVE_PSYCHO_CUT] =
    {
        .name = COMPOUND_STRING("Psicocorte"),
        .description = COMPOUND_STRING(
            "Cuchillas psíquicas con alta\n"
        "probabilidad de crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoCut,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .name = COMPOUND_STRING("Cabezazo Zen"),
        .description = COMPOUND_STRING(
            "Fuerte cabezazo psíquico que\n"
        "puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ZenHeadbutt,
    },

    [MOVE_MIRROR_SHOT] =
    {
        .name = COMPOUND_STRING("Disparo Espejo"),
        .description = COMPOUND_STRING(
            "Destello de luz espejo que\n"
        "puede bajar la Precisión."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorShot,
    },

    [MOVE_FLASH_CANNON] =
    {
        .name = COMPOUND_STRING("Cañón Resplandor"),
        .description = COMPOUND_STRING(
            "Haz de luz concentrada que\n"
        "puede bajar Def. Especial."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlashCannon,
    },

    [MOVE_ROCK_CLIMB] =
    {
        .name = COMPOUND_STRING("Treparrocas"),
        .description = COMPOUND_STRING(
            "Carga de escalada que puede\n"
        "dejar confuso al rival."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockClimb,
    },

    [MOVE_DEFOG] =
    {
        .name = COMPOUND_STRING("Despejar"),
        .description = COMPOUND_STRING(
            "Disipa neblina y pantallas;\n"
        "reduce la Evasión rival."),
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        //.ignoresSubstitute = TRUE, In Gen5+, the evasion drop will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Defog,
    },

    [MOVE_TRICK_ROOM] =
    {
        .name = COMPOUND_STRING("Espacio Raro"),
        .description = COMPOUND_STRING(
            "Los Pokémon más lentos se\n"
        "mueven antes durante 5 turnos."),
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickRoom,
    },

    [MOVE_DRACO_METEOR] =
    {
        .name = COMPOUND_STRING("Cometa Draco"),
        .description = COMPOUND_STRING(
            "Invoca cometas; reduce mucho\n"
        "el Ataque Especial propio."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DracoMeteor,
    },

    [MOVE_DISCHARGE] =
    {
        .name = COMPOUND_STRING("Chispazo"),
        .description = COMPOUND_STRING(
            "Descarga eléctrica que puede\n"
        "paralizar a los demás."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Discharge,
    },

    [MOVE_LAVA_PLUME] =
    {
        .name = COMPOUND_STRING("Humareda"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_LavaPlume,
    },

    [MOVE_LEAF_STORM] =
    {
        .name = COMPOUND_STRING("Lluevehojas"),
        .description = COMPOUND_STRING(
            "Tormenta de hojas; reduce mucho\n"
        "el Ataque Especial propio."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafStorm,
    },

    [MOVE_POWER_WHIP] =
    {
        .name = COMPOUND_STRING("Latigazo"),
        .description = COMPOUND_STRING(
            "Violento latigazo de zarcillos\n"
        "que castiga al rival."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PowerWhip,
    },

    [MOVE_ROCK_WRECKER] =
    {
        .name = COMPOUND_STRING("Romperrocas"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockWrecker,
    },

    [MOVE_CROSS_POISON] =
    {
        .name = COMPOUND_STRING("Veneno X"),
        .description = COMPOUND_STRING(
            "Corte en cruz; puede envenenar\n"
        "y tiene alto ratio crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrossPoison,
    },

    [MOVE_GUNK_SHOT] =
    {
        .name = COMPOUND_STRING("Lanzamugre"),
        .description = COMPOUND_STRING(
            "Lanza basura pestilente que\n"
        "puede envenenar al rival."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GunkShot,
    },

    [MOVE_IRON_HEAD] =
    {
        .name = COMPOUND_STRING("Cabeza de Hierro"),
        .description = COMPOUND_STRING(
            "Cabezazo de acero duro que\n"
        "puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronHead,
    },

    [MOVE_MAGNET_BOMB] =
    {
        .name = COMPOUND_STRING("Bomba Imán"),
        .description = COMPOUND_STRING(
            "Lanza un proyectil magnético\n"
        "que nunca puede fallar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetBomb,
    },

    [MOVE_STONE_EDGE] =
    {
        .name = COMPOUND_STRING("Roca Afilada"),
        .description = COMPOUND_STRING(
            "Apuñala con piedras afiladas;\n"
        "alta probabilidad de crítico."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_StoneEdge,
    },

    [MOVE_CAPTIVATE] =
    {
        .name = COMPOUND_STRING("Seducción"),
        .description = COMPOUND_STRING(
            "Seduce al género opuesto para\n"
        "bajar mucho su At. Esp."),
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Captivate,
    },

    [MOVE_STEALTH_ROCK] =
    {
        .name = COMPOUND_STRING("Trampa Rocas"),
        .description = COMPOUND_STRING(
            "Lanza rocas flotantes que dañan\n"
        "al rival al entrar."),
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK},
        .battleAnimScript = gBattleAnimMove_StealthRock,
    },

    [MOVE_GRASS_KNOT] =
    {
        .name = COMPOUND_STRING("Hierba Lazo"),
        .description = COMPOUND_STRING(
            "Lazo de hierba; hace más daño\n"
        "cuanto más pesado sea el rival."),
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassKnot,
    },

    [MOVE_CHATTER] =
    {
        .name = COMPOUND_STRING("Cháchara"),
        .description = COMPOUND_STRING(
            "Onda sonora estridente que\n"
        "provoca confusión segura."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .chance = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .chance = 10,
        #else
            .chance = 31,
        #endif
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Chatter,
    },

    [MOVE_JUDGMENT] =
    {
        .name = COMPOUND_STRING("Sentencia"),
        .description = COMPOUND_STRING(
            "Ataque cuyo tipo elemental varía\n"
        "según la tabla equipada."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_PLATE },
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Judgment,
    },

    [MOVE_BUG_BITE] =
    {
        .name = COMPOUND_STRING("Picadura"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBite,
    },

    [MOVE_CHARGE_BEAM] =
    {
        .name = COMPOUND_STRING("Rayo Carga"),
        .description = COMPOUND_STRING(
            "Rayo eléctrico que a menudo\n"
        "aumenta el Ataque Especial."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 70,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ChargeBeam,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .name = COMPOUND_STRING("Mazazo"),
        .description = COMPOUND_STRING(
            "Golpe demoledor de madera; causa\n"
        "daño de retroceso."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WoodHammer,
    },

    [MOVE_AQUA_JET] =
    {
        .name = COMPOUND_STRING("Acua Jet"),
        .description = COMPOUND_STRING(
            "Embestida acuática que ataca\n"
        "siempre en primer lugar."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaJet,
    },

    [MOVE_ATTACK_ORDER] =
    {
        .name = COMPOUND_STRING("Al Ataque"),
        .description = COMPOUND_STRING(
            "Ordena a los súbditos golpear;\n"
        "alto ratio de críticos."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ATTACK_ORDER,
        .contestComboMoves = {COMBO_STARTER_DEFEND_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_AttackOrder,
    },

    [MOVE_DEFEND_ORDER] =
    {
        .name = COMPOUND_STRING("A Defender"),
        .description = COMPOUND_STRING(
            "Crea un escudo de súbditos que\n"
        "sube Defensa y Def. Esp."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DEFEND_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_DefendOrder,
    },

    [MOVE_HEAL_ORDER] =
    {
        .name = COMPOUND_STRING("Auxilio"),
        .description = COMPOUND_STRING(
            "Los súbditos acuden a sanar\n"
        "la mitad de los PS máximos."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HEAL_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_DEFEND_ORDER},
        .battleAnimScript = gBattleAnimMove_HealOrder,
    },

    [MOVE_HEAD_SMASH] =
    {
        .name = COMPOUND_STRING("Testarazo"),
        .description = COMPOUND_STRING(
            "Cabezazo a vida o muerte con\n"
        "gran daño de retroceso."),
        .effect = EFFECT_RECOIL,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 50 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadSmash,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .name = COMPOUND_STRING("Doble Golpe"),
        .description = COMPOUND_STRING(
            "Golpea dos veces consecutivas\n"
        "con la cola o extremidades."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleHit,
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .name = COMPOUND_STRING("Distorsión"),
        .description = COMPOUND_STRING(
            "Ataque colosal; el usuario debe\n"
        "recargar el siguiente turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RoarOfTime,
    },

    [MOVE_SPACIAL_REND] =
    {
        .name = COMPOUND_STRING("Corte Vacío"),
        .description = COMPOUND_STRING(
            "Desgarra al rival y el espacio;\n"
        "alto ratio de críticos."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpacialRend,
    },

    [MOVE_LUNAR_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Lunar"),
        .description = sHealingWishDescription,
        .effect = EFFECT_LUNAR_DANCE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LunarDance,
    },

    [MOVE_CRUSH_GRIP] =
    {
        .name = COMPOUND_STRING("Agarrón"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrushGrip,
    },

    [MOVE_MAGMA_STORM] =
    {
        .name = COMPOUND_STRING("Lluvia Ígnea"),
        .description = COMPOUND_STRING(
            "Vórtice de magma ardiente que\n"
        "atrapa al rival varios turnos."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 120,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_MAGMA_STORM,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MagmaStorm,
    },

    [MOVE_DARK_VOID] =
    {
        .name = COMPOUND_STRING("Brecha Negra"),
        .description = COMPOUND_STRING(
            "Suma a los rivales en profunda\n"
        "oscuridad para dormirlos."),
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 80,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DARK_VOID,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkVoid,
    },

    [MOVE_SEED_FLARE] =
    {
        .name = COMPOUND_STRING("Fulgor Semilla"),
        .description = COMPOUND_STRING(
            "Onda de choque celestial que\n"
        "baja mucho la Def. Esp."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SeedFlare,
    },

    [MOVE_OMINOUS_WIND] =
    {
        .name = COMPOUND_STRING("Viento Aciago"),
        .description = COMPOUND_STRING(
            "Viento siniestro que puede\n"
        "subir todas las estadísticas."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OminousWind,
    },

    [MOVE_SHADOW_FORCE] =
    {
        .name = COMPOUND_STRING("Golpe Umbrío"),
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS == GEN_6,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowForce,
    },

    [MOVE_HONE_CLAWS] =
    {
        .name = COMPOUND_STRING("Afilagarras"),
        .description = COMPOUND_STRING(
            "El usuario se afila las\n"
        "garras para aumentar su\n"
        "Ataque y Precisión."),
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HONE_CLAWS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoneClaws,
    },

    [MOVE_WIDE_GUARD] =
    {
        .name = COMPOUND_STRING("Vasta Guardia"),
        .description = COMPOUND_STRING(
            "Bloquea los ataques de\n"
        "objetivo múltiple lanzados\n"
        "contra tu equipo durante"),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_WIDE_GUARD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WideGuard,
    },

    [MOVE_GUARD_SPLIT] =
    {
        .name = COMPOUND_STRING("Isoguardia"),
        .description = COMPOUND_STRING(
            "El usuario emplea sus\n"
        "poderes para hacer la\n"
        "media de su Defensa y"),
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSplit,
    },

    [MOVE_POWER_SPLIT] =
    {
        .name = COMPOUND_STRING("Isofuerza"),
        .description = COMPOUND_STRING(
            "El usuario emplea sus\n"
        "poderes para hacer la\n"
        "media de su Ataque y"),
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSplit,
    },

    [MOVE_WONDER_ROOM] =
    {
        .name = COMPOUND_STRING("Zona Extraña"),
        .description = COMPOUND_STRING(
            "Crea una zona misteriosa\n"
        "donde se intercambian la\n"
        "Defensa y la Defensa"),
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WonderRoom,
    },

    [MOVE_PSYSHOCK] =
    {
        .name = COMPOUND_STRING("Psicocarga"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psyshock,
    },

    [MOVE_VENOSHOCK] =
    {
        .name = COMPOUND_STRING("Carga Tóxica"),
        .description = COMPOUND_STRING(
            "Cubre al objetivo con un\n"
        "líquido venenoso. El daño\n"
        "será doble si este ya está"),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Venoshock,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .name = COMPOUND_STRING("Aligerar"),
        .description = COMPOUND_STRING(
            "El usuario se desprende de\n"
        "partes prescindibles de su\n"
        "cuerpo para hacerse más"),
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Autotomize,
    },

    [MOVE_RAGE_POWDER] =
    {
        .name = COMPOUND_STRING("Polvo Ira"),
        .description = COMPOUND_STRING(
            "Usa un polvo que irrita y\n"
        "centra en el usuario la\n"
        "atención y los ataques de"),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .powderMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagePowder,
    },

    [MOVE_TELEKINESIS] =
    {
        .name = COMPOUND_STRING("Telequinesis"),
        .description = COMPOUND_STRING(
            "El rival flota 3 turnos;\n"
        "más fácil de acertar."),
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Telekinesis,
    },

    [MOVE_MAGIC_ROOM] =
    {
        .name = COMPOUND_STRING("Zona Mágica"),
        .description = COMPOUND_STRING(
            "Crea un espacio misterioso\n"
        "que inutiliza todos los\n"
        "objetos de los Pokémon"),
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicRoom,
    },

    [MOVE_SMACK_DOWN] =
    {
        .name = COMPOUND_STRING("Antiaéreo"),
        .description = COMPOUND_STRING(
            "Ataca lanzando una piedra\n"
        "o un proyectil. Si el\n"
        "objetivo está en el aire,"),
        .effect = EFFECT_SMACK_DOWN,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SmackDown,
    },

    [MOVE_STORM_THROW] =
    {
        .name = COMPOUND_STRING("Llave Corsé"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_StormThrow,
    },

    [MOVE_FLAME_BURST] =
    {
        .name = COMPOUND_STRING("Pirotecnia"),
        .description = COMPOUND_STRING(
            "Llamarada explosiva que\n"
        "también daña a rivales cercanos."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLAME_BURST,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameBurst,
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .name = COMPOUND_STRING("Onda Tóxica"),
        .description = COMPOUND_STRING(
            "Una onda tóxica que daña a\n"
        "los Pokémon de alrededor.\n"
        "Puede envenenar."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SludgeWave,
    },

    [MOVE_QUIVER_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Aleteo"),
        .description = COMPOUND_STRING(
            "Danza mística que sube el\n"
        "Ataque Especial, la\n"
        "Defensa Especial y la"),
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuiverDance,
    },

    [MOVE_HEAVY_SLAM] =
    {
        .name = COMPOUND_STRING("Cuerpo Pesado"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeavySlam,
    },

    [MOVE_SYNCHRONOISE] =
    {
        .name = COMPOUND_STRING("Sincrorruido"),
        .description = COMPOUND_STRING(
            "Pulso extraño que solo daña\n"
        "a Pokémon del mismo tipo."),
        .effect = EFFECT_SYNCHRONOISE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Synchronoise,
    },

    [MOVE_ELECTRO_BALL] =
    {
        .name = COMPOUND_STRING("Bola Voltio"),
        .description = COMPOUND_STRING(
            "Lanza una bola eléctrica.\n"
        "Cuanto mayor sea la\n"
        "Velocidad del usuario en"),
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_CHARGE, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_ElectroBall,
    },

    [MOVE_SOAK] =
    {
        .name = COMPOUND_STRING("Empapar"),
        .description = COMPOUND_STRING(
            "Potente lluvia que\n"
        "transforma al objetivo en\n"
        "un Pokémon de tipo Agua."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_WATER },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Soak,
    },

    [MOVE_FLAME_CHARGE] =
    {
        .name = COMPOUND_STRING("Nitrocarga"),
        .description = COMPOUND_STRING(
            "Llamas que golpean al\n"
        "objetivo y aumentan la\n"
        "Velocidad del atacante."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameCharge,
    },

    [MOVE_COIL] =
    {
        .name = COMPOUND_STRING("Enrosque"),
        .description = COMPOUND_STRING(
            "El usuario se concentra,\n"
        "lo que le permite aumentar\n"
        "su Ataque, Defensa y"),
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coil,
    },

    [MOVE_LOW_SWEEP] =
    {
        .name = COMPOUND_STRING("Puntapié"),
        .description = COMPOUND_STRING(
            "Ataque rápido dirigido a\n"
        "los pies del objetivo que\n"
        "le hace perder Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowSweep,
    },

    [MOVE_ACID_SPRAY] =
    {
        .name = COMPOUND_STRING("Bomba Ácida"),
        .description = COMPOUND_STRING(
            "Ataca con un líquido\n"
        "corrosivo que reduce mucho\n"
        "la Defensa Especial del"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidSpray,
    },

    [MOVE_FOUL_PLAY] =
    {
        .name = COMPOUND_STRING("Juego Sucio"),
        .description = COMPOUND_STRING(
            "El usuario emplea la\n"
        "fuerza del objetivo para\n"
        "atacarlo. Cuanto mayor es"),
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FoulPlay,
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .name = COMPOUND_STRING("Onda Simple"),
        .description = COMPOUND_STRING(
            "Lanza una onda psíquica\n"
        "que hace que la habilidad\n"
        "del objetivo pase a ser"),
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_SIMPLE },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SimpleBeam,
    },

    [MOVE_ENTRAINMENT] =
    {
        .name = COMPOUND_STRING("Danza Amiga"),
        .description = COMPOUND_STRING(
            "Una extraña danza que hace\n"
        "que el usuario y el\n"
        "objetivo tengan la misma"),
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENTRAINMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Entrainment,
    },

    [MOVE_AFTER_YOU] =
    {
        .name = COMPOUND_STRING("Cede Paso"),
        .description = COMPOUND_STRING(
            "Si el usuario es el más\n"
        "rápido, permite al\n"
        "objetivo usar un"),
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AfterYou,
    },

    [MOVE_ROUND] =
    {
        .name = COMPOUND_STRING("Canon"),
        .description = COMPOUND_STRING(
            "Un canto que ataca al\n"
        "objetivo. Cuantos más\n"
        "Pokémon lo usan, más"),
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ROUND,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Round,
    },

    [MOVE_ECHOED_VOICE] =
    {
        .name = COMPOUND_STRING("Eco Voz"),
        .description = COMPOUND_STRING(
            "Un susurro que aumenta de\n"
        "potencia conforme el\n"
        "usuario y otros Pokémon lo"),
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EchoedVoice,
    },

    [MOVE_CHIP_AWAY] =
    {
        .name = COMPOUND_STRING("Guardia Baja"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChipAway,
    },

    [MOVE_CLEAR_SMOG] =
    {
        .name = COMPOUND_STRING("Niebla Clara"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo con una\n"
        "singular bola de lodo que\n"
        "elimina cualquier cambio"),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CLEAR_SMOG,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClearSmog,
    },

    [MOVE_STORED_POWER] =
    {
        .name = COMPOUND_STRING("Poder Reserva"),
        .description = COMPOUND_STRING(
            "Acumula poder para\n"
        "golpear. Cuanto más suban\n"
        "las características del"),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT},
        .battleAnimScript = gBattleAnimMove_StoredPower,
    },

    [MOVE_QUICK_GUARD] =
    {
        .name = COMPOUND_STRING("Anticipo"),
        .description = COMPOUND_STRING(
            "Se protege a sí mismo y a\n"
        "sus aliados de movimientos\n"
        "con prioridad."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_QUICK_GUARD, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuickGuard,
    },

    [MOVE_ALLY_SWITCH] =
    {
        .name = COMPOUND_STRING("Cambio de Banda"),
        .description = COMPOUND_STRING(
            "Extraño poder que\n"
        "intercambia la posición\n"
        "del usuario con la de un"),
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_7 ? 2 : 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AllySwitch,
    },

    [MOVE_SCALD] =
    {
        .name = COMPOUND_STRING("Escaldar"),
        .description = COMPOUND_STRING(
            "Ataca arrojando agua\n"
        "hirviendo al objetivo.\n"
        "Puede causar quemaduras."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCALD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Scald,
    },

    [MOVE_SHELL_SMASH] =
    {
        .name = COMPOUND_STRING("Rompecoraza"),
        .description = COMPOUND_STRING(
            "El usuario rompe su coraza\n"
        "y baja su Defensa y\n"
        "Defensa Especial, pero"),
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSmash,
    },

    [MOVE_HEAL_PULSE] =
    {
        .name = COMPOUND_STRING("Pulso Cura"),
        .description = COMPOUND_STRING(
            "Una onda curativa restaura\n"
        "la mitad de los PS máximos\n"
        "del objetivo."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealPulse,
    },

    [MOVE_HEX] =
    {
        .name = COMPOUND_STRING("Infortunio"),
        .description = COMPOUND_STRING(
            "Ataque que causa un gran\n"
        "daño a los objetivos que\n"
        "sufren problemas de"),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .argument = { .status = STATUS1_ANY },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_INFERNO, COMBO_STARTER_WILL_O_WISP, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_Hex,
    },

    [MOVE_SKY_DROP] =
    {
        .name = COMPOUND_STRING("Caída Libre"),
        .description = COMPOUND_STRING(
            "Lleva al rival al cielo y lo lanza\n"
        "al suelo el siguiente turno."),
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKTARGETHIGH, .status = STATE_ON_AIR },
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SkyDrop,
    },

    [MOVE_SHIFT_GEAR] =
    {
        .name = COMPOUND_STRING("Cambio de Marcha"),
        .description = COMPOUND_STRING(
            "Al hacer girar los\n"
        "engranajes, el usuario\n"
        "mejora su Ataque y aumenta"),
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SHIFT_GEAR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShiftGear,
    },

    [MOVE_CIRCLE_THROW] =
    {
        .name = COMPOUND_STRING("Llave Giro"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_CircleThrow,
    },

    [MOVE_INCINERATE] =
    {
        .name = COMPOUND_STRING("Calcinación"),
        .description = COMPOUND_STRING(
            "Llamas que golpean a los\n"
        "objetivos adyacentes. Si\n"
        "estos llevan bayas o"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 30,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INCINERATE,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Incinerate,
    },

    [MOVE_QUASH] =
    {
        .name = COMPOUND_STRING("Último Lugar"),
        .description = COMPOUND_STRING(
            "Consigue que el objetivo\n"
        "sea el último en moverse."),
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Quash,
    },

    [MOVE_ACROBATICS] =
    {
        .name = COMPOUND_STRING("Acróbata"),
        .description = COMPOUND_STRING(
            "Golpea ágilmente. Si el\n"
        "usuario no porta ningún\n"
        "objeto, el objetivo"),
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acrobatics,
    },

    [MOVE_REFLECT_TYPE] =
    {
        .name = COMPOUND_STRING("Clonatipo"),
        .description = COMPOUND_STRING(
            "Cambia el tipo del Pokémon\n"
        "al mismo tipo que el del\n"
        "objetivo."),
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ReflectType,
    },

    [MOVE_RETALIATE] =
    {
        .name = COMPOUND_STRING("Represalia"),
        .description = COMPOUND_STRING(
            "Venga a los amigos caídos.\n"
        "Si en el turno anterior\n"
        "han derrotado a alguno, la"),
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Retaliate,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .name = COMPOUND_STRING("Sacrificio"),
        .description = COMPOUND_STRING(
            "El usuario se sacrifica\n"
        "causándole un daño al\n"
        "objetivo equivalente a sus"),
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = B_UPDATED_MOVE_FLAGS <= GEN_5,
        .mirrorMoveBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FinalGambit,
    },

    [MOVE_BESTOW] =
    {
        .name = COMPOUND_STRING("Ofrenda"),
        .description = COMPOUND_STRING(
            "El usuario cede su objeto\n"
        "al rival."),
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Bestow,
    },

    [MOVE_INFERNO] =
    {
        .name = COMPOUND_STRING("Infierno"),
        .description = COMPOUND_STRING(
            "Ataca con una gran ráfaga\n"
        "de fuego que causa\n"
        "quemaduras."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_INFERNO,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Inferno,
    },

    [MOVE_WATER_PLEDGE] =
    {
        .name = COMPOUND_STRING("Voto Agua"),
        .description = COMPOUND_STRING(
            "Ataca con columnas de\n"
        "agua. Combinado con Voto\n"
        "Fuego, crea un arcoíris y"),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterPledge,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        .name = COMPOUND_STRING("Voto Fuego"),
        .description = COMPOUND_STRING(
            "Ataca con columnas de\n"
        "fuego. Combinado con Voto\n"
        "Planta, crea un mar de"),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirePledge,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        .name = COMPOUND_STRING("Voto Planta"),
        .description = COMPOUND_STRING(
            "Ataca con columnas de\n"
        "hojas. Combinado con Voto\n"
        "Agua, crea un pantano y"),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassPledge,
    },

    [MOVE_VOLT_SWITCH] =
    {
        .name = COMPOUND_STRING("Voltiocambio"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltSwitch,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        .name = COMPOUND_STRING("Estoicismo"),
        .description = COMPOUND_STRING(
            "El usuario opone\n"
        "resistencia y ataca a los\n"
        "oponentes. También reduce"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StruggleBug,
    },

    [MOVE_BULLDOZE] =
    {
        .name = COMPOUND_STRING("Terratemblor"),
        .description = COMPOUND_STRING(
            "Sacudida sísmica que\n"
        "afecta a los demás Pokémon\n"
        "adyacentes y también"),
        .effect = EFFECT_EARTHQUAKE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bulldoze,
    },

    [MOVE_FROST_BREATH] =
    {
        .name = COMPOUND_STRING("Vaho Gélido"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FrostBreath,
    },

    [MOVE_DRAGON_TAIL] =
    {
        .name = COMPOUND_STRING("Cola Dragón"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_DRAGON_TAIL,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_DragonTail,
    },

    [MOVE_WORK_UP] =
    {
        .name = COMPOUND_STRING("Avivar"),
        .description = COMPOUND_STRING(
            "Quien lo usa se concentra\n"
        "y potencia su Ataque y su\n"
        "Ataque Especial."),
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WorkUp,
    },

    [MOVE_ELECTROWEB] =
    {
        .name = COMPOUND_STRING("Electrotela"),
        .description = COMPOUND_STRING(
            "Atrapa y ataca a los\n"
        "objetivos con una telaraña\n"
        "eléctrica. También reduce"),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_Electroweb,
    },

    [MOVE_WILD_CHARGE] =
    {
        .name = COMPOUND_STRING("Voltio Cruel"),
        .description = COMPOUND_STRING(
            "Carga eléctrica muy\n"
        "potente que también hiere\n"
        "ligeramente a quien la"),
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WildCharge,
    },

    [MOVE_DRILL_RUN] =
    {
        .name = COMPOUND_STRING("Taladradora"),
        .description = COMPOUND_STRING(
            "El usuario golpea usando\n"
        "su cuerpo como un taladro.\n"
        "Suele ser crítico."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrillRun,
    },

    [MOVE_DUAL_CHOP] =
    {
        .name = COMPOUND_STRING("Golpe Bis"),
        .description = COMPOUND_STRING(
            "Golpea dos veces seguidas\n"
        "con las partes más recias\n"
        "de su cuerpo."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualChop,
    },

    [MOVE_HEART_STAMP] =
    {
        .name = COMPOUND_STRING("Arrumaco"),
        .description = COMPOUND_STRING(
            "Golpe sorpresa tras un gesto\n"
        "tierno. Puede amedrentar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartStamp,
    },

    [MOVE_HORN_LEECH] =
    {
        .name = COMPOUND_STRING("Asta Drenaje"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HornLeech,
    },

    [MOVE_SACRED_SWORD] =
    {
        .name = COMPOUND_STRING("Espada Santa"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SacredSword,
    },

    [MOVE_RAZOR_SHELL] =
    {
        .name = COMPOUND_STRING("Concha Filo"),
        .description = COMPOUND_STRING(
            "Una afilada vieira ataca\n"
        "al objetivo. También puede\n"
        "hacer disminuir su"),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorShell,
    },

    [MOVE_HEAT_CRASH] =
    {
        .name = COMPOUND_STRING("Golpe Calor"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeatCrash,
    },

    [MOVE_LEAF_TORNADO] =
    {
        .name = COMPOUND_STRING("Ciclón de Hojas"),
        .description = COMPOUND_STRING(
            "Tritura con afiladas hojas\n"
        "y puede bajar la Precisión\n"
        "del objetivo."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafTornado,
    },

    [MOVE_STEAMROLLER] =
    {
        .name = COMPOUND_STRING("Rodillo de Púas"),
        .description = COMPOUND_STRING(
            "Aplasta al rival con el cuerpo.\n"
        "Puede amedrentar."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Steamroller,
    },

    [MOVE_COTTON_GUARD] =
    {
        .name = COMPOUND_STRING("Rizo Algodón"),
        .description = COMPOUND_STRING(
            "Cubre al Pokémon con una\n"
        "madeja protectora. Aumenta\n"
        "muchísimo la Defensa."),
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonGuard,
    },

    [MOVE_NIGHT_DAZE] =
    {
        .name = COMPOUND_STRING("Pulso Noche"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo con una\n"
        "onda siniestra. Puede\n"
        "bajar su Precisión."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightDaze,
    },

    [MOVE_PSYSTRIKE] =
    {
        .name = COMPOUND_STRING("Onda Mental"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psystrike,
    },

    [MOVE_TAIL_SLAP] =
    {
        .name = COMPOUND_STRING("Plumerazo"),
        .description = COMPOUND_STRING(
            "Golpea con la cola de dos\n"
        "a cinco veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailSlap,
    },

    [MOVE_HURRICANE] =
    {
        .name = COMPOUND_STRING("Vendaval"),
        .description = COMPOUND_STRING(
            "Golpea al objetivo con un\n"
        "fuerte torbellino que\n"
        "envuelve al rival y puede"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .damagesAirborne = TRUE,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Hurricane,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .name = COMPOUND_STRING("Ariete"),
        .description = COMPOUND_STRING(
            "Propina un tremendo\n"
        "cabezazo. También daña al\n"
        "usuario un poco."),
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadCharge,
    },

    [MOVE_GEAR_GRIND] =
    {
        .name = COMPOUND_STRING("Rueda Doble"),
        .description = COMPOUND_STRING(
            "Rota dos engranajes de\n"
        "hierro sobre el objetivo.\n"
        "Golpea dos veces."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 180 },
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SHIFT_GEAR},
        .battleAnimScript = gBattleAnimMove_GearGrind,
    },

    [MOVE_SEARING_SHOT] =
    {
        .name = COMPOUND_STRING("Bomba Ígnea"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SearingShot,
    },

    [MOVE_TECHNO_BLAST] =
    {
        .name = COMPOUND_STRING("Tecno Shock"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo con un\n"
        "gran láser. El tipo del\n"
        "ataque lo determina el"),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_DRIVE },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TechnoBlast,
    },

    [MOVE_RELIC_SONG] =
    {
        .name = COMPOUND_STRING("Canto Arcaico"),
        .description = COMPOUND_STRING(
            "Ataca conmoviendo a los\n"
        "rivales de alrededor con\n"
        "un antiguo canto. Puede"),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_SLEEP },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RelicSong,
    },

    [MOVE_SECRET_SWORD] =
    {
        .name = COMPOUND_STRING("Sable Místico"),
        .description = COMPOUND_STRING(
            "Ensarta al objetivo con un\n"
        "largo cuerno dotado de un\n"
        "poder místico que provoca"),
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretSword,
    },

    [MOVE_GLACIATE] =
    {
        .name = COMPOUND_STRING("Mundo Gélido"),
        .description = COMPOUND_STRING(
            "Ataque con aire helado que\n"
        "baja la Velocidad del\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Glaciate,
    },

    [MOVE_BOLT_STRIKE] =
    {
        .name = COMPOUND_STRING("Ataque Fulgor"),
        .description = COMPOUND_STRING(
            "Ataca envolviéndose de una\n"
        "gran carga eléctrica y\n"
        "embistiendo al objetivo"),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltStrike,
    },

    [MOVE_BLUE_FLARE] =
    {
        .name = COMPOUND_STRING("Llama Azul"),
        .description = COMPOUND_STRING(
            "Ataca con una bella pero\n"
        "potente llama azul que\n"
        "rodea al objetivo. Puede"),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BlueFlare,
    },

    [MOVE_FIERY_DANCE] =
    {
        .name = COMPOUND_STRING("Danza Llama"),
        .description = COMPOUND_STRING(
            "Envuelve en llamas y daña\n"
        "al objetivo. Puede\n"
        "aumentar el Ataque"),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryDance,
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .name = COMPOUND_STRING("Rayo Gélido"),
        .description = COMPOUND_STRING(
            "El usuario carga un bloque\n"
        "de hielo con electricidad\n"
        "en el primer turno y ataca"),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeShock,
    },

    [MOVE_ICE_BURN] =
    {
        .name = COMPOUND_STRING("Llama Gélida"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo en el\n"
        "segundo turno rodeándolo\n"
        "de un aire gélido. Puede"),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceBurn,
    },

    [MOVE_SNARL] =
    {
        .name = COMPOUND_STRING("Alarido"),
        .description = COMPOUND_STRING(
            "Chillido desagradable que\n"
        "baja el Ataque Especial\n"
        "del rival."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snarl,
    },

    [MOVE_ICICLE_CRASH] =
    {
        .name = COMPOUND_STRING("Chuzos"),
        .description = COMPOUND_STRING(
            "Lanza grandes carámbanos.\n"
        "Puede amedrentar al\n"
        "objetivo."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcicleCrash,
    },

    [MOVE_V_CREATE] =
    {
        .name = COMPOUND_STRING("V de Fuego"),
        .description = COMPOUND_STRING(
            "Golpea con una V de llamas\n"
        "al objetivo. Baja la\n"
        "Defensa, la Defensa"),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 220 },
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_V_CREATE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VCreate,
    },

    [MOVE_FUSION_FLARE] =
    {
        .name = COMPOUND_STRING("Llama Fusión"),
        .description = COMPOUND_STRING(
            "Ataca con una llamarada\n"
        "gigantesca. Aumenta su\n"
        "potencia si es"),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionFlare,
    },

    [MOVE_FUSION_BOLT] =
    {
        .name = COMPOUND_STRING("Rayo Fusión"),
        .description = COMPOUND_STRING(
            "Ataca con una enorme\n"
        "descarga eléctrica.\n"
        "Aumenta su potencia si es"),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionBolt,
    },

    [MOVE_FLYING_PRESS] =
    {
        .name = COMPOUND_STRING("Plancha Voladora"),
        .description = COMPOUND_STRING(
            "El Pokémon que lo usa se\n"
        "lanza sobre su oponente.\n"
        "Este movimiento es de tipo"),
        .effect = EFFECT_TWO_TYPED_MOVE,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 100 : 80,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 170 },
        .argument = { .type = TYPE_FLYING },
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .gravityBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlyingPress,
    },

    [MOVE_MAT_BLOCK] =
    {
        .name = COMPOUND_STRING("Escudo Tatami"),
        .description = COMPOUND_STRING(
            "El usuario usa un tatami\n"
        "para escudarse de los\n"
        "ataques enemigos. Protege"),
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAT_BLOCK, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MatBlock,
    },

    [MOVE_BELCH] =
    {
        .name = COMPOUND_STRING("Eructo"),
        .description = COMPOUND_STRING(
            "El Pokémon causa daño a su\n"
        "oponente lanzándole un\n"
        "eructo. Para poder"),
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Belch,
    },

    [MOVE_ROTOTILLER] =
    {
        .name = COMPOUND_STRING("Fertilizante"),
        .description = COMPOUND_STRING(
            "Cultiva el terreno subiendo el\n"
        "Ataque de tipo Planta."),
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROTOTILLER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rototiller,
    },

    [MOVE_STICKY_WEB] =
    {
        .name = COMPOUND_STRING("Red Viscosa"),
        .description = COMPOUND_STRING(
            "Coloca una red pegajosa\n"
        "alrededor del equipo rival\n"
        "que baja la Velocidad de"),
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_StickyWeb,
    },

    [MOVE_FELL_STINGER] =
    {
        .name = COMPOUND_STRING("Aguijón Letal"),
        .description = COMPOUND_STRING(
            "Si se derrota al objetivo\n"
        "utilizando este\n"
        "movimiento, aumenta"),
        .effect = EFFECT_FELL_STINGER,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FellStinger,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .name = COMPOUND_STRING("Golpe Fantasma"),
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_7,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhantomForce,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .name = COMPOUND_STRING("Halloween"),
        .description = COMPOUND_STRING(
            "Invita al objetivo a\n"
        "celebrar Halloween, lo que\n"
        "añade el tipo Fantasma a"),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GHOST },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickOrTreat,
    },

    [MOVE_NOBLE_ROAR] =
    {
        .name = COMPOUND_STRING("Rugido de Guerra"),
        .description = COMPOUND_STRING(
            "Intimida a su oponente con\n"
        "un rugido de guerra, lo\n"
        "que hace que disminuyan"),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NobleRoar,
    },

    [MOVE_ION_DELUGE] =
    {
        .name = COMPOUND_STRING("Cortina Plasma"),
        .description = COMPOUND_STRING(
            "Electrifica los movimientos\n"
        "Normales con átomos cargados."),
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_FIELD,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IonDeluge,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        .name = COMPOUND_STRING("Carga Parábola"),
        .description = COMPOUND_STRING(
            "Inflige daño a todos los\n"
        "Pokémon a su alrededor. El\n"
        "usuario absorbe la mitad"),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 65 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PARABOLIC_CHARGE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ParabolicCharge,
    },

    [MOVE_FORESTS_CURSE] =
    {
        .name = COMPOUND_STRING("Condena Silvana"),
        .description = COMPOUND_STRING(
            "El objetivo es presa de la\n"
        "maldición del bosque, por\n"
        "lo que pasa a ser un"),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GRASS },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForestsCurse,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .name = COMPOUND_STRING("Tormenta Floral"),
        .description = COMPOUND_STRING(
            "El usuario desata un\n"
        "intenso vendaval de\n"
        "pétalos que daña a los"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PetalBlizzard,
    },

    [MOVE_FREEZE_DRY] =
    {
        .name = COMPOUND_STRING("Liofilización"),
        .description = COMPOUND_STRING(
            "Super effective on Water-\n"
        #if B_USE_FROSTBITE == TRUE
            "types. May cause frostbite."),
        #else
            "types. May cause freezing."),
        #endif
        .effect = EFFECT_SUPER_EFFECTIVE_ON_ARG,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .type = TYPE_WATER },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeDry,
    },

    [MOVE_DISARMING_VOICE] =
    {
        .name = COMPOUND_STRING("Voz Cautivadora"),
        .description = COMPOUND_STRING(
            "Obnubila a los oponentes\n"
        "con su fascinante voz y\n"
        "les provoca daños"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DisarmingVoice,
    },

    [MOVE_PARTING_SHOT] =
    {
        .name = COMPOUND_STRING("Última Palabra"),
        .description = COMPOUND_STRING(
            "El usuario se cambia por\n"
        "otro Pokémon de su equipo,\n"
        "pero antes amedrenta a su"),
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PartingShot,
    },

    [MOVE_TOPSY_TURVY] =
    {
        .name = COMPOUND_STRING("Reversión"),
        .description = COMPOUND_STRING(
            "Invierte por completo los\n"
        "cambios en las\n"
        "características del"),
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TopsyTurvy,
    },

    [MOVE_DRAINING_KISS] =
    {
        .name = COMPOUND_STRING("Beso Drenaje"),
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrainingKiss,
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .name = COMPOUND_STRING("Truco Defensa"),
        .description = COMPOUND_STRING(
            "Usa unos misteriosos\n"
        "poderes para protegerse a\n"
        "sí mismo y a sus aliados"),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_CRAFTY_SHIELD },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CraftyShield,
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .name = COMPOUND_STRING("Defensa Floral"),
        .description = COMPOUND_STRING(
            "Aumenta la Defensa de\n"
        "todos los Pokémon de tipo\n"
        "Planta que hay en el"),
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlowerShield,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .name = COMPOUND_STRING("Campo de Hierba"),
        .description = COMPOUND_STRING(
            "Durante cinco turnos, se\n"
        "potencian los movimientos\n"
        "de tipo Planta y los"),
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GRASSY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassyTerrain,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .name = COMPOUND_STRING("Campo de Niebla"),
        .description = COMPOUND_STRING(
            "Durante cinco turnos, los\n"
        "Pokémon que están en el\n"
        "suelo no sufren problemas"),
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MISTY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MistyTerrain,
    },

    [MOVE_ELECTRIFY] =
    {
        .name = COMPOUND_STRING("Electrificación"),
        .description = COMPOUND_STRING(
            "Si el objetivo queda\n"
        "electrificado antes de\n"
        "usar un movimiento, este"),
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PARABOLIC_CHARGE},
        .battleAnimScript = gBattleAnimMove_Electrify,
    },

    [MOVE_PLAY_ROUGH] =
    {
        .name = COMPOUND_STRING("Carantoña"),
        .description = COMPOUND_STRING(
            "El Pokémon que lo usa le\n"
        "hace cucamonas al objetivo\n"
        "y lo ataca. Puede"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayRough,
    },

    [MOVE_FAIRY_WIND] =
    {
        .name = COMPOUND_STRING("Viento Feérico"),
        .description = COMPOUND_STRING(
            "El Pokémon que lo usa\n"
        "desata un vendaval feérico\n"
        "que arremete contra el"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyWind,
    },

    [MOVE_MOONBLAST] =
    {
        .name = COMPOUND_STRING("Fuerza Lunar"),
        .description = COMPOUND_STRING(
            "Invoca el poder de la luna\n"
        "para atacar al objetivo.\n"
        "Puede disminuir el Ataque"),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Moonblast,
    },

    [MOVE_BOOMBURST] =
    {
        .name = COMPOUND_STRING("Estruendo"),
        .description = COMPOUND_STRING(
            "Ataca a todos los Pokémon\n"
        "a su alrededor con una\n"
        "potentísima onda sonora."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Boomburst,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .name = COMPOUND_STRING("Cerrojo Feérico"),
        .description = COMPOUND_STRING(
            "Consigue que ningún\n"
        "Pokémon pueda huir en el\n"
        "siguiente turno echando un"),
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyLock,
    },

    [MOVE_KINGS_SHIELD] =
    {
        .name = COMPOUND_STRING("Escudo Real"),
        .description = COMPOUND_STRING(
            "El usuario adopta una\n"
        "postura defensiva y se\n"
        "protege de cualquier daño."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_KINGS_SHIELD },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_KingsShield,
    },

    [MOVE_PLAY_NICE] =
    {
        .name = COMPOUND_STRING("Camaradería"),
        .description = COMPOUND_STRING(
            "Se hace amigo de su\n"
        "oponente y consigue que a\n"
        "este se le quiten las"),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_PLAY_NICE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayNice,
    },

    [MOVE_CONFIDE] =
    {
        .name = COMPOUND_STRING("Confidencia"),
        .description = COMPOUND_STRING(
            "Hace que el objetivo\n"
        "pierda la concentración\n"
        "contándole un secreto."),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Confide,
    },

    [MOVE_DIAMOND_STORM] =
    {
        .name = COMPOUND_STRING("Tormenta de Diamantes"),
        .description = COMPOUND_STRING(
            "Desata un devastador\n"
        "vendaval de diamantes para\n"
        "dañar a los oponentes."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_7 ? MOVE_EFFECT_DEF_PLUS_2:  MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DiamondStorm,
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .name = COMPOUND_STRING("Chorro de Vapor"),
        .description = COMPOUND_STRING(
            "Envuelve al Pokémon\n"
        "oponente con vapor\n"
        "extremadamente caliente"),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SteamEruption,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .name = COMPOUND_STRING("Paso Dimensional"),
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_HOLE,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_FURY},
        .battleAnimScript = gBattleAnimMove_HyperspaceHole,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        .name = COMPOUND_STRING("Shuriken de Agua"),
        .description = COMPOUND_STRING(
            "Golpea al oponente de dos\n"
        "a cinco veces con\n"
        "estrellas arrojadizas"),
        .effect = EFFECT_SPECIES_POWER_OVERRIDE,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = B_UPDATED_MOVE_DATA >= GEN_7 ? DAMAGE_CATEGORY_SPECIAL : DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .speciesPowerOverride.species = SPECIES_GRENINJA_ASH,
            .speciesPowerOverride.power = 20,
            .speciesPowerOverride.numOfHits = 3
        },
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterShuriken,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        .name = COMPOUND_STRING("Llama Embrujada"),
        .description = COMPOUND_STRING(
            "El usuario lanza por la\n"
        "boca una singular llama a\n"
        "gran temperatura con la"),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 75 : 65,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MysticalFire,
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .name = COMPOUND_STRING("Barrera Espinosa"),
        .description = COMPOUND_STRING(
            "Protege al usuario de\n"
        "ataques, e inflige daño a\n"
        "quien se los lance si"),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SPIKY_SHIELD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikyShield,
    },

    [MOVE_AROMATIC_MIST] =
    {
        .name = COMPOUND_STRING("Niebla Aromática"),
        .description = COMPOUND_STRING(
            "Consigue aumentar la\n"
        "Defensa Especial de un\n"
        "Pokémon de su equipo con"),
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AromaticMist,
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .name = COMPOUND_STRING("Onda Anómala"),
        .description = COMPOUND_STRING(
            "El usuario irradia unas\n"
        "raras ondas que, al\n"
        "alcanzar a un oponente,"),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EerieImpulse,
    },

    [MOVE_VENOM_DRENCH] =
    {
        .name = COMPOUND_STRING("Trampa Venenosa"),
        .description = COMPOUND_STRING(
            "Impregna a su objetivo con\n"
        "un líquido venenoso que\n"
        "disminuye el Ataque, el"),
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_VenomDrench,
    },

    [MOVE_POWDER] =
    {
        .name = COMPOUND_STRING("Polvo Explosivo"),
        .description = COMPOUND_STRING(
            "Esparce un polvo sobre el\n"
        "objetivo. Si este usa un\n"
        "movimiento de tipo Fuego"),
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .powderMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Powder,
    },

    [MOVE_GEOMANCY] =
    {
        .name = COMPOUND_STRING("Geocontrol"),
        .description = COMPOUND_STRING(
            "Concentra energía durante\n"
        "el primer turno, de forma\n"
        "que su Velocidad, Ataque"),
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKNMABSORBINGPOWER },
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Geomancy,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .name = COMPOUND_STRING("Aura Magnética"),
        .description = COMPOUND_STRING(
            "Manipula el campo\n"
        "magnético y logra aumentar\n"
        "la Defensa y la Defensa"),
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagneticFlux,
    },

    [MOVE_HAPPY_HOUR] =
    {
        .name = COMPOUND_STRING("Paga Extra"),
        .description = COMPOUND_STRING(
            "Al usar este movimiento se\n"
        "consigue duplicar la\n"
        "recompensa recibida tras"),
        .effect = EFFECT_HAPPY_HOUR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HAPPY_HOUR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HappyHour,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .name = COMPOUND_STRING("Campo Eléctrico"),
        .description = COMPOUND_STRING(
            "Durante cinco turnos, se\n"
        "potencian los movimientos\n"
        "de tipo Eléctrico y los"),
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ELECTRIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ElectricTerrain,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .name = COMPOUND_STRING("Brillo Mágico"),
        .description = COMPOUND_STRING(
            "Inflige daño a los\n"
        "oponentes con una potente\n"
        "luz."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DazzlingGleam,
    },

    [MOVE_CELEBRATE] =
    {
        .name = COMPOUND_STRING("Celebración"),
        .description = COMPOUND_STRING(
            "El Pokémon te felicita en\n"
        "un día muy especial para\n"
        "ti."),
        .effect = EFFECT_CELEBRATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CELEBRATE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Celebrate,
    },

    [MOVE_HOLD_HANDS] =
    {
        .name = COMPOUND_STRING("Manos Juntas"),
        .description = COMPOUND_STRING(
            "El Pokémon le da la mano a\n"
        "un aliado y ambos se\n"
        "sienten muy felices."),
        .effect = EFFECT_HOLD_HANDS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldHands,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .name = COMPOUND_STRING("Ojitos Tiernos"),
        .description = COMPOUND_STRING(
            "Lanza una mirada al\n"
        "objetivo con ojos\n"
        "acaramelados, con lo que"),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BabyDollEyes,
    },

    [MOVE_NUZZLE] =
    {
        .name = COMPOUND_STRING("Moflete Estático"),
        .description = COMPOUND_STRING(
            "Quien lo usa frota sus\n"
        "mofletes cargados de\n"
        "electricidad contra el"),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Nuzzle,
    },

    [MOVE_HOLD_BACK] =
    {
        .name = COMPOUND_STRING("Clemencia"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldBack,
    },

    [MOVE_INFESTATION] =
    {
        .name = COMPOUND_STRING("Acoso"),
        .description = COMPOUND_STRING(
            "Hostiga al objetivo\n"
        "durante cuatro o cinco\n"
        "turnos e impide que pueda"),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_INFESTATION,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Infestation,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .name = COMPOUND_STRING("Puño Incremento"),
        .description = COMPOUND_STRING(
            "Cada vez que golpea a un\n"
        "oponente se endurecen sus\n"
        "puños. Si acierta al"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerUpPunch,
    },

    [MOVE_OBLIVION_WING] =
    {
        .name = COMPOUND_STRING("Ala Mortífera"),
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OblivionWing,
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .name = COMPOUND_STRING("Mil Flechas"),
        .description = COMPOUND_STRING(
            "Acierta incluso a Pokémon\n"
        "que estén en el aire y los\n"
        "hace caer al suelo."),
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .ignoreTypeIfFlyingAndUngrounded = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_ARROWS,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_WAVES},
        .battleAnimScript = gBattleAnimMove_ThousandArrows,
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .name = COMPOUND_STRING("Mil Temblores"),
        .description = COMPOUND_STRING(
            "El usuario genera ondas\n"
        "sísmicas que se propagan\n"
        "por el suelo y sacuden a"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_WAVES,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_ARROWS},
        .battleAnimScript = gBattleAnimMove_ThousandWaves,
    },

    [MOVE_LANDS_WRATH] =
    {
        .name = COMPOUND_STRING("Fuerza Telúrica"),
        .description = COMPOUND_STRING(
            "Acumula energía de la\n"
        "corteza terrestre y la\n"
        "concentra contra los"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LandsWrath,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
        .name = COMPOUND_STRING("Luz Aniquiladora"),
        .description = COMPOUND_STRING(
            "El usuario emplea el poder\n"
        "de la Flor Eterna para\n"
        "lanzar un potente rayo de"),
        .effect = EFFECT_RECOIL,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .recoilPercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LightOfRuin,
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .name = COMPOUND_STRING("Pulso Primigenio"),
        .description = COMPOUND_STRING(
            "Ataca al objetivo con una\n"
        "infinidad de rayos de luz\n"
        "azulada."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OriginPulse,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .name = COMPOUND_STRING("Filo del Abismo"),
        .description = COMPOUND_STRING(
            "Hace que el poder latente\n"
        "de la tierra se manifieste\n"
        "en forma de hojas afiladas"),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrecipiceBlades,
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .name = COMPOUND_STRING("Ascenso Draco"),
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonAscent,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .name = COMPOUND_STRING("Cerco Dimensión"),
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT, // TODO: Is this supposed to happen before the attack animation?
        },
        {
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_FURY,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_HOLE},
        .battleAnimScript = gBattleAnimMove_HyperspaceFury,
    },

    [MOVE_SHORE_UP] =
    {
        .name = COMPOUND_STRING("Carrera Arrolladora"),
        .description = COMPOUND_STRING(
            "Restaura PS propios.\n"
        "Más PS recuperados en tormenta."),
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_ShoreUp,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .name = COMPOUND_STRING("Carrera Arrolladora"),
        .description = COMPOUND_STRING(
            "Golpe fuerte y prioritario\n"
        "solo en el primer turno."),
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .moveProperty = MOVE_FIRST_IMPRESSION },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirstImpression,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .name = COMPOUND_STRING("Ráfaga Demoledora"),
        .description = COMPOUND_STRING(
            "Se protege y envenena a quien\n"
        "haga contacto con el usuario."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BANEFUL_BUNKER },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BanefulBunker,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .name = COMPOUND_STRING("Ráfaga Demoledora"),
        .description = COMPOUND_STRING(
            "Tras ser golpeado, los rivales\n"
        "no pueden escapar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritShackle,
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .name = COMPOUND_STRING("Picado Supersónico"),
        .description = COMPOUND_STRING(
            "Gira los brazos para atacar.\n"
        "Ignora los cambios de stats."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkestLariat,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .name = COMPOUND_STRING("Picado Supersónico"),
        .description = COMPOUND_STRING(
            "Canta con burbujas.\n"
        "Cura las quemaduras al contacto."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_BURN },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
            .sheerForceOverride = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SparklingAria,
    },

    [MOVE_ICE_HAMMER] =
    {
        .name = COMPOUND_STRING("Diluvio Corrosivo"),
        .description = COMPOUND_STRING(
            "Golpe con el puño que baja\n"
        "la propia Velocidad."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceHammer,
    },

    [MOVE_FLORAL_HEALING] =
    {
        .name = COMPOUND_STRING("Diluvio Corrosivo"),
        .description = COMPOUND_STRING(
            "Restaura PS de un aliado.\n"
        "Cura más en terreno de hierba."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .argument = { .moveProperty = MOVE_EFFECT_FLORAL_HEALING },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FloralHealing,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .name = COMPOUND_STRING("Barrena Telúrica"),
        .description = COMPOUND_STRING(
            "Embiste al rival con todo\n"
        "el cuerpo con gran fuerza."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HighHorsepower,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .name = COMPOUND_STRING("Barrena Telúrica"),
        .description = COMPOUND_STRING(
            "Drena el Ataque rival para\n"
        "curar PS y baja su Ataque."),
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrengthSap,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .name = COMPOUND_STRING("Aplastamiento Gigalítico"),
        .description = COMPOUND_STRING(
            "Carga el primer turno y corta\n"
        "con hoja de luz solar el segundo."),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBlade,
    },

    [MOVE_LEAFAGE] =
    {
        .name = COMPOUND_STRING("Aplastamiento Gigalítico"),
        .description = COMPOUND_STRING(
            "Ataca con una ráfaga de\n"
        "pequeñas hojas."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Leafage,
    },

    [MOVE_SPOTLIGHT] =
    {
        .name = COMPOUND_STRING("Guadaña Sedosa"),
        .description = COMPOUND_STRING(
            "Fuerza al rival a atacar\n"
        "al Pokémon iluminado."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spotlight,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .name = COMPOUND_STRING("Guadaña Sedosa"),
        .description = COMPOUND_STRING(
            "Ataque con hilo que envenena\n"
        "y baja la Velocidad del rival."),
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
        .battleAnimScript = gBattleAnimMove_ToxicThread,
    },

    [MOVE_LASER_FOCUS] =
    {
        .name = COMPOUND_STRING("Presa Espectral"),
        .description = COMPOUND_STRING(
            "Garantiza que el siguiente\n"
        "movimiento sea un crítico."),
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LaserFocus,
    },

    [MOVE_GEAR_UP] =
    {
        .name = COMPOUND_STRING("Presa Espectral"),
        .description = COMPOUND_STRING(
            "Sube el Ataque de quienes\n"
        "tengan Más o Menos."),
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GearUp,
    },

    [MOVE_THROAT_CHOP] =
    {
        .name = COMPOUND_STRING("Hélice Trepanadora"),
        .description = COMPOUND_STRING(
            "Golpe en la garganta que\n"
        "impide usar sonidos 2 turnos."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THROAT_CHOP,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThroatChop,
    },

    [MOVE_POLLEN_PUFF] =
    {
        .name = COMPOUND_STRING("Hélice Trepanadora"),
        .description = COMPOUND_STRING(
            "Explota contra rivales, pero\n"
        "restaurans los PS de aliados."),
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PollenPuff,
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .name = COMPOUND_STRING("Hecatombe Pírica"),
        .description = COMPOUND_STRING(
            "Atrapa al rival con una cadena.\n"
        "El rival no puede escapar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AnchorShot,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .name = COMPOUND_STRING("Hecatombe Pírica"),
        .description = COMPOUND_STRING(
            "El terreno se vuelve psíquico\n"
        "5 turnos; bloquea prioridad."),
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicTerrain,
    },

    [MOVE_LUNGE] =
    {
        .name = COMPOUND_STRING("Hidrovórtice Abisal"),
        .description = COMPOUND_STRING(
            "Se lanza contra el rival\n"
        "bajando su Ataque."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lunge,
    },

    [MOVE_FIRE_LASH] =
    {
        .name = COMPOUND_STRING("Hidrovórtice Abisal"),
        .description = COMPOUND_STRING(
            "Fustigada de fuego que baja\n"
        "la Defensa del rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireLash,
    },

    [MOVE_POWER_TRIP] =
    {
        .name = COMPOUND_STRING("Megatón Floral"),
        .description = COMPOUND_STRING(
            "Más potente cuantas más mejoras\n"
        "de stats tenga el usuario."),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrip,
    },

    [MOVE_BURN_UP] =
    {
        .name = COMPOUND_STRING("Megatón Floral"),
        .description = COMPOUND_STRING(
            "Quema completamente al usuario,\n"
        "perdiendo el tipo Fuego."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .argument = { .type = TYPE_FIRE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BurnUp,
    },

    [MOVE_SPEED_SWAP] =
    {
        .name = COMPOUND_STRING("Gigavoltio Destructor"),
        .description = COMPOUND_STRING(
            "Intercambia la Velocidad\n"
        "del usuario con la del rival."),
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpeedSwap,
    },

    [MOVE_SMART_STRIKE] =
    {
        .name = COMPOUND_STRING("Gigavoltio Destructor"),
        .description = COMPOUND_STRING(
            "Ataca con un cuerno preciso\n"
        "que nunca puede fallar."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SmartStrike,
    },

    [MOVE_PURIFY] =
    {
        .name = COMPOUND_STRING("Disruptor Psíquico"),
        .description = COMPOUND_STRING(
            "Cura el estado del rival\n"
        "para recuperar PS propios."),
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Purify,
    },

    [MOVE_REVELATION_DANCE] =
    {
        .name = COMPOUND_STRING("Disruptor Psíquico"),
        .description = COMPOUND_STRING(
            "Baile místico; el tipo varía\n"
        "según el primero del usuario."),
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RevelationDance,
    },

    [MOVE_CORE_ENFORCER] =
    {
        .name = COMPOUND_STRING("Crioaliento Despiadado"),
        .description = COMPOUND_STRING(
            "Rayo que anula la habilidad\n"
        "del rival si atacó primero."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 140 },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CORE_ENFORCER,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CoreEnforcer,
    },

    [MOVE_TROP_KICK] =
    {
        .name = COMPOUND_STRING("Crioaliento Despiadado"),
        .description = COMPOUND_STRING(
            "Patada tropical intensa que\n"
        "baja el Ataque del rival."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TropKick,
    },

    [MOVE_INSTRUCT] =
    {
        .name = COMPOUND_STRING("Dracoaliento Devastador"),
        .description = COMPOUND_STRING(
            "Ordena al objetivo usar de\n"
        "nuevo su último movimiento."),
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Instruct,
    },

    [MOVE_BEAK_BLAST] =
    {
        .name = COMPOUND_STRING("Dracoaliento Devastador"),
        .description = COMPOUND_STRING(
            "Calienta el pico para atacar.\n"
        "Quema si hay contacto."),
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .ballisticMove = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeakBlast,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .name = COMPOUND_STRING("Agujero Negro Aniquilador"),
        .description = COMPOUND_STRING(
            "Ruido de escamas potente\n"
        "que baja la Defensa propia."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangingScales,
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .name = COMPOUND_STRING("Agujero Negro Aniquilador"),
        .description = COMPOUND_STRING(
            "Usa todo el cuerpo como\n"
        "un martillo para golpear."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonHammer,
    },

    [MOVE_BRUTAL_SWING] =
    {
        .name = COMPOUND_STRING("Arrumaco Sideral"),
        .description = COMPOUND_STRING(
            "Gira violentamente para\n"
        "golpear a todos los cercanos."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BrutalSwing,
    },

    [MOVE_AURORA_VEIL] =
    {
        .name = COMPOUND_STRING("Arrumaco Sideral"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
            "Debilita todos los ataques,\n"
        "pero solo usable con nieve."),
        #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_BOTH
        .description = COMPOUND_STRING(
            "Debilita todos los ataques,\n"
        "pero solo usable con nieve."),
        #else
        .description = COMPOUND_STRING(
            "Debilita todos los ataques,\n"
        "pero solo usable con nieve."),
        #endif
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraVeil,
    },

    [MOVE_SHELL_TRAP] =
    {
        .name = COMPOUND_STRING("Pikavoltio Letal"),
        .description = COMPOUND_STRING(
            "Prepara una trampa en la\n"
        "concha; daña al que contacte."),
        .effect = EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = -3,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellTrap,
    },

    [MOVE_FLEUR_CANNON] =
    {
        .name = COMPOUND_STRING("Recogearena"),
        .description = COMPOUND_STRING(
            "Restaura la mitad de los\n"
        "PS máximos del usuario.\n"
        "Durante las tormentas de"),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FleurCannon,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .name = COMPOUND_STRING("Escaramuza"),
        .description = COMPOUND_STRING(
            "Movimiento de gran\n"
        "potencia que solo puede\n"
        "usarse en el turno en que"),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicFangs,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .name = COMPOUND_STRING("Búnker"),
        .description = COMPOUND_STRING(
            "Protege de los ataques y,\n"
        "al mismo tiempo, envenena\n"
        "al Pokémon que use un"),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StompingTantrum,
    },

    [MOVE_SHADOW_BONE] =
    {
        .name = COMPOUND_STRING("Puntada Sombría"),
        .description = COMPOUND_STRING(
            "Ataca al oponente y, al\n"
        "mismo tiempo, fija su\n"
        "sombra al terreno para"),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SHADOW_BONE,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
        .battleAnimScript = gBattleAnimMove_ShadowBone,
    },

    [MOVE_ACCELEROCK] =
    {
        .name = COMPOUND_STRING("Lariat Oscuro"),
        .description = COMPOUND_STRING(
            "Gira sobre sí mismo y\n"
        "golpea al oponente con\n"
        "ambos brazos. Ignora los"),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Accelerock,
    },

    [MOVE_LIQUIDATION] =
    {
        .name = COMPOUND_STRING("Aria Burbuja"),
        .description = COMPOUND_STRING(
            "Libera burbujas al cantar.\n"
        "Este movimiento cura las\n"
        "quemaduras de los Pokémon"),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Liquidation,
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .name = COMPOUND_STRING("Martillo Hielo"),
        .description = COMPOUND_STRING(
            "Un terrible puño golpea al\n"
        "contrincante, pero la\n"
        "Velocidad del usuario se"),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrismaticLaser,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .name = COMPOUND_STRING("Cura Floral"),
        .description = COMPOUND_STRING(
            "Restaura la mitad de los\n"
        "PS máximos del objetivo.\n"
        "Es más efectivo cuando se"),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEAL_STATS,
            .preAttackEffect = TRUE,
        }),
        .ignoresSubstitute = TRUE,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpectralThief,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .name = COMPOUND_STRING("Fuerza Equina"),
        .description = COMPOUND_STRING(
            "Asesta un golpe devastador\n"
        "usando todo su cuerpo."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunsteelStrike,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .name = COMPOUND_STRING("Absorbefuerza"),
        .description = COMPOUND_STRING(
            "Restaura una cantidad de\n"
        "PS equivalente al valor de\n"
        "Ataque del rival, que"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MoongeistBeam,
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .name = COMPOUND_STRING("Cuchilla Solar"),
        .description = COMPOUND_STRING(
            "El usuario dedica un turno\n"
        "a absorber energía\n"
        "lumínica y concentrarla en"),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TearfulLook,
    },

    [MOVE_ZING_ZAP] =
    {
        .name = COMPOUND_STRING("Follaje"),
        .description = COMPOUND_STRING(
            "Ataca al oponente lanzando\n"
        "hojas."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ZingZap,
    },

    [MOVE_NATURES_MADNESS] =
    {
        .name = COMPOUND_STRING("Foco"),
        .description = COMPOUND_STRING(
            "Reduce los PS del rival\\n"
        "a la mitad con el poder nat."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturesMadness,
    },

    [MOVE_MULTI_ATTACK] =
    {
        .name = COMPOUND_STRING("Hilo Venenoso"),
        .description = COMPOUND_STRING(
            "Ataca al oponente con\n"
        "hilillos venenosos que\n"
        "reducen su Velocidad y lo"),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .holdEffect = HOLD_EFFECT_MEMORY },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MultiAttack,
    },

    [MOVE_MIND_BLOWN] =
    {
        .name = COMPOUND_STRING("Aguzar"),
        .description = COMPOUND_STRING(
            "El usuario se concentra\n"
        "para que el siguiente\n"
        "ataque propine un golpe"),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindBlown,
    },

    [MOVE_PLASMA_FISTS] =
    {
        .name = COMPOUND_STRING("Piñón Auxiliar"),
        .description = COMPOUND_STRING(
            "Cambia de marcha y logra\n"
        "aumentar el Ataque y el\n"
        "Ataque Especial de los"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ION_DELUGE,
        }),
        .battleAnimScript = gBattleAnimMove_PlasmaFists,
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .name = COMPOUND_STRING("Golpe Mordaza"),
        .description = COMPOUND_STRING(
            "Inflige al rival un dolor\n"
        "tan abrumador que le\n"
        "impide utilizar durante"),
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhotonGeyser,
    },

    [MOVE_ZIPPY_ZAP] =
    {
        .name = COMPOUND_STRING("Bola de Polen"),
        .description = COMPOUND_STRING(
            "Ráfaga eléctrica con prioridad\n"
        "que siempre asesta crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .alwaysCriticalHit = TRUE,
        .metronomeBanned = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EVS_PLUS_1,
            .self = TRUE,
        }),
        #endif
        .battleAnimScript = gBattleAnimMove_ZippyZap,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
        .name = COMPOUND_STRING("Anclaje"),
        .description = COMPOUND_STRING(
            "Gran ola electrificada que\n"
        "puede causar parálisis."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SplishySplash,
    },

    [MOVE_FLOATY_FALL] =
    {
        .name = COMPOUND_STRING("Campo Psíquico"),
        .description = COMPOUND_STRING(
            "Se eleva y cae en picado;\n"
        "puede amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .gravityBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_FloatyFall,
    },

    [MOVE_PIKA_PAPOW] =
    {
        .name = COMPOUND_STRING("Plancha"),
        .description = COMPOUND_STRING(
            "Poder del cariño de Pikachu;\n"
        "nunca falla."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PikaPapow,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
        .name = COMPOUND_STRING("Látigo Ígneo"),
        .description = COMPOUND_STRING(
            "Attack that absorbs\n"
        #if B_UPDATED_MOVE_DATA >= GEN_8
            "all the damage inflicted."),
        #else
            "half the damage inflicted."),
        #endif
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 50 },
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .battleAnimScript = gBattleAnimMove_BouncyBubble,
    },

    [MOVE_BUZZY_BUZZ] =
    {
        .name = COMPOUND_STRING("Chulería"),
        .description = COMPOUND_STRING(
            "Chispa eléctrica certera que\n"
        "siempre causa parálisis."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
        }),
        .battleAnimScript = gBattleAnimMove_BuzzyBuzz,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        .name = COMPOUND_STRING("Llama Final"),
        .description = COMPOUND_STRING(
            "Carga envuelta en llamas que\n"
        "siempre causa quemaduras."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
        }),
        .battleAnimScript = gBattleAnimMove_SizzlySlide,
    },

    [MOVE_GLITZY_GLOW] =
    {
        .name = COMPOUND_STRING("Cambiavelocidad"),
        .description = COMPOUND_STRING(
            "Onda que crea una pantalla que\n"
        "mitiga el daño especial."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LIGHT_SCREEN,
        }),
        .battleAnimScript = gBattleAnimMove_GlitzyGlow,
    },

    [MOVE_BADDY_BAD] =
    {
        .name = COMPOUND_STRING("Cuerno Certero"),
        .description = COMPOUND_STRING(
            "Ataque que crea una pantalla que\n"
        "mitiga el daño físico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REFLECT,
        }),
        .battleAnimScript = gBattleAnimMove_BaddyBad,
    },

    [MOVE_SAPPY_SEED] =
    {
        .name = COMPOUND_STRING("Purificación"),
        .description = COMPOUND_STRING(
            "Esparce semillas gigantes que\n"
        "drenan PS cada turno."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LEECH_SEED,
        }),
        .battleAnimScript = gBattleAnimMove_SappySeed,
    },

    [MOVE_FREEZY_FROST] =
    {
        .name = COMPOUND_STRING("Danza Despertar"),
        .description = COMPOUND_STRING(
            "Ráfaga helada que elimina los\n"
        "cambios en estadísticas."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAZE,
        }),
        .battleAnimScript = gBattleAnimMove_FreezyFrost,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
        .name = COMPOUND_STRING("Núcleo Castigo"),
        .description = COMPOUND_STRING(
            "Vórtice perfumado que cura los\n"
        "estados de todo el equipo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_FAIRY,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 85 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 5 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
        .battleAnimScript = gBattleAnimMove_SparklySwirl,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
        .name = COMPOUND_STRING("Patada Tropical"),
        .description = COMPOUND_STRING(
            "Poder del cariño de Eevee;\n"
        "nunca puede fallar."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_VeeveeVolley,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        .name = COMPOUND_STRING("Mandato"),
        .description = COMPOUND_STRING(
            "Gira y golpea dos veces con los\n"
        "brazos; puede amedrentar."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 2,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleIronBash,
    },

    [MOVE_DYNAMAX_CANNON] =
    {
        .name = COMPOUND_STRING("Pico Cañón"),
        .description = COMPOUND_STRING(
            "Cañonazo de Dinamax; doble\n"
        "daño a Pokémon Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DynamaxCannon,
    },

    [MOVE_SNIPE_SHOT] =
    {
        .name = COMPOUND_STRING("Fragor Escamas"),
        .description = COMPOUND_STRING(
            "Disparo directo que no afectan\n"
        "habilidades ni movimientos."),
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnipeShot,
    },

    [MOVE_JAW_LOCK] =
    {
        .name = COMPOUND_STRING("Martillo Dragón"),
        .description = COMPOUND_STRING(
            "Mordisco que impide huir al\n"
        "usuario y al objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TRAP_BOTH,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JawLock,
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .name = COMPOUND_STRING("Giro Vil"),
        .description = COMPOUND_STRING(
            "Devora una baya y sube mucho\n"
        "la Defensa del usuario."),
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StuffCheeks,
    },

    [MOVE_NO_RETREAT] =
    {
        .name = COMPOUND_STRING("Velo Aurora"),
        .description = COMPOUND_STRING(
            "Sube todas las estadísticas\n"
        "pero impide retirarse."),
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NoRetreat,
    },

    [MOVE_TAR_SHOT] =
    {
        .name = COMPOUND_STRING("Aluvión de Flechas Sombrías"),
        .description = COMPOUND_STRING(
            "Empapa de alquitrán; reduce\n"
        "la Velocidad y la resistencia."),
        .effect = EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TarShot,
    },

    [MOVE_MAGIC_POWDER] =
    {
        .name = COMPOUND_STRING("Hiperplancha Oscura"),
        .description = COMPOUND_STRING(
            "Polvo mágico que cambia el\n"
        "tipo del objetivo a Psíquico."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_PSYCHIC },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicPowder,
    },

    [MOVE_DRAGON_DARTS] =
    {
        .name = COMPOUND_STRING("Sinfonía de la Diva Marina"),
        .description = COMPOUND_STRING(
            "Drago y Dragapi lanzan dos\n"
        "dardos al equipo rival."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SMART,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonDarts,
    },

    [MOVE_TEATIME] =
    {
        .name = COMPOUND_STRING("Cólera del Guardián"),
        .description = COMPOUND_STRING(
            "Hora del té que hace que todos\n"
        "coman sus bayas a la vez."),
        .effect = EFFECT_TEATIME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Teatime,
    },

    [MOVE_OCTOLOCK] =
    {
        .name = COMPOUND_STRING("Constelación Robaalmas"),
        .description = COMPOUND_STRING(
            "Atrapa al rival bajando su\n"
        "Defensa y Def. Esp. cada turno."),
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Octolock,
    },

    [MOVE_BOLT_BEAK] =
    {
        .name = COMPOUND_STRING("Surfeo Galvánico"),
        .description = COMPOUND_STRING(
            "Pico eléctrico; duplica fuerza\n"
        "si el usuario va primero."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltBeak,
    },

    [MOVE_FISHIOUS_REND] =
    {
        .name = COMPOUND_STRING("Arrojo Intempestivo"),
        .description = COMPOUND_STRING(
            "Mordisco feroz; duplica fuerza\n"
        "si el usuario va primero."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FishiousRend,
    },

    [MOVE_COURT_CHANGE] =
    {
        .name = COMPOUND_STRING("Novena Potencia"),
        .description = COMPOUND_STRING(
            "Intercambia los efectos del\n"
        "terreno entre ambos lados."),
        .effect = EFFECT_COURT_CHANGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CourtChange,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .name = COMPOUND_STRING("Supernova Original"),
        .description = COMPOUND_STRING(
            "Aumenta todas las estadísticas\n"
        "pero cuesta un tercio de PS."),
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .danceMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangorousSoul,
    },

    [MOVE_BODY_PRESS] =
    {
        .name = COMPOUND_STRING("Coraza Trampa"),
        .description = COMPOUND_STRING(
            "Aplasta con el cuerpo; la\n"
        "Def. determina el daño."),
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodyPress,
    },

    [MOVE_DECORATE] =
    {
        .name = COMPOUND_STRING("Cañón Floral"),
        .description = COMPOUND_STRING(
            "Adorna al aliado; sube mucho\n"
        "Ataque y Ataque Especial."),
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Decorate,
    },

    [MOVE_DRUM_BEATING] =
    {
        .name = COMPOUND_STRING("Psicocolmillo"),
        .description = COMPOUND_STRING(
            "Golpea un tótem; baja la\n"
        "Velocidad del objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrumBeating,
    },

    [MOVE_SNAP_TRAP] =
    {
        .name = COMPOUND_STRING("Pataleta"),
        .description = COMPOUND_STRING(
            "Atrapa al objetivo en una\n"
        "trampa durante 4-5 turnos."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SNAP_TRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnapTrap,
    },

    [MOVE_PYRO_BALL] =
    {
        .name = COMPOUND_STRING("Hueso Sombrío"),
        .description = COMPOUND_STRING(
            "Bola de fuego ardiente que\n"
        "puede quemar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .ballisticMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PyroBall,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .name = COMPOUND_STRING("Roca Veloz"),
        .description = COMPOUND_STRING(
            "Espadazo titánico; doble daño\n"
        "a Pokémon Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBlade,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .name = COMPOUND_STRING("Hidroariete"),
        .description = COMPOUND_STRING(
            "Escudazo titánico; doble daño\n"
        "a Pokémon Dinamax."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBash,
    },

    [MOVE_AURA_WHEEL] =
    {
        .name = COMPOUND_STRING("Láser Prisma"),
        .description = COMPOUND_STRING(
            "Rueda de aura que sube la\n"
        "Velocidad; tipo según Morpeko."),
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraWheel,
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .name = COMPOUND_STRING("Robasombra"),
        .description = COMPOUND_STRING(
            "Golpe de cola que baja el\n"
        "Ataque de todos los rivales."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BreakingSwipe,
    },

    [MOVE_BRANCH_POKE] =
    {
        .name = COMPOUND_STRING("Meteoimpacto"),
        .description = COMPOUND_STRING(
            "Golpea con una ramita; funciona\n"
        "muy bien contra Agua."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BranchPoke,
    },

    [MOVE_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("Rayo Umbrío"),
        .description = COMPOUND_STRING(
            "Onda sonora eléctrica que dañan\n"
        "a todos los rivales."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Overdrive,
    },

    [MOVE_APPLE_ACID] =
    {
        .name = COMPOUND_STRING("Ojos Llorosos"),
        .description = COMPOUND_STRING(
            "Zumo ácido que baja la\n"
        "Defensa Especial del objetivo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AppleAcid,
    },

    [MOVE_GRAV_APPLE] =
    {
        .name = COMPOUND_STRING("Electropunzada"),
        .description = COMPOUND_STRING(
            "Manzana que cae fuerte; baja\n"
        "la Defensa y la gravedad."),
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GravApple,
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .name = COMPOUND_STRING("Furia Natural"),
        .description = COMPOUND_STRING(
            "Ataque espiritual que baja\n"
        "mucho el At. Esp. del rival."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritBreak,
    },

    [MOVE_STRANGE_STEAM] =
    {
        .name = COMPOUND_STRING("Multiataque"),
        .description = COMPOUND_STRING(
            "Vapor peculiar que puede\n"
        "confundir al objetivo."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrangeSteam,
    },

    [MOVE_LIFE_DEW] =
    {
        .name = COMPOUND_STRING("Gigarrayo Fulminante"),
        .description = COMPOUND_STRING(
            "Rocía agua bendita que cura\n"
        "PS a usuario y aliados."),
        .effect = EFFECT_LIFE_DEW,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LifeDew,
    },

    [MOVE_OBSTRUCT] =
    {
        .name = COMPOUND_STRING("Cabeza Sorpresa"),
        .description = COMPOUND_STRING(
            "Protege y baja la Defensa\n"
        "del rival si hace contacto."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_OBSTRUCT },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Obstruct,
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .name = COMPOUND_STRING("Puños Plasma"),
        .description = COMPOUND_STRING(
            "Reverencia falsa que nunca\n"
        "puede fallar."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FalseSurrender,
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .name = COMPOUND_STRING("Géiser Fotónico"),
        .description = COMPOUND_STRING(
            "Ataque potente; el usuario debe\n"
        "recargar el siguiente turno."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorAssault,
    },

    [MOVE_ETERNABEAM] =
    {
        .name = COMPOUND_STRING("Fotodestrucción Apocalíptica"),
        .description = COMPOUND_STRING(
            "Movimiento de Eternatus; debe\n"
        "recargar el turno siguiente."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Eternabeam,
    },

    [MOVE_STEEL_BEAM] =
    {
        .name = COMPOUND_STRING("Embestida Solar"),
        .description = COMPOUND_STRING(
            "Haz de acero devastador que\n"
        "causa daño al usuario."),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelBeam,
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .name = COMPOUND_STRING("Deflagración Lunar"),
        .description = COMPOUND_STRING(
            "Fuerza expansiva; más potente\n"
        "con Campo Psíquico activo."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_PSYCHIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
            .hitsBothFoes = TRUE,
        },
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_ExpandingForce,
    },

    [MOVE_STEEL_ROLLER] =
    {
        .name = COMPOUND_STRING("Somanta Amistosa"),
        .description = COMPOUND_STRING(
            "Bola de acero que elimina\n"
        "el terreno activo."),
        .effect = EFFECT_STEEL_ROLLER,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelRoller,
    },

    [MOVE_SCALE_SHOT] =
    {
        .name = COMPOUND_STRING("Tempestad Rocosa"),
        .description = COMPOUND_STRING(
            "Lanza escamas de 2 a 5 veces;\n"
        "sube Velocidad, baja Defensa."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SCALE_SHOT,
        }),
        .battleAnimScript = gBattleAnimMove_ScaleShot,
    },

    [MOVE_METEOR_BEAM] =
    {
        .name = COMPOUND_STRING("Estruendo Implacable"),
        .description = COMPOUND_STRING(
            "Carga energía en turno 1 y\n"
        "ataca en turno 2; sube At. Esp."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_METEORBEAMCHARGING },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorBeam,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .name = COMPOUND_STRING("Pikaturbo"),
        .description = COMPOUND_STRING(
            "Ataque especial o físico según\n"
        "lo que cause más daño."),
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSideArm,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .name = COMPOUND_STRING("Salpikasurf"),
        .description = COMPOUND_STRING(
            "Explota en un campo de niebla\n"
        "para causar gran daño."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = TRUE,
        .dampBanned = TRUE,
        .argument.terrainBoost = {
            .terrain =  STATUS_FIELD_MISTY_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
        },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MISTY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_MistyExplosion,
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .name = COMPOUND_STRING("Pikapicado"),
        .description = COMPOUND_STRING(
            "Movimiento de alta prioridad\n"
        "en campo de hierba."),
        .effect = EFFECT_GRASSY_GLIDE,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 55 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GRASSY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_GrassyGlide,
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .name = COMPOUND_STRING("Pikatormenta"),
        .description = COMPOUND_STRING(
            "Rayo eléctrico; doble daño\n"
        "bajo Campo Eléctrico."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 100,
            .groundCheck = GROUND_CHECK_TARGET,
        },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_RisingVoltage,
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .name = COMPOUND_STRING("Vapodrenaje"),
        .description = COMPOUND_STRING(
            "Pulso que cambia de tipo según\n"
        "el terreno activo."),
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN, COMBO_STARTER_MISTY_TERRAIN, COMBO_STARTER_GRASSY_TERRAIN, COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_TerrainPulse,
    },

    [MOVE_SKITTER_SMACK] =
    {
        .name = COMPOUND_STRING("Joltioparálisis"),
        .description = COMPOUND_STRING(
            "Ataque sorpresa que baja el\n"
        "Ataque Especial del rival."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkitterSmack,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .name = COMPOUND_STRING("Flarembestida"),
        .description = COMPOUND_STRING(
            "Quema a rivales cuyos stats\n"
        "hayan subido en ese turno."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BurningJealousy,
    },

    [MOVE_LASH_OUT] =
    {
        .name = COMPOUND_STRING("Espeaura"),
        .description = COMPOUND_STRING(
            "Ataque doble si los stats del\n"
        "usuario bajaron en ese turno."),
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LashOut,
    },

    [MOVE_POLTERGEIST] =
    {
        .name = COMPOUND_STRING("Umbreozona"),
        .description = COMPOUND_STRING(
            "Ataca usando el objeto del\n"
        "rival; falla si no lo tiene."),
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Poltergeist,
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .name = COMPOUND_STRING("Leafitobombas"),
        .description = COMPOUND_STRING(
            "Gas corrosivo que destruye\n"
        "los objetos de los rivales."),
        .effect = EFFECT_CORROSIVE_GAS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CorrosiveGas,
    },

    [MOVE_COACHING] =
    {
        .name = COMPOUND_STRING("Glaceoprisma"),
        .description = COMPOUND_STRING(
            "Ayuda a los aliados subiendo\n"
        "su Ataque y Defensa."),
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coaching,
    },

    [MOVE_FLIP_TURN] =
    {
        .name = COMPOUND_STRING("Sylveotornado"),
        .description = COMPOUND_STRING(
            "Causa daño y regresa al\n"
        "equipo para relevarse."),
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlipTurn,
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .name = COMPOUND_STRING("Eevimpacto"),
        .description = COMPOUND_STRING(
            "Tres patadas de 20, 40 y 60\n"
        "de poder; puede fallar."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TripleAxel,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .name = COMPOUND_STRING("Ferropuño Doble"),
        .description = COMPOUND_STRING(
            "Ataca dos veces seguidas\n"
        "con las alas."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualWingbeat,
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .name = COMPOUND_STRING("Maxibarrera"),
        .description = COMPOUND_STRING(
            "Arena hirviente que puede\n"
        "quemar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ScorchingSands,
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .name = COMPOUND_STRING("Cañón Dinamax"),
        .description = COMPOUND_STRING(
            "Cura PS y estado del usuario\n"
        "y aliados en la selva."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JungleHealing,
    },

    [MOVE_WICKED_BLOW] =
    {
        .name = COMPOUND_STRING("Disparo Certero"),
        .description = COMPOUND_STRING(
            "Golpe oscuro que siempre\n"
        "asesta un crítico."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WickedBlow,
    },

    [MOVE_SURGING_STRIKES] =
    {
        .name = COMPOUND_STRING("Presa Maxilar"),
        .description = COMPOUND_STRING(
            "Tres golpes acuáticos que\n"
        "siempre son golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 3,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SurgingStrikes,
    },

    [MOVE_THUNDER_CAGE] =
    {
        .name = COMPOUND_STRING("Atiborramiento"),
        .description = COMPOUND_STRING(
            "Atrapa al rival en un campo\n"
        "eléctrico durante varios turnos."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_THUNDER_CAGE,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderCage,
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .name = COMPOUND_STRING("Bastión Final"),
        .description = COMPOUND_STRING(
            "Soplo de fuego; más potente\n"
        "cuantos más PS tenga el usuario."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonEnergy,
    },

    [MOVE_FREEZING_GLARE] =
    {
        .name = COMPOUND_STRING("Alquitranazo"),
        .description = COMPOUND_STRING(
            "Shoots psychic power from\n"
        #if B_USE_FROSTBITE == TRUE
            "the eyes. May frostbite."),
        #else
            "the eyes. May freeze the foe."),
        #endif
        .power = 90,
        .effect = EFFECT_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezingGlare,
    },

    [MOVE_FIERY_WRATH] =
    {
        .name = COMPOUND_STRING("Polvo Mágico"),
        .description = COMPOUND_STRING(
            "Ira abrasadora que puede\n"
        "amedrentar al objetivo."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryWrath,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .name = COMPOUND_STRING("Dracoflechas"),
        .description = COMPOUND_STRING(
            "Patada eléctrica que baja\n"
        "la Defensa del objetivo."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderousKick,
    },

    [MOVE_GLACIAL_LANCE] =
    {
        .name = COMPOUND_STRING("Hora del Té"),
        .description = COMPOUND_STRING(
            "Lanza de hielo gigante que\n"
        "daña a todos los rivales."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 130,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GlacialLance,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .name = COMPOUND_STRING("Octopresa"),
        .description = COMPOUND_STRING(
            "Bombardeo espectral que daña\n"
        "a todos los rivales."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AstralBarrage,
    },

    [MOVE_EERIE_SPELL] =
    {
        .name = COMPOUND_STRING("Electropico"),
        .description = COMPOUND_STRING(
            "Magia siniestra que reduce\n"
        "3 PP del último movimiento."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EERIE_SPELL,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EerieSpell,
    },

    [MOVE_DIRE_CLAW] =
    {
        .name = COMPOUND_STRING("Branquibocado"),
        .description = COMPOUND_STRING(
            "Garra letal que puede causar\n"
        "parálisis, veneno o somnolencia."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DIRE_CLAW,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_DireClaw,
    },

    [MOVE_PSYSHIELD_BASH] =
    {
        .name = COMPOUND_STRING("Cambio de Cancha"),
        .description = COMPOUND_STRING(
            "Carga de energía psíquica que\n"
        "aumenta la propia Defensa."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsyshieldBash,
    },

    [MOVE_POWER_SHIFT] =
    {
        .name = COMPOUND_STRING("Maxignición"),
        .description = COMPOUND_STRING(
            "El usuario intercambia sus\n"
        "valores de Ataque y Defensa."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PowerShift,
},

    [MOVE_STONE_AXE] =
    {
        .name = COMPOUND_STRING("Maxinsecto"),
        .description = COMPOUND_STRING(
            "Hachazo de piedra que coloca\n"
        "Trampa Rocas en el campo."),
        .effect = EFFECT_STONE_AXE,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_StoneAxe,
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
        .name = COMPOUND_STRING("Maxitormenta"),
        .description = COMPOUND_STRING(
            "Viento feroz primaveral; efecto\n"
        "según la forma del usuario."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SpringtideStorm,
    },

    [MOVE_MYSTICAL_POWER] =
    {
        .name = COMPOUND_STRING("Maxiataque"),
        .description = COMPOUND_STRING(
            "Poder misterioso que aumenta el\n"
        "Ataque Especial del usuario."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MysticalPower,
    },

    [MOVE_RAGING_FURY] =
    {
        .name = COMPOUND_STRING("Maxipuño"),
        .description = COMPOUND_STRING(
            "Furia de dos o tres turnos que\n"
        "deja confuso al usuario."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagingFury,
    },

    [MOVE_WAVE_CRASH] =
    {
        .name = COMPOUND_STRING("Maxiespectro"),
        .description = COMPOUND_STRING(
            "Embestida acuática que causa\n"
        "daño de retroceso al usuario."),
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 75,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaveCrash,
    },

    [MOVE_CHLOROBLAST] =
    {
        .name = COMPOUND_STRING("Maxihelada"),
        .description = COMPOUND_STRING(
            "Explosión de clorofila potente\n"
        "que hiere mucho al usuario."),
        .effect = EFFECT_CHLOROBLAST,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 150 : 120,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_Chloroblast,
    },

    [MOVE_MOUNTAIN_GALE] =
    {
        .name = COMPOUND_STRING("Maxiácido"),
        .description = COMPOUND_STRING(
            "Bloques gigantes de hielo que\n"
        "pueden amedrentar al rival."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MountainGale,
    },

    [MOVE_VICTORY_DANCE] =
    {
        .name = COMPOUND_STRING("Maxichorro"),
        .description = COMPOUND_STRING(
            "Danza triunfal que aumenta el\n"
        "Ataque, Defensa y Velocidad."),
        .effect = EFFECT_VICTORY_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VictoryDance,
    },

    [MOVE_HEADLONG_RUSH] =
    {
        .name = COMPOUND_STRING("Maxiciclón"),
        .description = COMPOUND_STRING(
            "Placaje a fondo que reduce las\n"
        "defensas del propio usuario."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadlongRush,
    },

    [MOVE_BARB_BARRAGE] =
    {
        .name = COMPOUND_STRING("Maxiestela"),
        .description = COMPOUND_STRING(
            "Dispara púas; duplica su poder\n"
        "si el rival está envenenado."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_BarbBarrage,
    },

    [MOVE_ESPER_WING] =
    {
        .name = COMPOUND_STRING("Maxidraco"),
        .description = COMPOUND_STRING(
            "Ala psíquica con alto crítico\n"
        "que sube la Velocidad."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 75,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EsperWing,
    },

    [MOVE_BITTER_MALICE] =
    {
        .name = COMPOUND_STRING("Maxionda"),
        .description = COMPOUND_STRING(
            "Rencor gélido que reduce el\n"
        "Ataque del objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_BitterMalice,
    },

    [MOVE_SHELTER] =
    {
        .name = COMPOUND_STRING("Maxilito"),
        .description = COMPOUND_STRING(
            "Se encierra en su caparazón para\n"
        "subir mucho su Defensa."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Shelter,
    },

    [MOVE_TRIPLE_ARROWS] =
    {
        .name = COMPOUND_STRING("Maxitemblor"),
        .description = COMPOUND_STRING(
            "Tres flechas con alto crítico\n"
        "que pueden bajar la Defensa."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 90 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_TripleArrows,
    },

    [MOVE_INFERNAL_PARADE] =
    {
        .name = COMPOUND_STRING("Maxisombra"),
        .description = COMPOUND_STRING(
            "Doble poder si el rival tiene\n"
        "estado; puede causar quemadura."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_InfernalParade,
    },

    [MOVE_CEASELESS_EDGE] =
    {
        .name = COMPOUND_STRING("Maxiflora"),
        .description = COMPOUND_STRING(
            "Tajo siniestro que coloca púas\n"
        "tóxicas en el campo rival."),
        .effect = EFFECT_CEASELESS_EDGE,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_CeaselessEdge,
    },

    [MOVE_BLEAKWIND_STORM] =
    {
        .name = COMPOUND_STRING("Maximetal"),
        .description = COMPOUND_STRING(
            "Viento helado polar que puede\n"
        "reducir la Velocidad rival."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BleakwindStorm,
    },

    [MOVE_WILDBOLT_STORM] =
    {
        .name = COMPOUND_STRING("Estruendo Escama"),
        .description = COMPOUND_STRING(
            "Tempestad eléctrica que puede\n"
        "paralizar al objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_WildboltStorm,
    },

    [MOVE_SANDSEAR_STORM] =
    {
        .name = COMPOUND_STRING("Plancha Corporal"),
        .description = COMPOUND_STRING(
            "Arena abrasadora que puede\n"
        "quemar al objetivo."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_SandsearStorm,
    },

    [MOVE_LUNAR_BLESSING] =
    {
        .name = COMPOUND_STRING("Decoración"),
        .description = COMPOUND_STRING(
            "Bendición lunar que cura PS y\n"
        "estados del usuario y aliado."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_LunarBlessing,
    },

    [MOVE_TAKE_HEART] =
    {
        .name = COMPOUND_STRING("Batería Asalto"),
        .description = COMPOUND_STRING(
            "Se llena de valor para curarse\n"
        "y subir sus características."),
        .effect = EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TakeHeart,
    },

    [MOVE_TERA_BLAST] =
    {
        .name = COMPOUND_STRING("Cepo"),
        .description = COMPOUND_STRING(
            "Ataque que adopta el teratipo\n"
        "del usuario si teracristaliza."),
        .effect = EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .forcePressure = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TERA_BLAST,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_TeraBlast,
    },

    [MOVE_SILK_TRAP] =
    {
        .name = COMPOUND_STRING("Balón Ígneo"),
        .description = COMPOUND_STRING(
            "Se protege y baja la Velocidad\n"
        "de quien haga contacto."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SILK_TRAP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SilkTrap,
    },

    [MOVE_AXE_KICK] =
    {
        .name = COMPOUND_STRING("Tajo Supremo"),
        .description = COMPOUND_STRING(
            "Patada hacha que puede fallar\n"
        "y confundir al objetivo."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_AxeKick,
    },

    [MOVE_LAST_RESPECTS] =
    {
        .name = COMPOUND_STRING("Embate Supremo"),
        .description = COMPOUND_STRING(
            "Gana potencia por cada aliado\n"
        "derrotado en el equipo."),
        .effect = EFFECT_LAST_RESPECTS,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LastRespects,
    },

    [MOVE_LUMINA_CRASH] =
    {
        .name = COMPOUND_STRING("Rueda Aural"),
        .description = COMPOUND_STRING(
            "Luz cegadora que siempre baja\n"
        "mucho la Def. Especial rival."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_LuminaCrash,
    },

    [MOVE_ORDER_UP] =
    {
        .name = COMPOUND_STRING("Vasto Impacto"),
        .description = COMPOUND_STRING(
            "Golpea y sube un stat según el\n"
        "Tatsugiri en la boca de Dondozo."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ORDER_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_OrderUp,
    },

    [MOVE_JET_PUNCH] =
    {
        .name = COMPOUND_STRING("Punzada Rama"),
        .description = COMPOUND_STRING(
            "Puñetazo a velocidad vertiginosa\n"
        "que ataca con prioridad."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JetPunch,
    },

    [MOVE_SPICY_EXTRACT] =
    {
        .name = COMPOUND_STRING("Amplificador"),
        .description = COMPOUND_STRING(
            "Aumenta mucho el Ataque pero\n"
        "baja mucho la Defensa rival."),
        .effect = EFFECT_SPICY_EXTRACT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SpicyExtract,
    },

    [MOVE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("Ácido Málico"),
        .description = COMPOUND_STRING(
            "Esfuerzo extremo en las ruedas\n"
        "que baja mucho la Velocidad."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_2,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_SpinOut,
    },

    [MOVE_POPULATION_BOMB] =
    {
        .name = COMPOUND_STRING("Fuerza G"),
        .description = COMPOUND_STRING(
            "Familia que ataca de 1 a 10\n"
        "veces seguidas en un turno."),
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .strikeCount = 10,
        .battleAnimScript = gBattleAnimMove_PopulationBomb,
    },

    [MOVE_ICE_SPINNER] =
    {
        .name = COMPOUND_STRING("Choque Anímico"),
        .description = COMPOUND_STRING(
            "Giro con patas de hielo que daña\n"
        "y elimina el terreno activo."),
        .effect = EFFECT_ICE_SPINNER,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_IceSpinner,
    },

    [MOVE_GLAIVE_RUSH] =
    {
        .name = COMPOUND_STRING("Cautivapor"),
        .description = COMPOUND_STRING(
            "Ataque temerario; el rival no\n"
        "fallará y duplicará daño luego."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GLAIVE_RUSH,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_GlaiveRush,
    },

    [MOVE_REVIVAL_BLESSING] =
    {
        .name = COMPOUND_STRING("Gota Vital"),
        .description = COMPOUND_STRING(
            "Revive a un compañero debilitado\n"
        "con la mitad de sus PS."),
        .effect = EFFECT_REVIVAL_BLESSING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .healingMove = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_RevivalBlessing,
    },

    [MOVE_SALT_CURE] =
    {
        .name = COMPOUND_STRING("Obstrucción"),
        .description = COMPOUND_STRING(
            "Daña cada turno; duplica el daño\n"
        "contra Acero y Agua."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SALT_CURE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SaltCure,
    },

    [MOVE_TRIPLE_DIVE] =
    {
        .name = COMPOUND_STRING("Irreverencia"),
        .description = COMPOUND_STRING(
            "Tres golpes de agua sucesivos\n"
        "en un mismo turno."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .battleAnimScript = gBattleAnimMove_TripleDive,
    },

    [MOVE_MORTAL_SPIN] =
    {
        .name = COMPOUND_STRING("Asalto Estelar"),
        .description = COMPOUND_STRING(
            "Elimina trampas y Drenadoras;\n"
        "envenena a los rivales."),
        .effect = EFFECT_RAPID_SPIN,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MortalSpin,
    },

    [MOVE_DOODLE] =
    {
        .name = COMPOUND_STRING("Rayo Infinito"),
        .description = COMPOUND_STRING(
            "Cambia la habilidad propia y de\n"
        "aliado por la del rival."),
        .effect = EFFECT_DOODLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Doodle,
    },

    [MOVE_FILLET_AWAY] =
    {
        .name = COMPOUND_STRING("Metaláser"),
        .description = COMPOUND_STRING(
            "Pierde PS para aumentar mucho\n"
        "sus ataques y la Velocidad."),
        .effect = EFFECT_FILLET_AWAY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_FilletAway,
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
        .name = COMPOUND_STRING("Vasta Fuerza"),
        .description = COMPOUND_STRING(
            "Corte ceremonial certero que\n"
        "nunca puede fallar."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_KowtowCleave,
    },

    [MOVE_FLOWER_TRICK] =
    {
        .name = COMPOUND_STRING("Allanador Férreo"),
        .description = COMPOUND_STRING(
            "Ramillete trucado; nunca falla\n"
        "y siempre es golpe crítico."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .alwaysCriticalHit = TRUE,
        .battleAnimScript = gBattleAnimMove_FlowerTrick,
    },

    [MOVE_TORCH_SONG] =
    {
        .name = COMPOUND_STRING("Ráfaga Escamas"),
        .description = COMPOUND_STRING(
            "Canto ardiente que siempre sube\n"
        "el Ataque Especial propio."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_TorchSong,
    },

    [MOVE_AQUA_STEP] =
    {
        .name = COMPOUND_STRING("Rayo Meteórico"),
        .description = COMPOUND_STRING(
            "Paso de baile acuático que sube\n"
        "la Velocidad propia."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AquaStep,
    },

    [MOVE_RAGING_BULL] =
    {
        .name = COMPOUND_STRING("Moluscañón"),
        .description = COMPOUND_STRING(
            "Placaje de toro; rompe barreras\n"
        "y tipo varía según Tauros."),
        .effect = EFFECT_RAGING_BULL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RagingBull,
    },

    [MOVE_MAKE_IT_RAIN] =
    {
        .name = COMPOUND_STRING("Bruma Explosiva"),
        .description = COMPOUND_STRING(
            "Lluvia de monedas; baja At. Esp.\n"
        "y deja dinero tras la batalla."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        },
        {
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_MakeItRain,
    },

    [MOVE_RUINATION] =
    {
        .name = COMPOUND_STRING("Fitoimpulso"),
        .description = COMPOUND_STRING(
            "Poder de ruina que reduce a la\n"
        "mitad los PS del rival."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ruination,
    },

    [MOVE_COLLISION_COURSE] =
    {
        .name = COMPOUND_STRING("Alto Voltaje"),
        .description = COMPOUND_STRING(
            "Explosión prehistórica; más\n"
        "poderosa si es supereficaz."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_CollisionCourse,
    },

    [MOVE_ELECTRO_DRIFT] =
    {
        .name = COMPOUND_STRING("Pulso de Campo"),
        .description = COMPOUND_STRING(
            "Relámpago futurista; más fuerte\n"
        "si es supereficaz."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ElectroDrift,
    },

    [MOVE_SHED_TAIL] =
    {
        .name = COMPOUND_STRING("Golpe Rastrero"),
        .description = COMPOUND_STRING(
            "Crea un Sustituto y cambia de\n"
        "Pokémon dejándoselo al relevo."),
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ShedTail,
    },

    [MOVE_CHILLY_RECEPTION] =
    {
        .name = COMPOUND_STRING("Envidia Ardiente"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
            "Cuenta un chiste frío; invoca\n"
        "nieve y el usuario se retira."),
        #else
        .description = COMPOUND_STRING(
            "Cuenta un chiste frío; invoca\n"
        "nieve y el usuario se retira."),
        #endif
        .effect = EFFECT_WEATHER_AND_SWITCH,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .battleAnimScript = gBattleAnimMove_ChillyReception,
    },

    [MOVE_TIDY_UP] =
    {
        .name = COMPOUND_STRING("Desahogo"),
        .description = COMPOUND_STRING(
            "Recoge púas y sustitutos;\n"
        "sube Ataque y Velocidad."),
        .effect = EFFECT_TIDY_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TidyUp,
    },

    [MOVE_SNOWSCAPE] =
    {
        .name = COMPOUND_STRING("Poltergeist"),
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
            .description = COMPOUND_STRING(
                "Invoca una tormenta de nieve\n"
        "por 5 turnos."),
        #else
            .description = COMPOUND_STRING(
                "Invoca una tormenta de nieve\n"
        "por 5 turnos."),
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? gBattleAnimMove_Hail : gBattleAnimMove_Snowscape,
    },

    [MOVE_POUNCE] =
    {
        .name = COMPOUND_STRING("Gas Corrosivo"),
        .description = COMPOUND_STRING(
            "Zarpazo que baja la Velocidad\n"
        "del objetivo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_Pounce,
    },

    [MOVE_TRAILBLAZE] =
    {
        .name = COMPOUND_STRING("Motivación"),
        .description = COMPOUND_STRING(
            "Golpe rápido que sube la\n"
        "Velocidad del usuario."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trailblaze,
    },

    [MOVE_CHILLING_WATER] =
    {
        .name = COMPOUND_STRING("Viraje"),
        .description = COMPOUND_STRING(
            "Lanza agua helada que baja\n"
        "el Ataque del objetivo."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChillingWater,
    },

    [MOVE_HYPER_DRILL] =
    {
        .name = COMPOUND_STRING("Triple Axel"),
        .description = COMPOUND_STRING(
            "Taladro que penetra incluso\n"
        "ella Protección del rival."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_HyperDrill,
    },

    [MOVE_TWIN_BEAM] =
    {
        .name = COMPOUND_STRING("Ala Bis"),
        .description = COMPOUND_STRING(
            "Dos rayos psíquicos lanzados\n"
        "uno tras otro."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TwinBeam,
    },

    [MOVE_RAGE_FIST] =
    {
        .name = COMPOUND_STRING("Arenas Ardientes"),
        .description = COMPOUND_STRING(
            "Se hace más fuerte por cada\n"
        "impacto recibido."),
        .effect = EFFECT_RAGE_FIST,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RageFist,
    },

    [MOVE_ARMOR_CANNON] =
    {
        .name = COMPOUND_STRING("Cura Selvática"),
        .description = COMPOUND_STRING(
            "Lanza su propia armadura como\n"
        "cañonazo; baja las defensas."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ArmorCannon,
    },

    [MOVE_BITTER_BLADE] =
    {
        .name = COMPOUND_STRING("Golpe Oscuro"),
        .description = COMPOUND_STRING(
            "Hoja vengativa que absorbe\n"
        "la mitad del daño causado."),
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_BitterBlade,
    },

    [MOVE_DOUBLE_SHOCK] =
    {
        .name = COMPOUND_STRING("Azote Torrencial"),
        .description = COMPOUND_STRING(
            "Libera electricidad; el usuario\n"
        "deja de ser tipo Eléctrico."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .type = TYPE_ELECTRIC },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_DoubleShock,
    },

    [MOVE_GIGATON_HAMMER] =
    {
        .name = COMPOUND_STRING("Electrojaula"),
        .description = COMPOUND_STRING(
            "Martillazo colosal; no puede\n"
        "usarse dos veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_GigatonHammer,
    },

    [MOVE_COMEUPPANCE] =
    {
        .name = COMPOUND_STRING("Dracoenergía"),
        .description = COMPOUND_STRING(
            "Devuelve el daño recibido\n"
        "con creces al agresor."),
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Comeuppance,
    },

    [MOVE_AQUA_CUTTER] =
    {
        .name = COMPOUND_STRING("Mirada Heladora"),
        .description = COMPOUND_STRING(
            "Hoja de agua con alta tasa\n"
        "de golpes críticos."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_AquaCutter,
    },

    [MOVE_BLAZING_TORQUE] =
    {
        .name = COMPOUND_STRING("Furia Candente"),
        .description = COMPOUND_STRING("Movimiento de Revavroom;\n"
        "la potencia varía."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BlazingTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_WICKED_TORQUE] =
    {
        .name = COMPOUND_STRING("Patada Relámpago"),
        .description = COMPOUND_STRING("Movimiento de Revavroom;\n"
        "la potencia varía."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .battleAnimScript = gBattleAnimMove_WickedTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
        .name = COMPOUND_STRING("Lanza Glacial"),
        .description = COMPOUND_STRING("Movimiento de Revavroom;\n"
        "la potencia varía."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_NoxiousTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_COMBAT_TORQUE] =
    {
        .name = COMPOUND_STRING("Orbes Espectro"),
        .description = COMPOUND_STRING("Movimiento de Revavroom;\n"
        "la potencia varía."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_CombatTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_MAGICAL_TORQUE] =
    {
        .name = COMPOUND_STRING("Conjuro Funesto"),
        .description = COMPOUND_STRING("Movimiento de Revavroom;\n"
        "la potencia varía."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MagicalTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_PSYBLADE] =
    {
        .name = COMPOUND_STRING("Garra Nociva"),
        .description = COMPOUND_STRING(
            "Espada psíquica más potente en\n"
        "Campo Eléctrico."),
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_NONE,
        },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_Psyblade,
    },

    [MOVE_HYDRO_STEAM] =
    {
        .name = COMPOUND_STRING("Asalto Barrera"),
        .description = COMPOUND_STRING(
            "Vapor hirviente que duplica su\n"
        "poder bajo sol abrasador."),
        .effect = EFFECT_HYDRO_STEAM,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .battleAnimScript = gBattleAnimMove_HydroSteam,
    },

    [MOVE_BLOOD_MOON] =
    {
        .name = COMPOUND_STRING("Cambiapoder"),
        .description = COMPOUND_STRING(
            "Dispara la luna llena; no puede\n"
        "usarse dos veces seguidas."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_BloodMoon,
    },

    [MOVE_MATCHA_GOTCHA] =
    {
        .name = COMPOUND_STRING("Hachazo Pétreo"),
        .description = COMPOUND_STRING(
            "Dispara té caliente; puede quemar\n"
        "y absorbe mitad del daño."),
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .thawsUser = TRUE,
        .healingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_MatchaGotcha,
    },

    [MOVE_SYRUP_BOMB] =
    {
        .name = COMPOUND_STRING("Ciclón Primavera"),
        .description = COMPOUND_STRING(
            "Dispara sirope que reduce la\n"
        "Velocidad del rival 3 turnos."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SYRUP_BOMB,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SyrupBomb,
    },

    [MOVE_IVY_CUDGEL] =
    {
        .name = COMPOUND_STRING("Poder Místico"),
        .description = COMPOUND_STRING(
            "Golpe con garrote; alto ratio\n"
        "de críticos."),
        .effect = EFFECT_IVY_CUDGEL,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_IvyCudgel,
    },

    [MOVE_ELECTRO_SHOT] =
    {
        .name = COMPOUND_STRING("Erupción de Ira"),
        .description = COMPOUND_STRING(
            "Carga electricidad en turno 1,\n"
        "dispara en 2; sube At. Esp."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_ELECTROSHOTCHARGING, .weather = B_WEATHER_RAIN },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_ElectroShot,
    },

    [MOVE_TERA_STARSTORM] =
    {
        .name = COMPOUND_STRING("Envite Acuático"),
        .description = COMPOUND_STRING(
            "Ataque estelar de Terapagos;\n"
        "hiere a todos los rivales."),
        .effect = EFFECT_TERA_STARSTORM,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .assistBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_TeraStarstorm,
    },

    [MOVE_FICKLE_BEAM] =
    {
        .name = COMPOUND_STRING("Clorofiláser"),
        .description = COMPOUND_STRING(
            "Rayo que a veces duplica\n"
        "toda su potencia."),
        .effect = EFFECT_FICKLE_BEAM,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_FickleBeam,
    },

    [MOVE_BURNING_BULWARK] =
    {
        .name = COMPOUND_STRING("Viento Carámbano"),
        .description = COMPOUND_STRING(
            "Se protege; si contacto,\n"
        "quema al rival."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BURNING_BULWARK },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_BurningBulwark,
    },

    [MOVE_THUNDERCLAP] =
    {
        .name = COMPOUND_STRING("Danza Triunfal"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thunderclap,
    },

    [MOVE_MIGHTY_CLEAVE] =
    {
        .name = COMPOUND_STRING("Arremetida"),
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_MightyCleave,
    },

    [MOVE_TACHYON_CUTTER] =
    {
        .name = COMPOUND_STRING("Mil Púas Tóxicas"),
        .description = COMPOUND_STRING(
            "Dispara dos partículas veloces\n"
        "que nunca pueden fallar."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_TachyonCutter,
    },

    [MOVE_HARD_PRESS] =
    {
        .name = COMPOUND_STRING("Ala Aural"),
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_HardPress,
    },

    [MOVE_DRAGON_CHEER] =
    {
        .name = COMPOUND_STRING("Rencor Reprimido"),
        .description = COMPOUND_STRING(
            "Canto de dragón que sube el\n"
        "ratio crítico de los aliados."),
        .effect = EFFECT_DRAGON_CHEER,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresSubstitute = TRUE,
        .battleAnimScript = gBattleAnimMove_DragonCheer,
    },

    [MOVE_ALLURING_VOICE] =
    {
        .name = COMPOUND_STRING("Retracción"),
        .description = COMPOUND_STRING(
            "Confunde al rival si subió\n"
        "sus estadísticas ese turno."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AlluringVoice,
    },

    [MOVE_TEMPER_FLARE] =
    {
        .name = COMPOUND_STRING("Triple Flecha"),
        .description = COMPOUND_STRING(
            "Ira ígnea; duplica poder si\n"
        "el último movimiento falló."),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_TemperFlare,
    },

    [MOVE_SUPERCELL_SLAM] =
    {
        .name = COMPOUND_STRING("Marcha Espectral"),
        .description = COMPOUND_STRING(
            "Carga electrificada brutal;\n"
        "hiere al usuario si falla."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SupercellSlam,
    },

    [MOVE_PSYCHIC_NOISE] =
    {
        .name = COMPOUND_STRING("Tajo Metralla"),
        .description = COMPOUND_STRING(
            "Onda sónica que daña e impide\n"
        "curarse al rival 2 turnos."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_NOISE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsychicNoise,
    },

    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_UPPER_HAND,
        .name = COMPOUND_STRING("Vendaval Gélido"),
        .description = COMPOUND_STRING(
            "Golpea antes e impone retroceso\n"
        "si el rival usaba prioridad."),
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_UpperHand,
    },

    [MOVE_MALIGNANT_CHAIN] =
    {
        .name = COMPOUND_STRING("Electormenta"),
        .description = COMPOUND_STRING(
            "Cadena de toxinas que suele\n"
        "provoca envenenamiento grave."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_MalignantChain,
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
        .name = COMPOUND_STRING("Simún de Arena"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Normal.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,    //determined from move type
        .battleAnimScript = gBattleAnimMove_BreakneckBlitz,
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .name = COMPOUND_STRING("Plegaria Lunar"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Lucha.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AllOutPummeling,
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .name = COMPOUND_STRING("Bálsamo Osado"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Volador.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SupersonicSkystrike,
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .name = COMPOUND_STRING("Teraexplosión"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Veneno.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AcidDownpour,
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .name = COMPOUND_STRING("Telatrampa"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Tierra.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_TectonicRage,
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .name = COMPOUND_STRING("Patada Hacha"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Roca.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ContinentalCrush,
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("Homenaje Póstumo"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Bicho.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SavageSpinOut,
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("Fotocolisión"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Fantasma.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_NeverEndingNightmare,
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .name = COMPOUND_STRING("Oído Cocina"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Acero.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_CorkscrewCrash,
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("Puño Jet"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Fuego.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_InfernoOverdrive,
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .name = COMPOUND_STRING("Extracto Picante"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Agua.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_HydroVortex,
    },
    [MOVE_BLOOM_DOOM] =
    {
        .name = COMPOUND_STRING("Quemarrueda"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Planta.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BloomDoom,
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .name = COMPOUND_STRING("Proliferación"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Eléctrico.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GigavoltHavoc,
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .name = COMPOUND_STRING("Pirueta Helada"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Psíquico.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ShatteredPsyche,
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .name = COMPOUND_STRING("Asalto Espadón"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Hielo.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SubzeroSlammer,
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .name = COMPOUND_STRING("Plegaria Vital"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Dragón.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_DevastatingDrake,
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .name = COMPOUND_STRING("Salazón"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Siniestro.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BlackHoleEclipse,
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .name = COMPOUND_STRING("Triple Inmersión"),
        .description = COMPOUND_STRING(
            "Ataque Z de tipo Hada.\n"
        "La potencia varía."),
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_TwinkleTackle,
    },
    [MOVE_CATASTROPIKA] =
    {
        .name = COMPOUND_STRING("Giro Mortífero"),
        .description = COMPOUND_STRING(
            "Ataque Z exclusivo de Pikachu\n"
        "con electricidad máxima."),
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_Catastropika,
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("Decalcomanía"),
        .description = COMPOUND_STRING(
            "Ataque Z de Pikachu con gorra;\n"
        "alto ratio de críticos."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .criticalHitStage = 2,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_10000000VoltThunderbolt,
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .name = COMPOUND_STRING("Deslome"),
        .description = COMPOUND_STRING(
            "Ataque Z de Raichu de Alola;\n"
        "paraliza al rival."),
        .effect = EFFECT_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_StokedSparksurfer,
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .name = COMPOUND_STRING("Genufendiente"),
        .description = COMPOUND_STRING(
            "Ataque Z de Eevee; sube todas\n"
        "las características."),
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .battleAnimScript = gBattleAnimMove_ExtremeEvoboost,
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .name = COMPOUND_STRING("Truco Floral"),
        .description = COMPOUND_STRING(
            "Ataque Z de Snorlax lanzado\n"
        "a plena potencia."),
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_PulverizingPancake,
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .name = COMPOUND_STRING("Canto Ardiente"),
        .description = COMPOUND_STRING(
            "Ataque Z de Mew que activa el\n"
        "Campo Psíquico."),
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_GenesisSupernova,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
            .chance = 100,
        }),
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .name = COMPOUND_STRING("Danza Acuática"),
        .description = COMPOUND_STRING(
            "Ataque Z de Decidueye; dispara\n"
        "infinidad de flechas."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SinisterArrowRaid,
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .name = COMPOUND_STRING("Furia Taurina"),
        .description = COMPOUND_STRING(
            "Ataque Z de Incineroar con un\n"
        "salto devastador."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .minimizeDoubleDamage = TRUE,
        .battleAnimScript = gBattleAnimMove_MaliciousMoonsault,
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .name = COMPOUND_STRING("Fiebre Dorada"),
        .description = COMPOUND_STRING(
            "Ataque Z de Primarina con una\n"
        "gigantesca masa de agua."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_OceanicOperetta,
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .name = COMPOUND_STRING("Psicohojas"),
        .description = COMPOUND_STRING(
            "Ataque Z de Lycanroc que elimina\n"
        "todos los terrenos."),
        .effect = EFFECT_ICE_SPINNER,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SplinteredStormshards,
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .name = COMPOUND_STRING("Hidrovapor"),
        .description = COMPOUND_STRING(
            "Ataque Z de Mimikyu que propina\n"
        "una paliza con cariño."),
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LetsSnuggleForever,
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .name = COMPOUND_STRING("Calamidad"),
        .description = COMPOUND_STRING(
            "Kommo-o attacks with full\n"
            "force. Boosts all stats."),
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_ClangorousSoulblaze,
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .name = COMPOUND_STRING("Nitrochoque"),
        .description = COMPOUND_STRING(
            "Ataque Z del Guardián que reduce\n"
        "3/4 de los PS del rival."),
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 75 },
        .battleAnimScript = gBattleAnimMove_GuardianOfAlola,
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .name = COMPOUND_STRING("Electroderrape"),
        .description = COMPOUND_STRING(
            "Ataque Z de Solgaleo que ignora\n"
        "habilidades defensivas."),
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_SearingSunrazeSmash,
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .name = COMPOUND_STRING("Autotomía"),
        .description = COMPOUND_STRING(
            "Ataque Z de Lunala que ignora\n"
        "habilidades defensivas."),
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_MenacingMoonrazeMaelstrom,
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .name = COMPOUND_STRING("Fría Acogida"),
        .description = COMPOUND_STRING(
            "Ataque Z de Necrozma que usa\n"
        "su mejor estadística."),
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_LightThatBurnsTheSky,
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .name = COMPOUND_STRING("Limpieza General"),
        .description = COMPOUND_STRING(
            "Ataque Z de Marshadow con\n"
        "golpes fulminantes."),
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SoulStealing7StarStrike,
    },

    [MOVE_MAX_GUARD] =
    {
        .name = COMPOUND_STRING("Paisaje Nevado"),
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAX_GUARD },
        .battleAnimScript = gBattleAnimMove_MaxGuard,
    },

    [MOVE_MAX_FLARE] =
    {
        .name = COMPOUND_STRING("Martillo Colosal"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Fuego.\n"
        "Pone el clima soleado."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlare,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SUN,
        }),
    },

    [MOVE_MAX_FLUTTERBY] =
    {
        .name = COMPOUND_STRING("Cañón Armadura"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Bicho.\n"
        "Baja el At. Esp. del rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlutterby,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_ATK_SIDE,
        }),
    },

    [MOVE_MAX_LIGHTNING] =
    {
        .name = COMPOUND_STRING("Pirochoque"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Eléctrico.\n"
        "Activa el Campo Eléctrico."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxLightning,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ELECTRIC_TERRAIN,
        }),
    },

    [MOVE_MAX_STRIKE] =
    {
        .name = COMPOUND_STRING("Brinco"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Normal.\n"
        "Baja la Velocidad rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_SIDE,
        }),
    },

    [MOVE_MAX_KNUCKLE] =
    {
        .name = COMPOUND_STRING("Abrecaminos"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Lucha.\n"
        "Sube el Ataque del equipo."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxKnuckle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_ATTACK,
        }),
    },

    [MOVE_MAX_PHANTASM] =
    {
        .name = COMPOUND_STRING("Espada Lamento"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Fantasma.\n"
        "Baja la Defensa del rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxPhantasm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_DEFENSE_SIDE,
        }),
    },

    [MOVE_MAX_HAILSTORM] =
    {
        .name = COMPOUND_STRING("Ponzochoque"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Hielo.\n"
        "Invoca granizo o nieve."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxHailstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAIL,
        }),
    },

    [MOVE_MAX_OOZE] =
    {
        .name = COMPOUND_STRING("Hipertaladro"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Veneno.\n"
        "Sube el At. Esp. del equipo."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOoze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_ATK,
        }),
    },

    [MOVE_MAX_GEYSER] =
    {
        .name = COMPOUND_STRING("Resarcimiento"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Agua.\n"
        "Invoca lluvia en combate."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxGeyser,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAIN,
        }),
    },

    [MOVE_MAX_AIRSTREAM] =
    {
        .name = COMPOUND_STRING("Agua Fría"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Volador.\n"
        "Sube la Velocidad del equipo."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxAirstream,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SPEED,
        }),
    },

    [MOVE_MAX_STARFALL] =
    {
        .name = COMPOUND_STRING("Luna Roja"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Hada.\n"
        "Activa el Campo de Niebla."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStarfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_MISTY_TERRAIN,
        }),
    },

    [MOVE_MAX_WYRMWIND] =
    {
        .name = COMPOUND_STRING("Pugnachoque"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Dragón.\n"
        "Baja el Ataque del rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxWyrmwind,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_ATTACK_SIDE,
        }),
    },

    [MOVE_MAX_MINDSTORM] =
    {
        .name = COMPOUND_STRING("Ominochoque"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Psíquico.\n"
        "Activa el Campo Psíquico."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxMindstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
        }),
    },

    [MOVE_MAX_ROCKFALL] =
    {
        .name = COMPOUND_STRING("Puño Furia"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Roca.\n"
        "Invoca tormenta de arena."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxRockfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDSTORM,
        }),
    },

    [MOVE_MAX_QUAKE] =
    {
        .name = COMPOUND_STRING("Láser Doble"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Tierra.\n"
        "Sube Def. Esp. del equipo."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_MaxQuake,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_DEF,
        }),
    },

    [MOVE_MAX_DARKNESS] =
    {
        .name = COMPOUND_STRING("Feerichoque"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax Siniestro.\n"
        "Baja la Def. Esp. rival."),
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxDarkness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_DEF_SIDE,
        }),
    },

    [MOVE_MAX_OVERGROWTH] =
    {
        .name = COMPOUND_STRING("Tajo Acuático"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Planta.\n"
        "Activa el Campo de Hierba."),
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOvergrowth,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRASSY_TERRAIN,
        }),
    },

    [MOVE_MAX_STEELSPIKE] =
    {
        .name = COMPOUND_STRING("Electropalmas"),
        .description = COMPOUND_STRING(
            "Ataque Dinamax de Acero.\n"
        "Sube la Defensa del equipo."),
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxSteelspike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_DEFENSE,
        }),
    },

    [MOVE_G_MAX_VINE_LASH] =
    {
        .name = COMPOUND_STRING("Cañón Batidor"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Venusaur.\n"
        "Daña durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVineLash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VINE_LASH,
        }),
    },

    [MOVE_G_MAX_WILDFIRE] =
    {
        .name = COMPOUND_STRING("Bomba Caramelo"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Charizard.\n"
        "Daña durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWildfire,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WILDFIRE,
        }),
    },

    [MOVE_G_MAX_CANNONADE] =
    {
        .name = COMPOUND_STRING("Garrote Liana"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Blastoise.\n"
        "Daña durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCannonade,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CANNONADE,
        }),
    },

    [MOVE_G_MAX_BEFUDDLE] =
    {
        .name = COMPOUND_STRING("Electrorrayo"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Butterfree.\n"
        "Envenena, paraliza o duerme."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxBefuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EFFECT_SPORE_SIDE,
        }),
    },

    [MOVE_G_MAX_VOLT_CRASH] =
    {
        .name = COMPOUND_STRING("Teraclúster"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Pikachu.\n"
        "Paraliza a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVoltCrash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_GOLD_RUSH] =
    {
        .name = COMPOUND_STRING("Láser Veleidoso"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Meowth.\n"
        "Confunde y da dinero."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGoldRush,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE,
        }),
    },

    [MOVE_G_MAX_CHI_STRIKE] =
    {
        .name = COMPOUND_STRING("Llama Protectora"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Machamp.\n"
        "Aumenta la probabilidad crítica."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxChiStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CRIT_PLUS_SIDE,
        }),
    },

    [MOVE_G_MAX_TERROR] =
    {
        .name = COMPOUND_STRING("Relámpago Súbito"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Gengar.\n"
        "Impide escapar a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTerror,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE_SIDE,
        }),
    },

    [MOVE_G_MAX_FOAM_BURST] =
    {
        .name = COMPOUND_STRING("Filo Potente"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Kingler.\n"
        "Baja mucho la Velocidad rival."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFoamBurst,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_2_SIDE,
        }),
    },

    [MOVE_G_MAX_RESONANCE] =
    {
        .name = COMPOUND_STRING("Tajo Taquión"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Lapras.\n"
        "Reduce daño durante 5 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxResonance,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AURORA_VEIL,
        }),
    },

    [MOVE_G_MAX_CUDDLE] =
    {
        .name = COMPOUND_STRING("Prensa Metálica"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Eevee.\n"
        "Enamora a los oponentes."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INFATUATE_SIDE,
        }),
    },

    [MOVE_G_MAX_REPLENISH] =
    {
        .name = COMPOUND_STRING("Bramido Dragón"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Snorlax.\n"
        "Restaura las bayas comidas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxReplenish,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECYCLE_BERRIES,
        }),
    },

    [MOVE_G_MAX_MALODOR] =
    {
        .name = COMPOUND_STRING("Canto Encantador"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Garbodor.\n"
        "Envenena a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMalodor,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_SIDE,
        }),
    },

    [MOVE_G_MAX_MELTDOWN] =
    {
        .name = COMPOUND_STRING("Cólera Ardiente"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Melmetal.\n"
        "Impide repetir movimientos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMeltdown,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TORMENT_SIDE,
        }),
    },

    [MOVE_G_MAX_DRUM_SOLO] =
    {
        .name = COMPOUND_STRING("Plancha Voltaica"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Rillaboom.\n"
        "Ignora habilidades rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxDrumSolo,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_FIREBALL] =
    {
        .name = COMPOUND_STRING("Psicorruido"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Cinderace.\n"
        "Ignora habilidades rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxFireball,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_HYDROSNIPE] =
    {
        .name = COMPOUND_STRING("Palma Rauda"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Inteleon.\n"
        "Ignora habilidades rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxHydrosnipe,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_WIND_RAGE] =
    {
        .name = COMPOUND_STRING("Cadena Virulenta"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Corviknight.\n"
        "Elimina pantallas del rival."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWindRage,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEFOG,
        }),
    },

    [MOVE_G_MAX_GRAVITAS] =
    {
        .name = COMPOUND_STRING("Gigagravidez"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Orbeetle.\n"
        "Cambia la gravedad 5 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGravitas,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRAVITY,
        }),
    },

    [MOVE_G_MAX_STONESURGE] =
    {
        .name = COMPOUND_STRING("Gigarroca Puntiaguda"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Drednaw.\n"
        "Lanza rocas puntiagudas."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStonesurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEALTH_ROCK,
        }),
    },

    [MOVE_G_MAX_VOLCALITH] =
    {
        .name = COMPOUND_STRING("Gigarroca Ígnea"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Coalossal.\n"
        "Daña durante 4 turnos."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVolcalith,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VOLCALITH,
        }),
    },

    [MOVE_G_MAX_TARTNESS] =
    {
        .name = COMPOUND_STRING("Gigacorrosión Ácida"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Flapple.\n"
        "Reduce la Evasión rival."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTartness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_EVASIVENESS_SIDE,
        }),
    },

    [MOVE_G_MAX_SWEETNESS] =
    {
        .name = COMPOUND_STRING("Giganéctar"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Appletun.\n"
        "Cura problemas de estado."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSweetness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
    },

    [MOVE_G_MAX_SANDBLAST] =
    {
        .name = COMPOUND_STRING("Gigapolvareda"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Sandaconda.\n"
        "Atrapa en tormenta de arena."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSandblast,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDBLAST_SIDE,
        }),
    },

    [MOVE_G_MAX_STUN_SHOCK] =
    {
        .name = COMPOUND_STRING("Gigadescarga"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Toxtricity.\n"
        "Envenena o paraliza rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStunShock,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_CENTIFERNO] =
    {
        .name = COMPOUND_STRING("Gigaciempiés"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Centiskorch.\n"
        "Atrapa en llamas al rival."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCentiferno,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIRE_SPIN_SIDE,
        }),
    },

    [MOVE_G_MAX_SMITE] =
    {
        .name = COMPOUND_STRING("Gigacastigo"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Hatterene.\n"
        "Confunde a los rivales."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSmite,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_SIDE,
        }),
    },


    [MOVE_G_MAX_SNOOZE] =
    {
        .name = COMPOUND_STRING("Gigasopor"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Grimmsnarl.\n"
        "Duerme a los oponentes."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSnooze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_YAWN_FOE,
        }),
    },

    [MOVE_G_MAX_FINALE] =
    {
        .name = COMPOUND_STRING("Gigacolofón"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Alcremie.\n"
        "Restaura PS a los aliados."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFinale,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HEAL_TEAM,
        }),
    },

    [MOVE_G_MAX_STEELSURGE] =
    {
        .name = COMPOUND_STRING("Gigaestampida"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Copperajah.\n"
        "Esparce púas de acero."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSteelsurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEELSURGE,
        }),
    },

    [MOVE_G_MAX_DEPLETION] =
    {
        .name = COMPOUND_STRING("Gigadesgaste"),
        .description = COMPOUND_STRING(
            "Ataque Gigamax de Duraludon.\n"
        "Reduce PP del objetivo."),    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxDepletion,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPITE,
        }),
    },

    [MOVE_G_MAX_ONE_BLOW] =
    {
        .name = COMPOUND_STRING("Gigagolpe Brusco"),
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxOneBlow,
    },

    [MOVE_G_MAX_RAPID_FLOW] =
    {
        .name = COMPOUND_STRING("Gigagolpe Fluido"),
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxRapidFlow,
    },
};
