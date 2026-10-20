CeruleanCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CERULEAN_GYM_ROCKET
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_HNS, CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA_HNS, CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER_HNS, CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "GIMNASIO POKéMON DE CELESTE\n"
    .string "LÍDER: MISTY\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "AZUL, ROJO$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "GIMNASIO POKéMON DE CELESTE\n"
    .string "LÍDER: MISTY\p"
    .string "ENTRENADORES GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

CeruleanGym_Text_Note:
	.string "Perdón, estaré fuera un rato.\p"
	.string "MISTY, LÍDER DEL GIMNASIO\p"
	.string "Como MISTY no está, nosotros\n"
	.string "también nos vamos.\p"
	.string "ENTRENADORES DEL GIMNASIO$"

CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	setvar VAR_0x8008, 10
	special CheckGymTrainersDefeated
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_Misty_NotReady
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY_HNS, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers_hns
	msgbox CeruleanGym_Text_Misty_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	msgbox CeruleanGym_Text_Misty_ExplainTM, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_EventScript_Misty_NotReady::
	msgbox CeruleanGym_Text_Misty_NotReady, MSGBOX_DEFAULT
	release
	end

CeruleanGym_Text_Misty_NotReady:
	.string "MISTY: ¿Crees que puedes tirarte\n"
	.string "piscina sin saber nadar?\p"
	.string "¡Demuestra tu nivel venciendo\n"
	.string "a todos mis entrenadores!$"

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "¡Uups! ¡Yo sentirlo! Tú no estar\n"
	.string "herido, ¿verdad?\p"
	.string "Yo muy ocupado. No tener tiempo\n"
	.string "para hablar. Malo si alguien\l"
	.string "verme.$"
CeruleanGym_Text_GruntBigMistake:
	.string "¡Oh, no! ¡Tú ya verme!\n"
	.string "¡Yo cometer gran error!$"
CeruleanGym_Text_GruntBye:
	.string "¡Oye! Tú olvidar haberme visto,\n"
	.string "¿vale?\p"
	.string "Tú no ver, oír ni saber nada.\p"
	.string "¡Adiós, joven! ¡Nada de nada!\p"
	.string "¡Adiós y muy buenas!$"
CeruleanGym_Text_Note1:
	.string "Perdón, estaré fuera un rato.\p"
	.string "MISTY, LÍDER DEL GIMNASIO\p"
	.string "Como MISTY no está, nosotros\n"
	.string "también nos vamos.\p"
	.string "ENTRENADORES DEL GIMNASIO$"

CeruleanGym_Text_MistyIntro:
	.string "MISTY: ¡Te esperaba, pelma!\p"
	.string "Puede que tengas muchas MEDALLAS\n"
	.string "de JOHTO, pero no me subestimes.\p"
	.string "¡Mis POKéMON de tipo AGUA\n"
	.string "son muy duros!$"
CeruleanGym_Text_MistyWinLoss:
	.string "MISTY: De verdad que eres bueno…\p"
	.string "Admito que tienes mucha habilidad…\p"
	.string "Aquí tienes la MEDALLA CASCADA.$"
CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER} recibió la\n"
	.string "MEDALLA CASCADA.$"
CeruleanGym_Text_MistyFightDone:
	.string "MISTY: ¿Hay muchos entrenadores\n"
	.string "fuertes en JOHTO? Como tú, digo.\p"
	.string "Algún día viajaré para combatir\n"
	.string "contra entrenadores expertos.$"
CeruleanGym_Text_MistyRematch:
	.string "MISTY: ¡Uau, ahora eres CAMPEÓN\n"
	.string "de KANTO!\p"
	.string "¡Es increíble! Has llegado lejos,\n"
	.string "{PLAYER}.\p"
	.string "Pero no pienso echarme atrás.\p"
	.string "¿Quieres combatir otra vez?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "MISTY: De verdad que eres bueno…$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "Siento haber estado fuera.\n"
	.string "¡Vamos al lío!$"
CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "¡Me rindo!\n"
	.string "¡Has ganado!$"
CeruleanGym_Text_SwimmerfDianaAfter:
	.string "Seguiré nadando tranquilamente.$"
CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "Que mi elegante forma de nadar\n"
	.string "no te intimide.$"
CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "¡Oh! Me has vencido sin inmutarte…$"
CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "No presumas tanto por vencerme.\p"
	.string "MISTY te destrozará si bajas\n"
	.string "la guardia.$"
CeruleanGym_Text_SwimmermParkerSeen:
	.string "¡Glup…!\p"
	.string "¡Soy el primero!\n"
	.string "¡Ven a por mí!$"
CeruleanGym_Text_SwimmermParkerBeaten:
	.string "No puede ser…$"
CeruleanGym_Text_SwimmermParkerAfter:
	.string "MISTY ha mejorado muchísimo\n"
	.string "estos últimos años.\p"
	.string "¡No te descuides o te aplastará!$"
CeruleanGym_Text_GuideIntro:
	.string "¡Hola, futuro CAMPEÓN!\p"
	.string "Como MISTY no estaba, yo también\n"
	.string "salí a divertirme. Je, je.$"

CeruleanGym_Text_GuideWin:
	.string "Vaya, me has demostrado lo\n"
	.string "fuerte que eres.\p"
	.string "¡Como siempre, ha sido un combate\n"
	.string "increíble!$"

CeruleanGym_Text_Misty_GiveTM:
	.string "Toma, llévate esto también.$"

CeruleanGym_Text_Misty_ExplainTM:
	.string "Es la MT PULSO AGUA.\p"
	.string "¡Hace daño y a veces también\n"
	.string "provoca confusión!$"

CeruleanCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_CELESTE, CeruleanCity_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_CELESTE, CeruleanCity_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_CELESTE
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

CeruleanCity_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_CELESTE, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_Gym_EventScript_Manolin_GiveDampRock
	case 1, CeruleanCity_Gym_EventScript_Manolin_GiveWacanBerry
	case MULTI_B_PRESSED, CeruleanCity_Gym_EventScript_Manolin_NoChoice
	end

CeruleanCity_Gym_EventScript_Manolin_GiveDampRock::
	giveitem ITEM_DAMP_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_CELESTE
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_DampRockExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanCity_Gym_EventScript_Manolin_GiveWacanBerry::
	giveitem ITEM_WACAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_CELESTE
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_WacanBerryExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanCity_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanCity_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox CeruleanCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanCity_Gym_Text_Manolin_Intro:
	.string "¡Ey, mi gente! ¡Menudo chapuzón!\p"
	.string "Oye, ¿esto no es Arrecípolis?\n"
	.string "¿Dónde está la cascada gigante y el\l"
	.string "boss Plubio con su capa elegante?\p"
	.string "¡Esto es solo una piscina olímpica\n"
	.string "con una pelirroja enfurruñada!\l"
	.string "Vaya despiste de coordenadas llevo…$"

CeruleanCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Para el pull un segundo, loco!\n"
	.string "¡La party está empapada y sin PS!\p"
	.string "Un Hidrobomba crítico y nos vamos\n"
	.string "directos al fondo del mar.\l"
	.string "Toma cura completa y agárrate.$"

CeruleanCity_Gym_Text_Manolin_Healed:
	.string "¡Toda la party con la vida al cien\n"
	.string "y un consumible para el bolsillo!$"

CeruleanCity_Gym_Text_Manolin_OfferChoices:
	.string "Para lidiar con el agua a presión\n"
	.string "hace falta buen equipo de buceo.\l"
	.string "¿Cuál prefieres para el trameo?$"

CeruleanCity_Gym_Text_Manolin_DampRockExplain:
	.string "¡La ROCA LLUVIA alarga Danza Lluvia\n"
	.string "a 8 turnos enteros!\l"
	.string "Para spamear Trueno o potenciar tus\l"
	.string "propios ataques de Agua a tope.$"

CeruleanCity_Gym_Text_Manolin_WacanBerryExplain:
	.string "¡La BAYA RINNA reduce a la mitad\n"
	.string "el daño si te enchufan un rayo!\l"
	.string "Ideal si sacas a un tipo Agua.$"

CeruleanCity_Gym_Text_Manolin_NoChoice:
	.string "Sécate y decide cuando quieras,\n"
	.string "que la piscina no se va a evaporar.$"

CeruleanCity_Gym_Text_Manolin_AfterItem:
	.string "No tragues agua durante el combate.\n"
	.string "¡A por ese boss, mi gente!$"
