CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Hola…\n"
	.string "Bonito día,\p"
	.string "¿verdad? Se está\n"
	.string "tan bien…\p"
	.string "Podría hasta\n"
	.string "dormirme…\p"
	.string "Me llamo ERIKA.\n"
	.string "Soy la LÍDER\p"
	.string "del GIMNASIO de\n"
	.string "CIUDAD AZULONA.\p"
	.string "¿Cómo? ¿Vienes\n"
	.string "de JOHTO?\l"
	.string "¡Qué bien…!\p"
	.string "¡Oh! Lo siento,\n"
	.string "no me di cuenta\p"
	.string "de que querías\n"
	.string "desafiarme.\p"
	.string "Muy bien, pero no\n"
	.string "perderé.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: ¡Oh! Admito\n"
	.string "que he perdido…\p"
	.string "Eres realmente\n"
	.string "fuerte…\p"
	.string "Te daré la MEDALLA\n"
	.string "ARCOIRIS…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} recibió\n"
	.string "MEDALLA ARCOIRIS.$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "ERIKA: Ha sido un combate\n"
	.string "encantador.\p"
	.string "Me has inspirado. Por favor,\n"
	.string "acepta esta MT.$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "Es GIGADRENADO.\p"
	.string "Drena la mitad del daño causado\n"
	.string "para curar a tu POKéMON.\p"
	.string "Úsala si es de tu agrado…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA: La derrota\n"
	.string "deja mal sabor de\l"
	.string "boca…\p"
	.string "Pero saber que hay\n"
	.string "entrenadores más\p"
	.string "fuertes me anima a\n"
	.string "mejorar…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Ah, hola.\p"
	.string "¡Qué sorpresa, CAMPEÓN de KANTO!\p"
	.string "Me alegra mucho volver a verte.\p"
	.string "Tu viaje habrá sido emocionante.\p"
	.string "Hasta los campeones disfrutan\n"
	.string "de un desafío.\p"
	.string "¿Quieres combatir otra vez?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: Perder aún deja un\n"
	.string "regusto amargo…\p"
	.string "Pero conocer entrenadores fuertes\n"
	.string "me anima a mejorar…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "¿Te parece raro un\n"
	.string "GIMNASIO exclusivo\l"
	.string "para chicas?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "¡Oh, maldición!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "Tenía que haber\n"
	.string "estado más atenta.$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "¡Oh! ¿Un combate?\n"
	.string "Me da un poco de\l"
	.string "miedo, pero bueno.$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "¡Oh! ¿Se acabó?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "¡Uauu! ¡Tienes\n"
	.string "muchas MEDALLAS!\p"
	.string "¡No me extraña\n"
	.string "haber perdido!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "¿Estabas mirando\n"
	.string "estas flores o\l"
	.string "a mí?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "¡Qué rabia!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "¿Cómo podré llegar\n"
	.string "a ser tan elegante\l"
	.string "como ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "¡Te enseñaremos\n"
	.string "los movimientos\p"
	.string "POKéMON que nos\n"
	.string "enseñó ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Hemos perdido…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "¡ERIKA te lo hará\n"
	.string "pagar!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "¡Vamos a proteger\n"
	.string "a ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "No podíamos ganar…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "¡ERIKA es mucho,\n"
	.string "mucho más fuerte!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "GIMNASIO POKéMON DE AZULONA\n"
    .string "LÍDER: ERIKA\p"
	.string "GANADORES:\n"
	.string "AZUL, ROJO$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "GIMNASIO POKéMON DE AZULONA\n"
    .string "LÍDER: ERIKA\p"
    .string "GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

CeladonCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_AZULONA, CeladonCity_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_AZULONA, CeladonCity_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_AZULONA
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

CeladonCity_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_AZULONA, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Gym_EventScript_Manolin_GiveFlameOrb
	case 1, CeladonCity_Gym_EventScript_Manolin_GiveHeatRock
	case MULTI_B_PRESSED, CeladonCity_Gym_EventScript_Manolin_NoChoice
	end

CeladonCity_Gym_EventScript_Manolin_GiveFlameOrb::
	giveitem ITEM_FLAME_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_AZULONA
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_FlameOrbExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Manolin_GiveHeatRock::
	giveitem ITEM_HEAT_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_AZULONA
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_HeatRockExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox CeladonCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_Manolin_Intro:
	.string "¡Buenas mi gente! ¡Qué pasada de jardín!\p"
	.string "Esta debe de ser Ciudad Arborada,\n"
	.string "el feudo de Alana, ¿a que sí?\p"
	.string "Aunque no veo casitas en los árboles ni\n"
	.string "pájaros... ¡solo flores gigantes y chicas!\p"
	.string "Me he colado disimulando antes de que\n"
	.string "me echen. Hay que tramear el pull.$"

CeladonCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Ojo al dato! ¡Llevas la party a punto\n"
	.string "de caer de rodillas!\p"
	.string "Aquí las flores pegan con drenadoras\n"
	.string "y somníferos molestos.\l"
	.string "Primero full de vida y luego hablamos.$"

CeladonCity_Gym_Text_Manolin_Healed:
	.string "¡Salud restaurada y una cura premium\n"
	.string "para tu inventario!$"

CeladonCity_Gym_Text_Manolin_OfferChoices:
	.string "Para quemar este bosque con estilo\n"
	.string "hace falta calor del bueno.\l"
	.string "¿Cuál de estos dos objetos bis quieres?$"

CeladonCity_Gym_Text_Manolin_FlameOrbExplain:
	.string "¡La LLAMASFERA te quema al final del\n"
	.string "primer turno! Pega brutal con Agallas\l"
	.string "o Imagen, y encima evita parálisis.$"

CeladonCity_Gym_Text_Manolin_HeatRockExplain:
	.string "¡La ROCA CALOR alarga el Día Soleado\n"
	.string "a 8 turnazos completos!\l"
	.string "Los ataques de Fuego pegan una barbaridad.$"

CeladonCity_Gym_Text_Manolin_NoChoice:
	.string "Tómate tu tiempo, huele las flores\n"
	.string "y decide cuando quieras.$"

CeladonCity_Gym_Text_Manolin_AfterItem:
	.string "Tráeme un ramo si sales victorioso,\n"
	.string "¡y a reventar el boss, mi gente!$"
