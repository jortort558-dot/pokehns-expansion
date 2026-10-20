LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Al norte de PUEBLO LAVANDA está\n"
	.string "el TÚNEL ROCA.\p"
	.string "Crúzalo para llegar a la CENTRAL\n"
	.string "DE ENERGÍA.$"
LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Hay un programa de radio que\n"
	.string "emite música de POKé FLAUTA.\p"
	.string "Tu radio necesita una TARJETA\n"
	.string "EXPANSIÓN para sintonizarlo.\p"
	.string "Quizá te den una en la EMISORA\n"
	.string "de este pueblo.$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la CENTRAL DE ENERGÍA no\n"
	.string "funciona, el MAGNETOTRÉN tampoco…\p"
	.string "Y la EMISORA DE RADIO tampoco\n"
	.string "podrá emitir…$"
LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "El DIRECTOR de la EMISORA estaba\n"
	.string "muy contento.\p"
	.string "Dijo que han vuelto a emitir\n"
	.string "porque la CENTRAL DE ENERGÍA\l"
	.string "funciona otra vez.$"
