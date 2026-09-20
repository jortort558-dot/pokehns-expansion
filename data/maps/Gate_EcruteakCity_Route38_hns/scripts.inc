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
	.string "¿De dónde has dicho que vienes?\n¿De PUEBLO PRIMAVERA?\pAllí vive el PROF. ELM, ¿verdad?\pHas recorrido un camino muy largo\npara\lllegar hasta aquí.$"
