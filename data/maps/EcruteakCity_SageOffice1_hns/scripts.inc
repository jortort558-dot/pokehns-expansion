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
	.string "La campana de hojalata tañe con\n"
	.string "pureza para quienes se cobijan\l"
	.string "bajo el ala de la torre.$"
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
	.string "La TORRE HOJALATA está\n"
	.string "restringida a los no dignos. Lo\l"
	.string "siento, pero debes irte.$"
EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "El paso a la TORRE HOJALATA\n"
	.string "requiere la MEDALLA del GIMNASIO\l"
	.string "de CIUDAD IRIS.\p"
	.string "¡Ah! ¡La MEDALLA de CIUDAD IRIS!\n"
	.string "Adelante, puedes pasar sin\l"
	.string "problemas.$"
EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Ha ocurrido un acontecimiento de\n"
	.string "enorme trascendencia.\p"
	.string "Te ruego me disculpes, pero debo\n"
	.string "pedirte que te marches.\p"
	.string "...Aquello que sosiega el\n"
	.string "alma...\p"
	.string "El TRÍO SABIO dice cosas que\n"
	.string "resultan tan difíciles de\l"
	.string "comprender...$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Ha ocurrido un hecho\n"
	.string "trascendental.\p"
	.string "Disculpa, pero debo pedirte que\n"
	.string "te marches.\p"
	.string "..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "¡Ah! ¡El sonido de esa CAMPANA\n"
	.string "CLARA!\p"
	.string "¡E-es sublime! ¡Jamás en mi vida\n"
	.string "había oído un sonido tan\l"
	.string "hermoso!\p"
	.string "El tañido de esa campana refleja\n"
	.string "la pureza del alma de su\l"
	.string "portador.\p"
	.string "Tú... Quizá tú seas capaz de\n"
	.string "cruzar la TORRE HOJALATA.\p"
	.string "Por favor, continúa adelante.$"
EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Por favor, continúa adelante.$"
EcruteakTinTowerEntrance_Text_SageDone:
	.string "El tañido de esa campana refleja\n"
	.string "el alma de su portador.\p"
	.string "Tú... Verdaderamente eres digno.$"
EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TORRE HOJALATA que ves\n"
	.string "delante es una torre de nueve\l"
	.string "pisos de belleza divina.\p"
	.string "Sosiega el alma de todo aquel\n"
	.string "que la contempla.$"
EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "¡La TORRE HOJALATA se\n"
	.string "estremeció! ¡Un POKéMON\l"
	.string "legendario debe de haber\l"
	.string "regresado a su cumbre!$"
EcruteakTinTowerEntrance_Text_Gramps:
	.string "Dos torres... Dos POKéMON...\p"
	.string "Pero cuando una ardió, ambos\n"
	.string "POKéMON se fueron volando para\l"
	.string "no volver jamás.$"
