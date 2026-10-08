Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "¡Hola, Entrenador!\n"
	.string "Hoy celebramos el Concurso de\l"
	.string "Captura de Bichos.\p"
	.string "Las reglas son muy sencillas.\p"
	.string "Usando uno de tus POKéMON, atrapa\n"
	.string "un POKéMON bicho para que sea\l"
	.string "calificado.\p"
	.string "¿Te gustaría participar?$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "La EXP que gane tu POKéMON en el\n"
	.string "concurso se restablecerá al salir.\p"
	.string "Aquí tienes las PARQUE BALLS\n"
	.string "para el Concurso.$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "¡{PLAYER} recibió PARQUE BALLS!$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "Quien capture el POKéMON bicho\n"
	.string "más fuerte será el ganador.\p"
	.string "Si te quedas sin PARQUE BALLS,\n"
	.string "habrás terminado tu participación.\p"
	.string "Puedes atrapar hasta 5 POKéMON.\n"
	.string "El último que captures será el\l"
	.string "único que conserves y el que\l"
	.string "compita en el concurso.\p"
	.string "¡Sal ahí fuera y atrapa el bicho\n"
	.string "más formidable que encuentres!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Si llevas más de un POKéMON,\n"
	.string "tendrás que usar el primer POKéMON\l"
	.string "de tu equipo.\p"
	.string "¿Estás de acuerdo?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Perfecto, cuidaremos de tus demás\n"
	.string "POKéMON mientras compites.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "Los POKéMON de {PLAYER} quedaron al\n"
	.string "cuidado del AYUDANTE DEL CONCURSO.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Por favor, pon al frente del equipo\n"
	.string "al POKéMON con el que quieras\l"
	.string "participar y vuelve a hablarme.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "De acuerdo. Esperamos verte en una\n"
	.string "próxima ocasión.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "¡Vaya! El primer POKéMON de tu\n"
	.string "equipo no puede combatir.\p"
	.string "Cámbialo por otro en condiciones y\n"
	.string "vuelve a hablar conmigo.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "¡Vaya! Tienes tanto tu equipo como\n"
	.string "tus CAJAS del PC llenos.\p"
	.string "No te queda sitio para guardar el\n"
	.string "POKéMON bicho que captures.\p"
	.string "Haz hueco en tu equipo o en tus\n"
	.string "cajas y vuelve a verme.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "¡Vaya! Tienes un HUEVO en el\n"
	.string "primer lugar de tu equipo.\p"
	.string "Cámbialo por un POKéMON que pueda\n"
	.string "luchar y vuelve a hablar conmigo.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "El Concurso de hoy ha terminado.\n"
	.string "Esperamos que participes la\l"
	.string "próxima vez.$"
Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "¡Me chiflan los POKéMON pájaro!\n¡Anoche\lencontré un pájaro de tipo\lSINIESTRO\len el parque!$"
Route35NationalParkGate_Text_BC2:
	.string "¡Acabo de atrapar un SCYTHER que te\ncagas de grande!$"
Route35NationalParkGate_Text_Beauty:
	.string "¡Siempre gana él todos los\nconcursos!$"
Route35NationalParkGate_Text_WeHoldContests:
	.string "Celebramos concursos en el PARQUE a\nmenudo. Deberías animarte a probar.$"
Route35NationalParkGate_Text_YoungsterWonders:
	.string "¿Cuándo será el próximo Concurso de\nCaptura de Bichos?$"
Route35NationalParkGate_Text_ContestExplanation:
	.string "El Concurso de Captura de Bichos se\n"
	.string "celebra los martes, jueves y\l"
	.string "sábados.\p"
	.string "No solo te llevas un premio por el\n"
	.string "mero hecho de participar,\p"
	.string "¡sino que además te quedas con el\n"
	.string "bicho que tengas al final!$"
