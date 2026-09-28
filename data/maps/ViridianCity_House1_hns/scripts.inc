ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "¿Piensas mucho los nombres de tus\n"
	.string "POKéMON?\p"
	.string "Un buen mote hace más divertidos\n"
	.string "los intercambios.$"

ViridianCity_House1_Text_Lass:
	.string "Son SPEARY, un SPEAROW, y RATTEY,\n"
	.string "un RATTATA.$"

ViridianCity_House1_Text_Speary:
	.string "SPEARY: Ch-chun!$"

ViridianCity_House1_Text_Rattey:
	.string "RATTEY: Kikiii!$"
