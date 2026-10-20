PalletTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_Lab_OnTransition
	.byte 0

PalletTown_Lab_OnTransition::
	setflag FLAG_HIDE_MOHEDANO_PALLET
	clearflag FLAG_HIDE_PALLET_LAB_OAK
	call_if_set FLAG_MOHEDANO_PALLET_FINALE_READY, PalletTown_Lab_EventScript_CheckMohedanoFinale
	end

PalletTown_Lab_EventScript_CheckMohedanoFinale::
	goto_if_set FLAG_MOHEDANO_STORY_COMPLETE, PalletTown_Lab_EventScript_CheckMohedanoFinaleEnd
	setflag FLAG_HIDE_PALLET_LAB_OAK
	clearflag FLAG_HIDE_MOHEDANO_PALLET
PalletTown_Lab_EventScript_CheckMohedanoFinaleEnd::
	return

PalletTown_Lab_EventScript_Mohedano::
	lock
	faceplayer
	setspeaker SP_NAME_MOHEDANO
	goto_if_defeated TRAINER_TABULA_RASA_HNS, PalletTown_Lab_EventScript_MohedanoEnding
	goto_if_defeated TRAINER_PROFESSOR_MOHEDANO_HNS, PalletTown_Lab_EventScript_TabulaBattle
	msgbox PalletTown_Lab_Text_MohedanoReveal, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_PROFESSOR_MOHEDANO_HNS, PalletTown_Lab_Text_MohedanoDefeated

PalletTown_Lab_EventScript_TabulaBattle::
	setspeaker SP_NAME_MOHEDANO
	msgbox PalletTown_Lab_Text_TabulaAwakens, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_TABULA_RASA_HNS, PalletTown_Lab_Text_TabulaDefeated

PalletTown_Lab_EventScript_MohedanoEnding::
	setspeaker SP_NAME_MOHEDANO
	msgbox PalletTown_Lab_Text_MohedanoEnding, MSGBOX_DEFAULT
	setflag FLAG_MOHEDANO_STORY_COMPLETE
	setflag FLAG_HIDE_MOHEDANO_PALLET
	clearflag FLAG_HIDE_PALLET_LAB_OAK
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PALLET_LAB_MOHEDANO
	addobject LOCALID_PALLET_LAB_OAK
	fadescreenswapbuffers FADE_FROM_BLACK
	setspeaker SP_NAME_NONE
	msgbox PalletTown_Lab_Text_OakAfterMohedano, MSGBOX_DEFAULT
	release
	end

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "¿Cómo va tu POKéDEX?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "OAK: ¡Ah, {PLAYER}!\n"
	.string "Me alegra que hayas venido hasta\l"
	.string "KANTO.\p"
	.string "¿Qué opinas de sus ENTRENADORES?\n"
	.string "Son bastante duros, ¿eh?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Si estás por la zona, espero que\n"
	.string "vuelvas a visitarme.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "OAK: ¡Vaya! ¡Excelente!\p"
	.string "Has reunido las MEDALLAS de los\n"
	.string "GIMNASIOS de KANTO. ¡Bien hecho!\p"
	.string "No me equivocaba contigo.\p"
	.string "Te diré algo, {PLAYER}. Haré los\n"
	.string "preparativos para que puedas ir\l"
	.string "al MONTE PLATEADO.\p"
	.string "Es una gran montaña habitada por\n"
	.string "muchos POKéMON salvajes.\p"
	.string "Es demasiado peligrosa para un\n"
	.string "ENTRENADOR cualquiera y está\l"
	.string "prohibido entrar, pero contigo\l"
	.string "haremos una excepción, {PLAYER}.\p"
	.string "Ve a la MESETA AÑIL. Desde allí\n"
	.string "llegarás al MONTE PLATEADO.$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "Ah, y hablando de la MESETA AÑIL,\n"
	.string "ahora que tienes 16 MEDALLAS, la\l"
	.string "LIGA de KANTO volverá a aceptar\l"
	.string "tu desafío.\p"
	.string "Pero ten cuidado: LANCE y su\n"
	.string "ALTO MANDO no te lo pondrán fácil\l"
	.string "esta vez.\p"
	.string "¡Buena suerte, {PLAYER}!$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "OAK: ¿Mmm? ¿No reúnes las MEDALLAS\n"
	.string "de KANTO?\p"
	.string "Sus LÍDERES son tan duros como los\n"
	.string "que enfrentaste en JOHTO.\p"
	.string "Te recomiendo que los desafíes.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "OAK: Ah, reúnes las MEDALLAS de\n"
	.string "KANTO.\p"
	.string "Será difícil, pero la experiencia\n"
	.string "te ayudará.\p"
	.string "Ven cuando las tengas todas.\p"
	.string "Tendré un regalo para ti.\p"
	.string "¡Sigue esforzándote, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "El programa de radio CHARLAS\n"
	.string "POKéMON no se emite en KANTO.\p"
	.string "Es una pena. Me gustaría oírlo.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Gracias a tu labor con la POKéDEX,\n"
	.string "la investigación del PROFESOR va\l"
	.string "estupendamente.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "No se lo digas a nadie: CHARLAS\n"
	.string "POKéMON no se emite en directo.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Hay un correo electrónico en el PC.\p"
	.string "…\p"
	.string "PROF. OAK, ¿cómo avanza su\n"
	.string "investigación?\p"
	.string "Yo sigo trabajando duro.\p"
	.string "He oído que {PLAYER} está ganando\n"
	.string "bastante fama.\p"
	.string "Me alegra mucho saberlo.\p"
	.string "ELM, en PUEBLO PRIMAVERA 8-)$"

PalletTown_Lab_Text_MohedanoReveal:
	.string "Llegas tarde para impedirlo,\n"
	.string "pero justo a tiempo para verlo.\p"
	.string "Los recuerdos de un POKéMON\n"
	.string "limitan aquello que puede ser.\p"
	.string "TABULA RASA los libera.\n"
	.string "Sin miedo. Sin dueño. Sin pasado.\p"
	.string "¿Acaso tu NUZLOCKE no hace lo\n"
	.string "mismo cada vez que pierdes?\p"
	.string "Demuéstrame que tu vínculo vale\n"
	.string "más que mi ciencia.$"

PalletTown_Lab_Text_MohedanoDefeated:
	.string "Así que esto es recordar...$"

PalletTown_Lab_Text_TabulaAwakens:
	.string "No importa. El profesor era solo\n"
	.string "la hipótesis.\p"
	.string "TABULA RASA ya ha aprendido de\n"
	.string "todos nosotros.\p"
	.string "Y ahora va a aprender de ti.$"

PalletTown_Lab_Text_TabulaDefeated:
	.string "TABULA RASA pierde la señal.$"

PalletTown_Lab_Text_MohedanoEnding:
	.string "Curioso... No la venciste\n"
	.string "olvidando, sino recordando.\p"
	.string "Quizá me equivoqué. O quizá solo\n"
	.string "faltaba una muestra como tú.\p"
	.string "Cuando vuelvas a verme, decide\n"
	.string "cuál de las dos cosas ocurrió.$"

PalletTown_Lab_Text_OakAfterMohedano:
	.string "OAK: El sistema ha quedado limpio.\p"
	.string "Pero no encuentro a MOHEDANO\n"
	.string "entre los registros de salida.\p"
	.string "Sea lo que sea TABULA RASA,\n"
	.string "esto aún no ha terminado.$"
