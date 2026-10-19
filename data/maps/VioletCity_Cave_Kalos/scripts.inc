VioletCity_Cave_Kalos_MapScripts::
	.byte 0

VioletCity_Cave_Kalos_EventScript_ReturnToViolet::
	lockall
	fadescreen FADE_TO_BLACK
	warp MAP_VIOLET_CITY_HNS, 19, 11
	waitstate
	end

VioletCity_Cave_Kalos_EventScript_Campfire::
	lock
	msgbox VioletCity_Cave_Kalos_Text_Campfire, MSGBOX_DEFAULT
	release
	end

VioletCity_Cave_Kalos_EventScript_Expeditionary::
	lock
	faceplayer
	msgbox VioletCity_Cave_Kalos_Text_Expeditionary, MSGBOX_DEFAULT
	release
	end

VioletCity_Cave_Kalos_EventScript_Restorer::
	lock
	faceplayer
	msgbox VioletCity_Cave_Kalos_Text_Restorer, MSGBOX_DEFAULT
	release
	end

VioletCity_Cave_Kalos_EventScript_YoungObserver::
	lock
	faceplayer
	msgbox VioletCity_Cave_Kalos_Text_YoungObserver, MSGBOX_DEFAULT
	release
	end

VioletCity_Cave_Kalos_Text_Campfire:
	.string "La hoguera arde sin consumir\n"
	.string "la madera.\p"
	.string "Sus llamas dejan huecos oscuros\n"
	.string "en vez de ceniza.$"

VioletCity_Cave_Kalos_Text_Expeditionary:
	.string "Bajamos siguiendo las marcas,\n"
	.string "pero cada tramo olvidado era\l"
	.string "más largo que el anterior.\p"
	.string "Así trabaja el GOMMAGE:\n"
	.string "borra la medida del camino.$"

VioletCity_Cave_Kalos_Text_Restorer:
	.string "El GOMMAGE no destruye.\n"
	.string "Retira algo del lienzo y deja\l"
	.string "que tu memoria lo complete.\p"
	.string "Los POKÉMON, en cambio, todavía\n"
	.string "notan lo que ya no está.$"

VioletCity_Cave_Kalos_Text_YoungObserver:
	.string "La llama proyecta treinta y tres\n"
	.string "sombras. Las he contado.\p"
	.string "Solo somos cuatro alrededor\n"
	.string "del fuego... ¿Verdad?$"
