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
	.string "¡Soy PEGASO, el Líder del GIMNASIO\n"
	.string "POKéMON de CIUDAD MALVA!\p"
	.string "La gente dice que se pueden cortar\nlas\l"
	.string "alas a los Pokémon pájaro\p"
	.string "con una simple descarga eléctrica…\n"
	.string "¡No permitiré tales insultos a mis\l"
	.string "POKéMON voladores!\p"
	.string "¡Te demostraré el auténtico poder\n"
	.string "de las majestuosas aves del cielo!$"

VioletGym_Text_Falkner_WinLoss:
	.string "… ¡Maldición! Los queridos pájaros\nde\l"
	.string "mi padre…\p"
	.string "De acuerdo. Te has ganado esto.\p"
	.string "La MEDALLA CÉFIRO oficial de la\n"
	.string "LIGA POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "¡{PLAYER} recibió la MEDALLA CÉFIRO!$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "La MEDALLA CÉFIRO aumenta el ATAQUE\n"
	.string "de tus POKéMON.\p"
	.string "Además, permite que tus POKéMON\nusen\l"
	.string "DESTELLO fuera de combate si lo\naprenden.\p"
	.string "Toma… Llévate esto también.$"

VioletGym_Text_Falkner_TMExplain:
	.string "Al usar una MT, tus POKéMON\naprenderán\l"
	.string "un nuevo movimiento al instante.\p"
	.string "Esa MT contiene RESPIRO.\p"
	.string "Restaura la mitad de los PS máximos\nde\l"
	.string "tu POKéMON en combate.\p"
	.string "En otras palabras, ¡curará a tus\nalas!$"

VioletGym_Text_Falkner_AfterFight:
	.string "Hay muchos otros GIMNASIOS POKéMON\nen\l"
	.string "las ciudades que te esperan.\p"
	.string "Deberías ponerte a prueba en todos\nellos.\p"
	.string "¡Yo seguiré entrenando sin descanso\nhasta\l"
	.string "ser el maestro de las aves\ndefinitivo!$"

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
	.string "¡Aquí entrenamos día y noche para\ndominar\l"
	.string "el arte de los POKéMON pájaro!\p"
	.string "¡Vamos allá!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "¡Aaaaargh!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "¡El talento de PEGASO es de otro\nnivel!\p"
	.string "¡No te creas la gran cosa solo por\nhaberme\l"
	.string "ganado a mí!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "¡Veamos si tienes el nivel\nsuficiente\l"
	.string "para plantarle cara a PEGASO!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "¡No puede ser verdad!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "Qué humillación, perder contra un\n"
	.string "entrenador novato…$"

VioletGym_Text_GymGuide_Intro:
	.string "¡Ey! ¿Qué tal, futuro campeón?\n"
	.string "¡No seré entrenador, pero sé dar\nconsejos!\p"
	.string "¡Créeme! Con fe, el sueño de ganar\nla\l"
	.string "Liga puede hacerse realidad.\p"
	.string "¿Me crees? Pues abre bien las\norejas.\p"
	.string "El as de PEGASO es un búho robusto\nal que\l"
	.string "le chifla comerse sus BAYAS.\p"
	.string "Aguanta golpes como un muro.\p"
	.string "Dará buenos resultados usar\nmovimientos\l"
	.string "de tipo ELÉCTRICO y ROCA, ¡pero ojo\ncon su\l"
	.string "BOFETÓN LODO!\p"
	.string "Si necesitas más consejos, pásate\npor la\l"
	.string "ACADEMIA POKéMON.\p"
	.string "¡Los alumnos de allí se lo saben\ntodo!$"

VioletGym_Text_GymGuide_Win:
	.string "¡Menudo combatazo! ¡Sigue así y\nserás el\l"
	.string "CAMPEÓN en menos que canta un\ngallo!$"

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
	.string "ENTRENADORES CERTIFICADOS POR\nPEGASO:\l"
	.string "{PLAYER}$"
