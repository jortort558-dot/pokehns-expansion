OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "¿Tus POKéMON ya conocen el\nmovimiento que transporta personas\lpor el agua?$"
OlivineCity_Text_MartLass:
	.string "Mi BUTTERFREE vino de parte de mi\nnovio, que vive en el extranjero.\pTraía una CARTA suya.\p¿Quieres saber qué dice?\pA ver... ¡No! ¡Es un secreto!$"
