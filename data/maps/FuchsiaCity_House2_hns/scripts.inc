FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mi abuelo es el GUARDA de la\n"
	.string "ZONA SAFARI.\p"
	.string "O al menos lo era…\p"
	.string "Decidió irse de vacaciones al\n"
	.string "extranjero él solo.\p"
	.string "Dejó la ZONA SAFARI\n"
	.string "así sin más.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "A muchos les dolió que cerrase la\n"
	.string "ZONA SAFARI, pero el abuelo es\l"
	.string "muy cabezota…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "Es la foto de un anciano sonriente\n"
	.string "rodeado de POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "Es una gran pradera donde juegan\n"
	.string "POKéMON poco comunes.$"
