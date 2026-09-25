AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Todos los SLOWPOKE del pueblo han\n"
	.string "desaparecido sin dejar rastro.\p"
	.string "Quizá el protector del bosque esté\n"
	.string "enfadado con nosotros…\p"
	.string "Puede ser un mal presagio.\n"
	.string "Será mejor quedarnos resguardados.$"

CharcoalKiln_Text_Boss2:
	.string "Los SLOWPOKE han vuelto…$"

CharcoalKiln_Text_Boss3:
	.string "Los SLOWPOKE han vuelto…\p"
	.string "¡Pero mi APRENDIZ aún no ha vuelto\n"
	.string "del ENCINAR!\p"
	.string "¿Dónde se habrá metido ese vago?$"

CharcoalKiln_Text_Boss4:
	.string "¿Ahuyentaste al TEAM ROCKET y te\n"
	.string "adentraste a solas en el ENCINAR?\p"
	.string "¡Vaya agallas! Me gusta tu estilo.\n"
	.string "¡Ven a entrenar con nosotros!$"

CharcoalKiln_Text_Apprentice1:
	.string "¿Dónde se habrán metido\n"
	.string "los SLOWPOKE?\p"
	.string "¿Estarán jugando en algún sitio?$"

CharcoalKiln_Text_Apprentice2:
	.string "¡Los SLOWPOKE han vuelto!$"

CharcoalKiln_Text_Apprentice3:
	.string "Perdón, ¡se me olvidó darte las\n"
	.string "gracias por tu ayuda!\p"
	.string "Toma este CARBÓN que yo mismo hice.\p"
	.string "A los POKéMON de tipo FUEGO les\n"
	.string "encantará llevarlo equipado.$"

CharcoalKiln_Text_Apprentice4:
	.string "Los SLOWPOKE regresaron y además\n"
	.string "encontraste a FARFETCH'D.\p"
	.string "¡Eres el entrenador más enrollado!$"

CharcoalKiln_Text_Farfetchd:
	.string "FARFETCH'D: ¡Kwaa!$"
