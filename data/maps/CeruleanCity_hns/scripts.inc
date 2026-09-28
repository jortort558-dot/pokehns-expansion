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
	.string "¿La CENTRAL\n"
	.string "ENERGÍA de KANTO?\p"
	.string "Está al final de\n"
	.string "la RUTA 9, el\p"
	.string "camino que hay\n"
	.string "al este de aquí.\p"
	.string "Creo que hubo\n"
	.string "algún tipo de\l"
	.string "accidente allí.$"
CeruleanCity_Text_CooltrainerM2:
	.string "¿Vas a atrapar\n"
	.string "todos los tipos de\l"
	.string "POKéMON?\p"
	.string "Parece un gran\n"
	.string "desafío, pero será\l"
	.string "divertido.$"
CeruleanCity_Text_SuperNerd:
	.string "El CABO que está\n"
	.string "al norte es ideal\p"
	.string "para una cita a\n"
	.string "ciegas.\l"
	.string "¡Es tan romántico!$"
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
	.string "¡Mi SLOWBRO y yo\n"
	.string "formamos un equipo\l"
	.string "impresionante!$"
CeruleanCity_Text_CooltrainerF2:
	.string "¡SLOWBRO, enséñame\n"
	.string "tu CONFUSIÓN!$"
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
	.string "Soy un gran segui-\n"
	.string "dor de MISTY, la\p"
	.string "LÍDER de GIMNASIO\n"
	.string "de CIUDAD CELESTE.$"
CeruleanCity_Text_Fisher_RocketTip:
	.string "Vi a ese tipo\n"
	.string "sospechoso de\p"
	.string "camino al CABO de\n"
	.string "CIUDAD CELESTE.$"
CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La cueva al norte del pueblo\n"
	.string "está llena de POKéMON muy fuertes.$"

CeruleanCity_Text_Youngster2:
	.string "¡Caray!\p"
	.string "Mi BUSCAOBJETOS\n"
	.string "responde…$"
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
	.string "Una misteriosa\n"
	.string "aura azulada la\l"
	.string "rodea$"
CeruleanCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO\n"
	.string "POKéMON DE CIUDAD\l"
	.string "CELESTE: MISTY\p"
	.string "La sirena poco\n"
	.string "femenina$"
CeruleanCity_Text_BikeShopSign:
	.string "Aquí hay una nota…\p"
	.string "La TIENDA DE BICIS\n"
	.string "se ha trasladado a\p"
	.string "CIUDAD TRIGAL, en\n"
	.string "JOHTO…$"
CeruleanCity_Text_PoliceSign:
	.string "Aquí hay una nota…\p"
	.string "¡Acaba con los\n"
	.string "ladrones y haz que\p"
	.string "la ciudad sea más\n"
	.string "grata y alegre!\p"
	.string "POLICÍA C. CELESTE$"
CeruleanCity_Text_CapeSign:
	.string "Hacia el\n"
	.string "CABO CELESTE$"
CeruleanCity_Text_LockedDoor:
	.string "Está cerrado…$"
