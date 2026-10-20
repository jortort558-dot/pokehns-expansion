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
	.string "Aquí vive una chica que es\n"
	.string "experta en imitar a la gente.\p"
	.string "Imita incluso a la gente con la\n"
	.string "que habla, y te confunde.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIONA parecía muy triste.\p"
	.string "Dijo que perdió su POKé MUÑECO\n"
	.string "favorito: CLEFAIRY.$"

SaffronCity_Text_PokefanM:
	.string "¿Eres de JOHTO?\p"
	.string "Si funcionara el MAGNETOTRÉN, no\n"
	.string "tardarías nada en volver a casa.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "¿Eres de JOHTO?\p"
	.string "Con el MAGNETOTRÉN enseguida\n"
	.string "estarás de vuelta en casa.$"

SaffronCity_Text_CooltrainerM:
	.string "Iba al GIMNASIO a luchar contra\n"
	.string "los entrenadores…\p"
	.string "¡Y acabé en el viejo GIMNASIO\n"
	.string "que hay al lado!\p"
	.string "¡Vaya, qué vergüenza pasé!$"

SaffronCity_Text_CooltrainerF:
	.string "Es SILPH S.A., famosa por sus\n"
	.string "magníficos artículos POKéMON.\p"
	.string "En el pasado, el TEAM ROCKET\n"
	.string "quiso hacerse con esta compañía\l"
	.string "por esa misma razón.$"

SaffronCity_Text_Fisher:
	.string "¡Ñam, ñam!\p"
	.string "Dicen que en la CENTRAL ENERGÍA\n"
	.string "tienen muchos problemas.\p"
	.string "¡Ñam, ñam!$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "¡Ñam, ñam!\p"
	.string "Dicen que hubo problemas en la\n"
	.string "CENTRAL ENERGÍA.\p"
	.string "¡Ñam, ñam! ¡Estoy lleno!$"

SaffronCity_Text_Youngster1:
	.string "Entrar por primera vez en un\n"
	.string "callejón me pone un poco nervioso.$"

SaffronCity_Text_Youngster2:
	.string "En CIUDAD VERDE hay un lugar\n"
	.string "llamado la CASA del ENTRENADOR,\l"
	.string "donde se reúne gente de todas\l"
	.string "partes.$"

SaffronCity_Text_Lass2:
	.string "Nuestra ciudad salió en un\n"
	.string "programa de radio.\p"
	.string "Está bien oír alabanzas sobre tu\n"
	.string "ciudad, pero también da un poco\l"
	.string "de vergüenza.$"

SaffronCity_Text_Sign:
	.string "CIUDAD AZAFRÁN\n"
	.string "La brillante y dorada tierra\l"
	.string "del comercio.$"

SaffronCity_Text_GymSign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD AZAFRÁN: SABRINA\p"
	.string "Maestra de los POKéMON\n"
	.string "psíquicos.$"

SaffronCity_Text_FightingDojoSign:
	.string "PUERTAS ABIERTAS:\n"
	.string "DOJO KARATE$"

SaffronCity_Text_SilphCoSign:
	.string "SILPH S.A.\n"
	.string "EDIFICIO CENTRAL$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "CASA DEL SR. PSÍQUICO$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "ESTACIÓN DEL MAGNETOTRÉN DE\n"
	.string "CIUDAD AZAFRÁN$"
