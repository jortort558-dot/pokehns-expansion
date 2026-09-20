AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "¿Tus POKéMON conocen alguna MO?\p"
	.string "Puedes usarlas fuera de combate\n"
	.string "aunque el POKéMON esté debilitado.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Un tal BILL inventó el sistema para\n"
	.string "guardar POKéMON en el PC.\p"
	.string "¡El PC DE BILL almacena hasta 30\n"
	.string "POKéMON por cada CAJA!$"

AzaleaPokecenter_Text_FishingGuru:
	.string "¡El PC DE BILL almacena hasta 30\n"
	.string "POKéMON por cada CAJA!$"

AzaleaPokecenter_Text_PokefanF:
	.string "¿Conoces los BONGURIS y a CÉSAR?\p"
	.string "Los vacía con cuidado y les instala\n"
	.string "un dispositivo especial.\p"
	.string "¡Así puedes atrapar POKéMON!\p"
	.string "Antes de inventar las Poké Balls,\n"
	.string "todo el mundo usaba BONGURIS.$"
