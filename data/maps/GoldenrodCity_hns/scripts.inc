GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "¡Este es el GIMNASIO de TRIGAL!\p"
	.string "BLANCA no está ahora mismo.\n"
	.string "Quizá esté en la TORRE RADIO.$"

GoldenrodCity_Text_Woman:
	.string "Antes entrenaba en el GIMNASIO\n"
	.string "de BLANCA, pero tanto llanto me\l"
	.string "daba dolor de cabeza.$"

GoldenrodCity_Text_HikerDay:
	.string "¡Cuando entré al CASINO era de\n"
	.string "noche…! ¡¿Cuánto tiempo me he\l"
	.string "pasado ahí metido?!$"

GoldenrodCity_Text_HikerNight:
	.string "¡Cuando entré al CASINO era de\n"
	.string "día…! ¡¿Cuánto tiempo me he pasado\l"
	.string "ahí metido?!$"

GoldenrodCity_Text_Snubbull:
	.string "SNUBBULL: ¡Snuuubuuurrr!$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmName:
	.string "PROF. ELM$"

GoldenrodCity_Text_ElmCall:
	.string "PROF. ELM: ¿Diga, {PLAYER}?\n"
	.string "¿Ha eclosionado ya el HUEVO?\p"
	.string "¡En cuanto nazca el POKéMON, ven\n"
	.string "pitando al laboratorio! ¡Tengo que\l"
	.string "verlo con mis propios ojos!$"

GoldenrodCity_Text_PokefanM:
	.string "Construyeron la nueva TORRE RADIO\n"
	.string "para sustituir la vieja torre de\l"
	.string "madera carcomida.$"

GoldenrodCity_Text_Youngster1:
	.string "Sé que han abierto una TIENDA DE\n"
	.string "BICIS, pero no la encuentro por\l"
	.string "ninguna parte.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "¿Ese tipo de negro va disfrazado\n"
	.string "del TEAM ROCKET?\p"
	.string "¡Qué payasada!$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "¿De verdad ese tipo de negro era\n"
	.string "del TEAM ROCKET? ¡No me lo creo!$"

GoldenrodCity_Text_CooltrainerF2:
	.string "La TORRE RADIO de CIUDAD TRIGAL es\n"
	.string "el gran símbolo de la ciudad.\p"
	.string "Ahora mismo tienen una promoción:\n"
	.string "si aciertas las preguntas de su\l"
	.string "concurso, te regalan una TARJETA\l"
	.string "RADIO para el POKéGEAR.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "¡Hala, si tu POKéGEAR ya sintoniza\n"
	.string "la radio!$"

GoldenrodCity_Text_Youngster2:
	.string "Je, je, je…\p"
	.string "Me cayó una bronca enorme por jugar\n"
	.string "en el sótano del CENTRO COMERCIAL.$"

GoldenrodCity_Text_Lass:
	.string "El señor de esa casa evalúa los\n"
	.string "motes de tus POKéMON.\p"
	.string "¡Incluso puede cambiárselos!$"

GoldenrodCity_Text_Gramps:
	.string "¡Buf! Esta ciudad es tan descomunal\n"
	.string "que me pierdo en cada esquina.$"

GoldenrodCity_Text_RocketScout1:
	.string "Conque esta es la TORRE RADIO…$"

GoldenrodCity_Text_RocketScout2:
	.string "¿Qué miras, renacuajo?\n"
	.string "¡Lárgate de aquí!$"

GoldenrodCity_Text_Rocket1:
	.string "¡No estorbes!\n"
	.string "¡Ahueca el ala, peque!$"

GoldenrodCity_Text_Rocket2:
	.string "Tomar el control de la TORRE…\p"
	.string "¿Qué? ¡A ti qué te importa!$"

GoldenrodCity_Text_Rocket3:
	.string "¿Los POKéMON? ¡No son más que meras\n"
	.string "herramientas para ganar pasta!$"

GoldenrodCity_Text_Rocket4:
	.string "Muy pronto se cumplirá nuestro\nsueño…\p"
	.string "Ha sido una lucha larga y dura…$"

GoldenrodCity_Text_Rocket5:
	.string "¡Eh, niñato! ¡No pintas nada\n"
	.string "aquí! ¡Piérdete de una vez!$"

GoldenrodCity_Text_Rocket6:
	.string "¡Ven y prueba el auténtico terror\n"
	.string "del TEAM ROCKET!$"

GoldenrodCity_Text_StationSign:
	.string "ESTACIÓN DE CIUDAD TRIGAL$"

GoldenrodCity_Text_RadioTowerSign:
	.string "TORRE RADIO DE CIUDAD TRIGAL$"

GoldenrodCity_Text_DeptStoreSign:
	.string "¡El mayor surtido de artículos\nPOKéMON!\p"
	.string "CENTRO COMERCIAL DE CIUDAD TRIGAL$"

GoldenrodCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD TRIGAL\n"
	.string "LÍDER: BLANCA\p"
	.string "¡La chica increíblemente adorable!$"

GoldenrodCity_Text_CitySign:
	.string "CIUDAD TRIGAL\p"
	.string "La alegre metrópoli del encanto y\n"
	.string "la opulencia$"

GoldenrodCity_Text_BikeShopSign:
	.string "¡El mundo es tu carril bici!\n"
	.string "TIENDA DE BICICLETAS$"

GoldenrodCity_Text_GameCornerSign:
	.string "¡Tu rincón de diversión!\p"
	.string "CASINO DE CIUDAD TRIGAL$"

GoldenrodCity_Text_NameRaterSign:
	.string "INSPECTOR DE MOTES\p"
	.string "Evalúa y renueva los nombres de tus\n"
	.string "POKéMON$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ENTRADA AL SUBTERRÁNEO$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ENTRADA AL SUBTERRÁNEO$"


GoldenrodCity_Text_FlowerShopSign:
	.string "FLORISTERÍA HERMOSA PRIMAVERA$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "¡Puedo enseñar a tus POKéMON unos\n"
	.string "movimientos descomunales!\p"
	.string "¿Te enseño alguno?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "Te costará 1000 fichas del Casino.\n"
	.string "¿Hace el trato?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Vaya… ¡Pero son ataques geniales!$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "¡Jajaja! ¡No te vas a arrepentir!\p"
	.string "¿Qué ataque enseño?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Qué lástima. Tendré que pedir algo\n"
	.string "de dinero en casa…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "Quien domina este movimiento,\n"
	.string "domina el arte de combatir.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "¡Jajaja! ¡Hasta la vista, peque!$"

GoldenrodCity_Text_MoveTutorBut:
	.string "P-pero…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "…No tienes suficientes fichas…$"
