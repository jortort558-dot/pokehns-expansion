EventScript_CarnetPokemitosMenu::
	lockall
EventScript_CarnetPokemitosMenuLoop::
	message CarnetPokemitos_Text_MenuTitle
	waitmessage
	dynmultipush CarnetPokemitos_Text_OptionPasses, 0
	dynmultipush CarnetPokemitos_Text_OptionStatus, 1
	dynmultipush CarnetPokemitos_Text_OptionRules, 2
	dynmultipush CarnetPokemitos_Text_OptionExit, 3
	dynmultistack 0, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, EventScript_CarnetPokemitos_Passes
	case 1, EventScript_CarnetPokemitos_Status
	case 2, EventScript_CarnetPokemitos_Rules
	case 3, EventScript_CarnetPokemitos_Exit
	case MULTI_B_PRESSED, EventScript_CarnetPokemitos_Exit
	goto EventScript_CarnetPokemitos_Exit

EventScript_CarnetPokemitos_Passes::
	special BufferPokemitosTicketsSummary
	msgbox CarnetPokemitos_Text_PassesSummary, MSGBOX_DEFAULT
	goto EventScript_CarnetPokemitosMenuLoop

EventScript_CarnetPokemitos_Status::
	special BufferPokemitosStatusSummary
	msgbox CarnetPokemitos_Text_StatusSummary, MSGBOX_DEFAULT
	goto EventScript_CarnetPokemitosMenuLoop

EventScript_CarnetPokemitos_Rules::
	msgbox CarnetPokemitos_Text_Rules, MSGBOX_DEFAULT
	goto EventScript_CarnetPokemitosMenuLoop

EventScript_CarnetPokemitos_Exit::
	closemessage
	releaseall
	end

CarnetPokemitos_Text_MenuTitle:
	.string "CARNET POKÉMITOS CUP II\n"
	.string "¿Qué deseas consultar?$"

CarnetPokemitos_Text_OptionPasses:
	.string "Pases y Capturas$"

CarnetPokemitos_Text_OptionStatus:
	.string "Estado del Torneo$"

CarnetPokemitos_Text_OptionRules:
	.string "Reglas de la Copa$"

CarnetPokemitos_Text_OptionExit:
	.string "Cerrar Carnet$"

CarnetPokemitos_Text_PassesSummary:
	.string "PASES DE CAPTURA POKÉMITOS:\p"
	.string "CONCURSO DE BICHOS:\n"
	.string "{STR_VAR_1}\p"
	.string "ZONA SAFARI JOHTO:\n"
	.string "{STR_VAR_2}\p"
	.string "ZONA SAFARI KANTO:\n"
	.string "{STR_VAR_3}$"

CarnetPokemitos_Text_StatusSummary:
	.string "CARNET POKÉMITOS CUP II\p"
	.string "Participante: {PLAYER}\n"
	.string "Fichas Pokemitos: {STR_VAR_1}\l"
	.string "Medallas ganadas: {STR_VAR_2}/16\p"
	.string "Semanas computadas: {STR_VAR_3}\n"
	.string "Reglas oficiales activas.$"

CarnetPokemitos_Text_Rules:
	.string "REGLAS POKÉMITOS CUP II:\p"
	.string "1. Locke activo: POKéMON caído\n"
	.string "   no puede volver a usarse.\p"
	.string "2. Pases de captura semanales\n"
	.string "   independientes por zona.\p"
	.string "3. Límites de nivel activos\n"
	.string "   según cada líder.$"
