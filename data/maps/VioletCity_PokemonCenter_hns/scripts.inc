VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "¡{PLAYER}, dichosos los ojos!\p"
	.string "El PROF. ELM me envió a buscarte.\p"
	.string "Tiene otro gran favor que pedirte.\p"
	.string "¿Te harías cargo de este\n"
	.string "HUEVO POKéMON?$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "¡{PLAYER}, dichosos los ojos!\p"
	.string "El PROF. ELM me envió a buscarte.\p"
	.string "Tiene otro gran favor que pedirte.\p"
	.string "¿Te harías cargo de este HUEVO?\p"
	.string "Ah, espera... Primero necesitas\n"
	.string "hacer hueco en tu equipo.$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "Descubrimos que el POKéMON no\n"
	.string "nacerá si el HUEVO no viaja junto\l"
	.string "a un entrenador.\p"
	.string "Necesita estar junto a otros\n"
	.string "POKéMON activos para eclosionar.\p"
	.string "¡{PLAYER}, eres la única persona\n"
	.string "en la que podemos confiar!$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "¡Ah! Esto te vendrá muy bien\n"
	.string "cuando nazca.$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "Vaya, llevas el equipo completo.\p"
	.string "Te espero aquí mientras haces\n"
	.string "sitio para el HUEVO.$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "Vaya, no puedes llevar más\n"
	.string "POKéMON contigo.\p"
	.string "No te preocupes: ¡he enviado el\n"
	.string "HUEVO al PC DE BILL por ti!$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "P-pero… El PROF. ELM insistió\n"
	.string "en que fueras tú…$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "Mientras mis POKéMON se recuperan,\n"
	.string "me encanta leer un buen libro.$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "¡Acabo de combatir por conexión\n"
	.string "con un amigo de ORQUÍDEA!\p"
	.string "¡Es increíble poder conectarse\n"
	.string "con alguien que está tan lejos!$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "Un genio llamado BILL inventó\n"
	.string "el sistema de almacenamiento\l"
	.string "de POKéMON del PC.$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "Ocurrió hace unos tres años.\p"
	.string "El TEAM ROCKET hacía de las suyas\n"
	.string "con los POKéMON.\p"
	.string "Pero se hizo justicia: un joven\n"
	.string "acabó con todos ellos.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "Los POKéMON son muy listos. No\n"
	.string "obedecen a quien no se gana\l"
	.string "su respeto.\p"
	.string "¡Sin las MEDALLAS adecuadas,\n"
	.string "harán lo que les dé la gana!$"
