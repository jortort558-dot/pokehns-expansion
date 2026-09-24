LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
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
	.string "{PLAYER}.\pIncluso aquí, el frío mantiene mi\nmente\ldespejada.\pSi deseas volver a combatir,\nbúscame en el\lDOJO de COMBATE.$"
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
	.string "Este lago está atestado de GYARADOS\ny de\lnada más…\pAsí que los MAGIKARP están siendo\nforzados\la evolucionar…$"
LakeOfRage_Text_LanceIntro1:
	.string "¿Has venido por los rumores?\p¿Eres {PLAYER}? Me llamo LANCE.\nSoy un Entrenador como tú.$"
LakeOfRage_Text_LanceIntro2:
	.string "Este hombre de aquí me puso al\ntanto de\lciertos rumores extraños.\pAsí que vinimos a investigar…$"
LakeOfRage_Text_LanceIntro3:
	.string "Vi cómo luchaste antes, {PLAYER}.\pSe nota a leguas que eres un\nEntrenador\lde enorme destreza.\pSi no te importa, ¿podrías\nayudarnos a\linvestigar este misterio?$"
LakeOfRage_Text_LanceRadioSignal:
	.string "LANCE: ¡Excelente!\pTodo apunta a que los MAGIKARP del\nLAGO\lestán siendo obligados a\levolucionar.\pLa culpable es una misteriosa\nemisión de\lradio que procede de CAOBA.\pTe esperaremos allí.\n¡No tardes, {PLAYER}!$"
LakeOfRage_Text_LanceRefused:
	.string "Vaya… Bueno, si cambias de parecer,\npor favor ven a echarnos una mano.$"
LakeOfRage_Text_LanceAskHelp:
	.string "LANCE: ¿Mmm? ¿Te decides a\nayudarnos?$"
LakeOfRage_Text_GyaradosCry:
	.string "GYARADOS: ¡Giaaash!$"
LakeOfRage_Text_Gramps:
	.string "¡Los GYARADOS están enfurecidos!\p¡Esto es un mal presagio!$"
LakeOfRage_Text_GrampsCleared:
	.string "¡Jajaja! ¡Los MAGIKARP vuelven a\npicar!$"
LakeOfRage_Text_SuperNerd:
	.string "Dicen que este lago fue creado por\nuna\lestampida de GYARADOS enfurecidos.\p¿Tendrá relación con este brote\nmasivo que\lhay ahora?$"
LakeOfRage_Text_CooltrainerF:
	.string "¿Me engañan los ojos o vi a un\nGYARADOS\lrojo en el LAGO?\pPero si los GYARADOS son azules de\ntoda\lla vida…$"
LakeOfRage_Text_FisherAndreSeen:
	.string "¡Déjame luchar con el POKéMON que\nacabo\lde pescar!$"
LakeOfRage_Text_FisherAndreBeaten:
	.string "Seré un hacha con la caña, pero\ncomo\lEntrenador doy bastante pena…$"
LakeOfRage_Text_FisherAndreAfter:
	.string "¡Pescando no me gana nadie! Me paso\nel día\lentero sacando POKéMON del agua.$"
LakeOfRage_Text_FisherRaymondSeen:
	.string "Haga lo que haga, ¡solo pesco los\nmismos\lPOKéMON una y otra vez!$"
LakeOfRage_Text_FisherRaymondBeaten:
	.string "Se me ha enredado todo el sedal…$"
LakeOfRage_Text_FisherRaymondAfter:
	.string "¿Por qué no logro pescar ningún\nPOKéMON en\lcondiciones?$"
LakeOfRage_Text_CooltrainermAaronSeen:
	.string "Si un Entrenador cruza la mirada\ncon otro,\lel desafío es inevitable.\pEse es nuestro destino.$"
LakeOfRage_Text_CooltrainermAaronBeaten:
	.string "Uf… Magnífico combate.$"
LakeOfRage_Text_CooltrainermAaronAfter:
	.string "Los POKéMON y sus Entrenadores se\nhacen\lfuertes a base de batirse el cobre.$"
LakeOfRage_Text_CooltrainerfLoisSeen:
	.string "¿Qué le ha pasado al GYARADOS rojo?\n¿Ya no está?\l¡Maldición! ¿He venido para nada?\l¡Pues mira, echemos un combate!$"
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
	.string "MIO: Hola, ¿cómo estás?\p¡Soy de los HERMANOS DE LOS DÍAS!\n¿Adivinas cuál es mi día preferido?$"
LakeOfRage_Text_WesleyGivesGift:
	.string "Encantado de conocerte.\nQuédate con este recuerdo.$"
LakeOfRage_Text_WesleyGaveGift:
	.string "MIO: El CINTURÓN NEGRO potencia los\ngolpes\lde tipo LUCHA.$"
LakeOfRage_Text_WesleyWednesday:
	.string "MIO: Si me has encontrado, seguro\nque ya\lhas visto a mis hermanos y\lhermanas.\p¿O ha sido pura chiripa?$"
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
