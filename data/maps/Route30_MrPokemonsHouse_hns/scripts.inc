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
	.string "¡Hola, hola! Tú debes de ser\n"
	.string "{PLAYER}.\p"
	.string "El PROF. ELM me avisó de que\n"
	.string "vendrías a visitarme.$"

MrPokemonHouse_Text_Intro2:
	.string "Esto es lo que quiero que el\n"
	.string "PROF. ELM examine.$"

MrPokemonHouse_Text_GotEgg:
	.string "¡Recibes el HUEVO MISTERIOSO!$"

MrPokemonHouse_Text_Intro3:
	.string "Conozco a una pareja que lleva\n"
	.string "una GUARDERÍA POKéMON.\p"
	.string "Ellos me dieron ese HUEVO.\p"
	.string "Sentí curiosidad y le envié un\n"
	.string "correo al PROF. ELM.\p"
	.string "En evolución POKéMON, el\n"
	.string "PROF. ELM es toda una autoridad.$"


MrPokemonHouse_Text_Intro4:
	.string "Incluso el PROF. OAK que está\n"
	.string "aquí presente lo reconoce.$"

MrPokemonHouse_Text_Intro5:
	.string "Si mi suposición es acertada,\n"
	.string "el PROF. ELM sabrá confirmarlo.$"

MrPokemonHouse_Text_Heal:
	.string "¿Vas a regresar con el PROF. ELM?\n"
	.string "Tus POKéMON deberían descansar.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "¡Cuento contigo!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "¡La vida es maravillosa!\n"
	.string "¡Siempre hay cosas por descubrir!$"

MrPokemonHouse_Text_OakIntro:
	.string "OAK: ¡Ajá! ¡Conque tú eres\n"
	.string "{PLAYER}!\p"
	.string "¡Soy OAK, investigador POKéMON!\p"
	.string "Estaba visitando a mi viejo\n"
	.string "amigo, el SR. POKéMON.\p"
	.string "Supe que hacías un recado para\n"
	.string "ELM y decidí esperarte aquí.\p"
	.string "¡Oh! ¿Qué tenemos aquí?\n"
	.string "¡Un POKéMON muy poco común!\p"
	.string "A ver… Mmm, ¡ya lo entiendo!\p"
	.string "Comprendo por qué ELM te dio un\n"
	.string "POKéMON para este recado.\p"
	.string "Para investigadores como ELM y yo,\n"
	.string "los POKéMON son nuestros amigos.\p"
	.string "Él vio que tratarías al tuyo\n"
	.string "con mucho cariño y dedicación.\p"
	.string "… ¡Vaya!\n"
	.string "Pareces alguien muy de fiar.\p"
	.string "¿Qué te parecería echarme\n"
	.string "una mano con mi investigación?\p"
	.string "Esta es la última versión\n"
	.string "de la POKéDEX.\p"
	.string "Registra datos de los POKéMON\n"
	.string "que vayas viendo o capturando.\p"
	.string "¡Una enciclopedia portátil\n"
	.string "de última tecnología!$"


MrPokemonHouse_Text_GetDex:
	.string "¡{PLAYER} recibió la POKéDEX!$"

MrPokemonHouse_Text_OakParting:
	.string "¡Sal a conocer montones de\n"
	.string "POKéMON y completa la POKéDEX!\p"
	.string "Pero ya me he entretenido de más.\p"
	.string "Debo ir a CIUDAD TRIGAL para\n"
	.string "mi programa habitual de radio.\p"
	.string "¡Cuento contigo, {PLAYER}!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "¿Mmm? ¡Esa ESCAMA! ¿Qué es eso?\n"
	.string "¿La escama de un GYARADOS rojo?\p"
	.string "¡Qué rareza! La… la quiero…\p"
	.string "{PLAYER}, ¿me la cambiarías?\p"
	.string "Puedo darte este REPARTIR EXP\n"
	.string "que me regaló el PROF. OAK.$"

MrPokemonHouse_Text_Disappointed:
	.string "Qué lástima…\n"
	.string "Resulta que es algo muy raro.$"

MrPokemonHouse_Text_ExpShare:
	.string "También tengo un objeto especial\n"
	.string "para ti.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "Está repleto de revistas de fuera.\n"
	.string "No se pueden ni leer los títulos…$"


MrPokemonHouse_Text_BrokenComputer:
	.string "Es un ordenador enorme.\n"
	.string "Hmm… Parece que está roto.$"

MrPokemonHouse_Text_StrangeCoins:
	.string "¡Un montón de monedas extrañas!\p"
	.string "Quizá sean de otro país…$"

MrPokemonHouse_Text_GotExpShare:
	.string "¡{PLAYER} recibió REPARTIR EXP!$"
