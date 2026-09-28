CeladonCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FRUSTRATION, CeladonDeptStore5_EventScript_Receptionist_Already
	msgbox CeladonDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, FRIENDSHIP_50_TO_99, CeladonDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	msgbox CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_Already::
	msgbox CeladonDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore_Text_5FReceptionistOhYourMon:
    .string "Hola. Vaya, tu POKéMON…$"

CeladonDeptStore_Text_5FReceptionistWait:
    .string "¡Espera, ya te di esa MT!$"

CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Mmm…\n"
	.string "No está mal, pero tampoco bien.\p"
	.string "Como ENTRENADOR, debes esforzarte\n"
	.string "un poco más.$"

CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "Parece tener muy mal humor.\p"
    .string "¿Qué te parece esta MT?$"

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}. No esperaba verte aquí.\p"
	.string "Estoy comprando equipo para mis\n"
	.string "POKéMON pájaro.\p"
	.string "Si quieres volver a enfrentarte,\n"
	.string "estaré en el DOJO de AZAFRÁN.$"

CeladonDeptStore5F_Text_Gentleman:
	.string "Quiero comprar objetos que mejoran\n"
	.string "las características de los POKéMON,\l"
	.string "pero no tengo bastante dinero…$"

CeladonDeptStore5F_Text_Sailor:
	.string "Quiero un MÁS PP para aumentar los\n"
	.string "PP de un movimiento. No se vende…$"

CeladonDeptStore5F_Text_Teacher:
	.string "Usar objetos en los POKéMON hace\n"
	.string "que estén felices.\p"
	.string "Aunque hay objetos que detestan…$"

CeladonDeptStore5F_Text_Directory:
	.string "P5: FARMACIA$"
