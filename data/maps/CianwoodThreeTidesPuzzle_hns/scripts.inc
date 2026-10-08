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
	goto_if_set FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 5
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	goto_if_eq VAR_TEMP_1, 1, CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	setvar VAR_TEMP_1, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_CalmSet, MSGBOX_DEFAULT
	goto CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	end

CianwoodThreeTidesPuzzle_EventScript_SocketEcho::
	lockall
	goto_if_set FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 14
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	goto_if_eq VAR_TEMP_2, 1, CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	setvar VAR_TEMP_2, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_EchoSet, MSGBOX_DEFAULT
	goto CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	end

CianwoodThreeTidesPuzzle_EventScript_SocketBrio::
	lockall
	goto_if_set FLAG_CIANWOOD_BRIO_TRIAL_COMPLETE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 24
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	goto_if_eq VAR_TEMP_3, 1, CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	setvar VAR_TEMP_3, 1
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 30
	msgbox CianwoodThreeTidesPuzzle_Text_BrioSet, MSGBOX_DEFAULT
	goto CianwoodThreeTidesPuzzle_EventScript_CheckAllThree
	end

CianwoodThreeTidesPuzzle_EventScript_CheckAllThree::
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 5
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_0x8004, 15
	setvar VAR_0x8005, 14
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 24
	special IsBoulderAtCoords
	goto_if_eq VAR_RESULT, FALSE, CianwoodThreeTidesPuzzle_EventScript_SocketDone
	goto CianwoodThreeTidesPuzzle_EventScript_AllSolved
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
	.string "INSCRIPCIÓN DE LAS TRES MAREAS\p"
	.string "“Tres monolitos, tres destinos.\n"
	.string "Escucha el rumor de la caverna:\p"
	.string "Arriba, en el extremo norte,\n"
	.string "reposa la CALMA en su lecho.\p"
	.string "En el centro de la roca aguarda\n"
	.string "el ECO que responde al paso.\p"
	.string "Y abajo a la derecha, en el rincón\n"
	.string "sureste, ruge el fiero BRÍO.\p"
	.string "Guía cada peso a su vacío\n"
	.string "y el guardián romperá su velo.”$"

CianwoodThreeTidesPuzzle_Text_CalmSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "de la CALMA!\p"
	.string "Una voz susurra entre la bruma:\n"
	.string "“Has elegido... sabiamente.”$"

CianwoodThreeTidesPuzzle_Text_EchoSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "del ECO!\p"
	.string "La caverna retumba solemnemente:\n"
	.string "“Has elegido... sabiamente.”$"

CianwoodThreeTidesPuzzle_Text_BrioSet:
	.string "¡El monolito encaja en la hendidura\n"
	.string "del BRÍO!\p"
	.string "El agua bravía calma su corriente:\n"
	.string "“Has elegido... sabiamente.”$"

CianwoodThreeTidesPuzzle_Text_PuzzleSolved:
	.string "¡Las tres corrientes han hallado\n"
	.string "su armonía ancestral!\p"
	.string "La niebla de la caverna se disipa…\p"
	.string "Sientes que una presencia sabia\n"
	.string "ha aparecido en el norte.$"
