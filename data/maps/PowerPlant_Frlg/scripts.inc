PowerPlant_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PowerPlant_EventScript_TryRemoveStaticMon
	end

PowerPlant_EventScript_TryRemoveStaticMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

PowerPlant_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call PowerPlant_EventScript_UpdateSitoVisibility
	call_if_unset FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_ShowZapdos
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	end

PowerPlant_EventScript_UpdateSitoVisibility::
	goto_if_set FLAG_SITO_POWER_PLANT_DEFEATED, PowerPlant_EventScript_HideSito
	goto_if_set FLAG_MOHEDANO_QUEST_STARTED, PowerPlant_EventScript_ShowSito

PowerPlant_EventScript_HideSito::
	setflag FLAG_HIDE_POWER_PLANT_SITO
	return

PowerPlant_EventScript_ShowSito::
	clearflag FLAG_HIDE_POWER_PLANT_SITO
	return

PowerPlant_EventScript_ShowZapdos::
	clearflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
	return

PowerPlant_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_Zapdos::
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdos::
	setflag FLAG_FOUGHT_ZAPDOS
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode1
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	release
	end

PowerPlant_EventScript_FoughtElectrode1::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	release
	end

PowerPlant_EventScript_FoughtElectrode2::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Sito::
	lock
	faceplayer
	goto_if_defeated TRAINER_SITO_POWER_PLANT_HNS, PowerPlant_EventScript_SitoReward
	msgbox PowerPlant_Text_SitoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SITO_POWER_PLANT_HNS, PowerPlant_Text_SitoDefeated

PowerPlant_EventScript_SitoReward::
	checkitemspace ITEM_MIMINUCLEO_TARAFANTASTICO, 1
	goto_if_eq VAR_RESULT, FALSE, PowerPlant_EventScript_SitoBagFull
	msgbox PowerPlant_Text_SitoAfter, MSGBOX_DEFAULT
	giveitem ITEM_MIMINUCLEO_TARAFANTASTICO
	setflag FLAG_SITO_POWER_PLANT_DEFEATED
	setflag FLAG_HIDE_POWER_PLANT_SITO
	removeobject VAR_LAST_TALKED
	release
	end

PowerPlant_EventScript_SitoBagFull::
	msgbox PowerPlant_Text_SitoBagFull, MSGBOX_DEFAULT
	release
	end

PowerPlant_Text_SitoIntro:
	.string "¡Anda! ¡Si es el recadero de\n"
	.string "Silph!\p"
	.string "Este cacharro daba unos chispazos\n"
	.string "guapísimos, así que me lo llevé.\p"
	.string "Mis chicas y yo nos lo estamos\n"
	.string "pasando de miedo.\p"
	.string "¿Lo quieres? ¡Pues tendrás que\n"
	.string "quitárnoslo!$"

PowerPlant_Text_SitoDefeated:
	.string "¡Pero si mis perras tenían el\n"
	.string "combate controladísimo!$"

PowerPlant_Text_SitoAfter:
	.string "Vale, vale... Toma el cacharro.\p"
	.string "Yo no he estado aquí y tú no me\n"
	.string "has visto. ¡Hasta luego!$"

PowerPlant_Text_SitoBagFull:
	.string "¡No te cabe el cacharro!\n"
	.string "Haz sitio y vuelve.$"
