BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
	.string "Soy DÉBORA.\p"
	.string "La mejor maestra dragón del mundo.\p"
	.string "Puedo plantar cara incluso al\n"
	.string "ALTO MANDO de la LIGA POKéMON.\p"
	.string "¿Aún así quieres desafiarme?\p"
	.string "…Bien. ¡Adelante!\p"
	.string "Como LÍDER DE GIMNASIO, lucharé\n"
	.string "con todas mis fuerzas.$"

BlackthornGym_Text_ClairWinText:
	.string "¿He perdido?\p"
	.string "No me lo creo. Debe de haber\n"
	.string "algún error…$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
	.string "No pienso aceptarlo.\p"
	.string "Puede que haya perdido, pero aún no\n"
	.string "tienes nivel para la LIGA POKéMON.\p"
	.string "Ya sé. Supera la prueba del clan\n"
	.string "dragón.\p"
	.string "Tras este GIMNASIO se encuentra la\n"
	.string "GUARIDA DRAGÓN.\p"
	.string "Hay un pequeño templo en el centro.\n"
	.string "Ve hasta allí.\p"
	.string "Si demuestras que has abandonado\n"
	.string "tus viejas ideas, te reconoceré\l"
	.string "como un Entrenador digno de una\l"
	.string "MEDALLA.$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
	.string "¿Qué ocurre?\p"
	.string "¿Es demasiado para ti?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
	.string "¡Me has hecho esperar!\p"
	.string "¡Toma esto!$"

BlackthornGym_Text_ClairText_DescribeTM:
	.string "Contiene GARRA DRAGÓN.\p"
	.string "Ya descubrirás lo que hace.$"

BlackthornGym_Text_ClairText_League:
	.string "¿Qué ocurre?\p"
	.string "¿No ibas hacia la LIGA POKéMON?\p"
	.string "¿No sabes dónde está?\p"
	.string "Ve desde aquí a PUEBLO PRIMAVERA.\p"
	.string "Después usa SURF hacia el este.\n"
	.string "La ruta es muy dura.\p"
	.string "¡Ni se te ocurra perder en la\n"
	.string "LIGA POKéMON!\p"
	.string "¡Si pierdes, me sentará aún peor\n"
	.string "haber sido derrotada por ti!\p"
	.string "Dalo todo.$"

BlackthornGym_Text_ClairAfterLeague:
	.string "Lo has conseguido, ¿eh?\p"
	.string "Ahora eres CAMPEÓN de JOHTO.$"

BlackthornGym_Text_ClairRematchText:
	.string "Lo has conseguido, ¿eh?\p"
	.string "Ahora eres CAMPEÓN de JOHTO.\p"
	.string "Has demostrado tu fuerza, pero\n"
	.string "¿podrás volver a derrotarme?\p"
	.string "Como maestra dragón, no me\n"
	.string "contendré.\p"
	.string "Esta vez no.\p"
	.string "¿Quieres una revancha?$"

BlackthornGym_Text_ClairRematchDefeatText:
	.string "¿He perdido?\p"
	.string "¿Otra vez?\p"
	.string "No me lo creo. Debe de haber\n"
	.string "algún error…$"

BlackthornGym_Text_CooltrainermCodySeenText:
	.string "¡Acaban de permitirme usar POKéMON\n"
	.string "de tipo DRAGÓN!$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
	.string "¡Rayos! ¡Si tuviera un DRAGONITE!$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
	.string "Los miembros de nuestro clan solo\n"
	.string "podemos usar POKéMON dragón cuando\l"
	.string "el MAESTRO nos da permiso.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
	.string "¡No puedo dejar pasar a un\n"
	.string "Entrenador cualquiera!\p"
	.string "¡DÉBORA se pondría hecha una furia!$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
	.string "Ay… He perdido…$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
	.string "Vaya… DÉBORA se va a enfadar…$"

BlackthornGym_Text_CooltrainermPaulSeenText:
	.string "¿Es tu primer combate contra\n"
	.string "dragones?\p"
	.string "¡Te mostraré lo fuertes que son!$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
	.string "¿Mis POKéMON dragón han perdido?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
	.string "¿LANCE dijo que quiere volver a\n"
	.string "verte?\p"
	.string "¡Ni lo sueñes!$"

BlackthornGym_Text_CooltrainermMikeSeenText:
	.string "¿Mis probabilidades de perder?\n"
	.string "¡Ni un uno por ciento!$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
	.string "Qué extraño.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
	.string "Ahora conozco mis puntos débiles.\p"
	.string "¡Gracias por mostrármelos!$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
	.string "Los dragones son POKéMON sagrados.\p"
	.string "Rebosan energía vital.\p"
	.string "Si no te lo tomas en serio, no\n"
	.string "podrás derrotarlos.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
	.string "¡Bien hecho!$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
	.string "Los dragones son débiles ante los\n"
	.string "movimientos de tipo DRAGÓN.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
	.string "¡Ey, futuro campeón!\p"
	.string "Ha sido un viaje largo, pero ya\n"
	.string "casi acabamos. ¡Confía en mí!\p"
	.string "DÉBORA admira a LANCE, el Maestro\n"
	.string "Dragón, pero ha creado su propio\l"
	.string "estilo con un equipo de dragones\l"
	.string "procedentes del mar.\p"
	.string "Los dragones son débiles contra\n"
	.string "el tipo HIELO, pero necesitarás\l"
	.string "movimientos de tipo DRAGÓN o HADA\l"
	.string "si quieres ganar.\p"
	.string "¡Tú puedes!$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "¡Has estado genial contra DÉBORA!\p"
	.string "Aunque no sabe perder muy bien…\p"
	.string "Parece que debes ir a la GUARIDA\n"
	.string "DRAGÓN para conseguir la MEDALLA.$"

BlackthornGym_Text_GuideWinText:
	.string "¡Has estado genial contra DÉBORA!\p"
	.string "Ya solo queda el desafío de la\n"
	.string "LIGA POKéMON.\p"
	.string "¡Vas camino de convertirte en\n"
	.string "CAMPEÓN POKéMON!$"

BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE ENDRINO$"

BlackthornGym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE ENDRINO\p"
	.string "ENTRENADORES VICTORIOSOS:\n"
	.string "{PLAYER}$"
