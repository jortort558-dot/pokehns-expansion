GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "En mitad de un combate, mi POKéMON\n"
    .string "se quedó sin poder atacar.\p"
    .string "¡Se le habían agotado los PUNTOS DE\n"
    .string "PODER (PP) de sus ataques!$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "A veces, un POKéMON lleno de salud\n"
    .string "no puede usar sus movimientos.\p"
    .string "Si te pasa, cúralo en un CENTRO\n"
    .string "POKéMON o usa algún objeto.$"
