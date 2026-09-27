LakeOfRage_House2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_House2_OnTransition
	.byte 0

LakeOfRage_House2_OnTransition::
	goto_if_unset FLAG_RECEIVED_MEGA_TEST_KIT, LakeOfRage_House2_HideElPiedras
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, LakeOfRage_House2_HideElPiedras
	clearflag FLAG_HIDE_LAKE_OF_RAGE_EL_PIEDRAS
	end

LakeOfRage_House2_HideElPiedras::
	setflag FLAG_HIDE_LAKE_OF_RAGE_EL_PIEDRAS
	end

LakeOfRage_House2_EventScript_ElPiedras::
	lock
	faceplayer
	msgbox LakeOfRage_House2_Text_ElPiedras, MSGBOX_DEFAULT
	setflag FLAG_TALKED_EL_PIEDRAS_LAKE_OF_RAGE
	closemessage
	release
	end

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
	.string "El LAGO DE LA FURIA es un cráter\ncreado por GYARADOS enfurecidos.\pEl cráter se llenó de lluvia y así\nse formó el LAGO.\pEs la historia que heredé del\ntatarabuelo de mi abuelo.\pAntes se pescaban MAGIKARP llenos\nde vigor, pero ahora…\pNo entiendo qué está ocurriendo.$"
LakeOfRage_House2_Text_MenInBlack:
	.string "El LAGO no es el mismo desde que\nllegaron esos hombres de negro.$"
LakeOfRage_House2_Text_LastMon:
	.string "¡No dejaré que me des tu último\nPOKéMON!$"
LakeOfRage_House2_Text_WorldsLargest:
	.string "El LAGO DE LA FURIA está en calma.\pLos MAGIKARP han regresado.\pQuizá cumpla mi sueño de tener el\nMAGIKARP más grande del mundo.\pDe hecho… Te pagaré 2.000¥ por cada\nMAGIKARP que me des, y 100.000¥\lsi es ENORME.$"
LakeOfRage_House2_Text_ForMe:
	.string "Y bien... ¿Tienes algún MAGIKARP\npara mí?$"
LakeOfRage_House2_Text_HaveMagikarp:
	.string "¡Ah, tienes un MAGIKARP! Veamos\ncuánto mide esa criatura.$"
LakeOfRage_House2_Text_BigPayout:
	.string "¡Hala! ¡Este ejemplar es magnífico!\p¡Me quito el sombrero ante ti!\pAquí tienes algo por las\nmolestias.$"
LakeOfRage_House2_Text_Bonus:
	.string "Lo importante es el récord mundial.\p¡Considéralo una bonificación!$"
LakeOfRage_House2_Text_TooShort:
	.string "¡Hala! Este ejemplar es magnífico…\pOjalá pudiera decirlo, pero ya he\nvisto uno más grande.\pSupongo que algo vale.$"
LakeOfRage_House2_Text_NotMagikarp:
	.string "¿Cómo? ¡Eso no es un MAGIKARP!$"
LakeOfRage_House2_Text_Refused:
	.string "Vaya… ¿No tienes ninguno digno de\nenseñarme? Quizá la próxima vez.$"

LakeOfRage_House2_Text_ElPiedras:
	.string "¡Hermano! ¡Cierra la puerta que\n"
	.string "se me enfrían los cheetos!\p"
	.string "¿Has visto al tipo pelirrojo fuera\n"
	.string "activar una mega-transformación\l"
	.string "digna de anime shonen?\p"
	.string "¡Esas piedras de mega-evolución\n"
	.string "existen de verdad! ¡El mercado no\l"
	.string "estaba inflado, socio!\p"
	.string "Los del Team Rocket salieron por\n"
	.string "patas dejando suministros.\p"
	.string "En cuanto los barras de la Torre\n"
	.string "Radio de Trigal, ¡voy a reventar\l"
	.string "el monopolio de las tiendas!$"
