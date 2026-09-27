LakeOfRage_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_House1_OnTransition
	.byte 0

LakeOfRage_House1_OnTransition::
	goto_if_unset FLAG_RECEIVED_MEGA_TEST_KIT, LakeOfRage_House1_HideElPiedras
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, LakeOfRage_House1_HideElPiedras
	clearflag FLAG_HIDE_LAKE_OF_RAGE_EL_PIEDRAS
	end

LakeOfRage_House1_HideElPiedras::
	setflag FLAG_HIDE_LAKE_OF_RAGE_EL_PIEDRAS
	end

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

LakeOfRage_House1_EventScript_ElPiedras::
	lock
	faceplayer
	msgbox LakeOfRage_House1_Text_ElPiedras, MSGBOX_DEFAULT
	setflag FLAG_TALKED_EL_PIEDRAS_LAKE_OF_RAGE
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
	.string "…Has llegado desde muy lejos…\pHe meditado aquí. En mi interior\nha despertado un nuevo poder.\pPermíteme compartirlo con tus\nPOKéMON. Toma esto, criatura.$"
HiddenPowerGuy_Text_Explanation:
	.string "¿Lo ves? ¡Es PODER OCULTO!\pExtrae el poder del POKéMON para\natacar.\pRecuerda: su tipo y potencia\ndependen del POKéMON que lo use.$"
HiddenPowerGuy_Text_Meditating:
	.string "Me hallo en profunda meditación…$"

LakeOfRage_House1_Text_ElPiedras:
	.string "¡Hermano! ¡Cierra la puerta que\n"
	.string "se me enfrían los cheetos!\p"
	.string "¿Has visto al tipo pelirrojo fuera\n"
	.string "activar una mega-transformación\l"
	.string "digna de anime shonen?\p"
	.string "¡Esas piedras de mega-evolución\n"
	.string "existen de verdad! ¡El mercado no\l"
	.string "estaba inflado, socio!\p"
	.string "Los del Team Rocket salieron por\n"
	.string "patas dejando suministros.\p"
	.string "En cuanto los barras de la Torre\n"
	.string "Radio de Trigal, ¡voy a reventar\l"
	.string "el monopolio de las tiendas!$"

