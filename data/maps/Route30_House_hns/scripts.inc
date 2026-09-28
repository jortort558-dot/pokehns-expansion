Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Siguiendo el camino al norte,\n"
	.string "verás la casa del SR. POKéMON.\p"
	.string "Pero antes déjame hablarte\n"
	.string "de las BAYAS.\p"
	.string "Los POKéMON recuperan salud\n"
	.string "cuando comen BAYAS.\p"
	.string "También pueden comer las que\n"
	.string "lleven durante el combate.\p"
	.string "CÉSAR fabrica BALLS con BAYAS\n"
	.string "en PUEBLO AZALEA.\p"
	.string "¡Toma, te regalo una!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Busca BAYAS en los árboles.\n"
	.string "Vuelven a crecer en unas horas.$"
