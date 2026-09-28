Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "¿Quieres usar la REGADERA?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} usó la REGADERA.$"

Route36_Text_SudowoodoAttacked:
	.string "¡Al árbol extraño no le hace\nninguna\l"
	.string "gracia el agua de la REGADERA!\p"
	.string "¡El árbol extraño se abalanza al\n"
	.string "ataque!$"

Route36_Text_RockSmashGuy1:
	.string "¡Aaarg!\p"
	.string "Iba a quebrar ese árbol de un solo\n"
	.string "puñetazo certero.\p"
	.string "¡Pero ni se ha inmutado! ¡He\n"
	.string "fracasado como Karateka!$"

Route36_Text_RockSmashGuy2:
	.string "¿Has logrado quitar ese maldito\n"
	.string "árbol del camino?\p"
	.string "¡Me has dejado boquiabierto!\n"
	.string "¡Quiero que te quedes con esto!$"

Route36_Text_RockSmashGuy3:
	.string "¡Es la MO GOLPE ROCA!\p"
	.string "Con ella puedes reventar peñascos\n"
	.string "agrietados de un solo impacto.\p"
	.string "Si alguna roca te corta el paso,\n"
	.string "¡hazla trizas sin dudarlo!$"

Route36_Text_OddTree:
	.string "Un árbol extrañísimo bloquea el\n"
	.string "camino.$"

Route36_Text_Lass1:
	.string "¡Mucho ojo por las noches en esta\n"
	.string "ruta!\p"
	.string "Vi a un POKéMON parecido a\n"
	.string "GROWLITHE, pero con un aura que\ldaba\l"
	.string "auténtico pavor.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "El árbol raro se esfumó sin dejar\n"
	.string "rastro.\p"
	.string "¡¿Cómo?! ¿Que en realidad era un\n"
	.string "POKéMON disimulando?$"

Route36_Text_PsychicMarkSeen:
	.string "¡Voy a leer tu mente como un libro\n"
	.string "abierto!$"

Route36_Text_PsychicMarkBeaten:
	.string "¡Te he leído fatal!$"

Route36_Text_PsychicMarkAfter:
	.string "Sería imparable si pudiera\nanticipar\l"
	.string "lo que trama mi rival…$"

Route36_Text_SchoolboyAlan1Seen:
	.string "¡Gracias a mis horas de estudio, no\n"
	.string "hay POKéMON que me sorprenda!$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "¡Uy! ¿Fallo de cálculo?$"

Route36_Text_SchoolboyAlanAfter:
	.string "Vaya. Y eso que estudio cinco horas\n"
	.string "al día.\p"
	.string "Se aprende más en la práctica que\nen\l"
	.string "los libros.$"

Route36_Text_MeetArthur:
	.string "ARTURO: ¿Quién anda ahí?\n"
	.string "Soy ARTURO, de la familia semanal.\p"
	.string "Si adivinas mi día favorito de la\n"
	.string "semana, ¡te daré un buen regalo!$"

Route36_Text_ArthurNope:
	.string "¡Frío, frío!$"

Route36_Text_ArthurGivesGift:
	.string "¡Acertaste! ¡Quédate con esto!$"

Route36_Text_ArthurGaveGift:
	.string "ARTURO: Es la PIEDRA DURA.\n"
	.string "Dásela a un POKéMON que conozca\l"
	.string "ataques de tipo ROCA.\p"
	.string "¡Potenciará la fuerza de sus\ngolpes!$"

Route36_Text_ArthurThursday:
	.string "ARTURO: Soy ARTURO, del Jueves.\n"
	.string "El quinto de siete hermanos.$"

Route36_Text_Sign:
	.string "RUTA 36$"

Route36_Text_Sign_RuinsNorth:
	.string "RUINAS ALFA\n"
	.string "ACCESO NORTE$"

Route36_Text_Tips1:
	.string "PISTAS PARA ENTRENADORES\n"
	.string "Las estadísticas varían incluso\lentre\l"
	.string "POKéMON de la misma especie.\p"
	.string "Al principio pueden parecer\niguales,\l"
	.string "pero con el entrenamiento sus\ltalentos\l"
	.string "se diferencian con claridad.$"

Route36_Text_Tips2:
	.string "PISTAS PARA ENTRENADORES\n"
	.string "Usa EXCAVAR para volver a la\l"
	.string "entrada de cualquier lugar.\p"
	.string "Es muy útil para explorar cuevas.$"

Route36_Text_AlanRegister:
	.string "Vaya. Estudio cinco horas al día.\p"
	.string "Para aprender no basta con leer.$"

Route36_Text_AlanRematchIntro:
	.string "¡Gracias a mis estudios, estoy\n"
	.string "preparado para cualquier POKéMON!$"

Route36_Text_AlanRematchDefeat:
	.string "¡Uy! ¿Error de cálculo?$"

Route36_Text_AlanPostRematch:
	.string "Vaya. Estudio cinco horas al día.\p"
	.string "Para aprender no basta con leer.$"

Route36_Text_AlanHasItem:
	.string "¡He encontrado algo mientras\n"
	.string "estudiaba! ¡Puedes quedártelo!$"

Route36_Text_AlanGaveItem:
	.string "¡Te avisaré si encuentro algo más!$"

Route36_Text_AlanNoRoom:
	.string "Mmm, tienes la BOLSA llena.\p"
	.string "Vuelve cuando tengas sitio.$"
