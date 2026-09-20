Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "El agua está templada.\nEstoy ágil y en forma.\p¡Venga, acepto tu reto!$"
Route41_Text_SwimmermCharlieBeaten:
	.string "¡Uf! ¡Se me han arrugado las yemas!$"
Route41_Text_SwimmermCharlieAfter:
	.string "¿A que relaja un montón flotar así?$"
Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Estoy agotado.\nSi gano, préstame a tu POKéMON.$"
Route41_Text_SwimmermGeorgeBeaten:
	.string "Uf, jadeo, jadeo…$"
Route41_Text_SwimmermGeorgeAfter:
	.string "Está lejísimos CIUDAD ORQUÍDEA.\pY volver nadando a OLIVO tampoco es\nnada fácil.\p¿Qué se supone que hago ahora?$"
Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "¿Ves esas islas rodeadas por\ntorbellinos?\l¡Seguro que esconden algún gran\lsecreto!$"
Route41_Text_SwimmermBerkeBeaten:
	.string "¿Cuál es el secreto de tu fuerza?$"
Route41_Text_SwimmermBerkeAfter:
	.string "Era una noche oscura y de tormenta…\pVi a un POKéMON colosal salir\nvolando\lde las islas.\pIba esparciendo plumas desde sus\nalas\lplateadas.$"
Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Las olas son muy bravas por aquí.\nTe agotan en un santiamén mientras\lnadas.$"
Route41_Text_SwimmermKirkBeaten:
	.string "¡Estoy machacado!$"
Route41_Text_SwimmermKirkAfter:
	.string "Las corrientes marinas me impiden\nalcanzar esa isla.$"
Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "¿Andas buscando los misterios de\nlas\lISLAS REMOLINO?$"
Route41_Text_SwimmermMathewBeaten:
	.string "¡Oye, tienes un aguante de hierro!$"
Route41_Text_SwimmermMathewAfter:
	.string "Un misterio de las ISLAS REMOLINO…\p¡Por dentro reina la más absoluta\noscuridad!$"
Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Voy rumbo a las ISLAS REMOLINO.\pHe quedado con unos amigos para ir\na\lexplorar.$"
Route41_Text_SwimmerfKayleeBeaten:
	.string "¿Así es como se hace?$"
Route41_Text_SwimmerfKayleeAfter:
	.string "Dicen que hay un gran POKéMON en\nlas\lprofundidades de las ISLAS\lREMOLINO.\p¿Qué criatura será?$"
Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Qué porte tan elegante tienes sobre\ntu POKéMON.$"
Route41_Text_SwimmerfSusieBeaten:
	.string "¡Me has aplastado…!$"
Route41_Text_SwimmerfSusieAfter:
	.string "¿No había una canción famosa sobre\nun niño\la lomos de un LAPRAS?$"
Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Hace un día tan radiante que estoy\nempanada de felicidad.$"
Route41_Text_SwimmerfDeniseBeaten:
	.string "¡Aaaay!$"
Route41_Text_SwimmerfDeniseAfter:
	.string "Las quemaduras de sol son lo peor\npara\lla piel.\pPero no me echo crema protectora:\n¡no pienso contaminar el mar!$"
Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si necesitas descansar, ponte a\nhacer la\lmuerta.\pRecuperarás el aliento para seguir\nnadando\lcon brío.$"
Route41_Text_SwimmerfKaraBeaten:
	.string "¡Vaya! Tienes bastante más energía\nque yo.$"
Route41_Text_SwimmerfKaraAfter:
	.string "He escuchado rugidos que venían del\ninterior de las ISLAS.$"
Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "De noche, los STARYU suben a la\nsuperficie del agua.$"
Route41_Text_SwimmerfWendyBeaten:
	.string "¡Madre mía…!$"
Route41_Text_SwimmerfWendyAfter:
	.string "Los grupos de STARYU se iluminan\ntodos a\lla vez.\pEs tan hermoso que hasta da\nescalofríos.$"
Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruuuu...$"
Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: ¡CRUUUUUU!$"
Route41_Text_TentacruelHeal:
	.string "¡El TENTACRUEL usó RECUPERACIÓN!\n¡Se ha curado por completo!$"
