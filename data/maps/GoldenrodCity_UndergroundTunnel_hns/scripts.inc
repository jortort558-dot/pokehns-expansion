GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
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
	.string "Miembros del TEAM ROCKET de negro\nhan\l"
	.string "estado corriendo por aquí…\p"
	.string "Me preguntaba qué estaba\nocurriendo.\l"
	.string "¿Te has enfrentado tú al TEAM\lROCKET?\l"
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
	.string "¡Bienvenido a la PELUQUERÍA\nPOKéMON!\lSoy el menor y el más barato de los\ldos\lHERMANOS PELUQUEROS.\lDejaré niquelado a tu POKéMON por\lsolo 300¥.\l¿Qué te parece? ¿Te hace?$"
GoldenrodUnderground_Text_YoungerBrotherAskWhich:
	.string "¡De acuerdo! ¿Con qué POKéMON me\npongo manos\la la obra?$"
GoldenrodUnderground_Text_YoungerBrotherLookCool:
	.string "¡Genial! ¡Lo dejaré hecho un\npincel!$"
GoldenrodUnderground_Text_YoungerBrotherAllDone:
	.string "¡Ya está! ¡Listo de papeles!$"
GoldenrodUnderground_Text_YoungerBrotherDisappointed:
	.string "¿Que no? ¡Vaya chasco!$"
GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
	.string "Andas un poco corto de fondos.$"
GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
	.string "Solo hago un corte de pelo al día.\nLo siento, pero he terminado por\lhoy.$"
GoldenrodUnderground_Text_OlderBrotherOffer:
	.string "¡Te damos la bienvenida!\n¡Llevo la PELUQUERÍA POKéMON!\lSoy el mayor y con mejores manos de\llos dos\lHERMANOS PELUQUEROS.\lDejaré precioso a tu POKéMON por\l500¥.\l¿Te gustaría probar?$"
GoldenrodUnderground_Text_OlderBrotherAskWhich:
	.string "¿A qué POKéMON le doy el toque de\ngracia?$"
GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
	.string "¡Muy bien! ¡Vas a ver qué\nhermosura!$"
GoldenrodUnderground_Text_OlderBrotherAllDone:
	.string "¡Tachán! ¡Trabajo impecable!$"
GoldenrodUnderground_Text_OlderBrotherThatsAShame:
	.string "¿Eso piensas? ¡Qué lástima!$"
GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
	.string "Necesitarás algo más de dinero que\neso.$"
GoldenrodUnderground_Text_OlderBrotherOnePerDay:
	.string "Solo realizo un peinado al día.\nPor hoy he cerrado el chiringuito.$"
GoldenrodUnderground_Text_SupernerdEricSeen:
	.string "Me pusieron de patitas en la calle\nen el\lRINCÓN DEL JUEGO.\lIntenté hacer trampas con mis\lPOKéMON…$"
GoldenrodUnderground_Text_SupernerdEricBeaten:
	.string "…Maldición…$"
GoldenrodUnderground_Text_SupernerdEricAfterBattle:
	.string "Supongo que tendré que ganarme las\ncosas\lpor las buenas…$"
GoldenrodUnderground_Text_SupernerdTeruSeen:
	.string "¿Tienes en cuenta la tabla de tipos\nen\lcombate?\lSi conoces las ventajas\lelementales, te irá\lmucho mejor.$"
GoldenrodUnderground_Text_SupernerdTeruBeaten:
	.string "¡Ay, ay, ay!$"
GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
	.string "Me sé al dedillo las\ncompatibilidades de tipos.\lPero solo uso POKéMON de un único\ltipo.$"
GoldenrodUnderground_Text_PokemaniacIssacSeen:
	.string "¡Mi POKéMON acaba de salir de la\npeluquería!\l¡Te enseñaré lo fuerte que está!$"
GoldenrodUnderground_Text_PokemaniacIssacBeaten:
	.string "¡Aiiiieee!$"
GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
	.string "Tus POKéMON te cogerán mucho más\ncariño si\llos llevas a cortar el pelo.$"
GoldenrodUnderground_Text_PokemaniacDonaldSeen:
	.string "Me da la nariz de que llevas\nPOKéMON muy\lraros contigo.\l¡Déjame verlos!$"
GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
	.string "¡Aaargh! ¡He perdido! ¡Qué coraje\nme da!$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "Anoche, paseando cerca de la TIENDA\nDE\lBICIS, sentí como si me espiaran\ldesde los\ltejados...$"
GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
	.string "¿Estás completando la POKéDEX?\nEscucha este buen soplo:\lEl MONTAÑERO de la RUTA 33,\lANTHONY, es un\ltrozo de pan.\lTe llamará si avista algún POKéMON\lraro.$"
GoldenrodUnderground_Text_DoorsLocked:
	.string "La puerta está cerrada con llave…$"
GoldenrodUnderground_Text_DoorIsOpen:
	.string "La puerta está abierta.$"
GoldenrodUnderground_Text_KeyOpenedDoor:
	.string "La LLAVE DEL SÓTANO abrió la\npuerta.$"
GoldenrodUnderground_Text_NoEntry:
	.string "PROHIBIDO EL PASO A PARTIR DE ESTE\nPUNTO$"
