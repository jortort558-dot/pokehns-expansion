EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Mi EEVEE evolucionó a ESPEON.\p"
	.string "Pero el de mi amigo se convirtió\n"
	.string "en un UMBREON.\p"
	.string "¿Por qué será? Si ambos criamos\n"
	.string "a nuestros EEVEE exactamente\l"
	.string "igual...$"
EcruteakMart_Text_Granny:
	.string "Si usas REVIVIR, un POKéMON que\n"
	.string "se haya debilitado volverá a\l"
	.string "despertar al instante.$"
