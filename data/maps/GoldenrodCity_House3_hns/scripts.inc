GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "No paro de perder combates y mis\n"
    .string "POKéMON acaban debilitados…\p"
    .string "Quizá por eso no me tienen mucho\n"
    .string "aprecio…$"

GoldenrodHappinessRater_Text_Twin:
    .string "¡Cuando uso objetos en mis POKéMON,\n"
    .string "se ponen la mar de contentos!$"
