#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H

#include "global.h"
#include "constants/quests.h"

struct Quest
{
    u16 id;
    const u8 *title;
    const u8 *giver;
    const u8 *location;
    const u8 *desc;
    const u8 *descCompleted;
    u16 checkFlagStart;
    u16 checkFlagComplete;
};

void Quest_InitSaveData(void);
void Quest_Start(u16 questId);
void Quest_SetStage(u16 questId, u8 stage);
void Quest_Complete(u16 questId);
u8 Quest_GetStatus(u16 questId);
bool8 Quest_IsActive(u16 questId);
bool8 Quest_IsCompleted(u16 questId);
bool8 Quest_HasAnyQuests(void);
u8 Quest_GetActiveCount(void);
u8 Quest_GetCompletedCount(void);
u8 Quest_GetTotalAssignedCount(void);
const struct Quest *Quest_GetQuestData(u16 questId);
u16 Quest_GetAssignedQuestIdByIndex(u8 index, bool8 activeOnly);

// Specials para el motor de scripts
void Special_QuestStart(void);
void Special_QuestSetStage(void);
void Special_QuestComplete(void);
void Special_QuestGetStatus(void);
void Special_QuestHasAny(void);
void Special_BufferQuestTitle(void);

#endif // GUARD_QUESTS_H

