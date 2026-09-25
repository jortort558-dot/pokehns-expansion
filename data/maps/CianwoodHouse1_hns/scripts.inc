CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "No recuerdo la última vez\n"
	.string "que alguien vino a visitarme.\p"
	.string "De joven también fui Entrenador\n"
	.string "POKéMON. Intenté llegar a la torre\l"
	.string "y sumergirme en el océano.\p"
	.string "Puse mucho empeño en muchas\n"
	.string "cosas.\p"
	.string "Ahora me lo tomo con calma,\n"
	.string "escuchando las olas y el viento\l"
	.string "en esta playa.$"

CianwoodCity_Text_BellTowerStory:
	.string "¿Conoces la TORRE HOJALATA de\n"
	.string "CIUDAD IRIS?\p"
	.string "En lo alto están las llamadas\n"
	.string "CAMPANAS CLARAS.\p"
	.string "No suenan ni siquiera cuando\n"
	.string "sopla un viento fuerte.\p"
	.string "Solo hay una forma de hacerlas\n"
	.string "sonar:\p"
	.string "conseguir otra CAMPANA CLARA\n"
	.string "como las que hay en lo alto\l"
	.string "de la torre.\p"
	.string "La busqué cuando era joven,\n"
	.string "pero nunca conseguí una…$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "¿Conoces las ISLAS REMOLINO?\p"
	.string "En la poza de su cascada están\n"
	.string "las llamadas CAMPANAS OLEAJE.\p"
	.string "No suenan ni con el embate\n"
	.string "de las olas.\p"
	.string "Solo hay una forma de hacerlas\n"
	.string "sonar:\p"
	.string "conseguir otra CAMPANA OLEAJE\n"
	.string "como las que hay en la poza\l"
	.string "de la cascada.\p"
	.string "La busqué cuando era joven,\n"
	.string "pero nunca conseguí una…$"

CianwoodCity_Text_ClearBellReaction:
	.string "¡Oh! ¿Has conseguido una\n"
	.string "CAMPANA CLARA?\p"
	.string "Aquel viejo sueño de juventud…\n"
	.string "Ya veo…\p"
	.string "Lo has logrado…\n"
	.string "…\l"
	.string "¡Puedo oírlo!\p"
	.string "El tañido de las campanas llega\n"
	.string "con el viento desde la\l"
	.string "TORRE HOJALATA…$"

CianwoodCity_Text_TidalBellReaction:
	.string "¡Oh! ¿Has conseguido una\n"
	.string "CAMPANA OLEAJE?\p"
	.string "Aquel viejo sueño de juventud…\n"
	.string "Ya veo…\p"
	.string "Lo has logrado…\n"
	.string "…\l"
	.string "¡Puedo oírlo!\p"
	.string "El tañido de las campanas llega\n"
	.string "con la brisa marina desde las\l"
	.string "ISLAS REMOLINO…$"
