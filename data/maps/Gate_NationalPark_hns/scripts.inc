Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	special CheckAndResetSaturdayWeeklyCaptures
	goto_if_set FLAG_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
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
	special CheckAndResetSaturdayWeeklyCaptures
	goto_if_set FLAG_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
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
	.string "¡Oíd, noble aventurero!\n"
	.string "Hoy se celebra el grandioso\l"
	.string "Concurso de Caza de Bichos.\p"
	.string "Pero ojo al piojo: las normas\n"
	.string "son sagradas y estrictas.\p"
	.string "Solo se permite una incursión\n"
	.string "por sábado en el concurso.\p"
	.string "Entras con un solo POKéMON y\n"
	.string "lo que caces, tuyo será.\p"
	.string "¿Tientas a la suerte o te\n"
	.string "bates en retirada?$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "La EXP cosechada dentro no te\n"
	.string "valdrá al salir, ¡sin trampas!\p"
	.string "Toma estas 30 PARQUE BALLS.\n"
	.string "¡Gástalas bien, tunante!$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "¡{PLAYER} recibió PARQUE BALLS!$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "El bicho más gordo y pintón que\n"
	.string "atrapes te dará la gloria.\p"
	.string "Si agotas tus BALLS, a la calle.\n"
	.string "Caza varios, pero solo el último\l"
	.string "quedará en tu poder.\p"
	.string "¡Y hasta el próximo sábado no\n"
	.string "habrá otra oportunidad!\l"
	.string "¡Que la musa te bendiga!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Solo pasas con el primer\n"
	.string "POKéMON de tu equipo.\p"
	.string "¿Te fías de tus dotes con él?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "¡Perfecto! Yo vigilaré a tus\n"
	.string "camaradas mientras danzas entre\l"
	.string "orugas y saltamontes.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "Los POKéMON de {PLAYER} quedaron\n"
	.string "a buen recaudo del ENCARGADO.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Pon al frente a tu campeón y\n"
	.string "vuelve a hablar conmigo.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "¡Ja! Una retirada a tiempo es\n"
	.string "victoria. ¡Vuelve si te animas!$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "¡Caramba! ¡Ese primer bicho tuyo\n"
	.string "está tieso como una tabla!\p"
	.string "Cúralo un poco antes de meterte\n"
	.string "al fregado, alma cándida.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "¡Criatura, si llevas las bolsas\n"
	.string "y cajas a punto de reventar!\p"
	.string "No te cabe ni una pulga.\n"
	.string "Haz sitio y vuelve a verme.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "¡Por favor! ¿Pretendes cazar\n"
	.string "bichos con un HUEVO?\p"
	.string "Pon a un POKéMON despierto o el\n"
	.string "espectáculo será de risa.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "¡Alto ahí, tragaldabas!\n"
	.string "Ya quemaste tu cartucho de hoy.\p"
	.string "No hay segundas vueltas hasta\n"
	.string "el próximo sábado.\l"
	.string "¡A pasear a otra parte, pillín!$"


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
