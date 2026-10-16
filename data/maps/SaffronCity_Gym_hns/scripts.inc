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

SaffronCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_AZAFRAN, SaffronCity_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_AZAFRAN, SaffronCity_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_AZAFRAN
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

SaffronCity_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_AZAFRAN, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_Gym_EventScript_Manolin_GiveToxicOrb
	case 1, SaffronCity_Gym_EventScript_Manolin_GiveMentalHerb
	case MULTI_B_PRESSED, SaffronCity_Gym_EventScript_Manolin_NoChoice
	end

SaffronCity_Gym_EventScript_Manolin_GiveToxicOrb::
	giveitem ITEM_TOXIC_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_AZAFRAN
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_ToxicOrbExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_EventScript_Manolin_GiveMentalHerb::
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_AZAFRAN
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_MentalHerbExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox SaffronCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_Manolin_Intro:
	.string "¡Ey, mi gente! ¡Qué mareo de teleport!\p"
	.string "Se supone que este es el GIMNASIO\n"
	.string "de Ciudad Algaria, ¿verdad?\l"
	.string "¿Pero dónde narices están los dos\l"
	.string "gemelos que levitan, Vito y Leti?\p"
	.string "Solo veo baldosas mágicas y a una chica\n"
	.string "con cara de pocos amigos al fondo.\l"
	.string "El lag mental que llevo es fino…$"

SaffronCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Aguanta ahí! ¡Pero si tienes al\n"
	.string "roster temblando de vida!\p"
	.string "Un golpe psíquico en la nuca y te\n"
	.string "mandan directo al cementerio.\l"
	.string "Trago de cura y todos listos.$"

SaffronCity_Gym_Text_Manolin_Healed:
	.string "¡Salud a tope y toma un consumible\n"
	.string "gourmet para que no te falte sustain!$"

SaffronCity_Gym_Text_Manolin_OfferChoices:
	.string "Contra bosses con control mental hay\n"
	.string "que tramear con cabeza.\l"
	.string "¿Qué objeto bis prefieres para el pull?$"

SaffronCity_Gym_Text_Manolin_ToxicOrbExplain:
	.string "¡La TOXISFERA es pura táctica!\n"
	.string "Te envenena al final del primer turno,\l"
	.string "así que nadie te puede dormir ni paralizar,\l"
	.string "¡y con Agallas o Antídoto revientas!$"

SaffronCity_Gym_Text_Manolin_MentalHerbExplain:
	.string "¡La HIERBA MENTAL te quita al instante\n"
	.string "la Mofa, la Atracción o el Anulación!\l"
	.string "Para que nadie te corte el casteo.$"

SaffronCity_Gym_Text_Manolin_NoChoice:
	.string "Piénsatelo con calma, que el boss\n"
	.string "no va a dejar de mirarte fijamente.$"

SaffronCity_Gym_Text_Manolin_AfterItem:
	.string "Cuidado con pisar las baldosas que no\n"
	.string "son, que acabas en otra dimensión.\l"
	.string "¡A por el boss, mi gente!$"
