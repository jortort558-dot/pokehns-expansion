RocketHideout_B2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B2F_OnLoad
	.byte 0

RocketHideout_B2F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT2_GATE, RocketHideout_B2F_HideGate
	call_if_eq VAR_MAHOGANY_TOWN_STATE, 13, RocketHideout_B2F_MoveLanceDragonite
	call_if_ge VAR_ELECTRODES_FAINTED, 4, RockerHideout2_DeactivateGenerator
	end

RockerHideout2_DeactivateGenerator::
	setmetatile 13, 8, 0x303, TRUE
	setmetatile 13, 9, 0x303, TRUE
	setmetatile 13, 10, 0x303, TRUE
	setmetatile 13, 11, 0x303, TRUE
	setmetatile 13, 12, 0x303, TRUE
	setmetatile 13, 13, 0x303, TRUE
	setmetatile 13, 14, 0x303, TRUE
	setmetatile 13, 15, 0x303, TRUE

	setmetatile 14, 8, 0x303, TRUE
	setmetatile 14, 9, 0x303, TRUE
	setmetatile 14, 10, 0x303, TRUE
	setmetatile 14, 11, 0x303, TRUE
	setmetatile 14, 12, 0x303, TRUE
	setmetatile 14, 13, 0x303, TRUE
	setmetatile 14, 14, 0x303, TRUE
	setmetatile 14, 15, 0x303, TRUE

	setmetatile 15, 8, 0x303, TRUE
	setmetatile 15, 9, 0x303, TRUE
	setmetatile 15, 10, 0x303, TRUE
	setmetatile 15, 11, 0x303, TRUE
	setmetatile 15, 12, 0x303, TRUE
	setmetatile 15, 13, 0x303, TRUE
	setmetatile 15, 14, 0x303, TRUE
	setmetatile 15, 15, 0x303, TRUE

	setmetatile 16, 8, 0x303, TRUE
	setmetatile 16, 9, 0x303, TRUE
	setmetatile 16, 10, 0x303, TRUE
	setmetatile 16, 11, 0x303, TRUE
	setmetatile 16, 12, 0x303, TRUE
	setmetatile 16, 13, 0x303, TRUE
	setmetatile 16, 14, 0x303, TRUE
	setmetatile 16, 15, 0x303, TRUE

	setmetatile 17, 8, 0x303, TRUE
	setmetatile 17, 9, 0x303, TRUE
	setmetatile 17, 10, 0x303, TRUE
	setmetatile 17, 11, 0x303, TRUE
	setmetatile 17, 12, 0x303, TRUE
	setmetatile 17, 13, 0x303, TRUE
	setmetatile 17, 14, 0x303, TRUE
	setmetatile 17, 15, 0x303, TRUE

	setmetatile 18, 8, 0x303, TRUE
	setmetatile 18, 9, 0x303, TRUE
	setmetatile 18, 10, 0x303, TRUE
	setmetatile 18, 11, 0x303, TRUE
	setmetatile 18, 12, 0x303, TRUE
	setmetatile 18, 13, 0x303, TRUE
	setmetatile 18, 14, 0x303, TRUE
	setmetatile 18, 15, 0x303, TRUE
	return

RocketHideout_B2F_HideGate::
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	return

RocketHideout_B2F_MoveLanceDragonite::
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	return

RocketHideout_B2F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout_B2F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setvar VAR_MAHOGANY_TOWN_STATE, 10
	release
	end

RocketHideout_B2F_Movement_MurkrowStairs1:
	jump_in_place_left
	jump_in_place_left
	step_end

RocketHideout_B2F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Trigger_MurkrowGate::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_Murkrow, MSGBOX_DEFAULT
	msgbox RocketHideout_B2F_Text_MurkrowUnlock, MSGBOX_DEFAULT
	playse SE_CLICK
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWGATE, RocketHideout_B2F_Movement_MurkrowGate2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 12
	release
	end
RocketHideout_B2F_Movement_MurkrowGate1:
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B2F_Movement_MurkrowGate2:
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RocketHideout_B2F_Text_MurkrowUnlock:
	.string "MURKROW graznó la contraseña\nimitando\lla voz de PETREL a la perfección.\p..................\n¡El sistema de reconocimiento de\lvoz ha\ldesbloqueado la puerta!$"
@============================================================================================================================================

RocketHideout_B2F_Trigger_PlayerMoveLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return
RocketHideout_B2F_Trigger_PlayerMoveRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

RocketHideout_B2F_Trigger_Ariana::
	lock 
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 6, 26
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 5, 26
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	addobject LOCALID_ROCKETHIDEOUT2_ARIANA
	addobject LOCALID_ROCKETHIDEOUT2_GRUNT
	delay 20
	msgbox RocketHideout_B2F_Text_ArianaHoldIt, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 14, RocketHideout_B2F_Trigger_PlayerMoveLeft
	call_if_eq VAR_TEMP_0, 16, 	RocketHideout_B2F_Trigger_PlayerMoveRight
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerMeetAriana
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, RocketHideout_B2F_Movement_Ariana
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, RocketHideout_B2F_Movement_Ariana
	waitmovement LOCALID_ROCKETHIDEOUT2_GRUNT
	msgbox RocketHideout_B2F_Text_ArianaChallenge, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	addobject LOCALID_ROCKETHIDEOUT2_LANCE
	addobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_Lance
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_Lance
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceInterrupt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkInPlaceFasterUp
	msgbox RocketHideout_B2F_Text_ArianaOutraged
	closemessage
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt
	end
	
RocketHideout_B2F_Movement_PlayerMeetAriana:
	walk_down
	walk_down
	walk_down
	step_end

RocketHideout_B2F_Movement_Ariana:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B2F_Movement_Lance:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B2F_Text_ArianaHoldIt:
	.string "ATENEA: ¡Alto ahí mismo!$"
RocketHideout_B2F_Text_ArianaChallenge:
	.string "ATENEA: No podemos permitir que una\nsabandija\lcomo tú siga campando a sus anchas.\lHieres el orgullo del Team Rocket\luna y\lotra vez.\l...Así que ha llegado la hora de\lborrarte\ldel mapa.\lPor muy fuerte que te creas,\lsi luchamos dos contra uno, no\ltienes la más\lmínima posibilidad de ganar. ¿A que\lno?\l¡Ji, ji, ji! Lo siento, criatura.\l¡Prepárate para recibir una paliza!$"
RocketHideout_B2F_Text_LanceInterrupt:
	.string "LANCE: ¡Un momento!\n¿Un combate de dos contra uno?\p¡Eso es de una cobardía\nintolerable!\lTípico del Team Rocket recurrir a\lestas\lartimañas rastreras.\p¡Permíteme que me una a la batalla!$"
RocketHideout_B2F_Text_ArianaOutraged:
	.string "ATENEA: ¿Qué? ¿Tenías un cómplice?\n¿Dónde está vuestro sentido del\lhonor?\l¡Como líder provisional en ausencia\lde\lGIOVANNI, os enseñaré lo que cuesta\lmeterse\lcon el Team Rocket!$"
RocketHideout_B2F_Text_LanceChooseMons:
	.string "LANCE: ¡Rápido, {PLAYER}!\n¡Elige a tus POKéMON!$"
RocketHideout_B2F_EventScript_ReadyForBattlePrompt::
	msgbox RocketHideout_B2F_Text_LanceChooseMons, MSGBOX_DEFAULT
	goto RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle
	end

RocketHideout_B2F_EventScript_ChoosePartyForMultiBattle::
	setflag FLAG_ROCKETHIDEOUT2_BATTLE
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, RocketHideout_B2F_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	goto RocketHideout_B2F_EventScript_ReadyForBattlePrompt

RocketHideout_B2F_EventScript_DoLanceMultiBattle::
	@ special ReducePlayerPartyToSelectedMons
	@ frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	@ setvar VAR_0x8004, SPECIAL_BATTLE_LANCE
	@ setvar VAR_0x8005, 0
	applymovement LOCALID_ROCKETHIDEOUT2_ARIANA, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_GRUNT, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_ROCKETHIDEOUT2_GRUNT, DIR_WEST
	multi_2_vs_2 TRAINER_ARIANA_1_HNS, Debug_Text_ArianaDefeat, TRAINER_GRUNT_23_HNS, Debug_Text_Grunt23Defeat, PARTNER_LANCE_HNS
	@ special DoSpecialTrainerBattle
	@ waitstate
	@ frontier_saveparty
	@ special LoadPlayerParty
	switch VAR_RESULT
	case 1, RocketHideout_B2F_EventScript_DefeatedAriana
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	special SetCB2WhiteOut
	waitstate

RocketHideout_B2F_EventScript_DefeatedAriana::
	clearflag FLAG_ROCKETHIDEOUT2_BATTLE
	msgbox RocketHideout_Text_ArianaRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkUp1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, Common_Movement_WalkRight1
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, Common_Movement_WalkRight1
	waitmovement 0
	setflag FLAG_HIDE_MAHOGANY_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	removeobject LOCALID_ROCKETHIDEOUT2_ARIANA
	removeobject LOCALID_ROCKETHIDEOUT2_GRUNT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox RocketHideout_Text_LanceStepBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteWalkToGenerator
	delay 55
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_LanceWalkToGenerator
	waitmovement 0

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteInvestigateGenerator
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceInvestigateGenerator
	delay 165
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	msgbox RocketHideout_B2F_Text_LanceElectrodeFaint, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceWalkToElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	applymovement OBJ_EVENT_ID_PLAYER, RocketHideout_B2F_Movement_PlayerWalkToElectrode
	waitmovement 0
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_DRAGONITE, 20, 16
	setobjectxyperm LOCALID_ROCKETHIDEOUT2_LANCE, 19, 16
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_DRAGONITE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ROCKETHIDEOUT2_LANCE, MOVEMENT_TYPE_FACE_UP
	setvar VAR_MAHOGANY_TOWN_STATE, 13
	release
	end

RocketHideout_B2F_Movement_LanceWalkToGenerator:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
RocketHideout_B2F_Movement_DragoniteWalkToGenerator:
	delay_8
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	step_end


RocketHideout_B2F_Movement_LanceInvestigateGenerator:
	walk_up
	walk_left
	face_up
	delay_8
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_8
	delay_8
	face_right
	delay_8
	delay_8
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RocketHideout_B2F_Movement_DragoniteInvestigateGenerator:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	delay_16
	delay_16
	delay_8
	delay_8	
	delay_8
	delay_8
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceWalkToElectrode:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RocketHideout_B2F_Movement_PlayerWalkToElectrode:
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Trigger_Electrode::
	lock
	goto_if_eq VAR_ELECTRODES_FAINTED, 3, RocketHideout_B2F_EventScript_ElectrodeDone
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_WEST
	msgbox RocketHideout_B2F_Text_LanceSide, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	release
	end

RocketHideout_B2F_EventScript_Electrode::
	lock
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELECTRODE, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RocketHideout_B2F_EventScript_Ran_Electrode
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RocketHideout_B2F_EventScript_Ran_Electrode
	removeobject VAR_LAST_TALKED
	addvar VAR_ELECTRODES_FAINTED, 1
	release
	end

RocketHideout_B2F_EventScript_Ran_Electrode::
	release
	end

RocketHideout_B2F_EventScript_ElectrodeDone::
	playse SE_M_HYPER_BEAM
	removeobject LOCALID_LANCEELECTRODE1
	removeobject LOCALID_LANCEELECTRODE2
	removeobject LOCALID_LANCEELECTRODE3
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1 
	call_if_eq VAR_TEMP_1, 16, RocketHideout_B2F_Movement_PlayerMeetLanceTop
	call_if_eq VAR_TEMP_1, 18, RocketHideout_B2F_Movement_PlayerMeetLanceBot
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE

	playse SE_CLICK
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_NORTH
	call RockerHideout2_DeactivateGenerator
	special DrawWholeMapView
	delay 55
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox RocketHideout_B2F_Text_LanceElectrodeDone, MSGBOX_DEFAULT
	giveitem ITEM_HM_WHIRLPOOL
	msgbox RocketHideout_B2F_Text_LanceWhirlpool, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROCKETHIDEOUT2_LANCE, DIR_SOUTH
	delay 20
	msgbox RocketHideout_B2F_Text_LanceMonMaster, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceFinalExit
	delay 20

	applymovement LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteFinalExit
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE

	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_ELECTRODES_FAINTED, 4
	setvar VAR_MAHOGANY_TOWN_STATE, 14
	clearflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 2
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 2
	release
	end

RocketHideout_B2F_Movement_PlayerMeetLanceTop:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	return

RocketHideout_B2F_Movement_PlayerMeetLanceBot:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	return

RocketHideout_B2F_Movement_LanceMeetPlayerAfterElectrode:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Movement_LanceFinalExit:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Movement_DragoniteFinalExit:
	walk_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Text_GruntLoss:
	.string "....................$"
RocketHideout_B2F_Text_ArianaLoss:
	.string "Tsk... Reconozco que tienes una\nfuerza fuera\lde lo común. Qué desperdicio.\lSi te unieras al Team Rocket\lpodrías llegar\la ser Ejecutivo.$"
RocketHideout_Text_ArianaRetreat:
	.string "ATENEA: Pero no importa.\nEl experimento de la emisión de\lradio ha\lsido un éxito rotundo.\lNos da igual lo que le pase a esta\lguarida.\lNuestros planes son infinitamente\lmayores.\lPronto comprenderéis el auténtico\lpoder del\lTeam Rocket.\lDisfrutad mientras podáis... ¡Ji,\lji, ji!$"
RocketHideout_Text_LanceStepBack:
	.string "Perdona, {PLAYER}. Vi que lo tenías\ntodo\lbajo control, así que preferí\lguardar las\lespaldas.\lAhora solo queda apagar esa\lsiniestra señal\lde radio.$"
RocketHideout_B2F_Text_LanceElectrodeFaint:
	.string "Es esta máquina la que está\ncausando todos\llos estragos.\lNo veo ningún interruptor a simple\lvista…\lNo tenemos elección: debemos\ldebilitar a\ltodos los ELECTRODE del generador.\lEso detendrá la transmisión de la\lseñal.\lLos POKéMON no tienen la culpa de\lesto,\lme parte el alma tener que hacerlo.\l{PLAYER}, repartámonos el trabajo.$"
RocketHideout_B2F_Text_LanceSide:
	.string "LANCE: Déjame este lado a mí.$"
RocketHideout_B2F_Text_LanceElectrodeDone:
	.string "LANCE: Por fin ha cesado esa\nextraña señal.\lEl LAGO debería volver a la\lnormalidad.\l¡Eres todo un héroe! Permíteme\ldarte las\lgracias en nombre de todos los\lPOKéMON.\l¡Ah, sí! Quédate con esto.\lLo encontré por aquí, pero a mí no\lme hace\lfalta.$"
RocketHideout_B2F_Text_LanceWhirlpool:
	.string "Es TORBELLINO. Enséñaselo a un\nPOKéMON para\lsortear aguas turbulentas y\lremolinos.\lPero ten presente una cosa:\lsolo podrás usarlo fuera de combate\lsi portas\lla MEDALLA del GIMNASIO de CAOBA.$"
RocketHideout_B2F_Text_LanceMonMaster:
	.string "{PLAYER}…\nEl camino para convertirse en\lMAESTRO\lPOKéMON es largo y sacrificado.\lSabiendo eso... ¿seguirás adelante?\l…\lYa veo. Tienes razón.\lSi te rindieras tan fácilmente,\ljamás habrías\lpersiguido ese sueño desde el\lprincipio.\l¡Espero con ansias nuestro próximo\lencuentro!$"
RocketHideout_B2F_Text_B2FTransmitter:
	.string "Es el transmisor de radio que envía\nla señal\lsiniestra.\lEstá funcionando a máxima potencia.$"
RocketHideout_B2F_Text_B2FDeactivateTransmitter:
	.string "El transmisor de radio por fin ha\ndetenido su\lmalévola emisión.$"
@===========================================================================================================================================

RocketHideout_EventScript_Item_Thief::
	finditem ITEM_TM_THIEF
	end

RocketHideout_B2F_EventScript_LanceTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_LanceTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout_B2F_EventScript_Lance

RocketHideout_B2F_EventScript_Lance::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	msgbox RocketHideout_B2F_Text_LanceHeals1, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RocketHideout_B2F_Text_LanceHeals2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout_B2F_Movement_LanceGoDeeper
	applymovement2 LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout_B2F_Movement_DragoniteGoDeeper
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 6
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	release
	end

RocketHideout_B2F_Movement_LanceGoDeeper:
	walk_right
	walk_right
	delay_2
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Movement_DragoniteGoDeeper:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Text_LanceHeals1:
	.string "LANCE: ¿Te encuentras bien?\nTus POKéMON están exhaustos y\lheridos.\lToma, déjame curarlos con mi\lmedicina.$"
RocketHideout_B2F_Text_LanceHeals2:
	.string "LANCE: {PLAYER}, demos lo mejor de\nnosotros\lpor el bien de los POKéMON.$"
RocketHideout_B2F_Text_GruntM17Seen:
	.string "¿Que la puerta no se abre?\nPues claro, genio. Hace falta una\lcontraseña\lque solo conocemos en el TEAM\lROCKET.$"
RocketHideout_B2F_Text_GruntM17Beaten:
	.string "¿Qué? ¡¿He perdido?!$"
RocketHideout_B2F_Text_GruntM17After:
	.string "Je, no soy más que un SOLDADO.\nNo tengo ni idea de cuál es la\lclave.\lTú te lo pierdes.$"
RocketHideout_B2F_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_14_HNS, RocketHideout_B2F_Text_GruntM17Seen, RocketHideout_B2F_Text_GruntM17Beaten
	msgbox RocketHideout_B2F_Text_GruntM17After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM18Seen:
	.string "¿Un crío? No es plato de buen gusto\npara\lmí, pero las órdenes son\leliminarte.$"
RocketHideout_B2F_Text_GruntM18Beaten:
	.string "Sabía que iba a perder…$"
RocketHideout_B2F_Text_GruntM18After:
	.string "En la última misión también me\nbarrió un crío.\lEstábamos mangando POKéMON y un\lchaval con\lpelo rojo y cara de pocos amigos me\ldio una\lpaliza tremenda…$"
RocketHideout_B2F_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_15_HNS, RocketHideout_B2F_Text_GruntM18Seen, RocketHideout_B2F_Text_GruntM18Beaten
	msgbox RocketHideout_B2F_Text_GruntM18After, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntM19Seen:
	.string "¡Maldita sabandija entrometida!$"
RocketHideout_B2F_Text_GruntM19Beaten:
	.string "Grrrrr…$"
RocketHideout_B2F_Text_GruntM19After:
	.string "Je, solo los jefes conocen la\ncontraseña de\lesa puerta.\l¿Dónde están? ¿Quién sabe? Búscalos\ltú.$"
RocketHideout_B2F_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_16_HNS, RocketHideout_B2F_Text_GruntM19Seen, RocketHideout_B2F_Text_GruntM19Beaten
	msgbox RocketHideout_B2F_Text_GruntM19After, MSGBOX_AUTOCLOSE
	end
