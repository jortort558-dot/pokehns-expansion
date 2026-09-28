CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "¡Hola!\p"
	.string "Estamos celebrando\n"
	.string "un concurso de\l"
	.string "tragones.\p"
	.string "Perdona. Ahora no\n"
	.string "podemos atenderte.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "¡No me hables!\p"
	.string "¡Me vas a\n"
	.string "desconcentrar!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "¡Glup…! ¡Ñam!$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "¡Mejor cantidad\n"
	.string "que calidad!\p"
	.string "¡Si estoy lleno,\n"
	.string "estoy feliz!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "La comida de aquí\n"
	.string "es buena, pero en\p"
	.string "CIUDAD TRIGAL es\n"
	.string "aún mejor.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "¡Ñam, ñam!$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Aquí nadie te va\n"
	.string "a dar un MONEDERO.\p"
	.string "Mejor que lo\n"
	.string "busques en JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "Ñam… Ñam…\p"
	.string "¡Puedo seguir comiendo!\n"
	.string "¡Más, COCINERO!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "¡Concurso de\n"
	.string "tragones! ¡Sin\p"
	.string "tiempo! ¡Una lucha\n"
	.string "sin fin! ¡El mayor\p"
	.string "tragón podrá comer\n"
	.string "gratis!$"
