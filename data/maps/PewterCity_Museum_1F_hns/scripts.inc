PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Museum_1F_OnTransition
	.byte 0

PewterCity_Museum_1F_OnTransition::
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_unset FLAG_PEWTER_MUSEUM_JP_DEFEATED, PewterCity_Museum_1F_HideDani
	goto_if_set FLAG_PEWTER_MUSEUM_DANI_DEFEATED, PewterCity_Museum_1F_HideDani
	clearflag FLAG_HIDE_PEWTER_MUSEUM_DANI
	end

PewterCity_Museum_1F_HideDani::
	setflag FLAG_HIDE_PEWTER_MUSEUM_DANI
	end

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
	goto_if_set FLAG_PEWTER_MUSEUM_DUO_DEFEATED, PewterCity_Museum_1F_EventScript_ReceptionistCrewDefeated
	goto_if_set FLAG_PEWTER_MUSEUM_DANI_DEFEATED, PewterCity_Museum_1F_EventScript_ReceptionistDuoOutside
	goto_if_set FLAG_PEWTER_MUSEUM_JP_DEFEATED, PewterCity_Museum_1F_EventScript_ReceptionistDani
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_1F_EventScript_ReceptionistAfterRobbery
	goto_if_set FLAG_FUCHSIA_BLACK_SLUDGE_RECEIVED, PewterCity_Museum_1F_EventScript_ReceptionistMuseumAlert
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_ReceptionistMuseumAlert::
	msgbox PewterCity_Museum_1F_Text_ReceptionistMuseumAlert, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_ReceptionistAfterRobbery::
	msgbox PewterCity_Museum_1F_Text_ReceptionistAfterRobbery, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_ReceptionistDani::
	msgbox PewterCity_Museum_1F_Text_ReceptionistDani, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_ReceptionistDuoOutside::
	msgbox PewterCity_Museum_1F_Text_ReceptionistDuoOutside, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_ReceptionistCrewDefeated::
	msgbox PewterCity_Museum_1F_Text_ReceptionistCrewDefeated, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Dani::
	trainerbattle_single TRAINER_DANI_MUSEUM_HNS, PewterCity_Museum_1F_Text_DaniIntro, PewterCity_Museum_1F_Text_DaniDefeat, PewterCity_Museum_1F_EventScript_DaniDefeated
	msgbox PewterCity_Museum_1F_Text_DaniAfter, MSGBOX_AUTOCLOSE
	end

PewterCity_Museum_1F_EventScript_DaniDefeated::
	special PlayerFaceTrainerAfterBattle
	setflag FLAG_PEWTER_MUSEUM_DANI_DEFEATED
	msgbox PewterCity_Museum_1F_Text_DaniEscape, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_PEWTER_MUSEUM_DANI
	removeobject LOCALID_MUSEUM_1F_DANI
	releaseall
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

PewterCity_Museum_1F_Text_ReceptionistMuseumAlert:
	.string "¡Tú debes de ser el entrenador\n"
	.string "recomendado desde FUCSIA!\p"
	.string "La visitante sospechosa está junto\n"
	.string "a la muestra lunar, arriba.\p"
	.string "No la alarmes. Solo observa.$"

PewterCity_Museum_1F_Text_ReceptionistAfterRobbery:
	.string "¡Uno de sus cómplices sigue\n"
	.string "arriba! Ten cuidado.$"

PewterCity_Museum_1F_Text_ReceptionistDani:
	.string "¡Otro encapuchado bajó antes que\n"
	.string "tú! Está junto a la escalera.$"

PewterCity_Museum_1F_Text_ReceptionistDuoOutside:
	.string "DANI ha gritado dos nombres:\n"
	.string "ZORTEX y PANDA.\p"
	.string "Creo que esperan en la plaza.$"

PewterCity_Museum_1F_Text_ReceptionistCrewDefeated:
	.string "La credencial contiene el mismo\n"
	.string "compuesto de la ZONA SAFARI.\p"
	.string "Esa M plateada demuestra que los\n"
	.string "incidentes están relacionados.$"

PewterCity_Museum_1F_Text_DaniIntro:
	.string "DANI: JP te ha entretenido lo\n"
	.string "suficiente.\p"
	.string "Ahora veremos cuánto tardas en\n"
	.string "encontrar la salida.$"

PewterCity_Museum_1F_Text_DaniDefeat:
	.string "Has encontrado el hueco.$"

PewterCity_Museum_1F_Text_DaniEscape:
	.string "DANI: ¡ZORTEX! ¡PANDA!\n"
	.string "¡Cambio de plan!\p"
	.string "Te esperan fuera. Los dos.$"

PewterCity_Museum_1F_Text_DaniAfter:
	.string "DANI calcula la distancia hasta\n"
	.string "la puerta.$"

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
