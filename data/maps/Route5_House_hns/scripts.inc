Route5_House_hns_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "¡Aaaayy!"
	.string "\pSiento que una"
	.string "\nsiniestra sombra"
	.string "\pse cierne sobre"
	.string "\nti."
	.string "\p¡Toma esto para"
	.string "\n$protegerte!"
Route5_House_Text_Granny2:
	.string "Corrías un peligro"
	.string "\nmortal, pero ahora"
	.string "\l$estás a salvo."
Route5_House_Text_Woman:
	.string "A mi abuela le"
	.string "\ngusta protegerse"
	.string "\pcontra supuestos"
	.string "\nmalos espíritus."
	.string "\pPerdona si te"
	.string "\n$ha asustado."
