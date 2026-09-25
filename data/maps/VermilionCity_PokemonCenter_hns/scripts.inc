VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "Hay un POKéMON dormido frente a\n"
	.string "la CUEVA DIGLETT.\p"
	.string "Es una ocasión genial para\n"
	.string "capturarlo, pero ¿cómo despertarlo?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "Había un POKéMON dormido frente\n"
	.string "a la CUEVA DIGLETT.\p"
	.string "Pero parece que ha desaparecido.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "El S.S. AQUA es ideal para conocer\n"
	.string "entrenadores y combatir.$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "¿Eh? Tienes MEDALLAS que nunca\n"
	.string "había visto.\p"
	.string "Ah, ya entiendo. Las conseguiste\n"
	.string "en JOHTO.$"
