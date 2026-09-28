CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Vengo a comprar CORREO SURF\n"
	.string "para mi novia.\p"
	.string "¿Cómo? ¿Se ha agotado?$"

CeladonDeptStore4F_Text_Youngster:
	.string "Este era el único sitio donde\n"
	.string "vendían CORREO BELLO.\p"
	.string "Pero dicen que se ha agotado.$"

CeladonDeptStore4F_Text_Directory:
	.string "¡Dilo con un\n"
	.string "regalo!\p"
	.string "P3: REGALOS$"
