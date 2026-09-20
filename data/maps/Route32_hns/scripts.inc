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
	.string "¿Ya has visitado la TORRE\nBELLSPROUT?\l"
	.string "Si pasas por CIUDAD MALVA,\p"
	.string "se espera que entrenes allí\nprimero.\l"
	.string "Es lo básico para cualquier\nentrenador.\p"
	.string "¡Pásate por la TORRE BELLSPROUT!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "¿Has ido ya al GIMNASIO POKéMON?\n"
	.string "Allí podrás poner a prueba a tus\p"
	.string "POKéMON y tu propia valía.\n"
	.string "¡Es el rito de iniciación para\p"
	.string "cualquier entrenador!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "¡Llevas unos POKéMON muy bien\ncuidados!\l"
	.string "Se nota que has entrenado duro por\nlos\p"
	.string "alrededores de CIUDAD MALVA.\n"
	.string "El combate del GIMNASIO debió de\nser\p"
	.string "de gran ayuda. Como recuerdo de\nMALVA,\l"
	.string "¡quédate con esto!\p"
	.string "Potencia los movimientos de\n"
	.string "tipo PLANTA.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Lo vivido en CIUDAD MALVA te\nservirá\l"
	.string "de mucho a lo largo de tu viaje.$"

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
	.string "Whoa!\p"
	.string "You made me lose that fish!$"

Route32_Text_FisherJustin_Beaten:
	.string "Sploosh!$"

Route32_Text_FisherJustin_After:
	.string "Calm, collected… The essence of\n"
	.string "fishing and POKéMON is the same.$"

Route32_Text_FisherRalph1_Seen:
	.string "I'm really good at both\n"
	.string "fishing and POKéMON.\p"
	.string "I'm not about to lose to any kid!$"

Route32_Text_FisherRalph1_Beaten:
	.string "Tch! I tried to rush\n"
	.string "things…$"

Route32_Text_FisherRalph1_After:
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"

Route32_Text_RalphRegister:
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"

Route32_Text_RalphRematchIntro:
	.string "I'm really good at both\n"
	.string "fishing and POKéMON.\p"
	.string "I'm not about to lose to any kid!$"

Route32_Text_RalphRematchDefeat:
	.string "Tch! I tried to rush\n"
	.string "things…$"

Route32_Text_RalphPostRematch:
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"

Route32_Text_FisherHenry_Seen:
	.string "My POKéMON? Freshly caught!$"

Route32_Text_FisherHenry_Beaten:
	.string "SPLASH?$"

Route32_Text_FisherHenry_After:
	.string "Freshly caught POKéMON are\n"
	.string "no match for properly raised ones.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "I haven't seen you around before.\n"
	.string "So you think you are pretty tough?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "You're strong!$"

Route32_Text_YoungsterAlbert_After:
	.string "I'm going to try to be the\n"
	.string "best with my favorites.\p"
	.string "I'm not using the same tough\n"
	.string "POKéMON as everyone else.$"

Route32_Text_YoungsterGordon_Seen:
	.string "I found some good POKéMON\n"
	.string "in the grass!\p"
	.string "I think they'll do it for me!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Darn. I thought I could win.$"

Route32_Text_YoungsterGordon_After:
	.string "The grass is full of\n"
	.string "clingy things.$"

Route32_Text_CamperRoland_Seen:
	.string "That glance… It's intriguing.$"

Route32_Text_CamperRoland_Beaten:
	.string "Hmmm. This is disappointing.$"

Route32_Text_CamperRoland_After:
	.string "If you don't want to battle,\n"
	.string "just avoid eye contact.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "Oh! I've got to relieve\n"
	.string "my anger!$"

Route32_Text_PicnickerLiz1_After:
	.string "I was having a nice chat too.$"

Route32_Text_LizRegister:
	.string "I was having a nice chat too.$"

Route32_Text_LizRematchIntro:
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"

Route32_Text_LizRematchDefeat:
	.string "Oh! I've got to relieve\n"
	.string "my anger!$"

Route32_Text_LizPostRematch:
	.string "I was having a nice chat too.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "That BADGE! It's from VIOLET CITY!\n"
	.string "You beat FALKNER?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "I know what my weaknesses are.$"

Route32_Text_BirdKeeperPeter_After:
	.string "I should train again at the\n"
	.string "GYM in VIOLET CITY.$"

Route32_Text_RoarIntro:
	.string "¡¡¡GROOOAAAR!!! ¡LA GENTE SALE\nCORRIENDO\l"
	.string "CUANDO RUJO! ¡PERO TÚ TE HAS\nACERCADO!\p"
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
	.string "¡Te sorprenderá lo mucho que\npotencia\l"
	.string "los movimientos venenosos!$"

Route32_Text_FriedaFriday:
	.string "VIKI: ¡Buenas! ¿Cuál es tu día\n"
	.string "preferido?\p"
	.string "A mí me flipa el viernes. ¡Sin\nduda!\p"
	.string "¿A que a ti también te parece\ngenial?$"

Route32_Text_FriedaNope:
	.string "FRIEDA: Not that one!$"

Route32_Text_Sign1:
	.string "RUTA 32\p"
	.string "CIUDAD MALVA - PUEBLO AZALEA$"

Route32_Text_Sign2:
	.string "RUINAS ALFA\n"
	.string "ENTRADA ESTE$"

Route32_Text_Sign3:
	.string "CUEVA UNIÓN\n"
	.string "MÁS ADELANTE$"
