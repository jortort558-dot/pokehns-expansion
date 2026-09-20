GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "¡Te damos la bienvenida al CENTRO\n"
    .string "COMERCIAL DE CIUDAD TRIGAL!$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "El CENTRO COMERCIAL tiene un\nsurtido\l"
    .string "impresionante.\p"
    .string "Aunque algunos objetos exclusivos\nsolo\l"
    .string "se consiguen de premio en el\nCASINO.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "¡Hoy me he levantado con unas ganas\n"
    .string "locas de gastar dinero!$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "A mi madre se le da de perlas cazar\n"
    .string "gangas. ¡Siempre compra al mejor\l"
    .string "precio!$"

GoldenrodDeptStore1_Text_Directory:
    .string "PB MOSTRADOR DE INFORMACIÓN\n"
	.string "USTED ESTÁ AQUÍ.\p"
    .string "1P BAZAR DEL ENTRENADOR\p"
    .string "2P COLECCIÓN DE COMBATE\p"
    .string "3P FARMACIA POKéMON\p"
    .string "4P RINCÓN DE MTs\p"
    .string "5P PLAZA TRANQUILA\p"
    .string "AZOTEA Y MIRADOR$"
