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
    .string "CELADON POKéMON GYM\n"
    .string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "CELADON POKéMON GYM\n"
    .string "LEADER: ERIKA\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
