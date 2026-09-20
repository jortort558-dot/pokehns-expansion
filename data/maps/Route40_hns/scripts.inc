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
	.string "Hay que calentar antes de meterse\nen el agua.\pEso es de primero de natación.$"
Route40_Text_SwimmermSimonBeaten:
	.string "¡Vale! ¡Me rindo! ¡Tú ganas!$"
Route40_Text_SwimmermSimonAfter:
	.string "CIUDAD ORQUÍDEA queda a un buen\ntrecho\lde aquí.$"
Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "¡Oye, se te ve joven y con energía!\p¡Nada de montar en tu POKéMON!\n¡Nada tú!$"
Route40_Text_SwimmermRandallBeaten:
	.string "Vaya... He perdido…$"
Route40_Text_SwimmermRandallAfter:
	.string "Nadar ejercita todo el cuerpo.\nEs sanísimo.$"
Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "¿Te diriges a CIUDAD ORQUÍDEA?\p¿Qué tal un combatazo rápido\nprimero?$"
Route40_Text_SwimmerfElaineBeaten:
	.string "¡Esa la he perdido!$"
Route40_Text_SwimmerfElaineAfter:
	.string "Yo diría que nado mejor que tú.\n¡Sí señor!$"
Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Nada de flotadores para mí.\p¡Mejor me agarro a un POKéMON\nmarino!$"
Route40_Text_SwimmerfPaulaBeaten:
	.string "¡Uy, qué mareo me ha entrado!$"
Route40_Text_SwimmerfPaulaAfter:
	.string "Mientras floto así, las olas me\nllevan\lde aquí para allá.$"
Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Aunque no se distinga desde aquí,\nCIUDAD ORQUÍDEA está al otro lado\ldel\lmar.$"
Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Llegué a OLIVO en barco para hacer\nturismo y disfrutar del\lambientillo.\pAl ser un puerto, se respira algo\nmuy\ldistinto a una gran ciudad.$"
Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "¿Has ido ya a la COLINA DESAFÍO?\pCreo que se han reunido allí un\nmontón\lde Entrenadores muy curtidos.\pPero con tantas MEDALLAS como\ntienes,\lseguro que das la talla de sobra.$"
Route40_Text_Monica:
	.string "LUNA: Encantada de conocerte.\nSoy LUNA, de los HERMANOS DE LOS\lDÍAS.\p¡A que no adivinas cuál es mi día\nfavorito de la semana!$"
Route40_Text_MonicaGivesGift:
	.string "¡Eso es!\p¡En señal de nuestra amistad, tengo\nun regalo para ti!$"
Route40_Text_MonicaGaveGift:
	.string "LUNA: Es un objeto que potencia los\nataques de tipo VOLADOR.\pDeberías equipárselo a un POKéMON\npájaro.$"
Route40_Text_MonicaMonday:
	.string "LUNA: Mis hermanos y hermanas andan\nrepartidos por todas partes.\p¡A ver si logras encontrarlos a\ntodos!$"
Route40_Text_MonicaNotMonday:
	.string "LUNA: Me da a mí que hoy no es\nlunes.\lQué pena…$"
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
