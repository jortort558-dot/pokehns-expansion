Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "No puedes trepar por los\ndesniveles.\p"
	.string "Pero puedes saltar desde ellos\n"
	.string "para tomar un atajo.$"

Gate_Route29_Route46_Text_Youngster:
	.string "A partir de aquí aparecen tipos de\n"
	.string "POKéMON bastante diferentes.\p"
	.string "Si quieres atraparlos a todos,\n"
	.string "¡tendrás que buscar por todas\npartes!$"
