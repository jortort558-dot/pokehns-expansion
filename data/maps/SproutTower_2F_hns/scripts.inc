SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "However hard we battle,\n"
	.string "the TOWER will stand strong.$"

SproutTower_Text_SageNico_Beaten:
	.string "Luché con entrega, pero no bastó…$"

SproutTower_Text_SageNico_AfterBattle:
	.string "The flexible pillar protects the\n"
	.string "TOWER, even from earthquakes.$"

SproutTower_Text_SageEdmond_Seen:
	.string "… Mézclate como hojas en el viento…$"

SproutTower_Text_SageEdmond_Beaten:
	.string "¡Ay, qué débil soy!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "I tried to copy BELLSPROUT's\n"
	.string "gentle movements for battle…\p"
	.string "But I didn't train well enough.$"

SproutTower_Text_2F_Statue:
	.string "A POKéMON statue…\p"
	.string "It looks very distinguished.$"
