CianwoodThreeTidesCave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodThreeTidesCave_EventScript_UpdateSage
	.byte 0

CianwoodThreeTidesCave_EventScript_UpdateSage::
	goto_if_unset FLAG_CIANWOOD_THREE_TIDES_REWARD, CianwoodThreeTidesCave_EventScript_HideSage
	goto_if_set FLAG_JOHTO_SECRET_SAGE_MET, CianwoodThreeTidesCave_EventScript_HideSage
	clearflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	end

CianwoodThreeTidesCave_EventScript_HideSage::
	setflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	end

CianwoodThreeTidesCave_EventScript_SecretSage::
	lock
	faceplayer
	msgbox CianwoodThreeTidesCave_Text_SecretSageIntro, MSGBOX_DEFAULT
	setflag FLAG_JOHTO_SECRET_SAGE_MET
	setflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	clearflag FLAG_HIDE_JOHTO_SECRET_SAGE_OUTSIDE
	removeobject LOCALID_THREE_TIDES_SECRET_SAGE
	release
	end

CianwoodThreeTidesCave_EventScript_ExitAutomatic::
	warp MAP_CIANWOOD_CITY_HNS, 17, 14
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
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 23, 5
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

CianwoodThreeTidesCave_Text_SecretSageIntro:
	.string "Así que el ATLAS eligió a otro...\p"
	.string "Yo fui el último compañero de\n"
	.string "NEREO en aquella expedición.\p"
	.string "Los sellos están despertando.\n"
	.string "Y alguien desea romperlos todos.\p"
	.string "Te esperaré fuera. La primera voz\n"
	.string "duerme en las ISLAS REMOLINO.$"
