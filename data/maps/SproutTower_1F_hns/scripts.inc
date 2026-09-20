SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Montamos guardia en esta torre.\p"
	.string "Aquí mostramos nuestra gratitud\n"
	.string "para honrar a todo POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "¡G-gracias!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Todos los seres vivos coexistimos\n"
	.string "mediante la cooperación mutua.\p"
	.string "Debemos estar eternamente\n"
	.string "agradecidos por ello.$"

SproutTower_Text_1F_Sage1:
	.string "Solo si llegas hasta la cima\n"
	.string "conseguirás la preciada MO.$"

SproutTower_Text_1F_Sage2:
	.string "La TORRE BELSPROUT se erigió hace\n"
	.string "mucho para entrenar POKéMON.$"

SproutTower_Text_1F_Granny:
	.string "Un BELLSPROUT de más de 30 metros\n"
	.string "de altura…\p"
	.string "Cuentan que su cuerpo conformó el\n"
	.string "pilar central de esta torre.$"

SproutTower_Text_1F_Teacher:
	.string "¿Ves cómo se balancea el pilar?\p"
	.string "Es porque arriba están entrenando.$"

SproutTower_Text_1F_Statue:
	.string "Una estatua de un POKéMON…\p"
	.string "Se ve muy elegante y solemne.$"
