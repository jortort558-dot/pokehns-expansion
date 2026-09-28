Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "Tus POKéMON parecen algo cansados.\p"
    .string "Deberías dejarlos descansar.$"

Route26_Text_HealHouseKeepAtIt:
    .string "¡Listo!\p"
    .string "¡Tus POKéMON tienen buen aspecto!\p"
    .string "¡Sigue así!$"
