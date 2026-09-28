GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "Uf, qué cansancio.\p"
    .string "A veces subo a la azotea para\n"
    .string "descansar de las compras.$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "¿Perdona? ¿Quién dice que esto no\n"
    .string "es para adultos?\p"
    .string "¡Volveré cada día hasta reunir\n"
    .string "todos los muñecos!$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "De vez en cuando hacen aquí\n"
    .string "ventas de saldos.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "¡Oh, vaya!$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "¿Quieres dejar de molestarme?$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "Quiero una cosa, pero no tengo\n"
    .string "suficiente dinero…\p"
    .string "Quizá venda las BAYAS que reuní…$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "¡Oh, todo está baratísimo!\p"
    .string "¡He comprado tanto que mi BOLSA\n"
    .string "está a reventar!$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "Mis POKéMON siempre acaban\n"
    .string "paralizados o envenenados…\p"
    .string "He venido a comprar CURA TOTAL.\n"
    .string "¿Quedará alguna?$"
