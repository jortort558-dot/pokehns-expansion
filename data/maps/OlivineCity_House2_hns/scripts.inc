OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "De camino a CIUDAD ORQUÍDEA hay\ncuatro\lislas desiertas.\p¡A los niños malos los mandan\ncastigados\la esas islas perdidas!$"
OlivineCity_Text_PunishmentBoy:
	.string "Cada vez que hago una trastada,\nmi hermano mayor me asusta con eso.$"
