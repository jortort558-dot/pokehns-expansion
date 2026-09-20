UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "Hace mucho que no veía\n"
	.string "a otra persona.\p"
	.string "No seas tímido. ¡Combatamos!$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Uurggh…$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Llevo perdido mucho tiempo…\p"
	.string "No estoy mal aquí, pero tengo\n"
	.string "¡muchííísima hambre!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "¡Vaya! ¡Una visita!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "¡Ja, ja! ¡Tienes mucho carácter!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Vivo aquí abajo.\p"
	.string "Tú también puedes, si quieres.\p"
	.string "Como ves, hay sitio de sobra.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "¿Quién anda ahí?\p"
	.string "¡Déjanos en paz a mí y mis POKéMON!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "¡Vete…! ¡Déjame en paz!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Solo estamos mis POKéMON y yo.\n"
	.string "¡No podría ser más feliz!$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "He venido a investigar los POKéMON.\p"
	.string "¡Déjame mostrarte mis hallazgos en\n"
	.string "un combate de verdad!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "¡Me has usado de experimento!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Debería recopilar y publicar los\n"
	.string "resultados de mi estudio.\p"
	.string "Quizá llegue a ser famoso como el\n"
	.string "PROF. ELM.$"
