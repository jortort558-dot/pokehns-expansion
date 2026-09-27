Route10_PowerPlantBackRoom_hns_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	setvar VAR_VERMILION_CITY_SAMSON, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "DIRECTOR: ¡Estoy que exploto!\p"
	.string "¿Quién se atreve a destrozar mi\n"
	.string "generador?\p"
	.string "¡Le dediqué muchísimo tiempo!\p"
	.string "¡Si lo atrapo, probará mi\n"
	.string "ELECTROCAÑÓN!$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "DIRECTOR: ¡Nunca"
	.string "\nle perdonaré!"
	.string "\pAunque el culpable"
	.string "\nllore y suplique"
	.string "\pperdón, ¡le"
	.string "\nmachacaré!"
	.string "\p$¡Ja, ja, ja!"
Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "DIRECTOR: ¡Ah! ¡Sí!\p"
	.string "¡Es la PIEZA que le faltaba a mi\n"
	.string "querido generador! ¿La hallaste?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "¡Yuju! ¡Gracias!"
	.string "\p¡Toma esta MT"
	.string "\n$como recompensa!"
Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "DIRECTOR: Esa MT contiene TRUENO.\p"
	.string "¡Es una técnica muy potente!\p"
	.string "No destaca por su precisión, pero\n"
	.string "¡golpea con una fuerza tremenda!$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "DIRECTOR: ¡Mi querido generador!\p"
	.string "¡Sigue produciendo electricidad!$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "Sin energía, esta puerta no es\n"
	.string "segura.$"
