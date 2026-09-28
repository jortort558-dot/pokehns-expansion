AzaleaTown_KurtsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end	

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	special CreateKurtBallShop
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, AzaleaTown_KurtsHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_WEST, AzaleaTown_KurtsHouse_EventScript_TurnEast
	call_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_TurnSouth
	goto_if_eq VAR_0x8005, 1, AzaleaTown_KurtsHouse_EventScript_SingularBall
	bufferitemname STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox KurtsHouse_Text_KurtFinishedPlural, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedPlural
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_TurnSouth::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_SOUTH
	return
AzaleaTown_KurtsHouse_EventScript_TurnWest::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_WEST
	return
AzaleaTown_KurtsHouse_EventScript_TurnEast::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_EAST
	return


AzaleaTown_KurtsHouse_EventScript_SingularBall::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox KurtsHouse_Text_KurtFinishedSingular, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedSingular
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
	.string "Bueno, ¿quieres que te fabrique\n"
	.string "alguna Poké Ball?$"

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
	.string "CÉSAR: ¡Me pongo ahora mismo!$"

KurtsHouse_Text_KurtMakingBallsMustWait:
	.string "¿Mmm? ¿Quién eres tú?\p"
	.string "¿{PLAYER}? ¿Quieres que te fabrique\n"
	.string "alguna Poké Ball?\p"
	.string "Lo siento, pero eso tendrá que\n"
	.string "esperar un poco.\p"
	.string "¿Conoces al TEAM ROCKET?\n"
	.string "Bueno, da igual, ¡te lo cuento ya!\p"
	.string "El TEAM ROCKET es una banda de\n"
	.string "maleantes que explota a los\l"
	.string "POKéMON.\p"
	.string "Se suponía que se disolvieron hace\n"
	.string "tres años…\p"
	.string "¡Pero están en el POZO cortando las\n"
	.string "COLASLOWPOKE para comerciar!\p"
	.string "¡Voy a darles una lección que no\n"
	.string "olvidarán jamás!\p"
	.string "¡Aguantad, SLOWPOKE!\n"
	.string "¡El viejo CÉSAR va de camino!$"

KurtsHouse_Text_KurtHonoredToMakeBalls:
	.string "CÉSAR: ¡Hola, {PLAYER}!\p"
	.string "¡Te portaste como un auténtico\n"
	.string "héroe en el POZO!\p"
	.string "¡Me gusta tu temple!\p"
	.string "Será un honor fabricar Poké Balls\n"
	.string "para alguien como tú.\p"
	.string "Esto es todo lo que tengo a mano,\n"
	.string "¡pero acéptalo de corazón!$"

KurtsHouse_Text_KurtBallsFromApricorns:
	.string "CÉSAR: Fabrico Poké Balls a partir\n"
	.string "de BONGURIS.\p"
	.string "Recógelos de los árboles y\n"
	.string "tráemelos.\p"
	.string "¡Los convertiré en magníficas\n"
	.string "Poké Balls!$"

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
	.string "CÉSAR: ¿Traes BONGURIS para mí?\p"
	.string "¡Perfecto! Los convertiré en\n"
	.string "Poké Balls artesanas.$"

KurtsHouse_Text_KurtThatsALetdown:
	.string "CÉSAR: ¡No llevas {STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedPlural:
	.string "CÉSAR: ¡{PLAYER}!\n"
	.string "¡Ya están listos tus {STR_VAR_1}!$"

KurtsHouse_Text_KurtObtainedPlural:
	.string "¡{PLAYER} recibió {STR_VAR_2}\n"
	.string "{STR_VAR_1}!$"

KurtsHouse_Text_KurtFinishedSingular:
	.string "CÉSAR: ¡{PLAYER}!\n"
	.string "¡Ya está listo tu {STR_VAR_1}!$"

KurtsHouse_Text_KurtObtainedSingular:
	.string "¡{PLAYER} recibió\n"
	.string "{STR_VAR_1}!$"

KurtsHouse_Text_KurtTurnedOutGreat:
	.string "CÉSAR: ¡Ha quedado impresionante!\p"
	.string "¡Prueba a capturar POKéMON\n"
	.string "con ella!$"

KurtsHouse_Text_KurtWhatIsThat:
	.string "¿Q-qué es eso?\p"
	.string "Nunca había visto nada igual.\p"
	.string "Parece una Poké Ball, pero debe\n"
	.string "de ser otra cosa.\p"
	.string "Déjame examinarla.$"

KurtsHouse_Text_KurtImCheckingItNow:
	.string "La estoy examinando ahora.$"

KurtsHouse_Text_KurtAhHaISee:
	.string "¡Ajá! ¡Ya veo! Entonces…$"

KurtsHouse_Text_KurtThisBallStartedToShake:
	.string "¡{PLAYER}!\p"
	.string "¡Esta Poké Ball empezó a vibrar\n"
	.string "mientras la estaba examinando!\p"
	.string "¡Sin duda encierra algo insólito!$"

KurtsHouse_Text_Kurt_Whatwasthat:
	.string "¿¡Qué ha sido ese estruendo!?\p"
	.string "¡Salgamos fuera a investigar!$"

KurtsHouse_Text_GranddaughterSlowpokeGone:
	.string "Los SLOWPOKE han desaparecido…\n"
	.string "¿Se los llevaron personas malas?$"

KurtsHouse_Text_GranddaughterLonely:
	.string "El abuelo se ha ido…\n"
	.string "¡Me siento muy sola!$"

KurtsHouse_Text_GranddaughterSlowpokeBack:
	.string "¡El SLOWPOKE que me dio papá\n"
	.string "ha vuelto!\p"
	.string "¡También le está creciendo\n"
	.string "la COLA de nuevo!$"

KurtsHouse_Text_GranddaughterDad:
	.string "Papá trabaja en SILPH investigando\n"
	.string "las Poké Balls.\p"
	.string "Yo me quedo aquí en casita con el\n"
	.string "abuelo y SLOWPOKE.$"

KurtsHouse_Text_GranddaughterHelp:
	.string "¡Ahora puedo ayudar al abuelo!\p"
	.string "Te haremos Poké Balls geniales,\n"
	.string "¡así que espera un poco!$"

KurtsHouse_Text_GranddaughterFun:
	.string "¡Fabricar Poké Balls es divertido!$"

KurtsHouse_Text_GranddaughterSound:
	.string "¿Vino ese ruido del ENCINAR?$"

KurtsHouse_Text_Forest:
	.string "¿Has ido ya al ENCINAR?\n"
	.string "Se percibe un gran desasosiego.$"

KurtsHouse_Text_Slowpoke:
	.string "SLOWPOKE: … ¿Bostezo?$"

KurtsHouse_Text_OakPhoto:
	.string "…¿Un joven PROF. OAK?$"

KurtsHouse_Text_CelebiStatue:
	.string "Es una estatua del protector del\n"
	.string "bosque.$"
