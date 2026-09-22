Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Estoy haciendo los preparativos\n"
    .string "finales para la LIGA POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "¡Lo he fastidiado!$"

Route26_Text_CooltrainermJakeAfter:
    .string "Será difícil ganar en la LIGA.\p"
    .string "Necesito entrenar un poco más.\p"
    .string "Dicen que el ALTO MANDO es más\n"
    .string "fuerte que los LÍDERES de GIMNASIO.$"

Route26_Text_CooltrainermGavenSeen:
    .string "Los combates difíciles hacen\n"
    .string "que te vuelvas más fuerte.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "¡Aaah! ¡La vida es aún más dura!$"

Route26_Text_CooltrainermGavenAfter:
    .string "Para llegar a la LIGA POKéMON debes\n"
    .string "cruzar la CALLE VICTORIA.\p"
    .string "Pero es muy dura.\n"
    .string "¡Casi nadie se aventura allí!$"

Route26_Text_GavenRegister:
    .string "Para llegar a la LIGA POKéMON debes\n"
    .string "cruzar la CALLE VICTORIA.\p"
    .string "Pero es muy dura.\n"
    .string "¡Casi nadie se aventura allí!$"

Route26_Text_GavenRematchIntro:
    .string "Los combates difíciles hacen\n"
    .string "que te vuelvas más fuerte.$"

Route26_Text_GavenRematchDefeat:
    .string "¡Aaah! ¡La vida es aún más dura!$"

Route26_Text_GavenPostRematch:
    .string "Para llegar a la LIGA POKéMON debes\n"
    .string "cruzar la CALLE VICTORIA.\p"
    .string "Pero es muy dura.\n"
    .string "¡Casi nadie se aventura allí!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Si has llegado tan lejos,\n"
    .string "debes de ser bueno.\p"
    .string "¡Lo daré todo en este combate!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "¡No! ¡No me lo puedo creer!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "He derrotado a ocho LÍDERES,\n"
    .string "así que tenía mucha confianza.\p"
    .string "La próxima vez me esforzaré más.$"

Route26_Text_CooltrainerfBethSeen:
    .string "Perdí contra un tal {RIVAL}.\p"
    .string "Era muy fuerte, pero parecía\n"
    .string "dispuesto a ganar a toda costa.\p"
    .string "Sentí pena por sus POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "Los POKéMON no son armas.$"

Route26_Text_CooltrainerfBethAfter:
    .string "Los POKéMON son compañeros\n"
    .string "inestimables para toda la vida.$"

Route26_Text_BethRegister:
    .string "Los POKéMON son compañeros\n"
    .string "inestimables para toda la vida.$"

Route26_Text_BethRematchIntro:
    .string "Perdí contra un tal {RIVAL}.\p"
    .string "¡Pero no perderé contra ti!$"

Route26_Text_BethRematchDefeat:
    .string "Los POKéMON no son armas.$"

Route26_Text_BethPostRematch:
    .string "Los POKéMON son compañeros\n"
    .string "inestimables para toda la vida.$"

Route26_Text_PsychicRichardSeen:
    .string "¡Vaya, cuántas MEDALLAS!\n"
    .string "Estoy impresionado.\p"
    .string "Pero no te basta con reunirlas,\n"
    .string "¿verdad?$"

Route26_Text_PsychicRichardBeaten:
    .string "¡Buen combate!$"

Route26_Text_PsychicRichardAfter:
    .string "Las personas y los POKéMON crecen\n"
    .string "gracias a sus experiencias.\p"
    .string "No te vuelvas vago ni conformista.$"

Route26_Text_Sign:
    .string "RUTA 26\p"
    .string "ACCESO A LA LIGA POKéMON$"
