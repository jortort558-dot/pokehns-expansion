CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "¡Una máquina expendedora!\p"
	.string "Este es el menú.$"

CeladonDeptStore6F_Text_Clang:
	.string "Clang!\p"
	.string "{STRING} popped out.$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "Vaya, no tienes suficiente dinero…$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "No hay sitio para nada más…$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "Una máquina expendedora con ruleta\n"
	.string "de premios…\p"
	.string "Ya no se ven máquinas así.$"

CeladonDeptStore6F_Text_Youngster:
	.string "¡Jo! ¡Aquí no hay juegos!\p"
	.string "Quería jugar…$"

CeladonDeptStore6F_Text_Directory:
	.string "P5: PLAZA DE LA AZOTEA\n"
	.string "MÁQUINAS EXPENDEDORAS$"

CeladonDeptRoof_EventScript_Mori::
	lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox CeladonDeptRoof_Text_MoriTalk, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonDeptRoof_EventScript_DaraOtaku::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox CeladonDeptRoof_Text_DaraIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	checkmoney 30000
	goto_if_eq VAR_RESULT, FALSE, CeladonDeptRoof_EventScript_DaraNoMoney
CeladonDeptRoof_EventScript_DaraChoosePartyMon:
	msgbox CeladonDeptRoof_Text_DaraChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CeladonDeptRoof_EventScript_DaraDeclined
	message CeladonDeptRoof_Text_DaraChooseService
	waitmessage
	multichoice 15, 6, MULTI_DARA_SERVICE_CHOICE, FALSE
	switch VAR_RESULT
	case 0, CeladonDeptRoof_EventScript_DaraServiceStandard
	case 1, CeladonDeptRoof_EventScript_DaraServiceEvolutionary
	goto CeladonDeptRoof_EventScript_DaraDeclined

CeladonDeptRoof_EventScript_DaraServiceStandard::
	special DaraOtaku_CheckAndPrepareAbilities
	switch VAR_RESULT
	case 0, CeladonDeptRoof_EventScript_DaraNoChangeAvailable
	case 1, CeladonDeptRoof_EventScript_DaraOnlyNormal
	case 2, CeladonDeptRoof_EventScript_DaraOnlyHidden
	case 3, CeladonDeptRoof_EventScript_DaraBothChoices
	end

CeladonDeptRoof_EventScript_DaraDeclined::
	msgbox CeladonDeptRoof_Text_DaraDeclined, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraNoMoney::
	msgbox CeladonDeptRoof_Text_DaraNoMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraNoMoneyEvo::
	msgbox CeladonDeptRoof_Text_DaraNoMoneyEvo, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraNoChangeAvailable::
	msgbox CeladonDeptRoof_Text_DaraNoOtherAbility, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraOnlyNormal::
	msgbox CeladonDeptRoof_Text_DaraConfirmNormal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	setvar VAR_0x8005, 1
	goto CeladonDeptRoof_EventScript_DaraExecuteChange

CeladonDeptRoof_EventScript_DaraOnlyHidden::
	msgbox CeladonDeptRoof_Text_DaraConfirmHidden, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	setvar VAR_0x8005, 2
	goto CeladonDeptRoof_EventScript_DaraExecuteChange

CeladonDeptRoof_EventScript_DaraBothChoices::
	message CeladonDeptRoof_Text_DaraSelectWhich
	waitmessage
	multichoice 19, 6, MULTI_DARA_ABILITY_CHOICE, FALSE
	switch VAR_RESULT
	case 0, CeladonDeptRoof_EventScript_DaraChooseNormalFromBoth
	case 1, CeladonDeptRoof_EventScript_DaraChooseHiddenFromBoth
	goto CeladonDeptRoof_EventScript_DaraDeclined

CeladonDeptRoof_EventScript_DaraChooseNormalFromBoth::
	setvar VAR_0x8005, 1
	special DaraOtaku_PrepareChoiceAbility
	msgbox CeladonDeptRoof_Text_DaraConfirmNormal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	goto CeladonDeptRoof_EventScript_DaraExecuteChange

CeladonDeptRoof_EventScript_DaraChooseHiddenFromBoth::
	setvar VAR_0x8005, 2
	special DaraOtaku_PrepareChoiceAbility
	msgbox CeladonDeptRoof_Text_DaraConfirmHidden, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	goto CeladonDeptRoof_EventScript_DaraExecuteChange

CeladonDeptRoof_EventScript_DaraExecuteChange::
	removemoney 30000
	updatemoneybox
	playse SE_SHOP
	waitse
	playse SE_USE_ITEM
	special DaraOtaku_ApplyAbilityChange
	waitse
	msgbox CeladonDeptRoof_Text_DaraSuccess, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraServiceEvolutionary::
	checkmoney 100000
	goto_if_eq VAR_RESULT, FALSE, CeladonDeptRoof_EventScript_DaraNoMoneyEvo
	special DaraOtaku_CheckAndPrepareEvolutionAbilities
	goto_if_eq VAR_RESULT, 0, CeladonDeptRoof_EventScript_DaraNoEvolutionAbilities
	msgbox CeladonDeptRoof_Text_DaraSelectEvoAbility, MSGBOX_DEFAULT
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, CeladonDeptRoof_EventScript_DaraDeclined
	goto_if_eq VAR_RESULT, 0, CeladonDeptRoof_EventScript_DaraDeclined
	copyvar VAR_0x8005, VAR_RESULT
	special DaraOtaku_PrepareChosenEvoAbilityName
	msgbox CeladonDeptRoof_Text_DaraConfirmEvoAbility, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonDeptRoof_EventScript_DaraDeclined
	removemoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	playse SE_USE_ITEM
	special DaraOtaku_ApplyEvolutionAbilityChange
	waitse
	msgbox CeladonDeptRoof_Text_DaraSuccessEvo, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_EventScript_DaraNoEvolutionAbilities::
	msgbox CeladonDeptRoof_Text_DaraNoEvoAbilityAvailable, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

CeladonDeptRoof_Text_MoriTalk:
	.string "Mori: ¡Guau, guau!\p"
	.string "Menea la cola alegremente\n"
	.string "mientras vigila la azotea.$"

CeladonDeptRoof_Text_DaraIntro:
	.string "¡Ah, qué brisa tan buena!\p"
	.string "Hola, me llamo DARA.\n"
	.string "Vendo libros abajo en la ciudad,\l"
	.string "pero subo aquí con Mori para leer\l"
	.string "tranquila y tomar el aire.\p"
	.string "He estudiado el potencial oculto\n"
	.string "y el linaje de los POKéMON.\p"
	.string "Por 30.000¥ puedo despertar otra\n"
	.string "habilidad actual de tu compañero.\p"
	.string "Por 100.000¥ puedo rastrear sus\n"
	.string "raíces y recuperar una habilidad\l"
	.string "que tuviera en su línea evolutiva.\p"
	.string "¿Te gustaría que lo intente?$"

CeladonDeptRoof_Text_DaraChooseMon:
	.string "¿A qué compañero quieres que\n"
	.string "consulte en mis tomos?$"

CeladonDeptRoof_Text_DaraChooseService:
	.string "¿Qué tipo de servicio buscas?$"

CeladonDeptRoof_Text_DaraDeclined:
	.string "No pasa nada. Aquí seguiremos\n"
	.string "Mori y yo disfrutando del aire.$"

CeladonDeptRoof_Text_DaraNoMoney:
	.string "Vaya... No tienes 30.000¥ encima.\n"
	.string "Los tomos antiguos son caros de\l"
	.string "mantener. ¡Vuelve cuando puedas!$"

CeladonDeptRoof_Text_DaraNoMoneyEvo:
	.string "Vaya… Rastrear su linaje requiere\n"
	.string "consultar tomos muy raros\l"
	.string "y cuesta 100.000¥.\p"
	.string "¡Vuelve cuando tengas el dinero!$"

CeladonDeptRoof_Text_DaraNoOtherAbility:
	.string "Mmm… Mori y yo hemos mirado bien,\n"
	.string "pero {STR_VAR_1} ya tiene todo\l"
	.string "su potencial actual descubierto.$"

CeladonDeptRoof_Text_DaraNoEvoAbilityAvailable:
	.string "Mmm… He revisado a fondo su línea\n"
	.string "evolutiva, pero {STR_VAR_1} no\l"
	.string "cuenta con habilidades previas\l"
	.string "distintas a las que ya conoce.$"

CeladonDeptRoof_Text_DaraConfirmNormal:
	.string "{STR_VAR_1} tiene {STR_VAR_2}.\p"
	.string "¿Quieres cambiarla por su otra\n"
	.string "habilidad, {STR_VAR_3}?$"

CeladonDeptRoof_Text_DaraConfirmHidden:
	.string "{STR_VAR_1} tiene {STR_VAR_2}.\p"
	.string "¿Quieres despertar su habilidad\n"
	.string "oculta, {STR_VAR_3}?$"

CeladonDeptRoof_Text_DaraSelectWhich:
	.string "¿Qué habilidad quieres despertar?$"

CeladonDeptRoof_Text_DaraSelectEvoAbility:
	.string "¿Qué habilidad de su linaje\n"
	.string "te gustaría que recupere?$"

CeladonDeptRoof_Text_DaraConfirmEvoAbility:
	.string "{STR_VAR_1} tiene {STR_VAR_2}.\p"
	.string "¿Quieres que recupere {STR_VAR_3}\n"
	.string "de su linaje por 100.000¥?$"

CeladonDeptRoof_Text_DaraSuccess:
	.string "¡Una lectura rápida y…\n"
	.string "¡{STR_VAR_1} ha despertado\l"
	.string "{STR_VAR_2}! ¡Le sienta genial!$"

CeladonDeptRoof_Text_DaraSuccessEvo:
	.string "¡He conectado sus raíces con los\n"
	.string "tomos ancestrales…\p"
	.string "¡{STR_VAR_1} ha recuperado\n"
	.string "{STR_VAR_2}! ¡Menudo poder!$"
