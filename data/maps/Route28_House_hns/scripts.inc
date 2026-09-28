Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Vaya, me has encontrado.\p"
	.string "Por favor, no se lo digas a nadie.\p"
	.string "Te daré esto por guardar mi\n"
	.string "secreto. ¿De acuerdo?$"

Route28House_Text_Celebrity2:
	.string "Es duro ser una gran celebridad.\p"
	.string "Vaya donde vaya, me persiguen.\p"
	.string "Solo quiero que me dejen en paz…$"

Route28House_Text_Fearow:
	.string "FEAROW: ¡Fiiiro!$"
