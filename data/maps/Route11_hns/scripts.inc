Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "Vi un POKéMON extraño trepando\n"
	.string "por los árboles, pero no parecía\l"
	.string "un MANKEY…$"

Route11_Text_YoungsterOwenSeen:
	.string "En los combates POKéMON no vale\n"
	.string "hacer trampas.\p"
	.string "¡Luchemos limpiamente!$"

Route11_Text_YoungsterOwenBeaten:
	.string "¿Eh? ¿Cómo ha pasado esto?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "He combatido limpiamente\n"
	.string "y con honor.\p"
	.string "No me arrepiento de nada.$"

Route11_Text_YoungsterJasonSeen:
	.string "La hierba pica y hace cosquillas\n"
	.string "cuando llevo pantalones cortos.$"

Route11_Text_YoungsterJasonBeaten:
	.string "¡Aaaah! ¡Me has aplastado!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Voy a capturar más POKéMON\n"
	.string "entre la hierba.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "He perdido por cerrar los ojos…$"

Route11_Text_PsychicFidelSeen:
	.string "Puedo verlo…\p"
	.string "Todo lo que hay que saber de ti…$"

Route11_Text_PsychicFidelBeaten:
	.string "No pude prever tu poder…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "La fuerza nace de la convicción…\p"
	.string "Eres fuerte porque confías\n"
	.string "en tus POKéMON.$"

Route11_Text_Sign:
	.string "RUTA 11$"
