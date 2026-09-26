LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call LakeOfRage_EventScript_SetupSilver
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_SetupSilver::
	setflag FLAG_HIDE_LAKE_OF_RAGE_SILVER
	return

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
	.string "{PLAYER}.\pIncluso aquí, el frío me mantiene\ndespejado.\pSi deseas volver a combatir, ven al\nDOJO DE LUCHA.$"

LakeOfRage_EventScript_SilverTrigger::
	goto_if_set FLAG_RECEIVED_MEGA_TEST_KIT, LakeOfRage_EventScript_SilverTriggerEnd
	goto_if_set FLAG_HIDE_LAKE_OF_RAGE_GYARADOS, LakeOfRage_EventScript_SilverTriggerEnd
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 1, LakeOfRage_EventScript_SilverTriggerEnd
	lockall
	clearflag FLAG_HIDE_LAKE_OF_RAGE_SILVER
	addobject LOCALID_LAKEOFRAGE_SILVER
	applymovement LOCALID_LAKEOFRAGE_SILVER, LakeOfRage_Movement_SilverApproach
	waitmovement LOCALID_LAKEOFRAGE_SILVER
	turnobject LOCALID_LAKEOFRAGE_SILVER, DIR_NORTH
	delay 30
	msgbox LakeOfRage_Text_SilverGyaradosAwesome, MSGBOX_DEFAULT
	applymovement LOCALID_LAKEOFRAGE_SILVER, Common_Movement_ExclamationMark
	waitmovement LOCALID_LAKEOFRAGE_SILVER
	turnobject LOCALID_LAKEOFRAGE_SILVER, DIR_SOUTH
	msgbox LakeOfRage_Text_SilverNoticePlayer, MSGBOX_DEFAULT
	goto LakeOfRage_EventScript_SilverBattle

LakeOfRage_EventScript_SilverAtGyaradosTrigger::
	lockall
	clearflag FLAG_HIDE_LAKE_OF_RAGE_SILVER
	addobject LOCALID_LAKEOFRAGE_SILVER
	turnobject LOCALID_LAKEOFRAGE_SILVER, DIR_NORTH
	delay 30
	msgbox LakeOfRage_Text_SilverGyaradosAwesome, MSGBOX_DEFAULT
	applymovement LOCALID_LAKEOFRAGE_SILVER, Common_Movement_ExclamationMark
	waitmovement LOCALID_LAKEOFRAGE_SILVER
	turnobject LOCALID_LAKEOFRAGE_SILVER, DIR_SOUTH
	msgbox LakeOfRage_Text_SilverNoticePlayer, MSGBOX_DEFAULT

LakeOfRage_EventScript_SilverBattle::
	setflag FLAG_MEGA_SYSTEM_UNLOCKED
	call_if_eq VAR_STARTER_MON, 0, LakeOfRage_EventScript_SilverCyndaquil
	call_if_eq VAR_STARTER_MON, 1, LakeOfRage_EventScript_SilverTotodile
	call_if_eq VAR_STARTER_MON, 2, LakeOfRage_EventScript_SilverChikorita
	goto LakeOfRage_EventScript_SilverRewards

LakeOfRage_EventScript_Silver::
	lock
	faceplayer
	goto_if_defeated TRAINER_RIVAL_CHIKORITA_LAKE_HNS, LakeOfRage_EventScript_SilverRewards
	goto_if_defeated TRAINER_RIVAL_CYNDAQUIL_LAKE_HNS, LakeOfRage_EventScript_SilverRewards
	goto_if_defeated TRAINER_RIVAL_TOTODILE_LAKE_HNS, LakeOfRage_EventScript_SilverRewards
	release
	goto LakeOfRage_EventScript_SilverTrigger

LakeOfRage_EventScript_SilverCyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_LAKE_HNS, LakeOfRage_Text_SilverDefeat
	return

LakeOfRage_EventScript_SilverTotodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_LAKE_HNS, LakeOfRage_Text_SilverDefeat
	return

LakeOfRage_EventScript_SilverChikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_LAKE_HNS, LakeOfRage_Text_SilverDefeat
	return

LakeOfRage_EventScript_SilverRewards::
	msgbox LakeOfRage_Text_SilverAfterBattle, MSGBOX_DEFAULT
	checkitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_SilverGiveMon
	giveitem ITEM_MEGA_RING

LakeOfRage_EventScript_SilverGiveMon::
	msgbox LakeOfRage_Text_SilverDropMon, MSGBOX_DEFAULT
	special GiveRandomMegaGift
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, LakeOfRage_EventScript_SilverNoRoom
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LakeOfRage_EventScript_SilverGiftToPC
	msgbox LakeOfRage_Text_SilverGiftReceived, MSGBOX_DEFAULT
	goto LakeOfRage_EventScript_SilverLeave

LakeOfRage_EventScript_SilverGiftToPC::
	msgbox LakeOfRage_Text_SilverGiftToPC, MSGBOX_DEFAULT

LakeOfRage_EventScript_SilverLeave::
	setflag FLAG_RECEIVED_MEGA_TEST_KIT
	applymovement LOCALID_LAKEOFRAGE_SILVER, LakeOfRage_Movement_SilverLeave
	waitmovement LOCALID_LAKEOFRAGE_SILVER
	setflag FLAG_HIDE_LAKE_OF_RAGE_SILVER
	removeobject LOCALID_LAKEOFRAGE_SILVER
	releaseall
	end

LakeOfRage_EventScript_SilverNoRoom::
	msgbox LakeOfRage_Text_SilverNoRoom, MSGBOX_DEFAULT
	releaseall
	end

LakeOfRage_EventScript_SilverTriggerEnd::
	end

LakeOfRage_Movement_SilverApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_SilverLeave:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_SilverGyaradosAwesome:
	.string "Míralo...\p"
	.string "Ese color rojo sangre...\n"
	.string "La furia que emana de sus\l"
	.string "escamas...\p"
	.string "Es sencillamente...\n"
	.string "impresionante.$"

LakeOfRage_Text_SilverNoticePlayer:
	.string "¡¿Eh?! ¡¿Tú otra vez, {PLAYER}?!\p"
	.string "¿Qué miras, pringao? ¿Te crees\n"
	.string "que he venido de turismo?\p"
	.string "Estudiaba la energía del lago.\n"
	.string "¡He encontrado una fuerza que tú\l"
	.string "ni en sueños podrás alcanzar!\p"
	.string "¡Abre bien los ojos y contempla\n"
	.string "el verdadero poder de combate!$"

LakeOfRage_Text_SilverDefeat:
	.string "¡¿Qué demonios?!\n"
	.string "¡¿Cómo ha podido pasar esto?!$"

LakeOfRage_Text_SilverAfterBattle:
	.string "Tch... No te vengas arriba.\n"
	.string "Ha sido un fallo técnico.\p"
	.string "Toma, quédate con esta chatarra.\n"
	.string "Me dieron dos MEGA-AROS en el\l"
	.string "laboratorio y no necesito otro\l"
	.string "para machacarte la próxima.$"

LakeOfRage_Text_SilverDropMon:
	.string "¡Y quítame esto de la vista!\n"
	.string "Este bicho con su piedra rara\l"
	.string "solo me está ocupando sitio.\p"
	.string "¡La próxima no tendrás tanta\n"
	.string "suerte, espantapájaros!$"

LakeOfRage_Text_SilverGiftReceived:
	.string "{STR_VAR_1} se unió a tu equipo\n"
	.string "con su MEGAPIEDRA equipada.$"

LakeOfRage_Text_SilverGiftToPC:
	.string "{STR_VAR_1} fue enviado al PC\n"
	.string "con su MEGAPIEDRA equipada.$"

LakeOfRage_Text_SilverNoRoom:
	.string "¡Tu equipo y tus cajas están\n"
	.string "llenos! Haz sitio y vuelve.\p"
	.string "No pienso cargar con este trasto\n"
	.string "eternamente, pringao.$"
LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	goto_if_unset FLAG_RECEIVED_MEGA_TEST_KIT, LakeOfRage_EventScript_SilverAtGyaradosTrigger
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRAGONITE: ¡Giafuuuu!$"
LakeOfRage_Text_LanceForcedToEvolve:
	.string "Este lago está lleno de GYARADOS\ny nada más…\pAsí obligan a evolucionar\na los MAGIKARP…$"
LakeOfRage_Text_LanceIntro1:
	.string "¿Has venido por los rumores?\p¿Eres {PLAYER}? Soy LANCE,\nun Entrenador como tú.$"
LakeOfRage_Text_LanceIntro2:
	.string "Este hombre me habló de ciertos\nrumores.\pAsí que vinimos a investigar…$"
LakeOfRage_Text_LanceIntro3:
	.string "Vi cómo combatiste antes, {PLAYER}.\pSe nota que eres un Entrenador\nmuy hábil.\pSi no te importa, ¿nos ayudarías\na investigar?$"
LakeOfRage_Text_LanceRadioSignal:
	.string "LANCE: ¡Excelente!\pParece que están obligando a los\nMAGIKARP del LAGO a evolucionar.\pLa causa es una misteriosa emisión\nde radio procedente de CAOBA.\pTe esperaremos allí,\n{PLAYER}.$"
LakeOfRage_Text_LanceRefused:
	.string "Vaya… Si cambias de opinión,\nayúdanos, por favor.$"
LakeOfRage_Text_LanceAskHelp:
	.string "LANCE: ¿Mmm? ¿Vas a\nayudarnos?$"
LakeOfRage_Text_GyaradosCry:
	.string "GYARADOS: ¡Giaaash!$"
LakeOfRage_Text_Gramps:
	.string "¡Los GYARADOS están enfurecidos!\p¡Esto es un mal presagio!$"
LakeOfRage_Text_GrampsCleared:
	.string "¡Jajaja! ¡Los MAGIKARP vuelven a\npicar!$"
LakeOfRage_Text_SuperNerd:
	.string "Dicen que unos GYARADOS enfurecidos\ncrearon este lago.\p¿Tendrá relación con el brote\nque hay ahora?$"
LakeOfRage_Text_CooltrainerF:
	.string "¿Me engañan los ojos? Vi un\nGYARADOS rojo en el LAGO…\pPero creía que los GYARADOS eran\nazules.$"
LakeOfRage_Text_FisherAndreSeen:
	.string "¡Déjame combatir con el POKéMON\nque acabo de pescar!$"
LakeOfRage_Text_FisherAndreBeaten:
	.string "Puede que sea un gran pescador,\npero soy un Entrenador pésimo…$"
LakeOfRage_Text_FisherAndreAfter:
	.string "¡Nadie me gana pescando! Capturo\nPOKéMON todo el día.$"
LakeOfRage_Text_FisherRaymondSeen:
	.string "¡Haga lo que haga, siempre pesco\nlos mismos POKéMON!$"
LakeOfRage_Text_FisherRaymondBeaten:
	.string "Se me ha enredado todo el sedal…$"
LakeOfRage_Text_FisherRaymondAfter:
	.string "¿Por qué no pesco ningún\nPOKéMON bueno?$"
LakeOfRage_Text_CooltrainermAaronSeen:
	.string "Si un Entrenador ve a otro,\ndebe desafiarlo.\pEse es nuestro destino.$"
LakeOfRage_Text_CooltrainermAaronBeaten:
	.string "Uf… Magnífico combate.$"
LakeOfRage_Text_CooltrainermAaronAfter:
	.string "Los POKéMON y sus Entrenadores se\nfortalecen combatiendo sin cesar.$"
LakeOfRage_Text_CooltrainerfLoisSeen:
	.string "¿Qué pasó con el GYARADOS rojo?\p¿Ya no está?\p¡Maldición! ¿He venido para nada?\p¡Ya sé, combatamos!$"
LakeOfRage_Text_CooltrainerfLoisBeaten:
	.string "¡Bien jugado!$"
LakeOfRage_Text_CooltrainerfLoisAfter:
	.string "Ahora que me acuerdo, una vez vi un\nBUTTERFREE de color rosa.$"
LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
	.string "MIO: Hola, ¿cómo estás?\p¡Soy de los HERMANOS DE LOS DÍAS!\n¿Adivinas mi día preferido?$"
LakeOfRage_Text_WesleyGivesGift:
	.string "Encantado de conocerte. Acepta\neste recuerdo.$"
LakeOfRage_Text_WesleyGaveGift:
	.string "MIO: El CINTURÓN NEGRO aumenta la\npotencia de los ataques de LUCHA.$"
LakeOfRage_Text_WesleyWednesday:
	.string "MIO: Si me has encontrado, debes\nhaber conocido a mis hermanos y\lhermanas.\p¿O solo has tenido suerte?$"
LakeOfRage_Text_WesleyNotWednesday:
	.string "MIO: Pues va a ser que no...$"
LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
	.string "LAGO DE LA FURIA,\ntambién conocido como LAGO\lGYARADOS.$"
LakeOfRage_Text_FishingGuruSign:
	.string "CASA DEL GURÚ DE LA PESCA$"
