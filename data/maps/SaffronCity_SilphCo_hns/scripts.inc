SaffronCity_SilphCo_hns_MapScripts::
	.byte 0

SaffronCity_SilphCo_EventScript_Steven::
	lock 
	msgbox SaffronCity_SilphCo_Text_Steven1, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	delay 20
	playse SE_PIN
	applymovement LOCALID_SILPHCO_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SILPHCO_STEVEN
SaffronCity_SilphCo_EventScript_StevenChooseStone::
	message SaffronCity_SilphCo_Text_Steven2
	waitmessage
	multichoice 20, 0, MULTI_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_SilphCo_EventScript_TreeckoChosen
	case 1, SaffronCity_SilphCo_EventScript_TorchicChosen
	case 2, SaffronCity_SilphCo_EventScript_MudkipChosen
	case MULTI_B_PRESSED, SaffronCity_SilphCo_EventScript_Refused

SaffronCity_SilphCo_EventScript_Refused::
	msgbox SaffronCity_SilphCo_Text_Refused, MSGBOX_DEFAULT
	turnobject LOCALID_SILPHCO_STEVEN, DIR_NORTH
	closemessage
	release
	end

SaffronCity_SilphCo_Text_Refused:
	.string "Vaya…$"

SaffronCity_SilphCo_EventScript_TreeckoChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TREECKO, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_TorchicChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TORCHIC, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_MudkipChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_MUDKIP, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven

SaffronCity_SilphCo_EventScript_AfterStarterGiven::
	msgbox SaffronCity_SilphCo_Text_Steven4, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SaffronCity_SilphCo_EventScript_PlayerMove
	applymovement LOCALID_SILPHCO_STEVEN, SaffronCity_SilphCo_Movement_StevenLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_GOT_HOENN_STARTER
	removeobject LOCALID_SILPHCO_STEVEN
	release
	end

SaffronCity_SilphCo_EventScript_PlayerMove:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

SaffronCity_SilphCo_Movement_StevenLeave:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


SaffronCity_SilphCo_Text_Steven1:
	.string "Hola…\n"
	.string "Se entrecorta la llamada…\l"
	.string "Creo que depende de mi padre.\p"
	.string "Ya veo…\n"
	.string "Me pondré en camino. Hasta pronto.$"
SaffronCity_SilphCo_Text_Steven2:
	.string "MÁXIMO: Tú eres… Recuerdo\n"
	.string "tus ojos.\p"
	.string "Siempre recuerdo a los entrenadores\n"
	.string "que tienen un brillo especial\l"
	.string "en la mirada.\p"
	.string "¡Tienes una POKéDEX! ¡Así que tú\n"
	.string "también buscas POKéMON!\p"
	.string "Déjame ver…\p"
	.string "Creo que puedo ayudarte.\p"
	.string "Imagina que tienes varias piedras\n"
	.string "delante. ¿Qué color elegirías?$"
SaffronCity_SilphCo_Text_Steven3:
	.string "¡Buena elección! ¡Te daré\n"
	.string "{STR_VAR_1}!$"
SaffronCity_SilphCo_Text_Steven4:
	.string "Cuídalo bien. Saber que lo tratas\n"
	.string "con cariño me hará muy feliz.$"

SaffronCity_SilphCo_EventScript_Receptionist::
	msgbox SilphCo_Text_Receptionist, MSGBOX_NPC
	end
SaffronCity_SilphCo_EventScript_Officer::
	goto_if_set FLAG_GOT_UP_GRADE, SaffronCity_SilphCo_EventScript_OfficerAfter
	msgbox SilphCo_Text_Officer, MSGBOX_NPC
	giveitem ITEM_UP_GRADE
	setflag FLAG_GOT_UP_GRADE
SaffronCity_SilphCo_EventScript_OfficerAfter::
	msgbox SilphCo_Text_Officer_GotUpGrade, MSGBOX_NPC
	end

SaffronCity_SilphCo_EventScript_Sign1::
	msgbox SilphCo_Text_Sign1, MSGBOX_SIGN
	end

SaffronCity_SilphCo_EventScript_Sign2::
	msgbox SilphCo_Text_Sign2, MSGBOX_SIGN
	end

SilphCo_Text_Sign1:
	.string "SILPH S.A.\n"
	.string "RECEPCIÓN, PB.$"

SilphCo_Text_Sign2:
	.string "SILPH S.A.\n"
	.string "ASCENSOR FUERA DE SERVICIO$"

SilphCo_Text_Receptionist:
	.string "Bienvenido a la sede central\n"
	.string "de SILPH S.A.$"

SilphCo_Text_Officer:
	.string "Solo los empleados pueden subir.\p"
	.string "Pero ya que has venido desde\n"
	.string "tan lejos,\p"
	.string "llévate este bonito recuerdo.$"

SilphCo_Text_Officer_GotUpGrade:
	.string "Es el último producto de\n"
	.string "SILPH S.A.\p"
	.string "Todavía no está a la venta.$"

SaffronCity_SilphCo_EventScript_ScientistZygarde::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_CO_ZYGARDE_CUBE_RECEIVED, SaffronCity_SilphCo_EventScript_ScientistZygarde_Done
	checkitem ITEM_MIMINUCLEO_TARAFANTASTICO
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_SilphCo_EventScript_ScientistZygarde_Assemble
	goto_if_set FLAG_MOHEDANO_QUEST_STARTED, SaffronCity_SilphCo_EventScript_ScientistZygarde_Waiting
	setflag FLAG_MOHEDANO_QUEST_STARTED
	msgbox SaffronCity_SilphCo_Text_ScientistIntro, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_EventScript_ScientistZygarde_Waiting::
	msgbox SaffronCity_SilphCo_Text_ScientistWaiting, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_EventScript_ScientistZygarde_Assemble::
	msgbox SaffronCity_SilphCo_Text_ScientistReward, MSGBOX_DEFAULT
	removeitem ITEM_MIMINUCLEO_TARAFANTASTICO
	giveitem ITEM_ZYGARDE_CUBE
	setflag FLAG_SILPH_CO_ZYGARDE_CUBE_RECEIVED
	msgbox SaffronCity_SilphCo_Text_ScientistExplainCube, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_EventScript_ScientistZygarde_Done::
	msgbox SaffronCity_SilphCo_Text_ScientistDone, MSGBOX_DEFAULT
	release
	end

SaffronCity_SilphCo_Text_ScientistIntro:
	.string "¡Qué catástrofe! ¡Un desastre\n"
	.string "para la ciencia moderna!\p"
	.string "Un ladrón estrambótico ha burlado\n"
	.string "la seguridad del laboratorio.\p"
	.string "Al parecer, lo vieron huir\n"
	.string "con un par de perras de caza.\p"
	.string "¡Se ha llevado nuestra mayor obra:\n"
	.string "el Miminúcleo Tarafantástico!\p"
	.string "Es la pieza de un contenedor\n"
	.string "para estabilizar la energía\l"
	.string "celular del legendario Zygarde.\p"
	.string "Detectamos picos bioeléctricos\n"
	.string "en la vieja Central de Energía...\p"
	.string "¡Por favor, debes recuperarlo!\n"
	.string "¡Te recompensaremos bien!$"

SaffronCity_SilphCo_Text_ScientistWaiting:
	.string "El ladrón sigue libre con el núcleo\n"
	.string "en la Central de Energía de Kanto.\p"
	.string "¡Si sobrecarga el Miminúcleo\n"
	.string "podría causar una catástrofe!$"

SaffronCity_SilphCo_Text_ScientistReward:
	.string "¡Increíble! ¡Has recuperado el\n"
	.string "Miminúcleo Tarafantástico!\p"
	.string "Déjame acoplar la matriz en\n"
	.string "el contenedor celular...\p"
	.string "¡Listo y bien calibrado!\n"
	.string "Como prometí, quédate con esto.$"

SaffronCity_SilphCo_Text_ScientistExplainCube:
	.string "Es el Arca de Zygarde.\p"
	.string "Con ella puedes transformar a\n"
	.string "Zygarde entre su Forma 10% y 50%.\p"
	.string "Además, con la habilidad\n"
	.string "Agrupamiento, desatará en combate\l"
	.string "su colosal Forma Completa.$"

SaffronCity_SilphCo_Text_ScientistDone:
	.string "Zygarde vela por el equilibrio de\n"
	.string "todo el ecosistema.\p"
	.string "En tus manos, esa tecnología está\n"
	.string "a salvo de malas intenciones.$"
