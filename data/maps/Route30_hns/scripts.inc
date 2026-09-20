Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "Casa del SR. POKéMON$"

Route30_Text_UseTackle:
	.string "¡Adelante, RATTATA!\p"
	.string "¡PLACAJE!$"

Route30_Text_ThisIsABigBattle:
	.string "¿Qué pasa? ¡Estamos en medio de un\ncombate\l"
	.string "importante! ¡Déjame en paz!$"

Route30_Text_YoungsterJoey1Seen:
	.string "Acabo de perder, así que estoy\nbuscando más\l"
	.string "POKéMON.\p"
	.string "¡Espera! ¡Tú tienes cara de flojo!\n"
	.string "¡Vamos a combatir!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "¡Puaj! ¡He vuelto a perder!\n"
	.string "¡Maldita sea!$"

Route30_Text_YoungsterJoey1After:
	.string "¿Acaso necesito más POKéMON para\nluchar\l"
	.string "mejor?\p"
	.string "¡De eso nada! ¡Seguiré luchando con\neste\l"
	.string "pase lo que pase!$"

Route30_Text_YoungsterMikeySeen:
	.string "Eres un entrenador POKéMON, ¿a que\nsí?\p"
	.string "¡Pues entonces tenemos que\ncombatir!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "Qué raro...\n"
	.string "Antes había ganado.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Llegar a ser un buen entrenador\ncuesta\l"
	.string "un montón.\p"
	.string "Lucharé contra más gente para\nhacerme más\l"
	.string "fuerte.$"

Route30_Text_BugCatcherDonSeen:
	.string "¡En vez de un POKéMON bicho,\n"
	.string "me he encontrado con un entrenador!$"

Route30_Text_BugCatcherDonBeaten:
	.string "¡Arrgh! ¡Eres demasiado fuerte!$"

Route30_Text_BugCatcherDonAfter:
	.string "Me quedé sin POKé BALLS mientras\n"
	.string "atrapaba POKéMON.\p"
	.string "Debí haber comprado más…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "¿La casa del SR. POKéMON?\n"
	.string "Está un poco más adelante.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "¡Todo el mundo se lo pasa bomba en\nlos\l"
	.string "combates!\p"
	.string "¡Tú también deberías probar!$"

Route30_Text_CooltrainerF:
	.string "Yo no soy entrenadora.\p"
	.string "Pero si cruzas la mirada con uno,\n"
	.string "prepárate para luchar.$"

Route30_Text_Sign:
	.string "RUTA 30\p"
	.string "CIUDAD MALVA - CIUDAD CEREZO$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "¡CASA DEL SR. POKéMON\n"
	.string "TODO RECTO!$"

Route30_Text_MrPokemonsHouseSign:
	.string "CASA DEL SR. POKéMON$"

Route30_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\p"
	.string "¡Está prohibido robar los POKéMON\nde\l"
	.string "otras personas!\p"
	.string "¡Las POKé BALLS solo deben lanzarse\na\l"
	.string "POKéMON salvajes!$"

Route30_Text_JoeyRegister:
	.string "¡Oye, no lo haces nada mal!\p"
	.string "Mi RATTATA está que se sale, como\nsiempre.\p"
	.string "Es el único que tengo, ¡pero me\nconvertiré\l"
	.string "en un gran ENTRENADOR con él!\p"
	.string "¡Combatamos de nuevo algún día!$"

Route30_Text_JoeyRematchIntro:
	.string "¡Te prometí que esta vez sería\ndistinto!\l"
	.string "¡A luchar!$"

Route30_Text_JoeyRematchDefeat:
	.string "¡Puaj! ¡He vuelto a perder!\n"
	.string "¡Maldición!$"

Route30_Text_JoeyPostRematch:
	.string "Estoy revisando los ataques de mi\nRATTATA y\l"
	.string "planeando nuevas tácticas.\p"
	.string "¡En cuanto se me ocurra una buena,\n"
	.string "volveremos a combatir!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "He vuelto a perder…\n"
	.string "¡Caray, qué fuerte eres!\p"
	.string "Ah, sí, casi me olvido de que tenía\nque\l"
	.string "darte esto.\p"
	.string "Úsalo para hacerte aún más fuerte,\n¿vale?\l"
	.string "¡Yo también me haré más fuerte!$"

Route30_Text_ElmName:
	.string "PROF. ELM$"

Route30_Text_Elm_Disaster:
	.string "PROF. ELM: ¿H-hola? ¿{PLAYER}?\n"
	.string "¡Ha ocurrido un desastre!\p"
	.string "¡Es… es algo terrible!\p"
	.string "¿Qué vamos a hacer? Es que…\n"
	.string "¡Ay, no!\p"
	.string "¡Por favor, vuelve al laboratorio\nya mismo!$"


Route30_Text_Poliwag:
	.string "POLIWAG: Wag waag!$"
