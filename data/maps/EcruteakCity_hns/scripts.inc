EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "¡¡PUM!!$"
EcruteakCity_Text_Silver2:
	.string "{RIVAL}: ¿Cómo...? ¿Cómo cojones\n"
	.string "ha podido pasar esto?\p"
	.string "¿Cómo coño puedo perder contra\n"
	.string "unas simples CHICAS KIMONO...?$"
EcruteakCity_Text_Silver3:
	.string "{RIVAL}: Me estabas espiando,\n"
	.string "¿verdad, {PLAYER}?\p"
	.string "¡Sí, claro que sí!\p"
	.string "Nunca imaginé que tumbar a cinco\n"
	.string "CHICAS KIMONO fuera tan\l"
	.string "jodidamente difícil...\p"
	.string "Me han dado una paliza de\n"
	.string "espanto...\p"
	.string "...\p"
	.string "Tú has venido por lo mismo, ¿a\n"
	.string "que sí?\p"
	.string "¡No te creas la gran hostia solo\n"
	.string "por haber derrotado al TEAM\l"
	.string "ROCKET!\p"
	.string "Esas CHICAS KIMONO son\n"
	.string "exageradamente fuertes.\p"
	.string "A ver si tú puedes con ellas,\n"
	.string "payaso.\p"
	.string "Pero yo paso de volver dentro:\n"
	.string "me niego a verte ganar.$"
EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EEVEE: ¡Veee!$"
EcruteakCity_Text_Vulpix:
	.string "VULPIX: ¡Vullll Pix!$"
EcruteakCity_Text_UnusedMissingDaughter:
	.string "¡Ay, no! ¡Ay, no!\p"
	.string "Mi hija ha desaparecido.\p"
	.string "No... No habrá ido a la TORRE\n"
	.string "QUEMADA, ¿verdad?\p"
	.string "Le advertí que no se acercara\n"
	.string "allí... Dicen que la gente se\l"
	.string "desvanece...\p"
	.string "¡Oh, qué debería hacer...!$"
EcruteakCity_Text_Gramps1:
	.string "CIUDAD IRIS solía tener dos\n"
	.string "torres: una en el este y otra en\l"
	.string "el oeste.$"
EcruteakCity_Text_Gramps2:
	.string "Ah, criatura. ¿Has aprendido a\n"
	.string "bailar como las CHICAS KIMONO?\p"
	.string "Si vas a su TEATRO DE DANZA, un\n"
	.string "viejo muy curioso te dará un\l"
	.string "buen regalo, según he oído.$"
EcruteakCity_Text_Lass1:
	.string "Voy a practicar al TEATRO DE\n"
	.string "DANZA. ¿Te apetece venir\l"
	.string "conmigo?$"
EcruteakCity_Text_Lass2:
	.string "La torre que solía estar aquí...\p"
	.string "Mi abuela me contó que era\n"
	.string "muchísimo más alta antes del\l"
	.string "incendio.\p"
	.string "Dicen que ahora está llena de\n"
	.string "fantasmas.$"
EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Tres enormes POKéMON salieron\n"
	.string "huyendo en distintas\l"
	.string "direcciones. ¿Qué eran?$"
EcruteakCity_Text_Fisher:
	.string "He oído un rumor sobre el FARO\n"
	.string "de CIUDAD OLIVO.\p"
	.string "El POKéMON que sirve de guía\n"
	.string "luminosa ha caído enfermo.\l"
	.string "Parece que están en un buen\l"
	.string "aprieto.$"
EcruteakCity_Text_Fisher_JasmineReturned:
	.string "¡El POKéMON del FARO de CIUDAD\n"
	.string "OLIVO ya está curado!\p"
	.string "Los barcos pueden navegar de\n"
	.string "nuevo con seguridad por la\l"
	.string "noche.$"
EcruteakCity_Text_Youngster:
	.string "Dicen que hay POKéMON\n"
	.string "enfurecidos en el LAGO DE LA\l"
	.string "FURIA. ¡Me molaría verlo!$"
EcruteakCity_Text_Gramps3:
	.string "En un pasado muy remoto...\p"
	.string "Esta torre ardió en llamas. Tres\n"
	.string "POKéMON sin nombre perecieron en\l"
	.string "ella.\p"
	.string "Un POKéMON con los colores del\n"
	.string "arcoíris bajó del cielo y les\l"
	.string "devolvió la vida...\p"
	.string "Es una leyenda transmitida por\n"
	.string "los LÍDERES de GIMNASIO de\l"
	.string "CIUDAD IRIS.\p"
	.string "¿Yo?\p"
	.string "Yo fui un gran entrenador en mis\n"
	.string "tiempos mozos. ¡Jojojo!$"
EcruteakCity_Text_SageGym:
	.string "El Líder MORTI no está aquí\n"
	.string "ahora. Quizá lo encuentres en la\l"
	.string "TORRE QUEMADA.$"
EcruteakCity_Text_Sign:
	.string "CIUDAD IRIS Una Ciudad Histórica\p"
	.string "Donde el Pasado se Funde con el\n"
	.string "Presente$"
EcruteakCity_Text_TinTowerSign:
	.string "TORRE HOJALATA\p"
	.string "Dicen que un POKéMON legendario\n"
	.string "anida en su cima.$"
EcruteakCity_Text_OfficeSign:
	.string "Control de Acceso a la TORRE\n"
	.string "HOJALATA\p"
	.string "Prohibido el paso a los no\n"
	.string "dignos.$"
EcruteakCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD IRIS\n"
	.string "LÍDER: MORTI\p"
	.string "El Vidente Místico del Futuro$"
EcruteakCity_Text_DanceTheaterSign:
	.string "TEATRO DE DANZA DE CIUDAD IRIS$"
EcruteakCity_Text_BurnedTowerSign:
	.string "TORRE QUEMADA\p"
	.string "Fue destruida por un misterioso\n"
	.string "fuego. Por favor, manténgase\l"
	.string "alejado por su propia seguridad.$"
