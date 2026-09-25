Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end

Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "CUEVA OSCURA…\p"
	.string "Si un POKéMON pudiera iluminarla,\n"
	.string "entraría a explorarla.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "¡He atrapado un montón de POKéMON!\n"
	.string "¡Échate un combate conmigo!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "¡Ayyy!$"

Route31_Text_BugCatcherWade1_After:
	.string "Puedes atrapar POKéMON aunque ya\n"
	.string "lleves seis contigo.\p"
	.string "Si atrapas uno más, se enviará\n"
	.string "directo a tu CAJA del PC.$"

Route31_Text_SleepyMan:
	.string "… Mmmf… ¿Eh?\p"
	.string "He andado demasiado hoy buscando\n"
	.string "POKéMON.\p"
	.string "Me duelen los pies y tengo sueño…\p"
	.string "Si yo fuera un POKéMON salvaje,\n"
	.string "sería facilísimo atraparme…\p"
	.string "… Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "… Zzzz… ¿Eh?\p"
	.string "¿Qué es eso? ¿Tienes una CARTA\n"
	.string "para mí?$"

Route31_Text_SleepyManFail:
	.string "… Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} entregó el POKéMON\n"
	.string "que llevaba la CARTA.$"

Route31_Text_ReadingMail:
	.string "A ver qué dice…\p"
	.string "¡Muchas gracias por traérmelo!\p"
	.string "Mi colega es un fenómeno, ¡y tú\n"
	.string "también eres de fiar!\p"
	.string "¡Quiero darte algo a cambio!\p"
	.string "¡Ya sé! ¡Toma esto!$"

Route31_Text_DescribeRest:
	.string "… Zzz…\p"
	.string "… Mmm… ¡Descanso!\p"
	.string "Descansar sirve para recuperar\n"
	.string "fuerzas al instante, ¿sabes?\p"
	.string "Con este movimiento te duermes y\n"
	.string "recuperas todos tus PS.$"

Route31_Text_WrongMail:
	.string "Esta CARTA no es para mí.$"

Route31_Text_MissingMail:
	.string "¿Por qué es tan especial este\n"
	.string "POKéMON?\p"
	.string "¡Si no lleva ninguna CARTA!$"

Route31_Text_DeclinedToHandOverMail:
	.string "¿Cómo? ¿No quieres nada?$"

Route31_Text_CantTakeLastMon:
	.string "Si te quito ese POKéMON,\p"
	.string "¿con qué vas a luchar luego?$"

Route31_Text_Youngster:
	.string "Encontré un buen POKéMON dentro de\n"
	.string "la CUEVA OSCURA.\p"
	.string "Voy a entrenarlo a tope para vencer\n"
	.string "a PEGASO.\p"
	.string "¡Es el LÍDER de GIMNASIO de\n"
	.string "CIUDAD MALVA!$"

Route31_Text_Sign:
	.string "RUTA 31\p"
	.string "CIUDAD MALVA - PUEBLO CEREZO$"

Route31_Text_WadeRegister:
	.string "¡Eres genial! ¡Me caes bien!\p"
	.string "Vengo aquí a buscar POKéMON todos\n"
	.string "los días.\p"
	.string "Y entre la hierba siempre encuentro\n"
	.string "todo tipo de BAYAS.\p"
	.string "Si te apetece, puedo darte\n"
	.string "algunas cuando encuentre.$"

Route31_Text_WadeRematchIntro:
	.string "¡Te estaba esperando!\n"
	.string "¡A combatir!$"

Route31_Text_WadeRematchDefeat:
	.string "¡Ayyy!$"

Route31_Text_WadePostRematch:
	.string "¡Te daré un toque por el POKéGEAR\n"
	.string "en cuanto encuentre algo que te\lmole!$"

Route31_Text_WadeHasItem:
	.string "¡Eh! ¡Te estaba buscando!\p"
	.string "He encontrado algo chulo mientras\n"
	.string "miraba por la hierba.\p"
	.string "¡Toma, para ti!$"

Route31_Text_WadeGaveItem:
	.string "¡Te aviso si encuentro alguna otra\n"
	.string "cosa!$"

Route31_Text_WadeNoRoom:
	.string "Mmm, parece que llevas la BOLSA\n"
	.string "a rebosar.\p"
	.string "¡Vuelve cuando tengas sitio!$"

Route31_Text_DarkCaveSign:
	.string "CUEVA OSCURA$"
