AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "¿Ya puedes comprar SÚPER BALLS?\n"
	.string "A mí solo me ofrecen Poké Balls.\p"
	.string "¡Dicen que hay más surtido a medida\n"
	.string "que ganas MEDALLAS DE GIMNASIO!\p"
	.string "Ojalá CÉSAR me hiciera alguna de\n"
	.string "sus Balls especiales.$"

AzaleaMart_Text_BugCatcher:
	.string "La SÚPER BALL atrapa mejor que una\n"
	.string "Poké Ball corriente.\p"
	.string "¡Pero las Balls de CÉSAR son mucho\n"
	.string "mejores en ciertas ocasiones!$"

