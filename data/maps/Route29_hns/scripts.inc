Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Pulsa A o B para dejar de mirar.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Los POKéMON se esconden en la\nhierba.\l"
	.string "¡Quién sabe cuándo saldrán!$"

Route29_Text_OldMan2:
	.string "Te he visto un par de veces.\n"
	.string "¿Cuántos POKéMON has atrapado?\p"
	.string "¿Quieres que te enseñe\n"
	.string "a atrapar POKéMON?$"

Route29_Text_OldManExplanation:
	.string "Si antes los debilitas,\n"
	.string "será más fácil atraparlos.\p"
	.string "¡Luego lánzales una BALL\n"
	.string "desde la BOLSA!\p"
	.string "Si quieres saber más,\n"
	.string "ve a la ACADEMIA de MALVA.\p"
	.string "Sus alumnos saben mucho\n"
	.string "sobre POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Ah, bueno, pues nada.\p"
	.string "Explora cada ruta para encontrar\n"
	.string "diferentes tipos de POKéMON.\p"
	.string "¡Tu POKéDEX también te indica dónde\n"
	.string "puedes encontrarlos!\p"
	.string "Si quieres aprender más,\n"
	.string "¡ve a la ACADEMIA de CIUDAD MALVA!\p"
	.string "Los alumnos saben un montón sobre\n"
	.string "los POKéMON.$"

Route29_Text_Youngster:
	.string "¡Ey! ¿Cómo están tus POKéMON?\p"
	.string "Si están débiles, evita\n"
	.string "meterte en la hierba.$"

Route29_Text_Lass:
	.string "¿Ves esos desniveles?\n"
	.string "Da un poco de miedo saltar por\lellos.\p"
	.string "Pero así puedes volver a PRIMAVERA\n"
	.string "sin tener que cruzar la hierba.$"

Route29_Text_Girl:
	.string "Quería tomarme un descanso,\n"
	.string "así que guardé mis avances.$"

Route29_Text_Boy_WaitingForDay:
	.string "Estoy esperando a los POKéMON que\n"
	.string "solo aparecen a plena luz del día.$"

Route29_Text_Boy_WaitingForNight:
	.string "Estoy esperando a los POKéMON que\n"
	.string "solo aparecen de noche.$"

Route29_Text_MeetTuscany:
	.string "MARTITA: Si no me equivoco,\n"
	.string "¿es la primera vez que nos vemos?\p"
	.string "Soy MARTITA, de los SIETE HERMANOS.\p"
	.string "Si adivinas mi día favorito,\n"
	.string "te daré un premio.$"

Route29_Text_TuscanyNope:
	.string "¡Casi, pero no!$"

Route29_Text_TuscanyGivesGift:
	.string "¡Sí! Como presentación,\n"
	.string "por favor, acepta este PAÑUELO\lSEDA.$"

Route29_Text_TuscanyGaveGift:
	.string "MARTITA: ¿A que es de lo más\nadorable?\p"
	.string "Potencia los ataques de tipo\nNORMAL.\p"
	.string "Seguro que te vendrá de perlas.$"

Route29_Text_TuscanyTuesday:
	.string "MARTITA: ¿Has conocido ya a MONI,\n"
	.string "mi hermana mayor?\p"
	.string "¿O a mi hermano pequeño, MIÉRCOLES?\p"
	.string "Soy la tercera de siete hermanos.$"

Route29_Text_Sign1:
	.string "RUTA 29\p"
	.string "CIUDAD CEREZO - PUEBLO PRIMAVERA$"
