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
	.string "¡Vuela bien alto hacia el cielo,\nmi querido POKéMON pájaro!$"
Route38_Text_BirdKeeperTobyBeaten:
	.string "Ahora me dan ganas de salir\nvolando de aquí…$"
Route38_Text_BirdKeeperTobyAfter:
	.string "Pienso ir a entrenar a CIUDAD\nORQUÍDEA para enseñarle a volar\la mi POKéMON.$"
Route38_Text_SchoolboyChad1Seen:
	.string "¡Déjame probar algo que aprendí\nhoy en clase!$"
Route38_Text_SchoolboyChad1Beaten:
	.string "Supongo que no he estudiado lo\nsuficiente…$"
Route38_Text_SchoolboyChadAfter:
	.string "Tengo tantos exámenes que casi no\nme queda tiempo para los POKéMON.\pPor eso, cuando tengo un rato para\njugar, me concentro al máximo.$"
Route38_Text_ChadRegister:
	.string "Tengo tantos exámenes que casi no\nme queda tiempo para los POKéMON.\pPor eso, cuando tengo un rato para\njugar, me concentro al máximo.$"
Route38_Text_ChadRematchIntro:
	.string "¡Déjame probar algo que aprendí\nhoy en clase!$"
Route38_Text_ChadRematchDefeat:
	.string "Supongo que no he estudiado lo\nsuficiente…$"
Route38_Text_ChadPostRematch:
	.string "Tengo tantos exámenes que casi no\nme queda tiempo para los POKéMON.\pPor eso, cuando tengo un rato para\njugar, me concentro al máximo.$"
Route38_Text_LassDana1Seen:
	.string "Parece que se te da muy bien esto\nde los POKéMON.\pSi es así, ¿qué tal si me das\nalgún que otro consejillo?$"
Route38_Text_LassDana1Beaten:
	.string "Ya veo. Así que se puede luchar de\nesa manera…$"
Route38_Text_LassDanaAfter:
	.string "¡Sé algo muy bueno!\pLa leche de la GRANJA MU-MU es\nfamosísima por su rico sabor.$"
Route38_Text_BeautyValerieSeen:
	.string "¡Hola! ¿A que eres un Entrenador\nmonísimo?\p¿Puedo ver a tus POKéMON?$"
Route38_Text_BeautyValerieBeaten:
	.string "¡Qué alegría haber podido ver a tus\nPOKéMON!$"
Route38_Text_BeautyValerieAfter:
	.string "Ver a los POKéMON me calma los\nnervios y me da mucha paz.$"
Route38_Text_SailorHarrySeen:
	.string "¡He navegado por ultramar, así que\nconozco toda clase de POKéMON!$"
Route38_Text_SailorHarryBeaten:
	.string "¡Tu técnica es de categoría\nmundial!$"
Route38_Text_SailorHarryAfter:
	.string "Por todo el mundo hay personas de\ntodo tipo viviendo felices con los\lPOKéMON.$"
Route38_Text_BeautyOliviaSeen:
	.string "¿No te parece que mis POKéMON y yo\nsomos absolutamente divinos?$"
Route38_Text_BeautyOliviaBeaten:
	.string "Bebemos LECHE MU-MU a diario.$"
Route38_Text_BeautyOliviaAfter:
	.string "La LECHE MU-MU es fantástica para\nla belleza y la salud,\ppero es un engorro que solo te\nvendan una botella a la vez.$"
Route38_Text_Sign:
	.string "RUTA 38\pCIUDAD OLIVO - CIUDAD IRIS$"
Route38_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\pSi un POKéMON intenta evolucionar,\npuedes detenerlo.\pPulsa el Botón B durante la\nevolución para cancelarla.\pEso sobresaltará al POKéMON y\nfrenará su transformación.$"
Route38_Text_WaterSign:
	.string "PROHIBIDO NADAR Y PESCAR.\nAGUA DE USO EXCLUSIVO AGRÍCOLA.\p-CONCEJO DE CIUDAD IRIS$"
Route38_Text_DanaRegister:
	.string "¡Sé algo muy bueno!\pLa leche de la GRANJA MU-MU es\nfamosísima por su rico sabor.$"
Route38_Text_DanaRematchIntro:
	.string "Parece que se te da muy bien esto\nde los POKéMON.\pSi es así, ¿qué tal si me das\nalgún que otro consejillo?$"
Route38_Text_DanaRematchDefeat:
	.string "Ya veo. Así que se puede luchar de\nesa manera…$"
Route38_Text_DanaPostRematch:
	.string "¡Sé algo muy bueno!\pLa leche de la GRANJA MU-MU es\nfamosísima por su rico sabor.$"
Route38_Text_DanaHasItem:
	.string "¡Hola! ¡Encontré algo muy\ninteresante por aquí!\p¡Toma, para ti!$"
Route38_Text_DanaGaveItem:
	.string "¡Te avisaré si encuentro alguna\notra\lcosita!$"
Route38_Text_DanaNoRoom:
	.string "Vaya, tienes la BOLSA llena.\pVuelve cuando tengas algo de hueco.$"
