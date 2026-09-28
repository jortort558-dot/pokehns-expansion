GoldenrodCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore2_EventScript_Youngster::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FGentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_2FYoungster:
    .string "El POKéGEAR guarda hasta 100\n"
    .string "números de teléfono.\p"
    .string "Cuesta decidir cuáles conservar.$"

GoldenrodDeptStore_Text_2FCooltrainerF:
    .string "Conseguí mi ABRA en el CASINO.\p"
    .string "Ahora es mi mejor compañero.$"

GoldenrodDeptStore_Text_2FGentleman:
    .string "Estos GRANDES ALMACENES demuestran\n"
    .string "que TRIGAL es una gran ciudad.\p"
    .string "No hay otro surtido como este.$"

GoldenrodDeptStore2_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore2_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore2_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

GoldenrodDeptStore_EventScript_VendingMachine::
	lockall
	message GoldenrodDeptStore_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto GoldenrodDeptStore_EventScript_ChooseDrink
	end

GoldenrodDeptStore_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, GoldenrodDeptStore_EventScript_FreshWater
	case 1, GoldenrodDeptStore_EventScript_SodaPop
	case 2, GoldenrodDeptStore_EventScript_Lemonade
	msgbox GoldenrodDeptStore_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto GoldenrodDeptStore_EventScript_ExitVendingMachine
	end

GoldenrodDeptStore_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto GoldenrodDeptStore_EventScript_TryBuyDrink
	end

GoldenrodDeptStore_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto GoldenrodDeptStore_EventScript_TryBuyDrink
	end

GoldenrodDeptStore_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto GoldenrodDeptStore_EventScript_TryBuyDrink
	end

GoldenrodDeptStore_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

GoldenrodDeptStore_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

GoldenrodDeptStore_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

GoldenrodDeptStore_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

GoldenrodDeptStore_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

GoldenrodDeptStore_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

GoldenrodDeptStore_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, GoldenrodDeptStore_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, GoldenrodDeptStore_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, GoldenrodDeptStore_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, GoldenrodDeptStore_EventScript_NotEnoughMoney
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodDeptStore_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, GoldenrodDeptStore_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, GoldenrodDeptStore_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, GoldenrodDeptStore_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox GoldenrodDeptStore_Text_DrinkClankedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_MEDICINE
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	goto_if_ne VAR_RESULT, 0, GoldenrodDeptStore_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodDeptStore_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox GoldenrodDeptStore_Text_ExtraDrinkClankedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_MEDICINE
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	goto_if_ne VAR_RESULT, 0, GoldenrodDeptStore_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, GoldenrodDeptStore_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox GoldenrodDeptStore_Text_ExtraDrinkClankedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_MEDICINE
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto GoldenrodDeptStore_EventScript_ChooseNewDrink
	end

GoldenrodDeptStore_EventScript_ChooseNewDrink::
	message GoldenrodDeptStore_Text_WhichDrinkWouldYouLike
	waitmessage
	goto GoldenrodDeptStore_EventScript_ChooseDrink
	end

GoldenrodDeptStore_EventScript_NotEnoughMoney::
	msgbox GoldenrodDeptStore_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto GoldenrodDeptStore_EventScript_ExitVendingMachine
	end

GoldenrodDeptStore_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto GoldenrodDeptStore_EventScript_ExitVendingMachine
	end

GoldenrodDeptStore_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

GoldenrodDeptStore_Text_WhichDrinkWouldYouLike:
	.string "Es una MÁQUINA EXPENDEDORA.\n"
	.string "¿Qué bebida quieres?$"

GoldenrodDeptStore_Text_DrinkClankedDown:
	.string "¡Clonc!\p"
	.string "Ha caído una lata de {STR_VAR_1}.$"

GoldenrodDeptStore_Text_ExtraDrinkClankedDown:
	.string "¡Clonc!\p"
	.string "¡Premio! ¡Ha caído otra lata\n"
	.string "de {STR_VAR_1}!$"

GoldenrodDeptStore_Text_NotEnoughMoney:
	.string "No tienes suficiente dinero…$"

GoldenrodDeptStore_Text_DecidedAgainstBuyingDrink:
	.string "Has decidido no comprar nada.$"

GoldenrodDeptStore_Text_2FDirectory:
    .string "TU COMPAÑERO DE VIAJE\p"
    .string "2.ª PLANTA: MERCADO ENTRENADOR$"

GoldenrodDeptStore2_EventScript_ElPiedras::
	lock
	faceplayer
	setflag FLAG_HIDE_VIOLET_SCHOOL_EL_PIEDRAS
	goto_if_set FLAG_DEFEATED_EL_PIEDRAS_GOLDENROD, GoldenrodDeptStore2_EventScript_ElPiedrasAfter
	goto_if_set FLAG_BOUGHT_USELESS_STONE, GoldenrodDeptStore2_EventScript_ElPiedrasAlreadyBought
	showmoneybox 0, 0
	msgbox GoldenrodCity_Text_ElPiedrasPitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodDeptStore2_EventScript_ElPiedrasDeclined
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, GoldenrodDeptStore2_EventScript_ElPiedrasNoMoney
	removemoney 10000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	giveitem ITEM_USELESS_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_BOUGHT_USELESS_STONE
	msgbox GoldenrodCity_Text_ElPiedrasBoughtStone, MSGBOX_DEFAULT
	goto GoldenrodDeptStore2_EventScript_ElPiedrasStartBattle

GoldenrodDeptStore2_EventScript_ElPiedrasNoMoney::
	hidemoneybox
	msgbox GoldenrodCity_Text_ElPiedrasNoMoney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_ElPiedrasDeclined::
	hidemoneybox
	goto GoldenrodDeptStore2_EventScript_ElPiedrasStartBattle

GoldenrodDeptStore2_EventScript_ElPiedrasAlreadyBought::
	goto GoldenrodDeptStore2_EventScript_ElPiedrasStartBattle

GoldenrodDeptStore2_EventScript_ElPiedrasStartBattle::
	msgbox GoldenrodCity_Text_ElPiedrasPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EL_PIEDRAS_HNS, GoldenrodCity_Text_ElPiedrasDefeat
	setflag FLAG_DEFEATED_EL_PIEDRAS_GOLDENROD
	msgbox GoldenrodCity_Text_ElPiedrasPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_EL_PIEDRAS
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_BLACK
	release
	end

GoldenrodDeptStore2_EventScript_ElPiedrasAfter::
	msgbox GoldenrodCity_Text_ElPiedrasPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_ElPiedrasPitch:
	.string "¡Eeeeh, tú, el del chándal!\n"
	.string "Te veo cara de querer progresar.\p"
	.string "Mira lo que tengo aquí recién\n"
	.string "sacado de la mina. No mires al\l"
	.string "tendero, ese estafador te clava\l"
	.string "tres mil monedas por una piedra que\l"
	.string "encima caduca si la miras mal.\p"
	.string "Yo te ofrezco esta PIEDRA INÚTIL.\n"
	.string "Nombre técnico registrado por mí.\p"
	.string "Efecto top: si tu Pokémon la lleva,\n"
	.string "sus ataques jamás matarán al rival.\l"
	.string "¡Ideal para rushear capturas en tu\l"
	.string "run sin trolear!\p"
	.string "Solo te pido una inversión\n"
	.string "simbólica de 10.000 monedas.\p"
	.string "¿Entras al negocio o prefieres ser\n"
	.string "un NPC el resto de tu aventura?$"

GoldenrodCity_Text_ElPiedrasNoMoney:
	.string "Pero bro... Si no llevas ni diez\n"
	.string "mil monedas encima. Así no se hace\l"
	.string "networking. Vuelve con cash.$"

GoldenrodCity_Text_ElPiedrasBoughtStone:
	.string "¡Trato cerrado! ¡Toma tu piedra!\n"
	.string "¡Eres oficialmente accionista de mi\l"
	.string "holding empresarial!$"

GoldenrodCity_Text_ElPiedrasPreBattle:
	.string "Y ahora que cerramos el trato,\n"
	.string "¡toca el control de calidad!\p"
	.string "¡Chispa, sal ahí y demuéstrale lo\n"
	.string "que vale una Meowth con mentalidad\l"
	.string "de tiburón financiero!$"

GoldenrodCity_Text_ElPiedrasDefeat:
	.string "¡¿Qué?! ¡Vaya desbalanceo!\n"
	.string "¡Tenía el joystick con drift!$"

GoldenrodCity_Text_ElPiedrasPostBattle:
	.string "Nada, una mala partida la tiene\n"
	.string "cualquiera. Me voy a casa de un\l"
	.string "colega a vaciarle la nevera y a\l"
	.string "jugar al LoL hasta las tantas.\l"
	.string "¡Volverás a oír de mis proyectos!$"
