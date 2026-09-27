ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "OAK$"

ViridianCity_Text_OakCall:
	.string "OAK: ¡Ah, {PLAYER}!\p"
	.string "Ven a verme a mi LABORATORIO\n"
	.string "de PUEBLO PALETA cuando puedas.$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "¡Eh, joven! ¡Me he tomado un café\n"
	.string "doble y estoy como una moto!\p"
	.string "Necesito hablar con alguien,\n"
	.string "¡así que tú servirás!\p"
	.string "Ahora no lo parece, pero era un\n"
	.string "experto capturando POKéMON.\p"
	.string "¿Me crees?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Bien, bien. Sí, era alguien fuera\n"
	.string "de lo común, ¡te lo aseguro!$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "¿Qué? ¡Mocoso!\p"
	.string "Si fuera algo más joven, te\n"
	.string "enseñaría un par de cosas. ¡Hum!$"

ViridianCity_Text_GrampsNearGym:
	.string "Este GIMNASIO no tenía LÍDER\n"
	.string "hasta hace poco.\p"
	.string "Un joven de PALETA se hizo LÍDER,\n"
	.string "pero suele estar fuera.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "¿Vas a luchar contra el LÍDER?\p"
	.string "Buena suerte. La necesitarás.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "…Zzzzz…\p" 
	.string "¡Buaaa!\p"
	.string "Debí quedarme dormido al sol.\p"
	.string "¿Qué? ¿Te recuerdo a alguien?\p"
	.string "No sé… Toma esto.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "¡Buaaa!\p"
	.string "Debí quedarme dormido al sol.\p"
	.string "Soñé que un DROWZEE se comía\n"
	.string "mi sueño. Qué raro, ¿no?\p"
	.string "¿Eh? ¿Qué es esto?\p"
	.string "¿De dónde salió esta MT?\p"
	.string "¡Qué miedo! Toma, quédatela.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "La MT42 contiene COME SUEÑOS…\p"
	.string "…Zzzzz…$"

ViridianCity_Text_Youngster:
	.string "He oído que hay muchos objetos\n"
	.string "por el suelo del BOSQUE VERDE.$"

ViridianCity_Text_Sign:
	.string "CIUDAD VERDE\p"
	.string "El paraíso verde eterno$"

ViridianCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD VERDE\n"
	.string "LÍDER: …\p"
	.string "El resto del texto es ilegible…$"

ViridianCity_Text_WelcomeSign:
	.string "BIENVENIDO A CIUDAD VERDE,\p"
	.string "PUERTA DE LA MESETA AÑIL$"

ViridianCity_Text_TrainerHouseSign:
	.string "CASA DEL ENTRENADOR\p"
	.string "Club de combates de élite$"
