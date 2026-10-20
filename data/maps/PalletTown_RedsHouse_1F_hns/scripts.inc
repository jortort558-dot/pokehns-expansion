PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "¡Hola!\p"
	.string "ROJO lleva mucho tiempo fuera.\p"
	.string "Tampoco ha llamado, así que no sé\n"
	.string "dónde está ni qué estará haciendo.\p"
	.string "Dicen que no tener noticias son\n"
	.string "buenas noticias, pero me preocupa.$"

RedsHouse_Text_Mom2:
	.string "Me preocupa que ROJO se haga daño o\n"
	.string "enferme, pero ya es mayor.\p"
	.string "Me enorgullece que haga lo que\n"
	.string "desea.$"

RedsHouse_Text_TV:
	.string "Emiten programas que no se ven\n"
	.string "en JOHTO…$"
