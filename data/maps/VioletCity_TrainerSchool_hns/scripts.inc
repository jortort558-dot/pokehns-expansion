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
	.string "Good! Teach you, I will!\p"
	.string "In battle, POKéMON top on list\n"
	.string "jump out first!\p"
	.string "Change order in list, make\n"
	.string "battle easy, maybe!\p"
	.string "More from me you want to hear?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "So, want to know how to raise\n"
	.string "POKéMON well?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "Fine! Teach you, I will!\p"
	.string "If POKéMON come out in battle\n"
	.string "even briefly, some EXP. Points\p"
	.string "it gets.\n"
	.string "At top of list put weak POKéMON\p"
	.string "Switch in battle quick!\n"
	.string "This way, weak POKéMON strong\p"
	.string "become!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh! Smart student you are!\n"
	.string "Nothing more do I teach!\p"
	.string "If you want more, talk to\n"
	.string "pupils!$"

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
	.string "It's this kid's notebook…\p"
	.string "Catch POKéMON using POKé BALLS.\p"
	.string "Up to six can be in your party.\p"
	.string "Keep reading?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Before throwing a POKé BALL,\n"
	.string "weaken the target first.\p"
	.string "A poisoned or burned POKéMON\n"
	.string "is easier to catch.\p"
	.string "Keep reading?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Some moves may cause confusion.\p"
	.string "Confusion may make a POKéMON\n"
	.string "attack itself.\p"
	.string "Leaving battle clears up any\n"
	.string "confusion.\p"
	.string "Keep reading?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "People who catch and use\n"
	.string "POKéMON in battle are POKéMON\n"
	.string "trainers.\p"
	.string "They are expected to visit\n"
	.string "POKéMON GYMS and defeat other\n"
	.string "trainers.\p"
	.string "The next page is… Blank!\p"
	.string "Boy: E-he-he…\p"
	.string "I haven't written anymore…$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "This super machine prints data\n"
	.string "out as stickers!$"
