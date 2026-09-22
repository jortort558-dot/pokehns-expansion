.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "¿Qué haces aquí?\p"
	.string "¡Mi ayudante sigue esperándote\n"
	.string "en CIUDAD MALVA!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1_Register, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_RegisteredElm, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "¡Mejor no tocar!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM: ¡{PLAYER}! ¡Ya estás aquí!\p"
	.string "Quería pedirte un favor.\p"
	.string "Ahora mismo estoy haciendo\n"
	.string "un estudio sobre POKéMON. Me\l"
	.string "gustaría que me ayudaras\l"
	.string "con él, {PLAYER}.\p"
	.string "Verás…\p"
	.string "Estoy escribiendo un trabajo\n"
	.string "para presentarlo en un congreso.\p"
	.string "Pero todavía hay cosas\n"
	.string "que no logro comprender.\p"
	.string "¡Así que…!\p"
	.string "Quiero que cuides de un\n"
	.string "POKéMON que capturé hace poco.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "¡Gracias, {PLAYER}!\n"
	.string "¡Eres de gran ayuda!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Pero… ¡Por favor, necesito tu\nayuda!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Cuando anuncie mis hallazgos,\n"
	.string "estoy seguro de que profundizaremos\p"
	.string "en los muchos misterios de los\n"
	.string "POKéMON.\p"
	.string "¡Puedes contar con ello!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "¡Oh, mira! ¡He recibido un e-mail!\p"
	.string "… … … … … … … …\n"
	.string "Hm… Ajá…\p"
	.string "De acuerdo…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Oye, escucha.\p"
	.string "Tengo un conocido llamado\n"
	.string "SR. POKéMON.\p"
	.string "Siempre encuentra cosas raras y\n"
	.string "presume de sus hallazgos.\p"
	.string "Acaba de mandarme un correo\n"
	.string "diciendo que esta vez\l"
	.string "va en serio.\p"
	.string "Es interesante, pero estamos\n"
	.string "ocupados con el estudio…\p"
	.string "¡Espera!\n"
	.string "¡Ya lo tengo!\p"
	.string "{PLAYER}, ¿puedes ir tú\n"
	.string "en nuestro lugar?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Quiero que cries a uno de los\nPOKéMON\l"
	.string "que están en estas BALLS.\p"
	.string "¡Serás el primer compañero de ese\n"
	.string "POKéMON, {PLAYER}!\p"
	.string "Adelante. ¡Elige uno!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ELM: ¡Espera! ¿A dónde vas?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ELM: ¿Te quedarás con {STR_VAR_1},\n"
	.string "el POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ELM: ¿Quieres a {STR_VAR_1},\n"
	.string "el POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ELM: ¿Así que te gusta {STR_VAR_1},\n"
	.string "el POKéMON {STR_VAR_2}?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ELM: Piénsalo con cuidado.\p"
	.string "Tu compañero es importante.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ELM: ¡Creo que también es un gran\n"
	.string "POKéMON!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "¡{PLAYER} recibió a {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "¿Quieres ponerle un mote a tu\n"
	.string "{STR_VAR_1}?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "El SR. POKéMON vive algo más\n"
	.string "allá de CEREZO, en la\l"
	.string "ciudad siguiente.\p"
	.string "El camino es casi recto,\n"
	.string "no tiene pérdida.\p"
	.string "Por si acaso, tienes mi\n"
	.string "número. ¡Llámame si\l"
	.string "ocurre cualquier cosa!$"

NewBarkTown_Lab_Text_ElmDirections1_Register:
	.string "El SR. POKéMON vive algo más\n"
	.string "allá de CEREZO, en la ciudad\l"
	.string "siguiente.\p"
	.string "Es un camino casi directo,\n"
	.string "no tiene pérdida.\p"
	.string "Pero por si acaso, aquí tienes mi\n"
	.string "número de teléfono. ¡Llámame si\l"
	.string "pasa algo!$"

NewBarkTown_Lab_Text_RegisteredElm:
	.string "Registrado el PROF. ELM\n"
	.string "en el POKéGEAR.$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "¡Si aparece un POKéMON salvaje,\n"
	.string "deja que tu POKéMON luche!$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Si aparece un POKéMON salvaje,\n"
	.string "¡deja que el tuyo luche!\p"
	.string "Si resulta herido, cúralo\n"
	.string "con la máquina de mi derecha\l"
	.string "o en un CENTRO POKéMON.\p"
	.string "¡Cuento contigo!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} consiguió el número de\n"
	.string "teléfono de ELM.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "El SR. POKéMON viaja a todas partes\n"
	.string "y encuentra rarezas.\p"
	.string "Lástima que sean solo raras y no\n"
	.string "muy útiles…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Contiene un POKéMON capturado\n"
	.string "por el PROF. ELM.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ELM: {PLAYER}, esto es terrible…\p"
	.string "Por cierto, ¿cuál era el gran\n"
	.string "descubrimiento del SR. POKéMON?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} le entregó el HUEVO\n"
	.string "MISTERIOSO al PROF. ELM.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ELM: ¿Esto?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Pero… ¿es un HUEVO POKéMON?\p"
	.string "¡Si lo es, será todo\n"
	.string "un descubrimiento!\p"
	.string "ELM: ¡¿Cómo?!\p"
	.string "¿El PROF. OAK te dio una POKéDEX?\p"
	.string "{PLAYER}, ¿es verdad?\n"
	.string "¡E-es increíble!\p"
	.string "Sabe reconocer muy bien\n"
	.string "el talento de un entrenador.\p"
	.string "Vaya, {PLAYER}. Quizá puedas\n"
	.string "llegar a ser CAMPEÓN.\p"
	.string "Además, pareces llevarte muy\n"
	.string "bien con los POKéMON.\p"
	.string "Deberías aceptar el reto\n"
	.string "de los GIMNASIOS.\p"
	.string "El más cercano está en\n"
	.string "CIUDAD MALVA.\p"
	.string "…{PLAYER}. Llegar a CAMPEÓN\n"
	.string "será un camino muy largo.\p"
	.string "Antes de irte, no olvides\n"
	.string "hablar con tu madre.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ELM: ¡No te rindas!\n"
	.string "¡Te llamaré si me entero de algo\lsobre\l"
	.string "ese HUEVO!$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ELM: ¿{PLAYER}? ¿No viste\n"
	.string "a mi ayudante?\p"
	.string "Debía llevarte el HUEVO en\n"
	.string "el CENTRO POKéMON\l"
	.string "de CIUDAD MALVA.\p"
	.string "Quizá os cruzasteis.\n"
	.string "Intenta encontrarlo allí.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ELM: Oye, ¿ha cambiado en algo ese\n"
	.string "HUEVO?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}? Pensé que el HUEVO había\n"
	.string "eclosionado.\p"
	.string "¿Dónde está el POKéMON?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ELM: ¡{PLAYER}, te ves genial!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "¡¿Qué?! ¡¿Ese POKéMON?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "¡El HUEVO eclosionó! Así que los\n"
	.string "POKéMON nacen de HUEVOS…\p"
	.string "Bueno, tal vez no todos los\nPOKéMON.\p"
	.string "Vaya, aún queda mucho por\ninvestigar.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "¡Gracias, {PLAYER}! Nos ayudas\n"
	.string "a desentrañar los misterios\l"
	.string "POKéMON.\p"
	.string "Quiero que tengas esto como muestra\n"
	.string "de nuestro agradecimiento.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "Es una PIEDRAETERNA.\p"
	.string "Algunos POKéMON evolucionan\n"
	.string "al alcanzar cierto nivel.\p"
	.string "Si llevan la PIEDRAETERNA,\n"
	.string "no evolucionarán.\p"
	.string "Dásela a quien no quieras\n"
	.string "que evolucione.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM: {PLAYER}, te llamaré si surge\ncualquier\l"
	.string "cosa.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "… Suspiro… Ese POKéMON robado.\p"
	.string "Me pregunto cómo le irá.\p"
	.string "Dicen que un POKéMON criado por una\n"
	.string "mala persona se vuelve malo\ltambién.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM: ¡Hola, {PLAYER}!\p"
	.string "¡Gracias a ti, mi investigación va\ngenial!\p"
	.string "Toma esto como muestra de mi\n"
	.string "agradecimiento.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "¡La MASTER BALL es la mejor!\p"
	.string "¡Es la BALL definitiva! Atrapará a\n"
	.string "cualquier POKéMON sin fallar.\p"
	.string "Solo se otorga a investigadores\nPOKéMON\l"
	.string "reconocidos.\p"
	.string "¡Creo que tú le darás mucho mejor\nuso\l"
	.string "que yo, {PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Por cierto...\n"
	.string "Un grupo de hermosas CHICAS KIMONO\lte\l"
	.string "estaban buscando.\p"
	.string "Me dijeron que te están esperando\nen el\l"
	.string "TEATRO DE DANZA de CIUDAD IRIS.\p"
	.string "Sé que has pasado por muchas cosas\ndesde\l"
	.string "que ese HUEVO te involucró en todo\lesto...\p"
	.string "Espero que salgas adelante.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF. ELM: Las CHICAS KIMONO te\nestán\l"
	.string "esperando en el TEATRO DE DANZA de\l"
	.string "CIUDAD IRIS.$"

NewBarkTown_Lab_Text_League:
	.string "PROF. ELM: Jajaja...\n"
	.string "¡Buen trabajo!\p"
	.string "Ese HUEVO raro te trajo bastantes\n"
	.string "problemas, ¿eh?\p"
	.string "¿Las CHICAS KIMONO dijeron algo\nsobre mí?\p"
	.string "Yo no tengo nada que ver con eso.\p"
	.string "Tú tomaste tu decisión y seguiste\nadelante.\p"
	.string "Habiendo hecho tanto, ¡deberías\npoder\l"
	.string "enfrentarte a la LIGA ahora!\p"
	.string "¡Deberías poner rumbo a la MESETA\nAÑIL!\p"
	.string "¿Sabes cómo llegar?\n"
	.string "Sigue la RUTA 27 hasta la RUTA 26.\p"
	.string "Una vez allí, ¡ve recto al norte!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM: ¡{PLAYER}! ¡Ahí estás!\p"
	.string "Te llamé porque tengo algo para ti.\p"
	.string "¿Ves? Es un TICKET BARCO.\p"
	.string "Ahora puedes atrapar POKéMON en\nKANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "El barco sale de CIUDAD OLIVO.\p"
	.string "Pero eso ya lo sabías, {PLAYER}.\p"
	.string "Después de todo, has viajado por\ntodas\l"
	.string "partes con tus POKéMON.\p"
	.string "¡Dale mis recuerdos al PROF. OAK en\nKANTO!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "Es el HUEVO POKéMON que está siendo\n"
	.string "estudiado por el PROF. ELM.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, quiero darte esto para\n"
	.string "tu recado.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Solo somos tres, así que siempre\nestamos\l"
	.string "ocupados.$"

NewBarkTown_Lab_Text_AideSave:
	.string "¡No olvides guardar tu partida\n"
	.string "regularmente!\p"
	.string "¡Pulsa el botón START y luego\nGUARDA\l"
	.string "la partida!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Se oyó un ruido muy fuerte\n"
	.string "fuera…\p"
	.string "Al salir a mirar,\n"
	.string "alguien robó un POKéMON.\p"
	.string "¡No puedo creer que alguien\n"
	.string "hiciera algo así!\p"
	.string "…Ese POKéMON robado.\p"
	.string "Me pregunto cómo estará.\p"
	.string "Dicen que un POKéMON criado\n"
	.string "por alguien malo se vuelve malo.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "¡{PLAYER}!\p"
	.string "¡Usa esto en tu búsqueda para\ncompletar\l"
	.string "la POKéDEX!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Para añadir a tu POKéDEX, tienes\nque\l"
	.string "atrapar POKéMON.\p"
	.string "Lanza POKé BALLS a los POKéMON\nsalvajes\l"
	.string "para atraparlos.$"

NewBarkTown_Lab_Text_Officer1:
	.string "He oído que han robado un POKéMON\naquí…\p"
	.string "Estaba obteniendo información del\n"
	.string "PROF. ELM.\p"
	.string "Al parecer, era un varón joven con\n"
	.string "cabello largo y rojo…\p"
	.string "¿Qué?\p"
	.string "¿Luchaste contra un entrenador así?\p"
	.string "¿Por casualidad conseguiste su\nnombre?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "¡De acuerdo! ¿Así que se llamaba\n{RIVAL}?$"

NewBarkTown_Lab_Text_Officer2:
	.string "¡Gracias por ayudar en mi\ninvestigación!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "¡¿Seguro que no conseguiste su\nnombre?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "¡Ah, {PLAYER}!\p"
	.string "¿Qué tal va tu POKéDEX?\n"
	.string "Ahora estoy ocupado, ¡pero llámame\len otro\l"
	.string "momento y comprobaré tus avances!$"
