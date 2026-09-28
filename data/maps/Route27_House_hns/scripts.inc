Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "¿Adónde vas con tus POKéMON?\p"
    .string "¿A la LIGA POKéMON?\p"
    .string "¿Confían en ti lo suficiente\n"
    .string "como para vencer?\p"
    .string "Déjame ver…$"

SandstormHouse_Text_LoyalMon:
    .string "¡Ah! Tu POKéMON confía mucho en ti.\p"
    .string "Da gusto ver a un buen Entrenador.\p"
    .string "Toma. Un regalo para tu viaje.$"

SandstormHouse_Text_TM37Description:
    .string "La MT37 contiene TORMENTA ARENA.\p"
    .string "Es un movimiento que daña a ambos\n"
    .string "combatientes.\p"
    .string "Solo es apto para expertos.\n"
    .string "¡Úsalo si te atreves! ¡Suerte!$"

SandstormHouse_Text_DisloyalMon:
    .string "Si no aprende a confiar más en ti,\n"
    .string "lo tendrás muy difícil.\p"
    .string "La confianza une a los POKéMON\n"
    .string "con sus Entrenadores.$"

