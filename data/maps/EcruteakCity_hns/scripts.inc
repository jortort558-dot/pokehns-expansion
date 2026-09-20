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
	.string "{RIVAL}: ¿Cómo...? ¿Cómo cojones ha\npodido pasar esto?\p¿Cómo coño puedo perder contra unas\nsimples CHICAS KIMONO...?$"
EcruteakCity_Text_Silver3:
	.string "{RIVAL}: Me estabas espiando,\n¿verdad, {PLAYER}?\p¡Sí, claro que sí!\pNunca imaginé que tumbar a cinco\nCHICAS\lKIMONO fuera tan jodidamente\ldifícil...\pMe han dado una paliza de\nespanto...\p...\pTú has venido por lo mismo, ¿a que\nsí?\p¡No te creas la gran hostia solo\npor\lhaber derrotado al TEAM ROCKET!\pEsas CHICAS KIMONO son\nexageradamente\lfuertes.\pA ver si tú puedes con ellas,\npayaso.\pPero yo paso de volver dentro: me\nniego\la verte ganar.$"
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
	.string "¡Ay, no! ¡Ay, no!\pMi hija ha desaparecido.\pNo... No habrá ido a la TORRE\nQUEMADA,\l¿verdad?\pLe advertí que no se acercara\nallí...\lDicen que la gente se desvanece...\p¡Oh, qué debería hacer...!$"
EcruteakCity_Text_Gramps1:
	.string "CIUDAD IRIS solía tener dos torres:\nuna en el este y otra en el oeste.$"
EcruteakCity_Text_Gramps2:
	.string "Ah, criatura. ¿Has aprendido a\nbailar\lcomo las CHICAS KIMONO?\pSi vas a su TEATRO DE DANZA, un\nviejo\lmuy curioso te dará un buen regalo,\lsegún he oído.$"
EcruteakCity_Text_Lass1:
	.string "Voy a practicar al TEATRO DE DANZA.\n¿Te apetece venir conmigo?$"
EcruteakCity_Text_Lass2:
	.string "La torre que solía estar aquí...\pMi abuela me contó que era\nmuchísimo\lmás alta antes del incendio.\pDicen que ahora está llena de\nfantasmas.$"
EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Tres enormes POKéMON salieron\nhuyendo\len distintas direcciones. ¿Qué\leran?$"
EcruteakCity_Text_Fisher:
	.string "He oído un rumor sobre el FARO de\nCIUDAD OLIVO.\pEl POKéMON que sirve de guía\nluminosa\lha caído enfermo. Parece que están\len un\lbuen aprieto.$"
EcruteakCity_Text_Fisher_JasmineReturned:
	.string "¡El POKéMON del FARO de CIUDAD\nOLIVO ya\lestá curado!\pLos barcos pueden navegar de nuevo\ncon\lseguridad por la noche.$"
EcruteakCity_Text_Youngster:
	.string "Dicen que hay POKéMON enfurecidos\nen el\lLAGO DE LA FURIA. ¡Me molaría\lverlo!$"
EcruteakCity_Text_Gramps3:
	.string "En un pasado muy remoto...\pEsta torre ardió en llamas. Tres\nPOKéMON sin nombre perecieron en\lella.\pUn POKéMON con los colores del\narcoíris\lbajó del cielo y les devolvió la\lvida...\pEs una leyenda transmitida por los\nLÍDERES de GIMNASIO de CIUDAD IRIS.\p¿Yo?\pYo fui un gran entrenador en mis\ntiempos\lmozos. ¡Jojojo!$"
EcruteakCity_Text_SageGym:
	.string "El Líder MORTI no está aquí ahora.\nQuizá lo encuentres en la TORRE\lQUEMADA.$"
EcruteakCity_Text_Sign:
	.string "CIUDAD IRIS\nUna Ciudad Histórica\pDonde el Pasado se Funde con el\nPresente$"
EcruteakCity_Text_TinTowerSign:
	.string "TORRE HOJALATA\pDicen que un POKéMON legendario\nanida en\lsu cima.$"
EcruteakCity_Text_OfficeSign:
	.string "Control de Acceso a la TORRE\nHOJALATA\pProhibido el paso a los no dignos.$"
EcruteakCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD IRIS\nLÍDER: MORTI\pEl Vidente Místico del Futuro$"
EcruteakCity_Text_DanceTheaterSign:
	.string "TEATRO DE DANZA DE CIUDAD IRIS$"
EcruteakCity_Text_BurnedTowerSign:
	.string "TORRE QUEMADA\pFue destruida por un misterioso\nfuego.\lPor favor, manténgase alejado por\lsu\lpropia seguridad.$"
