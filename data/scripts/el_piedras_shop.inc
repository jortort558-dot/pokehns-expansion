Common_EventScript_ElPiedrasMart::
	lock
	faceplayer
	msgbox Common_Text_ElPiedrasMartIntro, MSGBOX_DEFAULT
	special CreateElPiedrasMegaShop
	waitstate
	msgbox Common_Text_ElPiedrasMartFarewell, MSGBOX_DEFAULT
	release
	end

Common_Text_ElPiedrasMartIntro:
	.string "¡Socio! Mi franquicia ya está en\n"
	.string "todas las tiendas importantes.\p"
	.string "El catálogo cambia cada día.\n"
	.string "Compra antes de que suba el FOMO.$"

Common_Text_ElPiedrasMartFarewell:
	.string "Vuelve mañana: nueva rotación,\n"
	.string "nuevas oportunidades de mercado.$"
