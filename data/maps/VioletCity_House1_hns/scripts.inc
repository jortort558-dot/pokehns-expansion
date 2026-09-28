VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "¡Colecciono POKéMON!\n"
	.string "¿Tienes un {STR_VAR_1}?\p"
	.string "¿Te gustaría cambiármelo por mi\n"
	.string "{STR_VAR_2}?$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "¡Bieeeen! ¡Tengo un {STR_VAR_1}!\p"
	.string "¡{STR_VAR_2}, cuídate mucho!$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "Mmm… Me parece que no.\n"
	.string "Eso no es un {STR_VAR_1}.$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "¿No quieres cambiar? Vaya… Jo…$"

VioletCity_House1_Text_After:
	.string "¡Buenas! ¿Qué tal le va a mi ONIX?$"

VioletCity_House1_Text_PokefanM:
	.string "Los POKéMON recibidos en un\n"
	.string "intercambio crecen muy rápido.\p"
	.string "Pero si no tienes la MEDALLA\n"
	.string "adecuada, pueden desobedecerte.$"
