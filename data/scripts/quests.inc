Common_EventScript_QuestNewNotification::
	special Special_BufferQuestTitle
	playse SE_POKENAV_ON
	message gText_QuestNewRegistered
	waitmessage
	waitbuttonpress
	closemessage
	return

Common_EventScript_QuestCompletedNotification::
	special Special_BufferQuestTitle
	playfanfare MUS_OBTAIN_ITEM
	message gText_QuestCompletedNotification
	waitfanfare
	closemessage
	return

gText_QuestNewRegistered:
	.string "¡Nueva misión en el POKéGEAR!\n"
	.string "- {STR_VAR_1}$"

gText_QuestCompletedNotification:
	.string "¡Misión completada!\n"
	.string "- {STR_VAR_1}$"
