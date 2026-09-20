LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
	.string "…Has viajado desde muy lejos…\pAquí he meditado en soledad. En mi\nser se\lha despertado un nuevo poder.\pPermíteme compartir este don con\ntus\lPOKéMON. Toma esto, criatura.$"
HiddenPowerGuy_Text_Explanation:
	.string "¿Lo sientes? ¡Es PODER OCULTO!\pExtrae la fuerza innata del POKéMON\npara\latacar.\pRecuerda esto: su tipo y potencia\ndependen\lexclusivamente del POKéMON que lo\luse.$"
HiddenPowerGuy_Text_Meditating:
	.string "Me hallo en profunda meditación…$"
