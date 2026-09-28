GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "¡{PLAYER}! ¡Qué casualidad!\p"
	.string "He venido a comprar algo para\n"
	.string "mi MILTANK.\p"
	.string "Si quieres otra revancha, ¡ven\n"
	.string "al DOJO KARATE!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON!\n"
	.string "¿Tienes un {STR_VAR_1}?\p"
	.string "¿Lo cambias por mi {STR_VAR_2}?$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "¡Bien! ¡Ya tengo a {STR_VAR_1}!\p"
	.string "¡Cuida mucho de {STR_VAR_2}!$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "Eh… No, creo que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "¿No quieres intercambiar? Jo…$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "¡Hola! ¿Cómo está el MACHOP\n"
	.string "que te di?$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "¿Escuchas el CANAL SUERTE?\p"
    .string "Dicen que, para ganar, debes\n"
	.string "intercambiar POKéMON con mucha\l"
    .string "gente y reunir distintos ID.\p"
	.string "Aunque ya no se intercambia tanto\n"
	.string "como antes.$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "Si te cansas, prueba las bebidas\n"
    .string "de la máquina expendedora.\p"
    .string "A tus POKéMON también les gustarán.$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "¡DESCANSA DE TANTAS COMPRAS!\p"
    .string "6.ª PLANTA: PLAZA TRANQUILA$"
