DarkCave_NorthSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "¡Uala! ¡Qué susto me has pegao!\p"
    .string "Llevaba puestas mis GAFAS DE SOL y\n"
    .string "no te he visto ni venir.\p"
    .string "¿Que qué hago aquí metido?\p"
    .string "Oye, a ti qué te importa.\p"
    .string "Te doy unas GAFAS DE SOL y tú te\n"
    .string "olvidas de que me has visto aquí,\n"
    .string "¿hace?$"

DarkCave2_Text_Nerd2:
    .string "Las GAFAS DE SOL potencian los\nataques\l"
    .string "de tipo SINIESTRO.$"
