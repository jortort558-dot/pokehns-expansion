ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "¿Dónde está el LÍDER de CIUDAD\n"
	.string "VERDE? Quería desafiarlo.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "No hay ENTRENADORES en el GIMNASIO\n"
	.string "de CIUDAD VERDE.\p"
	.string "El LÍDER dice que su norma es ganar\n"
	.string "sin subordinados.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "He oído que el GIMNASIO de CANELA\n"
	.string "ha desaparecido.\p"
	.string "¿Qué habrá sido de su LÍDER BLAINE?$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Sueño con ser LÍDER de GIMNASIO.$"
