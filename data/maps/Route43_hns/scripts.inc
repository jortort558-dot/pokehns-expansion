Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
	.string "¡Me encantan los POKéMON!\pPor eso empecé a coleccionarlos\ny pienso seguir haciéndolo.$"
Route43_Text_PokemaniacBenBeaten:
	.string "¿Cómo has podido hacerme esto?$"
Route43_Text_PokemaniacBenAfter:
	.string "¿Qué más me gusta aparte de los\nPOKéMON?\pROSA, la locutora de radio.\n¡Seguro que es muy guapa!$"
Route43_Text_PokemaniacBrentSeen:
	.string "¡Ey! ¿Tienes algún POKéMON raro?$"
Route43_Text_PokemaniacBrentBeaten:
	.string "¡Ay, mis pobres POKéMON queridos!$"
Route43_Text_PokemaniacBrentAfter:
	.string "Sería feliz con tener un solo\nPOKéMON raro.$"
Route43_Text_BrentRegister:
	.string "Sería feliz con tener un solo\nPOKéMON raro.$"
Route43_Text_BrentRematchIntro:
	.string "¡Ey! ¿Tienes algún POKéMON raro?$"
Route43_Text_BrentRematchDefeat:
	.string "¡Ay, mis pobres POKéMON queridos!$"
Route43_Text_BrentPostRematch:
	.string "Sería feliz con tener un solo\nPOKéMON raro.$"
Route43_Text_PokemaniacRonSeen:
	.string "¿Te lo puedes creer?\p¡Un tal {RIVAL} se burló de mis\nPOKéMON!\p¡Maldita sea! ¡Mis POKéMON son\ngeniales!$"
Route43_Text_PokemaniacRonBeaten:
	.string "¡Mi NIDOKING lo hizo muy bien!$"
Route43_Text_PokemaniacRonAfter:
	.string "Está bien que a cada cual le gusten\ntipos de POKéMON distintos.\pEsto no consiste solo en tener al\nPOKéMON más poderoso.$"
Route43_Text_FisherMarvinSeen:
	.string "Estoy en mala racha.\pQuizá sea por el equipo que uso.\p¡Combatamos para cambiar de aires!$"
Route43_Text_FisherMarvinBeaten:
	.string "He perdido, pero al menos me he\ndesfogado.$"
Route43_Text_FisherMarvinAfter:
	.string "La CEBO BALL de CÉSAR es la mejor\npara capturar POKéMON pescados.\pEs mucho más eficaz que una\nULTRA BALL.$"
Route43_Text_CamperSpencerSeen:
	.string "Puedo hacer muchísimas cosas con\nmis POKéMON. ¡Es muy divertido!$"
Route43_Text_CamperSpencerBeaten:
	.string "Perder no tiene ninguna gracia…$"
Route43_Text_CamperSpencerAfter:
	.string "¿Qué ocurre en el LAGO DE LA FURIA?\pPensábamos acampar allí.$"
Route43_Text_PicnickerTiffanySeen:
	.string "¿También vas al LAGO DE LA FURIA?\p¡Juguemos un rato antes!$"
Route43_Text_PicnickerTiffanyBeaten:
	.string "¡He jugado de más!$"
Route43_Text_PicnickerTiffanyWantsPicnic:
	.string "Estoy de pícnic con mis POKéMON.\p¿Quieres acompañarnos?$"
Route43_Text_TiffanyRegister:
	.string "Estoy de pícnic con mis POKéMON.\p¿Quieres acompañarnos?$"
Route43_Text_TiffanyRematchIntro:
	.string "¿También vas al LAGO DE LA FURIA?\p¡Juguemos un rato antes!$"
Route43_Text_TiffanyRematchDefeat:
	.string "¡He jugado de más!$"
Route43_Text_TiffanyPostRematch:
	.string "Estoy de pícnic con mis POKéMON.\p¿Quieres acompañarnos?$"
Route43_Sign1:
	.string "RUTA 43\pLAGO DE LA FURIA - PUEBLO CAOBA$"
Route43_Sign2:
	.string "RUTA 43\pLAGO DE LA FURIA - PUEBLO CAOBA$"
Route43_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\pTodos los POKéMON tienen ventajas y\ndesventajas según sus tipos.\pSi los tipos difieren, hasta un\nPOKéMON de más nivel puede perder.\pAprende qué tipos son fuertes y\ndébiles contra tus POKéMON.$"
