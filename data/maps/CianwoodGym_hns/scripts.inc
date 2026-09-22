CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD ORQUÍDEA$"
CianwoodGym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD ORQUÍDEA\nENTRENADORES CERTIFICADOS POR\lANÍBAL:\l{PLAYER}$"
CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "¡JAJAJAJA, {PLAYER}!\n¡Estoy en pleno entrenamiento!\pSi quieres otra revancha, ¡pásate\npor\lel DOJO de COMBATE en AZAFRÁN!$"
CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "¡Nos veremos en el DOJO!\n¡JAJAJAJAJAJAJA!$"
CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "¡JAJAJA!\p¡Conque has llegado hasta aquí!\p¡Te advierto que soy duro de pelar!\p¡Mis POKéMON rompen piedras y\nquiebran\lhuesos con un solo golpe!\p¡Fíjate en esto!$"
CianwoodGym_Text_ChuckIntro2:
	.string "ANÍBAL: ¡Uaaargh!\n…\n¡¡¡Yaaaaaargh!!!$"
CianwoodGym_Text_ChuckIntro3:
	.string "¡Toma ya! ¿Asustado, eh?\p¿Qué? ¿Que eso no tiene nada que\nver con\llos POKéMON?\p¡Bueno, en eso tienes razón!\p¡Al turrón! ¡Que empiece el\ncombate!$"
CianwoodGym_Text_ChuckLoss:
	.string "¿C-cómo? ¿Que he perdido?\p¡Vaya sorpresa!\n¡Eres digno de la MEDALLA TORMENTA!$"
CianwoodGym_Text_GetStormBadge:
	.string "¡{PLAYER} recibió la MEDALLA TORMENTA!$"
CianwoodGym_Text_ChuckBadgeSpeech:
	.string "La MEDALLA TORMENTA hace que todos\nlos\lPOKéMON hasta nivel 70 te\lobedezcan,\lincluso los intercambiados.\pAdemás, permite a tus POKéMON usar\nVUELO fuera del combate.\p¡Toma, quédate con esto también!$"
CianwoodGym_Text_ChuckTMSpeech:
	.string "Eso es PUÑO CERTERO.\nSe prepara despacio, pero causa un\ldaño\ldevastador. ¡Solo procura que no te\lgolpeen primero!$"
CianwoodGym_Text_ChuckAfter:
	.string "¡JAJAJA! ¡He disfrutado muchísimo\ncon\lnuestro combate!\p¡Pero una derrota es una derrota!\p¡A partir de ahora pienso entrenar\nlas\l24 horas del día!$"
CianwoodGym_Text_ChuckRematch:
	.string "¡JAJAJA! ¡CAMPEÓN DE JOHTO!\n¡Has vuelto con ganas de más\lmarcha!\p¡Veo que tus habilidades han\nmejorado!\l¿Listo para ver quién es más\lfuerte?$"
CianwoodGym_Text_ChuckRematchDefeat:
	.string "¿C-cómo? ¿He vuelto a perder?\n¿Otra vez?$"
CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "A mis POKéMON y a mí nos une un\nlazo de\lverdadera amistad.\p¡Nuestro vínculo jamás se romperá!$"
CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "¡Esto no puede ser real!$"
CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "¡Parece que tú también tienes un\nlazo\linquebrantable con tus POKéMON!$"
CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "¡Los maestros de artes marciales no\nle\ltenemos miedo a nada!$"
CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "¡Qué sorpresa!$"
CianwoodGym_Text_BlackbeltLaoAfter:
	.string "A los POKéMON de LUCHA les dan\npavor\llos psíquicos…$"
CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Las palabras sobran.\n¡Deja que tus puños hablen por ti!$"
CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"
CianwoodGym_Text_BlackbeltNobAfter:
	.string "¡He perdido! ¡Me has dejado sin\npalabras!$"
CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "¡Mis puños demoledores harán trizas\na tus POKéMON!$"
CianwoodGym_Text_BlackbeltLungBeaten:
	.string "¡Me han hecho trizas a mí!$"
CianwoodGym_Text_BlackbeltLungAfter:
	.string "Mis POKéMON han perdido…\nMi... mi orgullo está hecho\lpedazos…$"
