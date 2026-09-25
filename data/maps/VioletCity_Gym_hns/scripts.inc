VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "¡Soy PEGASO, el LÍDER del GIMNASIO\n"
	.string "POKéMON de CIUDAD MALVA!\p"
	.string "Dicen que una descarga eléctrica\n"
	.string "puede cortar las alas de los\l"
	.string "POKéMON voladores…\p"
	.string "¡No permitiré tales insultos\n"
	.string "POKéMON voladores!\p"
	.string "¡Te demostraré el auténtico poder\n"
	.string "de las majestuosas aves del cielo!$"

VioletGym_Text_Falkner_WinLoss:
	.string "…¡Maldición! Los queridos POKéMON\n"
	.string "pájaro de mi padre…\p"
	.string "De acuerdo. Te has ganado esto.\p"
	.string "La MEDALLA CÉFIRO oficial de la\n"
	.string "LIGA POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} recibió la MEDALLA CÉFIRO.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "La MEDALLA CÉFIRO aumenta el ATAQUE\n"
	.string "de tus POKéMON.\p"
	.string "Además, permite usar DESTELLO\n"
	.string "fuera de combate a los POKéMON\l"
	.string "que puedan aprenderlo.\p"
	.string "Toma… Llévate esto también.$"

VioletGym_Text_Falkner_TMExplain:
	.string "Al usar una MT, un POKéMON aprende\n"
	.string "un movimiento al instante.\p"
	.string "Esa MT contiene RESPIRO.\p"
	.string "Restaura la mitad de los PS máximos\n"
	.string "del POKéMON en combate.\p"
	.string "En otras palabras, ¡te curará\n"
	.string "las alas!$"

VioletGym_Text_Falkner_AfterFight:
	.string "Te esperan muchos otros GIMNASIOS\n"
	.string "POKéMON en pueblos y ciudades.\p"
	.string "Deberías poner a prueba tu destreza\n"
	.string "en todos ellos.\p"
	.string "¡Yo seguiré entrenando para ser\n"
	.string "el mejor maestro de POKéMON pájaro!$"

VioletGym_Text_Falkner_Rematch:
	.string "¡Enhorabuena por derrotar al\n"
	.string "ALTO MANDO!\p"
	.string "He estado entrenando a mis POKéMON\n"
	.string "voladores aún más duro.\p"
	.string "¿Crees que podrás resistir de nuevo\n"
	.string "el poder de los cielos?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Guau… Me has vuelto a vencer.\p"
	.string "¡Seguiré entrenando duro para ser\n"
	.string "el mayor maestro de las aves!$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "¡La clave es tener agallas!\p"
	.string "¡Aquí entrenamos día y noche para\n"
	.string "dominar a los POKéMON pájaro!\p"
	.string "¡Vamos allá!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "¡Aaaaargh!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "¡El talento de PEGASO es auténtico!\p"
	.string "¡No te confíes solo por haberme\n"
	.string "vencido a mí!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "¡Veamos si tienes nivel suficiente\n"
	.string "para plantarle cara a PEGASO!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "¡No puede ser verdad!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "Qué humillación, perder contra un\n"
	.string "entrenador novato…$"

VioletGym_Text_GymGuide_Intro:
	.string "¡Ey! ¿Qué tal, futuro CAMPEÓN?\n"
	.string "No soy entrenador, ¡pero sé dar\l"
	.string "buenos consejos!\p"
	.string "¡Créeme! Con fe, tu sueño de ser\n"
	.string "CAMPEÓN puede hacerse realidad.\p"
	.string "¿Me crees? Pues escucha.\p"
	.string "El as de PEGASO es un búho robusto\n"
	.string "al que le chiflan las BAYAS.\p"
	.string "No es el más fuerte, pero aguanta\n"
	.string "muchos golpes.\p"
	.string "Usa movimientos de tipo ELÉCTRICO\n"
	.string "y ROCA, ¡pero ten cuidado con su\l"
	.string "BOFETÓN LODO!\p"
	.string "Si necesitas más consejos, visita\n"
	.string "la ACADEMIA POKéMON.\p"
	.string "¡Sus alumnos saben de qué hablan!$"

VioletGym_Text_GymGuide_Win:
	.string "¡Menudo combate! ¡Sigue así y serás\n"
	.string "CAMPEÓN antes de que te des cuenta!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD MALVA$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD MALVA\p"
	.string "ENTRENADORES CERTIFICADOS\n"
	.string "POR PEGASO:\l"
	.string "{PLAYER}$"
