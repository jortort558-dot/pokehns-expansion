Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "¡La vida isleña es tan tranquila!\p"
	.string "¡Y qué bien que mis nietos estén a\n"
	.string "un viaje corto en barco en KANTO!$"

Melemele_House3_Man_Text_0:
	.string "¡Malditos turistas!\p"
	.string "Mi agente inmobiliario me prometió\n"
	.string "que esto sería tranquilo… pero\l"
	.string "claro, ¡es más barato venir aquí que\l"
	.string "viajar hasta la región de ALOLA!$"
