CianwoodThreeTidesCave_hns_MapScripts::
	.byte 0

CianwoodThreeTidesCave_EventScript_Exit::
	msgbox CianwoodThreeTidesCave_Text_Exit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CianwoodThreeTidesCave_EventScript_Cancel
	closemessage
	warp MAP_CIANWOOD_CITY_HNS, 16, 13
	waitstate
	end

CianwoodThreeTidesCave_EventScript_Cancel::
	end

CianwoodThreeTidesCave_EventScript_Seal::
	lock
	faceplayer
	msgbox CianwoodThreeTidesCave_Text_Seal, MSGBOX_DEFAULT
	giveitem ITEM_PEARL_STRING
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_CIANWOOD_THREE_TIDES_REWARD
	closemessage
	release
	end

CianwoodThreeTidesCave_EventScript_Inscription::
	msgbox CianwoodThreeTidesCave_Text_Inscription, MSGBOX_SIGN
	end

CianwoodThreeTidesCave_Text_Exit:
	.string "La salida conduce a ORQUÍDEA.\n"
	.string "¿Quieres volver?$"

CianwoodThreeTidesCave_Text_Seal:
	.string "El SELLO DE SAL reacciona al mapa.\p"
	.string "Entre las piedras aparece una\n"
	.string "SARTA DE PERLAS.$"

CianwoodThreeTidesCave_Text_Inscription:
	.string "'Quien escucha, recuerda y actúa\n"
	.string "puede seguir la ruta de NEREO'.$"
