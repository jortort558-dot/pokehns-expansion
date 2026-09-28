LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "¿Te lo puedes creer?\p"
	.string "Hay gente que se cansa de cuidar\n"
	.string "a sus POKéMON.\p"
	.string "El ABUELO acoge a esos pobres\n"
	.string "POKéMON y cuida de ellos.$"

LavenderTown_House1_Text_Guy:
	.string "El SR. FUJI vive aquí, pero ahora\n"
	.string "está en la CASA DE LAS ALMAS.$"

LavenderTown_House1_Text_Marowak:
	.string "<……>$"
LavenderTown_House1_Text_Marowak2:
	.string "MAROWAK está tranquilo, aunque\n"
	.string "parece bastante feliz.$"

