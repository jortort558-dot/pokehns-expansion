SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_Text_BaobaName:
	.string "BAOBA$"

SaffronCity_Text_Baoba:
	.string "DIRECTOR BAOBA: ¡{PLAYER}!\p"
	.string "Soy el DIRECTOR BAOBA.\p"
	.string "Te llamo para avisarte de que\n"
	.string "¡la ZONA SAFARI se ha ampliado\l"
	.string "otra vez!\p"
	.string "¡Por fin mi ZONA SAFARI está\n"
	.string "completamente terminada!\p"
	.string "¿Te acuerdas de dónde está, verdad?\p"
	.string "¡Al oeste de CIUDAD ORQUÍDEA!\n"
	.string "¡Nos vemos pronto!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "¡Me encanta VULPIX! :D$"

SaffronCity_Text_Lass1:
	.string "Aquí vive una niña"
	.string "\nque es experta en"
	.string "\limitar a la gente."
	.string "\pImita incluso a la"
	.string "\ngente con la que"
	.string "\phabla, y te"
	.string "\n$confunde."
SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIONA parecía muy triste.\p"
	.string "Dijo que perdió su POKé MUÑECO\n"
	.string "favorito: CLEFAIRY.$"

SaffronCity_Text_PokefanM:
	.string "¿Eres de JOHTO?"
	.string "\pSi funcionara el"
	.string "\nMAGNETOTRÉN, no"
	.string "\ptardarías nada en"
	.string "\n$volver a casa."
SaffronCity_Text_PokefanM_ReturnedPart:
	.string "¿Eres de JOHTO?"
	.string "\pCon el MAGNETOTRÉN"
	.string "\nenseguida estarás"
	.string "\l$en casa."
SaffronCity_Text_CooltrainerM:
	.string "Iba al GIMNASIO"
	.string "\na luchar contra"
	.string "\lentrenadores…"
	.string "\pY acabé en el"
	.string "\nviejo GIMNASIO que"
	.string "\lhay al lado."
	.string "\p¡Vaya, qué"
	.string "\n$vergüenza pasé!"
SaffronCity_Text_CooltrainerF:
	.string "Es SILPH S.A.,"
	.string "\nfamosa por sus"
	.string "\lartículos POKéMON."
	.string "\pEn el pasado, el"
	.string "\nTEAM ROCKET quiso"
	.string "\phacerse con esta"
	.string "\ncompañía por esa"
	.string "\l$misma razón."
SaffronCity_Text_Fisher:
	.string "¡Ñam, ñam!"
	.string "\pDicen que en la"
	.string "\nCENTRAL ENERGÍA"
	.string "\ptienen muchos"
	.string "\nproblemas."
	.string "\p$¡Ñam, ñam!"
SaffronCity_Text_Fisher_ReturnedPart:
	.string "¡Ñam, ñam!"
	.string "\pDicen que hay"
	.string "\nproblemas en la"
	.string "\lCENTRAL ENERGÍA."
	.string "\p¡Ñam, ñam!"
	.string "\n$¡Estoy lleno!"
SaffronCity_Text_Youngster1:
	.string "Entrar por primera"
	.string "\nvez en un callejón"
	.string "\pme pone un poco"
	.string "\n$nervioso."
SaffronCity_Text_Youngster2:
	.string "En CIUDAD VERDE"
	.string "\nhay un lugar"
	.string "\pllamado la CASA"
	.string "\ndel ENTRENADOR,"
	.string "\pdonde se reúne"
	.string "\ngente de todas"
	.string "\l$partes."
SaffronCity_Text_Lass2:
	.string "Nuestra ciudad"
	.string "\nsalió en un"
	.string "\lprograma de radio."
	.string "\pEstá bien oír"
	.string "\nalabanzas sobre tu"
	.string "\pciudad, pero"
	.string "\ntambién da un poco"
	.string "\l$de vergüenza."
SaffronCity_Text_Sign:
	.string "CIUDAD AZAFRÁN"
	.string "\pLa brillante y"
	.string "\ndorada tierra del"
	.string "\l$comercio"
SaffronCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO"
	.string "\nPOKéMON DE CIUDAD"
	.string "\lAZAFRÁN: SABRINA"
	.string "\pMaestra de los"
	.string "\n$POKéMON psíquicos"
SaffronCity_Text_FightingDojoSign:
	.string "¡Bienvenidos!"
	.string "\n$DOJO-KARATE"
SaffronCity_Text_SilphCoSign:
	.string "SILPH CO.\n"
	.string "OFFICE BUILDING$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "MR.PSYCHIC'S\n"
	.string "HOUSE$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ESTACIÓN DEL"
	.string "\nMAGNETOTRÉN DE"
	.string "\l$CIUDAD AZAFRÁN"
