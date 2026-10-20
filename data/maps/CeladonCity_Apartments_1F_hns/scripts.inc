CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "Mis queridos POKéMON me hacen\n"
	.string "compañía y nunca me siento sola.\p"
	.string "MEOWTH hasta trae dinero a casa.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "DESPACHO DE LA ADMINISTRADORA\n"
	.string "DE LA MANSIÓN AZULONA$"
