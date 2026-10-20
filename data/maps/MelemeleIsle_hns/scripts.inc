MelemeleIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_DAY
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_ALOLA_TRAVEL, 1, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

MelemeleIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 34
	goto_if_ne MelemeleIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 26
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 27
	goto_if_eq MelemeleIsle_hns_SetTotemSignWarpFacing_Set
	goto MelemeleIsle_hns_SetTotemSignWarpFacing_End

MelemeleIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

MelemeleIsle_hns_SetTotemSignWarpFacing_End:
	return

MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement Alola_Melemele_Captain, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_TRAVEL, 1, Alola_Melemele_GetOffBoat
	.2byte 0


Alola_Melemele_GetOffBoat::
	lock
	delay 30
	applymovement Alola_Melemele_Captain, Alola_Melemele_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, Alola_Melemele_GetOffBoat_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_GetOffBoat_Text_0, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_TRAVEL, 2
	applymovement LOCALID_PLAYER, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TravelToKanto::
	lock
	faceplayer
	msgbox Alola_Melemele_TravelToKanto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_TravelToKanto_1
	msgbox Alola_Melemele_TravelToKanto_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_TravelToKanto_1:
	msgbox Alola_Melemele_TravelToKanto_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 32
	goto_if_eq Alola_Melemele_TravelToKanto_5
	compare VAR_TEMP_0, 23
	goto_if_eq Alola_Melemele_TravelToKanto_8
Alola_Melemele_TravelToKanto_7:
Alola_Melemele_TravelToKanto_4:
	applymovement Alola_Melemele_Captain, Alola_Melemele_TravelToKanto_Movement_2
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_2
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_MELEMELE_ISLE_HNS
	hideobjectat Alola_Melemele_Captain, MAP_MELEMELE_ISLE_HNS
	applymovement OBJ_EVENT_ID_CAMERA, Alola_Melemele_TravelToKanto_Movement_3
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement Alola_Melemele_Ship, Alola_Melemele_TravelToKanto_Movement_4
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	special RemoveCameraObject
	warp MAP_ROUTE13_HNS, 77, 26
	waitstate
	end

Alola_Melemele_TravelToKanto_5:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_0
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_6:
	applymovement LOCALID_PLAYER, Alola_Melemele_TravelToKanto_Movement_1
	waitmovement 0
	goto Alola_Melemele_TravelToKanto_4

Alola_Melemele_TravelToKanto_8:
	compare VAR_TEMP_1, 33
	goto_if_eq Alola_Melemele_TravelToKanto_6
	goto Alola_Melemele_TravelToKanto_7


Alola_Melemele_Mailbox::
	lock
	msgbox Alola_Melemele_Mailbox_Text_0
	release
	end


Alola_Melemele_Melemele_Sign::
	lock
	msgbox Alola_Melemele_Melemele_Sign_Text_0
	release
	end


Alola_Melemele_Pokecenter_Sign::
	lock
	msgbox Alola_Melemele_Pokecenter_Sign_Text_0
	release
	end


Alola_Melemele_MelemeleMart_Sign::
	lock
	msgbox Alola_Melemele_MelemeleMart_Sign_Text_0
	release
	end


Alola_Melemele_FindItem1::
	finditem ITEM_RARE_CANDY, 1
	end


Alola_Melemele_SamsonOak_Trigger_Beginning::
	lock
	addobject SamsonOakMelemeleIntro
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0
	waitmovement 0
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3
	waitmovement 0
	delay 15
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3, MSGBOX_AUTOCLOSE
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4
	applymovement LOCALID_PLAYER, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5
	waitmovement 0
	delay 30
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6, MSGBOX_AUTOCLOSE
	applymovement SamsonOakMelemeleIntro, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7
	waitmovement 0
	delay 30
	fadedefaultbgm
	setvar VAR_ALOLA_STATE, 1
	removeobject SamsonOakMelemeleIntro
	setflag FLAG_VISITED_ALOLA
	release
	end


Alola_Melemele_NeedToTalkToSamsonOak::
	lock
	msgbox Alola_Melemele_NeedToTalkToSamsonOak_Text_0, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Alola_Melemele_NeedToTalkToSamsonOak_Movement_0
	waitmovement 0
	release
	end


Alola_Melemele_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_MELEMELE_TOTEM, Alola_Melemele_TotemBattle_Trigger_1
	end

Alola_Melemele_TotemBattle_Trigger_1:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_TotemBattle_Trigger_7
Alola_Melemele_TotemBattle_Trigger_5:
	end

Alola_Melemele_TotemBattle_Trigger_4:
	lock
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreenswapbuffers FADE_TO_BLACK
	delay 30
	clearflag FLAG_HIDE_MELEMELE_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_14
	playmoncry SPECIES_RATICATE_ALOLA, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( RATICATE_ALOLA )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq Alola_Melemele_TotemBattle_Trigger_20
	playmoncry SPECIES_RATICATE_ALOLA, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
Alola_Melemele_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_MELEMELE_TOTEM
	release
	end

Alola_Melemele_TotemBattle_Trigger_6:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_TotemBattle_Trigger_10
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_7:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_TotemBattle_Trigger_6
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_10:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_TotemBattle_Trigger_4
	goto Alola_Melemele_TotemBattle_Trigger_5

Alola_Melemele_TotemBattle_Trigger_14:
	playmoncry SPECIES_LEAFEON, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	addobject Melemele_Totem
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_13

Alola_Melemele_TotemBattle_Trigger_20:
	playmoncry SPECIES_LEAFEON, 0
	applymovement Melemele_Totem, Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
	goto Alola_Melemele_TotemBattle_Trigger_19


Alola_Melemele_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_MELEMELE_TOTEM_DAY, Alola_Melemele_TotemBattle_1
	playmoncry SPECIES_RATICATE_ALOLA, 0
	msgbox Alola_Melemele_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RATTATA_ALOLA, 60, ITEM_NONE, SPECIES_RATICATE_ALOLA_TOTEM, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_7
	return

Alola_Melemele_TotemBattle_1:
	playmoncry SPECIES_LEAFEON, 0
	msgbox Alola_Melemele_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_EEVEE, 60, ITEM_NONE, SPECIES_LEAFEON, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_TotemBattle_5
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Alola_Melemele_TotemBattle_9
	return

Alola_Melemele_TotemBattle_5:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_7:
	setflag FLAG_HIDE_MELEMELE_TOTEM
	setflag FLAG_DEFEATED_MELEMELE_TOTEM
	removeobject Melemele_Totem
	msgbox Alola_Melemele_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Alola_Melemele_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


Alola_Melemele_Totem_sign::
	lock
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_Totem_sign_5
Alola_Melemele_Totem_sign_3:
	msgbox Alola_Melemele_Totem_sign_Text_6, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_Totem_sign_2:
	msgbox Alola_Melemele_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_Totem_sign_Text_1, Alola_Melemele_Totem_sign_Text_2, Alola_Melemele_Totem_sign_Text_3, Alola_Melemele_Totem_sign_Text_4, Alola_Melemele_Totem_sign_Text_5
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_Totem_sign_12
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_Totem_sign_15
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_Totem_sign_18
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_Totem_sign_20
	release
	end

Alola_Melemele_Totem_sign_4:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_Totem_sign_8
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_5:
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_Totem_sign_4
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_8:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_Totem_sign_2
	goto Alola_Melemele_Totem_sign_3

Alola_Melemele_Totem_sign_12:
	goto_if_unset FLAG_HIDE_TAPU_KOKO, Alola_Melemele_Totem_sign_12_Lower
	warp MAP_MELEMELE_ISLE_HNS, 34, 26
	waitstate
	end

Alola_Melemele_Totem_sign_12_Lower:
	warp MAP_MELEMELE_ISLE_HNS, 34, 27
	waitstate
	end

Alola_Melemele_Totem_sign_15:
	goto_if_unset FLAG_HIDE_TAPU_LELE, Alola_Melemele_Totem_sign_15_Lower
	warp MAP_AKALA_ISLE_HNS, 9, 11
	waitstate
	end

Alola_Melemele_Totem_sign_15_Lower:
	warp MAP_AKALA_ISLE_HNS, 9, 12
	waitstate
	end

Alola_Melemele_Totem_sign_18:
	goto_if_unset FLAG_HIDE_TAPU_BULU, Alola_Melemele_Totem_sign_18_Lower
	warp MAP_ULA_ULA_FOREST_HNS, 16, 5
	waitstate
	end

Alola_Melemele_Totem_sign_18_Lower:
	warp MAP_ULA_ULA_FOREST_HNS, 16, 6
	waitstate
	end

Alola_Melemele_Totem_sign_20:
	goto_if_unset FLAG_HIDE_TAPU_FINI, Alola_Melemele_Totem_sign_20_Lower
	warp MAP_PONI_ISLE_HNS, 13, 8
	waitstate
	end

Alola_Melemele_Totem_sign_20_Lower:
	warp MAP_PONI_ISLE_HNS, 13, 9
	waitstate
	end


Alola_MeleMele_TapuKoko_Flyover::
	goto_if_set FLAG_FLYOVER_TAPU_KOKO, Alola_MeleMele_TapuKoko_Flyover_2
	release
	end

Alola_MeleMele_TapuKoko_Flyover_2:
	addobject Melemele_Flyover_Tapu
	playse SE_M_FLY
	applymovement Melemele_Flyover_Tapu, Alola_MeleMele_TapuKoko_Flyover_Movement_0
	waitmovement 0
	removeobject Melemele_Flyover_Tapu
	clearflag FLAG_FLYOVER_TAPU_KOKO
	clearflag FLAG_HIDE_TAPU_KOKO
	release
	end


Alola_Melemele_BattleVsTapuKoko::
	lock
	faceplayer
	playmoncry SPECIES_TAPU_KOKO, CRY_MODE_ENCOUNTER
	msgbox Alola_Melemele_BattleVsTapuKoko_Text_0
	waitmoncry
	seteventmon SPECIES_TAPU_KOKO, 60
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Melemele_BattleVsTapuKoko_3
	release
	end

	release
	end

Alola_Melemele_BattleVsTapuKoko_2:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end

Alola_Melemele_BattleVsTapuKoko_3:
	setflag FLAG_HIDE_TAPU_KOKO
	setflag FLAG_BATTLED_TAPU_KOKO
	removeobject Melemele_Tapu
	release
	end


Alola_Melemele_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_1_HNS, Alola_Melemele_TrainerBattleSwimmer_Text_0, Alola_Melemele_TrainerBattleSwimmer_Text_1
	msgbox Alola_Melemele_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Bugcatcher::
	lock
	faceplayer
	msgbox Alola_Melemele_Bugcatcher_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_camper::
	lock
	faceplayer
	msgbox Alola_Melemele_camper_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Alola_Melemele_Picnicker::
	lock
	faceplayer
	msgbox Alola_Melemele_Picnicker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

Alola_Melemele_GetOffBoat_Movement_0:
	face_right
	step_end

Alola_Melemele_GetOffBoat_Movement_1:
	face_left
	step_end

Alola_Melemele_TravelToKanto_Movement_0:
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_1:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_2:
	face_down
	step_end

Alola_Melemele_TravelToKanto_Movement_3:
	walk_down
	step_end

Alola_Melemele_TravelToKanto_Movement_4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_0:
	emote_exclamation_mark
	face_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_3:
	walk_in_place_up
	walk_in_place_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_4:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_5:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_6:
	jump_in_place_down
	jump_in_place_down
	step_end

Alola_Melemele_SamsonOak_Trigger_Beginning_Movement_7:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Alola_Melemele_NeedToTalkToSamsonOak_Movement_0:
	walk_up
	step_end

Alola_MeleMele_TapuKoko_Flyover_Movement_0:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Alola_Melemele_GetOffBoat_Text_0:
	.string "¡De vuelta a las ISLAS!\p"
	.string "¡Vuelve cuando quieras viajar a\n"
	.string "tierra firme en KANTO!$"

Alola_Melemele_TravelToKanto_Text_0:
	.string "¡Ah del barco!\p"
	.string "¿Quieres viajar de vuelta a\n"
	.string "KANTO?$"

Alola_Melemele_TravelToKanto_Text_1:
	.string "¡Ah del barco! ¡Sube a bordo!$"

Alola_Melemele_TravelToKanto_Text_2:
	.string "¡Ah del barco!\n"
	.string "Vuelve cuando quieras zarpar.$"

Alola_Melemele_Mailbox_Text_0:
	.string "VILLA DE GABRIEL OAK$"

Alola_Melemele_Melemele_Sign_Text_0:
	.string "¡Bienvenido a la ISLA MELEMELE!$"

Alola_Melemele_Pokecenter_Sign_Text_0:
	.string "¡CENTRO POKéMON DE ISLA MELEMELE!\p"
	.string "Es el único CENTRO POKéMON de las\n"
	.string "ISLAS ALOLA, pero puedes descansar\l"
	.string "en bancos repartidos por las islas.$"

Alola_Melemele_MelemeleMart_Sign_Text_0:
	.string "TIENDA POKéMON DE MELEMELE$"

Alola_Melemele_BattleSandygast_Text_0:
	.string "¡Kuuuuur!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_0:
	.string "¡ALOLA!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_1:
	.string "¡Bienvenido a las ISLAS ALOLA!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_2:
	.string "¡Me llamo GABRIEL OAK!\n"
	.string "Soy PROFESOR POKéMON.\p"
	.string "¿Cómo te llamas?$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_3:
	.string "¡Ah, {PLAYER}!\n"
	.string "¡Un gran nombre!\p"
	.string "Quizás conozcas a mi primo, el\n"
	.string "PROFESOR OAK, de la región de KANTO.\p"
	.string "¡Deja que te enseñe el pueblo!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_4:
	.string "Este es el pueblo principal de las islas.\p"
	.string "Se parece muchísimo a CIUDAD HAUOLI\n"
	.string "en ALOLA… {PAUSE 30}Y bien pensado…\p"
	.string "toda la isla me recuerda a la\n"
	.string "auténtica ISLA DE MELEMELE…$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_5:
	.string "Bueno, ¡al grano!\p"
	.string "¡Investigo las variaciones de POKéMON\n"
	.string "que habitan en distintas regiones!\p"
	.string "De regreso de la región de ALOLA,\n"
	.string "tropecé con este archipiélago…\p"
	.string "Para mi sorpresa, muchos POKéMON\n"
	.string "de ALOLA también vivían aquí, así\l"
	.string "que llamé al lugar… {PAUSE 30}¡las ISLAS ALOLA!$"

Alola_Melemele_SamsonOak_Trigger_Beginning_Text_6:
	.string "Aún no he explorado todas las islas…\n"
	.string "{PAUSE 30}Yo también acabo de desembarcar.\p"
	.string "Me gustaría comprobar si están aquí\n"
	.string "todas las variantes de ALOLA.\p"
	.string "Si te cruzas con alguna, ¡pásate por\n"
	.string "mi villa al este y enséñamela!\p"
	.string "¡Ah! Y siéntete libre de explorar la\n"
	.string "isla a tu aire.\p"
	.string "¡Nos vemos allí!$"

Alola_Melemele_NeedToTalkToSamsonOak_Text_0:
	.string "GABRIEL te espera en su villa…\n"
	.string "{PAUSE 30}¡Mejor no le hagas esperar mucho!$"

Alola_Melemele_TotemBattle_Text_0:
	.string "¡Liiii!$"

Alola_Melemele_TotemBattle_Text_1:
	.string "¡Venciste a LEAFEON Dominante!\n"
	.string "Salió huyendo a algún sitio…$"

Alola_Melemele_TotemBattle_Text_2:
	.string "¡Tssssh!$"

Alola_Melemele_TotemBattle_Text_3:
	.string "¡Venciste a RATICATE Dominante!\n"
	.string "Salió huyendo a algún sitio…$"

MelemeleIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


Alola_Melemele_Totem_sign_Text_0:
	.string "El tótem desprende una intensa\n"
	.string "energía…\p"
	.string "¿Quieres tocarlo para teletransportarte\n"
	.string "a otra isla?$"

Alola_Melemele_Totem_sign_Text_1:
	.string "ISLA MELEMELE$"

Alola_Melemele_Totem_sign_Text_2:
	.string "ISLA AKALA$"

Alola_Melemele_Totem_sign_Text_3:
	.string "ISLA ULA-ULA$"

Alola_Melemele_Totem_sign_Text_4:
	.string "ISLA PONI$"

Alola_Melemele_Totem_sign_Text_5:
	.string "CANCELAR$"

Alola_Melemele_Totem_sign_Text_6:
	.string "Hay un extraño tótem erigido aquí…\n"
	.string "Emana un gran poder misterioso.$"

Alola_Melemele_BattleVsTapuKoko_Text_0:
	.string "¡Ko-Ko-Kooo!$"

Alola_Melemele_TrainerBattleSwimmer_Text_0:
	.string "¡El agua está templadita junto a las\n"
	.string "ISLAS!$"

Alola_Melemele_TrainerBattleSwimmer_Text_1:
	.string "Quizá debería secarme un rato en la\n"
	.string "orilla…$"

Alola_Melemele_TrainerBattleSwimmer_Text_2:
	.string "¡Hay un montón de POKéMON en el agua!\n"
	.string "¡Prueba todas tus cañas de pescar!$"

Alola_Melemele_Bugcatcher_Text_0:
	.string "¡Los POKéMON bicho de las ISLAS\n"
	.string "ALOLA son más grandes que en KANTO!$"

Alola_Melemele_camper_Text_0:
	.string "¡Viajé desde KANTO para ver la forma\n"
	.string "regional de mi gato favorito: MEOWTH!$"

Alola_Melemele_Picnicker_Text_0:
	.string "¡Estas ISLAS están repletas de\n"
	.string "POKéMON únicos!\p"
	.string "¡Tengo que comprar un cargamento de\n"
	.string "POKé BALLS para atraparlos a todos!$"

MelemeleIsle_EventScript_Metacaballero::
	lock
	faceplayer
	setspeaker SP_NAME_METACABALLERO
	msgbox MelemeleIsle_Text_MetacaballeroIntro, MSGBOX_DEFAULT
	pokemart MelemeleIsle_MetacaballeroShop
	setspeaker SP_NAME_METACABALLERO
	msgbox MelemeleIsle_Text_MetacaballeroFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
MelemeleIsle_MetacaballeroShop:
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FAST_BALL
	.2byte ITEM_HEAVY_BALL
	pokemartlistend

MelemeleIsle_Text_MetacaballeroIntro:
	.string "Brisa marina, cero estrés y máxima\n"
	.string "eficiencia de campo.\p"
	.string "Qué agustito se está en esta playa\n"
	.string "inspeccionando la fauna insular.\p"
	.string "He traído BALLS de diseño avanzado\n"
	.string "y artesanales para ratios complejos.\p"
	.string "Pesca, peso, amistad y especies\n"
	.string "registradas. ¿Compras?$"

MelemeleIsle_Text_MetacaballeroFarewell:
	.string "Planifica cada captura.\n"
	.string "El azar es el enemigo del meta.$"

