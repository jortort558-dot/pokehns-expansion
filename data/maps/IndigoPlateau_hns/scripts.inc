IndigoPlateau_hns_MapScripts::
	.byte 0

IndigoPlateau_EventScript_ElmTrigger::
	lockall
	goto_if_set FLAG_INDIGO_PLATEAU_ELM, IndigoPlateau_EventScript_ElmTriggerEnd
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 10
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	addobject LOCALID_INDIGO_PLATEAU_ELM
	call_if_eq VAR_TEMP_1, 9, IndigoPlateau_EventScript_ElmWalkToPlayer9
	call_if_eq VAR_TEMP_1, 10, IndigoPlateau_EventScript_ElmWalkToPlayer10
	call_if_eq VAR_TEMP_1, 11, IndigoPlateau_EventScript_ElmWalkToPlayer11
	call_if_eq VAR_TEMP_1, 12, IndigoPlateau_EventScript_ElmWalkToPlayer12
	call_if_eq VAR_TEMP_1, 13, IndigoPlateau_EventScript_ElmWalkToPlayer13
	msgbox IndigoPlateau_Text_ElmCongrats, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 9, IndigoPlateau_EventScript_ElmLeave9
	call_if_eq VAR_TEMP_1, 10, IndigoPlateau_EventScript_ElmLeave10
	call_if_eq VAR_TEMP_1, 11, IndigoPlateau_EventScript_ElmLeave11
	call_if_eq VAR_TEMP_1, 12, IndigoPlateau_EventScript_ElmLeave12
	call_if_eq VAR_TEMP_1, 13, IndigoPlateau_EventScript_ElmLeave13
	removeobject LOCALID_INDIGO_PLATEAU_ELM
	setflag FLAG_INDIGO_PLATEAU_ELM
	setvar VAR_TEMP_0, 1
IndigoPlateau_EventScript_ElmTriggerEnd::
	releaseall
	end

IndigoPlateau_EventScript_ElmWalkToPlayer9:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmApproach9
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmWalkToPlayer10:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmApproach10
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmWalkToPlayer11:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmApproach11
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmWalkToPlayer12:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmApproach12
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmWalkToPlayer13:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmApproach13
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmLeave9:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmDepart9
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmLeave10:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmDepart10
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmLeave11:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmDepart11
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmLeave12:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmDepart12
	waitmovement 0
	return

IndigoPlateau_EventScript_ElmLeave13:
	applymovement LOCALID_INDIGO_PLATEAU_ELM, IndigoPlateau_Movement_ElmDepart13
	waitmovement 0
	return

IndigoPlateau_Movement_ElmApproach9:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

IndigoPlateau_Movement_ElmApproach10:
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

IndigoPlateau_Movement_ElmApproach11:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IndigoPlateau_Movement_ElmApproach12:
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

IndigoPlateau_Movement_ElmApproach13:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

IndigoPlateau_Movement_ElmDepart9:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Movement_ElmDepart10:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Movement_ElmDepart11:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Movement_ElmDepart12:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Movement_ElmDepart13:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

IndigoPlateau_Text_ElmCongrats:
	.string "¡{PLAYER}!\n"
	.string "¡Espera un segundo, por favor!\p"
	.string "¡Buf, qué carrera me he pegado!\n"
	.string "¡No podía dejar de venir a verte!\p"
	.string "Has atravesado la CALLE VICTORIA\n"
	.string "y has superado a cada uno de los\l"
	.string "Líderes de Gimnasio de JOHTO…\p"
	.string "Aún recuerdo aquel día en mi\n"
	.string "laboratorio de PUEBLO PRIMAVERA,\l"
	.string "cuando elegiste a tu compañero.\p"
	.string "Ver lo lejos que habéis llegado\n"
	.string "juntos me llena de orgullo.\p"
	.string "Tras esas puertas te espera el\n"
	.string "ALTO MANDO de la LIGA POKéMON.\p"
	.string "¡Estás a punto de completar el\n"
	.string "50% de todo este gran reto!\p"
	.string "Sé que no ha sido un camino fácil,\n"
	.string "pero confío plenamente en ti.\p"
	.string "¡Lucha con todo tu corazón,\n"
	.string "{PLAYER}! ¡Demuestra lo que vales!$"

IndigoPlateau_Sign::
	msgbox IndigoPlateau_Text_Sign, MSGBOX_SIGN
	end

IndigoPlateau_Text_Sign:
	.string "MESETA AÑIL\p"
	.string "¡La meta de todo Entrenador!\p"
	.string "SEDE DE LA LIGA POKéMON$"
