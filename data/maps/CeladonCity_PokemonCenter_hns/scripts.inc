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
	.string "ERIKA es experta en POKéMON de\n"
	.string "tipo planta.\p"
	.string "Como te descuides, te hará pagar\n"
	.string "el error.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "La guarida del TEAM ROCKET está en\n"
	.string "el sótano del CASINO.\p"
	.string "Ah, espera. Eso fue hace tres años.$"

Celadon_Text_Eusine1:
	.string "EUSINE: ¡Hola!\p"
	.string "He vuelto para visitar mi ciudad\n"
	.string "natal. Hacía mucho que no venía.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, ¿te has enterado?\p"
	.string "Corre el rumor de que un POKéMON\n"
	.string "de colores arcoíris ha aparecido\l"
	.string "en la TORRE HOJALATA.\p"
	.string "Acaban de curar a mi equipo, así\n"
	.string "que parto hacia CIUDAD IRIS.\p"
	.string "¡Nos veremos, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Ah, por cierto, {PLAYER}.\p"
	.string "¿Has capturado a los POKéMON\n"
	.string "legendarios RAIKOU y ENTEI?\p"
	.string "<……><……><……>\p"
	.string "Ya veo…\p"
	.string "Si capturas aunque sea a uno,\n"
	.string "espero que me lo cuentes.\p"
	.string "¡Cuento contigo, {PLAYER}!$"
