Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANA: ¡ANA y yo formamos el equipo\n"
	.string "perfecto!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANA Y ANITA: Mmm… Eres demasiado\n"
	.string "fuerte…$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANA: Sé exactamente qué piensan mi\n"
	.string "hermana y mis POKéMON.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANITA: ¡ANA y yo luchamos siempre\n"
	.string "unidas!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANA Y ANITA: Mmm… Eres demasiado\n"
	.string "fuerte…$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANITA: Compartimos el mismo corazón\n"
	.string "que nuestros POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "Un POKéMON dormido está indefenso.\p"
	.string "¡Te demostraré lo temible que\n"
	.string "resulta!$"

Route37_Text_PsychicGreg_Beaten:
	.string "He perdido. Qué desilusión…$"

Route37_Text_PsychicGreg_After:
	.string "Dormir o paralizar al rival son\n"
	.string "tácticas fundamentales en combate.$"

Route37_Text_Sunny_Meet:
	.string "DOMINGO: ¡Hola!\p"
	.string "¡Soy DOMINGO, de la familia\nsemanal!\p"
	.string "Si adivinas mi día favorito, ¡te\n"
	.string "daré un premio estupendo!$"

Route37_Text_Sunny_GiveGift1:
	.string "¡Me dijeron que te entregara esto\n"
	.string "en cuanto te viera!$"

Route37_Text_Sunny_GiveGift2:
	.string "¡Me dijeron que te entregara esto\nen\l"
	.string "cuanto te viera!$"

Route37_Text_Sunny_GaveGift:
	.string "DOMINGO: Ese trasto…\p"
	.string "Esto…\p"
	.string "¿Cómo era…?\p"
	.string "¡Ah, ya me acuerdo!\p"
	.string "Dáselo a un POKéMON con ataques\n"
	.string "eléctricos.\p"
	.string "¡Mi hermana MÓNICA dice que el IMÁN\n"
	.string "potencia los ataques de tipo\lELÉCTRICO!$"

Route37_Text_Sunny_Sunday:
	.string "DOMINGO: Mis hermanos son MÓNICA,\n"
	.string "TOSCANA, MIGUEL, ARTURO, VIERNES y\l"
	.string "SANTOS.\p"
	.string "¡Todos son mayores que yo!$"

Route37_Text_Sunny_NotSunday:
	.string "DOMINGO: ¿Hoy no es domingo?\n"
	.string "Mmm… ¡Se me había olvidado!$"

Route37_Text_Sign:
	.string "RUTA 37\n"
	.string "CIUDAD IRIS MÁS ADELANTE$"
