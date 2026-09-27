PalletTown_RedsHouse_2F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} jugó a la NES.\p"
	.string "¡Hay que irse, no hay tiempo!$"

RedsHouse_Text_PC:
	.string "Parece que no se ha usado desde\n"
	.string "hace mucho tiempo…$"
