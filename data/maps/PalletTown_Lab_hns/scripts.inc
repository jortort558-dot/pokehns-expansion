PalletTown_Lab_hns_MapScripts::
	.byte 0

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
	.string "No me equivocaba\n"
	.string "contigo.\p"
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
	.string "LIGA de KANTO volverá\l"
	.string "a aceptar\l"
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
