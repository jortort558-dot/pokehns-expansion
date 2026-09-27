CeruleanCity_House2_hns_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "Dicen que hay un\n"
	.string "tipo sospechoso\l"
	.string "merodeando.\p"
	.string "Si resulta ser el\n"
	.string "ladrón, le\l"
	.string "detendré.$"
CeruleanPolice_Text_PokefanF:
	.string "Ya nos atracaron\n"
	.string "antes.$"
CeruleanPolice_Text_Diglett:
	.string "DIGLETT: Dig, dig.$"
