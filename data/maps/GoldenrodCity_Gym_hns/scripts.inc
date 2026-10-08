GoldenrodCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_Gym_OnTransition
	.byte 0

GoldenrodCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_HideManolin
	clearflag FLAG_HIDE_MANOLIN_TRIGAL
	end

GoldenrodCity_Gym_HideManolin::
	setflag FLAG_HIDE_MANOLIN_TRIGAL
	end
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	call Common_EventScript_AwardRandomMint
	giveitem ITEM_FESTIVAL_TICKET, 1
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD TRIGAL$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD TRIGAL\p"
	.string "ENTRENADORES CERTIFICADOS POR\nBLANCA:\l"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "¡Hola! ¡Soy BLANCA!\p"
    .string "Todo el mundo estaba con los\nPOKéMON,\l"
    .string "¡así que me animé yo también!\p"
    .string "¡Es que los POKéMON son monísimos!\p"
    .string "¿Quieres combatir? ¡Te advierto que\n"
    .string "se me da genial!$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Buaaa…\p"
    .string "¡Buaaaaaah! ¡Qué mala persona eres!\p"
    .string "¡No hacía falta ponerse tan serio!\n"
    .string "¡Eres… un abusón!$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "¡Buaaaaaah!\p"
    .string "¡Buaaaaaah!\p"
    .string "…Snif, hip… ¡Mala persona!$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "…Snif…\p"
    .string "¿Qué? ¿Qué quieres? ¿Una MEDALLA?\p"
    .string "Ah, claro. Se me había olvidado.\n"
    .string "Toma la MEDALLA PLANICIE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "¡{PLAYER} recibió la\n"
    .string "MEDALLA PLANICIE!$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "La MEDALLA PLANICIE permite a tus\n"
    .string "POKéMON usar FUERZA fuera del\lcombate.\p"
    .string "También aumenta la DEFENSA de tus\n"
	.string "POKéMON.\p"
    .string "¡Ah, quédate con esto también!$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "¡Es ATRACCIÓN! Aprovecha al\n"
    .string "máximo el encanto de un POKéMON.\p"
    .string "¿A que le va como anillo al dedo a\n"
    .string "una monada como yo?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "¡Ay, qué a gusto me he quedado\n"
    .string "después de llorar!$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "¡Hola! ¡Si eres tú!\p"
    .string "¡Hala, ya eres CAMPEÓN DE JOHTO!\p"
    .string "¡Eres increíble de verdad!\p"
    .string "Quiero ver cuánto has mejorado.\p"
    .string "¿Echamos la revancha?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "¡Buaaaaaah!\p"
    .string "¡Buaaaaaah!\p"
    .string "…Snif, hip… ¡Mala persona!$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "No te dejes engañar por la carita\n"
    .string "mona de mis POKéMON.\p"
    .string "¡Te van a dar una paliza!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Vaya… Pensé que no aguantarías ni\n"
    .string "un asalto…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "¿Mis POKéMON pensarán que soy tan\n"
    .string "mona como ellos?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "Prefiero los POKéMON monos a los\n"
    .string "fuertes.\p"
    .string "¡Pero es que los míos son monos y\n"
    .string "fuertes a la vez!$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "¡Ay, no, no, no!$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "Intento vencer a BLANCA, pero…\n"
    .string "es deprimente.\p"
    .string "¡Aunque no me rindo! ¡Entrenaré más\n"
    .string "para la próxima!$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Ay, madre. Has hecho llorar a\n"
    .string "BLANCA.\p"
    .string "Tranqui, ya se le pasará.\n"
    .string "Siempre le da la llorera cuando\l"
    .string "pierde.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "¡Ay, qué entrenadorcillo tan\nmono!\p"
    .string "Me caes bien, ¡pero no me voy a\n"
    .string "contener!$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "A ver… ¡Uy! ¿Ya se ha acabado?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "¡Guau, se te da de lujo para\nhaberme\l"
    .string "ganado! ¡Sigue así!$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "¡Ponte las pilas o te barro del\n"
    .string "campo de batalla!$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "¡No! ¡Ay, MEOWTH, perdóname!$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "Le enseñé a MEOWTH ataques para\n"
    .string "hacer frente a cualquier tipo…$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "¡Aupa, futuro CAMPEÓN!\p"
    .string "En este GIMNASIO manda BLANCA, la\n"
    .string "maestra del tipo NORMAL.\p"
    .string "No te confíes por el aspecto de su\n"
    .string "equipo.\p"
    .string "Varios POKéMON de aquí pertenecen\n"
    .string "al recién descubierto tipo HADA.\p"
    .string "Date una vuelta por la RUTA 34 si\n"
    .string "necesitas tipos LUCHA o VENENO.$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "¿Has ganado? ¡Bien hecho! Yo estaba\n"
    .string "aquí embobado con las chicas.$"

GoldenrodCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_TRIGAL, GoldenrodCity_Gym_EventScript_Manolin_AfterItem
	msgbox GoldenrodCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_TRIGAL, GoldenrodCity_Gym_EventScript_Manolin_ChooseItem
	msgbox GoldenrodCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_SUPER_POTION
	setflag FLAG_MANOLIN_HEAL_TRIGAL
	msgbox GoldenrodCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

GoldenrodCity_Gym_EventScript_Manolin_ChooseItem::
	msgbox GoldenrodCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_TRIGAL, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_Gym_EventScript_Manolin_GiveFocusSash
	case 1, GoldenrodCity_Gym_EventScript_Manolin_GiveRockyHelmet
	case MULTI_B_PRESSED, GoldenrodCity_Gym_EventScript_Manolin_NoChoice
	end

GoldenrodCity_Gym_EventScript_Manolin_GiveFocusSash::
	giveitem ITEM_FOCUS_SASH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_TRIGAL
	msgbox GoldenrodCity_Gym_Text_Manolin_FocusSashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Manolin_GiveRockyHelmet::
	giveitem ITEM_ROCKY_HELMET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_TRIGAL
	msgbox GoldenrodCity_Gym_Text_Manolin_RockyHelmetExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Manolin_NoChoice::
	msgbox GoldenrodCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Manolin_AfterItem::
	msgbox GoldenrodCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_Manolin_Intro:
	.string "¡Hombre, mi gente! ¡Sigues vivo!\p"
	.string "Con la de wipes que causa esta\n"
	.string "zona me alegra verte en pie.\p"
	.string "Oye, ¿este no era el boss de roca?\n"
	.string "Ah, no… ¡que aquí está BLANCA!\l"
	.string "La pesadilla de cualquier locke.$"

GoldenrodCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Pega un frenazo, socio!\n"
	.string "¡Llevas a la party reventada!\p"
	.string "Como entres así al pull, la vaca\n"
	.string "te hace un instakill que flipas.\l"
	.string "¡Déjame tirar una cura tocha!$"

GoldenrodCity_Gym_Text_Manolin_Healed:
	.string "¡Equipo listo para tanquear!\p"
	.string "Toma una Superpoción por si te\n"
	.string "toca curar en medio del burst.$"

GoldenrodCity_Gym_Text_Manolin_OfferChoices:
	.string "El Miltank de BLANCA pega como un\n"
	.string "boss de míticas con Desenrollar.\p"
	.string "¿Prefieres aguantar el one-shot\n"
	.string "o que la vaca se coma daño cada\l"
	.string "vez que te meta cuerpo a cuerpo?$"

GoldenrodCity_Gym_Text_Manolin_FocusSashExplain:
	.string "¡BANDA FOCUS! Si estás a tope de\n"
	.string "vida, aguantas a 1 PS cualquier\l"
	.string "ataque que fuera a debilitarte.\p"
	.string "¡El seguro definitivo anti-wipe!$"

GoldenrodCity_Gym_Text_Manolin_RockyHelmetExplain:
	.string "¡CASCO DENTADO! Cada vez que la\n"
	.string "vaca o sus bichos hagan contacto,\l"
	.string "¡se llevan un castigo salvaje!$"

GoldenrodCity_Gym_Text_Manolin_NoChoice:
	.string "Piénsatelo bien, mi gente, que\n"
	.string "esta vaca ha mandado a muchos al\l"
	.string "cementerio de partidas.$"

GoldenrodCity_Gym_Text_Manolin_AfterItem:
	.string "¡A por todas! ¡Frena ese\n"
	.string "Desenrollar antes de que cargue!$"
