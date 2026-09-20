Route32_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32_HNS
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "Este es un rincón de pesca ideal.\p"
	.string "¿Viste a gente pescando fuera?\n"
	.string "¿Y tú?\p"
	.string "¿Te gustaría tener una de mis CAÑAS?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "¡Je, je, me alegra oír eso!\p"
	.string "¡Desde hoy ya eres pescador!$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "¡Pescar es genial!\p"
	.string "Donde haya agua, ya sea en mar o\n"
	.string "río, ¡prueba a usar tu CAÑA!$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "Vaya, qué decepción… Tú te lo pierdes.$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "¡Hola! ¿Pican o no pican esos peces?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "¿Qué objeto debería equipar a mi\n"
	.string "POKéMON?\p"
	.string "Quizá uno que potencie su ATAQUE…$"

