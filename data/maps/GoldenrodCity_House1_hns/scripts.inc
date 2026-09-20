GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "¿Quieres alternar los Colores\n"
	.string "Variocolor (Shinies) Únicos?$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "¡Ajuste de Variocolor cambiado!\p"
	.string "Puedes consultarlo en el VISOR DE\n"
	.string "RETOS de cualquier PC.$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "¡Están dando las noticias!\p"
	.string "¡La POLICÍA busca a ese CHAVAL\nPELIRROJO\l"
	.string "tan problemático!\p"
	.string "¿TÚ sabes cómo se llama?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "¡Hola, hola! ¡Soy el INSPECTOR DE\n"
	.string "MOTES! ¡Adivino la fortuna que\l"
	.string "esconde cada nombre!\p"
	.string "Será un placer evaluar los motes\n"
	.string "de tus POKéMON.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "¿El mote de qué POKéMON debería\n"
	.string "evaluar?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Mmm… {STR_VAR_1}, ¿verdad? Le has\n"
	.string "puesto un nombre bastante decente.\p"
	.string "¡Pero! ¿Qué me dices si te sugiero\n"
	.string "un mote todavía mejor?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "¡Estupendo! ¿Cómo quieres que se\n"
	.string "llame a partir de ahora?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "¡Hecho! A partir de hoy, ¡este\n"
	.string "POKéMON responderá por {STR_VAR_1}!\p"
	.string "¡Un nombre con muchísima más\nfuerza!\l"
	.string "¡Qué gran fortuna la tuya!$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ya veo.\n"
	.string "¡Pásate a verme cuando quieras!$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "¡Hecho! De ahora en adelante, ¡este\n"
	.string "POKéMON se llamará {STR_VAR_1}!\p"
	.string "Parece idéntico al de antes, pero…\n"
	.string "¡en el fondo es inmensamente\nsuperior!\p"
	.string "¡Qué gran fortuna la tuya!$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Mmm… ¡{STR_VAR_1}!\p"
	.string "¡Qué mote tan sensacional!\n"
	.string "¡Es perfecto, no tiene tacha\nalguna!\p"
	.string "Cuida con muchísimo orgullo de tu\n"
	.string "{STR_VAR_1} de ahora en adelante.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "¡Pero bueno!\n"
	.string "¡Si eso es solo un HUEVO!$"


