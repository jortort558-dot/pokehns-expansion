Gate_RuinsOfAlph_Route36_hns_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "RUINAS ALFA\p"
	.string "Un lugar turístico para ver y tocar.\p"
	.string "¡Prueba a mover los paneles\n"
	.string "deslizantes de piedra!$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "¿Estás investigando las RUINAS?\p"
	.string "Veo madera de científico en ti.$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "Hay dibujos en unos paneles de\n"
	.string "piedra dentro de las cámaras.\p"
	.string "Intenté moverlos para colocarlos.\n"
	.string "¿Qué misterio ocultarán?$"
