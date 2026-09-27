Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "¿Has nadado alguna vez en el mar\n"
	.string "por la noche?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glub…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "De noche, el mar se vuelve negro.\n"
	.string "Parece que vaya a tragarte.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Jadeo… Solo… un poco…\p"
	.string "más… hasta… FUCSIA…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "¡Me ahogo!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "Le… pedí a mi novia ir nadando\n"
	.string "hasta FUCSIA… Jadeo…$"

Route19_Text_SwimmerfDawnSeen:
	.string "¡La gente debilucha me da asco!$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Nadando sí podría ganarte…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "Se nada rápido entre FUCSIA y las\n"
	.string "ISLAS ESPUMA…\p"
	.string "¡Menudo hombretón es mi novio!\n"
	.string "¡Qué blandengue!$"

Route19_Text_SwimmermJeromeSeen:
	.string "¿Nadar? Se me da fatal.\p"
	.string "Solo chapoteo por estas aguas\n"
	.string "poco profundas.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Creía que podría ganar.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Puede que nade mal, pero me encanta\n"
	.string "el mar.$"

Route19_Text_Fisher1:
	.string "Lo siento. Esta ruta está cerrada\n"
	.string "por obras.\p"
	.string "Para llegar a CANELA, ve hacia el\n"
	.string "sur desde PUEBLO\l"
	.string "PALETA.$"

Route19_Text_Kingler:
	.string "KINGLER: KEEEEEEEEEEEE$"

Route19_Text_Fisher1_RocksCleared:
	.string "Estoy sudando. ¡Hora de nadar!$"

Route19_Text_Fisher2:
	.string "Vaya, los KINGLER bloquean la\n"
	.string "playa.$"

Route19_Text_FisherBefore:
	.string "No se puede pescar hasta que se\n"
	.string "marchen estos KINGLER.$"

Route19_Text_Fisher2_RocksCleared:
	.string "¡Por fin se fueron los KINGLER!\p"
	.string "Ya puedo volver a pescar.$"

Route19_Text_Sign:
	.string "RUTA 19\p"
	.string "CIUDAD FUCSIA - ISLAS ESPUMA$"

Route19_Text_CarefulSwimmingSign:
	.string "Ten cuidado si vas nadando hasta\n"
	.string "las ISLAS ESPUMA.\p"
	.string "POLICÍA DE FUCSIA$"
