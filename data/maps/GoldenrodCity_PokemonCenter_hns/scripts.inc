GoldenrodCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_PokemonCenter_hns_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodCity_PokemonCenter_hns_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY_HNS
	end

GoldenrodCity_PokemonCenter_hns_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	.2byte 0

GoldenrodCity_PokemonCenter_hns_OnWarp_Nop::
	end

GoldenrodCity_PokemonCenter_hns_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	.2byte 0

GoldenrodCity_PokemonCenter_hns_ExitLinkRoom::
	lockall
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	erasebox 0, 0, 29, 19
	releaseall
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc::
	lock
	faceplayer
	copyvar VAR_0x8007, VAR_LAST_TALKED
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_LINK_SERVICES_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_ChooseTrade
	case 1, GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseTrade::
	helpwindow HELP_TRADE_WINDOW
	delay 30
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	special SaveGymTokenTransaction
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom::
	setvar VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_TRADE_CENTER_HNS, 5, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseBattle::
	helpwindow HELP_TRADE_WINDOW
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_BATTLE_MODE_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_SingleBattle
	case 1, GoldenrodCity_PokemonCenter_EventScript_DoubleBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_SingleBattle::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_DoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	end

GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum::
	special SaveGymTokenTransaction
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

GoldenrodCity_PokemonCenter_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_BATTLE_COLOSSEUM_2P_HNS, 6, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline::
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End::
	release
	end

GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro:
	.string "RINCÓN DE CONEXIÓN\p"
	.string "ELIGE EL TIPO DE CONEXIÓN.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode:
	.string "ELIGE EL TIPO DE COMBATE.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye:
	.string "HASTA PRONTO.$"

GoldenrodCity_PokemonCenter_EventScript_LinkExplainerNpc::
	msgbox GoldenrodCity_PokemonCenter_Text_LinkExplainer, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_Text_LinkExplainer:
	.string "Esta máquina permite intercambiar\n"
	.string "o combatir con jugadores cercanos.\p"
	.string "¡La tecnología es increíble!$"

GoldenrodCity_PokemonCenter_EventScript_GymTokenClerk::
	lock
	faceplayer
	special GetGymTokenCount
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenNone

GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu::
	multichoice 0, 0, MULTI_GYM_TOKEN_SERVICES_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenRetry
	case 1, GoldenrodCity_PokemonCenter_EventScript_GymTokenTradeConfirm
	case 2, GoldenrodCity_PokemonCenter_EventScript_GymTokenReviveConfirm
	case 3, GoldenrodCity_PokemonCenter_EventScript_GymTokenExplain
	case 4, GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd

GoldenrodCity_PokemonCenter_EventScript_GymTokenNone::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenNone, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd

GoldenrodCity_PokemonCenter_EventScript_GymTokenRetry::
	special BuildGymTokenRetryMenu
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenNoRetry
	message GoldenrodCity_PokemonCenter_Text_GymTokenChooseRoute
	waitmessage
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu
	goto_if_eq VAR_RESULT, 112, GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu @ NUZLOCKE_NUM_ZONES
	copyvar VAR_0x8004, VAR_RESULT
	special SelectGymTokenRetry
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenNoRetry
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenRetryZone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu
	special UseSelectedGymTokenRetry
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenNoRetry
	special SaveGymTokenTransaction
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenRetryDone, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd

GoldenrodCity_PokemonCenter_EventScript_GymTokenNoRetry::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenNoRetry, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu

GoldenrodCity_PokemonCenter_EventScript_GymTokenTradeConfirm::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenTrade

GoldenrodCity_PokemonCenter_EventScript_GymTokenTrade::
	chooseboxmon SELECT_PC_MON_GYM_TOKEN_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd
	special UseGymTokenTrade
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenTradeFailed
	special DoInGameTradeScene
	waitstate
	special FinishGymTokenTrade
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenTradeFailed
	call Common_EventScript_SaveGame
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenTradeDone, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd

GoldenrodCity_PokemonCenter_EventScript_GymTokenTradeFailed::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenTradeFailed, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu

GoldenrodCity_PokemonCenter_EventScript_GymTokenReviveConfirm::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenRevive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenRevive

GoldenrodCity_PokemonCenter_EventScript_GymTokenRevive::
	chooseboxmon SELECT_PC_MON_GYM_TOKEN_REVIVE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd
	special UseGymTokenRevive
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_GymTokenReviveFailed
	call Common_EventScript_SaveGame
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenReviveDone, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd

GoldenrodCity_PokemonCenter_EventScript_GymTokenReviveFailed::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenReviveFailed, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu

GoldenrodCity_PokemonCenter_EventScript_GymTokenExplain::
	msgbox GoldenrodCity_PokemonCenter_Text_GymTokenExplain, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_GymTokenMenu

GoldenrodCity_PokemonCenter_EventScript_GymTokenEnd::
	release
	end

GoldenrodCity_PokemonCenter_Text_GymTokenIntro:
	.string "Soy el encargado de las\n"
	.string "FICHAS GIMNASIO.\p"
	.string "Ahora tienes {STR_VAR_1}.$"

GoldenrodCity_PokemonCenter_Text_GymTokenNone:
	.string "Obtendrás una al superar un\n"
	.string "GIMNASIO en un reto NUZLOCKE.$"

GoldenrodCity_PokemonCenter_Text_GymTokenRetry:
	.string "¿Canjear 1 FICHA por recuperar\n"
	.string "el intento fallido más antiguo?$"

GoldenrodCity_PokemonCenter_Text_GymTokenRetryZone:
	.string "¿Recuperar el intento de\n"
	.string "{STR_VAR_2} por 1 FICHA?$"

GoldenrodCity_PokemonCenter_Text_GymTokenChooseRoute:
	.string "Elige la ruta cuyo intento\n"
	.string "quieres recuperar.$"

GoldenrodCity_PokemonCenter_Text_GymTokenTrade:
	.string "¿Prefieres un intercambio\n"
	.string "misterioso por 1 FICHA?$"

GoldenrodCity_PokemonCenter_Text_GymTokenRevive:
	.string "¿Resucitar un POKéMON por\n"
	.string "2 FICHAS?$"

GoldenrodCity_PokemonCenter_Text_GymTokenRetryDone:
	.string "He recuperado ese intento.\n"
	.string "¡Aprovéchalo bien!$"

GoldenrodCity_PokemonCenter_Text_GymTokenNoRetry:
	.string "No tienes intentos fallidos\n"
	.string "que se puedan recuperar.$"

GoldenrodCity_PokemonCenter_Text_GymTokenTradeDone:
	.string "El intercambio se completó.\n"
	.string "¡Has recibido a {STR_VAR_3}!$"

GoldenrodCity_PokemonCenter_Text_GymTokenTradeFailed:
	.string "No puedo realizarlo. Solo se\n"
	.string "permite uno y sin objeto equipado.$"

GoldenrodCity_PokemonCenter_Text_GymTokenReviveDone:
	.string "Tu POKéMON vuelve a estar sano.\n"
	.string "No podrá resucitar otra vez.$"

GoldenrodCity_PokemonCenter_Text_GymTokenReviveFailed:
	.string "Necesitas 2 FICHAS y un POKéMON\n"
	.string "debilitado que no haya vuelto.$"

GoldenrodCity_PokemonCenter_Text_GymTokenExplain:
	.string "Cada medalla da una FICHA.\p"
	.string "Sirven para recuperar capturas,\n"
	.string "intercambiar o resucitar.\p"
	.string "Puedes guardar un máximo de 3.$"

GymToken_EventScript_Award::
	special AwardGymToken
	goto_if_eq VAR_RESULT, 1, GymToken_EventScript_AwardReceived
	goto_if_eq VAR_RESULT, 2, GymToken_EventScript_AwardFull
	return

GymToken_EventScript_AwardReceived::
	msgbox GymToken_Text_AwardReceived, MSGBOX_DEFAULT
	return

GymToken_EventScript_AwardFull::
	msgbox GymToken_Text_AwardFull, MSGBOX_DEFAULT
	return

GymToken_Text_AwardReceived:
	.string "¡Has recibido una FICHA GIMNASIO!\n"
	.string "Puedes canjearla en un CENTRO.$"

GymToken_Text_AwardFull:
	.string "Ya tienes 3 FICHAS GIMNASIO.\n"
	.string "No puedes guardar esta recompensa.$"

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "¡Me fascina la vida en la gran\nciudad!\l"
    .string "Me mudé aquí cuando era una joven\l"
    .string "entrenadora como tú.$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "Este CENTRO POKéMON es especial.\n"
    .string "¡El tejado está hecho de oro!$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "Le dije a mi hermano que el techo\les\l"
    .string "de oro puro. ¡Ese inocentón se\ltraga\l"
	.string "lo que sea!$"

GoldenrodCity_PokemonCenter_LassText:
    .string "Un POKéMON de mayor nivel no tiene\n"
    .string "la victoria asegurada.\p"
    .string "Las desventajas de tipo pueden\ndarle\l"
    .string "la vuelta al combate.\p"
    .string "No existe ningún POKéMON que sea el\n"
    .string "rey indiscutible.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "Tú eres {PLAYER}, ¿verdad?\p"
    .string "¡Enhorabuena!\p"
    .string "Como regalo especial, han enviado\n"
    .string "una GS BALL solo para ti.\p"
    .string "¡Acéptala, por favor!$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "¡Esperamos volver a verte!$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "¡Cielo santo, qué BOLSA tan\npesada!\p"
    .string "¡Oye! ¿Por casualidad tienes una\n"
    .string "CARTA EÓN?\p"
    .string "Mi hija está loca por conseguir\nuna.\p"
    .string "¿Podrías regalarme una, por favor?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "¿Entregar una CARTA EÓN?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "¡Ay, qué encanto de criatura!\n"
    .string "¡Muchísimas gracias!\p"
    .string "¡Toma esto en agradecimiento!$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "¡Mi hija se va a poner\ncontentísima!$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "¿No tienes ninguna? Vaya, qué pena.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "Bueno… Otra vez será entonces.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER} entregó la CARTA EÓN.$"
