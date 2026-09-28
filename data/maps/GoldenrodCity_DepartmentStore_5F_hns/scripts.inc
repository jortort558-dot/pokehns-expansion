GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_5F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_5F_OnTransition:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodDeptStore5_ShowElPiedras
	setflag FLAG_HIDE_MEGA_SHOP_EL_PIEDRAS
	end

GoldenrodDeptStore5_ShowElPiedras:
	clearflag FLAG_HIDE_MEGA_SHOP_EL_PIEDRAS
	end


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Hola. Vaya, tu POKéMON…$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "¡Espera, ya te di esa MT!$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Mmm…\n"
	.string "No está mal, pero tampoco bien.\p"
	.string "Como ENTRENADOR, debes esforzarte\n"
	.string "un poco más.$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "Te tiene mucho cariño.\p"
    .string "Este movimiento os vendrá genial.$"

GoldenrodDeptStore_Text_5FLass:
    .string "De día viene una mujer a observar\n"
    .string "a los POKéMON.\p"
    .string "¡Hasta regala MT!$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "No puedes cambiar el mote de un\n"
    .string "POKéMON recibido por intercambio.\p"
    .string "Su nombre refleja los sentimientos\n"
    .string "de su ENTRENADOR original.$"

GoldenrodDeptStore_Text_Girl:
	.string "¡La mujer me ha dado RETRIBUCIÓN!\n"
    .string "¡Mi POKéMON debe quererme mucho!$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
    .string "PERSONALIZA A TUS POKéMON\p"
    .string "5.ª PLANTA: RINCÓN DE MT$"

GoldenrodDeptStore5_EventScript_ElPiedras::
	lock
	faceplayer
	msgbox Mart_Text_ElPiedrasInStore, MSGBOX_DEFAULT
	special CreateElPiedrasMegaShop
	waitstate
	msgbox Mart_Text_ElPiedrasFarewell, MSGBOX_DEFAULT
	release
	end

Mart_Text_ElPiedrasInStore:
	.string "¡Pasa, pasa, socio! ¿Has visto al\n"
	.string "pobre dependiente de abajo?\l"
	.string "Vendiendo Pociones por calderilla\l"
	.string "como un asalariado del PNJ...\p"
	.string "Aquí el que maneja el cotarro soy\n"
	.string "yo. Traigo MEGAPIEDRAS exclusivas\l"
	.string "de contrabando directo.\p"
	.string "A 50.000 monedas cada una.\n"
	.string "El verdadero meta se paga caro.\p"
	.string "¿Te sobra el dinero o vas a seguir\n"
	.string "pegando sin transformar como si\l"
	.string "esto fuera primera generación?$"

Mart_Text_ElPiedrasFarewell:
	.string "Si no compras hoy, entra el FOMO.\n"
	.string "Chispa y yo estaremos reinvirtiendo\l"
	.string "las ganancias en el mercado.$"
