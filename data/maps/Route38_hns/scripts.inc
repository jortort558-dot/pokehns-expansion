Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "¡Vuela bien alto hacia el cielo,\n"
	.string "mi querido POKéMON pájaro!$"
Route38_Text_BirdKeeperTobyBeaten:
	.string "Ahora me dan ganas de salir\n"
	.string "volando de aquí…$"
Route38_Text_BirdKeeperTobyAfter:
	.string "Iré a entrenar a ORQUÍDEA\n"
	.string "y enseñaré VUELO a mi POKéMON.$"
Route38_Text_SchoolboyChad1Seen:
	.string "¡Déjame probar algo que aprendí\n"
	.string "hoy en clase!$"
Route38_Text_SchoolboyChad1Beaten:
	.string "Supongo que no he estudiado lo\n"
	.string "suficiente…$"
Route38_Text_SchoolboyChadAfter:
	.string "Tengo tantos exámenes que\n"
	.string "apenas me queda tiempo\l"
	.string "para mis POKéMON.\p"
	.string "Por eso, cuando puedo jugar,\n"
	.string "me concentro de verdad.$"
Route38_Text_ChadRegister:
	.string "Tengo tantos exámenes que\n"
	.string "apenas me queda tiempo\l"
	.string "para mis POKéMON.\p"
	.string "Por eso, cuando puedo jugar,\n"
	.string "me concentro de verdad.$"
Route38_Text_ChadRematchIntro:
	.string "¡Déjame probar algo que aprendí\n"
	.string "hoy en clase!$"
Route38_Text_ChadRematchDefeat:
	.string "Supongo que no he estudiado lo\n"
	.string "suficiente…$"
Route38_Text_ChadPostRematch:
	.string "Tengo tantos exámenes que\n"
	.string "apenas me queda tiempo\l"
	.string "para mis POKéMON.\p"
	.string "Por eso, cuando puedo jugar,\n"
	.string "me concentro de verdad.$"
Route38_Text_LassDana1Seen:
	.string "Parece que se te da muy bien\n"
	.string "esto de los POKéMON.\p"
	.string "Si es así, ¿qué tal si me das\n"
	.string "algún que otro consejillo?$"
Route38_Text_LassDana1Beaten:
	.string "Ya veo. Así que se puede luchar\n"
	.string "de esa manera…$"
Route38_Text_LassDanaAfter:
	.string "¡Sé algo muy bueno!\p"
	.string "La leche de la GRANJA MU-MU es\n"
	.string "famosísima por su rico sabor.$"
Route38_Text_BeautyValerieSeen:
	.string "¡Hola! ¿A que eres un Entrenador\n"
	.string "monísimo?\p"
	.string "¿Puedo ver a tus POKéMON?$"
Route38_Text_BeautyValerieBeaten:
	.string "¡Qué alegría haber podido ver a\n"
	.string "tus POKéMON!$"
Route38_Text_BeautyValerieAfter:
	.string "Ver a los POKéMON me calma los\n"
	.string "nervios y me da mucha paz.$"
Route38_Text_SailorHarrySeen:
	.string "¡He navegado por ultramar, así\n"
	.string "que conozco toda clase de\l"
	.string "POKéMON!$"
Route38_Text_SailorHarryBeaten:
	.string "¡Tu técnica es de talla mundial!$"
Route38_Text_SailorHarryAfter:
	.string "Por todo el mundo hay personas\n"
	.string "de todo tipo viviendo felices\l"
	.string "con los POKéMON.$"
Route38_Text_BeautyOliviaSeen:
	.string "¿No te parece que mis POKéMON y\n"
	.string "yo somos absolutamente divinos?$"
Route38_Text_BeautyOliviaBeaten:
	.string "Bebemos LECHE MU-MU\n"
	.string "cada día.$"
Route38_Text_BeautyOliviaAfter:
	.string "La LECHE MU-MU es fantástica\n"
	.string "para la belleza y la salud,\p"
	.string "pero es un engorro que solo te\n"
	.string "vendan una botella a la vez.$"
Route38_Text_Sign:
	.string "RUTA 38\p"
	.string "CIUDAD OLIVO - CIUDAD IRIS$"
Route38_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\p"
	.string "Si un POKéMON intenta\n"
	.string "evolucionar, puedes detenerlo.\p"
	.string "Pulsa el Botón B durante la\n"
	.string "evolución para cancelarla.\p"
	.string "Eso sobresaltará al POKéMON y\n"
	.string "frenará su transformación.$"
Route38_Text_WaterSign:
	.string "PROHIBIDO NADAR Y PESCAR. AGUA\n"
	.string "DE USO EXCLUSIVO AGRÍCOLA.\p"
	.string "-CONCEJO DE CIUDAD IRIS$"
Route38_Text_DanaRegister:
	.string "¡Sé algo muy bueno!\p"
	.string "La leche de la GRANJA MU-MU es\n"
	.string "famosísima por su rico sabor.$"
Route38_Text_DanaRematchIntro:
	.string "Parece que se te da muy bien\n"
	.string "esto de los POKéMON.\p"
	.string "Si es así, ¿qué tal si me das\n"
	.string "algún que otro consejillo?$"
Route38_Text_DanaRematchDefeat:
	.string "Ya veo. Así que se puede luchar\n"
	.string "de esa manera…$"
Route38_Text_DanaPostRematch:
	.string "¡Sé algo muy bueno!\p"
	.string "La leche de la GRANJA MU-MU es\n"
	.string "famosísima por su rico sabor.$"
Route38_Text_DanaHasItem:
	.string "¡Hola! ¡Encontré algo muy\n"
	.string "interesante por aquí!\p"
	.string "¡Toma, para ti!$"
Route38_Text_DanaGaveItem:
	.string "¡Te avisaré si encuentro alguna\n"
	.string "otra cosita!$"
Route38_Text_DanaNoRoom:
	.string "Vaya, tienes la BOLSA llena.\p"
	.string "Vuelve cuando tengas algo de\n"
	.string "hueco.$"
