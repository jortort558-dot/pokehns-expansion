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
	.string "En los combates yo\n"
	.string "prefiero usar\p"
	.string "POKéMON que he\n"
	.string "entrenado, aunque\p"
	.string "sean más débiles\n"
	.string "que los POKéMON\l"
	.string "recién capturados.$"
CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "El MAGNETOTRÉN supera los\n"
	.string "500 km/h. Une KANTO y JOHTO\l"
	.string "en un abrir y cerrar de ojos.\p"
	.string "Hace que JOHTO esté muy cerca.$"
