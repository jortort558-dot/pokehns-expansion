CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "Tus POKéMON parecen estar\nrebosantes\lde salud.\p¿Te preocupa algo?\p…\p¿Que el POKéMON del FARO está muy\nenfermo?\p¡Entendido!\pEsto debería bastar para devolverle\nla\lsalud.$"
CianwoodCity_Text_ReceivedSecretpotion:
	.string "¡{PLAYER} recibió la\nPOCIÓN SECRETA!$"
CianwoodCity_Text_PharmacistDescribePotion:
	.string "Mi POCIÓN SECRETA es un poco fuerte\nde\lmás, así que solo la entrego en\lcasos de\lurgencia.$"
