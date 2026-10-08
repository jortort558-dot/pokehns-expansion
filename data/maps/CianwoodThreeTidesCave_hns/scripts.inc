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

CianwoodThreeTidesCave_EventScript_TrialGate::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesCave_EventScript_Reward
	msgbox CianwoodThreeTidesCave_Text_TrialGate, MSGBOX_DEFAULT
	closemessage
	warp MAP_CIANWOOD_THREE_TIDES_CALM_HNS, 3, 4
	waitstate
	end

CianwoodThreeTidesCave_EventScript_Reward::
	goto_if_set FLAG_CIANWOOD_THREE_TIDES_REWARD, CianwoodThreeTidesCave_EventScript_RewardTaken
	msgbox CianwoodThreeTidesCave_Text_Seal, MSGBOX_DEFAULT
	giveitem ITEM_PEARL_STRING
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_CIANWOOD_THREE_TIDES_REWARD
	closemessage
	release
	end

CianwoodThreeTidesCave_EventScript_RewardTaken::
	msgbox CianwoodThreeTidesCave_Text_RewardTaken, MSGBOX_DEFAULT
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

CianwoodThreeTidesCave_Text_TrialGate:
	.string "Tres símbolos rodean la cámara.\p"
	.string "El primero representa la CALMA.$"

CianwoodThreeTidesCave_Text_RewardTaken:
	.string "Los tres símbolos permanecen\n"
	.string "encendidos. La prueba terminó.$"

CianwoodThreeTidesCave_Text_Inscription:
	.string "'Quien escucha, recuerda y actúa\n"
	.string "puede seguir la ruta de NEREO'.$"
