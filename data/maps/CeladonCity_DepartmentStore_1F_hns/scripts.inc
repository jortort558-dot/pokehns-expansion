CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
	.string "¡Hola! ¡Bienvenido al CENTRO\n"
	.string "COMERCIAL DE CIUDAD AZULONA!\p"
	.string "El directorio está en la pared.$"

CeladonDeptStore_Text_1FGentleman:
	.string "Este CENTRO COMERCIAL pertenece a\n"
	.string "la misma cadena que el de TRIGAL.\p"
	.string "Los renovaron al mismo tiempo.$"

CeladonDeptStore_Text_1FTeacher:
	.string "Es la primera vez que vengo.\p"
	.string "Es muy grande…\p"
	.string "Me preocupa acabar perdiéndome.$"

CeladonDeptStore_Text_1FDirectory:
	.string "PB: INFORMACIÓN\p"
	.string "P1: MERCADO PARA ENTRENADORES\p"
	.string "P2: TIENDA DE MT\p"
	.string "P3: REGALOS\p"
	.string "P4: FARMACIA\p"
	.string "P5: AZOTEA$"
