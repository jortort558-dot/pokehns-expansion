OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Ah... Hola, {PLAYER}.\pEsos platos que ves ahí no son\ntodos míos...\pEh...\pEn realidad, quien estaba aquí\nantes que yo comió muchísimo...\pSi quieres volver a combatir,\nvisítame en el DOJO DE LUCHA de\lCIUDAD AZAFRÁN.$"
OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "¡Ja! ¡Tus POKéMON parecen unos\npeso pluma!\pNo tienen fuerza suficiente para\napartar rocas.\p¡Toma, úsalo para enseñarles\nFUERZA!$"
OlivineCity_Text_CafeSailorGotStrength:
	.string "¡En alta mar, solo puedes\nconfiar en ti mismo!\p¡Estoy orgulloso de este cuerpazo!\n¡Entrena duro, como yo!$"
OlivineCity_Text_CafeFishingGuru:
	.string "¡El menú del CAFÉ DE OLIVO rebosa\nde comida contundente para\lMARINEROS fortachones como yo!$"
OlivineCity_Text_CafeSailor:
	.string "Siempre que atraco en esta ciudad,\nvoy directo al CAFÉ DE OLIVO.\pTodo el menú me da más fuerzas.\n¡No puedo parar de comer!$"
