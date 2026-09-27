SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA: Sabía"
	.string "\nque vendrías…"
	.string "\pHace tres años"
	.string "\ntuve una visión"
	.string "\lde tu llegada."
	.string "\pTú lo que quieres"
	.string "\nes mi MEDALLA."
	.string "\pNo me gusta"
	.string "\nluchar, pero mi"
	.string "\pdeber como LÍDER"
	.string "\nes conceder"
	.string "\pMEDALLAS a todo"
	.string "\naquel que se las"
	.string "\lmerezca."
	.string "\pComo eso es lo que"
	.string "\nquieres, mira mis"
	.string "\l$poderes psíquicos."
SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA: Tu poder…"
	.string "\nsupera con creces"
	.string "\llo que esperaba…"
	.string "\pQuizá no se pueda"
	.string "\npredecir del todo"
	.string "\plo que nos espera"
	.string "\nen el futuro…"
	.string "\pVale, tú ganas."
	.string "\nTe has ganado la"
	.string "\l$MEDALLA PANTANO."
SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} received MARSHBADGE.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA: La MEDALLA PANTANO\n"
	.string "despierta poderes ocultos…\p"
	.string "No pude predecir bien tu poder,\n"
	.string "pero sé algo con certeza.\p"
	.string "¡Serás un CAMPEÓN célebre y\n"
	.string "querido por todos!$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Toma esto también.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "Contiene INTERCAMBIO.\p"
	.string "Intercambia tu habilidad con la\n"
	.string "del rival. Úsala con cabeza…$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA: Tu amor"
	.string "\npor tus POKéMON"
	.string "\psupera mi poder"
	.string "\npsíquico…"
	.string "\pCreo que el poder"
	.string "\ndel amor es un"
	.string "\ptipo de poder"
	.string "\n$psíquico…"
SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA: Ah, CAMPEÓN de KANTO.\p"
	.string "Percibí tu regreso. Tu poder ha\n"
	.string "crecido enormemente.\p"
	.string "Aún siento tu aura.\n"
	.string "¿Quieres una revancha?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "SABRINA: Tu amor por tus POKéMON\n"
	.string "volvió a superar mi poder…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "¡El poder de todos"
	.string "\na los que venciste"
	.string "\l$está en mí!"
SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Fuerte…"
	.string "\n$Muy fuerte…"
SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "¿De dónde proviene"
	.string "\n$tu poder?"
SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "El poder psíquico"
	.string "\nes el poder de tu"
	.string "\l$alma."
SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "¡Tu alma tiene más"
	.string "\n$poder que la mía!"
SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Has fortalecido tu"
	.string "\nalma, no sólo tus"
	.string "\l$habilidades."
SaffronCity_Gym_Text_MediumDorisSeen:
	.string "¡Fufufufu…!"
	.string "\nLo veo claramente."
	.string "\p¡Puedo ver lo que"
	.string "\n$encierra tu alma!"
SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "A pesar de leerte"
	.string "\nel pensamiento,"
	.string "\l$he perdido…"
SaffronCity_Gym_Text_MediumDorisAfter:
	.string "¡Maldición! Olvidé"
	.string "\nque predije mi"
	.string "\l$derrota contra ti."
SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "El DOJO-KARATE era"
	.string "\nel GIMNASIO de"
	.string "\l$esta ciudad."
SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "¡No he estado a tu"
	.string "\n$altura…!"
SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "El REY del KARATE,"
	.string "\nel maestro del"
	.string "\pDOJO-KARATE, acaba"
	.string "\nde ser machacado"
	.string "\l$por SABRINA."
SaffronCity_Gym_Text_GymGuideIntro:
	.string "¡Hola, futuro CAMPEÓN!\p"
	.string "Un entrenador como tú no necesita\n"
	.string "consejos contra el tipo PSÍQUICO.\p"
	.string "¡Espero grandes cosas de ti!\n"
	.string "¡Buena suerte!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "¡Ha sido otro combate fantástico!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
