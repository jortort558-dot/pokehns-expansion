OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "¡CIUDAD OLIVO está frente al mar!\pY si hay mar, ¡por narices tiene\nque\lhaber pesca a rabiar!\pLlevo pescando aquí 30 años.\p¿Te gustaría plantarle cara al mar\ny probar suerte con la pesca?$"
OlivineCity_Text_GiveGoodRod:
	.string "¡Ja, jaja! ¡Tenemos a un nuevo\npescador\len ciernes!$"
OlivineCity_Text_GaveGoodRod:
	.string "Los peces no solo viven en el mar:\nestán en cualquier lugar donde haya\lagua.\pPor cierto, tu POKéDEX indica los\ntipos\lde pesca para cada POKéMON.\pEn distintas zonas puedes encontrar\npeces similares.$"
OlivineCity_Text_DontWantGoodRod:
	.string "¿Cooómo? ¿Que no te gusta pescar?\n¡Eso no entra en cabeza humana!$"
OlivineCity_Text_HaveGoodRod:
	.string "¿Cómo va la cosa?\n¿Has pescado ya alguna pieza gorda?$"
