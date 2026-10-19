Melemele_House_6_hns_MapScripts::
	.byte 0


Melemele_House6_Hiker::
	lock
	faceplayer
	msgbox Melemele_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_GameboyKid::
	lock
	faceplayer
	msgbox Melemele_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_Hiker_Text_0:
	.string "Compré esta casa para que mi hijo\n"
	.string "y yo disfrutáramos del aire libre…\p"
	.string "¡Pero no suelta esa Game Boy\n"
	.string "Advance ni para comer!$"

Melemele_House6_GameboyKid_Text_0:
	.string "¡Tengo un juego en mi Game Boy\n"
	.string "Advance para explorar ALOLA!\p"
	.string "Es clavadito a la realidad.\p"
	.string "¡Se llama ULTRA ECLIPSE,\n"
	.string "creado por PHANTONOMY!\p"
	.string "¡Mira, mira!\n"
	.string "¡Voy montado en un NOIVERN gélido!$"
