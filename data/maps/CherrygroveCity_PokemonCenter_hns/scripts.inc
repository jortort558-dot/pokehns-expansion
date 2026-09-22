CherrygroveCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_MegaResearcher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MEGA_TEST_KIT, CherryGrove_Pokecenter_EventScript_MegaResearcherReminder
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherIntro, MSGBOX_DEFAULT
	checkitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, TRUE, CherryGrove_Pokecenter_EventScript_MegaResearcherGiveMon
	giveitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, FALSE, CherryGrove_Pokecenter_EventScript_MegaResearcherEnd

CherryGrove_Pokecenter_EventScript_MegaResearcherGiveMon::
	special GiveRandomMegaGift
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CherryGrove_Pokecenter_EventScript_MegaResearcherNoRoom
	setflag FLAG_RECEIVED_MEGA_TEST_KIT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CherryGrove_Pokecenter_EventScript_MegaResearcherSentToPC
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherReceived, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_MegaResearcherInstructions

CherryGrove_Pokecenter_EventScript_MegaResearcherSentToPC::
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherSentToPC, MSGBOX_DEFAULT

CherryGrove_Pokecenter_EventScript_MegaResearcherInstructions::
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherInstructions, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_MegaResearcherEnd

CherryGrove_Pokecenter_EventScript_MegaResearcherNoRoom::
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherNoRoom, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_MegaResearcherEnd

CherryGrove_Pokecenter_EventScript_MegaResearcherReminder::
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherReminder, MSGBOX_DEFAULT

CherryGrove_Pokecenter_EventScript_MegaResearcherEnd::
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "Es una maravilla. Puedo guardar\ntantos\l"
	.string "POKéMON como quiera, y es gratis.$"

CherryGrove_Pokecenter_Text_Gentleman:
	.string "Cualquier entrenador puede usar ese\n"
	.string "PC libremente.$"

CherryGrove_Pokecenter_Text_Lass:
	.string "Dicen que mirar un reloj\n"
	.string "ralentiza el tiempo; aquí\l"
	.string "¡las horas pasan volando!$"

CherryGrove_Pokecenter_Text_MegaResearcherIntro:
	.string "¡Justo a tiempo! Necesito a alguien\n"
	.string "para probar la MEGAEVOLUCIÓN.\p"
	.string "Te daré un POKéMON y su\n"
	.string "MEGAPIEDRA, además de un MEGAARO.$"

CherryGrove_Pokecenter_Text_MegaResearcherReceived:
	.string "{STR_VAR_1} se ha unido a tu equipo\n"
	.string "con su MEGAPIEDRA equipada.$"

CherryGrove_Pokecenter_Text_MegaResearcherSentToPC:
	.string "Tu equipo está lleno, así que\n"
	.string "{STR_VAR_1} ha sido enviado al PC\l"
	.string "con su MEGAPIEDRA.$"

CherryGrove_Pokecenter_Text_MegaResearcherInstructions:
	.string "En combate, pulsa SELECT antes de\n"
	.string "elegir un movimiento para activar\l"
	.string "la MEGAEVOLUCIÓN.\p"
	.string "Pulsa START para consultar la\n"
	.string "descripción de los movimientos.$"

CherryGrove_Pokecenter_Text_MegaResearcherNoRoom:
	.string "No queda espacio ni en tu equipo\n"
	.string "ni en las cajas del PC.\p"
	.string "Haz sitio y vuelve luego.$"

CherryGrove_Pokecenter_Text_MegaResearcherReminder:
	.string "El POKéMON que te di ya lleva\n"
	.string "su MEGAPIEDRA equipada.\p"
	.string "Pulsa SELECT antes de elegir un\n"
	.string "movimiento para megaevolucionar.$"

CherryGrove_Pokecenter_Text_Chansey:
	.string "CHANSEY: Chaan! Sii!$"

CherryGrove_Pokecenter_EventScript_Vagrant::
	lock
	faceplayer
	random 5
	switch VAR_RESULT
	case 0, CherryGrove_Pokecenter_EventScript_VagrantText1
	case 1, CherryGrove_Pokecenter_EventScript_VagrantText2
	case 2, CherryGrove_Pokecenter_EventScript_VagrantText3
	case 3, CherryGrove_Pokecenter_EventScript_VagrantText4
	case 4, CherryGrove_Pokecenter_EventScript_VagrantText5

CherryGrove_Pokecenter_EventScript_VagrantText1::
	msgbox CherryGrove_Pokecenter_Text_Vagrant1, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_VagrantGivePotion

CherryGrove_Pokecenter_EventScript_VagrantText2::
	msgbox CherryGrove_Pokecenter_Text_Vagrant2, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_VagrantGivePotion

CherryGrove_Pokecenter_EventScript_VagrantText3::
	msgbox CherryGrove_Pokecenter_Text_Vagrant3, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_VagrantGivePotion

CherryGrove_Pokecenter_EventScript_VagrantText4::
	msgbox CherryGrove_Pokecenter_Text_Vagrant4, MSGBOX_DEFAULT
	goto CherryGrove_Pokecenter_EventScript_VagrantGivePotion

CherryGrove_Pokecenter_EventScript_VagrantText5::
	msgbox CherryGrove_Pokecenter_Text_Vagrant5, MSGBOX_DEFAULT

CherryGrove_Pokecenter_EventScript_VagrantGivePotion::
	goto_if_set FLAG_RECEIVED_OLDALE_VAGRANT_POTION, CherryGrove_Pokecenter_EventScript_VagrantDone
	msgbox CherryGrove_Pokecenter_Text_VagrantPotion, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, CherryGrove_Pokecenter_EventScript_VagrantDone
	setflag FLAG_RECEIVED_OLDALE_VAGRANT_POTION

CherryGrove_Pokecenter_EventScript_VagrantDone::
	release
	end

CherryGrove_Pokecenter_Text_Vagrant1:
	.string "Las baldosas saben cosas, colega...\p"
	.string "Pero solo hablan cuando trapean.$"

CherryGrove_Pokecenter_Text_Vagrant2:
	.string "Ayer vi un ZUBAT cuadrado.\p"
	.string "Igual era una ventana cerrada.$"

CherryGrove_Pokecenter_Text_Vagrant3:
	.string "Si una POKé BALL gira mucho...\p"
	.string "¿se marea el POKéMON o el mundo?$"

CherryGrove_Pokecenter_Text_Vagrant4:
	.string "La enfermera me mira raro.\p"
	.string "Creo que sabe que no tengo POKéMON.$"

CherryGrove_Pokecenter_Text_Vagrant5:
	.string "Mi barba predice el tiempo.\p"
	.string "Hoy anuncia... sopa con viento.$"

CherryGrove_Pokecenter_Text_VagrantPotion:
	.string "Toma esta POCIÓN.\p"
	.string "La encontré debajo de un martes.$"
