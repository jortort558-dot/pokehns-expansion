GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "Me desafiaron a un combate ahí\nabajo.\lEl ambiente está tenso. Ándate con\lojo.$"
GoldenrodUnderground1_Text_Teacher:
	.string "Hay tiendas en el piso de abajo…\nPero también hay ENTRENADORES.\lMe da miedo bajar ahí.$"
