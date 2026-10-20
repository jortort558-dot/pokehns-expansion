Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Soy el hermano pequeño del\n"
	.string "GURÚ PESCADOR.\p"
	.string "Veo que te gusta pescar.\p"
	.string "¡No me cabe ninguna duda!\p"
	.string "¿Qué? Sé que tengo razón.$"
Route12_House_Text_GiveSuperRod:
	.string "¡Sí! ¡Justo lo que pensaba!\p"
	.string "Toma, aficionado a la pesca.\n"
	.string "¡Es una SÚPER CAÑA!$"
Route12_House_Text_GaveSuperRod:
	.string "Prueba a pescar allí donde\n"
	.string "encuentres agua.\p"
	.string "Recuerda: cada CAÑA permite\n"
	.string "capturar POKéMON diferentes.$"
Route12_House_Text_DontWantSuperRod:
	.string "¿Eh? ¿Me han engañado mis ojos?$"
