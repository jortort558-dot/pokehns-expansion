OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
	.string "BAOBA$"
OlivineCity_Text_Baoba:
	.string "¡{PLAYER}!\pSoy el GUARDA BAOBA.\pPerdona por hacerte esperar.\n¡Por fin hemos abierto la\lZONA SAFARI!\p¿Sabes dónde está?\p¿Recuerdas el PASADIZO de la cueva\nde CIUDAD ORQUÍDEA?\pSi lo cruzas y caminas un poco,\npronto verás la ZONA SAFARI.\pEstamos algo apartados, pero\n¡ven a visitarnos!$"
OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "¿Otra vez tú?\n"
	.string "No te flipes, no vengo a por ti.\p"
	.string "Paso de perder el tiempo con\n"
	.string "pringaos como tú.\p"
	.string "Hablando de mataos, la LÍDER\n"
	.string "del GIMNASIO no está por aquí;\l"
	.string "dicen que anda cuidando\l"
	.string "a un POKéMON enfermo en el\l"
	.string "FARO.\p"
	.string "¡Bah! ¡Qué dramón!\n"
	.string "¡Que abandonen a ese POKéMON!\p"
	.string "Un POKéMON que no puede luchar\n"
	.string "¡no sirve para nada!\p"
	.string "¿Por qué no te largas a entrenar\n"
	.string "al FARO?\p"
	.string "Quién sabe. Igual así dejas de\n"
	.string "ser un Entrenador tan penoso!$"
OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "CAFÉ DE OLIVO\nDONDE LOS MARINEROS FORNIDOS\lDISFRUTAN COMIDAS CONTUNDENTES$"
OlivineCity_Text_EonTicketWoman1:
	.string "¡Me llamo ROSA!\pEs broma, ¡pero me encanta el\nprograma de radio de ROSA!$"
OlivineCity_Text_EonTicketWoman2:
	.string "¡¡¡Tú debes de ser {PLAYER}!!!\p¡Madre mía! ¡Eres el CAMPEÓN!\p¡Oí hablar de ti en el programa\nde radio de ROSA!\p¡Toma, quédate con esto!$"
OlivineCity_Text_EonTicketWoman3:
	.string "¡No me creo que haya conocido al\nCAMPEÓN!$"
OlivineCity_Text_Sailor1:
	.string "Los caminos oscuros son peligrosos\nde noche.\pPero, en plena oscuridad, el mar\nes aún más traicionero.\pSin la luz del FARO para guiarlo,\nningún barco podría navegar.$"
OlivineCity_Text_YoungsterPokegear:
	.string "Eso que llevas...\nes un POKéGEAR, ¿verdad?\l¡Hala, qué pasada!$"
OlivineCity_Text_YoungsterPokedex:
	.string "¡Hala, tienes una POKéDEX!\p¡Es una pasada!$"
OlivineCity_Text_Sailor2:
	.string "¡La LIGA considera a YASMINA\nla sexta LÍDER más fuerte!\p¡Ja! ¡Menuda patraña!\p¡FREDO jamás podría hacer daño a\nlos POKéMON de ACERO de YASMINA!\pPura burocracia, si me preguntas.\p¡Esa chica sí que da miedo,\neso seguro!$"
OlivineCity_Text_Sign:
	.string "CIUDAD OLIVO\pEl puerto más cercano a tierras\nlejanas.$"
OlivineCity_Text_PortSign:
	.string "PUERTO OLIVO\nEMBARCADERO DEL FERRY RÁPIDO$"
OlivineCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD OLIVO\nLÍDER: YASMINA\pLa chica de la defensa de acero$"
OlivineCity_Text_LighthouseSign:
	.string "FARO DE OLIVO\nTambién conocido como el FARO\lBRILLANTE$"
OlivineCity_Text_BattleTowerSign:
	.string "COLINA DESAFÍO Y CARPAS DE BATALLA\nMÁS ADELANTE.\p¡Ya están abiertas!$"
OlivineCity_Text_Machoke:
	.string "MACHOKE: ¡CHO!$"

OlivineCity_EventScript_SitoFriki::
	lock
	faceplayer
	msgbox OlivineCity_Text_SitoFriki, MSGBOX_DEFAULT
	release
	end

OlivineCity_Text_SitoFriki:
	.string "¡Buenas! Me llamo Sito...\p"
	.string "Oye, ¿me metes en tu grupo de\n"
	.string "Steam, por favor?\p"
	.string "Es solo para aprovecharme del\n"
	.string "préstamo familiar de juegos...\p"
	.string "¡Te juro que no cambiaré tus\n"
	.string "contraseñas ni nada de eso!$"

