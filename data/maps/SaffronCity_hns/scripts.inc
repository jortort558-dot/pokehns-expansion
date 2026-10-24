SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "BAOBA$"

SaffronCity_Text_Baoba:
	.string "DIRECTOR BAOBA: ¡{PLAYER}!\p"
	.string "Soy el DIRECTOR BAOBA.\p"
	.string "Te llamo para avisarte de que\n"
	.string "¡la ZONA SAFARI se ha ampliado\l"
	.string "otra vez!\p"
	.string "¡Por fin mi ZONA SAFARI está\n"
	.string "completamente terminada!\p"
	.string "¿Te acuerdas de dónde está, verdad?\p"
	.string "¡Al oeste de CIUDAD ORQUÍDEA!\n"
	.string "¡Nos vemos pronto!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "¡Me encanta VULPIX! :D$"

SaffronCity_Text_Lass1:
	.string "Aquí vive una chica que es\n"
	.string "experta en imitar a la gente.\p"
	.string "Imita incluso a la gente con la\n"
	.string "que habla, y te confunde.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIONA parecía muy triste.\p"
	.string "Dijo que perdió su POKé MUÑECO\n"
	.string "favorito: CLEFAIRY.$"

SaffronCity_Text_PokefanM:
	.string "¿Eres de JOHTO?\p"
	.string "Si funcionara el MAGNETOTRÉN, no\n"
	.string "tardarías nada en volver a casa.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "¿Eres de JOHTO?\p"
	.string "Con el MAGNETOTRÉN enseguida\n"
	.string "estarás de vuelta en casa.$"

SaffronCity_Text_CooltrainerM:
	.string "Iba al GIMNASIO a luchar contra\n"
	.string "los entrenadores…\p"
	.string "¡Y acabé en el viejo GIMNASIO\n"
	.string "que hay al lado!\p"
	.string "¡Vaya, qué vergüenza pasé!$"

SaffronCity_Text_CooltrainerF:
	.string "Es SILPH S.A., famosa por sus\n"
	.string "magníficos artículos POKéMON.\p"
	.string "En el pasado, el TEAM ROCKET\n"
	.string "quiso hacerse con esta compañía\l"
	.string "por esa misma razón.$"

SaffronCity_Text_Fisher:
	.string "¡Ñam, ñam!\p"
	.string "Dicen que en la CENTRAL ENERGÍA\n"
	.string "tienen muchos problemas.\p"
	.string "¡Ñam, ñam!$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "¡Ñam, ñam!\p"
	.string "Dicen que hubo problemas en la\n"
	.string "CENTRAL ENERGÍA.\p"
	.string "¡Ñam, ñam! ¡Estoy lleno!$"

SaffronCity_Text_Youngster1:
	.string "Entrar por primera vez en un\n"
	.string "callejón me pone un poco nervioso.$"

SaffronCity_Text_Youngster2:
	.string "En CIUDAD VERDE hay un lugar\n"
	.string "llamado la CASA del ENTRENADOR,\l"
	.string "donde se reúne gente de todas\l"
	.string "partes.$"

SaffronCity_Text_Lass2:
	.string "Nuestra ciudad salió en un\n"
	.string "programa de radio.\p"
	.string "Está bien oír alabanzas sobre tu\n"
	.string "ciudad, pero también da un poco\l"
	.string "de vergüenza.$"

SaffronCity_Text_Sign:
	.string "CIUDAD AZAFRÁN\n"
	.string "La brillante y dorada tierra\l"
	.string "del comercio.$"

SaffronCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD AZAFRÁN: SABRINA\p"
	.string "Maestra de los POKéMON\n"
	.string "psíquicos.$"

SaffronCity_Text_FightingDojoSign:
	.string "PUERTAS ABIERTAS:\n"
	.string "DOJO KARATE$"

SaffronCity_Text_SilphCoSign:
	.string "SILPH S.A.\n"
	.string "EDIFICIO CENTRAL$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "CASA DEL SR. PSÍQUICO$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ESTACIÓN DEL MAGNETOTRÉN DE\n"
	.string "CIUDAD AZAFRÁN$"

SaffronCity_EventScript_Rosa::
	lock
	faceplayer
	callnative GetDailyRosaChallengeInfo
	goto_if_set FLAG_DAILY_ROSA_CHALLENGE_WON, SaffronCity_EventScript_RosaAlreadyWon
	goto_if_set FLAG_DAILY_ROSA_CHALLENGE_ATTEMPTED, SaffronCity_EventScript_RosaAlreadyAttempted
	msgbox SaffronCity_Text_RosaIntro, MSGBOX_DEFAULT
	call SaffronCity_EventScript_RosaDisplayHint
	msgbox SaffronCity_Text_RosaAskBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_EventScript_RosaDecline
	msgbox SaffronCity_Text_RosaAccept, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DAILY_ROSA_CHALLENGE_ATTEMPTED
	switch VAR_0x8005
	case 0, SaffronCity_EventScript_RosaBattle0
	case 1, SaffronCity_EventScript_RosaBattle1
	case 2, SaffronCity_EventScript_RosaBattle2
	case 3, SaffronCity_EventScript_RosaBattle3
	case 4, SaffronCity_EventScript_RosaBattle4
	case 5, SaffronCity_EventScript_RosaBattle5
	case 6, SaffronCity_EventScript_RosaBattle6
	case 7, SaffronCity_EventScript_RosaBattle7
	case 8, SaffronCity_EventScript_RosaBattle8
	case 9, SaffronCity_EventScript_RosaBattle9
	case 10, SaffronCity_EventScript_RosaBattle10
	case 11, SaffronCity_EventScript_RosaBattle11
	case 12, SaffronCity_EventScript_RosaBattle12
	case 13, SaffronCity_EventScript_RosaBattle13
	goto SaffronCity_EventScript_RosaBattle0
	end

SaffronCity_EventScript_RosaBattle0::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_0_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle1::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_1_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle2::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_2_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle3::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_3_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle4::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_4_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle5::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_5_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle6::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_6_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle7::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_7_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle8::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_8_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle9::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_9_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle10::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_10_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle11::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_11_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle12::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_12_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaBattle13::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_13_HNS, SaffronCity_Text_RosaDefeat
	goto SaffronCity_EventScript_RosaPostBattle
	end

SaffronCity_EventScript_RosaPostBattle::
	setflag FLAG_DAILY_ROSA_CHALLENGE_WON
	msgbox SaffronCity_Text_RosaReward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	msgbox SaffronCity_Text_RosaWonFinal, MSGBOX_DEFAULT
	release
	end

SaffronCity_EventScript_RosaAlreadyWon::
	msgbox SaffronCity_Text_RosaAlreadyWon, MSGBOX_DEFAULT
	release
	end

SaffronCity_EventScript_RosaAlreadyAttempted::
	msgbox SaffronCity_Text_RosaAlreadyAttempted, MSGBOX_DEFAULT
	release
	end

SaffronCity_EventScript_RosaDecline::
	msgbox SaffronCity_Text_RosaDecline, MSGBOX_DEFAULT
	release
	end

SaffronCity_EventScript_RosaDisplayHint::
	switch VAR_0x8005
	case 0, SaffronCity_EventScript_RosaHint0
	case 1, SaffronCity_EventScript_RosaHint1
	case 2, SaffronCity_EventScript_RosaHint2
	case 3, SaffronCity_EventScript_RosaHint3
	case 4, SaffronCity_EventScript_RosaHint4
	case 5, SaffronCity_EventScript_RosaHint5
	case 6, SaffronCity_EventScript_RosaHint6
	case 7, SaffronCity_EventScript_RosaHint7
	case 8, SaffronCity_EventScript_RosaHint8
	case 9, SaffronCity_EventScript_RosaHint9
	case 10, SaffronCity_EventScript_RosaHint10
	case 11, SaffronCity_EventScript_RosaHint11
	case 12, SaffronCity_EventScript_RosaHint12
	case 13, SaffronCity_EventScript_RosaHint13
	return

SaffronCity_EventScript_RosaHint0::
	msgbox SaffronCity_Text_RosaHint0, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint1::
	msgbox SaffronCity_Text_RosaHint1, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint2::
	msgbox SaffronCity_Text_RosaHint2, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint3::
	msgbox SaffronCity_Text_RosaHint3, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint4::
	msgbox SaffronCity_Text_RosaHint4, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint5::
	msgbox SaffronCity_Text_RosaHint5, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint6::
	msgbox SaffronCity_Text_RosaHint6, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint7::
	msgbox SaffronCity_Text_RosaHint7, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint8::
	msgbox SaffronCity_Text_RosaHint8, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint9::
	msgbox SaffronCity_Text_RosaHint9, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint10::
	msgbox SaffronCity_Text_RosaHint10, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint11::
	msgbox SaffronCity_Text_RosaHint11, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint12::
	msgbox SaffronCity_Text_RosaHint12, MSGBOX_DEFAULT
	return

SaffronCity_EventScript_RosaHint13::
	msgbox SaffronCity_Text_RosaHint13, MSGBOX_DEFAULT
	return

SaffronCity_Text_RosaIntro:
	.string "ROSA: ¡Hola! Soy ROSA,\n"
	.string "LA ESTRATEGA.\p"
	.string "Entrenar junto al DOJO me ha\n"
	.string "permitido perfeccionar las tácticas\l"
	.string "de combate más exigentes.\p"
	.string "Cada día entreno con un arquetipo\n"
	.string "competitivo de alto nivel.\p"
	.string "Solo tienes una oportunidad al día\n"
	.string "para derrotarme, pero no temas:\l"
	.string "las derrotas aquí no son fatales.$"

SaffronCity_Text_RosaAskBattle:
	.string "¿Te atreves a medirte a mi\n"
	.string "estrategia de hoy?$"

SaffronCity_Text_RosaAccept:
	.string "¡Excelente! ¡Demuéstrame el nivel\n"
	.string "de tu preparación!$"

SaffronCity_Text_RosaDecline:
	.string "Entendido. Vuelve cuando sientas\n"
	.string "que tu equipo está listo.$"

SaffronCity_Text_RosaDefeat:
	.string "¡Impresionante despliegue!\n"
	.string "Has quebrado mi esquema táctico.$"

SaffronCity_Text_RosaReward:
	.string "Una victoria impecable.\n"
	.string "Te has ganado esta recompensa.$"

SaffronCity_Text_RosaWonFinal:
	.string "Mañana prepararé una táctica\n"
	.string "diferente. ¡Te esperaré!$"

SaffronCity_Text_RosaAlreadyWon:
	.string "ROSA: ¡Ya has superado el reto\n"
	.string "de hoy con honores!\p"
	.string "Vuelve mañana para enfrentarte a\n"
	.string "un nuevo arquetipo.$"

SaffronCity_Text_RosaAlreadyAttempted:
	.string "ROSA: Ya has combatido hoy.\p"
	.string "La disciplina exige estudiar los\n"
	.string "errores antes del próximo reto.\p"
	.string "¡Vuelve mañana para intentarlo!$"

SaffronCity_Text_RosaHint0:
	.string "Pista táctica de hoy:\n"
	.string "¡Lluvia incesante y atacantes\l"
	.string "veloces bajo el agua!$"

SaffronCity_Text_RosaHint1:
	.string "Pista táctica de hoy:\n"
	.string "¡Sol abrasador, clorofila y\l"
	.string "poderosas bestias del pasado!$"

SaffronCity_Text_RosaHint2:
	.string "Pista táctica de hoy:\n"
	.string "¡Arena asfixiante, desgastes y\l"
	.string "topos veloces entre el polvo!$"

SaffronCity_Text_RosaHint3:
	.string "Pista táctica de hoy:\n"
	.string "¡Nieve glacial, Velo Aurora y\l"
	.string "ofensiva contundente de hielo!$"

SaffronCity_Text_RosaHint4:
	.string "Pista táctica de hoy:\n"
	.string "¡Espacio Raro! Los más lentos\l"
	.string "golpearán primero con furia.$"

SaffronCity_Text_RosaHint5:
	.string "Pista táctica de hoy:\n"
	.string "¡Hiperofensiva tras pantallas!\l"
	.string "Cuidado con los potenciadores.$"

SaffronCity_Text_RosaHint6:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo Eléctrico y la implacable\l"
	.string "maquinaria del futuro!$"

SaffronCity_Text_RosaHint7:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo Psíquico! La Fuerza\l"
	.string "Expansiva arrasará todo.$"

SaffronCity_Text_RosaHint8:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo de Hierba y ataques de\l"
	.string "prioridad implacables!$"

SaffronCity_Text_RosaHint9:
	.string "Pista táctica de hoy:\n"
	.string "¡Muro defensivo supremo!\l"
	.string "Desgaste, púas y regeneración.$"

SaffronCity_Text_RosaHint10:
	.string "Pista táctica de hoy:\n"
	.string "¡Velocidad extrema y prioridad!\l"
	.string "Atacantes letales de remate.$"

SaffronCity_Text_RosaHint11:
	.string "Pista táctica de hoy:\n"
	.string "¡Estructura de campeonato!\l"
	.string "Intimidación doble y control.$"

SaffronCity_Text_RosaHint12:
	.string "Pista táctica de hoy:\n"
	.string "¡Relevo y aumentos de poder!\l"
	.string "Una cadena táctica coordinada.$"

SaffronCity_Text_RosaHint13:
	.string "Pista táctica de hoy:\n"
	.string "¡Especial Festivo Navideño!\l"
	.string "Espíritu invernal y estrellas.$"

