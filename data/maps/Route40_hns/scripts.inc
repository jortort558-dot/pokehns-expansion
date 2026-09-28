Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Hay que calentar antes\nde meterse en el agua.\pEs lo más básico.$"
Route40_Text_SwimmermSimonBeaten:
	.string "¡Vale! ¡Me rindo! ¡Tú ganas!$"
Route40_Text_SwimmermSimonAfter:
	.string "CIUDAD ORQUÍDEA queda bastante\nlejos de aquí.$"
Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "¡Eh, eres joven y estás en forma!\p¡No montes en tu POKéMON!\n¡Ponte a nadar!$"
Route40_Text_SwimmermRandallBeaten:
	.string "Vaya... He perdido…$"
Route40_Text_SwimmermRandallAfter:
	.string "Nadar ejercita todo\nel cuerpo. Es muy sano.$"
Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "¿Vas a CIUDAD ORQUÍDEA?\p¿Qué tal un combate rápido\nantes de irte?$"
Route40_Text_SwimmerfElaineBeaten:
	.string "¡Esa la he perdido!$"
Route40_Text_SwimmerfElaineAfter:
	.string "Diría que nado mejor\nque tú. ¡Sí!$"
Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Yo no necesito flotador.\p¡Me agarro a un POKéMON\nmarino!$"
Route40_Text_SwimmerfPaulaBeaten:
	.string "¡Uy, qué mareo me ha entrado!$"
Route40_Text_SwimmerfPaulaAfter:
	.string "Mientras floto así,\nlas olas me llevan.$"
Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Aunque no se vea desde aquí,\nORQUÍDEA está al otro lado del mar.$"
Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Vine a OLIVO en barco para ver\nla ciudad y disfrutar\ldel ambiente.\pAl ser un puerto, se siente\nmuy distinta de una gran ciudad.$"
Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "¿Has ido a la COLINA\nDESAFÍO?\pCreo que ya se han reunido allí\nmuchos Entrenadores fuertes.\pPero con todas esas MEDALLAS\nseguro que lo harás muy bien.$"
Route40_Text_Monica:
	.string "LUNA: Encantada de conocerte.\nSoy LUNA, de los HERMANOS DEL DÍA.\p¡A que no adivinas cuál es\nmi día favorito de la semana!$"
Route40_Text_MonicaGivesGift:
	.string "¡Correcto!\pComo muestra de nuestra amistad,\n¡tengo un regalo para ti!$"
Route40_Text_MonicaGaveGift:
	.string "LUNA: Este objeto aumenta\nla potencia del tipo VOLADOR.\pDeberías dárselo a un\nPOKéMON pájaro.$"
Route40_Text_MonicaMonday:
	.string "LUNA: Mis hermanos están\nrepartidos por todas partes.\p¡A ver si consigues\nencontrarlos a todos!$"
Route40_Text_MonicaNotMonday:
	.string "LUNA: Creo que hoy no\nes lunes. Qué pena…$"
Route40_Text_MonicaNope:
	.string "Ese no es.$"
Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
