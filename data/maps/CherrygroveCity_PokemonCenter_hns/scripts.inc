CherrygroveCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "Es una maravilla. Puedo guardar\ntantos\l"
	.string "POKéMON como quiera, y es gratis.$"

CherryGrove_Pokecenter_Text_Gentleman:
	.string "Cualquier entrenador puede usar ese\n"
	.string "PC libremente.$"

CherryGrove_Pokecenter_Text_Lass:
	.string "Dicen que el tiempo no pasa cuando\nesperas.\l"
	.string "¡Pero viendo el reloj del CENTRO\nPOKéMON\l"
	.string "el tiempo vuela!$"

CherryGrove_Pokecenter_Text_Chansey:
	.string "CHANSEY: Chaan! Sii!$"
