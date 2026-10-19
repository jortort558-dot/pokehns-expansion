Akala_Forest_hns_MapScripts::
	.byte 0


Alola_Akala_Forest_FindItem1::
	finditem ITEM_FULL_RESTORE, 1
	end


Alola_Akala_Forest_FindItem2::
	finditem ITEM_PP_UP, 1
	end


Alola_AkalaForest_TrainerBattleBugCatcher1::
	trainerbattle_single TRAINER_AKALA_FOREST_BUGCATCHER_1_HNS, Alola_AkalaForest_TrainerBattleBugCatcher1_Text_0, Alola_AkalaForest_TrainerBattleBugCatcher1_Text_1
	msgbox Alola_AkalaForest_TrainerBattleBugCatcher1_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaForest_TrainerBattleBugCatcher2::
	trainerbattle_single TRAINER_AKALA_FOREST_BUGCATCHER_2_HNS, Alola_AkalaForest_TrainerBattleBugCatcher2_Text_0, Alola_AkalaForest_TrainerBattleBugCatcher2_Text_1
	msgbox Alola_AkalaForest_TrainerBattleBugCatcher2_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_BattleRaichu::
	lock
	faceplayer
	setflag FLAG_BATTLED_RAICHU
	playmoncry SPECIES_RAICHU_ALOLA, 0
	msgbox Alola_Akala_BattleRaichu_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RAICHU_ALOLA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Akala_BattleRaichu_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_BattleRaichu_3
	release
	end

	release
	end

Alola_Akala_BattleRaichu_2:
	setflag FLAG_HIDE_RAICHU_ALOLA
	removeobject LOCALID_AKALA_RAICHU
	release
	end

Alola_Akala_BattleRaichu_3:
	setflag FLAG_HIDE_RAICHU_ALOLA
	removeobject LOCALID_AKALA_RAICHU
	release
	end


Alola_AkalaForest_TrainerBattleBugCatcher1_Text_0:
	.string "¡Mira cuántos bichos tan chulos hay\nen las ISLAS!$"

Alola_AkalaForest_TrainerBattleBugCatcher1_Text_1:
	.string "¡Ay, eso ha dolido!$"

Alola_AkalaForest_TrainerBattleBugCatcher1_Text_2:
	.string "Las ISLAS están lejos de tierra firme,\n"
	.string "así que los POKéMON de tipo Bicho\l"
	.string "se han adaptado al entorno.$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_0:
	.string "¡Mira lo que he cazado!$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_1:
	.string "¡Vaya mordisco!$"

Alola_AkalaForest_TrainerBattleBugCatcher2_Text_2:
	.string "El clima es algo distinto aquí en las\n"
	.string "ISLAS ALOLA…\p"
	.string "¡Por eso seguro que hay POKéMON de\n"
	.string "tipo Bicho únicos por aquí!$"


Alola_Akala_BattleRaichu_Text_0:
	.string "¡Gaaah!$"

