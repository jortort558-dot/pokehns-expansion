#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u32 ScriptGiveMon(u16 species, u8 level, enum Item item);
u8 ScriptGiveEgg(u16 species);
void CreateScriptedWildMon(u16 species, u8 level, enum Item item);
void CreateShinyScriptedMon(u16 species, u8 level, enum Item item);
void CreateScriptedWildBossMon(u16 species, u8 level, enum Item item, enum Move moves[MAX_MON_MOVES]);
void CreateScriptedDoubleWildBossMon(u16 species1, u8 level1, enum Item item1, enum Move moves1[MAX_MON_MOVES], \
    u16 species2, u8 level2, enum Item item2, \
    enum Move moves2[MAX_MON_MOVES]);
void CreateScriptedDoubleWildMon(u16 species, u8 level, enum Item item, u16 species2, u8 level2, enum Item item2);
void ScriptSetMonMoveSlot(u8 monIndex, enum Move move, u8 slot);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);
void Script_GetChosenMonOffensiveEVs(void);
void Script_GetChosenMonDefensiveEVs(void);
void Script_GetChosenMonOffensiveIVs(void);
void Script_GetChosenMonDefensiveIVs(void);
void YamiSuperTraining_CanTrainStat(void);
void YamiSuperTraining_AddEVs(void);
void YamiSuperTraining_ResetEVs(void);
void DaraOtaku_CheckAndPrepareAbilities(void);
void DaraOtaku_PrepareChoiceAbility(void);
void DaraOtaku_ApplyAbilityChange(void);
void DaraOtaku_CheckAndPrepareEvolutionAbilities(void);
void DaraOtaku_PrepareChosenEvoAbilityName(void);
void DaraOtaku_ApplyEvolutionAbilityChange(void);
void DoctoriniBea_CheckGender(void);
void DoctoriniBea_ApplyGenderChange(void);
void DoctoreFernan_CheckAndPrepareForms(void);
void DoctoreFernan_ApplyFormChange(void);
void DoctoreFernan_ShowPreview(void);
void DoctoreFernan_HidePreview(void);
void Script_GiveRandomLegendaryEgg(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
