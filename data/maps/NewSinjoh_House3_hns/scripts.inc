NewSinjoh_House3_hns_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, NewSinjoh_House3_OnFrame
    map_script MAP_SCRIPT_ON_LOAD, NewSinjoh_House3_OnTransition
    .byte 0


NewSinjoh_House3_OnTransition::
    call_if_ge VAR_NOBLE_TYPHLOSION, 2, NewSinjoh_House3_AddStairs
    end

NewSinjoh_House3_AddStairs::
    setmetatile 38, 13, 0x015, TRUE
	setmetatile 38, 14, 0x005, TRUE
	setmetatile 38, 15, 0x00D, TRUE
	setmetatile 39, 14, 0x006, TRUE
	setmetatile 39, 15, 0x00E, TRUE
	setmetatile 40, 14, 0x007, FALSE
	setmetatile 40, 15, 0x00F, FALSE
    return

NewSinjoh_House3_OnFrame:
    map_script_2 VAR_TEMP_0, 0, NewSinjoh_HauntedHouse_EventScript_Enter
	.2byte 0

NewSinjoh_HauntedHouse_EventScript_Enter::
    setvar VAR_TEMP_0, 1
    goto_if_eq VAR_NOBLE_TYPHLOSION, 1, NewSinjoh_HauntedHouse_EventScript_StartScary
    goto_if_eq VAR_NOBLE_TYPHLOSION, 0, NewSinjoh_HauntedHouse_EventScript_TooEarly
    end

NewSinjoh_HauntedHouse_EventScript_TooEarly::
    msgbox NewSinjoh_HauntedHouse_Text_TooEarlyNoReaction, MSGBOX_AUTOCLOSE
    release
    end

NewSinjoh_HauntedHouse_Text_TooEarlyNoReaction:
    .string "Sientes una presencia extraña...\p"
    .string "Pero no ocurre nada.$"

NewSinjoh_HauntedHouse_EventScript_StartScary::
    msgbox NewSinjoh_HauntedHouse_Text_StartScary, MSGBOX_AUTOCLOSE
    playse SE_M_DETECT
    getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
    playse SE_PIN
    applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_PLAYER
    msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
    closemessage
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
    playbgm MUS_DP_AZURE_FLUTE, FALSE
    delay 200
    fadedefaultbgm    
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, NewSinjoh_House3_Movement_CameraPanLeft
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
    setvar VAR_0x8005, 2  @ horizontal pan
    setvar VAR_0x8006, 20  @ num shakes
    setvar VAR_0x8007, 4  @ shake delay
    special ShakeCamera
    waitstate
    call NewSinjoh_House3_AddStairs
    special DrawWholeMapView
    playse SE_CLICK
    applymovement2 OBJ_EVENT_ID_CAMERA, NewSinjoh_House3_Movement_CameraPanRight
    waitmovement 0
    special RemoveCameraObject
    addobject LOCALID_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
    clearflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
    setvar VAR_NOBLE_TYPHLOSION, 2
    release
    end

NewSinjoh_House3_EventScript_NobleTyphlosion::
	lock
	faceplayer
	playmoncry SPECIES_TYPHLOSION_HISUI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_TYPHLOSION_HISUI, level=80, item=ITEM_SPOOKY_PLATE, move1_1=MOVE_INFERNAL_PARADE, move1_2=MOVE_LAVA_PLUME, move1_3=MOVE_CONFUSE_RAY move1_4=MOVE_SOLAR_BEAM
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 1, 2, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewSinjoh_House3_EventScript_NobleTyphlosionRan
    bufferspeciesname STR_VAR_1, SPECIES_TYPHLOSION_HISUI
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_SPOOKY_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	setflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

NewSinjoh_House3_EventScript_NobleTyphlosionRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

NewSinjoh_House3_Movement_CameraPanLeft:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

NewSinjoh_House3_Movement_CameraPanRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

NewSinjoh_HauntedHouse_Text_StartScary:
    .string "Sientes una presencia extraña...\p"
    .string "¿Alguien te está observando?$"

NewSinjoh_HauntedHouse_EventScript_Log1::
    msgbox NewSinjoh_HauntedHouse_Text_Log1, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_EventScript_Log2::
    msgbox NewSinjoh_HauntedHouse_Text_Log2, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_EventScript_Log3::
    msgbox NewSinjoh_HauntedHouse_Text_Log3, MSGBOX_SIGN
    end

NewSinjoh_HauntedHouse_Text_Log1:
    .string "Diario 9: 20 de septiembre de 1975\p"
    .string "Los días se van acortando y el\n"
    .string "viento empieza a ser implacable.\p"
    .string "La gente de la aldea fue\n"
    .string "muy acogedora conmigo.\p"
    .string "Me dejan pasar el invierno en esta\n"
    .string "cabaña.\p"
    .string "Parece que aquí vivía una familia.\n"
    .string "A menudo pienso en la mía.\p"
    .string "Quizá tenga el valor de volver con\n"
    .string "ellos cuando llegue la primavera.$"

NewSinjoh_HauntedHouse_Text_Log2:
    .string "Diario 10: 20 de octubre de 1975\p"
    .string "Mis pensamientos se han vuelto\n"
    .string "muy oscuros y sombríos.\p"
    .string "Tal vez sea por el cambio de\n"
    .string "estación.\p"
    .string "Los aldeanos siguen tratándome como\n"
    .string "a uno de los suyos.\p"
    .string "Pero la culpa que cargo me impide\n"
    .string "corresponderles.\p"
    .string "Apenas salgo ya de la cabaña.\p"
    .string "Y cuando pienso en mi familia...\n"
    .string "sus rostros han cambiado...\l"
    .string "Solo veo las caras de los POKéMON\l"
    .string "que se perdieron en las ruinas...\p"
    .string "A veces siento que los POKéMON\n"
    .string "están aquí conmigo. Los veo en los\l"
    .string "reflejos, siento sus miradas.\p"
    .string "Las cosas mejorarán en primavera.$"

NewSinjoh_HauntedHouse_Text_Log3:
    .string "Diario 11: 1 de noviembre de 1975\p"
    .string "No estoy solo aquí.\n"
    .string "Tal vez nunca lo estuve.\p"
    .string "Los POKéMON me acompañan...\p"
    .string "Creo que están furiosos conmigo.\p"
    .string "Vuelan objetos, se cierran puertas.\p"
    .string "Unas cajas muy pesadas\n"
    .string "bloquean la salida.\p"
    .string "Pero a decir verdad, podría irme\n"
    .string "si quisiera.\p"
    .string "Ya no me queda nada más fuera.\p"
    .string "Escribí antes sobre una familia,\n"
    .string "pero ellos son la única familia\l"
    .string "que logro recordar...\p"
    .string "Se me acaba la comida, pero la\n"
    .string "culpa pesa más que mi hambre.\p"
    .string "Creo que me quedaré aquí\n"
    .string "un tiempo...$"
  
