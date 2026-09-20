VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Al atrapar a un POKéMON, puede\n"
	.string "que sea bastante débil.\p"
	.string "Pero con paciencia se volverá\n"
	.string "muy fuerte.\p"
	.string "Lo importante es tratar a tus\n"
	.string "POKéMON siempre con cariño.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "Un POKéMON puede llevar objetos\n"
	.string "como POCIONES o ANTÍDOTOS.\p"
	.string "Sin embargo, no sabrán usar\n"
	.string "medicinas creadas por el hombre.$"
