LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "Menudo edificio,\n"
	.string "¿eh?\p"
	.string "Es la TORRE RADIO\n"
	.string "de KANTO.$"
LavenderTown_Text_Teacher:
	.string "KANTO tiene muchos\n"
	.string "programas de radio\l"
	.string "buenos.$"
LavenderTown_Text_Gramps:
	.string "Viene gente de\n"
	.string "todas partes a\p"
	.string "rendir homenaje a\n"
	.string "las almas de los\p"
	.string "POKéMON que han\n"
	.string "partido.$"
LavenderTown_Text_Youngster:
	.string "Necesitas una POKé FLAUTA para\n"
	.string "despertar a los POKéMON.\p"
	.string "¡Todo entrenador debe saberlo!$"

LavenderTown_Text_Sign:
	.string "PUEBLO LAVANDA\p"
	.string "El noble pueblo\n"
	.string "púrpura$"
LavenderTown_Text_KantoRadioStationSign:
	.string "EMISORA DE\n"
	.string "KANTO\p"
	.string "¡Tus programas\n"
	.string "favoritos a\l"
	.string "cualquier hora!$"
LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "CASA POKéMON\n"
	.string "DE VOLUNTARIOS DE\l"
	.string "PUEBLO LAVANDA$"
LavenderTown_Text_SoulHouseSign:
	.string "CEMENTERIO\p"
	.string "Que las almas de\n"
	.string "los POKéMON\l"
	.string "descansen en paz$"
