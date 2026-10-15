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
	call_if_unset FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_ShowZapdos
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	end

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

PowerPlant_EventScript_ProfessorMohedano::
	lock
	faceplayer
	goto_if_set FLAG_MOHEDANO_POWER_PLANT_DEFEATED, PowerPlant_EventScript_ProfessorMohedano_Post
	msgbox PowerPlant_Text_MohedanoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PROFESSOR_MOHEDANO_HNS, PowerPlant_Text_MohedanoDefeated
	msgbox PowerPlant_Text_MohedanoAfter, MSGBOX_DEFAULT
	giveitem ITEM_MIMINUCLEO_TARAFANTASTICO
	setflag FLAG_MOHEDANO_POWER_PLANT_DEFEATED
	release
	end

PowerPlant_EventScript_ProfessorMohedano_Post::
	msgbox PowerPlant_Text_MohedanoPostDialogue, MSGBOX_DEFAULT
	release
	end

PowerPlant_Text_MohedanoIntro:
	.string "¡Ja, ja, ja! ¿Un emisario de esa\n"
	.string "empresa de pacotilla?\p"
	.string "¡Yo soy el Profesor Mohedano!\n"
	.string "¡Pionero de la libre ciencia!\p"
	.string "Silph quería confinar las células\n"
	.string "del gran Zygarde bajo patentes\l"
	.string "y beneficios comerciales.\p"
	.string "¡El equilibrio del mundo pertenece\n"
	.string "a la naturaleza viva!\p"
	.string "Estoy cargando este Miminúcleo\n"
	.string "Tarafantástico con voltios puros.\p"
	.string "¿Quieres arrebatármelo?\n"
	.string "¡Demuestra si tu ciencia y tu\l"
	.string "espíritu están a mi altura!$"

PowerPlant_Text_MohedanoDefeated:
	.string "¡Qué voltaje! ¡Una potencia\n"
	.string "bioquímica deslumbrante!$"

PowerPlant_Text_MohedanoAfter:
	.string "Impresionante... Tus Pokémon vibran\n"
	.string "en resonancia natural.\p"
	.string "Quizás me equivoqué contigo.\n"
	.string "Toma el Miminúcleo Tarafantástico.\p"
	.string "Asegúrate de que el Arca sirva\n"
	.string "a la vida y no al interés de\l"
	.string "las oficinas de Silph S.A.$"

PowerPlant_Text_MohedanoPostDialogue:
	.string "Seguiré estudiando los campos\n"
	.string "magnéticos de este viejo lugar.\p"
	.string "¡La verdadera ciencia nunca duerme,\n"
	.string "joven prodigio!$"

