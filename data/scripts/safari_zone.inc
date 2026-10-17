SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setflag FLAG_SAFARI_ZONE_COMPLETED
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setflag FLAG_KANTO_SAFARI_ZONE_COMPLETED
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	setflag FLAG_SAFARI_ZONE_COMPLETED
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setflag FLAG_KANTO_SAFARI_ZONE_COMPLETED
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_CaughtMon::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_DidYouChooseWell
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockGone::
	lockall
	message SafariZone_Text_PokeblockGone
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_PokeblockGone:
	.string "¡Se han zampado todo el\n"
	.string "{STR_VAR_1}!$"

SafariZone_Text_WouldYouLikeToExit:
	.string "¿Quieres salir de la ZONA SAFARI\n"
	.string "ahora mismo?$"

SafariZone_Text_TimesUp:
	.string "¡Ding-dong! ¡Tiempo terminado!\n"
	.string "Tu juego del SAFARI ha concluido.$"

SafariZone_Text_OutOfBalls:
	.string "Te has quedado sin SAFARI BALLS.\n"
	.string "Tu juego del SAFARI ha terminado.$"

SafariZone_Text_DidYouChooseWell:
	.string "¿Habrás elegido bien?$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "¿Te gustaría poner un {POKEBLOCK}\n"
	.string "en el COMEDERO de {POKEBLOCK}S?$"

SafariZone_Text_PokeblockStillHere:
	.string "El {STR_VAR_1} que dejaste\n"
	.string "antes sigue aquí.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Pusiste el {STR_VAR_1}\n"
	.string "en el COMEDERO de {POKEBLOCK}S.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "¡Te damos la bienvenida a la\n"
	.string "ZONA SAFARI!\p"
	.string "Aquí podrás observar especies de\n"
	.string "POKéMON insólitas en esta región.\p"
	.string "Y podrás verlas en estado salvaje\n"
	.string "en sus propios hábitats naturales.\p"
	.string "Además, ¡abrimos nuestras puertas\n"
	.string "a los ENTRENADORES POKéMON!\p"
	.string "¡Te animamos a capturar ejemplares\n"
	.string "para quedártelos!\p"
	.string "¡Pasa y disfruta del SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "¡Te damos la bienvenida al SAFARI!\n"
	.string "¿Es tu primera vez por aquí?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "¡Pasa y disfruta de la ZONA SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Al entrar a la ZONA SAFARI, recibes\n"
	.string "30 SAFARI BALLS para capturar\l"
	.string "POKéMON salvajes.\p"
	.string "La partida termina si te quedas sin\n"
	.string "SAFARI BALLS o tras 500 pasos.\p"
	.string "¡Pasa y disfruta del SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "¡Te damos la bienvenida al SAFARI!\p"
	.string "¡Todo lo que puedas atrapar\n"
	.string "por solo 500¥!\l"
	.string "¿Te apetece jugar una partida?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Muy bien.\n"
	.string "¡Vuelve cuando te apetezca!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "No tienes suficiente dinero.\n"
	.string "Lo lamento.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Son 500¥, por favor.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Aquí tienes tus SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} recibió 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Te avisaremos cuando concluya\n"
	.string "tu juego.\p"
	.string "Hasta entonces, ¡pásalo en grande!\n"
	.string "¡Que disfrutes de tu excursión!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "¡Un momento!\n"
	.string "Las CAJAS de tu PC están llenas.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "¡Oye, perdona!\n"
	.string "Parece que no llevas un TUBO\l"
	.string "POKéCUBOS encima.\p"
	.string "Tu incursión en el SAFARI dará más\n"
	.string "frutos si usas POKéCUBOS.\p"
	.string "Vuelve cuando tengas uno.\p"
	.string "Puedes conseguir un TUBO POKéCUBOS\n"
#if IS_HNS
	.string "hablando con ese chico de ahí.$"
#else
	.string "en el AUDITORIO de CALAGUA.$"
#endif

SafariZone_South_Text_StillHaveTimeExit:
	.string "Aún te queda tiempo. ¿Deseas salir\n"
	.string "de la ZONA SAFARI ahora?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "¡Sigue disfrutando de tu excursión\n"
	.string "por la naturaleza salvaje!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "De acuerdo.\p"
	.string "Recuperaré tus SAFARI BALLS\n"
	.string "restantes.\p"
	.string "Muchas gracias por jugar.\n"
	.string "¡Esperamos verte de nuevo!$"

SafariZone_South_Text_GoodLuck:
	.string "¡Mucha suerte!\p"
	.string "Si necesitas cualquier cosa,\n"
	.string "¡no dudes en decírmelo!$"

SafariZone_South_Text_Boy:
	.string "¿Sabías una cosa?\p"
	.string "Si pones un {POKEBLOCK} ahí dentro,\n"
	.string "los POKéMON vendrán enseguida.$"

SafariZone_South_Text_Man:
	.string "Quiero explorar más a fondo,\n"
	.string "pero olvidé traer mi BICI.\p"
	.string "Algo me dice que en las zonas más\n"
	.string "alejadas viven POKéMON muy raros.$"

SafariZone_Southwest_Text_Woman:
	.string "A veces le tiro un {POKEBLOCK} a un\n"
	.string "POKéMON y no le hace ni caso.\p"
	.string "¿Tendrán gustos y manías con lo\n"
	.string "que comen, igual que nosotros?$"

SafariZone_Northwest_Text_Man:
	.string "Uf… Uf…\n"
	.string "He… llegado hasta aquí… pero…\p"
	.string "Estoy agotado… Ya no me quedan\n"
	.string "fuerzas ni para lanzar una BALL…$"

SafariZone_North_Text_Fisherman:
	.string "Busco POKéMON de AGUA que jamás\n"
	.string "se ven por HOENN.\p"
	.string "¿Tienes idea de dónde está el lago?$"

SafariZone_North_Text_Man:
	.string "¡Atraparé muchos POKéMON raros\n"
	.string "para cambiarlos con mis amigos!$"

SafariZone_South_Text_Youngster:
	.string "Puse un {POKEBLOCK} en el COMEDERO.\n"
	.string "¡Pero ha desaparecido!\p"
	.string "Seguro que algún POKéMON se lo ha\n"
	.string "comido sin que me diera cuenta.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "PISTAS PARA ENTRENADORES\p"
	.string "¡Lanza {POKEBLOCK}S a los salvajes\n"
	.string "para reducir sus ganas de huir!$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Alivia tus pies cansados.”\n"
	.string "CASA DE REPOSO$"

SafariZone_RestHouse_Text_Youngster:
	.string "No llevo {POKEBLOCK}S, ¡pero ya he\n"
	.string "atrapado a unos cuantos!\p"
	.string "Tienes más opciones si te acercas\n"
	.string "a ellos antes de lanzar la BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Con {POKEBLOCK}S, los salvajes no\n"
	.string "escaparán con tanta facilidad.\p"
	.string "Aunque apenas sirve de nada con\n"
	.string "especies que casi nunca huyen.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Pones un {POKEBLOCK} en el comedero\n"
	.string "y los POKéMON se sienten atraídos.\p"
	.string "Creo que cada clase de POKéMON se\n"
	.string "siente atraída por un sabor según\l"
	.string "cuál sea su naturaleza.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Esta zona aún sigue en obras.\n"
	.string "El paso está restringido, ¡perdón!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Las obras de ampliación del SAFARI\n"
	.string "ya han concluido.\p"
	.string "¡Esperamos que disfrutes del nuevo\n"
	.string "sector abierto al público!$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Esta zona aún sigue en obras.\n"
	.string "El paso está restringido, ¡perdón!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "¡Hala! ¡Yupi! ¡Jamás había visto\n"
	.string "a ninguno de estos bichitos!$"

SafariZone_Southeast_Text_FatMan:
	.string "Todos los POKéMON de este sector\n"
	.string "son completamente nuevos para mí.\p"
	.string "¡Y puedo atraparlos con total\n"
	.string "libertad! ¡Es una pasada!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Los POKéMON de estos lares parecen\n"
	.string "provenir de fuera de HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Solo me quedan un par de BALLS.\p"
	.string "Me cuesta mucho decidir qué POKéMON\n"
	.string "debería intentar atrapar.$"

SafariZone_Northeast_Text_Woman:
	.string "Dicen que por aquí se ve a PIKACHU.\n"
	.string "¿Por dónde andará escondido?$"

SafariZone_Northeast_Text_Girl:
	.string "¡Jo, qué rabia!\n"
	.string "¡No consigo atrapar a ninguno!\p"
	.string "¡Habré tirado el dinero de la\n"
	.string "entrada si salgo con las manos\l"
	.string "vacías!$"
