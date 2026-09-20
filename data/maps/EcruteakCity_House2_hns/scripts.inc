EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. ¿Estás de aventura con tus\nPOKéMON?\pBueno, ¿y qué clase de aventura\nsería\lsin buscar tesoros escondidos?\p¿Tengo razón o no la tengo?$"
Ecruteak_Text_ItemfinderTrueSpirit:
	.string "¡Muy bien! Comprendes el auténtico\nespíritu aventurero.\p¡Me gusta esa actitud! Llévate\nesto.$"
Ecruteak_Text_ItemfinderExplanation:
	.string "Hay muchos objetos tirados por el\nsuelo\lque no se ven a simple vista.\pUsa el BUSCAOBJETOS para detectar\nsi hay\lalgo oculto cerca de ti.\pNo te marcará el punto exacto, así\nque\ltendrás que rebuscar tú mismo.\p¡Ah, por cierto! Dicen que hay\nobjetos\lperdidos en la TORRE QUEMADA.$"
Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh... Cada cual con sus gustos,\nsupongo...$"
EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ECRUTEAK is a very old city.\n"
	.string "Many generations passed down\l"
	.string "their history in books like these.$"

Ecruteak_Text_HistoryBook:
	.string "HISTORIA DE CIUDAD IRIS\p¿Quieres leerla?$"
Ecruteak_Text_TwoTowers:
	.string "En CIUDAD IRIS había dos grandes\ntorres.\pCada torre era el hogar de un\npoderoso\lPOKéMON volador.\pSin embargo, una de las torres\nardió\lhasta quedar reducida a cenizas.\pDesde entonces, ninguno de los dos\nPOKéMON ha vuelto a ser visto...\p¿Quieres seguir leyendo?$"
Ecruteak_Text_ThreeMon:
	.string "CIUDAD IRIS también albergaba tres\nPOKéMON que corrían veloces por el\llugar.\pSe decía que habían nacido del\nagua, el\lrayo y el fuego.\pPero su poder desmedido era\nimposible de\lcontener.\lPor eso cuentan que los tres\lpartieron\lcomo el viento hacia los prados.$"
