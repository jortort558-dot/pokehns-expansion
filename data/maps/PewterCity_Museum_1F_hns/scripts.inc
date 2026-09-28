PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "¡Bienvenido!\p"
	.string "Todos los especímenes grandes se\n"
	.string "han llevado a otros museos.\p"
	.string "Así que, por ahora, ¡la entrada\n"
	.string "es gratis!\p"
	.string "Puedes pasar.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Debes de ser un Entrenador fuerte.\p"
	.string "No usamos mucho los fósiles del\n"
	.string "mostrador.\p"
	.string "Un extraño peliplata dejó aquí\n"
	.string "un montón.\p"
	.string "Puedes llevártelos si quieres.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Compartimos estudios con los\n"
	.string "investigadores de RUINAS ALFA.\p"
	.string "¡Hasta intercambiamos fósiles\n"
	.string "por PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Debo agradecer mi larga vida.\p"
	.string "¡Nunca pensé que llegaría a ver\n"
	.string "los huesos de un dragón!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Huesos de un antiguo POKéMON\n"
	.string "dragón.$"
