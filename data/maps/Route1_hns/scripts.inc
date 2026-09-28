Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Luchar es lo primero que hacen\n"
	.string "los Entrenadores al encontrarse.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Tengo un récord de derrotas…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Es natural que los Entrenadores\n"
	.string "luchemos al encontrarnos.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "¡Eh, tú! ¿Quieres luchar?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "He perdido…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Eres fuerte.\p"
	.string "Está claro que has entrenado\n"
	.string "mucho.$"

Route1_Text_Sign:
	.string "RUTA 1\p"
	.string "PUEBLO PALETA - CIUDAD VERDE$"
