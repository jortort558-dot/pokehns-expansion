Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "¿De dónde dices que vienes?\p"
	.string "¿De PUEBLO PRIMAVERA?\p"
	.string "El PROF. ELM vive allí,\n"
	.string "¿verdad?\p"
	.string "Has recorrido un largo camino\n"
	.string "para llegar hasta aquí.$"
