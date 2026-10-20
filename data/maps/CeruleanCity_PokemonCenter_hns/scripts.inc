CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Para combatir prefiero usar los\n"
	.string "POKéMON que he criado, aunque sean\l"
	.string "más débiles que otros recién\l"
	.string "capturados.$"
CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "El MAGNETOTRÉN supera los\n"
	.string "500 km/h. Une KANTO y JOHTO\l"
	.string "en un abrir y cerrar de ojos.\p"
	.string "Hace que JOHTO esté muy cerca.$"
