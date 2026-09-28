Route17_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY_HNS, Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten, Route17_EventScript_RegisterRiley
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchRiley
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterRiley::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_RileyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RILEY_HNS
	release
	end

Route17_EventScript_RematchRiley::
	trainerbattle_rematch TRAINER_RILEY_HNS, Route17_Text_RileyRematchIntro, Route17_Text_RileyRematchDefeat
	msgbox Route17_Text_RileyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_RILEY_2_HNS, Route17_EventScript_RematchRileyTryGiveItem
	end

Route17_EventScript_RematchRileyTryGiveItem::
	checkitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_TOXIC
	closemessage
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL_HNS, Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten, Route17_EventScript_RegisterJoel
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchJoel
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterJoel::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_JoelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEL_HNS
	release
	end

Route17_EventScript_RematchJoel::
	trainerbattle_rematch TRAINER_JOEL_HNS, Route17_Text_JoelRematchIntro, Route17_Text_JoelRematchDefeat
	msgbox Route17_Text_JoelPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_JOEL_2_HNS, Route17_EventScript_RematchJoelTryGiveItem
	end

Route17_EventScript_RematchJoelTryGiveItem::
	checkitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BRICK_BREAK
	closemessage
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN_HNS, Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES_HNS, Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten, Route17_EventScript_RegisterCharles
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route17_EventScript_RematchCharles
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RegisterCharles::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route17_Text_CharlesRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHARLES_HNS
	release
	end

Route17_EventScript_RematchCharles::
	trainerbattle_rematch TRAINER_CHARLES_HNS, Route17_Text_CharlesRematchIntro, Route17_Text_CharlesRematchDefeat
	msgbox Route17_Text_CharlesPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CHARLES_2_HNS, Route17_EventScript_RematchCharlesTryGiveItem
	end

Route17_EventScript_RematchCharlesTryGiveItem::
	checkitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_BULK_UP
	closemessage
	end

Route17_Text_BikerRileySeen:
	.string "¡Eh! Eres de JOHTO, ¿no?$"

Route17_Text_BikerRileyBeaten:
	.string "¡Vaya, pegas fuerte!$"

Route17_Text_BikerRileyAfterBattle:
	.string "¡No te flipes, macarra de JOHTO!$"

Route17_Text_BikerJoelSeen:
	.string "¡Qué BICI tan chula!$"

Route17_Text_BikerJoelBeaten:
	.string "Pero no solo lo pareces…$"

Route17_Text_BikerJoelAfterBattle:
	.string "Pareceré guay, pero soy débil,\n"
	.string "así que no lo soy de verdad.\p"
	.string "Tengo que entrenar más…$"

Route17_Text_BikerGlennSeen:
	.string "¡Eh! ¿Echamos una batalla veloz?$"

Route17_Text_BikerGlennBeaten:
	.string "¡Uf! ¡Tienes una fuerza brutal!$"

Route17_Text_BikerGlennAfterBattle:
	.string "Ir sin manos se considera guay\n"
	.string "en el CARRIL BICI.$"

Route17_Text_BikerCharlesSeen:
	.string "¡Somos estrellas sin miedo!$"

Route17_Text_BikerCharlesBeaten:
	.string "¡Aaarg! ¡Me he estampado!$"

Route17_Text_BikerCharlesAfterBattle:
	.string "¡Conducir a lo loco causa\n"
	.string "accidentes! ¡Ve con calma!$"

Route17_Text_RileyRegister:
	.string "¡Nada mal para alguien de JOHTO!$"

Route17_Text_RileyRematchIntro:
	.string "¡Los de JOHTO solo ganáis una vez!$"

Route17_Text_RileyRematchDefeat:
	.string "Me has dado una paliza…$"

Route17_Text_RileyPostRematch:
	.string "Quizá debería entrenar en JOHTO\n"
	.string "después de todo.$"

Route17_Text_JoelRegister:
	.string "¡Al final sí que molas!\n"
	.string "¡Intercambiemos números!$"

Route17_Text_JoelRematchIntro:
	.string "¡Veamos quién mola más ahora!$"

Route17_Text_JoelRematchDefeat:
	.string "Aún no molo lo suficiente…$"

Route17_Text_JoelPostRematch:
	.string "¡Seguiré entrenando para molar\n"
	.string "tanto como tú!$"

Route17_Text_CharlesRegister:
	.string "¡Rompes corazones como yo!\n"
	.string "¡Dame tu número!$"

Route17_Text_CharlesRematchIntro:
	.string "No soy solo el rey de la carretera,\n"
	.string "¡también rompo corazones!$"

Route17_Text_CharlesRematchDefeat:
	.string "¡Me he vuelto a estrellar!$"

Route17_Text_CharlesPostRematch:
	.string "Vi a alguien como tú en TESELIA.\n"
	.string "¡No te estampes!$"
