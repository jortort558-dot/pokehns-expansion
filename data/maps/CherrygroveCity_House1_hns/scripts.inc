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
	.string "¿Quieres comprobar lo bueno que\n"
	.string "eres como entrenador POKéMON?\p"
	.string "Pues más te vale visitar los\n"
	.string "GIMNASIOS POKéMON de todo JOHTO\l"
	.string "y ganar MEDALLAS.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "¡De mayor voy a ser LÍDER DE\n"
	.string "GIMNASIO!\p"
	.string "¡Hago combatir a mis POKéMON contra\n"
	.string "los de mi amigo para hacerlos\l"
	.string "más duros!$"
