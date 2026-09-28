Route21_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH_HNS, Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI_HNS, Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD_HNS, Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "¡Tierra a la vista! ¡A seguir!$"

Route21_Text_SwimmermSethBeaten:
	.string "Glug…$"

Route21_Text_SwimmermSethAfterBattle:
	.string "Ese tipo arrogante estaba en el\n"
	.string "volcán de CANELA.$"

Route21_Text_SwimmerfNikkiSeen:
	.string "¡Si gano, tendrás que ayudarme con\n"
	.string "la crema solar!$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "Me preocupan las quemaduras…$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "Debo cuidarme de las manchas que\n"
	.string "provoca el sol.$"

Route21_Text_FisherArnoldSeen:
	.string "Pescar me aburre. ¡Combatamos!$"

Route21_Text_FisherArnoldBeaten:
	.string "Fracaso absoluto…$"

Route21_Text_FisherArnoldAfterBattle:
	.string "Volveré a pescar…$"
