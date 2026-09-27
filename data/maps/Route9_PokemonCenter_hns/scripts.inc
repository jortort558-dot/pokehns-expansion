Route9_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_OnTransition::
	setflag FLAG_VISITED_ROUTE10
	setrespawn HEAL_LOCATION_ROUTE10_HNS
	end

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "A veces venimos aquí a descansar\n"
	.string "o a escapar de nuestro DIRECTOR.\p"
	.string "Ese hombre está como una cabra.$"

Route9_PokemonCenter_Text_Engineer2:
	.string "La CENTRAL ENERGÍA está muy lejos,\n"
	.string "así que viajo mucho para trabajar.$"
