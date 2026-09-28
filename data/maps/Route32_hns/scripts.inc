Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "¡Espera un momento!\n"
	.string "¿A dónde vas con tantas prisas?$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "¿Eres {PLAYER}, verdad?\n"
	.string "Un señor con gafas\p"
	.string "te estaba buscando.\p"
	.string "Ve a comprobarlo tú mismo. Te está\n"
	.string "esperando en el CENTRO POKéMON.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "¿Ya has visitado la\n"
	.string "TORRE BELLSPROUT?\p"
	.string "Si pasas por CIUDAD MALVA,\n"
	.string "se espera que entrenes allí.\l"
	.string "Es básico para todo entrenador.\p"
	.string "¡Pásate por la TORRE BELLSPROUT!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "¿Has ido ya al GIMNASIO POKéMON?\p"
	.string "Allí podrás poner a prueba\n"
	.string "a tus POKéMON y a ti mismo.\p"
	.string "¡Es el rito de iniciación\n"
	.string "de todo entrenador!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "¡Llevas unos POKéMON muy bien\n"
	.string "cuidados!\l"
	.string "Se nota que has entrenado duro\l"
	.string "por CIUDAD MALVA.\p"
	.string "El entrenamiento del GIMNASIO\n"
	.string "debió de ayudarte mucho. Como\l"
	.string "recuerdo de MALVA, ¡toma esto!\p"
	.string "Potencia los movimientos de\n"
	.string "tipo PLANTA.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Lo vivido en CIUDAD MALVA\n"
	.string "te servirá mucho a lo largo\l"
	.string "de tu viaje.$"

Route32_Text_SlowpokeTailOffer:
	.string "¿Te hace una rica y nutritiva\n"
	.string "COLASLOWPOKE recién cortada?\p"
	.string "¡Para ti ahora mismo por solo\n"
	.string "1.000.000 ¥!\p"
	.string "¡Seguro que la quieres!$"

Route32_Text_ThoughtKidsLoaded:
	.string "¡Tch! ¡Creía que los mocosos de hoy\n"
	.string "en día estaban forrados!$"

Route32_Text_RefusedSlowpokeTail:
	.string "¿No la quieres?\n"
	.string "¡Pues aire, pringao! ¡Largo!$"

Route32_Text_FisherJustin_Seen:
	.string "¡Hala!\p"
	.string "¡Por tu culpa se me escapó el pez!$"

Route32_Text_FisherJustin_Beaten:
	.string "¡Chof!$"

Route32_Text_FisherJustin_After:
	.string "Calma y sosiego… La pesca y los\n"
	.string "POKéMON requieren\l"
	.string "la misma paciencia.$"

Route32_Text_FisherRalph1_Seen:
	.string "Se me da de fábula pescar y criar\n"
	.string "POKéMON.\p"
	.string "¡No pienso perder contra un crío!$"

Route32_Text_FisherRalph1_Beaten:
	.string "¡Rayos! Me apresuré demasiado…$"

Route32_Text_FisherRalph1_After:
	.string "La pesca es una pasión eterna.\p"
	.string "¡Y los POKéMON, amigos para\nsiempre!$"

Route32_Text_RalphRegister:
	.string "La pesca es una pasión eterna.\p"
	.string "¡Y los POKéMON, amigos para\nsiempre!$"

Route32_Text_RalphRematchIntro:
	.string "Se me da de fábula pescar y criar\n"
	.string "POKéMON.\p"
	.string "¡No pienso perder contra un crío!$"

Route32_Text_RalphRematchDefeat:
	.string "¡Rayos! Me apresuré demasiado…$"

Route32_Text_RalphPostRematch:
	.string "La pesca es una pasión eterna.\p"
	.string "¡Y los POKéMON, amigos para\nsiempre!$"

Route32_Text_FisherHenry_Seen:
	.string "¿Mis POKéMON? ¡Recién pescados!$"

Route32_Text_FisherHenry_Beaten:
	.string "¿SALPICADURA?$"

Route32_Text_FisherHenry_After:
	.string "Un equipo recién pescado no puede\n"
	.string "rivalizar con uno bien entrenado.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "No te había visto antes por aquí.\n"
	.string "¿Te crees muy duro o qué?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "¡Eres increíblemente fuerte!$"

Route32_Text_YoungsterAlbert_After:
	.string "Quiero llegar a lo más alto con mis\n"
	.string "favoritos, sin copiar al resto.$"

Route32_Text_YoungsterGordon_Seen:
	.string "¡Encontré buenos POKéMON entre la\n"
	.string "hierba!\p"
	.string "¡Con ellos ganaré seguro!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Vaya. Estaba seguro de ganar.$"

Route32_Text_YoungsterGordon_After:
	.string "La hierba está llena de semillas\n"
	.string "y cosas pegajosas.$"

Route32_Text_CamperRoland_Seen:
	.string "Esa mirada… ¡Desafío a la vista!$"

Route32_Text_CamperRoland_Beaten:
	.string "Mmm… Qué decepción conmigo mismo.$"

Route32_Text_CamperRoland_After:
	.string "Si no quieres luchar, no mires a\n"
	.string "los ojos a otros entrenadores.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Sí, sí, ya sabes…\p"
	.string "¿Eh? ¿Un combate? Estoy al\n"
	.string "teléfono.\p"
	.string "Bueno, vale, pero que sea rápido.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "¡Vaya! ¡Qué rabia me da perder!$"

Route32_Text_PicnickerLiz1_After:
	.string "Con lo a gusto que estaba hablando…$"

Route32_Text_LizRegister:
	.string "Con lo a gusto que estaba hablando…$"

Route32_Text_LizRematchIntro:
	.string "Sí, sí, ya sabes…\p"
	.string "¿Eh? ¿Un combate? Estoy al\n"
	.string "teléfono.\p"
	.string "Bueno, vale, pero que sea rápido.$"

Route32_Text_LizRematchDefeat:
	.string "¡Vaya! ¡Qué rabia me da perder!$"

Route32_Text_LizPostRematch:
	.string "Con lo a gusto que estaba hablando…$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "¡Esa MEDALLA! ¡Es de CIUDAD MALVA!\n"
	.string "¿Derrotaste a PEGASO?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Ya sé cuáles son mis puntos\n"
	.string "débiles.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Debería volver a entrenar en el\n"
	.string "GIMNASIO de CIUDAD MALVA.$"

Route32_Text_RoarIntro:
	.string "¡¡¡GROOOAAAR!!! ¡LA GENTE SALE\n"
	.string "CORRIENDO CUANDO RUJO!\l"
	.string "¡PERO TÚ TE HAS ACERCADO!\p"
	.string "¡ESO ME MOLA! ¡TOMA ESTO!$"

Route32_Text_RoarOutro:
	.string "¡¡¡GROOOAAAR!!! ¡ES RUGIDO!\p"
	.string "¡HASTA LOS POKéMON SALEN POR PATAS\n"
	.string "CON UN BUEN RUGIDO!$"

Route32_Text_MeetFrieda:
	.string "VIKI: ¡Yujuuu!\p"
	.string "¡Soy VIKI, de la FAMILIA SEMANAL!\n"
	.string "¡Encantada de conocerte!\p"
	.string "Si adivinas mi día favorito,\n"
	.string "¡te daré un buen regalito!$"

Route32_Text_FriedaGivesGift:
	.string "¡Toma esta FLECHA VENENOSA!$"

Route32_Text_FriedaGaveGift:
	.string "VIKI: ¡Dásela a un POKéMON que use\n"
	.string "ataques de tipo VENENO!\p"
	.string "¡Oh!\p"
	.string "¡Es una pasada!\p"
	.string "¡Te sorprenderá cuánto potencia\n"
	.string "los movimientos venenosos!$"

Route32_Text_FriedaFriday:
	.string "VIKI: ¡Buenas! ¿Cuál es tu día\n"
	.string "preferido?\p"
	.string "A mí me flipa el viernes. ¡Sin\nduda!\p"
	.string "¿A que a ti también te parece\ngenial?$"

Route32_Text_FriedaNope:
	.string "VIKI: ¡Ese no es! ¡Frío, frío!$"

Route32_Text_Sign1:
	.string "RUTA 32\p"
	.string "CIUDAD MALVA - PUEBLO AZALEA$"

Route32_Text_Sign2:
	.string "RUINAS ALFA\n"
	.string "ENTRADA ESTE$"

Route32_Text_Sign3:
	.string "CUEVA UNIÓN\n"
	.string "MÁS ADELANTE$"
