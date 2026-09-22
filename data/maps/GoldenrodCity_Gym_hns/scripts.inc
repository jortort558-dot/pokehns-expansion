GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
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
	special AwardGymToken
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
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
    .string "¡Es ATRACCIÓN! Aprovecha al máximo\nel\l"
    .string "encanto de un POKéMON.\p"
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
    .string "Tranqui, ya se le pasará. Siempre\nle\l"
    .string "da la llorera cuando pierde.$"

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
