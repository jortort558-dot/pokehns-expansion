Common_EventScript_ElPiedrasMart::
	lock
	faceplayer
	setspeaker SP_NAME_EL_PIEDRAS
	msgbox Common_Text_ElPiedrasMartIntro, MSGBOX_DEFAULT
	special CreateElPiedrasMegaShop
	waitstate
	setspeaker SP_NAME_EL_PIEDRAS
	msgbox Common_Text_ElPiedrasMartFarewell, MSGBOX_DEFAULT
	release
	end

Common_Text_ElPiedrasName:
	.string "EL PIEDRAS$"

Common_Text_ElPiedrasMartIntro:
	.string "¡Socio! Mi franquicia ya está en\n"
	.string "todas las tiendas importantes.\p"
	.string "El catálogo cambia cada día.\n"
	.string "Compra antes de que suba el FOMO.$"

Common_Text_ElPiedrasMartFarewell:
	.string "Vuelve mañana: nueva rotación,\n"
	.string "nuevas oportunidades de mercado.$"

Common_EventScript_ElPiedrasBlackMarket::
	lock
	faceplayer
	setspeaker SP_NAME_EL_PIEDRAS
	msgbox Common_Text_ElPiedrasBlackMarketIntro, MSGBOX_DEFAULT
	special CreateElPiedrasBlackMarketShop
	waitstate
	setspeaker SP_NAME_EL_PIEDRAS
	msgbox Common_Text_ElPiedrasBlackMarketFarewell, MSGBOX_DEFAULT
	release
	end

Common_Text_ElPiedrasBlackMarketIntro:
	.string "¡Psss! ¡Socio, baja la voz!\p"
	.string "Aquí arriba la policía no sube\n"
	.string "porque hace un frío de locos.\l"
	.string "Tengo el cargamento más exclusivo\l"
	.string "y contrabandeado del juego.\p"
	.string "Megapiedras traídas de contrabando\n"
	.string "directamente de Kalos y más allá.\l"
	.string "¿Te sobra pasta? Hagamos business.$"

Common_Text_ElPiedrasBlackMarketFarewell:
	.string "Si te preguntan, tú y yo no nos\n"
	.string "hemos visto nunca. ¡Chispa, alerta!$"
