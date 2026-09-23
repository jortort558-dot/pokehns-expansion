EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "Esto ocurrió cuando yo era\n"
	.string "joven.\p"
	.string "De pronto, el cielo se volvió\n"
	.string "negro como el carbón. Un\l"
	.string "gigantesco POKéMON alado tapaba\l"
	.string "la luz del sol.\p"
	.string "¿Qué clase de POKéMON sería? Era\n"
	.string "como una mezcla de ave y dragón.$"
EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "¿De verdad existe un POKéMON tan\n"
	.string "enorme? Si existe, debe de ser\l"
	.string "increíblemente poderoso.$"
