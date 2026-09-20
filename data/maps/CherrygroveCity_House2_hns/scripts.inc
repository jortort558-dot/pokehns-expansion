CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "¡Cuando era un chavalín, era un\nentrenador\l"
	.string "de primera!\p"
	.string "Te daré un consejo:\n"
	.string "¡Atrapa un montón de POKéMON!\p"
	.string "¡Y trátalos a todos con cariño!$"
