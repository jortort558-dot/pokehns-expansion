SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ANCIANO: Posees ciertamente un gran\n"
	.string "talento para el combate.\p"
	.string "Como prometí, aquí tienes tu MO.\p"
	.string "Pero escucha esto: deberías tratar\n"
	.string "a tus POKéMON con mayor bondad.\p"
	.string "Tu forma de combatir es demasiado\n"
	.string "cruel.\p"
	.string "Los POKéMON no son meras\n"
	.string "herramientas de guerra…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "… ¡Menuda milonga!\p"
	.string "¡Dice que es el ANCIANO pero es un\n"
	.string "flojo de mierda!\p"
	.string "Era de cajón.\p"
	.string "¡Jamás voy a perder contra puretas\n"
	.string "que me comen la oreja con mimar a\l"
	.string "los bichos!\p"
	.string "A mí solo me importan los POKéMON\n"
	.string "fuertes que revientan en combate.\p"
	.string "¡Los bichos blandengues me la pelan\n"
	.string "por completo!$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "¡{RIVAL} usó una CUERDA HUIDA!$"

SproutTower_Text_SageLi_Seen:
	.string "¡Es un placer recibirte aquí!\p"
	.string "La TORRE BELSPROUT es un santuario\n"
	.string "de armonía y disciplina.\p"
	.string "Humanos y POKéMON forjan sus lazos\npara\l"
	.string "construir un futuro brillante.\p"
	.string "Yo soy la prueba final.\p"
	.string "¡Permíteme comprobar los vínculos\nque te\l"
	.string "unen a tus queridos POKéMON!$"

SproutTower_Text_SageLi_Beaten:
	.string "¡Ah, sublime!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Tus POKéMON y tú no tendréis\nproblema\l"
	.string "para dominar esta técnica.\p"
	.string "Acepta la MO de DESTELLO.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "DESTELLO ilumina hasta la más\nprofunda\l"
	.string "de las tinieblas.\p"
	.string "Pero para usarlo en cuevas,\nnecesitarás la\l"
	.string "MEDALLA del GIMNASIO de CIUDAD\nMALVA.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "Que la luz guíe tu camino y tu\ncorazón en\l"
	.string "este gran viaje.$"

SproutTower_Text_SageJin_Seen:
	.string "I train to find enlightenment\n"
	.string "in POKéMON!$"

SproutTower_Text_SageJin_Beaten:
	.string "My training is incomplete…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "As POKéMON grow stronger,\n"
	.string "so does the trainer.\p"
	.string "No, wait. As the trainer\n"
	.string "grows stronger, so do the\l"
	.string "POKéMON.$"

SproutTower_Text_SageTroy_Seen:
	.string "Let me see how much you trust\n"
	.string "your POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Yes, your trust is real!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "El ANCIANO te aguarda unos pasos\nadelante.$"

SproutTower_Text_SageNeal_Seen:
	.string "The ELDER's HM lights even\n"
	.string "pitch-black darkness.$"

SproutTower_Text_SageNeal_Beaten:
	.string "It is my head that is bright!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Let there be light on your\n"
	.string "journey.$"

SproutTower_Text_3F_Painting:
	.string "It's a powerful painting of a\n"
	.string "BELLSPROUT.$"
