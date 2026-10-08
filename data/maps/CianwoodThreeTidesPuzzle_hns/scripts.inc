CianwoodThreeTidesPuzzle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodThreeTidesPuzzle_OnTransition
	.byte 0

CianwoodThreeTidesPuzzle_OnTransition::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0 @ Contador de monolitos colocados
	goto_if_unset FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesPuzzle_EventScript_HideSage
	goto_if_set FLAG_JOHTO_SECRET_SAGE_MET, CianwoodThreeTidesPuzzle_EventScript_HideSage
	clearflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	end

CianwoodThreeTidesPuzzle_EventScript_HideSage::
	setflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	end

CianwoodThreeTidesPuzzle_EventScript_Exit::
	warp MAP_CIANWOOD_CITY_HNS, 17, 14
	waitstate
	end

CianwoodThreeTidesPuzzle_EventScript_Signboard::
	msgbox CianwoodThreeTidesPuzzle_Text_Signboard, MSGBOX_SIGN
	end

CianwoodThreeTidesPuzzle_EventScript_SocketCalm::
	lockall
	goto_if_eq VAR_TEMP_1, 1, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_TEMP_1, 1
	addvar VAR_TEMP_4, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_CalmSet, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_4, 3, CianwoodThreeTidesPuzzle_EventScript_AllSolved
	releaseall
	end

CianwoodThreeTidesPuzzle_EventScript_SocketEcho::
	lockall
	goto_if_eq VAR_TEMP_2, 1, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_TEMP_2, 1
	addvar VAR_TEMP_4, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_EchoSet, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_4, 3, CianwoodThreeTidesPuzzle_EventScript_AllSolved
	releaseall
	end

CianwoodThreeTidesPuzzle_EventScript_SocketBrio::
	lockall
	goto_if_eq VAR_TEMP_3, 1, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_TEMP_3, 1
	addvar VAR_TEMP_4, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_BrioSet, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_4, 3, CianwoodThreeTidesPuzzle_EventScript_AllSolved
	releaseall
	end

CianwoodThreeTidesPuzzle_EventScript_SocketDone::
	releaseall
	end

CianwoodThreeTidesPuzzle_EventScript_AllSolved::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 4
	special ShakeScreen
	delay 40
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	setflag FLAG_CIANWOOD_CALM_TRIAL_COMPLETE
	setflag FLAG_CIANWOOD_ECHO_TRIAL_COMPLETE
	setflag FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE
	clearflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	addobject LOCALID_PUZZLE_SAGE
	msgbox CianwoodThreeTidesPuzzle_Text_PuzzleSolved, MSGBOX_DEFAULT
	releaseall
	end

CianwoodThreeTidesPuzzle_EventScript_Sage::
	lock
	faceplayer
	msgbox CianwoodThreeTidesCave_Text_SecretSageIntro, MSGBOX_DEFAULT
	setflag FLAG_JOHTO_SECRET_SAGE_MET
	setflag FLAG_HIDE_JOHTO_SECRET_SAGE_CAVE
	clearflag FLAG_HIDE_JOHTO_SECRET_SAGE_OUTSIDE
	removeobject LOCALID_PUZZLE_SAGE
	release
	end

CianwoodThreeTidesPuzzle_Text_Signboard:
	.string "SANTUARIO DE LAS TRES MAREAS\p"
	.string "Tres monolitos esperan su lecho.\n"
	.string "Empuja las piedras sagradas hasta\l"
	.string "las tres hendiduras del norte.$"

CianwoodThreeTidesPuzzle_Text_CalmSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "de la CALMA! La marea se aquieta.$"

CianwoodThreeTidesPuzzle_Text_EchoSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "del ECO! La caverna resuena.$"

CianwoodThreeTidesPuzzle_Text_BrioSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "del BRÍO! La corriente ruge.$"

CianwoodThreeTidesPuzzle_Text_PuzzleSolved:
	.string "¡Las tres corrientes se han unido!\p"
	.string "La niebla de la caverna se disipa\n"
	.string "y un anciano sabio aparece.$"
