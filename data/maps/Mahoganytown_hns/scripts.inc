Mahoganytown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Mahoganytown_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Mahoganytown_OnFrame
	.byte 0

Mahoganytown_OnLoad::
	call_if_ge VAR_MAHOGANY_TOWN_STATE, 13, MahoganyTown_EventScript_FixTree
	end

MahoganyTown_EventScript_FixTree::
	setmetatile 18, 8, 0x378, FALSE
	setmetatile 19, 8, 0x379, FALSE
	end

MahoganyTown_EventScript_AipomFirst::
	lock
	faceplayer
	goto_if_set FLAG_MAHOGANY_SECRET_HOUSE_OPEN, MahoganyTown_EventScript_AipomAfter
	goto_if_ne VAR_MAHOGANY_AIPOM_KEY, 0, MahoganyTown_EventScript_AipomWrong
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	setvar VAR_MAHOGANY_AIPOM_KEY, 1
	msgbox MahoganyTown_Text_AipomFirst, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomSecond::
	lock
	faceplayer
	goto_if_set FLAG_MAHOGANY_SECRET_HOUSE_OPEN, MahoganyTown_EventScript_AipomAfter
	goto_if_ne VAR_MAHOGANY_AIPOM_KEY, 1, MahoganyTown_EventScript_AipomWrong
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	setvar VAR_MAHOGANY_AIPOM_KEY, 2
	msgbox MahoganyTown_Text_AipomSecond, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomThird::
	lock
	faceplayer
	goto_if_set FLAG_MAHOGANY_SECRET_HOUSE_OPEN, MahoganyTown_EventScript_AipomAfter
	goto_if_ne VAR_MAHOGANY_AIPOM_KEY, 2, MahoganyTown_EventScript_AipomWrong
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	setvar VAR_MAHOGANY_AIPOM_KEY, 3
	msgbox MahoganyTown_Text_AipomThird, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomFinal::
	lock
	faceplayer
	goto_if_set FLAG_MAHOGANY_SECRET_HOUSE_OPEN, MahoganyTown_EventScript_AipomAfter
	goto_if_eq VAR_MAHOGANY_AIPOM_KEY, 4, MahoganyTown_EventScript_AipomHasKey
	goto_if_ne VAR_MAHOGANY_AIPOM_KEY, 3, MahoganyTown_EventScript_AipomWrong
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	msgbox MahoganyTown_Text_AipomFinal, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_KEY
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_AipomBagFull
	setvar VAR_MAHOGANY_AIPOM_KEY, 4
	release
	end

MahoganyTown_EventScript_AipomBagFull::
	msgbox MahoganyTown_Text_AipomBagFull, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomHasKey::
	msgbox MahoganyTown_Text_AipomHasKey, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomWrong::
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	msgbox MahoganyTown_Text_AipomWrong, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_AipomAfter::
	playmoncry SPECIES_AIPOM, CRY_MODE_NORMAL
	msgbox MahoganyTown_Text_AipomAfter, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_SecretHouseDoor::
	lockall
	goto_if_set FLAG_MAHOGANY_SECRET_HOUSE_OPEN, MahoganyTown_EventScript_EnterSecretHouse
	checkitem ITEM_SECRET_KEY
	goto_if_eq VAR_RESULT, 0, MahoganyTown_EventScript_SecretHouseLocked
	msgbox MahoganyTown_Text_UseSecretKey, MSGBOX_DEFAULT
	removeitem ITEM_SECRET_KEY
	setflag FLAG_MAHOGANY_SECRET_HOUSE_OPEN
	setvar VAR_MAHOGANY_AIPOM_KEY, 5

MahoganyTown_EventScript_EnterSecretHouse::
	warp MAP_MAHOGANY_TOWN_HOUSE2_HNS, 0, 4, 7
	waitstate
	releaseall
	end

MahoganyTown_EventScript_SecretHouseLocked::
	msgbox MahoganyTown_Text_SecretHouseLocked, MSGBOX_DEFAULT
	releaseall
	end

MahoganyTown_Text_AipomFirst:
	.string "¡Ai, ai! Lleva una llave, pero\n"
	.string "se la lanza al AIPOM del pueblo.$"

MahoganyTown_Text_AipomSecond:
	.string "Atrapa la llave con la cola\n"
	.string "y la pasa hacia el gimnasio.$"

MahoganyTown_Text_AipomThird:
	.string "El AIPOM ríe y lanza la llave\n"
	.string "hacia la casa cerrada.$"

MahoganyTown_Text_AipomFinal:
	.string "El último AIPOM se rinde\n"
	.string "y te ofrece la llave.$"

MahoganyTown_Text_AipomBagFull:
	.string "Quiere darte la llave, pero\n"
	.string "no tienes espacio para ella.$"

MahoganyTown_Text_AipomHasKey:
	.string "El AIPOM señala satisfecho\n"
	.string "la casa de la esquina.$"

MahoganyTown_Text_AipomWrong:
	.string "Este AIPOM no tiene la llave.\n"
	.string "Mira hacia otro de la manada.$"

MahoganyTown_Text_AipomAfter:
	.string "¡Ai, aipom! La casa ya está\n"
	.string "abierta gracias a la manada.$"

MahoganyTown_Text_UseSecretKey:
	.string "La LLAVE SECRETA emite una\n"
	.string "señal y desaparece al usarse.$"

MahoganyTown_Text_SecretHouseLocked:
	.string "La puerta está cerrada.\n"
	.string "La cerradura tiene arañazos\l"
	.string "y varios pelos morados.$"

Mahoganytown_OnFrame::
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

Mahoganytown_EventScript_RocketTrigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall ElmPhoneRadioTowerRocketTakeoverText
	waitmessage
	setvar VAR_GOLDENROD_CITY_STATE, 6
	clearflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	setflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setvar VAR_MAHOGANY_TOWN_STATE, 16
	setvar VAR_TRIGGER_ELM_ROCKET_CALL, 2
	delay 10
	release
	end

MahoganyTown_EventScript_TownTrigger::
	clearflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_HIDE_MAHOGANY_TOWN_FATMAN
	clearflag FLAG_HIDE_MAHOGANY_ROCKETS
	clearflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	clearflag FLAG_GOT_BLACK_BELT
	clearflag FLAG_ROCKETHIDEOUT_SWITCH
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_GATE
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	clearflag FLAG_GOT_PASSWORD_FROM_ETO
	clearflag FLAG_GOT_PASSWORD_FROM_GRUNTF 
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE1 
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE2
	clearflag FLAG_HIDE_ROCKETHIDEOUT_ELECTRODE3 
	clearflag FLAG_GOT_HIDDEN_POWER
	clearflag FLAG_HIDE_ICE_PATH_KIMONO

	setflag FLAG_VISITED_MAHOGANY_TOWN
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	setflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	setflag FLAG_HIDE_MAHOGANY_COP
	setflag FLAG_HIDE_ROCKETHIDEOUT_ROCKETS
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT

	setvar VAR_ROCKET_HIDEOUT_STATUE_1, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_2, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_3, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_4, 0
	setvar VAR_ROCKET_HIDEOUT_STATUE_5, 0
	setvar VAR_ROCKET_PASSWORD, 0
	setvar VAR_ELECTRODES_FAINTED, 0
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 0
	setvar VAR_ICE_PATH_STATE, 0
	setvar VAR_ROUTE27_BAOBA_CALL, 0

	setvar VAR_MAHOGANY_TOWN_STATE, 1

	@blackthorn flagheap
	setvar VAR_BLACKTHORN_CITY_STATE, 1
    setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_SILVER
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_LANCE
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	clearflag FLAG_GOT_SPELL_TAG
	clearflag FLAG_GOT_DRATINI
	setvar VAR_BLACKTHORN_GYM_STATE, 0
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	end

MahoganyTown_EventScript_MerchantTrigger::
	lock
	turnobject LOCALID_MAHOGANY_MERCHANT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_MAHOGANY_MERCHANT, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 14, MahoganyTown_EventScript_WalkUp2
	call_if_eq VAR_TEMP_1, 13, MahoganyTown_EventScript_WalkUp1
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_WalkUp1::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant1
	waitmovement 0
	return

MahoganyTown_EventScript_WalkUp2::
	applymovement OBJ_EVENT_ID_PLAYER, MahoganyTown_Movement_PlayerMerchant2
	waitmovement 0
	return

MahoganyTown_EventScript_Merchant::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 17, MahoganyTown_EventScript_MerchantAfter
	showmoneybox 0, 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantTryOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantBroke
	removemoney 300
	updatemoneybox 0
	msgbox MahoganyTown_Text_RageCandyBarMerchantSavorIt, MSGBOX_DEFAULT
	giveitem ITEM_RAGE_CANDY_BAR
	hidemoneybox
	closemessage
	release
	end

MahoganyTown_EventScript_MerchantRefused::
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_MerchantBroke::
	msgbox MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	end

MahoganyTown_EventScript_NotEnoughSpace:
	msgbox MahoganyTown_Text_RageCandyBarMerchantRefused, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 30, MahoganyTown_EventScript_PushPlayer
	release
	return

MahoganyTown_EventScript_MerchantAfter::
	msgbox MahoganyTown_Text_RageCandyBarMerchantSoldOut, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_PushPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

MahoganyTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 6, MahoganyTown_EventScript_GrampsAfter
	msgbox MahoganyTown_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_GrampsAfter::
	msgbox MahoganyTown_Text_GrampsClearedRocketHideout, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Fisher::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Lass::
	lock
	faceplayer
	msgbox MahoganyTown_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_EventScript_Sign::
	lock
	msgbox MahoganyTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_CandybarSign::
	lock
	msgbox MahoganyTown_Text_RagecandybarSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_EventScript_GymSign::
	lock
	msgbox MahoganyTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

MahoganyTown_Movement_PlayerMerchant1:
	walk_up
	step_end

MahoganyTown_Movement_PlayerMerchant2:
	walk_up
	walk_up
	step_end

MahoganyTown_Text_RageCandyBarMerchantTryOne:
	.string "¡Hola, renacuajo!\pVeo que eres nuevo en PUEBLO CAOBA.\pEntonces debes probar un delicioso\nCARAMELO FURIA.\p¡Ahora puede ser tuyo por solo\n300¥! ¿Quieres uno?$"
MahoganyTown_Text_RageCandyBarMerchantSavorIt:
	.string "¡De perlas! ¡Saboréalo bien!$"
MahoganyTown_Text_RageCandyBarMerchantNotEnoughMoney:
	.string "No tienes bastante pasta encima.$"
MahoganyTown_Text_RageCandyBarMerchantRefused:
	.string "Pues nada, tú te lo pierdes…$"
MahoganyTown_Text_RageCandyBarMerchantSoldOut:
	.string "Los CARAMELOS FURIA se han agotado.\pEstoy recogiendo los bártulos.\nNo molestes, crío.$"
MahoganyTown_Text_Gramps:
	.string "¿Vas a ver a los GYARADOS\nenfurecidos del LAGO?$"
MahoganyTown_Text_GrampsClearedRocketHideout:
	.string "Los MAGIKARP han vuelto al\nLAGO DE LA FURIA.\pSerá una buena noticia para los\npescadores de allí.$"
MahoganyTown_Text_Fisher:
	.string "Ya que has llegado hasta aquí,\nhaz algo de turismo.\pVe al norte y visita ahora mismo\nel LAGO DE LA FURIA.$"
MahoganyTown_Text_Lass:
	.string "Pásate por la tienda de la abuela.\nVende cosas que nadie más tiene.$"
MahoganyTown_Text_Sign:
	.string "PUEBLO CAOBA\pBienvenidos al hogar ninja$"
MahoganyTown_Text_RagecandybarSign:
	.string "¡Si visitas PUEBLO CAOBA, prueba\nun CARAMELO FURIA!$"
MahoganyTown_Text_GymSign:
	.string "GIMNASIO POKéMON DE PUEBLO CAOBA\pLÍDER: FREDO\pEl maestro del crudo invierno$"
ElmPhoneRadioTowerRocketTakeoverText:
	.string "PROF. ELM: {PLAYER}, ¿cómo va todo?\pTe llamo porque ocurre algo extraño\ncon las emisiones de radio.\pEstaban hablando del TEAM ROCKET.\p{PLAYER}, ¿sabes algo sobre ello?\pQuizá haya vuelto el TEAM ROCKET.\nNo, no puede ser verdad.\pSiento molestarte.\n¡Cuídate!$"
