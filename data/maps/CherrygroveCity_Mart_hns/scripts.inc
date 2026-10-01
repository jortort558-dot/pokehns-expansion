CherrygroveCity_Mart_hns_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, Cherrygrove_Pokemart_EventScript_ElPiedrasOffer
Cherrygrove_Pokemart_EventScript_OpenRegularShop::
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, Cherrygrove_Pokemart_EventScript_ElPiedrasOffer
Cherrygrove_Pokemart_EventScript_OpenRegularShop2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_ElPiedrasOffer::
	msgbox Cherrygrove_Pokemart_Text_ElPiedrasOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Cherrygrove_Pokemart_EventScript_OpenRegularShopByProgress
	msgbox Cherrygrove_Pokemart_Text_ElPiedrasIntro, MSGBOX_DEFAULT
	special CreateElPiedrasMegaShop
	waitstate
	msgbox Cherrygrove_Pokemart_Text_ElPiedrasFarewell, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_OpenRegularShopByProgress::
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_OpenRegularShop2
	goto Cherrygrove_Pokemart_EventScript_OpenRegularShop

Cherrygrove_Pokemart_Text_ElPiedrasOffer:
	.string "EL PIEDRAS ha alquilado un rincón\n"
	.string "para sus negocios. ¿Quieres verlo?$"

Cherrygrove_Pokemart_Text_ElPiedrasIntro:
	.string "¡Socio! Mi franquicia ya está en\n"
	.string "todas las tiendas importantes.\p"
	.string "El catálogo cambia cada día.\n"
	.string "Compra antes de que suba el FOMO.$"

Cherrygrove_Pokemart_Text_ElPiedrasFarewell:
	.string "Vuelve mañana: nueva rotación,\n"
	.string "nuevas oportunidades de mercado.$"

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
	.string "¡Se han quedado sin POKé BALLS!\p"
	.string "¿Cuándo les llegará otra remesa?$"

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
	.string "¡Ya tienen POKé BALLS!\n"
	.string "¡Por fin podré atrapar POKéMON!$"

Cherrygrove_Pokemart_Text_Youngster:
	.string "Paseando por la hierba, ¡un POKéMON\nbicho\l"
	.string "envenenó al mío!\p"
	.string "Seguí caminando como si nada y mi\nPOKéMON\l"
	.string "se debilitó.\p"
	.string "Deberías llevar siempre un ANTÍDOTO\n"
	.string "encima.$"
