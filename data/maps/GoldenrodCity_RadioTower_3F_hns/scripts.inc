GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "Es la ranura para la LLAVE\nMAGNÉTICA.$"
GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "¡{PLAYER} introdujo la\n"
	.string "LLAVE MAGNÉTICA!$"
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "La verja se ha abierto.$"
GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3P PERSONAL$"
GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MÚSICA POKéMON con el DJ BEN$"
GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Tenemos grabaciones de los gritos\nde todos los POKéMON descubiertos.\pDebe de haber unas 400 especies.$"
GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Para los Entrenadores, los POKéMON\nson compañeros muy queridos.\pEs terrible que el TEAM ROCKET\nintente controlarlos.$"
GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "Emitimos las 24 horas para ofrecer\nprogramas entretenidos.\p¡Yo también trabajaré sin parar!$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "El jefe del TEAM ROCKET se ha\nencerrado dentro.\pEl DIRECTOR puede abrir la puerta.\pEstá en la quinta planta.\p¡Sálvalo, por favor!$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "¿El DIRECTOR se encuentra a salvo?$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "¡Gracias! ¡Eres mi héroe!\pAcepta esto en señal de gratitud.$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "Es INTERCAMBIO. Cambia la habilidad\nde un POKéMON por la de otro.$"
GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "¡Has estado sencillamente genial!$"
GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "Tengo órdenes estrictas.\p¡Debo aplastar a cualquiera que\ndesafíe al TEAM ROCKET!$"
GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "¡¿Quéee?!$"
GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "He fracasado en mi misión…\pATLAS se enfadará muchísimo…$"
GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "¡Me encanta ordenar a los POKéMON\nque cometan delitos!$"
GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "¡No me fastidies!$"
GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "¡Me siento fatal por perder!\p¡Maldita sea! ¡Odio a los inútiles!$"
GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "¿Por qué se abrió la verja?\n¿Has tenido algo que ver con esto?$"
GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "¡Estoy acabado!$"
GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "¡¿Qué?! ¿Has superado a nuestros\nhombres del SUBTERRÁNEO?\p¿Cómo has podido?$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "¿Un crío desconocido por aquí?\p¿Quién eres?$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "¡Tsk! ¡Te subestimé demasiado!$"
GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "¡Bua, ja, ja…!\pDesde aquí puedo emitir una señal\ntan potente como necesite.$"
