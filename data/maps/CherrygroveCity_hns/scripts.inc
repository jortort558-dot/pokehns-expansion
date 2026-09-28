CherrygroveCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGroveCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CherryGroveCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

CherryGroveCity_EventScript_TriggerGent_Top::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Top
	waitmovement 0 
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Mid::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Bottom::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0 
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Bottom
	waitmovement 0 
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Cancel::
	msgbox CherrygroveCity_Text_GuideGentDecline, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHERRYGROVE_CITY_STATE, 1 @ CHANGE THIS TO 1 LATER
	release
	end

CherryGroveCity_EventScript_GentTour::
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokecenter
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokecenter
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentPokecenter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokemart
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokemart
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentMart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Route30
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Route30
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentRoute30, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Sea
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Sea
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_House_Gent
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_House_Player
	waitmovement 0
	waitmovement 0
	delay 20
	msgbox CherrygroveCity_Text_GuideGentMap, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Gent_Leave
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 20
	opendoor 42, 14
	waitdooranim
	waitmovement 0
	removeobject LOCALID_GUIDE_GENT
	closedoor 42, 14
	waitdooranim
	
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
	fadedefaultbgm
	release
	end

CherryGroveCity_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MYSTICWATER, CherryGroveCity_EventScript_Fisherman2
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_Fisherman2
	giveitem ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull 
	closemessage
	setflag FLAG_GOT_MYSTICWATER
	release
	end

CherryGroveCity_EventScript_Fisherman2::
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_TeacherHaveMapCard, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherryGroveCity_EventScript_Boy2
	msgbox CherrygroveCity_Text_YoungsterNoPokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy2::
	msgbox CherrygroveCity_Text_YoungsterHavePokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Staryu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Staryu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Corsola::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Krabby::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Sign::
	lock
	msgbox CherrygroveCity_Text_CitySign, MSGBOX_SIGN
	closemessage
	release
	end	

CherryGroveCity_EventScript_TriggerSilver_Top::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Top
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver_Bottom::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Bottom
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Enter
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalSeen, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_MON, 0, CherryGroveCity_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, CherryGroveCity_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, CherryGroveCity_Silver_Battle_Chikorita
	release
	end

CherryGroveCity_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_AfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox CherrygroveCity_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Silver_Leave1Player
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave1
	waitmovement 0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CHERRYGROVE_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CHERRYGROVE_SILVER
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_EAST
	delay 60
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_SOUTH
	delay 30
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Return
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalID, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave2
	waitmovement 0
	removeobject LOCALID_CHERRYGROVE_SILVER
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 4
	fadedefaultbgm
	release
	end

CherrygroveCity_Text_GuideGentIntro:
	.string "Eres un entrenador novato,\n"
	.string "¿verdad? ¡Se te nota a la legua!\p"
	.string "¡No pasa nada! ¡Todos hemos sido\n"
	.string "novatos en algún momento!\p"
	.string "Si quieres, puedo enseñarte\n"
	.string "un par de cosas sobre la ciudad.$"

CherrygroveCity_Text_GuideGentTourStart:
	.string "¡Estupendo!\n"
	.string "¡Sígueme!$"

CherrygroveCity_Text_GuideGentPokecenter:
	.string "Esto es un CENTRO POKéMON.\p"
	.string "Curan a tus POKéMON en\n"
	.string "un momento.\p"
	.string "Los usarás a menudo,\n"
	.string "así que conviene conocerlos.$"

CherrygroveCity_Text_GuideGentMart:
	.string "Esto es una TIENDA POKéMON.\p"
	.string "Venden BALLS y otros objetos\n"
	.string "que te serán muy útiles.$"

CherrygroveCity_Text_GuideGentRoute30:
	.string "La RUTA 30 sale por aquí.\p"
	.string "Allí los entrenadores ponen a\nprueba\l"
	.string "a sus queridos POKéMON en combate.$"

CherrygroveCity_Text_GuideGentSea:
	.string "Esto es el mar, como puedes ver.\p"
	.string "Algunos POKéMON solo se encuentran\n"
	.string "en el agua.$"

CherrygroveCity_Text_GuideGentMap:
	.string "Y aquí…\p"
	.string "¡Es mi casa! Gracias por tu\ncompañía.\p"
	.string "¡Ah, y si alguna vez te pierdes,\nconsulta\l"
	.string "el MAPA en tu POKéGEAR!\p"
	.string "¡Te deseo mucha suerte en tu viaje!$"

CherrygroveCity_Text_GuideGentDecline:
	.string "Vaya… Es algo que me encanta hacer…\p"
	.string "Bueno. Pásate a verme cuando\nquieras.$"

CherrygroveCity_Text_RivalSeen:
	.string "… … … … … … … …\p"
	.string "Te dieron un POKéMON en el LAB.\p"
	.string "Menudo desperdicio.\n"
	.string "Con un pringao como tú.\p"
	.string "… … … … … … … …\p"
	.string "¿No pillas lo que te digo?\n"
	.string "Yo sí tengo un POKéMON bueno.\p"
	.string "¡Mira y aprende, payaso!$"

CherrygroveCity_Text_SilverWin:
	.string "Tsk… ¡De potra, payaso!\n"
	.string "¿Te crees muy chulo o qué?$"

CherrygroveCity_Text_RivalAfter:
	.string "… … … … … … … …\p"
	.string "¿Quieres saber quién soy?\p"
	.string "Voy a ser el puto amo de\n"
	.string "todos los entrenadores.$"

CherrygroveCity_Text_RivalID:
	.string "¡Suelta eso, mangante!\n"
	.string "¡Es mi TARJETA!\p"
	.string "¡Me cago en to'!\n"
	.string "¡¿Ya me has fichao el nombre?!$"

CherrygroveCity_Text_TeacherHaveMapCard:
	.string "Cuando viajas con POKéMON,\n"
	.string "cualquier lugar resulta divertido.$"

CherrygroveCity_Text_YoungsterNoPokedex:
	.string "La casa del SR. POKéMON está\n"
	.string "un poco más adelante.$"

CherrygroveCity_Text_YoungsterHavePokedex:
	.string "Combatí con los entrenadores\n"
	.string "del camino.\p"
	.string "Mis POKéMON perdieron. ¡Están\n"
	.string "hechos polvo! Debo llevarlos\l"
	.string "al CENTRO POKéMON.$"

CherrygroveCity_Text_MysticWaterGuyBefore:
	.string "Un POKéMON que atrapé llevaba un\nobjeto.\p"
	.string "Creo que es AGUA MÍSTICA.\p"
	.string "A mí no me hace falta, ¿la quieres\ntú?$"

CherrygroveCity_Text_MysticWaterGuyAfter:
	.string "Bueno, pues a seguir pescando.$"

CherrygroveCity_Text_CitySign:
	.string "CIUDAD CEREZO\p"
	.string "La Ciudad de las Flores Bellas y\n"
	.string "Aromáticas$"

CherrygroveCity_Text_GuideGentsHouseSign:
	.string "CASA DEL GUÍA TURÍSTICO$"

CherryGroveCity_Text_Staryu:
	.string "STARYU: Yuuuuuuuu.$"

CherryGroveCity_Text_Corsola:
	.string "CORSOLA: Corsola! La!$"

CherryGroveCity_Text_Krabby:
	.string "KRABBY: KOOOOKEEE!$"

CherryGroveCity_Movement_Trigger_Gent:
	walk_down
	walk_left
	walk_down
	face_left
	step_end

CherryGroveCity_Movement_Trigger_Top:
	walk_down
	face_up
	step_end

CherryGroveCity_Movement_Trigger_Bottom:
	walk_up
	face_up
	step_end

CherryGroveCity_Movement_Pokecenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherryGroveCity_Movement_Pokemart:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CherryGroveCity_Movement_Route30:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Sea:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

CherryGroveCity_Movement_House_Gent:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_House_Player:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_Gent_Leave:
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Trigger_Silver_Top:
	walk_down
	face_right
	step_end

CherryGroveCity_Movement_Trigger_Silver_Bottom:
	walk_up
	face_right
	step_end

CherryGroveCity_Movement_Silver_Enter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1:
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1Player:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

CherryGroveCity_Movement_Silver_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end


CherryGroveCity_Movement_Silver_Leave2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
