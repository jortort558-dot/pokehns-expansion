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
	.string "¿Cómo se te queda el cuerpo? ¿Que\nel\lTEAM ROCKET ha vuelto?\pHe visto a tipos vestidos de negro\npor el\lLAGO DE LA FURIA…$"
MahoganyTown_PokemonCenter_Text_Youngster:
	.string "Evito que mis POKéMON evolucionen\ndemasiado pronto.\pHago que aprendan ciertos ataques\nantes\lde dejarlos evolucionar.$"
MahoganyTown_PokemonCenter_Text_CooltrainerF:
	.string "Los POKéMON se vuelven mucho más\nfuertes\lal evolucionar,\lpero también aprenden movimientos\lcon más\llentitud.$"
