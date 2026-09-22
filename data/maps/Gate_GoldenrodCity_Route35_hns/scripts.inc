Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "¡Oye, peque! ¿Me harías un\nfavorcillo?\p"
	.string "¿Podrías llevar este POKéMON con\nuna\l"
	.string "CARTA para mi amigo?\p"
	.string "Está en la RUTA 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "¡¿De verdad?! ¡Mil gracias!\p"
	.string "Mi colega es un tipo regordete que\n"
	.string "se pasa el día roncando bajo un\lárbol.\p"
	.string "¡Lo vas a calar enseguida!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "¡{PLAYER} recibió un POKéMON\n"
	.string "con una CARTA!$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "¡Ponlo el primero del equipo cuando\n"
	.string "hables con mi amigo en la RUTA 31!\p"
	.string "Por cierto, había un árbol rarísimo\n"
	.string "bloqueando el paso en el cruce.\p"
	.string "¿Lo habrán quitado ya?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "No tienes hueco para más POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Bueno… No pasa nada entonces…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "¡Muchísimas gracias por llevar el\n"
	.string "encargo hasta allí!\p"
	.string "¡Toma esto por las molestias!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Mi colega estaba sobando, ¿a que\nsí?\l"
	.string "¡Te lo dije!$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Hay un árbol rarísimo tapando la\nvía.\p"
	.string "Se menea solo cuando te acercas.\p"
	.string "Dicen que se puso furioso cuando\n"
	.string "alguien le echó agua con una\l"
	.string "REGADERA.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "Me encanta la nana POKéMON que\nemiten\l"
	.string "por la radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Me pregunto cuántas especies de\n"
	.string "POKéMON habrá en el mundo.\p"
	.string "Hace tres años, el PROF. OAK decía\n"
	.string "que eran unas 150 distintas.\p"
	.string "¡Pero he oído que ya se conocen más\n"
	.string "de 400!$"
