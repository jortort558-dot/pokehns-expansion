CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "Esta es la CUEVA CELESTE.\p"
	.string "Dentro viven POKéMON muy fuertes.\p"
	.string "Solo dejan entrar a entrenadores\n"
	.string "realmente excepcionales.\p"
	.string "Para empezar, debes ser CAMPEÓN\n"
	.string "de la LIGA POKéMON de KANTO.\p"
	.string "Y también haber logrado una\n"
	.string "gran hazaña.$"

CeruleanCity_Text_CooltrainerM1:
	.string "¿La CENTRAL DE ENERGÍA de KANTO?\p"
	.string "Está cerca del final de la RUTA 9,\n"
	.string "la que sale hacia el este.\p"
	.string "Creo que allí hubo algún tipo\n"
	.string "de accidente.$"
CeruleanCity_Text_CooltrainerM2:
	.string "¿Intentas capturar todas las\n"
	.string "especies de POKéMON?\p"
	.string "Parece todo un reto, pero también\n"
	.string "suena divertido.$"
CeruleanCity_Text_SuperNerd:
	.string "El CABO del norte es un lugar\n"
	.string "ideal para tener una cita.\p"
	.string "¡A las chicas les encanta!$"
CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "SLOWBRO: ¿Slow?$"
CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "¡Mi SLOWBRO y yo formamos un\n"
	.string "equipo impresionante!$"
CeruleanCity_Text_CooltrainerF2:
	.string "¡SLOWBRO, enséñame tu CONFUSIÓN!$"
CeruleanCity_Text_CooltrainerF3:
	.string "<……>$"
CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "Soy un gran admirador de MISTY,\n"
	.string "la LÍDER del GIMNASIO de CELESTE.$"
CeruleanCity_Text_Fisher_RocketTip:
	.string "Vi a ese tipo sospechoso ir\n"
	.string "hacia el CABO CELESTE.$"
CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La cueva al norte del pueblo\n"
	.string "está llena de POKéMON muy fuertes.$"

CeruleanCity_Text_Youngster2:
	.string "¡Caray!\p"
	.string "Mi BUSCAOBJETOS está reaccionando…$"
CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "CIUDAD CELESTE\p"
	.string "Una misteriosa aura azul\n"
	.string "la envuelve.$"
CeruleanCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CELESTE\n"
	.string "LÍDER: MISTY\p"
	.string "¡La sirena indómita!$"
CeruleanCity_Text_BikeShopSign:
	.string "Aquí hay una nota…\p"
	.string "La TIENDA DE BICIS se ha mudado\n"
	.string "a CIUDAD TRIGAL, en JOHTO…$"
CeruleanCity_Text_PoliceSign:
	.string "Aquí hay una nota…\p"
	.string "¡Acabemos con los robos y hagamos\n"
	.string "de la ciudad un lugar más alegre!\p"
	.string "POLICÍA DE CIUDAD CELESTE$"
CeruleanCity_Text_CapeSign:
	.string "CABO CELESTE\n"
	.string "TODO RECTO$"
CeruleanCity_Text_LockedDoor:
	.string "Está cerrado…$"
