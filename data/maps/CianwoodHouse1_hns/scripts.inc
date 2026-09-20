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
	.string "Ya ni me acuerdo de la última vez\nque\lalguien vino a hacerme una visita.\pEn mi juventud yo también fui\nEntrenador\lPOKéMON.\pTraté de llegar a la cumbre de la\ntorre\ly de bucear en las profundidades\lmarinas.\pPuse empeño y corazón en muchas\ncosas.\pAhora me tomo la vida con calma,\nescuchando las olas y el viento en\lesta\lplaya.$"
CianwoodCity_Text_BellTowerStory:
	.string "¿Has oído hablar de la TORRE\nHOJALATA\len CIUDAD IRIS?\pDicen que arriba del todo descansan\nlas\lCampanas Claras.\pNo emiten ni un solo tintineo ni\nante los\lvientos más violentos.\pSolo hay una forma de hacerlas\ntañer:\lobtener otra CAMPANA CLARA idéntica\la las\lde la torre.\pYo la busqué sin descanso de joven.\nPero nunca logré dar con una...$"
CianwoodCity_Text_WhirlIslandsStory:
	.string "¿Has oído hablar de las ISLAS\nREMOLINO?\pDicen que en la poza de su cascada\nestán\llas Campanas Oleaje.\lNo emiten ni un sonido con el\lchocar de\llas olas.\pSolo hay una forma de hacerlas\ntañer:\lobtener otra Campana Oleaje\lidéntica a las\lde la cascada.\pYo la busqué con pasión de joven.\nPero jamás encontré una...$"
CianwoodCity_Text_ClearBellReaction:
	.string "¡Oh! ¿Has conseguido una CAMPANA\nCLARA?\pAquel viejo sueño de mi juventud...\nYa veo... Lo has logrado...\l...\l...¡Puedo oírlo!\p¡El tañido de las campanas en el\nviento\lllegando desde la dirección de la\lTORRE HOJALATA...$"
CianwoodCity_Text_TidalBellReaction:
	.string "¡Oh! ¿Has conseguido una Campana\nOleaje?\pAquel viejo sueño de mi juventud...\nYa veo... Lo has logrado...\l...\l...¡Puedo oírlo!\p¡El tañido de las campanas en la\nbrisa\lmarina llegando desde la dirección\lde\llas ISLAS REMOLINO...$"
