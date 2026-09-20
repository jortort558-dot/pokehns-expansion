Gate_Route31_VioletCity_hns_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "¡Hola! ¿Has visitado ya la\n"
	.string "TORRE BELLSPROUT?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "He visto un POKéMON monísimo\n"
	.string "ahí fuera.\p"
	.string "¡Se parecía un montón a PIKACHU!$"
