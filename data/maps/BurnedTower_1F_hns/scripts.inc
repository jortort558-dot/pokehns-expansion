BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSKADI: Me llamo EUSKADI.\p"
	.string "Voy tras la pista de un POKéMON\n"
	.string "llamado SUICUNE.\p"
	.string "¿Y tú eres...?\p"
	.string "¿{PLAYER}? ¡Encantado de\n"
	.string "conocerte!\p"
	.string "Oí rumores de que SUICUNE podría\n"
	.string "estar en esta TORRE QUEMADA, así\l"
	.string "que vine a comprobarlo.\p"
	.string "Pero ¿dónde estará exactamente?$"
BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSKADI: Dicen que SUICUNE\n"
	.string "podría estar en esta TORRE\l"
	.string "QUEMADA, así que vine a\l"
	.string "investigar.\p"
	.string "¿Dónde se habrá metido?$"
BurnedTower_1FMortyText:
	.string "MORTI: Como LÍDER de CIUDAD\n"
	.string "IRIS, debo estudiar a los\l"
	.string "POKéMON que se consideran\l"
	.string "legendarios: SUICUNE, ENTEI y\l"
	.string "RAIKOU.\p"
	.string "Como EUSKADI está aquí, he\n"
	.string "decidido inspeccionar la TORRE\l"
	.string "junto a él.$"
BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "...Vaya, tú otra vez, pringao.\p"
	.string "He venido buscando los POKéMON\n"
	.string "legendarios que dicen que anidan\l"
	.string "aquí.\p"
	.string "¡Pero aquí no hay una puta\n"
	.string "mierda!\p"
	.string "¿Tanto patear para llegar a este\n"
	.string "basurero y que no haya nada? ¡Ni\l"
	.string "de coña me lo trago!\p"
	.string "¡Seguro que es culpa tuya,\n"
	.string "payaso!$"
BurnedTowerSilver_WinText:
	.string "...¡Será posible!\p"
	.string "He perdido solo porque estos\n"
	.string "POKéMON míos son unos inútiles\l"
	.string "de mierda.\p"
	.string "Qué patético.$"
BurnedTowerSilver_AfterText1:
	.string "...Bah, suda de todo.\p"
	.string "Tampoco es que un matao como tú\n"
	.string "vaya a pillar a un legendario en\l"
	.string "su vida.$"
BurnedTowerSilver_LossText:
	.string "...¡Ja! ¡Vaya pringao!\p"
	.string "Por eso me jode pelear con\n"
	.string "paquetes: es una puta pérdida de\l"
	.string "tiempo.$"
BurnedTowerSilver_AfterText2:
	.string "¡Ja, qué subnormal!\p"
	.string "¿Te has caído por un boquete?\n"
	.string "¡Vaya lumbreras estás hecho!\p"
	.string "¡Te está bien empleado, pringao!$"
BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "¡Tranquilo!\p"
	.string "¡Los tragafuegos conocemos el\n"
	.string "auténtico poder del fuego mejor\l"
	.string "que nadie!$"
BurnedTower_Text_NardBeaten:
	.string "¡Gracias por un combate tan\n"
	.string "ardiente!$"
BurnedTower_Text_NardAfter:
	.string "Esta torre ardió porque le cayó\n"
	.string "un rayo encima en plena\l"
	.string "tormenta.\p"
	.string "Las llamaradas que yo escupo son\n"
	.string "una minucia en comparación...$"
BurnedTower_Text_RichardoSeen:
	.string "¡Estoy practicando mis robos en\n"
	.string "la TORRE QUEMADA! ¡No intentes\l"
	.string "esto en tu casa!$"
BurnedTower_Text_RichardoBeaten:
	.string "¡Pfffffffffffffff!$"
BurnedTower_Text_RichardoAfter:
	.string "A lo mejor la vida delictiva no\n"
	.string "es lo mío...$"
