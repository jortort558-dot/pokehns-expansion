BlackthornCity_House2_hns_MapScripts::
	.byte 0

BlackthornCity_House2_EventScript_Emy::
	lock
	faceplayer
	goto_if_set FLAG_BLACKTHORN_NPC_TRADE_COMPLETED, BlackthornCity_House2_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MR_MIME, BlackthornCity_House2_Text_YouWillTradeWontYou, BlackthornCity_House2_EventScript_DeclineTrade, BlackthornCity_House2_EventScript_NotRequestedMon, BlackthornCity_House2_Text_MonYouTakeCare
	setflag FLAG_BLACKTHORN_NPC_TRADE_COMPLETED
	release
	end

BlackthornCity_House2_EventScript_DeclineTrade::
	msgbox BlackthornCity_House2_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BlackthornCity_House2_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_EventScript_TradeCompleted::
	msgbox BlackthornCity_House2_Text_After, MSGBOX_DEFAULT
	release
	end

BlackthornCity_House2_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON!\n"
	.string "¿Tienes un {STR_VAR_1}?\p"
	.string "¿Quieres cambiarlo por mi\n"
	.string "{STR_VAR_2}?$"

BlackthornCity_House2_Text_MonYouTakeCare:
	.string "¡Bien! ¡Ya tengo a {STR_VAR_1}!\p"
	.string "¡Cuida bien de {STR_VAR_2}!$"

BlackthornCity_House2_Text_ThisIsntAMon:
	.string "Mmm, creo que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

BlackthornCity_House2_Text_YouWontTradeMe:
	.string "¿No quieres cambiarlo? Vaya…$"

BlackthornCity_House2_Text_After:
	.string "¿Qué tal está mi antiguo MR. MIME?$"
