CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Hace poco que soy entrenador.\p"
	.string "Mi hijo me animó a empezar.\p"
	.string "Me impresiona la variedad de\n"
	.string "objetos útiles que tienen.$"

CeladonDeptStore2F_Text_Youngster:
	.string "A mi padre le cuesta aprender los\n"
	.string "nombres de los objetos y para qué\l"
	.string "sirve cada uno…$"

CeladonDeptStore2F_Text_Directory:
	.string "¡Objetos de primera calidad para\n"
	.string "entrenadores!\p"
	.string "P1: MERCADO PARA ENTRENADORES$"
