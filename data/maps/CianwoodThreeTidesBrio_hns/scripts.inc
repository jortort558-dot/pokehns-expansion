CianwoodThreeTidesBrio_hns_MapScripts::
	.byte 0

CianwoodThreeTidesBrio_EventScript_Right::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesBrio_EventScript_Solved
	compare VAR_CIANWOOD_CAVE_PUZZLE, 0
	goto_if_ne CianwoodThreeTidesBrio_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 1
	msgbox CianwoodThreeTidesBrio_Text_Hit, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesBrio_EventScript_Left::
	lock
	faceplayer
	compare VAR_CIANWOOD_CAVE_PUZZLE, 1
	goto_if_ne CianwoodThreeTidesBrio_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 2
	msgbox CianwoodThreeTidesBrio_Text_Hit, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesBrio_EventScript_Center::
	lock
	faceplayer
	compare VAR_CIANWOOD_CAVE_PUZZLE, 2
	goto_if_ne CianwoodThreeTidesBrio_EventScript_Fail
	setflag FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesBrio_Text_Complete, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesBrio_EventScript_Fail::
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesBrio_Text_Fail, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesBrio_EventScript_Solved::
	msgbox CianwoodThreeTidesBrio_Text_Solved, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesBrio_EventScript_Back::
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 4, 24
	waitstate
	end
CianwoodThreeTidesBrio_EventScript_Hint::
	msgbox CianwoodThreeTidesBrio_Text_Hint, MSGBOX_SIGN
	end
CianwoodThreeTidesBrio_EventScript_Finish::
	goto_if_unset FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesBrio_EventScript_Closed
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 4, 5
	waitstate
	end
CianwoodThreeTidesBrio_EventScript_Closed:
	msgbox CianwoodThreeTidesBrio_Text_Closed, MSGBOX_SIGN
	end
CianwoodThreeTidesBrio_Text_Hit:
	.string "La roca cede con un golpe seco.$"
CianwoodThreeTidesBrio_Text_Hint:
	.string "PRUEBA DEL BRIO\pDerecha, izquierda y centro.\nReserva el centro para el final.$"
CianwoodThreeTidesBrio_Text_Complete:
	.string "La roca central retumba.\pEl símbolo de BRÍO se enciende y\nlas tres pruebas quedan completas.$"
CianwoodThreeTidesBrio_Text_Fail:
	.string "Las rocas recuperan su posición.\pLa fuerza necesita dirección.$"
CianwoodThreeTidesBrio_Text_Solved:
	.string "Esta roca ya reconoció tu fuerza.$"
CianwoodThreeTidesBrio_Text_Closed:
	.string "La salida no responde todavía.$"
