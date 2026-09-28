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
	.string "Soy el hermano"
	.string "\npequeño del GURÚ"
	.string "\lPESCADOR."
	.string "\pVeo que te gusta"
	.string "\npescar."
	.string "\p¡No tengo ninguna"
	.string "\nduda!"
	.string "\pSé que tengo"
	.string "\n$razón."
Route12_House_Text_GiveSuperRod:
	.string "Sí, sí. ¡Justo lo"
	.string "\nque pensaba!"
	.string "\p¡Aquí tienes!"
	.string "\nToma esto. Es"
	.string "\l$una SÚPER CAÑA."
Route12_House_Text_GaveSuperRod:
	.string "Intenta pescar"
	.string "\nallí donde veas"
	.string "\lagua."
	.string "\pRecuerda: puedes"
	.string "\ncapturar POKéMON"
	.string "\pdiferentes usando"
	.string "\n$distintas CAÑAS."
Route12_House_Text_DontWantSuperRod:
	.string "¿Eh? ¿Me han engañado mis ojos?$"
