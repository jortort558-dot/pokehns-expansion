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
	.string "Este POLIWRATH es\n"
	.string "mi compañero.\p"
	.string "Me pregunto si\n"
	.string "algún día\p"
	.string "evolucionará en\n"
	.string "una rana POKéMON.$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: ¡Polii!$"

CeladonCity_Text_Teacher1:
	.string "He vuelto a perder jugando…\p"
	.string "Ahora las chicas también jugamos.\p"
	.string "Deberías probar tú también.$"

CeladonCity_Text_Gramps1:
	.string "Últimamente han\n"
	.string "aparecido GRIMER.\p"
	.string "¿Ves esa charca\n"
	.string "que hay delante de\p"
	.string "la casa? Ahí viven\n"
	.string "GRIMER.\p"
	.string "¿De dónde han\n"
	.string "venido? Es un\l"
	.string "grave problema…$"

CeladonCity_Text_Gramps2:
	.string "¡Bravo! ¡Este\n"
	.string "GIMNASIO es\p"
	.string "genial! ¡Es sólo\n"
	.string "para chicas!$"

CeladonCity_Text_Youngster1:
	.string "¿Te cuento un\n"
	.string "secreto?\p"
	.string "La MANSIÓN AZULONA\n"
	.string "tiene una puerta\l"
	.string "trasera secreta.$"

CeladonCity_Text_Youngster2:
	.string "Hay un concurso\n"
	.string "de tragones en el\l"
	.string "restaurante.\p"
	.string "Sólo verlo hace\n"
	.string "que me sienta\l"
	.string "lleno…$"

CeladonCity_Text_Teacher2:
	.string "El C. COMERCIAL\n"
	.string "de CIUDAD AZULONA\p"
	.string "dispone de los\n"
	.string "mejores artículos.\p"
	.string "Si no encuentras\n"
	.string "algo aquí, no lo\p"
	.string "encontrarás en\n"
	.string "ningún otro sitio.\p"
	.string "¡Vaya…! Parezco\n"
	.string "una vendedora.$"
CeladonCity_Text_Lass:
	.string "Mirar al suelo\n"
	.string "mientras camino\l"
	.string "me marea.$"
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
	.string "La ciudad de los\n"
	.string "sueños de arco\l"
	.string "iris$"
CeladonGym_Text_Sign:
	.string "LÍDER DEL GIMNASIO\n"
	.string "POKéMON DE CIUDAD\l"
	.string "AZULONA: ERIKA\p"
	.string "La princesa amante\n"
	.string "de la naturaleza$"
CeladonCity_Text_DeptStoreSign:
	.string "¡Encuentra lo que\n"
	.string "necesitas en el\p"
	.string "CENTRO COMERCIAL\n"
	.string "de CIUDAD AZULONA!$"
CeladonCity_Text_MansionSign:
	.string "MANSIÓN AZULONA$"
CeladonCity_Text_GameCornerSign:
	.string "Diversión para todo el mundo:\n"
	.string "CASINO DE CIUDAD AZULONA$"

CeladonCity_Text_TrainerTips:
	.string "CONSEJOS PARA ENTRENADORES\p"
	.string "PROTEC. ESPECIAL protege frente\n"
	.string "a ataques especiales como\l"
	.string "LANZALLAMAS y SURF.\p"
	.string "¡Compra en el C. COMERCIAL de\n"
	.string "CIUDAD AZULONA!$"
