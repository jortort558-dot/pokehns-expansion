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
	.string "Mi EEVEE evolucionó a ESPEON.\pPero el de mi amigo se convirtió en\nun UMBREON.\p¿Por qué será? Si ambos criamos a\nnuestros EEVEE exactamente igual...$"
EcruteakMart_Text_Granny:
	.string "Si usas REVIVIR, un POKéMON que se\nhaya\ldebilitado volverá a despertar al\linstante.$"
