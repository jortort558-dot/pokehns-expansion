CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Te contaré una\n"
	.string "historia de miedo.$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Pero no te dará\n"
	.string "tanto miedo si aún\l"
	.string "es de día.\p"
	.string "Vuelve cuando\n"
	.string "anochezca, ¿vale?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Érase una vez un niño al que\n"
	.string "regalaron una BICICLETA nueva…\p"
	.string "Quiso probarla enseguida…\p"
	.string "Se divertía tanto que no vio\n"
	.string "que el sol se había puesto…\p"
	.string "De vuelta a casa, en plena noche,\n"
	.string "¡la bici frenó de repente!\p"
	.string "¡Los pedales pesaban mucho!\p"
	.string "Cuando dejó de pedalear, la bici\n"
	.string "¡empezó a ir hacia atrás!\p"
	.string "Parecía estar maldita y querer\n"
	.string "arrastrarlo al abismo.\p"
	.string "…\p"
	.string "…\p"
	.string "¡AAAAAH!\p"
	.string "¡El niño iba cuesta arriba por\n"
	.string "el CARRIL BICI!\p"
	.string "…\n"
	.string "¡Chan, chan!\p"
	.string "Por escuchar con paciencia,\n"
	.string "¡puedes llevarte esta MT82!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La MT82 es SONÁMBULO.\p"
	.string "Permite usar un movimiento al\n"
	.string "azar mientras duerme.\p"
	.string "¡A ver quién duerme después de\n"
	.string "esta historia terrorífica!$"

