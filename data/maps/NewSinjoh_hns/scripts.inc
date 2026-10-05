NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "Será mejor no hacer esperar a las\n"
	.string "chicas Kimono.$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
    .string "¡Lerrrrr!$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "MÁXIMO: Señora, ¿puedo ayudarla a\n"
	.string "llegar a las termas de allí?\p"
	.string "Parece que hay bastante sitio.$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "Soy el Lechero.\p"
	.string "Mi leche es deliciosa.\p"
	.string "Si quieres una botella hoy,\n"
	.string "serán 500¥.$"

NewSinjoh_MilkMan_GotMilk:
	.string "¡Aquí tienes!\n"
	.string "Tiene todo lo que el mundo pide.$"

NewSinjoh_MilkMan_NoMoney:
	.string "Lo siento.\n"
	.string "¡Consigue dinero y hablamos!$"

NewSinjoh_MilkMan_NoRoom:
	.string "Parece que tu MOCHILA está llena.$"

NewSinjoh_MilkMan_NoSale:
	.string "¿No la quieres?\n"
	.string "Tiene todo lo que el mundo merece.$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "¿Qué tal otra botellita?$"

NewSinjoh_Text_GotMilk:
	.string "{PLAYER} obtuvo LECHE MU-MU.$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "Soy el Lechero.\p"
	.string "Mi leche es deliciosa.\p"
	.string "¡Entrega especial hoy!$"

NewSinjoh_MilkMan_text_Lose:
	.string "Este mundo es perfecto,\n"
	.string "¿a que sí?$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE

NewSinjoh_Text_TravelShopGreeting:
	.string "Te doy la bienvenida a mi\n"
	.string "tiendecita de suministros.\p"
	.string "¿En qué te puedo ayudar?$"

NewSinjoh_Text_TravelShopEnd:
	.string "¡Vuelve cuando quieras!$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
    .string "¡Nuestros productos son caseros\n"
	.string "y cultivados por la zona!\p"
	.string "Mi hermana mayor abrió este puesto\n"
	.string "porque la compañía TIENDA POKéMON\l"
	.string "no quiere abrir una sucursal tan\l"
	.string "lejos de las grandes ciudades.$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "¡Este sitio es una pasada!\p"
	.string "Tener ocultas estas termas\n"
	.string "del mundo es casi un crimen.\p"
	.string "¡Pienso decírselo a mis amigos!$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "Estas termas son mágicas,\n"
	.string "pero me da la sensación de que la\l"
	.string "gente de aquí nos mira mal.$"
NewSinjoh_Text_JaniceAfter:
	.string "Estas termas son mágicas,\n"
	.string "¡y los lugareños son muy amables\l"
	.string "en cuanto los vas conociendo!$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "No hay nada como una hermosa vista\n"
	.string "para revivir esta vieja alma.$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "¡Fantástico! ¡Ahora estos turistas\n"
	.string "acaparan nuestras termas!\p"
	.string "¡Últimamente no ganamos para\n"
	.string "disgustos!$"
NewSinjoh_Text_OldLady2Steven:
	.string "¡Qué joven tan apuesto y educado!\p"
	.string "Tal vez estos turistas no sean tan\n"
	.string "malos después de todo.$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "¿Cómo puede esa mujer ser tan\n"
	.string "descortés con nuestras visitas?\p"
	.string "Lo que necesita es darse un baño\n"
	.string "en las aguas calientes.\p"
	.string "¡Hay sitio de sobra para todos!$"
NewSinjoh_Text_OldLady3After:
	.string "Parece que todos nos vamos\n"
	.string "acostumbrando a convivir aquí.\p"
	.string "¡Qué alegría!$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "Ha habido mucha división y tensión\n"
	.string "en el pueblo desde que llegaron\l"
	.string "los recién venidos.\p"
	.string "Se mire como se mire,\n"
	.string "el equilibrio se ha roto.\p"
	.string "Sé amable tanto con los de aquí\n"
	.string "como con los turistas.$"
NewSinjoh_Text_SpringsSageAfter:
	.string "Las cosas marchan mucho mejor tras\n"
	.string "calmar a los POKéMON legendarios.\p"
	.string "El equilibrio ha vuelto a SINJOH.$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "Los tiempos cambian, mas los\n"
	.string "STANTLER siguen congregándose.\p"
	.string "Por eso al menos demos gracias.$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
    .string "¡¡Yuuuuju!!\p"
    .string "¡Mira, mami!\n"
    .string "¡Sin manos!\p"
	.string "¡Igual que los de snowboard!$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
    .string "¡Mira qué arte tiene mi pequeña!\p"
    .string "Esta pista lleva aquí generaciones,\n"
	.string "pero los niños no la usaban hasta\l"
	.string "que llegaron los forasteros.$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "NUEVO SINJOH$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "CAFÉ FAMILIAR$"

NewSinjoh_EventScript_Cave_Sign::
	msgbox NewSinjoh_Text_Cave_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Cave_Sign:
	.string "CUEVA DE LAS TERMAS$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "¡El negocio va viento en popa!\n"
	.string "Aunque los precios han subido desde\l"
	.string "que la gente de ciudad se interesó\l"
	.string "por nuestro pueblecito.$"
NewSinjoh_Text_HikerAfter:
	.string "¡El negocio va que vuela!\p"
	.string "Y con las propinas que deja el tipo\n"
	.string "del pelo plateado, ¡los precios han\l"
	.string "podido bajar!$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "¡Solo vendo a los del pueblo!$"
NewSinjoh_Text_OldLady4After:
	.string "¡AÚN solo vendo a los del pueblo!$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end


