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
	.string "¡Aaaayy!\p"
	.string "Siento una sombra siniestra\n"
	.string "cernirse sobre ti.\p"
	.string "¡Toma esto para protegerte!$"
Route5_House_Text_Granny2:
	.string "Corrías un peligro mortal, pero\n"
	.string "ahora estás a salvo.$"
Route5_House_Text_Woman:
	.string "Mi abuela intenta protegerse de\n"
	.string "lo que cree que son espíritus.\p"
	.string "Perdona si te ha asustado.$"
