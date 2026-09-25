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
	.string "…Has llegado desde muy lejos…\pHe meditado aquí. En mi interior\nha despertado un nuevo poder.\pPermíteme compartirlo con tus\nPOKéMON. Toma esto, criatura.$"
HiddenPowerGuy_Text_Explanation:
	.string "¿Lo ves? ¡Es PODER OCULTO!\pExtrae el poder del POKéMON para\natacar.\pRecuerda: su tipo y potencia\ndependen del POKéMON que lo use.$"
HiddenPowerGuy_Text_Meditating:
	.string "Me hallo en profunda meditación…$"
