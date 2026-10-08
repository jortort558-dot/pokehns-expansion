CianwoodThreeTidesEcho_hns_MapScripts::
	.byte 0

CianwoodThreeTidesEcho_EventScript_Center::
	lock
	faceplayer
	goto_if_set FLAG_CIANWOOD_ECHO_TRIAL_COMPLETE, CianwoodThreeTidesEcho_EventScript_Solved
	compare VAR_CIANWOOD_CAVE_PUZZLE, 0
	goto_if_ne CianwoodThreeTidesEcho_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 1
	msgbox CianwoodThreeTidesEcho_Text_Note, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesEcho_EventScript_Right::
	lock
	faceplayer
	compare VAR_CIANWOOD_CAVE_PUZZLE, 1
	goto_if_ne CianwoodThreeTidesEcho_EventScript_Fail
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 2
	msgbox CianwoodThreeTidesEcho_Text_Note, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesEcho_EventScript_Left::
	lock
	faceplayer
	compare VAR_CIANWOOD_CAVE_PUZZLE, 2
	goto_if_ne CianwoodThreeTidesEcho_EventScript_Fail
	setflag FLAG_CIANWOOD_ECHO_TRIAL_COMPLETE
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesEcho_Text_Complete, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesEcho_EventScript_Fail::
	setvar VAR_CIANWOOD_CAVE_PUZZLE, 0
	msgbox CianwoodThreeTidesEcho_Text_Fail, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesEcho_EventScript_Solved::
	msgbox CianwoodThreeTidesEcho_Text_Solved, MSGBOX_DEFAULT
	release
	end
CianwoodThreeTidesEcho_EventScript_Back::
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 14, 5
	waitstate
	end
CianwoodThreeTidesEcho_EventScript_Next::
	goto_if_unset FLAG_CIANWOOD_ECHO_TRIAL_COMPLETE, CianwoodThreeTidesEcho_EventScript_Closed
	warp MAP_CIANWOOD_THREE_TIDES_CAVE_HNS, 14, 13
	waitstate
	end
CianwoodThreeTidesEcho_EventScript_Closed:
	msgbox CianwoodThreeTidesEcho_Text_Closed, MSGBOX_SIGN
	end
CianwoodThreeTidesEcho_Text_Note:
	.string "La piedra devuelve un eco grave.$"
CianwoodThreeTidesEcho_Text_Complete:
	.string "Centro, derecha, izquierda.\pEl eco repite la secuencia y el\nsegundo símbolo se enciende.$"
CianwoodThreeTidesEcho_Text_Fail:
	.string "El eco se rompe y guarda silencio.\pRecuerda dónde nació el sonido.$"
CianwoodThreeTidesEcho_Text_Solved:
	.string "La piedra conserva su último eco.$"
CianwoodThreeTidesEcho_Text_Closed:
	.string "El paso espera una melodía\ncompleta.$"
