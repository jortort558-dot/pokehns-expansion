PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "También crío POKéMON.\p"
	.string "Son mis guardaespaldas\n"
	.string "privados.$"

PalletTown_Text_Fisher:
	.string "¡La tecnología es increíble!\p"
	.string "Puedes intercambiar POKéMON en el\n"
	.string "tiempo como si fueran correos.$"

PalletTown_Text_Sign:
	.string "PUEBLO PALETA\p"
	.string "Un lugar tranquilo de paz\n"
	.string "y pureza$"

PalletTown_Text_RedsHouseSign:
	.string "CASA DE RED$"

PalletTown_Text_OaksLabSign:
	.string "LABORATORIO POKéMON\n"
	.string "DE OAK$"

PalletTown_Text_BluesHouseSign:
	.string "CASA DE BLUE$"
