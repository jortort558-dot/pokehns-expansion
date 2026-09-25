MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
	.string "¿Cómo? ¿Ha vuelto el TEAM ROCKET?\pVi a unos hombres de negro en el\nLAGO DE LA FURIA…$"
MahoganyTown_PokemonCenter_Text_Youngster:
	.string "Evito que mis POKéMON evolucionen\ndemasiado pronto.\pLes enseño ciertos movimientos\nantes de dejarlos evolucionar.$"
MahoganyTown_PokemonCenter_Text_CooltrainerF:
	.string "Los POKéMON se hacen más fuertes\nal evolucionar,\ppero también aprenden movimientos\nmás despacio.$"
