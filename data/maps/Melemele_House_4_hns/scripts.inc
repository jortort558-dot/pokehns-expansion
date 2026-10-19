Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "¡Estamos de vacaciones en las ISLAS ALOLA!\p"
	.string "¡Es igual que la región de ALOLA,\n"
	.string "pero al lado de KANTO!\p"
	.string "¡Menudo dineral me he ahorrado en billetes!$"

Melemele_House4_Woman_Text_0:
	.string "Mi novio me prometió que iríamos a\n"
	.string "ALOLA…\p"
	.string "Yo creía que se refería a la región,\n"
	.string "¡no a unos islotes frente a la costa\l"
	.string "de KANTO!$"
