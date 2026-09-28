Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "Estoy mejorando mis POKéMON.\n"
	.string "¿Quieres luchar contra mí?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "¡Argh! He perdido esta vez…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Si quieres mejorar un POKéMON,\n"
	.string "ponlo primero y cámbialo\l"
	.string "nada más empezar.\p"
	.string "Así es como hay que hacerlo.$"

Route4_Text_PicnickerHope_Seen:
	.string "Presiento que puedo ganar.\p"
	.string "¡Veamos si tengo razón!$"

Route4_Text_PicnickerHope_Beaten:
	.string "¡Uau! Eres demasiado fuerte.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "Dicen que CLEFAIRY aparece en\n"
	.string "MT. MOON. Pero ¿dónde?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Mmm…\n"
	.string "Yo…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "…Creo que seguiré entrenándome…$"

Route4_Text_MtMoonSquareSign:
	.string "NUEVA ENTRADA A MT. MOON\n"
	.string "POR DERRUMBE\p"
	.string "MIRA DÓNDE PISAS$"
