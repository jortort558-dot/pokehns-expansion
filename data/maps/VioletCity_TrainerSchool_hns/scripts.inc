VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "No soy de la época de la GBA,\n"
	.string "¡pero me encantan los juegos\l"
	.string "de POKéMON!\p"
	.string "En los juegos clásicos tenías que\n"
	.string "combatir contra muchos POKéMON\l"
	.string "salvajes para ganar suficiente EXP.\p"
	.string "En los nuevos, el REPARTIR EXP.\n"
	.string "hace que suban demasiado rápido.\p"
	.string "Aquí está equilibrado para que tus\n"
	.string "POKéMON tengan el nivel adecuado,\l"
	.string "o algo más si combates mucho.\p"
	.string "Si prefieres la experiencia clásica\n"
	.string "de las GEN 1-4, desactívalo.\l"
	.string "Si prefieres la moderna, actívalo.\p"
	.string "¡Tú decides cómo jugar!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "¡EARL, yo ser!\p"
	.string "¡Maravilla ser los POKéMON, sí!\p"
	.string "¡Enseñarte yo para ser un mejor\n"
	.string "entrenador!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Algunos POKéMON empiezan siendo\n"
	.string "débiles y necesitan mucha más EXP.\l"
	.string "que otros para fortalecerse.\p"
	.string "Por ejemplo, LARVITAR es débil,\n"
	.string "pero acaba convirtiéndose en un\l"
	.string "poderoso TYRANITAR a cambio\l"
	.string "de muchísima EXP.\p"
	.string "Solo entrenadores muy constantes\n"
	.string "deberían intentar criar uno.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "¡Bien! ¡Enseñarte yo haré!\p"
	.string "En combate, ¡el POKéMON arriba en\n"
	.string "la lista salir primero!\p"
	.string "Cambiar orden de lista, ¡hacer\n"
	.string "combate más fácil tal vez!\p"
	.string "¿Más cosas de mí querer oír?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "¿Querer saber cómo criar y entrenar\n"
	.string "a los POKéMON bien?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "¡Estupendo! ¡Enseñarte yo haré!\p"
	.string "Si un POKéMON sale a combatir,\n"
	.string "aunque sea un instante, ¡EXP.\l"
	.string "recibirá!\p"
	.string "Pon arriba al POKéMON más débil,\n"
	.string "¡y cámbialo rápido al luchar!\p"
	.string "¡Así, el POKéMON débil se hará\n"
	.string "fuerte!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "¡Oh! ¡Alumno muy listo ser tú!\n"
	.string "¡Nada más tener yo para enseñar!\p"
	.string "¡Si más querer, hablar con los\n"
	.string "demás alumnos!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Los POKéMON que antes solo\n"
	.string "evolucionaban por intercambio ahora\l"
	.string "pueden hacerlo subiendo de nivel.\p"
	.string "MACHOKE y GRAVELER evolucionan\n"
	.string "al NV. 38; KADABRA y HAUNTER,\l"
	.string "al NV. 42.\p"
	.string "Algunos objetos, como el REVEST.\n"
	.string "METÁLICO, también permiten\l"
	.string "evolucionar si se llevan equipados\l"
	.string "al subir de nivel.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "¡Puedes ver por el escenario\n"
	.string "POKéMON destacados de la zona!\p"
	.string "¡Pero explora las rutas de DÍA\n"
	.string "y de NOCHE. ¡No te pierdas ninguno!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Las BAYAS de JOHTO son ideales para\n"
	.string "curar y fabricar Poké Balls.\p"
	.string "En KANTO, ciertas BAYAS reducen\n"
	.string "los puntos de esfuerzo.\p"
	.string "¡Y el DOJO de KANTO ayuda\n"
	.string "a perfeccionar los atributos\l"
	.string "individuales!$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Ten en cuenta que tus rivales ahora\n"
	.string "llevan equipos con mejor cobertura\l"
	.string "de tipos. ¡Prepárate para un viaje\l"
	.string "bastante más exigente!$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "En la pizarra se explican los\n"
	.string "movimientos MO de los POKéMON.\p"
	.string "Una vez desbloqueadas, las MOs no\n"
	.string "deben enseñarse para usarlas fuera.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "Es el cuaderno de este alumno…\p"
	.string "Atrapa POKéMON usando POKé BALLS.\p"
	.string "Puedes llevar hasta seis en tu\n"
	.string "equipo.\p"
	.string "¿Quieres seguir leyendo?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Antes de lanzar una POKé BALL,\n"
	.string "debilita primero al objetivo.\p"
	.string "Un POKéMON envenenado o quemado\n"
	.string "será mucho más fácil de atrapar.\p"
	.string "¿Quieres seguir leyendo?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Ciertos ataques causan confusión.\p"
	.string "Un POKéMON confuso puede llegar\n"
	.string "a golpearse a sí mismo.\p"
	.string "Cambiar de POKéMON o terminar el\n"
	.string "combate cura toda confusión.\p"
	.string "¿Quieres seguir leyendo?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Quienes atrapan y usan POKéMON en\n"
	.string "combates son entrenadores POKéMON.\p"
	.string "Su meta es desafiar los GIMNASIOS\n"
	.string "y medirse a otros entrenadores.\p"
	.string "La página siguiente está…\n"
	.string "¡en blanco!\p"
	.string "Chico: Je, je, je…\p"
	.string "No me ha dado tiempo a escribir\n"
	.string "más…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "¡Esta supermáquina imprime datos\n"
	.string "en forma de pegatinas!$"
