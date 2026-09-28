Route24_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 16, 8
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 16, 9
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31_HNS, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "¡Eh, chaval! ¡Yo ser del TEAM\n"
	.string "ROCKET, más o menos!\p"
	.string "¡Venir de otro país y ser\n"
	.string "entrenador número uno!\p"
	.string "Pensar que cortar energía causa\n"
	.string "gran pánico a gente de aquí.\p"
	.string "Misión ser secreta, así que no\n"
	.string "contarte nada.\p"
	.string "¡Pero si tú ganar a mí, seré\n"
	.string "hombre y secreto mío te contaré!\p"
	.string "¡Eh, chaval! ¡Luchar ahora!$"

Route24_Text_RocketBeaten:
	.string "¡Ay! ¡No, no! ¡No poder creer!\p"
	.string "¡Tú ser muy fuerte! ¡Yo no ser\n"
	.string "rival para ti!$"

Route24_Text_RocketAfter:
	.string "Bien. ¿Contarte secreto mío?\n"
	.string "Yo robar PIEZA MAQUINARIA y\l"
	.string "esconder en GIMNASIO CELESTE.\p"
	.string "Meter en agua. Buscar en centro\n"
	.string "del agua del GIMNASIO.\p"
	.string "¡Pero tú no olvidarte de mí!\p"
	.string "TEAM ROCKET te vencerá seguro.\p"
	.string "Vendrán de JOHTO mis amigos, sí.\n"
	.string "Ellos vengarse.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "¿Tú decir qué? ¿TEAM ROCKET se\n"
	.string "fue y se disolvió? ¿Eso dices?\p"
	.string "¡Oh, no! ¿Qué hacer yo ahora?$"



Route24_Text_Woman:
	.string "¿No es una vista preciosa?$"
Route24_Text_Man:
	.string "Podría quedarme aquí todo el día.$"

Route24_Text_WomanRocket:
	.string "¡Nadie me empuja!$"
Route24_Text_ManRocket:
	.string "¡Nadie empuja a mi novia!$"

Route24_Text_WomanAfterRocket:
	.string "¿A qué ha venido todo eso?$"
Route24_Text_ManAfterRocket:
	.string "¿Ese era del TEAM ROCKET?$"
