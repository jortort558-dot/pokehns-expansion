TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "¡Hum! ¡Hum!\p"
	.string "¡Por fin has venido!\n"
	.string "¡Sí, has llegado!\p"
	.string "¡Espera! ¡No digas nada!\n"
	.string "¡Sé por qué has recorrido todo el\l"
	.string "camino hasta aquí en solitario!\p"
	.string "Querías verme a mí, el dueño de\n"
	.string "COLINA DESAFÍO, porque…\p"
	.string "¡Quieres formar pareja conmigo!\n"
	.string "¡Yuju!\p"
	.string "…¿Eh?\n"
	.string "¿No es eso?\p"
	.string "En fin, te vi durante el ascenso.\n"
	.string "¡Unos combates magníficos! ¡Bravo!$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "Para alguien tan magnífico como tú,\n"
	.string "tengo el regalo más magnífico,\l"
	.string "¡y dinero por tu esfuerzo!$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "¡Oh, no, no te cabe nada más!\n"
	.string "¡Vuelve luego a por esto!$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "¡Oh, espera! ¿Acaso has llegado\n"
	.string "hasta aquí a velocidad increíble?\p"
	.string "¡Qué maravilla! ¡No tenías que\n"
	.string "correr tanto para verme!\p"
	.string "Qué alegría. ¡Haré que actualicen\n"
	.string "el Panel de Tiempos de recepción!$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "Pero, vaya…\n"
	.string "No has llegado muy rápido.$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "Quizá me alegres más si la próxima\n"
	.string "vez llegas a toda velocidad.\p"
	.string "¡Entonces formaré pareja contigo\n"
	.string "con mucho gusto!\p"
	.string "¡Hasta la próxima, amigo!$"
