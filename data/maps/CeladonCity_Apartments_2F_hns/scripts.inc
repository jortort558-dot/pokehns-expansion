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
	.string "{PLAYER} encendió\n"
	.string "el PC.\p"
	.string "…\p"
	.string "Alguien estaba\n"
	.string "escribiendo un\l"
	.string "e-mail.\p"
	.string "Espero que vengas\n"
	.string "a KANTO.\p"
	.string "Te sorprenderás de\n"
	.string "cuánto han\p"
	.string "cambiado las\n"
	.string "cosas por aquí.\p"
	.string "También verás\n"
	.string "muchos POKéMON\p"
	.string "que no son nativos\n"
	.string "de JOHTO.\p"
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
	.string "¡Hola a todos, parche 15!\p"
	.string "Perdón, quería decir…\p"
	.string "¡Hola! ¡Soy el DIRECTOR!\p"
	.string "Creé los mapas, los tilesets,\n"
	.string "los scripts y mucho más.\p"
	.string "Pero no habría podido hacerlo\n"
	.string "sin los demás desarrolladores\l"
	.string "y quienes probaron el juego.\p"
	.string "¡Gracias por jugar! Espero que\n"
	.string "hayas disfrutado de POKéMON\l"
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
	.string "¿Has jugado a SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH?\p"
	.string "¡Yo lo traduje!\p"
	.string "Creo que mi próximo DEMAKE será\n"
	.string "¡el de ALOLA!$"

CeladonMansion2F_Text_Exclsior:
	.string "¡Implementé sprites únicos para\n"
	.string "cada POKéMON al hacer SURF!\p"
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
	.string "Pero DRAGONITE iba demasiado\n"
	.string "rápido con VELOC. EXTREMA\l"
	.string "¡y no pudo atraparlo!$"
