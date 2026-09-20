EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "La campana de hojalata tañe con\npureza\lpara quienes se cobijan bajo el ala\lde\lla torre.$"
EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TORRE HOJALATA está restringida\na los\lno dignos. Lo siento, pero debes\lirte.$"
EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "El paso a la TORRE HOJALATA\nrequiere la\lMEDALLA del GIMNASIO de CIUDAD\lIRIS.\p¡Ah!\n¡La MEDALLA de CIUDAD IRIS!\lAdelante,\lpuedes pasar sin problemas.$"
EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Ha ocurrido un acontecimiento de\nenorme\ltrascendencia.\pTe ruego me disculpes, pero debo\npedirte\lque te marches.\p...Aquello que sosiega el alma...\pEl TRÍO SABIO dice cosas que\nresultan\ltan difíciles de comprender...$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Ha ocurrido un hecho trascendental.\pDisculpa, pero debo pedirte que te\nmarches.\p..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "¡Ah!\n¡El sonido de esa CAMPANA CLARA!\p¡E-es sublime!\n¡Jamás en mi vida había oído un\lsonido\ltan hermoso!\pEl tañido de esa campana refleja la\npureza del alma de su portador.\pTú...\nQuizá tú seas capaz de cruzar la\lTORRE\lHOJALATA.\pPor favor, continúa adelante.$"
EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Por favor, continúa adelante.$"
EcruteakTinTowerEntrance_Text_SageDone:
	.string "El tañido de esa campana refleja el\nalma\lde su portador.\pTú...\nVerdaderamente eres digno.$"
EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TORRE HOJALATA que ves delante\nes\luna torre de nueve pisos de belleza\ldivina.\pSosiega el alma de todo aquel que\nla\lcontempla.$"
EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "¡La TORRE HOJALATA se estremeció!\n¡Un POKéMON legendario debe de\lhaber\lregresado a su cumbre!$"
EcruteakTinTowerEntrance_Text_Gramps:
	.string "Dos torres... Dos POKéMON...\pPero cuando una ardió, ambos\nPOKéMON se\lfueron volando para no volver\ljamás.$"
