NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "La nieve dificulta bastante\n"
	.string "orientarse por estos lares.\p"
	.string "Todo parece idéntico.\p"
	.string "¡Este mapa es una gran ayuda!\p"
	.string "¡Qué región tan hermosa!$"

NewSinjoh_Text_Artist:
	.string "¡He hallado una gran inspiración en\n"
	.string "este pueblo oculto!\p"
	.string "¿No crees que el paisaje es\n"
    .string "impresionante?$"

Text_ItemGiveaway:
	.string "¡Ya veo!\n"
	.string "¡Tú también tienes alma de artista!\p"
	.string "Resulta que me sobra algo que te\n"
	.string "ayudará a captar los pequeños\l"
    .string "detalles de la vida.$"

NewSinjoh_Text_Artist_No:
    .string "¿No serás de los que detestan a los\n"
    .string "turistas, verdad?\p"
	.string "La belleza está hecha para\n"
	.string "compartirla.$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "¡Espero que disfrutes de ese lente!$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "No tenemos demasiadas comodidades\n"
	.string "modernas en NUEVO SINJOH.\p"
	.string "Pero al menos contamos con este\n"
	.string "CENTRO POKéMON.$"


NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER} miró con atención el mapa\n"
	.string "de SINJOH.$"
