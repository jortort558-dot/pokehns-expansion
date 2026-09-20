CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "¿Quieres comprobar lo bueno que\neres\l"
	.string "como entrenador POKéMON?\p"
	.string "Pues más te vale visitar los\nGIMNASIOS\l"
	.string "POKéMON de todo JOHTO y ganar\nMEDALLAS.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "¡De mayor voy a ser LÍDER DE\nGIMNASIO!\p"
	.string "¡Hago combatir a mis POKéMON contra\nlos\l"
	.string "de mi amigo para hacerlos más\nduros!$"
