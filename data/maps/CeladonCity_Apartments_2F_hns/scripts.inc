CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} encendió el PC.\p"
	.string "…\p"
	.string "Alguien estaba redactando un\n"
	.string "correo electrónico.\p"
	.string "Espero que vengas a KANTO.\p"
	.string "Creo que te sorprenderá cuánto\n"
	.string "han cambiado las cosas aquí.\p"
	.string "También verás muchos POKéMON que\n"
	.string "no son originarios de JOHTO.\p"
	.string "Al PRODUCTOR\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "HEART & SOUL DEVELOPMENT OFFICE$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "¡Hola a todos, parche 15…!\p"
	.string "Perdón, quería decir…\p"
	.string "¡Hola! ¡Soy el DIRECTOR DEL JUEGO!\p"
	.string "Creé los mapas, los gráficos, los\n"
	.string "scripts y muchas cosas más.\p"
	.string "Pero no podría haberlo hecho sin\n"
	.string "los demás desarrolladores ni\l"
	.string "quienes probaron el juego.\p"
	.string "¡Gracias por jugar! Espero que\n"
	.string "hayas disfrutado POKéMON\l"
	.string "HEART & SOUL.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "¡Estamos reconstruyendo el juego\n"
	.string "con pokeemerald-expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "¿Has oído hablar del EGGENING?\p"
	.string "Era un fallo de las pruebas que\n"
	.string "convertía POKéMON al azar en\l"
	.string "HUEVOS.\p"
	.string "¡Yo desarrollé la solución!$"

CeladonMansion2F_Text_Phant:
	.string "¡Me encantan los DEMAKES!\p"
	.string "¿Has jugado a ESPADA Y ESCUDO\n"
	.string "ULTIMATE PLUS, versión inglesa?\p"
	.string "¡Yo hice esa traducción!\p"
	.string "Creo que mi próximo DEMAKE será\n"
	.string "sobre ALOLA.$"

CeladonMansion2F_Text_Exclsior:
	.string "¡Implementé gráficos únicos para\n"
	.string "cada POKéMON que usa SURF!\p"
	.string "Como el proyecto es de CÓDIGO\n"
	.string "ABIERTO, ¡tú también puedes\l"
	.string "añadir funciones!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "¡Hola!\p"
	.string "Se me da bien encontrar fallos\n"
	.string "y arreglar los pequeños.\p"
	.string "¿Quieres oír un chiste?\p"
	.string "Lance quiso enseñar a DRAGONITE\n"
	.string "el movimiento DRAGOALIENTO.\p"
	.string "Pero iba tan rápido con VELOCIDAD\n"
	.string "EXTREMA que no pudo ni recuperar\l"
	.string "el aliento.$"
