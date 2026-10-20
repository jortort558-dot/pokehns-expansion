MtSilver_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER_HNS
	end

MtSilver_PokemonCenter_EventScript_Meara::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 1, MtSilver_PokemonCenter_EventScript_Meara_AfterUnlockSinjoh
	checkitem ITEM_AZURE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, MtSilver_PokemonCenter_EventScript_Meara_NoFlute
	goto_if_unset FLAG_IS_KANTO_CHAMPION, MtSilver_PokemonCenter_EventScript_Meara_NeedKantoLeague
	goto MtSilver_PokemonCenter_EventScript_Meara_BonusContentPrompt

MtSilver_PokemonCenter_EventScript_Meara_NoFlute:
	msgbox MtSilver_PokemonCenter_Text_Meara1, MSGBOX_AUTOCLOSE
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_NeedKantoLeague:
	msgbox MtSilver_PokemonCenter_Text_MearaNeedKantoLeague, MSGBOX_AUTOCLOSE
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_BonusContentPrompt::
	msgbox MtSilver_PokemonCenter_Text_Meara2, MSGBOX_AUTOCLOSE
	helpwindow HELP_SINJOH_WINDOW
	
	msgbox MtSilver_PokemonCenter_Text_Prompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MtSilver_PokemonCenter_EventScript_Meara_BonusContentNo
	closemessage

	@sinjoh flagheap
	clearflag FLAG_MT_SILVER_1F_HIDE_SCIENTIST
    setflag FLAG_HIDE_SNOWSWEPT_NOBLE_SNEASLER
	setflag FLAG_HIDE_ROUTE49_NOBLE_WYRDEER
	setflag FLAG_HIDE_ROUTE49_NOBLE_OVERQWIL
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_ARCANINE
	setflag FLAG_HIDE_HOTSPRINGS_NOBLE_URSALUNA
	setflag FLAG_HIDE_ROUTE50_NOBLE_ELECTRODE
	setflag FLAG_HIDE_ROUTE50_NOBLE_KLEAVOR
	setflag FLAG_HIDE_NEWSINJOH_HOUSE3_NOBLE_TYPHLOSION
	setflag FLAG_HIDE_SINJOHRUINS_STEVEN
	setflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_ARCEUS
	setflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_STEVEN
	setflag FLAG_HIDE_NEWSINJOH_STEVEN
	setvar VAR_SINJOH_STORYLINE, 1
	setvar VAR_PLATECOUNTER, 0
	setvar VAR_REGIS_SCANNED, 0
	warp MAP_MT_SILVER_1F_WATERFALL_ROOM_HNS, 43, 9
	waitstate
	end

MtSilver_PokemonCenter_EventScript_Meara_BonusContentNo::
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_AfterUnlockSinjoh::
	msgbox MtSilver_PokemonCenter_Text_Meara3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MtSilver_PokemonCenter_EventScript_Meara_WarpToSinjoh
	closemessage
	release
	end

MtSilver_PokemonCenter_EventScript_Meara_WarpToSinjoh::
	warp MAP_MT_SILVER_1F_WATERFALL_ROOM_HNS, 43, 9
	waitstate
	release
	end

MtSilver_PokemonCenter_Text_Meara1:
	.string "Soy investigadora del… Ejem…\n"
	.string "¡MUSEO de CIUDAD PLATEADA!\p"
	.string "Aquí se han descubierto muchísimos\n"
	.string "artefactos. Vine a estudiarlos.\p"
	.string "¿Has hallado algo extraño en la\n"
	.string "montaña?\p"
	.string "¿Quizá algo parecido a una FLAUTA?\p"
	.string "Si lo haces, enséñamelo.$"

MtSilver_PokemonCenter_Text_MearaNeedKantoLeague:
	.string "¡Esa flauta es la legendaria\n"
	.string "FLAUTA AZUR!\p"
	.string "Desbloquea el paso hacia las\n"
	.string "tierras olvidadas de SINJOH.\p"
	.string "Sin embargo, ese territorio está\n"
	.string "habitado por fuerzas titánicas\l"
	.string "de poder inconmensurable.\p"
	.string "No permitiré que nadie vaya allí\n"
	.string "sin demostrar antes ser digno de\l"
	.string "vencer la revancha de la LIGA\l"
	.string "POKéMON tras conquistar KANTO.\p"
	.string "¡Consigue ese galardón supremo y te\n"
	.string "abriré el camino!$"

MtSilver_PokemonCenter_Text_Meara2:
	.string "¡Esa flauta!\p"
	.string "¡Tienes alma de auténtico\n"
	.string "arqueólogo!\p"
	.string "Hay un ramal de la cueva con\n"
	.string "POKéMON demasiado fuertes para mí.\p"
	.string "Si te llevo, ¿buscarás más\n"
	.string "artefactos?$"

MtSilver_PokemonCenter_Text_Prompt:
	.string "Si te llevo, ¿buscarás más\n"
	.string "artefactos?$"

MtSilver_PokemonCenter_Text_Meara3:
	.string "¿Listo para buscar más artefactos?$"
