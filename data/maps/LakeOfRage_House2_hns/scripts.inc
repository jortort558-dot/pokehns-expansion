LakeOfRage_House2_hns_MapScripts::
	.byte 0

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
	.string "El LAGO DE LA FURIA es en realidad\nun\lcráter provocado por GYARADOS en\lcólera.\pEl cráter se llenó de lluvia y así\nnació\leste gran LAGO.\pEsa es la historia que me contaba\nel tatarabuelo\lde mi abuelo.\lAntes se pescaban MAGIKARP llenos\lde vigor,\lpero ahora… No comprendo qué\locurre.$"
LakeOfRage_House2_Text_MenInBlack:
	.string "El LAGO no ha vuelto a ser el mismo\ndesde\lque llegaron esos tipos vestidos de\lnegro.$"
LakeOfRage_House2_Text_LastMon:
	.string "¡No me hagas quitarte a tu último\nPOKéMON!$"
LakeOfRage_House2_Text_WorldsLargest:
	.string "El LAGO DE LA FURIA ha vuelto a la\ncalma.\lLos MAGIKARP han regresado.\l¡Por fin podré cumplir mi sueño de\ltener el\lMAGIKARP más grande de todo el\lmundo!\pDe hecho... ¡te pagaré 2.000¥ por\ncada MAGIKARP\lque me traigas, y 100.000¥ si es\lENORME!$"
LakeOfRage_House2_Text_ForMe:
	.string "Y bien... ¿Tienes algún MAGIKARP\npara mí?$"
LakeOfRage_House2_Text_HaveMagikarp:
	.string "¡Ah, tienes un MAGIKARP! Vamos a\nmedir el\ltamaño de esa criatura.$"
LakeOfRage_House2_Text_BigPayout:
	.string "¡Uala! ¡Este ejemplar es\nimpresionante!\l¡Me quito el sombrero ante ti!\lToma una recompensa por las\lmolestias.$"
LakeOfRage_House2_Text_Bonus:
	.string "Lo importante es el récord mundial.\n¡Tómate eso como una propina!$"
LakeOfRage_House2_Text_TooShort:
	.string "¡Vaya! Este ejemplar está bien...\nOjalá pudiera decir que es récord,\lpero he\lvisto otros más grandes antes.\lBueno, algo vale.$"
LakeOfRage_House2_Text_NotMagikarp:
	.string "¿Cómo? ¡Eso no es un MAGIKARP!$"
LakeOfRage_House2_Text_Refused:
	.string "Vaya… ¿No has pescado ninguno digno\nde\lmétodo? Bueno, para la próxima vez.$"
