PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	goto_if_unset FLAG_PEWTER_MUSEUM_DANI_DEFEATED, PewterCity_EventScript_HideMuseumDuo
	goto_if_set FLAG_PEWTER_MUSEUM_DUO_DEFEATED, PewterCity_EventScript_HideMuseumDuo
	clearflag FLAG_HIDE_PEWTER_MUSEUM_ZORTEX
	clearflag FLAG_HIDE_PEWTER_MUSEUM_PANDA
	end

PewterCity_EventScript_HideMuseumDuo::
	setflag FLAG_HIDE_PEWTER_MUSEUM_ZORTEX
	setflag FLAG_HIDE_PEWTER_MUSEUM_PANDA
	end

PewterCity_EventScript_MuseumDuoFrontExit::
	goto_if_unset FLAG_PEWTER_MUSEUM_DANI_DEFEATED, PewterCity_EventScript_MuseumDuoNoScene
	goto_if_set FLAG_PEWTER_MUSEUM_DUO_DEFEATED, PewterCity_EventScript_MuseumDuoNoScene
	setvar VAR_TEMP_0, 1
	lockall
	setobjectxy LOCALID_PEWTER_HNS_ZORTEX, 17, 9
	setobjectxyperm LOCALID_PEWTER_HNS_ZORTEX, 17, 9
	setobjectxy LOCALID_PEWTER_HNS_PANDA, 21, 9
	setobjectxyperm LOCALID_PEWTER_HNS_PANDA, 21, 9
	call PewterCity_EventScript_MuseumDuoBlink
	applymovement LOCALID_PEWTER_HNS_ZORTEX, PewterCity_Movement_ZortexApproachesFrontDoor
	applymovement LOCALID_PEWTER_HNS_PANDA, PewterCity_Movement_PandaApproachesFrontDoor
	waitmovement 0
	goto PewterCity_EventScript_ZortexPandaChallenge

PewterCity_EventScript_MuseumDuoSideExit::
	goto_if_unset FLAG_PEWTER_MUSEUM_DANI_DEFEATED, PewterCity_EventScript_MuseumDuoNoScene
	goto_if_set FLAG_PEWTER_MUSEUM_DUO_DEFEATED, PewterCity_EventScript_MuseumDuoNoScene
	setvar VAR_TEMP_0, 1
	lockall
	setobjectxy LOCALID_PEWTER_HNS_ZORTEX, 25, 7
	setobjectxyperm LOCALID_PEWTER_HNS_ZORTEX, 25, 7
	setobjectxy LOCALID_PEWTER_HNS_PANDA, 29, 7
	setobjectxyperm LOCALID_PEWTER_HNS_PANDA, 29, 7
	call PewterCity_EventScript_MuseumDuoBlink
	applymovement LOCALID_PEWTER_HNS_ZORTEX, PewterCity_Movement_ZortexApproachesSideDoor
	applymovement LOCALID_PEWTER_HNS_PANDA, PewterCity_Movement_PandaApproachesSideDoor
	waitmovement 0
	goto PewterCity_EventScript_ZortexPandaChallenge

PewterCity_EventScript_MuseumDuoNoScene::
	end

PewterCity_EventScript_MuseumDuoBlink::
	removeobject LOCALID_PEWTER_HNS_ZORTEX
	removeobject LOCALID_PEWTER_HNS_PANDA
	delay 6
	addobject LOCALID_PEWTER_HNS_ZORTEX
	addobject LOCALID_PEWTER_HNS_PANDA
	delay 6
	removeobject LOCALID_PEWTER_HNS_ZORTEX
	removeobject LOCALID_PEWTER_HNS_PANDA
	delay 6
	addobject LOCALID_PEWTER_HNS_ZORTEX
	addobject LOCALID_PEWTER_HNS_PANDA
	delay 6
	return

PewterCity_EventScript_ZortexPanda::
	lockall
	faceplayer
	goto PewterCity_EventScript_ZortexPandaChallenge

PewterCity_EventScript_ZortexPandaChallenge::
	specialvar VAR_RESULT, HasEnoughMonsForDoubleBattle
	goto_if_eq VAR_RESULT, FALSE, PewterCity_EventScript_ZortexPandaNotEnoughMons
	msgbox PewterCity_Text_ZortexPandaIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ZORTEX_PANDA_MUSEUM_HNS, PewterCity_Text_ZortexPandaDefeat
	goto PewterCity_EventScript_ZortexPandaDefeated

PewterCity_EventScript_ZortexPandaNotEnoughMons::
	msgbox PewterCity_Text_ZortexPandaNotEnoughMons, MSGBOX_DEFAULT
	releaseall
	end

PewterCity_EventScript_ZortexPandaDefeated::
	setflag FLAG_PEWTER_MUSEUM_DUO_DEFEATED
	msgbox PewterCity_Text_ZortexPandaEscape, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_PEWTER_MUSEUM_ZORTEX
	setflag FLAG_HIDE_PEWTER_MUSEUM_PANDA
	removeobject LOCALID_PEWTER_HNS_ZORTEX
	removeobject LOCALID_PEWTER_HNS_PANDA
	releaseall
	end

PewterCity_Movement_ZortexApproachesFrontDoor:
	walk_right
	step_end

PewterCity_Movement_PandaApproachesFrontDoor:
	walk_left
	step_end

PewterCity_Movement_ZortexApproachesSideDoor:
	walk_right
	step_end

PewterCity_Movement_PandaApproachesSideDoor:
	walk_left
	step_end

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

PewterCity_Text_ZortexPandaIntro:
	.string "ZORTEX: YAMI ya está lejos.\p"
	.string "PANDA: Nosotros solo necesitamos\n"
	.string "que tú sigas aquí.$"

PewterCity_Text_ZortexPandaDefeat:
	.string "Hasta juntos dejamos un rastro…$"

PewterCity_Text_ZortexPandaNotEnoughMons:
	.string "PANDA: Esto se hace por parejas.\p"
	.string "Vuelve con dos POKéMON capaces\n"
	.string "de combatir.$"

PewterCity_Text_ZortexPandaEscape:
	.string "ZORTEX: La M no es una firma.\n"
	.string "Es una invitación.\p"
	.string "PANDA: Si sigues investigando,\n"
	.string "el PROFESOR te encontrará.$"

PewterCity_Text_ZortexPandaAfter:
	.string "Los dos ninjas vigilan la plaza\n"
	.string "sin decir una palabra.$"

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
