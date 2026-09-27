PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "¿Has visitado el GIMNASIO PLATEADO?\p"
	.string "El LÍDER usa POKéMON de tipo ROCA.$"

PewterCity_Text_BugCatcher:
	.string "De noche, los CLEFAIRY salen a\n"
	.string "jugar en MT. MOON.\p"
	.string "Pero no todas las noches.$"

PewterCity_Text_Gramps:
	.string "Ah, ¿has venido desde JOHTO?\p"
	.string "Qué recuerdos. De joven fui a\n"
	.string "JOHTO para entrenarme.\p"
	.string "Me recuerdas mucho a mí de joven.\p"
	.string "Toma este objeto que encontré\n"
	.string "en JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Conocer lugares y gente nuevos…\p"
	.string "Esas son las alegrías de viajar.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "CIUDAD PLATEADA\n"
	.string "La ciudad gris piedra$"

PewterCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE PLATEADA\n"
	.string "LÍDER: BROCK\p"
	.string "El férreo Entrenador POKéMON$"

PewterCity_Text_MuseumSign:
	.string "Hay un aviso…\p"
	.string "El MUSEO de CIENCIA está cerrado\n"
	.string "por reformas…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "Hay un aviso…\p"
	.string "¡TIENDA DE MT. MOON YA ABIERTA!$"

PewterCity_Text_WelcomeSign:
	.string "¡BIENVENIDO A CIUDAD PLATEADA!$"
