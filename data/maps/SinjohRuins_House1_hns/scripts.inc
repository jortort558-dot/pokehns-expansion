SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
   	.string "MÁXIMO: ¿Hum?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Reconocería esa mirada en cualquier\n"
	.string "lugar del mundo.\p"
	.string "¿Qué te trae tan al norte?\p"
	.string ".............\p"
	.string "Ya veo... Las CHICAS KIMONO de\n"
	.string "NUEVO SINJOH te enviaron para\l"
	.string "ayudarnos en la investigación.\p"
	.string "En ese caso, permíteme ponerte al\n"
	.string "corriente de la situación.$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "MÁXIMO: En cuanto oí hablar de\n"
	.string "estas ruinas, tuve que venir a\l"
	.string "verlas por mí mismo cuanto antes.\p"
	.string "Formé un equipo en DEVON S.A. y nos\n"
	.string "embarcamos en esta expedición.\p"
	.string "Quién sabe lo que podremos llegar a\n"
	.string "encontrar enterrado aquí.\p"
	.string "De hecho, ya hemos descubierto\n"
	.string "bastantes cosas fascinantes.$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "LINGÜISTA: Aunque la traducción\n"
	.string "de los glifos de las ruinas se me\l"
	.string "resiste, he logrado descifrar\l"
	.string "algunos detalles importantes.\p"
	.string "Existen 17 peculiares TABLAS.\p"
	.string "Tienen un significado crucial para\n"
	.string "las ruinas, pero hasta ahora solo\l"
	.string "hemos encontrado una.\p"
	.string "Se dice que el resto las custodian\n"
	.string "POKéMON y entrenadores poseedores\l"
	.string "de un poder abrumador.$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "MÁXIMO: Esa es la historia,\n"
	.string "{PLAYER}.\p"
	.string "Los POKéMON SEÑORIALES que guardan\n"
	.string "las demás TABLAS son demasiado para\l"
	.string "mi equipo, me temo.\p"
	.string "Y yo debo permanecer aquí para\n"
	.string "dirigir la investigación in situ.\p"
	.string "Pero estoy seguro de que tú sí\n"
	.string "podrás. ¿Nos prestarás tu ayuda?$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "¡Excelente!\p"
	.string "Los glifos revelan que las TABLAS\n"
	.string "están en manos de SEÑORIALES y de\l"
	.string "grandes entrenadores de SINJOH.\p"
	.string "Te llamaré al POKéGEAR si logramos\n"
	.string "descubrir algo nuevo.\p"
	.string "¡Muchísimas gracias, {PLAYER}!$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "¿De verdad estás seguro?\p"
	.string "Quién sabe lo que podremos llegar a\n"
	.string "encontrar enterrado aquí.\p"
	.string "¿No te lo replantearías?$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Creo que ya sé lo que va a suceder\n"
	.string "en cuanto reunamos las 17 TABLAS.\p"
	.string "Siento que...\l"
	.string ".....................$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "MÁXIMO: ¡Tengo que presenciar esto\n"
	.string "con mis propios ojos!\p"
	.string "¡Afuera, {PLAYER}!$" 

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "Llevas {STR_VAR_1} TABLAS reunidas.\n"
	.string "Nada mal, desde luego.\p"
	.string "Admito que tengo mucha curiosidad\n"
	.string "por ver qué ocurrirá cuando estén\l"
	.string "todas juntas.\p"
	.string "En fin, veamos qué logras hallar.$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "Llevas {STR_VAR_1} TABLAS reunidas.\n"
	.string "Nada mal, desde luego.\p"
	.string "¿Has investigado ya esa cámara?\l"
	.string "Todo esto es sumamente misterioso.$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "Llevas {STR_VAR_1} TABLAS reunidas.\n"
	.string "Un avance sensacional.\p"
	.string "Las cámaras que se han ido abriendo\n"
	.string "guardan una semejanza asombrosa con\l"
	.string "una serie de cámaras de HOENN.\p"
	.string "Cada una de ellas era también el\n"
	.string "hogar de un POKéMON legendario.\p"
	.string "Pero en HOENN solo llegamos a\n"
	.string "descubrir tres.\p"
	.string "Y aquí parece haber al menos seis.\p"
	.string "Quién sabe qué encontraremos luego.$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Esta expedición ha sido una de\n"
	.string "las mayores experiencias vividas.\p"
	.string "Desde que oí hablar de estas\n"
	.string "ruinas, tuve una corazonada.\p"
	.string "Sabía que descubriríamos algo\n"
	.string "maravilloso aquí.\p"
	.string "Y mis predicciones no fallan.\p"
	.string "Muchísimas gracias por toda tu\n"
	.string "ayuda, campeón.\p"
	.string "¿Hacia dónde te llevará tu viaje?\p"
	.string "Espero que podamos coincidir\n"
	.string "en algún rincón del mundo.$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
    .string "El radar de penetración terrestre\n"
	.string "muestra 6 cámaras subterráneas en\l"
	.string "este valle.\p"
	.string "Cinco parecen estar cerca de la\n"
	.string "superficie, y una a mucha mayor\l"
	.string "profundidad.$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "¡Todo este tiempo apuntando el\n"
	.string "radar hacia el suelo para escanear\l"
	.string "las profundidades!\p"
	.string "¡Cuando claramente debí haberlo\n"
	.string "apuntado hacia arriba!$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "¿Esas TABLAS estaban relacionadas\n"
	.string "con el POKéMON más poderoso?\p"
	.string "Ojalá hubiera tenido más tiempo\n"
	.string "para estudiarlas detenidamente.$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
    .string "Ufff....\n"
	.string "Hay demasiados glifos...\p"
	.string "No tenemos nada parecido a esto\n"
	.string "en la región de HOENN.$"
SinjohRuins_Lab_Text_LinguistDuring:
    .string "¡Imagínate mi sorpresa al traducir\n"
	.string "el glifo!\p"
	.string "¡Lo revisé varias veces antes de\n"
	.string "atreverme a decírselo a MÁXIMO!\p"
	.string "O sea, ¿el auténtico creador de\n"
	.string "los POKéMON?\p"
	.string "Es sobrecogedor.$"
SinjohRuins_Lab_Text_LinguistAfter:
    .string "Esta expedición ha sido una gran\n"
	.string "maravilla, {PLAYER}.\p"
	.string "Gracias por encargarte de todo el\n"
	.string "trabajo de campo.$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "La existencia de civilización aquí\n"
    .string "cambia radicalmente nuestra visión\l"
	.string "de la historia.\p"
	.string "Muchos de los objetos hallados\n"
	.string "tienen más de mil años de edad.\p"
	.string "La datación por carbono coincide\n"
	.string "con reliquias de SINNOH.\p"
	.string "Aunque esa flauta tuya...\n"
	.string "parece ser muchísimo más antigua.$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Esas tablas...\n"
	.string "La conexión con SINNOH...\l"
	.string "Esa flauta ancestral....\l"
	.string "Todo empieza a encajar bien.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "El valor histórico de lo que has\n"
	.string "ayudado a desenterrar aquí es\l"
	.string "incalculable, {PLAYER}.\p"
	.string "De verdad, muchísimas gracias.$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "¡¡Grrrowh owh!!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
    .string "Parece ser la Poké Ball de\n"
	.string "Growlithe. Dejarla en su sitio.$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
    .string "¡Fíjate en este espécimen único!\p"
	.string "Esta especie de GROWLITHE no se\n"
	.string "parece a las de otras regiones.\p"
	.string "El análisis genético revela un\n"
	.string "ancestro común con los GROWLITHE.\p"
	.string "Sin embargo, su temperamento y sus\n"
	.string "tipos elementales difieren mucho.\p"
	.string "Las descripciones de GROWLITHE en\n"
	.string "antiguos textos de SINNOH cuadran.\p"
	.string "Tal vez esta forma ocupó antaño un\n"
	.string "territorio enorme que se extendía\l"
	.string "hacia el norte.$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Si la criatura en la cima de la\n"
	.string "escalera es en verdad el creador\l"
	.string "de los POKéMON, ¿significa que\l"
	.string "es el primer ancestro de todos?$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "He recopilado una gran cantidad de\n"
	.string "datos sobre formas regionales y\l"
	.string "evolución gracias a esto.\p"
	.string "¡Muchas gracias, {PLAYER}!$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
   	.string "Llevo diez años recorriendo estos\n"
	.string "páramos solitarios.\p"
	.string "O mejor dicho, ¡veinte años!\p"
	.string "Hasta que un día hallé esos\n"
	.string "pilares gigantes y aquel templo.\p"
	.string "Son las RUINAS SINJOH.\n"
	.string "O eso he oído.\p"
	.string "Por entonces no sabía del pueblo.\p"
	.string "Solo se lo comenté a unos colegas,\n"
	.string "pero los rumores corren que vuelan.\p"
	.string "Nunca imaginé que atraería tanta\n"
	.string "atención a la zona.\p"
	.string "Me hace sentir un poco raro.$"
SinjohRuins_Lab_Text_HikerDuringAfter:
   	.string "No se lo digas a nadie...\n"
	.string "Pero yo vi ese templo en la cima\l"
	.string "cuando descubrí este sitio.\p"
	.string "Me lo guardé para mí solito.\p"
	.string "Bastante me fui de la lengua ya con\n"
	.string "el resto de las ruinas.\p"
	.string "Al menos parece que al final todo\n"
	.string "ha salido a pedir de boca.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
    .string "Diario 1: 3 de mayo de 1975\p"
	.string "Hemos llegado a la ubicación\n"
	.string "de las ruinas.\p"
	.string "El gélido frío de Mt. Plateado\n"
	.string "se deja sentir hasta aquí abajo...\p"
	.string "Pronto el equipo principal de\n"
	.string "excavación cruzará la montaña...\p"
	.string "¡Me muero por descubrir qué nos\n"
	.string "aguarda bajo nuestros pies!$"

SinjohRuins_Lab_Text_Note2:
    .string "Diario 2: 10 de mayo de 1975\p"
	.string "Una semana de excavaciones y\n"
	.string "ningún resultado en absoluto.\p"
	.string "El hielo aquí es muy grueso, y\n"
	.string "la roca destruye por completo\l"
	.string "nuestras herramientas.\p"
	.string "Ni siquiera MACHAMP logró hacerle\n"
	.string "el menor rasguño.\p"
	.string "¿Qué es este lugar?\p"
	.string "Tenemos que averiguarlo.$"

SinjohRuins_Lab_Text_Note3:
    .string "Diario 3: 14 de mayo de 1975\p"
	.string "Uno no sale adelante en la vida\n"
	.string "quedándose de brazos cruzados.\p"
	.string "Solo soy un simple obrero.\p"
	.string "Pero se me ocurrió cómo podríamos\n"
	.string "atravesar el hielo.\p"
	.string "O mejor dicho, cómo derretirlo.\p"
	.string "Necesitamos POKéMON de tipo FUEGO,\n"
	.string "y muchos de ellos.\p"
	.string "¿Pero cómo los traeremos hasta aquí\n"
	.string "desde SINNOH?$"

SinjohRuins_Lab_Text_Note4:
    .string "Diario 4: 21 de mayo de 1975\p"
	.string "Hemos tenido días intensos.\p"
	.string "Mi idea para perforar el hielo\n"
	.string "funcionó. Solo que no trajimos los\l"
	.string "de tipo FUEGO desde nuestra tierra.\p"
	.string "El jefe insistió en cogerlos aquí.\p"
	.string "Encontramos unas termas junto a\n"
	.string "una aldea cercana...\p"
	.string "Y nos llevamos lo necesario...\p"
	.string "No me enorgullece en absoluto.\n"
	.string "Pero el progreso pide sacrificios.\p"
	.string "El caso: el hielo desapareció.\p"
	.string "Hay 6 cámaras y un templo sellado\n"
	.string "en el centro.\p"
	.string "La arquitectura de la estructura\n"
	.string "indica que podría ser de los\l"
	.string "antiguos celestes...\p"
	.string "Nuestros ancestros. Antes de\n"
	.string "migrar al norte.\p"
	.string "El jefe quiere abrir ese templo lo\n"
	.string "antes posible...$"

SinjohRuins_Lab_Text_Note5:
    .string "Diario 5: 2 de junio de 1975\p"
	.string "Conseguimos abrirlo...\p"
	.string "Creí que saltaría de alegría...\p"
	.string "Pero perdimos a buenos hombres en\n"
	.string "la ráfaga de energía que brotó\l"
	.string "del templo.\p"
	.string "Por no hablar de los POKéMON\n"
	.string "que nos ayudaron a abrirlo.\l"
	.string "Que descansen en paz...\p"
	.string "........................\p"
	.string "Sea como fuere.\p"
	.string "El templo está abierto, pero\n"
	.string "solo nos quedan más preguntas.\p"
	.string "No hay ningún POKéMON legendario\n"
	.string "en su interior. Ningún tesoro.\p"
	.string "Los víveres escasean y no\n"
	.string "tenemos nada que compense nuestros\l"
	.string "esfuerzos...$"

SinjohRuins_Lab_Text_Note6:
  	.string "Diario 6: 10 de junio de 1975\p"
    .string "La expedición ha terminado.\n"
	.string "Los demás hombres recogen todo.\p"
	.string "Pero yo no puedo.\p"
	.string "No puedo abandonar esta misión.\n"
	.string "No después de todo lo que perdimos.\p"
	.string "Me voy a quedar aquí.$"

SinjohRuins_Lab_Text_Note7:
  	.string "Diario 7: 10 de septiembre de 1975\p"
	.string "Han pasado meses desde la llegada.\n"
	.string "Desde que me quedé aquí.\p"
	.string "Los demás hombres ya se fueron.\p"
	.string "Ahora solo quedamos los POKéMON\n"
	.string "que capturamos para las labores\l"
	.string "y yo.\p"
	.string "Los he estado entrenando a fondo\n"
	.string "para hacerlos más fuertes.\p"
	.string "A mi TYPHLOSION, sobre todo.\p"
	.string "Tenemos que descubrir qué se oculta\n"
	.string "bajo el templo.$"

SinjohRuins_Lab_Text_Note8:
  	.string "Diario 8: 15 de septiembre de 1975\p"
	.string "Fracaso total.\p"
	.string "......................\p"
	.string "Mis POKéMON....\p"
	.string "Juntos, mis 6 POKéMON lograron\n"
	.string "derribar un muro falso del templo.\p"
	.string "Pero nos estaba esperando...\p"
	.string "Una especie de titán colosal...\p"
	.string "La energía que desató fue idéntica\n"
	.string "a lo que ocurrió la otra vez.\p"
	.string "Quedaron fulminados...\p"
	.string "Y lo peor de todo: esa bestia\n"
	.string "volvió a sellar el muro.\p"
	.string "Ya no puedo volver a casa.\n"
	.string "Nadie me reconocería ya...\p"
	.string "Este lugar me cambió para siempre.\p"
	.string "Voy a hablar con los de la aldea.\p"
	.string "No saben lo que hice.\p"
	.string "Como los otros se fueron hace\n"
	.string "tiempo, creerán que soy un\l"
	.string "montañero perdido.\p"
	.string "Ya no me queda ningún lugar en el\n"
	.string "mundo más que este.$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
    .string "Una vitrina con muestras de\n"
	.string "minerales y reliquias.$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
   .string "Laboratorio de rayos X e impresión.$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
   .string "¡Es una reliquia encontrada en el\n"
   .string "interior de las ruinas!$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "La FLAUTA AZUR está reaccionando.\n"
	.string "¿Quieres tocar la flauta?$"

SinjohRuins_Lab_Text_DropedItem:
	.string "¡El {STR_VAR_1} SEÑORIAL ha dejado\n"
	.string "caer un objeto!$"

SinjohRuins_Lab_Text_StevenName:
	.string "MÁXIMO$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Acabamos de sentir un temblor\n"
	.string "aquí en las ruinas.\p"
	.string "Todo el mundo está bien, no temas.\p"
	.string "Es asombroso: una cámara bajo\n"
	.string "las ruinas se abrió de par en par.\p"
	.string "Los grabados me recuerdan a algo\n"
	.string "de HOENN.\p"
	.string "Pásate a verla cuando puedas.$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "¿Cómo va la búsqueda?\p"
	.string "Hemos tenido otro temblor aquí.\n"
	.string "Esta vez se abrió otra cámara.\p"
	.string "Le pedí al geólogo que tenga sus\n"
	.string "instrumentos listos por si acaso.\p"
	.string "Cuanto más hondo excavamos...\n"
	.string "más enigmas encontramos.$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Otro temblor más en las ruinas.\p"
	.string "Los datos reflejan un panorama del\n"
	.string "todo intrigante.\p"
	.string "No fue un terremoto en absoluto.\p"
	.string "Una gran energía en el subsuelo\n"
	.string "reventó la roca desde dentro.\p"
	.string "¿Qué podría provocar esto?\n"
	.string "Sinceramente, no tengo ni idea.$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Otro temblor y otra cámara abierta.\p"
	.string "Aún no logramos descifrar el patrón\n"
	.string "detrás del momento en que ocurren.\p"
	.string "Dime, {PLAYER}...\n"
	.string "¿No estarás causando esto, verdad?\p"
	.string "No... qué va, no puede ser eso.$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "¿Acabas de encontrar otra TABLA?\p"
	.string ".................\p"
	.string "Por supuesto.\p"
	.string "Los POKéMON legendarios que moran\n"
	.string "en estas ruinas...\l"
	.string "reaccionan a tu presencia, ¿verdad?\p"
	.string "Como si desearan ser encontrados.\p"
	.string "Mis predicciones casi nunca fallan.\n"
	.string "Debí imaginarlo en vez de dudar.$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Estamos muy cerca ya. Lo presiento.\p"
	.string "..................\p"
	.string "Tienes que venir a ver esto con tus\n"
	.string "propios ojos.$"

