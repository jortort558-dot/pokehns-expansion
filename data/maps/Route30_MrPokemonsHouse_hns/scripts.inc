Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "¡Hola! Tú debes de ser {PLAYER}.\p"
	.string "El PROF. ELM me avisó de que\nvendrías.$"

MrPokemonHouse_Text_Intro2:
	.string "Esto es lo que quiero que examine\nel\l"
	.string "PROF. ELM.$"

MrPokemonHouse_Text_GotEgg:
	.string "¡Recibes el HUEVO MISTERIOSO!$"

MrPokemonHouse_Text_Intro3:
	.string "Conozco a una pareja que regenta\nuna\l"
	.string "GUARDERÍA POKéMON.\p"
	.string "Ellos me dieron ese HUEVO.\p"
	.string "Sentí curiosidad, así que le envié\nun e-mail\l"
	.string "al PROF. ELM.\p"
	.string "En temas de evolución POKéMON, el\nPROF. ELM\l"
	.string "es la máxima autoridad.$"


MrPokemonHouse_Text_Intro4:
	.string "Hasta el PROF. OAK reconoce su\ntalento.$"

MrPokemonHouse_Text_Intro5:
	.string "Si mi hipótesis es correcta, el\nPROF. ELM\l"
	.string "sabrá descubrirlo.$"

MrPokemonHouse_Text_Heal:
	.string "¿Vas a volver con el PROF. ELM?\p"
	.string "Espera. Tus POKéMON deberían\ndescansar un poco.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "¡Cuento contigo!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "¡La vida es maravillosa!\n"
	.string "Siempre hay nuevos descubrimientos\lque hacer.$"

MrPokemonHouse_Text_OakIntro:
	.string "OAK: ¡Ajá! ¡Así que eres {PLAYER}!\p"
	.string "¡Soy OAK, investigador POKéMON!\p"
	.string "Visitaba a mi viejo amigo,\n"
	.string "el SR. POKéMON.\p"
	.string "Supe que hacías un recado\n"
	.string "para ELM y esperé aquí.\p"
	.string "¡Oh! ¡Un POKéMON muy raro!\p"
	.string "Veamos…\n"
	.string "Mmm, ¡ya entiendo!\p"
	.string "Ya sé por qué ELM te dio\n"
	.string "un POKéMON para el recado.\p"
	.string "Para ELM y para mí,\n"
	.string "los POKéMON son amigos.\p"
	.string "Vio que tratarías al tuyo\n"
	.string "con cariño y atención.\p"
	.string "…¡Ah!\p"
	.string "Pareces alguien de fiar.\n"
	.string "¿Te gustaría ayudarme?\p"
	.string "Mira, esta es la última\n"
	.string "versión de la POKéDEX.\p"
	.string "Registra datos de todos\n"
	.string "los POKéMON vistos o atrapados.\p"
	.string "¡Es una enciclopedia avanzada!\p"
	.string "Muestra dónde viven, cómo\n"
	.string "evolucionan y sus movimientos.$"

MrPokemonHouse_Text_GetDex:
	.string "¡{PLAYER} recibió la POKéDEX!$"

MrPokemonHouse_Text_OakParting:
	.string "¡Conoce muchos POKéMON y\n"
	.string "completa esa POKéDEX!\p"
	.string "Pero ya me he entretenido mucho.\p"
	.string "Debo ir a CIUDAD TRIGAL\n"
	.string "para mi programa de radio.\p"
	.string "¡Cuento contigo, {PLAYER}!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "¿Eh? ¡Esa ESCAMA! ¿De qué es?\n"
	.string "¿De un GYARADOS rojo?\p"
	.string "¡Qué rareza! La… la quiero…\p"
	.string "{PLAYER}, ¿te gustaría cambiármela?\p"
	.string "Puedo darte este REPARTIR EXP que\nme dio\l"
	.string "el PROF. OAK.$"

MrPokemonHouse_Text_Disappointed:
	.string "Qué pena…\n"
	.string "Es algo extraordinariamente raro.$"

MrPokemonHouse_Text_ExpShare:
	.string "También tengo un objeto especial\npara ti.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "Está repleto de revistas\nextranjeras.\l"
	.string "No se pueden ni leer los títulos…$"

MrPokemonHouse_Text_BrokenComputer:
	.string "Es un ordenador enorme.\n"
	.string "Hmm… Parece que está roto.$"

MrPokemonHouse_Text_StrangeCoins:
	.string "¡Un montón de monedas extrañas!\p"
	.string "Quizá sean de otro país…$"

MrPokemonHouse_Text_GotExpShare:
	.string "¡{PLAYER} recibió REPARTIR EXP!$"
