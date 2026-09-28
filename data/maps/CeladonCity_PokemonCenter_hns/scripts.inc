CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA es experta\n"
	.string "en POKéMON planta.\p"
	.string "Si no tienes\n"
	.string "cuidado, acabará\l"
	.string "contigo.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "El TEAM ROCKET\n"
	.string "está escondido\p"
	.string "en el sótano del\n"
	.string "CASINO.\p"
	.string "Espera. Eso fue\n"
	.string "hace tres años.$"

Celadon_Text_Eusine1:
	.string "EUSINE: ¡Hola!\p"
	.string "Vuelvo de visitar\n"
	.string "mi ciudad.\p"
	.string "Llevaba tiempo\n"
	.string "sin ir.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, ¿lo\n"
	.string "has oído?\p"
	.string "Rumores recientes\n"
	.string "dicen que un\p"
	.string "POKéMON multicolor\n"
	.string "aparece en la\l"
	.string "TORRE HOJALATA.\p"
	.string "Acabo de curar a\n"
	.string "mi equipo y ahora\p"
	.string "salgo para CIUDAD\n"
	.string "IRIS.\p"
	.string "¡Nos vemos,\n"
	.string "{PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Oh, por cierto,\n"
	.string "{PLAYER}.\p"
	.string "¿Has capturado\n"
	.string "los POKéMON\p"
	.string "legendarios RAIKOU\n"
	.string "y ENTEI?\p"
	.string "<……><……><……>\p"
	.string "Vale…\p"
	.string "Si llegas a captu-\n"
	.string "rar aunque sea\l"
	.string "uno, infórmame.\p"
	.string "¡Cuento contigo,\n"
	.string "{PLAYER}!$"
