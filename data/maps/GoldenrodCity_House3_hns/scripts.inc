GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox GoldenrodCity_House3_Text_CheckFriendship, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, GoldenrodCity_House3_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, GoldenrodCity_House3_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, GoldenrodCity_House3_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, GoldenrodCity_House3_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, GoldenrodCity_House3_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, GoldenrodCity_House3_EventScript_VeryHappy
	case FRIENDSHIP_MAX, GoldenrodCity_House3_EventScript_AdoresYou
	release
	end

GoldenrodCity_House3_EventScript_DetestsYou::
	msgbox GoldenrodCity_House3_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_VeryWary::
	msgbox GoldenrodCity_House3_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_NotUsedToYou::
	msgbox GoldenrodCity_House3_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_GettingUsedToYou::
	msgbox GoldenrodCity_House3_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_LikesYouQuiteALot::
	msgbox GoldenrodCity_House3_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_VeryHappy::
	msgbox GoldenrodCity_House3_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House3_EventScript_AdoresYou::
	msgbox GoldenrodCity_House3_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

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

GoldenrodCity_House3_Text_CheckFriendship:
	.string "Déjame ver a tu POKéMON.\n"
	.string "Comprobaré cuánto cariño te tiene.\p"
	.string "Vaya…\n"
	.string "Tu POKéMON…$"

GoldenrodCity_House3_Text_AdoresYou:
	.string "Te adora.\n"
	.string "No podría quererte más.\p"
	.string "Hasta yo me alegro al verlo.$"

GoldenrodCity_House3_Text_VeryHappy:
	.string "Parece muy feliz.\n"
	.string "Está claro que te quiere muchísimo.$"

GoldenrodCity_House3_Text_LikesYouQuiteALot:
	.string "Te quiere bastante.\n"
	.string "Parece querer algún mimo más.$"

GoldenrodCity_House3_Text_GettingUsedToYou:
	.string "Se está acostumbrando a ti.\n"
	.string "Parece que confía en ti.$"

GoldenrodCity_House3_Text_NotUsedToYou:
	.string "Aún no se ha acostumbrado a ti.\n"
	.string "No te quiere ni te detesta.$"

GoldenrodCity_House3_Text_VeryWary:
	.string "Desconfía mucho de ti.\n"
	.string "Tiene una mirada bastante hostil.\p"
	.string "No parece quererte nada.$"

GoldenrodCity_House3_Text_DetestsYou:
	.string "Me cuesta un poco decirte esto…\p"
	.string "Tu POKéMON te detesta.\n"
	.string "¿No te preocupa?$"
