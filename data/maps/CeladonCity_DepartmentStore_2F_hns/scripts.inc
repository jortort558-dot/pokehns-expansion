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
	.string "Hace poco que soy\n"
	.string "entrenador. Mi\p"
	.string "hijo me animó a\n"
	.string "serlo.\p"
	.string "Estoy impresionado\n"
	.string "por la cantidad de\p"
	.string "objetos útiles\n"
	.string "que hay.$"

CeladonDeptStore2F_Text_Youngster:
	.string "A mi padre le está\n"
	.string "costando aprender\p"
	.string "los nombres de los\n"
	.string "objetos y cómo se\p"
	.string "supone que debe\n"
	.string "utilizarlos…$"

CeladonDeptStore2F_Text_Directory:
	.string "¡Objetos de máxima\n"
	.string "calidad para\l"
	.string "entrenadores!\p"
	.string "P1: TIENDA DE\n"
	.string "    ENTRENADORES$"
