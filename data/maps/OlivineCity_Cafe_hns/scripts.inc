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
	.string "Ah... Hola, {PLAYER}.\pTodos estos platos que ves aquí no\nson\lsolo míos...\pEsto...\pEn realidad, quien estaba sentado\nantes\lque yo comió una barbaridad...\pSi quieres que luchemos otra vez,\nvisítame en el DOJO de COMBATE en\lCIUDAD AZAFRÁN.$"
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
	.string "¡Ja! ¡Tus POKéMON tienen pinta de\nser\lmás bien flacuchos!\pSeguro que no tienen fuelle ni para\nmover una roca.\p¡Anda, toma esto y enséñales\nFUERZA!$"
OlivineCity_Text_CafeSailorGotStrength:
	.string "En alta mar, ¡lo único con lo que\npuedes contar es con tu propio\lcuerpo!\p¡Mírame qué brazos tengo!\n¡Deberías entrenar tan duro como\lyo!$"
OlivineCity_Text_CafeFishingGuru:
	.string "¡El menú del CAFÉ DE OLIVO está\nlleno\lde manjares para MARINEROS de buena\lplanta como yo!$"
OlivineCity_Text_CafeSailor:
	.string "Cada vez que atraco en este pueblo,\nme vengo directo al CAFÉ DE OLIVO.\pTodo lo de la carta te llena de\nfuerza.\l¡Es imposible parar de zampar!$"
