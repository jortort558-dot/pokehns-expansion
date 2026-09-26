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
	msgbox CherryGrove_Pokecenter_Text_MegaResearcherIntro, MSGBOX_DEFAULT
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
	.string "Investigo una energía capaz de\n"
	.string "llevar a ciertos POKéMON más allá\l"
	.string "de la evolución.\p"
	.string "La señal más intensa viene del\n"
	.string "LAGO DE LA FURIA.\p"
	.string "Pero un chico pelirrojo robó dos\n"
	.string "prototipos del laboratorio...$"
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
