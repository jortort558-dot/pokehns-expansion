MtMoon_Cave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtMoon_Cave_MapScript_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_Cave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMoon_Cave_OnTransition: 
	callnative SetTimeBasedEncounters
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

MtMoon_Cave_EventScript_Sign::
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
