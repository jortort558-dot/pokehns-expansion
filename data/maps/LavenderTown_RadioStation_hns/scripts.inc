LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "¡Bienvenido! Puedes visitar\n"
	.string "libremente toda esta planta.$"
LavenderTown_RadioStation_Text_Officer:
	.string "Lo siento, pero solo se puede\n"
	.string "visitar la planta baja.\p"
	.string "Desde que una banda criminal tomó\n"
	.string "la TORRE RADIO de JOHTO, hemos\l"
	.string "reforzado la seguridad.$"
LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Aquí trabaja muchísima gente.\p"
	.string "Seguro que todos se esfuerzan para\n"
	.string "emitir buenos programas.$"
LavenderTown_RadioStation_Text_Gentleman:
	.string "¡Oh, no, no, no!\p"
	.string "Estamos fuera de antena desde que\n"
	.string "se detuvo la CENTRAL DE ENERGÍA.\p"
	.string "Todo mi esfuerzo por poner en\n"
	.string "marcha esta emisora será inútil\l"
	.string "si no podemos emitir.\p"
	.string "¡Me arruinaré!$"
LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "¡Ah! ¿Eres {PLAYER}, quien arregló\n"
	.string "el problema de la CENTRAL?\p"
	.string "Gracias a ti no perdí mi trabajo.\p"
	.string "¡Me has salvado la vida!\p"
	.string "Acepta esto como agradecimiento.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "¡{PLAYER} consiguió la\n"
	.string "TARJETA EXPANSIÓN!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Con eso podrás sintonizar los\n"
	.string "programas de radio de KANTO.\p"
	.string "¡Jajajaja!$"
LavenderTown_RadioStation_Text_SuperNerd2:
	.string "¡Hola!\p"
	.string "¡Soy el gran DIRECTOR MUSICAL!\p"
	.string "¿Tu RADIO no sintoniza mis\n" @POKéGEAR
	.string "programas? ¡Qué desgracia!\p"
	.string "Con una TARJETA EXPANSIÓN podrás\n"
	.string "escucharlos. ¡Consigue una!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "¡Hola!\p"
	.string "¡Soy el gran DIRECTOR MUSICAL!\p"
	.string "Me encargo de las maravillosas\n"
	.string "melodías que emitimos.\p"
	.string "No seas anticuado. ¡Sintoniza\n"
	.string "nuestra música!$"
LavenderTown_RadioStation_Text_Directory:
	.string "PB RECEPCIÓN  P1 VENTAS\p"
	.string "P2 PERSONAL   P3 PRODUCCIÓN\p"
	.string "P4 DESPACHO DEL DIRECTOR$"
LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Relaja a tus POKéMON con los\n"
	.string "dulces sonidos de la POKé FLAUTA\l"
	.string "en el CANAL 20.$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "¡Vaya! Un estante lleno de CD y\n"
	.string "vídeos de POKéMON.\p"
	.string "Debe de ser la biblioteca de\n"
	.string "consulta.$"
