Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Mi MILTANK ya no me da\nni una gota de leche.\pLa leche de esta GRANJA es famosa.\pTodo el mundo quiere probarla.\pSi le doy un montón de BAYAS,\nvolverá a dar mucha leche,\leso seguro.$"
Route39_Text_FarmerMBuyMilk:
	.string "¿Te apetece LECHE MU-MU?\pEs todo mi orgullo.\p¡Restaura los PS de los POKéMON!\pTe la dejo por tan solo\n500¥.$"
Route39_Text_FarmerMGotMilk:
	.string "¡Aquí tienes!\n¡Bébela bien fría y disfrútala!$"
Route39_Text_FarmerMNoMoney:
	.string "Lo siento, colega.\n¡Sin pasta no hay leche!$"
Route39_Text_FarmerMNoRoom:
	.string "Creo que tienes la BOLSA llena.$"
Route39_Text_FarmerMNoSale:
	.string "¿Que no la quieres?\n¡Pues vuelve cuando tengas sed!$"
Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "¿Te apetece otra botella?$"
Route39_Text_GotMilk:
	.string "{PLAYER} recibió LECHE MU-MU.$"
Route39_Text_FarmerMMilking:
	.string "Será mejor que me ponga a ordeñar.$"
Route39_Text_FarmerFInTrouble:
	.string "Nuestra leche llega hasta\nKANTO.\pSi nuestra MILTANK no da leche,\ntenemos un buen problema.$"
Route39_Text_FarmerFHealedMiltank:
	.string "Has curado a nuestra MILTANK.\nYa vuelve a dar LECHE MU-MU.\pToma esto por las molestias.$"
Route39_Text_FarmerFSnatchSpeech:
	.string "Esto es ROBO.\pEs un movimiento muy astuto:\nroba el movimiento del rival\ljusto antes de que lo use.\pSi varios POKéMON usan ROBO,\nsolo el más lento de todos\lacabará robando el movimiento.\pÚsalo bien. Aquí el ritmo\nlo es todo.$"
