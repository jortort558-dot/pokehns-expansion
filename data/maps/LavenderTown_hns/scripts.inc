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
	.string "Menudo edificio, ¿eh?\p"
	.string "Es la TORRE RADIO de KANTO.$"
LavenderTown_Text_Teacher:
	.string "KANTO tiene muy buenos programas\n"
	.string "de radio.$"
LavenderTown_Text_Gramps:
	.string "Viene gente de todas partes para\n"
	.string "rendir homenaje a las almas de\l"
	.string "los POKéMON que han partido.$"
LavenderTown_Text_Youngster:
	.string "Necesitas una POKé FLAUTA para\n"
	.string "despertar a los POKéMON.\p"
	.string "¡Todo entrenador debe saberlo!$"

LavenderTown_Text_Sign:
	.string "PUEBLO LAVANDA\p"
	.string "El noble pueblo púrpura$"
LavenderTown_Text_KantoRadioStationSign:
	.string "EMISORA DE RADIO DE KANTO\p"
	.string "¡Tus programas favoritos en antena\n"
	.string "a todas horas!$"
LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "CASA POKéMON DE VOLUNTARIOS\n"
	.string "DE PUEBLO LAVANDA$"
LavenderTown_Text_SoulHouseSign:
	.string "CASA DE LAS ALMAS\p"
	.string "Que las almas de los POKéMON\n"
	.string "descansen en paz$"
