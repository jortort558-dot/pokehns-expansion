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
	.string "Esto ocurrió cuando yo era joven.\pDe pronto, el cielo se volvió negro\ncomo\lel carbón. Un gigantesco POKéMON\lalado\ltapaba la luz del sol.\p¿Qué clase de POKéMON sería?\nEra como una mezcla de ave y\ldragón.$"
EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "¿De verdad existe un POKéMON tan\nenorme?\lSi existe, debe de ser\lincreíblemente\lpoderoso.$"
