BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	setflag FLAG_BUG_CONTEST_COMPLETED
	setflag FLAG_DAILY_BUG_CONTEST_COMPLETED
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
	.string "El concurso ha concluido.\n"
	.string "Elige el POKéMON que deseas\l"
	.string "conservar para la evaluación.$"

BugContest_Text_Judging1::
	.string "¡Procederemos a evaluar los\n"
	.string "POKéMON que habéis atrapado!\p"
	.string "………………………\n"
	.string "………………………\p"
	.string "¡Ya tenemos a los ganadores!\n"
	.string "¿Listos para el veredicto?$"

BugContest_Text_WrongChoiceMon:
	.string "Por favor, selecciona el POKéMON\n"
	.string "que conservarás para el jurado.$"

BugContest_Text_DidntCatch:
	.string "¡Vaya por Dios! No has atrapado\n"
	.string "ningún POKéMON en el parque.\p"
	.string "Quedas descalificado, bribón.\n"
	.string "Te devuelvo tu equipo entero.$"

BugContest_Text_TimesUp:
	.string "¡Din-don! ¡Tiempo cumplido!$"

BugContest_Text_WhiteOut:
	.string "¡A {PLAYER} no le quedan más\n"
	.string "POKéMON para seguir luchando!\p"
	.string "Quedas fuera del concurso.$"

BugContest_Text_First1:
	.string "En tercer lugar queda la\n"
	.string "GUAY BELINDA, ¡con un\l"
	.string "vivaracho BUTTERFREE!$"

BugContest_Text_First2:
	.string "En segundo lugar queda el\n"
	.string "CAZABICHOS SHAUN, ¡con un\l"
	.string "formidable PINSIR!$"

BugContest_Text_First3:
	.string "Y el gran vencedor del Concurso\n"
	.string "de Caza de Bichos es…\p"
	.string "¡{PLAYER}, con este gran\n"
	.string "{STR_VAR_1}!$"

BugContest_Text_Second1:
	.string "En tercer lugar queda la\n"
	.string "GUAY BELINDA, ¡con un\l"
	.string "vivaracho BUTTERFREE!$"

BugContest_Text_Second2:
	.string "En segundo lugar queda {PLAYER},\n"
	.string "¡con este gran {STR_VAR_1}!$"

BugContest_Text_Second3:
	.string "Y el gran vencedor del Concurso\n"
	.string "de Caza de Bichos es…\p"
	.string "¡El CAZABICHOS SHAUN, con un\n"
	.string "colosal PINSIR!$"

BugContest_Text_Third1:
	.string "En tercer lugar queda {PLAYER},\n"
	.string "¡con su fiel {STR_VAR_1}!$"

BugContest_Text_Third2:
	.string "En segundo lugar queda la\n"
	.string "GUAY BELINDA, ¡con un\l"
	.string "vivaracho BUTTERFREE!$"

BugContest_Text_Third3:
	.string "Y el gran vencedor del Concurso\n"
	.string "de Caza de Bichos es…\p"
	.string "¡El CAZABICHOS SHAUN, con un\n"
	.string "colosal PINSIR!$"

BugContest_Text_TakePartInFuture:
	.string "¡Muchas gracias por participar!\n"
	.string "¡Hasta la próxima, fiera!$"

BugContest_Text_TransferAndReturn:
	.string "Tu POKéMON bicho se enviará a tu\n"
	.string "PC y recuperarás tu equipo.$"


