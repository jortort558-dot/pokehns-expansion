MtMoon_Cave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtMoon_Cave_MapScript_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_Cave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMoon_Cave_OnTransition: 
	callnative SetTimeBasedEncounters
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SCIENTIST_M_HNS
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_OnTransition_SetIntro
	goto_if_set FLAG_MT_MOON_INVESTIGATION_COMPLETE, MtMoon_Cave_OnTransition_QuestComplete
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_GYM_GUY_HNS
	setflag FLAG_HIDE_MT_MOON_QUEST_CLEFAIRY
	goto MtMoon_Cave_OnTransition_SetIntro

MtMoon_Cave_OnTransition_QuestComplete:
	clearflag FLAG_HIDE_MT_MOON_QUEST_CLEFAIRY

MtMoon_Cave_OnTransition_SetIntro:
	setvar VAR_TEMP_C, 1
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_OnTransition_End
	goto_if_set FLAG_MT_MOON_ECHO_CHAMBER_INTRO, MtMoon_Cave_OnTransition_End
	setvar VAR_TEMP_C, 0

MtMoon_Cave_OnTransition_End:
	end


MtMoon_Cave_MapScript_OnFrame::
	map_script_2 VAR_PEWTER_CITY_STATE, 0, MtMoon_Cave_EventScript_Silver
	map_script_2 VAR_PEWTER_CITY_STATE, 1, MtMoon_Cave_EventScript_Silver
	map_script_2 VAR_TEMP_C, 0, MtMoon_Cave_EventScript_EchoChamberIntro
	.2byte 0

MtMoon_Cave_EventScript_EchoChamberIntro::
	setvar VAR_TEMP_C, 1
	lock
	special EnableGlasstownMessageBox
	msgbox MtMoon_Cave_Text_EchoChamberIntro, MSGBOX_DEFAULT
	setflag FLAG_MT_MOON_ECHO_CHAMBER_INTRO
	release
	end

MtMoon_Cave_EventScript_Batemagico::
	lock
	faceplayer
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_EventScript_Scientist
	setspeaker SP_NAME_BATEMAGICO
	goto_if_set FLAG_MT_MOON_INVESTIGATION_COMPLETE, MtMoon_Cave_EventScript_BatemagicoAfter
	goto_if_unset FLAG_MT_MOON_FOSSIL_TRACE, MtMoon_Cave_EventScript_BatemagicoCluesRemain
	goto_if_unset FLAG_MT_MOON_GEODUDE_TRACE, MtMoon_Cave_EventScript_BatemagicoCluesRemain
	goto_if_unset FLAG_MT_MOON_ALTAR_TRACE, MtMoon_Cave_EventScript_BatemagicoCluesRemain
	goto MtMoon_Cave_EventScript_LunarGuardian

MtMoon_Cave_EventScript_Scientist:
	msgbox MtMoon_Cave_Text_Scientist, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_BatemagicoCluesRemain:
	msgbox MtMoon_Cave_Text_BatemagicoCluesRemain, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_LunarGuardian:
	msgbox MtMoon_Cave_Text_BatemagicoCluesComplete, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LUNATONE, 0
	waitmoncry
	msgbox MtMoon_Cave_Text_LunatoneAppears, MSGBOX_DEFAULT
	setwildbattle SPECIES_LUNATONE, 62, ITEM_STARDUST
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MtMoon_Cave_EventScript_LunarGuardianDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMoon_Cave_EventScript_LunarGuardianDefeated
	release
	end

MtMoon_Cave_EventScript_LunarGuardianDefeated:
	setflag FLAG_MT_MOON_LUNATONE_DEFEATED
	clearflag FLAG_HIDE_MT_MOON_QUEST_CLEFAIRY
	addobject LOCALID_MTMOON_QUEST_CLEFAIRY_NORTH
	addobject LOCALID_MTMOON_QUEST_CLEFAIRY
	special EnableGlasstownMessageBox
	msgbox MtMoon_Cave_Text_ClefairyReturn, MSGBOX_DEFAULT
	setspeaker SP_NAME_BATEMAGICO
	msgbox MtMoon_Cave_Text_BatemagicoConclusion, MSGBOX_DEFAULT
	setflag FLAG_MT_MOON_INVESTIGATION_COMPLETE
	release
	end

MtMoon_Cave_EventScript_BatemagicoAfter:
	msgbox MtMoon_Cave_Text_BatemagicoAfter, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_FossilTrace::
	lock
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_EventScript_FossilNormal
	goto_if_set FLAG_MT_MOON_INVESTIGATION_COMPLETE, MtMoon_Cave_EventScript_FossilNormal
	goto_if_set FLAG_MT_MOON_FOSSIL_TRACE, MtMoon_Cave_EventScript_FossilAlreadyChecked
	special EnableGlasstownMessageBox
	msgbox MtMoon_Cave_Text_FossilTrace, MSGBOX_DEFAULT
	setflag FLAG_MT_MOON_FOSSIL_TRACE
	release
	end

MtMoon_Cave_EventScript_FossilAlreadyChecked:
	msgbox MtMoon_Cave_Text_FossilAlreadyChecked, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_FossilNormal:
	msgbox MtMoon_Cave_Text_FossilNormal, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_GeodudeTrace::
	lock
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_EventScript_GeodudeNormal
	goto_if_set FLAG_MT_MOON_INVESTIGATION_COMPLETE, MtMoon_Cave_EventScript_GeodudeNormal
	goto_if_set FLAG_MT_MOON_GEODUDE_TRACE, MtMoon_Cave_EventScript_GeodudeAlreadyChecked
	playmoncry SPECIES_GEODUDE, 0
	waitmoncry
	special EnableGlasstownMessageBox
	msgbox MtMoon_Cave_Text_GeodudeTrace, MSGBOX_DEFAULT
	setflag FLAG_MT_MOON_GEODUDE_TRACE
	release
	end

MtMoon_Cave_EventScript_GeodudeAlreadyChecked:
	msgbox MtMoon_Cave_Text_GeodudeAlreadyChecked, MSGBOX_DEFAULT
	release
	end

MtMoon_Cave_EventScript_GeodudeNormal:
	playmoncry SPECIES_GEODUDE, 0
	msgbox MtMoon_Cave_Text_GeodudeNormal, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MtMoon_Cave_EventScript_QuestClefairy::
	lock
	playmoncry SPECIES_CLEFAIRY, 0
	msgbox MtMoon_Cave_Text_QuestClefairy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MtMoon_Cave_EventScript_Sign::
	goto_if_unset FLAG_BATEMAGICO_MT_MOON_LEAD, MtMoon_Cave_EventScript_SignNormal
	goto_if_set FLAG_MT_MOON_INVESTIGATION_COMPLETE, MtMoon_Cave_EventScript_SignNormal
	goto_if_set FLAG_MT_MOON_ALTAR_TRACE, MtMoon_Cave_EventScript_AltarAlreadyChecked
	lock
	special EnableGlasstownMessageBox
	msgbox MtMoon_Cave_Text_AltarTrace, MSGBOX_DEFAULT
	setflag FLAG_MT_MOON_ALTAR_TRACE
	release
	end

MtMoon_Cave_EventScript_AltarAlreadyChecked:
	msgbox MtMoon_Cave_Text_AltarAlreadyChecked, MSGBOX_SIGN
	end

MtMoon_Cave_EventScript_SignNormal:
	msgbox MtMoon_Cave_Text_Sign, MSGBOX_SIGN
	end

MtMoon_Cave_EventScript_Silver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_PIN
	applymovement2 LOCALID_MTMOON_SILVER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement2 LOCALID_MTMOON_SILVER MtMoon_Cave_Movement_WalkToPlayer
	applymovement2 OBJ_EVENT_ID_PLAYER Common_Movement_WalkRight1
	waitmovement LOCALID_MTMOON_SILVER
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MtMoon_Cave_Text_Rival_Before, MSGBOX_DEFAULT
	goto_if_eq VAR_STARTER_MON, 0, MtMoon_Cave_EventScript_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, MtMoon_Cave_EventScript_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, MtMoon_Cave_EventScript_Silver_Battle_Chikorita
	release
	end

MtMoon_Cave_EventScript_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_SilverAfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox MtMoon_Cave_Text_Rival_After, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_MTMOON_SILVER, MtMoon_Cave_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_MTMOON_SILVER
	setflag FLAG_HIDE_MTMOON_SILVER
	clearflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
	setvar VAR_PEWTER_CITY_STATE, 2
	fadedefaultbgm
	release
	end

MtMoon_Cave_Movement_WalkToPlayer:
	walk_left
	walk_left
	walk_left
	step_end

MtMoon_Cave_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

MtMoon_Cave_Text_Rival_Before:
	.string "Cuánto tiempo, {PLAYER}.\n"
	.string "Ya echabas de menos mi cara, ¿eh?\p"
	.string "Desde que perdí contra ti, pensé\n"
	.string "qué les faltaba a mis POKéMON…\p"
	.string "Y encontramos una respuesta.\p"
	.string "¡Prepárate, que te la vamos a\n"
	.string "enseñar por las malas!$"

MtMoon_Cave_Text_Rival_Win:
	.string "¡Me cago en todo…!\p"
	.string "Creía haber criado a mis POKéMON\n"
	.string "para que fueran los mejores…\p"
	.string "Pero aún no ha bastado…$"

MtMoon_Cave_Text_Rival_After:
	.string "Has ganado limpiamente, sí.\n"
	.string "Pero no te vengas arriba.\p"
	.string "Lo admito. Pero esto no ha acabado.\p"
	.string "Seré el mejor Entrenador POKéMON\n"
	.string "de la historia.\p"
	.string "Porque ellos me apoyan.\p"
	.string "Escucha, {PLAYER}.\p"
	.string "Algún día te cerraré la boca\n"
	.string "derrotándote como toca.$"

MtMoon_Cave_Text_Rival_Loss:
	.string "¡Ja! Ya he saldado mi deuda\n"
	.string "contigo, pringao.\p"
	.string "Con mis POKéMON venceré al CAMPEÓN\n"
	.string "y seré el mejor Entrenador.$"

MtMoon_Cave_Text_Sign:
	.string "PLAZA MT. MOON ->$"

MtMoon_Cave_Text_EchoChamberIntro:
	.string "El aire pesa de una forma extraña.\p"
	.string "En algún lugar de la montaña,\n"
	.string "una piedra responde a otra.\p"
	.string "No se oye cantar a ningún\n"
	.string "CLEFAIRY.$"

MtMoon_Cave_Text_Scientist:
	.string "Estudio la respuesta magnética\n"
	.string "de los minerales de esta cueva.$"

MtMoon_Cave_Text_BatemagicoCluesRemain:
	.string "La montaña no se ha quedado muda\n"
	.string "porque sí, {PLAYER}.\p"
	.string "Busca tres focos de resonancia:\n"
	.string "el fósil, los GEODUDE y el altar.\p"
	.string "Toca, escucha y vuelve conmigo.\n"
	.string "Aquí hasta el silencio habla.$"

MtMoon_Cave_Text_BatemagicoCluesComplete:
	.string "Tres pulsos con el mismo intervalo.\n"
	.string "Esto no es un fenómeno natural.\p"
	.string "Alguien usó la muestra robada\n"
	.string "para forzar el canto lunar.\p"
	.string "Y creo que acabamos de despertar\n"
	.string "a quien vigilaba el experimento…$"

MtMoon_Cave_Text_LunatoneAppears:
	.string "¡Un LUNATONE alterado bloquea\n"
	.string "la resonancia de la cueva!$"

MtMoon_Cave_Text_ClefairyReturn:
	.string "El pulso artificial se extingue.\p"
	.string "Desde el fondo de la montaña\n"
	.string "regresa una canción temblorosa.\p"
	.string "Los CLEFAIRY vuelven a salir.$"

MtMoon_Cave_Text_BatemagicoConclusion:
	.string "Perfecto… Quiero decir: bien hecho.\p"
	.string "La señal llevaba datos biológicos\n"
	.string "ocultos dentro del pulso.\p"
	.string "Solo BILL puede separar materia\n"
	.string "viva de información digital.\p"
	.string "Ve a su casa, al norte de CELESTE.\n"
	.string "Yo custodiaré este fragmento.$"

MtMoon_Cave_Text_BatemagicoAfter:
	.string "BILL vive al norte de CELESTE.\p"
	.string "Dile que busque datos biológicos\n"
	.string "dentro de una onda mineral.$"

MtMoon_Cave_Text_FossilTrace:
	.string "El fósil tiene un corte demasiado\n"
	.string "limpio para ser una fractura.\p"
	.string "En la ranura queda polvo plateado\n"
	.string "con forma de una M diminuta.$"

MtMoon_Cave_Text_FossilAlreadyChecked:
	.string "La ranura del fósil conserva\n"
	.string "restos de polvo plateado.$"

MtMoon_Cave_Text_FossilNormal:
	.string "Un fósil antiguo descansa entre\n"
	.string "las rocas de la montaña.$"

MtMoon_Cave_Text_GeodudeTrace:
	.string "GEODUDE tiembla a intervalos\n"
	.string "perfectamente regulares.\p"
	.string "El polvo de su cuerpo vibra con\n"
	.string "la misma frecuencia que la cueva.$"

MtMoon_Cave_Text_GeodudeAlreadyChecked:
	.string "GEODUDE continúa temblando al\n"
	.string "ritmo del pulso subterráneo.$"

MtMoon_Cave_Text_GeodudeNormal:
	.string "GEODUDE parece encantado con\n"
	.string "las piedras que lo rodean.$"

MtMoon_Cave_Text_AltarTrace:
	.string "Alguien ha vaciado los surcos\n"
	.string "circulares del viejo altar.\p"
	.string "Las marcas recientes forman un\n"
	.string "conector parecido a los de SILPH.$"

MtMoon_Cave_Text_AltarAlreadyChecked:
	.string "El altar conserva las marcas\n"
	.string "de un conector arrancado.$"

MtMoon_Cave_Text_QuestClefairy:
	.string "CLEFAIRY canta muy bajito.\p"
	.string "Ya no parece tener miedo.$"
