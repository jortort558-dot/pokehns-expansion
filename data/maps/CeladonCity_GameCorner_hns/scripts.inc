CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "Todas las\n"
	.string "tragaperras son de\l"
	.string "última generación.$"

CeladonGameCorner_Text_Teacher:
	.string "Quiero jugar en esta máquina.\p"
	.string "Ayer me dejó sin nada, así que\n"
	.string "hoy debería dar premio.$"

CeladonGameCorner_Text_FishingGuru:
	.string "Creo que esta tragaperras va a\n"
	.string "dar premio…\p"
	.string "Cada máquina tiene su azar.$"

CeladonGameCorner_Text_Fisher1:
	.string "¡Ja, ja, ja!\p"
	.string "¡No paran de salirme fichas!\p"
	.string "¿Qué pasa, chaval? ¿Quieres jugar?\p"
	.string "¡Compartiré mi suerte contigo!$"

CeladonGameCorner_Text_Fisher2:
	.string "¡Bien!\p"
	.string "¡Me gusta hacer\n"
	.string "favores a la\l"
	.string "gente!$"

CeladonGameCorner_Text_GymGuide:
	.string "¡Hola, futuro CAMPEÓN!\p"
	.string "¿También juegas a las máquinas?\p"
	.string "Intento conseguir fichas para\n"
	.string "un POKéMON de premio.\p"
	.string "Pero aún no tengo suficientes…$"

CeladonGameCorner_Text_PokefanF:
	.string "La ruleta…\p"
	.string "La prefiero a las tragaperras\n"
	.string "porque es más fácil calcular.\p"
	.string "Pero el premio es mucho menor.$"

CeladonGameCorner_Text_Gramps:
	.string "Mmm… Es más probable acertar\n"
	.string "apostándolo todo al azul,\l"
	.string "pero… ¿qué hago?$"

CeladonGameCorner_Text_Woman:
	.string "¡No paro de ganar!$"
