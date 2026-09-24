Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: ¡Cielos benditos! ¿Esa\n"
	.string "sombra era de un POKéMON?\p"
	.string "¿Pudiste verlo bien?\n"
	.string "No distinguí bien su color...$"

Route39_Text_BaobaIntro::
	.string "Qué extraño...\p"
	.string "¡Oh!\n"
	.string "Eso que llevas ahí es...\l"
	.string "lo que llaman... ¡una POKéDEX!\p"
	.string "Hacía años que no veía una.\p"
	.string "¡Me llamo BAOBA!\n"
	.string "Antes dirigía la ZONA SAFARI de\l"
	.string "CIUDAD FUCSIA, pero quedó anticuada\l"
	.string "frente a las nuevas atracciones.\p"
	.string "Por eso viajé al extranjero para\n"
	.string "aprender técnicas y abrir una nueva\l"
	.string "ZONA SAFARI de última generación\l"
	.string "en CIUDAD ORQUÍDEA.\p"
	.string "Seguro que no es casualidad que nos\n"
	.string "hayamos conocido aquí.\p"
	.string "¿Qué tal si registramos nuestros\n"
	.string "números en el POKéGEAR?\p"
	.string "¡Te llamaré en cuanto inauguremos\n"
	.string "la ZONA SAFARI, antes que a nadie!$"

Route39_Text_Registered:
	.string "¡{PLAYER} registró a BAOBA en el\nPOKéGEAR!$"
Route39_Text_WillCall:
	.string "BAOBA: ¡Te avisaré pronto por el\nPOKéGEAR!$"
Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Esa sombra... ¿Sería acaso un\nPIDGEY gigante?$"
Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "MILTANK: ¡Muuuu!$"
Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Acabo de regresar a OLIVO.\p¿Qué te parece un combate POKéMON?$"
Route39_Text_SailorEugeneBeaten:
	.string "¡Aaaargh!$"
Route39_Text_SailorEugeneAfter:
	.string "Atrapé y crié a mis POKéMON en el\nextranjero.\pSon mis fieles compañeros en esas\nlargas travesías.$"
Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "¡Es el momento perfecto para fardar\nde mi PIKACHU!$"
Route39_Text_PokefanMDerekBeaten:
	.string "No me ha dado tiempo ni de lucir\na mi PIKACHU…$"
Route39_Text_PokefanMDerekAfter:
	.string "¡No pienso escuchar tus\nfanfarronadas!\pLos POKéFANS tenemos por norma no\nescuchar las presunciones de nadie.$"
Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "¡Qué POKéMON tan adorables!\pMostremos nuestros POKéMON juntos\nal mismo tiempo.$"
Route39_Text_PokefanFRuthBeaten:
	.string "No me importa perder.$"
Route39_Text_PokefanFRuthAfter:
	.string "¿Conoces a los POKéMON bebé?\n¡Seguro que son una auténtica\lmonada!$"
Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Déjame comprobar de qué son capaces\ntus POKéMON.$"
Route39_Text_PsychicNormanBeaten:
	.string "Oh, tus POKéMON tienen un potencial\nenorme.$"
Route39_Text_PsychicNormanAfter:
	.string "¿Sabes que los POKéMON tienen\nhabilidades distintas?\pA las personas les pasa igual.\nCada uno alberga un potencial\lúnico.$"
Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Llegas en el momento justo.\p¡Combatamos!$"
Route39_Text_PokefanFJaimeBeaten:
	.string "Vaya, qué decepción…$"
Route39_Text_PokefanFJaimeAfter:
	.string "Conocí a UMBREON de noche aquí\nmismo, en la RUTA 39.\pNo sé por qué, pero parece\nencantarle\lentrenar por esta zona.\pSe vuelve más cariñoso entrenando\naquí que en ningún otro sitio.$"
Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "RUTA 39\pCIUDAD OLIVO - CIUDAD IRIS$"
Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "GRANJA MU-MU\pDisfruta de nuestra leche fresca y\nsabrosa.$"
Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\pUsa GOLPE CABEZA en los árboles\npara que caigan POKéMON.\pCaen POKéMON de especies muy\ndistintas según el árbol.\p¡Dale un CABEZAZO a cualquier árbol\nque veas!$"
Route39_Text_DerekRegister:
	.string "¡No pienso escuchar tus\nfanfarronadas!\pLos POKéFANS tenemos por norma no\nescuchar las presunciones de nadie.$"
Route39_Text_DerekHasItem:
	.string "¡Ey! Estaba presumiendo de mi\nPIKACHU y encontré esto.\p¡Toma, te lo regalo!$"
Route39_Text_DerekGaveItem:
	.string "¡PIKACHU es lo más grande!\n¿A que estás de acuerdo?$"
Route39_Text_DerekNoRoom:
	.string "Vaya, tienes la BOLSA a tope.\pVuelve cuando tengas espacio.$"
