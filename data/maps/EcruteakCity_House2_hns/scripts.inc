EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. ¿Estás de aventura con tus\n"
	.string "POKéMON?\p"
	.string "Bueno, ¿y qué clase de aventura\n"
	.string "sería sin buscar tesoros\l"
	.string "escondidos?\p"
	.string "¿Tengo razón o no la tengo?$"
Ecruteak_Text_ItemfinderTrueSpirit:
	.string "¡Muy bien! Comprendes el\n"
	.string "auténtico espíritu aventurero.\p"
	.string "¡Me gusta esa actitud! Llévate\n"
	.string "esto.$"
Ecruteak_Text_ItemfinderExplanation:
	.string "Hay muchos objetos tirados por\n"
	.string "el suelo que no se ven a simple\l"
	.string "vista.\p"
	.string "Usa el BUSCAOBJETOS para\n"
	.string "detectar si hay algo oculto\l"
	.string "cerca de ti.\p"
	.string "No te marcará el punto exacto,\n"
	.string "así que tendrás que rebuscar tú\l"
	.string "mismo.\p"
	.string "¡Ah, por cierto! Dicen que hay\n"
	.string "objetos perdidos en la TORRE\l"
	.string "QUEMADA.$"
Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh... Cada cual con sus gustos,\n"
	.string "supongo...$"
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
	.string "CIUDAD IRIS es muy antigua.\n"
	.string "Muchas generaciones han legado\l"
	.string "su historia en libros como\l"
	.string "estos.$"

Ecruteak_Text_HistoryBook:
	.string "HISTORIA DE CIUDAD IRIS\p"
	.string "¿Quieres leerla?$"
Ecruteak_Text_TwoTowers:
	.string "En CIUDAD IRIS había dos grandes\n"
	.string "torres.\p"
	.string "Cada torre era el hogar de un\n"
	.string "poderoso POKéMON volador.\p"
	.string "Sin embargo, una de las torres\n"
	.string "ardió hasta quedar reducida a\l"
	.string "cenizas.\p"
	.string "Desde entonces, ninguno de los\n"
	.string "dos POKéMON ha vuelto a ser\l"
	.string "visto...\p"
	.string "¿Quieres seguir leyendo?$"
Ecruteak_Text_ThreeMon:
	.string "CIUDAD IRIS también albergaba\n"
	.string "tres POKéMON que corrían veloces\l"
	.string "por el lugar.\p"
	.string "Se decía que habían nacido del\n"
	.string "agua, el rayo y el fuego.\p"
	.string "Pero su poder desmedido era\n"
	.string "imposible de contener. Por eso\l"
	.string "cuentan que los tres partieron\l"
	.string "como el viento hacia los prados.$"
