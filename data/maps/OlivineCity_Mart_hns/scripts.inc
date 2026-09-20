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
	.string "¿Tus POKéMON ya han aprendido el\nmovimiento para llevar a personas\lpor el agua?$"
OlivineCity_Text_MartLass:
	.string "Mi BUTTERFREE me lo envió mi novio\ndesde el extranjero.\pTraía una CARTA suya.\p¿Quieres saber qué pone?\pA ver... ¡Pues no! ¡Es un secreto!$"
