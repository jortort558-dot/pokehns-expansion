GoldenrodCity_FlowerShop_hns_MapScripts::
	.byte 0


GoldenrodCity_FlowerShop_EventScript_MintClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodCity_FlowerShop_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_MintClerkNotReady::
	msgbox GoldenrodCity_FlowerShop_Text_MintClerkNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_MintClerkNotReady:
	.string "Nos hemos quedado sin existencias.\p"
	.string "Por favor, vuelve más tarde.$"

	.align 2
GoldenrodCity_FlowerShop_Mints:
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	pokemartlistend


GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "Le hablé a mi hermana del árbol que\nse\l"
	.string "menea y dice que es peligrosísimo.\p"
	.string "Si venzo a BLANCA, ¿me prestará su\n"
	.string "regadera para investigar…?$"

GoldenrodCity_FlowerShop_Text_Owner1:
.string "Por lo visto hay un árbol rarísimo\n"
.string "en la RUTA 36.\p"
.string "Cuentan que se pone a bailar cuando\n"
.string "lo riegas…\p"
.string "¡Ay, claro que no!\p"
.string "Esto es una floristería, tenemos\n"
.string "regaderas de sobra…\p"
.string "¡Pero no puedo darte una a la\nligera!\l"
.string "¡Es demasiado arriesgado!\p"
.string "Bueno, si logras vencer a la líder\n"
.string "BLANCA en el gimnasio, me lo\lpensaré.$"

GoldenrodCity_FlowerShop_Text_Owner2:
.string "Por lo visto hay un árbol rarísimo\n"
.string "en la RUTA 36.\p"
.string "Cuentan que se pone a bailar cuando\n"
.string "lo riegas…\p"
.string "¡Hala! ¡Si es la MEDALLA PLANICIE\n"
.string "del GIMNASIO de TRIGAL!\p"
.string "¿Has derrotado a BLANCA?\p"
.string "Bueno, entonces sabrás defenderte\nde\l"
.string "sobra, ¿verdad?\p"
.string "Toma esta REGADERA.\n"
.string "…\p"
.string "¡Bah, quédatela para tu viaje!$"

GoldenrodCity_FlowerShop_Text_Owner3:
.string "Ese árbol extraño está en la RUTA\n36.\l"
.string "¡Ten mucho cuidado!$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "Lalalá lalalá… ¡Bébete toda el\nagüita,\l"
    .string "preciosa mía!$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "¡Hala! ¿Has ganado a BLANCA? ¡Qué\npasada!$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "¡Así que de verdad era un POKéMON!$"


GoldenrodCity_FlowerShop_EventScript_RandomBerryGirl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS, GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY_HNS
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_FlowerShop_EventScript_AlreadyReceivedBerry::
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
	release
	end
