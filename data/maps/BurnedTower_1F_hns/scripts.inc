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
	.string "EUSKADI: Me llamo EUSKADI.\pVoy tras la pista de un POKéMON\nllamado SUICUNE.\p¿Y tú eres...?\p¿{PLAYER}? ¡Encantado de conocerte!\pOí rumores de que SUICUNE podría\nestar\len esta TORRE QUEMADA, así que vine\la\lcomprobarlo.\pPero ¿dónde estará exactamente?$"
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
	.string "EUSKADI: Dicen que SUICUNE podría\nestar\len esta TORRE QUEMADA, así que vine\la\linvestigar.\p¿Dónde se habrá metido?$"
BurnedTower_1FMortyText:
	.string "MORTI: Como LÍDER de CIUDAD IRIS,\ndebo estudiar a los POKéMON que se\lconsideran legendarios: SUICUNE,\lENTEI\ly RAIKOU.\pComo EUSKADI está aquí, he decidido\ninspeccionar la TORRE junto a él.$"
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
	.string "..............................\p...Vaya, tú otra vez, pringao.\pHe venido buscando los POKéMON\nlegendarios que dicen que anidan\laquí.\p¡Pero aquí no hay una puta mierda!\p¿Tanto patear para llegar a este\nbasurero y que no haya nada?\l¡Ni de coña me lo trago!\p¡Seguro que es culpa tuya, payaso!$"
BurnedTowerSilver_WinText:
	.string "...¡Será posible!\pHe perdido solo porque estos\nPOKéMON\lmíos son unos inútiles de mierda.\pQué patético.$"
BurnedTowerSilver_AfterText1:
	.string "...Bah, suda de todo.\pTampoco es que un matao como tú\nvaya\la pillar a un legendario en su\lvida.$"
BurnedTowerSilver_LossText:
	.string "...¡Ja! ¡Vaya pringao!\pPor eso me jode pelear con\npaquetes:\les una puta pérdida de tiempo.$"
BurnedTowerSilver_AfterText2:
	.string "¡Ja, qué subnormal!\p¿Te has caído por un boquete?\n¡Vaya lumbreras estás hecho!\p¡Te está bien empleado, pringao!$"
BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "¡Tranquilo!\p¡Los tragafuegos conocemos el\nauténtico\lpoder del fuego mejor que nadie!$"
BurnedTower_Text_NardBeaten:
	.string "¡Gracias por un combate tan\nardiente!$"
BurnedTower_Text_NardAfter:
	.string "Esta torre ardió porque le cayó un\nrayo\lencima en plena tormenta.\pLas llamaradas que yo escupo son\nuna\lminucia en comparación...$"
BurnedTower_Text_RichardoSeen:
	.string "¡Estoy practicando mis robos en la\nTORRE QUEMADA! ¡No intentes esto en\ltu\lcasa!$"
BurnedTower_Text_RichardoBeaten:
	.string "¡Pfffffffffffffff!$"
BurnedTower_Text_RichardoAfter:
	.string "A lo mejor la vida delictiva no es\nlo\lmío...$"
