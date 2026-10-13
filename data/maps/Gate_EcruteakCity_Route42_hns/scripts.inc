Gate_EcruteakCity_Route42_hns_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, Gate_EcruteakCity_Route42_EventScript_BadgeRequired
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_EcruteakCity_Route42_EventScript_BadgeRequired::
	msgbox Route42_Text_EcruteakGateBadgeRequired, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_EcruteakCity_Route42_TriggerScript_BadgeCheck::
	goto_if_set FLAG_BADGE06_GET, Gate_EcruteakCity_Route42_TriggerScript_AllowPassage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_ne VAR_RESULT, DIR_EAST, Gate_EcruteakCity_Route42_TriggerScript_AllowPassage
	lockall
	msgbox Route42_Text_EcruteakGateBadgeRequired, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	releaseall
	end

Gate_EcruteakCity_Route42_TriggerScript_AllowPassage::
	end

Route42_Text_EcruteakGateOfficer:
	.string "El MONTE MORTERO es un auténtico\n"
	.string "laberinto por dentro.\p"
	.string "Ten mucho cuidado. ¡No te vayas\n"
	.string "a perder ahí dentro!$"

Route42_Text_EcruteakGateBadgeRequired:
	.string "¡Alto! La RUTA 42 está cerrada\n"
	.string "para entrenadores sin experiencia.\p"
	.string "La LIGA exige seis medallas\n"
	.string "antes de cruzar el MONTE MORTERO.$"
