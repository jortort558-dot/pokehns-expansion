SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "No tengas miedo, no soy malo.\p"
	.string "Un lugar así atrae a gente\n"
	.string "desagradable.\p"
	.string "Al final causarían problemas…\p"
	.string "Solo pensarlo me pone furioso.$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "¡Ajá! ¡Eso es un\n"
	.string "CARAMELO FURIA!\p"
	.string "¿Me lo das?\n"
	.string "¡Por favor!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER} le dio el CARAMELO FURIA\n"
	.string "al hombre del pasadizo.\p"
	.string "¡Ñam!\p"
	.string "¡Qué irritante!\p"
	.string "¡Pero está buenísimo!\p"
	.string "¡Ñam, ñam!\p"
	.string "¡Argh! ¡Me pone furioso!\p"
	.string "¡Ñam, ñam!\p"
	.string "Argh…\p"
	.string "...................¡Uf!\p"
	.string "¡Ahora me siento mucho mejor!\n"
	.string "¡Gracias por el caramelo!\l"
	.string "¡Quiero que te quedes esto!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "La MT64 contiene…\p"
	.string "tic… tac…\n"
	.string "tic… tac…\l"
	.string "tic… tac…\l"
	.string "tic… tac…\l"
	.string "tic… ¡y entonces!\l"
	.string "......................\l"
	.string "......................\l"
	.string "¡¡¡BUM!!!$"
