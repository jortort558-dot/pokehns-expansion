Route18_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Trigger_HideKecleon0::
	setvar VAR_TEMP_0, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_ROUTE18_KECLEON0
	end

Route18_EventScript_Trigger_HideKecleon1::
	setvar VAR_TEMP_1, 1
	setflag FLAG_TEMP_2
	removeobject LOCALID_ROUTE18_KECLEON1
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS_HNS, Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB_HNS, Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "Si buscas POKéMON, tendrás que\n"
	.string "mirar en la hierba alta.$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "¡Aaaay!$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "Con lo fuerte que eres, combatir\n"
	.string "debe de ser divertido.$"

Route18_Text_BirdKeeperBobSeen:
	.string "El CARRIL BICI es un atajo rápido\n"
	.string "hasta AZULONA.$"

Route18_Text_BirdKeeperBobBeaten:
	.string "…¡Uf!$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "Si no tienes una BICI, no puedes\n"
	.string "usar\l"
	.string "el atajo.$"

Route18_Text_Sign:
	.string "RUTA 18\p"
	.string "CIUDAD AZULONA - CIUDAD FUCSIA$"
