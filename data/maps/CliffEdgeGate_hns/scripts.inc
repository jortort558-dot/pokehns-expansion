CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "¿Lo sabías? Hay una ZONA SAFARI\n"
	.string "a la vuelta de la esquina.\p"
	.string "¡Es muy divertida!\n"
	.string "Verás muchas especies de POKéMON\l"
	.string "¡y podrás capturar cuanto quieras!\p"
	.string "No hay razón para no ir, ¿verdad?\n"
	.string "Está ahí al lado.$"

CliffEdgeGate_Text_Expectations:
	.string "Me alegra que todos estén deseando\n"
	.string "visitarla.\p"
	.string "Pero la chica de recepción parece\n"
	.string "un poco exagerada…\p"
	.string "¡No te hagas demasiadas ilusiones!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "¡Pura emoción!\n"
	.string "¡Explora y halla POKéMON salvajes!\l"
	.string "¡ZONA SAFARI del DIRECTOR BAOBA\l"
	.string "abierta al público!$"
