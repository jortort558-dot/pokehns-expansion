BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "El REVIVIR MÁX. no se vende, pero\n"
	.string "recupera del todo a un POKéMON\l"
	.string "debilitado.\p"
	.string "Eso sí, no restaura los PP de sus\n"
	.string "movimientos.$"

BlackthornMart_Text_BlackBelt:
	.string "El REPELENTE MÁX. mantiene alejados\n"
	.string "a los POKéMON débiles.\p"
	.string "Es el REPELENTE que dura más.$"
