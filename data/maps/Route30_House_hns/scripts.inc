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
	.string "Si sigues ese camino hacia el\nnorte, verás\l"
	.string "la casa del SR. POKéMON.\p"
	.string "Pero antes de que vayas, ¡déjame\nque te\l"
	.string "hable sobre las BAYAS!\p"
	.string "Los POKéMON recuperan salud\ncomiendo BAYAS.\p"
	.string "Incluso pueden comerse la BAYA que\nlleven\l"
	.string "equipada en pleno combate.\p"
	.string "Además, CÉSAR de PUEBLO AZALEA\npuede\l"
	.string "transformar las BAYAS en BALLS.\p"
	.string "¡Toma, te regalo una para que la\npruebes!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Mira bien en los árboles para\nencontrar\l"
	.string "BAYAS. Vuelven a crecer pasadas\nunas horas.$"
