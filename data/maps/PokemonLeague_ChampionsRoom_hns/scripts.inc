PokemonLeague_ChampionsRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChampionRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	special DoPokemonLeagueLightingEffect
	end

ChampionRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, ChampionRoom_CloseDoor
	.2byte 0

ChampionRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, ChamionRoom_Movement_Enter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	release
	end

ChamionRoom_Movement_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ChampionRoom_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

PokemonLeague_WillsRoom_EventScript_Lance::
	lockall
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_WillsRoom_EventScript_LanceRematch
	msgbox PokemonLeague_ChampionsRoom_Text_BattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_1_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto

PokemonLeague_WillsRoom_EventScript_LanceRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_WillsRoom_EventScript_LanceRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_WillsRoom_EventScript_LanceRematchPostOBC

PokemonLeague_WillsRoom_EventScript_LanceRematchStandard::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_2_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceRematchPostOBC::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_POSTOBC_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_LANCE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_MARY
	msgbox PokemonLeague_ChampionsRoom_Text_MaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_LANCE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_MARY
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest
	waitmovement 0
	return

PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast:
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth:
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest:
	walk_down
	walk_left
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceMoveOver:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_2
	walk_in_place_fast_down
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryMoveOver:
	walk_left
	face_right
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryInterview:
	walk_fast_up
	walk_in_place_fast_right
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceAnxious:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceLeave:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PokemonLeague_ChampionsRoom_Text_RematchBattleIntro:
    .string "LANCE: ¡Bienvenido de nuevo!\p"
    .string "Demostraste tu valía en JOHTO:\n"
    .string "lograste las ocho MEDALLAS\l"
    .string "e incluso me venciste una vez.\p"
    .string "Pero ahora estás en la gran liga:\n"
    .string "¡la LIGA de KANTO!\p"
    .string "Una región con sus propias pruebas\n"
    .string "y campeones.\p"
    .string "Aquí soy tu desafío final, con un\n"
    .string "equipo más fuerte que nunca.\p"
    .string "Esta es la verdadera prueba:\n"
    .string "un combate para decidir quién será\l"
    .string "el CAMPEÓN de KANTO.\p"
	.string "¿Te atreves a afrontar este\n"
    .string "nuevo desafío y probarte otra vez?\p"
    .string "¡Muéstrame la fuerza que conquistó\n"
    .string "JOHTO, CAMPEÓN!$"

PokemonLeague_ChampionsRoom_Text_BattleIntro:
    .string "LANCE: Te estaba esperando.\p"
    .string "¡{PLAYER}!\p"
    .string "Sabía que con tu habilidad\n"
    .string "acabarías llegando hasta mí.\p"
    .string "Ya no hacen falta palabras.\p"
    .string "Lucharemos para decidir cuál\n"
    .string "de los dos es más fuerte.\p"
    .string "Como Entrenador más poderoso\n"
    .string "y CAMPEÓN de la LIGA POKéMON…\p"
    .string "¡Yo, LANCE, Maestro Dragón,\n"
    .string "acepto tu desafío!$"

PokemonLeague_ChampionsRoom_Text_BattleWin:
    .string "Se acabó…\p"
    .string "Pero es una sensación extraña.\p"
    .string "No me enfada haber perdido.\n"
    .string "De hecho, me siento feliz.\p"
    .string "¡Feliz por haber visto el auge\n"
    .string "de un nuevo gran CAMPEÓN!$"

PokemonLeague_ChampionsRoom_Text_BattleAfter:
    .string "Uf…\p"
    .string "Te has vuelto realmente poderoso,\n"
    .string "{PLAYER}.\p"
    .string "Tus POKéMON han respondido a tu\n"
    .string "carácter firme y honrado.\p"
    .string "Como Entrenador, seguirás creciendo\n"
    .string "más fuerte junto a tus POKéMON.$"

PokemonLeague_ChampionsRoom_Text_MaryOhNoOak:
    .string "MARY: ¡Oh, no! ¡Ya ha terminado!\p"
    .string "PROF. OAK, si no fuera tan lento…$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations:
    .string "PROF. OAK: ¡Ah, {PLAYER}!\p"
    .string "¡Cuánto tiempo!\n"
    .string "Tienes un aspecto imponente.\p"
    .string "¡Tu conquista de la LIGA de JOHTO\n"
    .string "ha sido fantástica!\p"
    .string "Tu entrega, confianza y amor por\n"
    .string "tus POKéMON lo hicieron posible.\p"
    .string "Tus POKéMON también destacaron.\n"
    .string "Perseveraron porque creían en ti.\p"
    .string "¡Enhorabuena, {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations:
    .string "PROF. OAK: ¡Ah, {PLAYER}!\p"
    .string "Sigo tus avances desde que el\n"
    .string "PROF. ELM te envió de viaje.\p"
    .string "Te has vuelto realmente imponente.\p"
    .string "Conquistar la LIGA de JOHTO y ahora\n"
    .string "la de KANTO no es poca cosa.\p"
    .string "¡Te has superado!\p"
    .string "Está claro que tus POKéMON confían\n"
    .string "enormemente en ti.\p"
    .string "Esa confianza ha sido la base\n"
    .string "de tu éxito.\p"
    .string "Pero recuerda: el viaje de un\n"
    .string "Entrenador nunca acaba de verdad.\p"
    .string "¡Enhorabuena por tu victoria,\n"
    .string "{PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_MaryInterview:
    .string "MARY: ¡Entrevistemos al flamante\n"
    .string "CAMPEÓN de JOHTO!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryInterview:
    .string "MARY: ¡Entrevistemos al flamante\n"
    .string "CAMPEÓN de KANTO!$"

PokemonLeague_ChampionsRoom_Text_Noisy:
    .string "LANCE: Esto empieza a ser\n"
    .string "demasiado ruidoso…\p"
    .string "{PLAYER}, ¿puedes acompañarme?$"

PokemonLeague_ChampionsRoom_Text_MaryNoInterview:
    .string "MARY: ¡Espera! ¡Aún no hemos hecho\n"
    .string "la entrevista!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview:
    .string "MARY: ¡Vamos! ¡No puedes volver\n"
    .string "a escaquearte de la entrevista!$"
