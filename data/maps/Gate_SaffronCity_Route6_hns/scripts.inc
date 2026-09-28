Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "¡Te damos la bienvenida a CIUDAD\n"
	.string "AZAFRÁN, hogar del MAGNETOTRÉN!\p"
	.string "…Eso diría normalmente, pero\n"
	.string "el MAGNETOTRÉN no funciona.\p"
	.string "No recibe electricidad porque hay\n"
	.string "un problema en la CENTRAL\l"
	.string "DE ENERGÍA.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "El MAGNETOTRÉN es la mayor\n"
	.string "atracción de CIUDAD AZAFRÁN.$"
