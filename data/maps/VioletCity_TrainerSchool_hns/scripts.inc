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
	.string "No soy de la época de la GBA, ¡pero\n"
	.string "me flipan los juegos de POKéMON!\p"
	.string "En las ediciones clásicas tenías\nque\l"
	.string "pelear contra mil bichos salvajes\l"
	.string "para conseguir suficiente EXP.\p"
	.string "Pero en los nuevos, el REPARTIR\nEXP.\l"
	.string "hace que subas de nivel en un\nsuspiro.\p"
	.string "En este juego está equilibrado para\n"
	.string "que tus POKéMON tengan el nivel\njusto\l"
	.string "según los combates que disputes.\p"
	.string "Si prefieres el desafío clásico de\nla\l"
	.string "GEN 1-4, desactiva el REPARTIR EXP.\l"
	.string "Si buscas algo más ágil, déjalo\nACTIVO.\p"
	.string "¡Tú decides cómo jugar!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "¡EARL, yo ser!\p"
	.string "¡Maravilla ser los POKéMON, sí!\p"
	.string "¡Enseñarte yo para ser un mejor\n"
	.string "entrenador!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Hay ciertos POKéMON que empiezan\nmuy\l"
	.string "débiles y exigen montones de EXP\npara\l"
	.string "desatar su verdadero potencial.\p"
	.string "Por ejemplo, LARVITAR parece poca\ncosa,\l"
	.string "pero acabará siendo un imponente\l"
	.string "TYRANITAR si le dedicas mucho\nesfuerzo.\p"
	.string "¡Solo los entrenadores más\nconstantes\l"
	.string "logran sacar provecho a tales\njoyas!$"

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
	.string "Si un POKéMON sale a luchar aunque\n"
	.string "sea un instante, ¡puntos de EXP\l"
	.string "recibirá!\p"
	.string "Pon arriba al POKéMON más débil,\n"
	.string "¡y cámbialo rápido al luchar!\p"
	.string "¡Así, el POKéMON débil en fuerte\n"
	.string "se convertirá!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "¡Oh! ¡Alumno muy listo ser tú!\n"
	.string "¡Nada más tener yo para enseñar!\p"
	.string "¡Si más querer, hablar con los\n"
	.string "demás alumnos!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Los POKéMON que antes solo\nevolucionaban\l"
	.string "por intercambio ahora pueden\nhacerlo\p"
	.string "subiendo de nivel.\n"
	.string "MACHOKE y GRAVELER evolucionan al\nNV. 38,\p"
	.string "mientras que KADABRA y HAUNTER lo\nhacen\l"
	.string "al NV. 42.\p"
	.string "Ciertos objetos, como el\nREVESTIMIENTO\l"
	.string "METÁLICO, permiten evolucionar si\nlos\l"
	.string "llevan equipados al subir de nivel.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "¡Puedes ver a los POKéMON más\ndestacados\l"
	.string "de la zona paseando por el\nescenario!\p"
	.string "¡Pero asegúrate de explorar las\nrutas de\l"
	.string "DÍA y de NOCHE para no perderte\nninguno!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Las BAYAS de JOHTO son fantásticas\npara\l"
	.string "curar y fabricar Poké Balls.\p"
	.string "En KANTO, ciertas bayas sirven para\n"
	.string "reducir los puntos de esfuerzo de\nun bicho.\p"
	.string "¡Y el DOJO de KANTO ayuda a\nperfeccionar\l"
	.string "las estadísticas individuales!$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Ten en cuenta que tus rivales ahora\n"
	.string "llevan equipos con mejor cobertura\l"
	.string "de tipos. ¡Prepárate para un viaje\l"
	.string "bastante más exigente!$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "En la pizarra se explican los\n"
	.string "movimientos MO de los POKéMON.\p"
	.string "¡Las MOs, una vez desbloqueadas, no\n"
	.string "necesitan enseñarse para usarlas\nfuera!$"

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
	.string "La página siguiente está… ¡en\nblanco!\p"
	.string "Chico: Je, je, je…\p"
	.string "No me ha dado tiempo a escribir\nmás…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "¡Esta supermáquina imprime datos\n"
	.string "en forma de pegatinas!$"
