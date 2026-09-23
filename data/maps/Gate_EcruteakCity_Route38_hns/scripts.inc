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
	.string "¿De dónde has dicho que vienes?\n"
	.string "¿De PUEBLO PRIMAVERA?\p"
	.string "Allí vive el PROF. ELM, ¿verdad?\p"
	.string "Has recorrido un camino muy\n"
	.string "largo para llegar hasta aquí.$"
