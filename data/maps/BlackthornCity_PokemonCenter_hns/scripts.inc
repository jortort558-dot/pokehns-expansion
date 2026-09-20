BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "En la lejana MESETA AÑIL se\n"
	.string "encuentra la LIGA POKéMON.\p"
	.string "Allí se reúnen los mejores\n"
	.string "Entrenadores del país.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Tenía que enseñar un movimiento a\n"
	.string "mi POKéMON como fuera.\p"
	.string "Así que pedí al QUITA-MOVIMIENTOS\n"
	.string "que le borrara una MO.$"
