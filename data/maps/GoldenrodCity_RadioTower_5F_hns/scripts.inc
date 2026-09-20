GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "¡T-tú! ¿Has venido a rescatarme?$"
GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "¿Eso era lo que esperabas escuchar?\n¡Pues te equivocas! ¡Soy un\limpostor!\lMe disfracé de DIRECTOR para\lpreparar la toma\lde la torre.\l¿Quieres saber dónde encerramos al\lauténtico?\lClaro que te lo diré. ¡Pero solo si\llogras\lvencerme en combate!$"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "¡Vale, vale! Te diré dónde está.$"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "El jefe encerró al DIRECTOR en los\nALMACENES\lSUBTERRÁNEOS.\lQuedan al fondo del todo del\lSUBTERRÁNEO.\lComo soy un trozo de pan, te daré\lla LLAVE\lDEL SÓTANO para entrar.\lAunque dudo horrores que llegues\lcon vida.$"
GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "El jefe metió al DIRECTOR en los\nALMACENES\lSUBTERRÁNEOS.\lQuedan al fondo del SUBTERRÁNEO.\lPuedes usar la LLAVE DEL SÓTANO\lpara abrir\lla puerta, ¡pero dudo que llegues\ltan lejos!$"
@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "¿Te acuerdas de mí de la GUARIDA de\nPUEBLO\lCAOBA?\lMi jefe me echó una bronca de aúpa,\lpero me he\lvuelto mucho más fuerte.\lPerdí entonces, ¡pero hoy no se\lrepetirá!$"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "¡Esto no puede estar pasando!\nHe luchado con todo... y aun así\lperdí…\lPerdóneme, señor GIOVANNI…$"
GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "Te llamas {PLAYER}, ¿cierto?\nUn mico como tú jamás comprenderá\lla grandeza\ldel TEAM ROCKET.\lEs una lástima. Admiro tu fuerza.$"
GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "¿Oh? ¿Has logrado llegar hasta aquí\narriba?\lSin duda eres un Entrenador\lformidable.\lPretendemos tomar esta EMISORA DE\lRADIO para\lproclamar nuestro triunfal regreso.\lEso hará que nuestro líder GIOVANNI\lregrese de\lsu entrenamiento en soledad.\l¡Recuperaremos nuestra antigua\lgloria...!\l¡No consentiré que arruines\lnuestros minuciosos\lplanes!$"
GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "¡No! ¡Perdóname, señor GIOVANNI!$"
GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "¿Cómo ha podido suceder esto?\nNuestros anhelos se han esfumado en\lla nada.\lAl final no estuve a la altura del\lcargo.\lTal y como hizo GIOVANNI en su día,\lhoy disuelvo\lal TEAM ROCKET de forma definitiva.\lAdiós.$"
GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTOR: ¡{PLAYER}, muchísimas\ngracias!\lTu coraje y valentía han salvado a\llos\lPOKéMON de todo el país.\lSé que no es gran cosa, pero por\lfavor quédate\lcon esto.$"
GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Antiguamente se alzaba una torre\naquí mismo\len CIUDAD TRIGAL.\lPero era vetusta y crujía entera.\lAsí que la sustituimos por la TORRE\lRADIO.\lExcavamos esa pluma durante las\lobras.\lDicen que antaño convivían toda\lclase de\lPOKéMON en TRIGAL.\lQuizás... esa pluma guarde relación\lcon la\lTORRE HOJALATA de CIUDAD IRIS…\lBueno, será mejor que regrese a mi\lDESPACHO.$"
GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Antiguamente se alzaba una torre\naquí mismo\len CIUDAD TRIGAL.\lPero era muy vieja y crujía entera.\lAsí que la sustituimos por la TORRE\lRADIO.\lExcavamos esa pluma durante las\lobras.\lDicen que antaño convivían toda\lclase de\lPOKéMON en TRIGAL.\lQuizás... esa pluma tenga conexión\lcon las\lISLAS REMOLINO cerca de CIUDAD\lORQUÍDEA…\lBueno, será mejor que vuelva a mi\lDESPACHO.$"
GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "¡Ah!\nEso me recuerda…\lEsa pluma que te di... creo que\lguarda\lrelación con el POKéMON LEGENDARIO.\l¡Pero el LEGENDARIO no se mostrará\lsolo con\lla pluma...!\lAl parecer hace falta algo más... O\lalgo así.\lMe pregunto qué sería... Ya no me\lacuerdo.$"
GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "¿Esperabas algo? A esto lo llaman\nSORPRESA.\lDe verdad tengo que volver a mi\lDESPACHO.\l¡Nos vemos!$"
GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTOR: ¡Hola, {PLAYER}!\nMe apasionan los POKéMON.\lConstruí esta TORRE RADIO para\lproclamar mi\lamor hacia ellos por las ondas.\lSería maravilloso que la gente\ldisfrute con\lnuestra programación.$"
GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN: ¿Escuchas nuestra música?$"
GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5P DESPACHO DEL DIRECTOR$"
GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5P ESTUDIO 1$"
