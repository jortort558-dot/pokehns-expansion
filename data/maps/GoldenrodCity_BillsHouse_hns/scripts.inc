GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "BILL: ¡Hola, {PLAYER}! Hazme\n"
    .string "un favor\l"
    .string "y quédate con este EEVEE.\p"
    .string "Nos lo dejaron a cuidar mientras yo\n"
    .string "andaba fuera perfeccionando mi PC.\p"
    .string "Alguien tiene que sacarlo de paseo,\n"
    .string "pero yo soy muy casero…\p"
    .string "¿Puedo contar contigo para que lo\n"
    .string "entrenes, {PLAYER}?$"

BillHouse_Text_CountingOnYou:
    .string "BILL: ¡Sabía que no me fallarías!\p"
    .string "¡Eres un fenómeno!\p"
    .string "Cuento contigo, ¿eh?\n"
    .string "¡Cuídalo de maravilla!$"

BillHouse_Text_ReceivedEevee:
    .string "¡{PLAYER} recibió a EEVEE!$"

BillHouse_Text_EeveeMayEvolve:
    .string "BILL: El PROF. ELM dice que EEVEE\n"
    .string "puede evolucionar de formas nuevas\ly\l"
    .string "desconocidas.$"

BillHouse_Text_PartyFull:
    .string "¡Ojo, espera! No tienes hueco para\n"
    .string "más POKéMON en tu equipo.$"

BillHouse_Text_NoEevee:
    .string "Vaya… ¿Y ahora qué hago yo con él?$"

BillHouse_Text_PopWontWork:
    .string "BILL: Mi padre no da un palo al\nagua.\l"
    .string "Se pasa el día vagueando de un lado\la\l"
    .string "otro. Es un caso perdido…$"

BillHouse_Text_MomBeforeEcruteak:
    .string "¿Coleccionas POKéMON? Mi hijo BILL\n"
    .string "es todo un experto.\p"
    .string "Lo acaban de llamar del CENTRO\n"
    .string "POKéMON de CIUDAD IRIS.\p"
    .string "Y mi marido se ha largado al CASINO\n"
    .string "sin que nadie le diga nada…$"

BillHouse_Text_MomAfterEcruteak:
    .string "De joven a mi marido lo llamaban el\n"
    .string "POKéMANÍACO.\p"
    .string "BILL debió de heredar esa misma\lpasión\l"
    .string "por los bichos.$"

BillHouse_Text_SisterUsefulNumber:
    .string "¿Eres entrenador?\p"
    .string "Tengo un número de teléfono que te\n"
    .string "va a venir de perlas.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} registró el número\n"
    .string "de BILL.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mi hermano creó el sistema de\n"
    .string "almacenamiento del PC.\p"
    .string "Iba a darte el número de BILL…$"

BillHouse_Text_SisterPhoneFull:
    .string "No puedes registrar más números.$"

BillHouse_Text_SisterStorageSystem:
    .string "Mi hermano mayor BILL inventó el\n"
    .string "sistema de almacenamiento del PC.$"
