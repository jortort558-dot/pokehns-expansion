CeruleanCity_Mart_hns_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "De camino al CABO CELESTE te\n"
	.string "cruzarás con muchos entrenadores.\p"
	.string "Quieren medir sus fuerzas con\n"
	.string "las de otros entrenadores.$"
CeruleanMart_Text_CooltrainerF:
	.string "MISTY es casi la única capaz de\n"
	.string "vencer a los entrenadores del\l"
	.string "CABO CELESTE.$"
