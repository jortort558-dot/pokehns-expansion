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
	.string "¿Qué tal? Mira por\n"
	.string "donde quieras en\l"
	.string "esta planta.$"
LavenderTown_RadioStation_Text_Officer:
	.string "Lo siento, pero\n"
	.string "sólo puedes dar\p"
	.string "una vuelta por la\n"
	.string "planta baja.\p"
	.string "Desde que una\n"
	.string "banda criminal\p"
	.string "asaltó la TORRE\n"
	.string "RADIO de JOHTO,\p"
	.string "tuvimos que incre-\n"
	.string "mentar las medidas\l"
	.string "de seguridad.$"
LavenderTown_RadioStation_Text_SuperNerd1:
	.string "En la TORRE RADIO\n"
	.string "hay mucha gente\p"
	.string "que trabaja\n"
	.string "duramente.\p"
	.string "Seguro que están\n"
	.string "haciendo todo lo\p"
	.string "posible por emitir\n"
	.string "buenos programas.$"
LavenderTown_RadioStation_Text_Gentleman:
	.string "¡Oh, no, no, no!\p"
	.string "No hemos emitido\n"
	.string "desde que cerró la\l"
	.string "CENTRAL ENERGÍA.\p"
	.string "Si no emitimos, de\n"
	.string "nada servirá el\p"
	.string "esfuerzo realizado\n"
	.string "por la emisora.\p"
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
	.string "Con eso podrás\n"
	.string "sintonizar los\p"
	.string "programas de\n"
	.string "radio de KANTO.\p"
	.string "¡Jajajaja!$"
LavenderTown_RadioStation_Text_SuperNerd2:
	.string "¡Hola!\p"
	.string "¡Soy el gran DIRECTOR MUSICAL!\p"
	.string "¿Tu RADIO no sintoniza mis\n" @POKéGEAR
	.string "programas? ¡Qué desgracia!\p"
	.string "Con una TARJETA EXPANSIÓN podrás\n"
	.string "escucharlos. ¡Consigue una!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "¡Oye, joven!\p"
	.string "¡Soy el DIRECTOR\n"
	.string "de MÚSICA!\p"
	.string "Soy el encargado\n"
	.string "de las fantásticas\p"
	.string "melodías que se\n"
	.string "emiten aquí.\p"
	.string "No seas anticuado.\n"
	.string "¡Atrapa la música\l"
	.string "de las ondas!$"
LavenderTown_RadioStation_Text_Directory:
	.string "PB RECEPCIÓN\n"
	.string "P1 VENTAS\p"
	.string "P2 PERSONAL\n"
	.string "P3 PRODUCCIÓN\p"
	.string "P4 DESPACHO DEL\n"
	.string "   DIRECTOR$"
LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Relaja a tus POKéMON con los\n"
	.string "dulces sonidos de la POKé FLAUTA\l"
	.string "en el CANAL 20.$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "¡Uau! Un estante\n"
	.string "lleno de CD y\l"
	.string "vídeos de POKéMON.\p"
	.string "Debe de ser una\n"
	.string "biblioteca.$"
