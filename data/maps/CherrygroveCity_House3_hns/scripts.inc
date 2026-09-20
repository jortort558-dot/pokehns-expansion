CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "Los POKéMON ganan experiencia en\ncombate\l"
	.string "y cambian de forma.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "¿Que los POKéMON cambian?\p"
	.string "¡Me quedaría de piedra si viera a\nuno\l"
	.string "hacer eso!$"
