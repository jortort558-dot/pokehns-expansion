GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end

GoldenrodUnderground_EventScript_HerbClerk::
	lock
	faceplayer
	message GoldenrodUnderground_Text_HerbShopWelcome
	waitmessage
	pokemart GoldenrodUnderground_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodUnderground_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_MIRROR_HERB
	pokemartlistend
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "Miembros del TEAM ROCKET de negro\n"
	.string "estado corriendo por aquí…\p"
	.string "Me preguntaba qué estaba pasando.\n"
	.string "¿Te enfrentaste al TEAM ROCKET?\l"
	.string "¡Qué valor tan admirable!\p"
	.string "Puede que seas capaz de encarar al\n"
	.string "legendario POKé…$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "¡Jajaja! Olvídalo.\nDebo marcharme ya.$"
GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC_HNS, GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU_HNS, GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC_HNS, GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD_HNS, GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother2
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
	.string "¡Bienvenido a PELUQUERÍA POKéMON!\pSoy el menor y más barato de los\ndos HERMANOS PELUQUEROS.\pArreglaré a tu POKéMON por solo\n300¥.\p¿Qué te parece?$"
GoldenrodUnderground_Text_HerbShopWelcome:
	.string "¡Bienvenido a la HERBORISTERÍA!\p"
	.string "¡Remedios eficaces y económicos!$"
GoldenrodUnderground_Text_YoungerBrotherAskWhich:
	.string "¡De acuerdo! ¿Qué POKéMON elijo?$"
GoldenrodUnderground_Text_YoungerBrotherLookCool:
	.string "¡Bien! ¡Haré que quede genial!$"
GoldenrodUnderground_Text_YoungerBrotherAllDone:
	.string "¡Ya está! ¡He terminado!$"
GoldenrodUnderground_Text_YoungerBrotherDisappointed:
	.string "¿Que no? ¡Vaya chasco!$"
GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
	.string "Andas un poco corto de fondos.$"
GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
	.string "Solo hago un corte de pelo al día.\pLo siento, he terminado por hoy.$"
GoldenrodUnderground_Text_OlderBrotherOffer:
	.string "¡Te doy la bienvenida!\p¡Dirijo la PELUQUERÍA POKéMON!\pSoy el mayor y mejor de los dos\nHERMANOS PELUQUEROS.\pDejaré precioso a tu POKéMON por\n500¥.\p¿Quieres que lo haga?$"
GoldenrodUnderground_Text_OlderBrotherAskWhich:
	.string "¿Con qué POKéMON debo trabajar?$"
GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
	.string "¡Bien! ¡Verás qué hermoso queda!$"
GoldenrodUnderground_Text_OlderBrotherAllDone:
	.string "¡Tachán! ¡Trabajo impecable!$"
GoldenrodUnderground_Text_OlderBrotherThatsAShame:
	.string "¿Eso piensas? ¡Qué lástima!$"
GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
	.string "Necesitarás algo más de dinero que\neso.$"
GoldenrodUnderground_Text_OlderBrotherOnePerDay:
	.string "Solo hago un corte de pelo al día.\nHe terminado por hoy.$"
GoldenrodUnderground_Text_SupernerdEricSeen:
	.string "Me echaron del RINCÓN DEL JUEGO.\pIntenté hacer trampas con mis\nPOKéMON…$"
GoldenrodUnderground_Text_SupernerdEricBeaten:
	.string "…Maldición…$"
GoldenrodUnderground_Text_SupernerdEricAfterBattle:
	.string "Supongo que tendré que hacer las\ncosas de forma justa…$"
GoldenrodUnderground_Text_SupernerdTeruSeen:
	.string "¿Tienes en cuenta los tipos en\ncombate?\pSi conoces sus ventajas, te irá\nmucho mejor.$"
GoldenrodUnderground_Text_SupernerdTeruBeaten:
	.string "¡Ay, ay, ay!$"
GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
	.string "Conozco bien las relaciones\nentre tipos.\pPero solo uso un tipo de POKéMON.$"
GoldenrodUnderground_Text_PokemaniacIssacSeen:
	.string "¡Mi POKéMON acaba de ir a la pelu!\p¡Te mostraré lo fuerte que es!$"
GoldenrodUnderground_Text_PokemaniacIssacBeaten:
	.string "¡Aiiiieee!$"
GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
	.string "Tus POKéMON te querrán más si\nles cortas el pelo.$"
GoldenrodUnderground_Text_PokemaniacDonaldSeen:
	.string "Creo que llevas algún POKéMON raro\ncontigo.\p¡Déjame verlo!$"
GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
	.string "¡Aaargh! ¡He perdido! ¡Qué coraje\nme da!$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "Anoche, cerca de la TIENDA DE\nBICIS, sentí que me observaban\ldesde los tejados…$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
	.string "¿Estás completando la POKéDEX?\nTe daré un buen consejo.\pEl MONTAÑERO ANTHONY, de la\nRUTA 33, es buena persona.\pTe llamará si ve un POKéMON raro.$"
GoldenrodUnderground_Text_DoorsLocked:
	.string "La puerta está cerrada con llave…$"
GoldenrodUnderground_Text_DoorIsOpen:
	.string "La puerta está abierta.$"
GoldenrodUnderground_Text_KeyOpenedDoor:
	.string "La LLAVE DEL SÓTANO abrió la\npuerta.$"
GoldenrodUnderground_Text_NoEntry:
	.string "PROHIBIDO EL PASO A PARTIR DE ESTE\nPUNTO$"

@ --- BAR SUBTERRÁNEO DE TRIGAL ---

GoldenrodCity_UndergroundTunnel_EventScript_Item_BarBall::
	finditem ITEM_NUGGET
	end

GoldenrodUnderground_EventScript_BarGuard1::
	trainerbattle_single TRAINER_BAR_GUARD1_HNS, GoldenrodUnderground_Text_BarGuard1Seen, GoldenrodUnderground_Text_BarGuard1Beaten
	msgbox GoldenrodUnderground_Text_BarGuard1AfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_BarGuard2::
	trainerbattle_single TRAINER_BAR_GUARD2_HNS, GoldenrodUnderground_Text_BarGuard2Seen, GoldenrodUnderground_Text_BarGuard2Beaten
	msgbox GoldenrodUnderground_Text_BarGuard2AfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Igor::
	lock
	faceplayer
	msgbox GoldenrodUnderground_Text_IgorWelcome, MSGBOX_DEFAULT
GoldenrodCity_UndergroundTunnel_EventScript_Igor_Menu::
	message GoldenrodUnderground_Text_IgorOffer
	waitmessage
	multichoice 0, 0, MULTI_IGOR_BAR, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoPS
	case 1, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoAtk
	case 2, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoDef
	case 3, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpAtk
	case 4, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpDef
	case 5, GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpeed
	case 6, GoldenrodCity_UndergroundTunnel_EventScript_BuyCubata
	goto GoldenrodCity_UndergroundTunnel_EventScript_Igor_Exit
	end

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoPS::
	setvar VAR_0x8008, ITEM_CHUPITO_PS
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoAtk::
	setvar VAR_0x8008, ITEM_CHUPITO_ATK
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoDef::
	setvar VAR_0x8008, ITEM_CHUPITO_DEF
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpAtk::
	setvar VAR_0x8008, ITEM_CHUPITO_SPATK
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpDef::
	setvar VAR_0x8008, ITEM_CHUPITO_SPDEF
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_BuyChupitoSpeed::
	setvar VAR_0x8008, ITEM_CHUPITO_SPEED
	goto GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito

GoldenrodCity_UndergroundTunnel_EventScript_ProcessSingleChupito::
	checkitem ITEM_FESTIVAL_TICKET, 1
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoTickets
	checkitemspace VAR_0x8008, 1
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoRoom
	removeitem ITEM_FESTIVAL_TICKET, 1
	giveitem VAR_0x8008, 1
	msgbox GoldenrodUnderground_Text_IgorDelivered, MSGBOX_DEFAULT
	goto GoldenrodCity_UndergroundTunnel_EventScript_Igor_Menu
	end

GoldenrodCity_UndergroundTunnel_EventScript_BuyCubata::
	checkitem ITEM_FESTIVAL_TICKET, 6
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoTicketsCubata
	checkitemspace ITEM_CUBATA, 1
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoRoom
	removeitem ITEM_FESTIVAL_TICKET, 6
	giveitem ITEM_CUBATA, 1
	msgbox GoldenrodUnderground_Text_IgorDeliveredCubata, MSGBOX_DEFAULT
	goto GoldenrodCity_UndergroundTunnel_EventScript_Igor_Menu
	end

GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoTickets::
	msgbox GoldenrodUnderground_Text_IgorNoTickets, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoTicketsCubata::
	msgbox GoldenrodUnderground_Text_IgorNoTicketsCubata, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_Igor_NoRoom::
	msgbox GoldenrodUnderground_Text_IgorNoRoom, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_Igor_Exit::
	msgbox GoldenrodUnderground_Text_IgorGoodbye, MSGBOX_DEFAULT
	release
	end

GoldenrodUnderground_Text_BarGuard1Seen:
	.string "¡Eh, tú! ¿Qué pintas por aquí?\n"
	.string "Nadie pasa al garito sin mi\l"
	.string "visto bueno.$"

GoldenrodUnderground_Text_BarGuard1Beaten:
	.string "¡Vaya paliza me has dado!\n"
	.string "Tira pa' dentro, fiera.$"

GoldenrodUnderground_Text_BarGuard1AfterBattle:
	.string "El bar de Igor no es para todo el\n"
	.string "mundo. Pero tú pareces tener\l"
	.string "buenas tablas.$"

GoldenrodUnderground_Text_BarGuard2Seen:
	.string "¡Alto ahí! Para entrar a la barra\n"
	.string "hay que demostrar que se aguanta\l"
	.string "el ritmo.$"

GoldenrodUnderground_Text_BarGuard2Beaten:
	.string "¡Madre mía!\n"
	.string "Aguantas más de lo que creía.$"

GoldenrodUnderground_Text_BarGuard2AfterBattle:
	.string "Si traes Vales de Fiesta, habla\n"
	.string "con el jefe Igor. Sirve unas copas\l"
	.string "que te pondrán al máximo.$"

GoldenrodUnderground_Text_IgorWelcome:
	.string "Bienvenido a mi modesto rincón\n"
	.string "entre las sombras…\p"
	.string "Me llamo Igor. Este refugio existe\n"
	.string "para despertar el auténtico\l"
	.string "potencial de tus acompañantes.$"

GoldenrodUnderground_Text_IgorOffer:
	.string "Trae tus Vales de Fiesta y te\n"
	.string "serviré brebajes legendarios.\p"
	.string "Un Chupito (1 vale) maximiza un\n"
	.string "atributo (31 IVs).\p"
	.string "El Cubata (6 vales) alcanzará la\n"
	.string "perfección absoluta en todos.$"

GoldenrodUnderground_Text_IgorDelivered:
	.string "Una elección exquisita.\n"
	.string "Dáselo a un POKéMON y verás cómo\l"
	.string "su potencial florece.$"

GoldenrodUnderground_Text_IgorDeliveredCubata:
	.string "¡Ah, la gran obra maestra!\n"
	.string "Este trago despertará la fuerza\l"
	.string "completa de quien lo tome.$"

GoldenrodUnderground_Text_IgorNoTickets:
	.string "Je, je, je… Me temo que no portas\n"
	.string "suficientes Vales de Fiesta.\p"
	.string "Vuelve cuando consigas alguno.$"

GoldenrodUnderground_Text_IgorNoTicketsCubata:
	.string "Para este manjar supremo requiero\n"
	.string "al menos 6 Vales de Fiesta.\p"
	.string "Aún te faltan unos cuantos, je, je.$"

GoldenrodUnderground_Text_IgorNoRoom:
	.string "Tu MOCHILA está a rebosar.\n"
	.string "Haz hueco antes de brindar.$"

GoldenrodUnderground_Text_IgorGoodbye:
	.string "Hasta la próxima visita…\n"
	.string "El destino siempre nos reúne aquí.$"

