#include "global.h"
#include "quests.h"
#include "event_data.h"
#include "string_util.h"
#include "strings.h"
#include "constants/flags_hns.h"
#include "constants/vars_hns.h"

static const u8 sText_QuestTitle_Manolin[] = _("El colega Manolín");
static const u8 sText_QuestGiver_Manolin[] = _("Manolín");
static const u8 sText_QuestLoc_Manolin[]   = _("Ruta 34");
static const u8 sText_QuestDesc_Manolin[]  = _("Manolín te ha pedido que le eches\nun cable con sus asuntos en Johto.\n¡Búscalo para ver qué trama!");
static const u8 sText_QuestDone_Manolin[]  = _("Has cumplido el encargo de\nManolín. ¡Menuda pieza!");

static const u8 sText_QuestTitle_Piedras[] = _("El Coleccionista de Rocas");
static const u8 sText_QuestGiver_Piedras[] = _("El Piedras");
static const u8 sText_QuestLoc_Piedras[]   = _("Cueva Unión");
static const u8 sText_QuestDesc_Piedras[]  = _("El Piedras busca minerales y fósiles\nraros por las cuevas de Johto.\nLlévale lo que descubras.");
static const u8 sText_QuestDone_Piedras[]  = _("El Piedras ha quedado satisfecho\ncon las rocas que le trajiste.");

static const u8 sText_QuestTitle_Mohedano[] = _("Conspiración en Kanto");
static const u8 sText_QuestGiver_Mohedano[] = _("Prof. Mohedano");
static const u8 sText_QuestLoc_Mohedano[]   = _("Silph S.A. / Kanto");
static const u8 sText_QuestDesc_Mohedano[]  = _("El Profesor Mohedano investiga\nanomalías ecológicas y células raras.\nPermanece atento a sus avisos.");
static const u8 sText_QuestDone_Mohedano[]  = _("Has colaborado en resolver la trama\necológica del Prof. Mohedano.");

static const u8 sText_QuestTitle_Magikarp[] = _("El Magikarp Gigante");
static const u8 sText_QuestGiver_Magikarp[] = _("Pescador");
static const u8 sText_QuestLoc_Magikarp[]   = _("Lago de la Furia");
static const u8 sText_QuestDesc_Magikarp[]  = _("Un pescador busca el espécimen de\nMagikarp más grande del lago.\nPesca uno enorme y enséñaselo.");
static const u8 sText_QuestDone_Magikarp[]  = _("Has registrado un Magikarp récord\npara el asombro del pescador.");

static const u8 sText_QuestTitle_Pokemitos[] = _("Carnet Pokemitos");
static const u8 sText_QuestGiver_Pokemitos[] = _("Comité Pokemitos");
static const u8 sText_QuestLoc_Pokemitos[]   = _("Johto / Kanto");
static const u8 sText_QuestDesc_Pokemitos[]  = _("Desafío especial para entrenadores.\nDemuestra tu valía en combate\nbajo las reglas del carnet.");
static const u8 sText_QuestDone_Pokemitos[]  = _("Has superado las pruebas de la\nCopa Pokemitos con éxito.");

static const u8 sText_QuestTitle_Malva[] = _("Expedición Malva");
static const u8 sText_QuestGiver_Malva[] = _("Arqueólogo");
static const u8 sText_QuestLoc_Malva[]   = _("Ciudad Malva");
static const u8 sText_QuestDesc_Malva[]  = _("Unos investigadores exploran los\nantiguos misterios de las ruinas\ny torres sagradas de Johto.");
static const u8 sText_QuestDone_Malva[]  = _("Has desvelado los enigmas de la\nexpedición de Ciudad Malva.");

static const struct Quest sQuestsTable[QUEST_COUNT] =
{
    [QUEST_MANOLIN_1] = {
        .id = QUEST_MANOLIN_1,
        .title = sText_QuestTitle_Manolin,
        .giver = sText_QuestGiver_Manolin,
        .location = sText_QuestLoc_Manolin,
        .desc = sText_QuestDesc_Manolin,
        .descCompleted = sText_QuestDone_Manolin,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
    [QUEST_EL_PIEDRAS] = {
        .id = QUEST_EL_PIEDRAS,
        .title = sText_QuestTitle_Piedras,
        .giver = sText_QuestGiver_Piedras,
        .location = sText_QuestLoc_Piedras,
        .desc = sText_QuestDesc_Piedras,
        .descCompleted = sText_QuestDone_Piedras,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
    [QUEST_PROFESOR_MOHEDANO] = {
        .id = QUEST_PROFESOR_MOHEDANO,
        .title = sText_QuestTitle_Mohedano,
        .giver = sText_QuestGiver_Mohedano,
        .location = sText_QuestLoc_Mohedano,
        .desc = sText_QuestDesc_Mohedano,
        .descCompleted = sText_QuestDone_Mohedano,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
    [QUEST_CONCURSO_MAGIKARP] = {
        .id = QUEST_CONCURSO_MAGIKARP,
        .title = sText_QuestTitle_Magikarp,
        .giver = sText_QuestGiver_Magikarp,
        .location = sText_QuestLoc_Magikarp,
        .desc = sText_QuestDesc_Magikarp,
        .descCompleted = sText_QuestDone_Magikarp,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
    [QUEST_CARNET_POKEMITOS] = {
        .id = QUEST_CARNET_POKEMITOS,
        .title = sText_QuestTitle_Pokemitos,
        .giver = sText_QuestGiver_Pokemitos,
        .location = sText_QuestLoc_Pokemitos,
        .desc = sText_QuestDesc_Pokemitos,
        .descCompleted = sText_QuestDone_Pokemitos,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
    [QUEST_EXPEDICION_MALVA] = {
        .id = QUEST_EXPEDICION_MALVA,
        .title = sText_QuestTitle_Malva,
        .giver = sText_QuestGiver_Malva,
        .location = sText_QuestLoc_Malva,
        .desc = sText_QuestDesc_Malva,
        .descCompleted = sText_QuestDone_Malva,
        .checkFlagStart = 0,
        .checkFlagComplete = 0,
    },
};

void Quest_InitSaveData(void)
{
    u32 i;
    for (i = 0; i < MAX_QUESTS; i++)
        gSaveBlock1Ptr->questStates[i] = QUEST_STATUS_UNASSIGNED;

    // Sincronización con eventos existentes en partidas ya empezadas
    if (FlagGet(FLAG_DEFEATED_EL_PIEDRAS_GOLDENROD))
        gSaveBlock1Ptr->questStates[QUEST_EL_PIEDRAS] = QUEST_STATUS_ACTIVE;
    if (FlagGet(FLAG_TALKED_EL_PIEDRAS_LAKE_OF_RAGE))
        gSaveBlock1Ptr->questStates[QUEST_EL_PIEDRAS] = QUEST_STATUS_COMPLETED;
}

const struct Quest *Quest_GetQuestData(u16 questId)
{
    if (questId >= QUEST_COUNT)
        return NULL;
    return &sQuestsTable[questId];
}

void Quest_Start(u16 questId)
{
    if (questId >= MAX_QUESTS)
        return;

    // Solo se inicia si no estaba ya completada
    if (gSaveBlock1Ptr->questStates[questId] != QUEST_STATUS_COMPLETED)
        gSaveBlock1Ptr->questStates[questId] = QUEST_STATUS_ACTIVE;
}

void Quest_SetStage(u16 questId, u8 stage)
{
    if (questId >= MAX_QUESTS)
        return;

    gSaveBlock1Ptr->questStates[questId] = stage;
}

void Quest_Complete(u16 questId)
{
    if (questId >= MAX_QUESTS)
        return;

    gSaveBlock1Ptr->questStates[questId] = QUEST_STATUS_COMPLETED;
}

u8 Quest_GetStatus(u16 questId)
{
    if (questId >= MAX_QUESTS)
        return QUEST_STATUS_UNASSIGNED;

    return gSaveBlock1Ptr->questStates[questId];
}

bool8 Quest_IsActive(u16 questId)
{
    u8 status = Quest_GetStatus(questId);
    return (status != QUEST_STATUS_UNASSIGNED && status != QUEST_STATUS_COMPLETED);
}

bool8 Quest_IsCompleted(u16 questId)
{
    return (Quest_GetStatus(questId) == QUEST_STATUS_COMPLETED);
}

bool8 Quest_HasAnyQuests(void)
{
    u32 i;
    for (i = 0; i < QUEST_COUNT; i++)
    {
        if (gSaveBlock1Ptr->questStates[i] != QUEST_STATUS_UNASSIGNED)
            return TRUE;
    }
    return FALSE;
}

u8 Quest_GetActiveCount(void)
{
    u32 i;
    u8 count = 0;
    for (i = 0; i < QUEST_COUNT; i++)
    {
        if (Quest_IsActive(i))
            count++;
    }
    return count;
}

u8 Quest_GetCompletedCount(void)
{
    u32 i;
    u8 count = 0;
    for (i = 0; i < QUEST_COUNT; i++)
    {
        if (Quest_IsCompleted(i))
            count++;
    }
    return count;
}

u8 Quest_GetTotalAssignedCount(void)
{
    u32 i;
    u8 count = 0;
    for (i = 0; i < QUEST_COUNT; i++)
    {
        if (gSaveBlock1Ptr->questStates[i] != QUEST_STATUS_UNASSIGNED)
            count++;
    }
    return count;
}

u16 Quest_GetAssignedQuestIdByIndex(u8 targetIndex, bool8 activeOnly)
{
    u32 i;
    u8 currentIndex = 0;

    for (i = 0; i < QUEST_COUNT; i++)
    {
        bool8 match = FALSE;
        if (activeOnly)
            match = Quest_IsActive(i);
        else
            match = (gSaveBlock1Ptr->questStates[i] != QUEST_STATUS_UNASSIGNED);

        if (match)
        {
            if (currentIndex == targetIndex)
                return i;
            currentIndex++;
        }
    }
    return 0xFFFF;
}

// Specials para el motor de scripting
void Special_QuestStart(void)
{
    u16 questId = VarGet(VAR_0x8004);
    Quest_Start(questId);
}

void Special_QuestSetStage(void)
{
    u16 questId = VarGet(VAR_0x8004);
    u8 stage = VarGet(VAR_0x8005);
    Quest_SetStage(questId, stage);
}

void Special_QuestComplete(void)
{
    u16 questId = VarGet(VAR_0x8004);
    Quest_Complete(questId);
}

void Special_QuestGetStatus(void)
{
    u16 questId = VarGet(VAR_0x8004);
    gSpecialVar_Result = Quest_GetStatus(questId);
}

void Special_QuestHasAny(void)
{
    gSpecialVar_Result = Quest_HasAnyQuests();
}

void Special_BufferQuestTitle(void)
{
    u16 questId = VarGet(VAR_0x8004);
    const struct Quest *q = Quest_GetQuestData(questId);
    if (q != NULL)
        StringCopy(gStringVar1, q->title);
    else
        StringCopy(gStringVar1, gText_EmptyString2);
}
