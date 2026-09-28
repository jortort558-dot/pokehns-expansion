CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "Mis queridos\n"
	.string "POKéMON me hacen\p"
	.string "compañía, así que\n"
	.string "nunca estoy sola.\p"
	.string "MEOWTH hasta trae\n"
	.string "dinero a casa.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "DESPACHO DEL JEFE\n"
	.string "DE MANSIÓN AZULONA$"
