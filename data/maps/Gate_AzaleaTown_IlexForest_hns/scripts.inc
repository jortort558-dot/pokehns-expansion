Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "El ENCINAR es inmenso.\n"
	.string "¡Ten mucho cuidado!\l"
	.string "No vayas a perderte.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "El ENCINAR está custodiado por\n"
	.string "el espíritu de su protector.\p"
	.string "¡Ni se te ocurra hacer trastadas!$"
