GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "BLANCA: ¡Hola!\p"
	.string "¡Me llamo BLANCA!\p"
	.string "Oí hablar del CONCURSO para ganar\nuna\l"
	.string "TARJETA RADIO y vine a por una…\p"
	.string "¡Pero las preguntas son\ndificilísimas!$"

RadioTower1F_Text_Whitney2::
	.string "BLANCA: ¡Hala! ¡Lo has conseguido!\p"
	.string "¡Pues yo estaba convencida de que\nla\l"
	.string "tercera pregunta era falsa!\l"
	.string "¡Vaya metedura de pata!\p"
	.string "¡Bueno, me vuelvo al GIMNASIO!$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "¡Te damos la bienvenida!$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "Hola. Lo lamentamos, pero hoy no\n"
    .string "ofrecemos visitas guiadas.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "Tenemos una campaña especial de\n"
    .string "PREGUNTAS ahora mismo.\p"
    .string "Si aciertas cinco preguntas,\n"
    .string "ganarás una TARJETA RADIO para el\l"
    .string "POKéGEAR.\p"
    .string "Podréis escuchar música POKéMON en\n"
    .string "cualquier lugar y momento.\p"
    .string "¿Quieres participar en el CONCURSO?$"

RadioTower1F_Text_QuizQuestion1:
    .string "Pregunta 1:\p"
    .string "¿Hay POKéMON que solo aparecen\n"
    .string "durante el día?$"

RadioTower1F_Text_QuizQuestion2:
    .string "¡Correcto!\n"
    .string "Pregunta 2:\p"
    .string "¿Es correcta esta afirmación?\p"
    .string "No se pueden comprar BAYAS en las\n"
    .string "TIENDAS POKéMON ordinarias.$"

RadioTower1F_Text_QuizQuestion3:
    .string "¡En el clavo!\n"
    .string "Pregunta 3:\p"
    .string "¿CÉSAR, el artesano de Poké Balls,\n"
	.string "utiliza BONGURIS como material?$"

RadioTower1F_Text_QuizQuestion4:
    .string "¡Vas por buen camino!\n"
    .string "Pregunta 4:\p"
    .string "¿Es PEGASO el LÍDER de MALVA y\n"
    .string "combate con POKéMON pájaro?$"

RadioTower1F_Text_QuizQuestion5:
    .string "¡Increíble, pleno de aciertos!\n"
    .string "La última pregunta:\p"
    .string "¿Aparece CHARMANDER en los rodillos\n"
    .string "de las tragaperras del CASINO de\l"
    .string "CIUDAD TRIGAL?$"

RadioTower1F_Text_QuizWin:
    .string "¡Bingo! ¡Lo has bordado!\n"
    .string "¡Enhorabuena!\p"
    .string "¡Aquí tienes tu premio, la TARJETA\n"
    .string "RADIO!$"

RadioTower1F_Text_PokegearRadio:
    .string "¡El POKéGEAR de {PLAYER} ahora\n"
    .string "sintoniza la RADIO!$"

RadioTower1F_Text_TuneIn:
    .string "¡No te pierdas nuestros programas\nde\l"
    .string "radio!$"

RadioTower1F_Text_WrongAnswer:
    .string "Vaya por Dios.\n"
    .string "Has fallado la pregunta.\p"
    .string "¡Inténtalo de nuevo!$"

RadioTower1F_Text_DeclineQuiz:
    .string "Comprendo. Avísame si cambias de\n"
    .string "opinión.$"

RadioTower1F_Text_Lass:
    .string "BEN es un locutor fabuloso.\p"
    .string "¡Su voz tan dulce me derrite!$"

RadioTower1F_Text_Youngster:
    .string "Me encanta ROSA, de la HORA\nPOKéMON.\p"
    .string "Aunque solo conozco cómo suena su\n"
    .string "voz por las ondas.$"

RadioTower1F_Text_GruntM3Seen:
    .string "¡Por fin hemos tomado la TORRE\n"
    .string "RADIO!\p"
    .string "¡Ahora todos conocerán el auténtico\n"
    .string "terror del TEAM ROCKET!\p"
    .string "¡Verás lo peligrosos que somos!$"

RadioTower1F_Text_GruntM3Beaten:
    .string "¡Demasiado fuerte! Perdón, jefe…$"

RadioTower1F_Text_GruntM3After:
    .string "Eres demasiado fuerte.\p"
    .string "Nuestro plan corre peligro. Debo\n"
    .string "avisar a los demás…$"

RadioTower1F_Text_Directory:
    .string "P1 RECEPCIÓN\n"
    .string "P2 VENTAS\p"
    .string "P3 PERSONAL\n"
    .string "P4 PRODUCCIÓN\p"
    .string "P5 DESPACHO DEL DIRECTOR$"

RadioTower1F_Text_GotRadio:
	.string "¡{PLAYER} recibió la TARJETA RADIO\n"
	.string "para el POKéGEAR!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Este es el RINCÓN DE LA LOTERÍA.\p"
	.string "Si el número del boleto coincide\n"
	.string "con el ID de uno de tus POKéMON,\l"
	.string "recibirás un regalo fabuloso.\p"
	.string "¿Quieres sacar un boleto?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Vuelve mañana, por favor.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "¡Esperamos volver a verte!$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Elige un boleto de lotería.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}"
	.string "{PAUSE 0x0F}{PAUSE 0x0F}…"
	.string "{PAUSE 0x0F}{PAUSE 0x0F}"
	.string "{PAUSE 0x0F}{PAUSE 0x0F}…"
	.string "{PAUSE 0x0F}{PAUSE 0x0F}"
	.string "{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "El boleto tiene el número\n"
	.string "{STR_VAR_1}.\p"
	.string "Comprobaré si coincide con el ID\n"
	.string "de alguno de tus POKéMON. Espera.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "¡Enhorabuena!\p"
	.string "¡El ID de {STR_VAR_1}, que está en\n"
	.string "tu equipo, coincide con el boleto!$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "¡Enhorabuena!\p"
	.string "¡El ID de {STR_VAR_1}, guardado en\n"
	.string "el PC, coincide con el boleto!$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Lo siento.\n"
	.string "No ha coincidido ningún número.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "¡Han coincidido dos cifras!\n"
	.string "¡Ganas el tercer premio:\l"
	.string "{STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "¡Han coincidido tres cifras!\n"
	.string "¡Ganas el segundo premio:\l"
	.string "{STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "¡Han coincidido cuatro cifras!\n"
	.string "¡Ganas el primer premio:\l"
	.string "{STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "¡Madre mía! ¡Han coincidido las\n"
	.string "cinco cifras!\p"
	.string "¡Has ganado el premio gordo:\n"
	.string "{STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "¿Eh?\n"
	.string "Parece que no tienes sitio.\p"
	.string "Haz hueco en la BOLSA y avísame.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "¿{PLAYER}?\n"
	.string "Sí, te estaba esperando.\p"
	.string "Este es el premio que guardábamos\n"
	.string "para ti.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "¡Esperamos volver a verte!$"
