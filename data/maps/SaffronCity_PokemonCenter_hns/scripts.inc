SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "¿Cómo son los CENTROS POKéMON\n"
	.string "de JOHTO?\p"
	.string "…Ya veo. No son muy distintos\n"
	.string "de los de KANTO.\p"
	.string "¡Entonces puedo ir a JOHTO\n"
	.string "sin preocuparme!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Acabo de atravesar el TÚNEL ROCA.\p"
	.string "Había cierto revuelo en la\n"
	.string "CENTRAL DE ENERGÍA.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "Hay una cueva rara en CELESTE.\p"
	.string "Como MONTAÑERO experto debería\n"
	.string "explorarla, pero hasta a mí\l"
	.string "me da miedo.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "La sede de SILPH S.A. y la estación\n"
	.string "del MAGNETOTRÉN son visitas\l"
	.string "obligadas en CIUDAD AZAFRÁN.$"
