OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Vagrant::
	lock
	faceplayer
	random 5
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_1F_EventScript_VagrantText1
	case 1, OldaleTown_PokemonCenter_1F_EventScript_VagrantText2
	case 2, OldaleTown_PokemonCenter_1F_EventScript_VagrantText3
	case 3, OldaleTown_PokemonCenter_1F_EventScript_VagrantText4
	case 4, OldaleTown_PokemonCenter_1F_EventScript_VagrantText5

OldaleTown_PokemonCenter_1F_EventScript_VagrantText1::
	msgbox OldaleTown_PokemonCenter_1F_Text_Vagrant1, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_VagrantGivePotion

OldaleTown_PokemonCenter_1F_EventScript_VagrantText2::
	msgbox OldaleTown_PokemonCenter_1F_Text_Vagrant2, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_VagrantGivePotion

OldaleTown_PokemonCenter_1F_EventScript_VagrantText3::
	msgbox OldaleTown_PokemonCenter_1F_Text_Vagrant3, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_VagrantGivePotion

OldaleTown_PokemonCenter_1F_EventScript_VagrantText4::
	msgbox OldaleTown_PokemonCenter_1F_Text_Vagrant4, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_VagrantGivePotion

OldaleTown_PokemonCenter_1F_EventScript_VagrantText5::
	msgbox OldaleTown_PokemonCenter_1F_Text_Vagrant5, MSGBOX_DEFAULT

OldaleTown_PokemonCenter_1F_EventScript_VagrantGivePotion::
	goto_if_set FLAG_RECEIVED_OLDALE_VAGRANT_POTION, OldaleTown_PokemonCenter_1F_EventScript_VagrantDone
	msgbox OldaleTown_PokemonCenter_1F_Text_VagrantPotion, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_PokemonCenter_1F_EventScript_VagrantDone
	setflag FLAG_RECEIVED_OLDALE_VAGRANT_POTION

OldaleTown_PokemonCenter_1F_EventScript_VagrantDone::
	release
	end
OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"
OldaleTown_PokemonCenter_1F_Text_Vagrant1:
	.string "Las baldosas saben cosas, colega...\p"
	.string "Pero solo hablan cuando trapean.$"

OldaleTown_PokemonCenter_1F_Text_Vagrant2:
	.string "Ayer vi un ZUBAT cuadrado.\p"
	.string "Igual era una ventana cerrada.$"

OldaleTown_PokemonCenter_1F_Text_Vagrant3:
	.string "Si una POKe BALL gira mucho...\p"
	.string "se marea el POKeMON o el mundo?$"

OldaleTown_PokemonCenter_1F_Text_Vagrant4:
	.string "La enfermera me mira raro.\p"
	.string "Creo que sabe que no tengo POKeMON.$"

OldaleTown_PokemonCenter_1F_Text_Vagrant5:
	.string "Mi barba predice el tiempo.\p"
	.string "Hoy anuncia... sopa con viento.$"

OldaleTown_PokemonCenter_1F_Text_VagrantPotion:
	.string "Toma esta POCION.\p"
	.string "La encontre debajo de un martes.$"
