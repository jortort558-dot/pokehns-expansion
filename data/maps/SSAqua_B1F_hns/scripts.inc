SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "¡Puaj!\n"
    .string "¡No debería haber mirado!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Oye, chico. ¿Puedes buscar a\n"
	.string "mi compañero?\p"
	.string "Está vagueando por algún sitio.\n"
	.string "¡Será holgazán!\p"
	.string "Iría yo, pero ahora mismo estoy\n"
	.string "de servicio.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Vaya…\p"
	.string "El CAPITÁN se pondrá furioso…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "¡Gracias, chico! Le he echado\n"
	.string "una buena bronca por vaguear.$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "¿Una niña pequeña?\p"
	.string "Creo que la he visto pasar.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "El comedor está más adelante.\p"
	.string "Las escaleras del fondo llevan\n"
	.string "al camarote del CAPITÁN.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "¡Nada como combatir durante\n"
	.string "mi descanso!$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "¡Gane o pierda, se acabó\n"
	.string "mi descanso!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Supongo que no ganaré si no me\n"
	.string "lo tomo en serio.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Me aburro mucho. ¿Combatimos?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "¡Vaya! ¡Eres demasiado fuerte!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "AZAFRÁN, AZULONA… Dicen que en\n"
	.string "KANTO hay muchas ciudades grandes.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Uf… ¡Estoy mareado!$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "Ya no puedo moverme…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "No pienso volver a viajar\n"
	.string "en barco.\p"
	.string "La próxima vez iré en\n"
	.string "MAGNETOTRÉN.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "¡Aquí trabajamos los marineros!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "He perdido en mi propio terreno…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Llevamos toda clase de pasajeros\n"
	.string "entre CIUDAD CARMÍN y\l"
	.string "CIUDAD OLIVO.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "¡Estamos en alta mar y no puedo\n"
	.string "pescar!\p"
	.string "¡Qué aburrido! ¡Combatamos!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Ya… Ya no estoy aburrido…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Pienso pescar desde el muelle\n"
	.string "de CIUDAD CARMÍN.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "¡Fortalezco las piernas\n"
	.string "aguantando el balanceo del barco!$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "¡Me has hecho perder el equilibrio!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "No encontré al MAESTRO KARATE\n"
	.string "en JOHTO.\p"
	.string "Dicen que entrena en una cueva\n"
	.string "en algún lugar.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "¡Soy todo un marinero!\p"
	.string "¡Pero entreno a mis POKéMON para\n"
	.string "convertirme en CAMPEÓN!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Se nota que me falta entrenar…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "¡Ocho MEDALLAS! Demuestran que\n"
	.string "has vencido a los LÍDERES\l"
	.string "de GIMNASIO.\p"
	.string "¡Con razón eres tan bueno!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "¡No les pongas un dedo encima\n"
	.string "a mis alumnos!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "¡Aaah!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "Estamos de excursión en las RUINAS\n"
	.string "que hay a las afueras de MALVA.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "¿Conoces las RUINAS ALFA?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "¡Aaah!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Las radios captan señales extrañas\n"
	.string "dentro de las RUINAS.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "En las RUINAS ALFA hay unos\n"
	.string "extraños paneles de piedra.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "¡Me has derrotado!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "He leído que hay cuatro paneles\n"
	.string "de piedra.$"
