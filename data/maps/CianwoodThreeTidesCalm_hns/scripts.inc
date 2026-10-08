CianwoodThreeTidesCalm_hns_MapScripts::
	.byte 0

CianwoodThreeTidesCalm_EventScript_Left::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_CALM_TRIAL_COMPLETE, CianwoodThreeTidesCalm_EventScript_Solved
	compare VAR_CIANWOOD_CAVE_PUZZLE, 0
	goto_if_ne CianwoodThreeTidesCalm_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 1
	msgbox CianwoodThreeTidesCalm_Text_First, MSGBOX_DEFAULT
	release
	end

CianwoodThreeTidesCalm_EventScript_Center::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_CALM_TRIAL_COMPLETE, CianwoodThreeTidesCalm_EventScript_Solved
	compare VAR_CIANWOOD_CAVE_PUZZLE, 1
	goto_if_ne CianwoodThreeTidesCalm_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 2
	msgbox CianwoodThreeTidesCalm_Text_Second, MSGBOX_DEFAULT
	release
	end

CianwoodThreeTidesCalm_EventScript_Right::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_CALM_TRIAL_COMPLETE, CianwoodThreeTidesCalm_EventScript_Solved
	compare VAR_CIANWOOD_CAVE_PUZZLE, 2
	goto_if_ne CianwoodThreeTidesCalm_EventScript_Fail
	setflag FLAG_CIANWOOD_CALM_TRIAL_COMPLETE
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesCalm_Text_Complete, MSGBOX_DEFAULT
	release
	end

CianwoodThreeTidesCalm_EventScript_Fail::
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesCalm_Text_Fail, MSGBOX_DEFAULT
	release
	end

CianwoodThreeTidesCalm_EventScript_Solved::
	msgbox CianwoodThreeTidesCalm_Text_Solved, MSGBOX_DEFAULT
	release
	end

CianwoodThreeTidesCalm_EventScript_Back::
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 4, 5
	waitstate
	end

CianwoodThreeTidesCalm_EventScript_Next::
	goto_if_unset FLAG_CIANWOOD_CALM_TRIAL_COMPLETE, CianwoodThreeTidesCalm_EventScript_Closed
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 4, 24
	waitstate
	end

CianwoodThreeTidesCalm_EventScript_Hint::
	msgbox CianwoodThreeTidesCalm_Text_Hint, MSGBOX_SIGN
	end

CianwoodThreeTidesCalm_EventScript_Closed::
	msgbox CianwoodThreeTidesCalm_Text_Closed, MSGBOX_SIGN
	end

CianwoodThreeTidesCalm_Text_First:
	.string "La corriente izquierda se aquieta.$"
CianwoodThreeTidesCalm_Text_Hint:
	.string "PRUEBA DE LA CALMA\pActiva las corrientes de izquierda\na derecha.$"
CianwoodThreeTidesCalm_Text_Second:
	.string "La corriente central te imita.$"
CianwoodThreeTidesCalm_Text_Complete:
	.string "La última corriente queda en calma.\pEl primer símbolo se enciende.$"
CianwoodThreeTidesCalm_Text_Fail:
	.string "Las corrientes se agitan.\pDebes observarlas de izquierda a\nderecha y no precipitarte.$"
CianwoodThreeTidesCalm_Text_Solved:
	.string "Esta corriente permanece en calma.$"
CianwoodThreeTidesCalm_Text_Closed:
	.string "El paso no responde.\pPrimero calma las tres corrientes.$"
