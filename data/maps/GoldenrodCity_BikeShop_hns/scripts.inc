GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Montar en BICI es tan fácil como\n"
	.string "pulsar un botón si la ASIGNAS\l"
	.string "desde tu MOCHILA.\p"
	.string "¡Y si quieres ir a toda pastilla,\n"
	.string "primero tienes que frenar del todo!\p"
	.string "Suena raro, pero solo puedes\ncambiar\l"
	.string "de marcha con la BICI parada.\p"
	.string "Pulsa el botón R estando quieto\n"
	.string "y en cuanto pedalees saldrás\l"
	.string "zumbando a máxima velocidad.$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "…Suspiro… Me mudé aquí, pero no\nvendo\l"
    .string "ni una sola BICICLETA. ¿Por qué?\p"
    .string "¿Podrías montar en una BICI para\n"
    .string "hacerme algo de publicidad?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "¡¿En serio?! ¡De lujo!\p"
    .string "Dame tu nombre y tu número, y te\n"
    .string "presto una flamante BICICLETA.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} tomó prestada una BICI.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Nos cuesta arrancar desde que nos\n"
	.string "mudamos desde KANTO.\l"
	.string "¡Agradecemos un montón tu ayuda!\p"
	.string "Presume todo lo que puedas de\nnuestro\l"
	.string "sistema patentado de marchas.\p"
	.string "Basta con pulsar R mientras estás\n"
	.string "parado en la BICI.\p"
	.string "¡Ojo, que vas a volar sobre ruedas!$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "…Suspiro… Con lo generosa que suele\n"
    .string "ser la gente…$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "¡Novedad absoluta!\p"
    .string "¡BICICLETAS compactas de primera!$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "¡Es una flamante BICI reluciente!$"
