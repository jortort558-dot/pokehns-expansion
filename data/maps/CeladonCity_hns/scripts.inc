CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
	.string "Oh, {PLAYER}.\n"
	.string "¿No está preciosa la fuente?\p"
	.string "Si quieres volver a combatir,\n"
	.string "estaré en el DOJO KARATE.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "Este POLIWRATH es mi compañero.\p"
	.string "Me pregunto si algún día\n"
	.string "evolucionará en un POKéMON rana.$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: ¡Polii!$"

CeladonCity_Text_Teacher1:
	.string "He vuelto a perder jugando…\p"
	.string "Ahora las chicas también jugamos.\p"
	.string "Deberías probar tú también.$"

CeladonCity_Text_Gramps1:
	.string "Últimamente aparecen GRIMER.\p"
	.string "¿Ves el estanque que hay delante\n"
	.string "de esa casa? Ahora viven allí.\p"
	.string "¿De dónde habrán salido? Esto es\n"
	.string "un problema grave…$"

CeladonCity_Text_Gramps2:
	.string "¡Je, je, je! ¡Este GIMNASIO es\n"
	.string "genial! ¡Solo admiten chicas!$"

CeladonCity_Text_Youngster1:
	.string "¿Quieres saber un secreto?\p"
	.string "La MANSIÓN AZULONA tiene una\n"
	.string "puerta trasera oculta.$"

CeladonCity_Text_Youngster2:
	.string "En el restaurante celebran un\n"
	.string "concurso de tragones.\p"
	.string "Solo de verlos comer ya me siento\n"
	.string "empachado…$"

CeladonCity_Text_Teacher2:
	.string "El CENTRO COMERCIAL de AZULONA\n"
	.string "ofrece la mejor selección.\p"
	.string "Si no lo tienen allí, no lo\n"
	.string "encontrarás en ninguna parte.\p"
	.string "Vaya… Parezco una dependienta.$"
CeladonCity_Text_Lass:
	.string "Mirar al suelo mientras caminaba\n"
	.string "me ha mareado.$"
CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CIUDAD AZULONA\p"
	.string "La ciudad de los sueños arcoíris$"
CeladonGym_Text_Sign:
	.string "GIMNASIO POKéMON DE AZULONA\p"
	.string "LÍDER: ERIKA\p"
	.string "La princesa amante de la naturaleza$"
CeladonCity_Text_DeptStoreSign:
	.string "¡Todo lo que buscas en el CENTRO\n"
	.string "COMERCIAL DE AZULONA!$"
CeladonCity_Text_MansionSign:
	.string "MANSIÓN AZULONA$"
CeladonCity_Text_GameCornerSign:
	.string "Diversión para todo el mundo:\n"
	.string "CASINO DE CIUDAD AZULONA$"

CeladonCity_Text_TrainerTips:
	.string "CONSEJOS PARA ENTRENADORES\p"
	.string "PROTEC. ESPECIAL protege a los\n"
	.string "POKéMON de ataques especiales\l"
	.string "como los de fuego y agua.\p"
	.string "¡Compra tus objetos en el CENTRO\n"
	.string "COMERCIAL DE AZULONA!$"
