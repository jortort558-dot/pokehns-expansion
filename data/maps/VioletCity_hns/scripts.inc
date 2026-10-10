VioletCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VioletCity_OnFrame::
	map_script_2 VAR_VIOLET_CITY_KIMONO_GIRL, 1, VioletCity_EventScript_Kimono_Girl
	map_script_2 VAR_VIOLET_CITY_STATE, 3, VioletCity_EventScript_ElmCall_Trigger
	.2byte 0

VioletCity_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_OnTransition_ShowRosa
	setflag FLAG_HIDE_VIOLET_ROSA
	end

VioletCity_OnTransition_ShowRosa::
	clearflag FLAG_HIDE_VIOLET_ROSA
	end

VioletCity_EventScript_Trigger::
	@LOCAL FLAGHEAP
	clearflag FLAG_RECEIVED_TOGEPI_EGG
	clearflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	clearflag FLAG_HIDE_SPROUT_TOWER_SILVER
	clearflag FLAG_HIDE_JOHTO_GYM_LEADERS
	clearflag FLAG_HOOH_BROUGHT
	clearflag FLAG_OMANYTE_BROUGHT
	clearflag FLAG_AERODACTYL_BROUGHT
	clearflag FLAG_KABUTO_BROUGHT
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_GOT_HARD_STONE
	clearflag FLAG_GOT_POISON_BARB
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_GOT_BLACK_GLASSES
	
	setvar VAR_SLOWPOKE_TAIL, 0
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 0
	setvar VAR_RUINSOFALPH_STATE, 0
	
	setflag FLAG_ITEM_GS_BALL
	setflag FLAG_ITEM_DOME_FOSSIL
	setflag FLAG_ITEM_HELIX_FOSSIL
	setflag FLAG_ITEM_OLD_AMBER
	setflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_VISITED_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	
	setvar VAR_SPROUT_TOWER, 0
	setvar VAR_VIOLET_CITY_STATE, 1
	end

VioletCity_EventScript_Earl::
	lock
	faceplayer
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	faceplayer
	msgbox VioletCity_Text_EarlAsksIfYouBeatFalkner, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_EarlTrainerSchool
	msgbox VioletCity_Text_VeryNiceIndeed, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_EarlTrainerSchool::
	msgbox VioletCity_Text_FollowEarl, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	switch VAR_FACING
	case DIR_NORTH, VioletCity_EventScript_EarlTrainerSchoolSouth
	case DIR_WEST, VioletCity_EventScript_EarlTrainerSchoolEast
	release
	end

VioletCity_EventScript_EarlTrainerSchoolSouth::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_South_Adjustment
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_South_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolEast::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_East_Adjustment
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_East_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolTransition:
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Walk_To_School
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Walk_To_School
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	turnobject LOCALID_VIOLETCITY_EARL, DIR_WEST
	msgbox VioletCity_Text_HereTeacherIAm, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Walk_Inside
	delay 20
	opendoor 39, 36
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_VIOLET_CITY_EARL
	removeobject LOCALID_VIOLETCITY_EARL
	closedoor 39, 36
	waitdooranim
	clearflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	fadedefaultbgm
	release
	end

VioletCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox VioletCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Boy::
	lock
	faceplayer
	msgbox VioletCity_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox VioletCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Gustal::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_GustalSolved
	msgbox VioletCity_Text_GustalHint, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_GustalSolved::
	msgbox VioletCity_Text_GustalSolved, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_Maelle::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_MaelleSolved
	msgbox VioletCity_Text_MaelleHint, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_MaelleSolved::
	msgbox VioletCity_Text_MaelleSolved, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_Verson::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_VersonSolved
	msgbox VioletCity_Text_VersonHint, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_VersonSolved::
	msgbox VioletCity_Text_VersonSolved, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampAcademy::
	lock
	goto_if_unset FLAG_BADGE04_GET, VioletCity_EventScript_LampDormant
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_LampSolved
	goto_if_eq VAR_VIOLET_LAMP_SEQUENCE, 0, VioletCity_EventScript_LampAcademyFirst
	goto_if_eq VAR_VIOLET_LAMP_SEQUENCE, 1, VioletCity_EventScript_LampAcademySecond
	goto VioletCity_EventScript_LampWrong

VioletCity_EventScript_LampAcademyFirst::
	setvar VAR_VIOLET_LAMP_SEQUENCE, 1
	goto VioletCity_EventScript_LampCorrect

VioletCity_EventScript_LampAcademySecond::
	setvar VAR_VIOLET_LAMP_SEQUENCE, 2
	goto VioletCity_EventScript_LampCorrect

VioletCity_EventScript_LampCanal::
	lock
	goto_if_unset FLAG_BADGE04_GET, VioletCity_EventScript_LampDormant
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_LampSolved
	goto_if_eq VAR_VIOLET_LAMP_SEQUENCE, 2, VioletCity_EventScript_LampCanalCorrect
	goto VioletCity_EventScript_LampWrong

VioletCity_EventScript_LampCanalCorrect::
	setvar VAR_VIOLET_LAMP_SEQUENCE, 3
	goto VioletCity_EventScript_LampCorrect

VioletCity_EventScript_LampTower::
	lock
	goto_if_unset FLAG_BADGE04_GET, VioletCity_EventScript_LampDormant
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_LampSolved
	goto_if_eq VAR_VIOLET_LAMP_SEQUENCE, 3, VioletCity_EventScript_LampComplete
	goto VioletCity_EventScript_LampWrong

VioletCity_EventScript_LampCorrect::
	playse SE_PIN
	msgbox VioletCity_Text_LampCorrect, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampWrong::
	setvar VAR_VIOLET_LAMP_SEQUENCE, 0
	playse SE_FAILURE
	msgbox VioletCity_Text_LampWrong, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampComplete::
	setvar VAR_VIOLET_LAMP_SEQUENCE, 4
	setflag FLAG_VIOLET_LAMP_PUZZLE_SOLVED
	clearflag FLAG_HIDE_VIOLET_ROSA
	playse SE_M_PETAL_DANCE
	special DoSealedChamberShakingEffect_Short
	waitstate
	msgbox VioletCity_Text_LampComplete, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampDormant::
	msgbox VioletCity_Text_LampDormant, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampSolved::
	msgbox VioletCity_Text_LampSolved, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_LampInactive::
	lock
	msgbox VioletCity_Text_LampInactive, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_SecretCaveEntrance::
	lockall
	goto_if_set FLAG_VIOLET_LAMP_PUZZLE_SOLVED, VioletCity_EventScript_SecretCaveOpen
	msgbox VioletCity_Text_SecretCaveClosed, MSGBOX_DEFAULT
	releaseall
	end

VioletCity_EventScript_SecretCaveOpen::
	msgbox VioletCity_Text_SecretCaveOpen, MSGBOX_DEFAULT
	releaseall
	end

VioletCity_Text_GustalHint:
	.string "Somos de CIUDAD LUMINALIA,\n"
	.string "en la bella región de KALOS.\p"
	.string "Mi expedición sigue el 33:\n"
	.string "la tercera luz, dos veces.\p"
	.string "Aquí la tercera es la que\n"
	.string "vigila la ACADEMIA.$"

VioletCity_Text_GustalSolved:
	.string "Has trazado tu propio lienzo.\n"
	.string "Expedición MALVA 33...\l"
	.string "Suena bastante elegante.$"

VioletCity_Text_MaelleHint:
	.string "Después del 33 viene el trazo.\n"
	.string "Busca la luz cuyo reflejo\l"
	.string "tiembla sobre el canal.$"

VioletCity_Text_MaelleSolved:
	.string "Ni el Gommage habría borrado\n"
	.string "una secuencia tan limpia.$"

VioletCity_Text_VersonHint:
	.string "El último Chroma duerme junto\n"
	.string "a la torre que araña el cielo.\p"
	.string "Academia dos veces, canal\n"
	.string "y finalmente la torre.$"

VioletCity_Text_VersonSolved:
	.string "El Monolito habría respondido\n"
	.string "con una nota menos alegre.$"

VioletCity_Text_LampDormant:
	.string "La lámpara está cubierta por\n"
	.string "una humedad extraña.$"

VioletCity_Text_LampCorrect:
	.string "La lámpara absorbe un destello\n"
	.string "de Chroma y queda encendida.$"

VioletCity_Text_LampWrong:
	.string "La luz parpadea y se apaga.\n"
	.string "La secuencia se ha reiniciado.$"

VioletCity_Text_LampComplete:
	.string "Las luces forman un 33.\n"
	.string "Algo se abre al norte de MALVA.$"

VioletCity_Text_LampSolved:
	.string "La lámpara conserva un brillo\n"
	.string "de Chroma permanente.$"

VioletCity_Text_LampInactive:
	.string "Esta lámpara no reacciona.\n"
	.string "No forma parte del lienzo.$"

VioletCity_Text_SecretCaveClosed:
	.string "Las piedras encajan sin dejar\n"
	.string "ninguna entrada visible.$"

VioletCity_Text_SecretCaveOpen:
	.string "Las piedras se han separado.\n"
	.string "Un túnel inundado desciende,\l"
	.string "pero aún no puede explorarse.$"

VioletCity_EventScript_Pichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Pichu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Bellsprout::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Bellsprout, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Rattata, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_ElmCall_Trigger::
	lock
	setspeaker VioletCity_Text_ElmName
	pokenavcall VioletCity_Text_Elm_Call
	waitmessage
	delay 30
	clearflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	setvar VAR_VIOLET_CITY_STATE, 4
	release
	end

VioletCity_EventScript_Kimono_Girl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	playse SE_PIN
	applymovement LOCALID_VIOLET_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_VIOLET_KIMONO
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_1
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_2
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_3
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_4
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_5
	waitmovement 0
	fadedefaultbgm
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 2
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	removeobject LOCALID_VIOLET_KIMONO
	release
	end


VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VioletCity_EventScript_ItemPechaBerry::
	finditem ITEM_PECHA_BERRY
	end

VioletCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

VioletCity_Movement_Earl_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

VioletCity_Movement_Earl_East_Adjustment:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VioletCity_Movement_Player_East_Adjustment:
	walk_down
	walk_down
	walk_left
	walk_down
	face_right
	step_end

VioletCity_Movement_Earl_South_Adjustment:
	walk_right
	walk_down
	walk_down
	walk_down
	face_right
	step_end

VioletCity_Movement_Player_South_Adjustment:
	walk_down
	walk_down
	step_end

VioletCity_Movement_Walk_To_School:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

VioletCity_Movement_Walk_To_School_Player:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VioletCity_Movement_Earl_Walk_Inside:
	walk_up
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_1:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

VioletCity_Movement_Kimono_Girl_2:
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_3:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

VioletCity_Movement_Kimono_Girl_4:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	step_end

VioletCity_Movement_Kimono_Girl_5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end	

VioletCity_EventScript_LiquidJustice::
	msgbox VioletCity_Text_LiquidJustice, MSGBOX_NPC
	end

VioletCity_EventScript_GymSign::
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
	end

VioletCity_Text_LiquidJustice:
	.string "¡Mira a tu alrededor!\p"
	.string "Es facilísimo ver qué POKéMON hay\n"
	.string "en la zona sin pasarte el día dando\l"
	.string "vueltas por la hierba alta.$"

VioletCity_Text_EarlAsksIfYouBeatFalkner:
	.string "¡Hola!\n"
	.string "¿Entrenador ser tú?\p"
	.string "¿Luchar contra LÍDER DE GIMNASIO\n"
	.string "y ganar tú lograste?$"

VioletCity_Text_VeryNiceIndeed:
	.string "¡Ooh, la la!\n"
	.string "¡Maravilloso ser de verdad!$"

VioletCity_Text_FollowEarl:
	.string "¿Eso ser verdad? ¡Entonces estudiar\n"
	.string "deberás! ¡Seguirme a mí!$"

VioletCity_Text_HereTeacherIAm:
	.string "Aquí, profesor ser yo.\n"
	.string "¡Muy bueno ser que estudies aquí!$"

VioletCity_Text_Lass:
	.string "Dicen que aparecen fantasmas\n"
	.string "en la TORRE BELLSPROUT.\p"
	.string "Los movimientos de tipo FANTASMA\n"
	.string "pueden atravesar las defensas de\l"
	.string "POKéMON duros como ONIX y GEODUDE.$"

VioletCity_Text_Boy:
	.string "¡Ey! ¿Eres entrenador?\p"
	.string "¡Si vas a la ACADEMIA, seguro que\n"
	.string "aprendes algo nuevo!$"

VioletCity_Text_Gramps:
	.string "¡PEGASO, el LÍDER del GIMNASIO,\n"
	.string "es un gran entrenador!\p"
	.string "Heredó el gimnasio de su padre\n"
	.string "y está haciendo un trabajo genial.$"

VioletCity_Text_Youngster:
	.string "¡He visto un árbol que se menea\n"
	.string "más adelante!\p"
	.string "¡Si lo tocas, se retuerce y baila!\n"
	.string "¡Mola un montón!$"

VioletCity_Text_Sign:
	.string "CIUDAD MALVA\p"
	.string "La Ciudad de los Aromas Nostálgicos$"

VioletCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE CIUDAD MALVA\p"
	.string "LÍDER: PEGASO\n"
	.string "Elegante maestro de los POKéMON\l"
	.string "voladores$"

VioletCity_Text_SproutTowerSign:
	.string "TORRE BELLSPROUT\p"
	.string "Vive la senda de los POKéMON$"

VioletCity_Text_EarlsAcademySign:
	.string "ACADEMIA POKéMON DE EARL$"

VioletCity_Text_Pichu:
	.string "PICHU: ¡Chuuuu!$"

VioletCity_Text_Bellsprout:
	.string "BELLSPROUT: ¡Sprouuuut!$"

VioletCity_Text_Rattata:
	.string "RATTATA: ¡RATTATARATTA!$"

VioletCity_Text_ElmName:
	.string "PROF.ELM$"

VioletCity_Text_Elm_Call:
	.string "PROF. ELM: ¿Hola, {PLAYER}?\n"
	.string "¡Hemos descubierto algo importante\l"
	.string "sobre el HUEVO!\p"
	.string "Mi ayudante te espera en el\n"
	.string "CENTRO POKéMON de CIUDAD MALVA.\p"
	.string "¿Podrías pasarte a hablar con él?$"

VioletCity_Text_Kimono_Girl1:
.string "¡Madre del amor hermoso…!\n"
.string "¡Ese HUEVO debe ser…!$"

VioletCity_Text_Kimono_Girl2:
.string "Comprendo…\p"
.string "Así que pasó del SR. POKéMON al\n"
.string "PROF. ELM, y de él a tus manos.\p"
.string "Ahora todo encaja…$"

VioletCity_Text_Kimono_Girl3:
.string "Ese HUEVO es realmente importante.\p"
.string "Por favor, cuídalo muy bien.\n"
.string "¿Entendido?$"

VioletCity_Text_Kimono_Girl4:
.string "Confío plenamente en ti.$"

VioletCity_EventScript_Rosa::
	lock
	faceplayer
	callnative GetDailyRosaChallengeInfo
	goto_if_set FLAG_DAILY_ROSA_CHALLENGE_WON, VioletCity_EventScript_RosaAlreadyWon
	goto_if_set FLAG_DAILY_ROSA_CHALLENGE_ATTEMPTED, VioletCity_EventScript_RosaAlreadyAttempted
	msgbox VioletCity_Text_RosaIntro, MSGBOX_DEFAULT
	call VioletCity_EventScript_RosaDisplayHint
	msgbox VioletCity_Text_RosaAskBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_RosaDecline
	msgbox VioletCity_Text_RosaAccept, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DAILY_ROSA_CHALLENGE_ATTEMPTED
	switch VAR_0x8005
	case 0, VioletCity_EventScript_RosaBattle0
	case 1, VioletCity_EventScript_RosaBattle1
	case 2, VioletCity_EventScript_RosaBattle2
	case 3, VioletCity_EventScript_RosaBattle3
	case 4, VioletCity_EventScript_RosaBattle4
	case 5, VioletCity_EventScript_RosaBattle5
	case 6, VioletCity_EventScript_RosaBattle6
	case 7, VioletCity_EventScript_RosaBattle7
	case 8, VioletCity_EventScript_RosaBattle8
	case 9, VioletCity_EventScript_RosaBattle9
	case 10, VioletCity_EventScript_RosaBattle10
	case 11, VioletCity_EventScript_RosaBattle11
	case 12, VioletCity_EventScript_RosaBattle12
	case 13, VioletCity_EventScript_RosaBattle13
	goto VioletCity_EventScript_RosaBattle0
	end

VioletCity_EventScript_RosaBattle0::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_0_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle1::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_1_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle2::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_2_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle3::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_3_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle4::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_4_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle5::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_5_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle6::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_6_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle7::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_7_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle8::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_8_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle9::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_9_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle10::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_10_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle11::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_11_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle12::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_12_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaBattle13::
	trainerbattle_no_intro TRAINER_ROSA_CHALLENGE_13_HNS, VioletCity_Text_RosaDefeat
	goto VioletCity_EventScript_RosaPostBattle
	end

VioletCity_EventScript_RosaPostBattle::
	setflag FLAG_DAILY_ROSA_CHALLENGE_WON
	msgbox VioletCity_Text_RosaReward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	msgbox VioletCity_Text_RosaWonFinal, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_RosaAlreadyWon::
	msgbox VioletCity_Text_RosaAlreadyWon, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_RosaAlreadyAttempted::
	msgbox VioletCity_Text_RosaAlreadyAttempted, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_RosaDecline::
	msgbox VioletCity_Text_RosaDecline, MSGBOX_DEFAULT
	release
	end

VioletCity_EventScript_RosaDisplayHint::
	switch VAR_0x8005
	case 0, VioletCity_EventScript_RosaHint0
	case 1, VioletCity_EventScript_RosaHint1
	case 2, VioletCity_EventScript_RosaHint2
	case 3, VioletCity_EventScript_RosaHint3
	case 4, VioletCity_EventScript_RosaHint4
	case 5, VioletCity_EventScript_RosaHint5
	case 6, VioletCity_EventScript_RosaHint6
	case 7, VioletCity_EventScript_RosaHint7
	case 8, VioletCity_EventScript_RosaHint8
	case 9, VioletCity_EventScript_RosaHint9
	case 10, VioletCity_EventScript_RosaHint10
	case 11, VioletCity_EventScript_RosaHint11
	case 12, VioletCity_EventScript_RosaHint12
	case 13, VioletCity_EventScript_RosaHint13
	return

VioletCity_EventScript_RosaHint0::
	msgbox VioletCity_Text_RosaHint0, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint1::
	msgbox VioletCity_Text_RosaHint1, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint2::
	msgbox VioletCity_Text_RosaHint2, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint3::
	msgbox VioletCity_Text_RosaHint3, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint4::
	msgbox VioletCity_Text_RosaHint4, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint5::
	msgbox VioletCity_Text_RosaHint5, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint6::
	msgbox VioletCity_Text_RosaHint6, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint7::
	msgbox VioletCity_Text_RosaHint7, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint8::
	msgbox VioletCity_Text_RosaHint8, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint9::
	msgbox VioletCity_Text_RosaHint9, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint10::
	msgbox VioletCity_Text_RosaHint10, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint11::
	msgbox VioletCity_Text_RosaHint11, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint12::
	msgbox VioletCity_Text_RosaHint12, MSGBOX_DEFAULT
	return

VioletCity_EventScript_RosaHint13::
	msgbox VioletCity_Text_RosaHint13, MSGBOX_DEFAULT
	return

VioletCity_Text_RosaIntro:
	.string "ROSA: ¡Hola! Soy ROSA,\n"
	.string "LA ESTRATEGA.\p"
	.string "Tras completar el enigma de\n"
	.string "KALOS, he venido a probar a\l"
	.string "entrenadores de élite.\p"
	.string "Cada día entreno con un arquetipo\n"
	.string "competitivo de alto nivel.\p"
	.string "Solo tienes una oportunidad al día\n"
	.string "para derrotarme, pero no temas:\l"
	.string "las derrotas aquí no son fatales.$"

VioletCity_Text_RosaAskBattle:
	.string "¿Te atreves a medirte a mi\n"
	.string "estrategia de hoy?$"

VioletCity_Text_RosaAccept:
	.string "¡Excelente! ¡Demuéstrame el nivel\n"
	.string "de tu preparación!$"

VioletCity_Text_RosaDecline:
	.string "Entendido. Vuelve cuando sientas\n"
	.string "que tu equipo está listo.$"

VioletCity_Text_RosaDefeat:
	.string "¡Impresionante despliegue!\n"
	.string "Has quebrado mi esquema táctico.$"

VioletCity_Text_RosaReward:
	.string "Una victoria impecable.\n"
	.string "Te has ganado esta recompensa.$"

VioletCity_Text_RosaWonFinal:
	.string "Mañana prepararé una táctica\n"
	.string "diferente. ¡Te esperaré!$"

VioletCity_Text_RosaAlreadyWon:
	.string "ROSA: ¡Ya has superado el reto\n"
	.string "de hoy con honores!\p"
	.string "Vuelve mañana para enfrentarte a\n"
	.string "un nuevo arquetipo.$"

VioletCity_Text_RosaAlreadyAttempted:
	.string "ROSA: Ya has combatido hoy.\p"
	.string "La disciplina exige estudiar los\n"
	.string "errores antes del próximo reto.\p"
	.string "¡Vuelve mañana para intentarlo!$"

VioletCity_Text_RosaHint0:
	.string "Pista táctica de hoy:\n"
	.string "¡Lluvia incesante y atacantes\l"
	.string "veloces bajo el agua!$"

VioletCity_Text_RosaHint1:
	.string "Pista táctica de hoy:\n"
	.string "¡Sol abrasador, clorofila y\l"
	.string "poderosas bestias del pasado!$"

VioletCity_Text_RosaHint2:
	.string "Pista táctica de hoy:\n"
	.string "¡Arena asfixiante, desgastes y\l"
	.string "topos veloces entre el polvo!$"

VioletCity_Text_RosaHint3:
	.string "Pista táctica de hoy:\n"
	.string "¡Nieve glacial, Velo Aurora y\l"
	.string "ofensiva contundente de hielo!$"

VioletCity_Text_RosaHint4:
	.string "Pista táctica de hoy:\n"
	.string "¡Espacio Raro! Los más lentos\l"
	.string "golpearán primero con furia.$"

VioletCity_Text_RosaHint5:
	.string "Pista táctica de hoy:\n"
	.string "¡Hiperofensiva tras pantallas!\n"
	.string "Cuidado con los potenciadores.$"

VioletCity_Text_RosaHint6:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo Eléctrico y la implacable\l"
	.string "maquinaria del futuro!$"

VioletCity_Text_RosaHint7:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo Psíquico! La Fuerza\n"
	.string "Expansiva arrasará todo a su paso.$"

VioletCity_Text_RosaHint8:
	.string "Pista táctica de hoy:\n"
	.string "¡Campo de Hierba y ataques de\l"
	.string "prioridad implacables!$"

VioletCity_Text_RosaHint9:
	.string "Pista táctica de hoy:\n"
	.string "¡Muro defensivo supremo!\n"
	.string "Desgaste, púas y regeneración.$"

VioletCity_Text_RosaHint10:
	.string "Pista táctica de hoy:\n"
	.string "¡Velocidad extrema y prioridad pura!\n"
	.string "Atacantes letales de remate.$"

VioletCity_Text_RosaHint11:
	.string "Pista táctica de hoy:\n"
	.string "¡Estructura de campeonato!\n"
	.string "Intimidación doble y control.$"

VioletCity_Text_RosaHint12:
	.string "Pista táctica de hoy:\n"
	.string "¡Relevo y aumentos de poder!\n"
	.string "Una cadena táctica coordinada.$"

VioletCity_Text_RosaHint13:
	.string "Pista táctica de hoy:\n"
	.string "¡Especial Festivo Navideño!\n"
	.string "Espíritu invernal y estrellas.$"

