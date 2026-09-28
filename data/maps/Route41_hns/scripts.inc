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
	.string "El agua está templada.\nEstoy ágil y en forma.\p¡Claro, acepto tu reto!$"
Route41_Text_SwimmermCharlieBeaten:
	.string "¡Uf! ¡Tengo la piel arrugada!$"
Route41_Text_SwimmermCharlieAfter:
	.string "¿No es relajante flotar\nasí?$"
Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Estoy agotado.\nSi gano, préstame a tu POKéMON.$"
Route41_Text_SwimmermGeorgeBeaten:
	.string "Uf, jadeo, jadeo…$"
Route41_Text_SwimmermGeorgeAfter:
	.string "ORQUÍDEA está muy lejos.\pPero tampoco es fácil volver\nnadando hasta OLIVO.\p¿Qué debería hacer?$"
Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "¿Ves esas islas bloqueadas\npor torbellinos?\p¡Seguro que esconden un secreto!$"
Route41_Text_SwimmermBerkeBeaten:
	.string "¿Cuál es el secreto de\ntu fuerza?$"
Route41_Text_SwimmermBerkeAfter:
	.string "Era una noche oscura y tormentosa…\pVi un POKéMON enorme que salía\nvolando de las islas.\pIba esparciendo plumas\nde sus alas plateadas.$"
Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Las olas son muy bravas aquí.\pTe agotan mientras\nnadas.$"
Route41_Text_SwimmermKirkBeaten:
	.string "¡Estoy machacado!$"
Route41_Text_SwimmermKirkAfter:
	.string "Las corrientes me impiden\nllegar a esa isla.$"
Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "¿Buscas los misterios\nde las ISLAS REMOLINO?$"
Route41_Text_SwimmermMathewBeaten:
	.string "¡Oye, tienes un aguante de hierro!$"
Route41_Text_SwimmermMathewAfter:
	.string "Un misterio de las ISLAS REMOLINO…\p¡Por dentro está totalmente oscuro!$"
Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Voy hacia las ISLAS REMOLINO.\pIré a explorarlas con mis amigos.$"
Route41_Text_SwimmerfKayleeBeaten:
	.string "¿Así es como se hace?$"
Route41_Text_SwimmerfKayleeAfter:
	.string "Dicen que hay un gran POKéMON\nbajo las ISLAS REMOLINO.\p¿Qué criatura será?$"
Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Qué elegancia tienes\nmontando en tu POKéMON.$"
Route41_Text_SwimmerfSusieBeaten:
	.string "¡Me has aplastado…!$"
Route41_Text_SwimmerfSusieAfter:
	.string "¿No había una canción famosa\nsobre un niño montado en LAPRAS?$"
Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Hace un día tan bonito\nque estoy embobada.$"
Route41_Text_SwimmerfDeniseBeaten:
	.string "¡Aaaay!$"
Route41_Text_SwimmerfDeniseAfter:
	.string "El sol es lo peor para la piel.\pPero no uso crema solar.\pNo pienso contaminar el agua.$"
Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si necesitas descansar,\nhaz el muerto.\pRecuperarás el aliento\ny podrás seguir con fuerza.$"
Route41_Text_SwimmerfKaraBeaten:
	.string "¡Vaya! Tienes más energía que yo.$"
Route41_Text_SwimmerfKaraAfter:
	.string "Oí rugidos procedentes del\ninterior de las ISLAS.$"
Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "De noche, los STARYU se reúnen\ncerca de la superficie.$"
Route41_Text_SwimmerfWendyBeaten:
	.string "¡Madre mía…!$"
Route41_Text_SwimmerfWendyAfter:
	.string "Los grupos de STARYU se iluminan\ntodos a la vez.\pEs tan bonito que hasta asusta.$"
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
