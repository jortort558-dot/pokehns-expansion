VioletCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Gym_OnTransition
	.byte 0

VioletCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_HideManolin
	clearflag FLAG_HIDE_MANOLIN_MALVA
	end

VioletCity_Gym_HideManolin::
	setflag FLAG_HIDE_MANOLIN_MALVA
	end

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

VioletCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_MALVA, VioletCity_Gym_EventScript_Manolin_AfterItem
	msgbox VioletCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_MALVA, VioletCity_Gym_EventScript_Manolin_ChooseItem
	msgbox VioletCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_POTION, 2
	setflag FLAG_MANOLIN_HEAL_MALVA
	msgbox VioletCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

VioletCity_Gym_EventScript_Manolin_ChooseItem::
	msgbox VioletCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_MALVA, FALSE
	switch VAR_RESULT
	case 0, VioletCity_Gym_EventScript_Manolin_GiveWideLens
	case 1, VioletCity_Gym_EventScript_Manolin_GiveBrightPowder
	case MULTI_B_PRESSED, VioletCity_Gym_EventScript_Manolin_NoChoice
	end

VioletCity_Gym_EventScript_Manolin_GiveWideLens::
	giveitem ITEM_WIDE_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_MALVA
	msgbox VioletCity_Gym_Text_Manolin_WideLensExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Manolin_GiveBrightPowder::
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_MALVA
	msgbox VioletCity_Gym_Text_Manolin_BrightPowderExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Manolin_NoChoice::
	msgbox VioletCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Manolin_AfterItem::
	msgbox VioletCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_Manolin_Intro:
	.string "¡Ey! Espera… ¿tú quién eras?\p"
	.string "¡Ah, sí! ¡El nuevo del server!\n"
	.string "Me llaman Manolín, pero la peña\l"
	.string "me conoce como El Bate Mágico.\p"
	.string "Y no por el béisbol, ¿eh? ¡Que yo\n"
	.string "soy bateador de míticas en el WoW!\p"
	.string "Oye, ¿este no era el boss de fuego?\n"
	.string "Ah, no… qué empanada llevo, socio,\l"
	.string "¡que aquí está PEGASO con\l"
	.string "los pájaros!$"

VioletCity_Gym_Text_Manolin_CheckHealth:
	.string "Hostia tú… ¡pero si llevas a los\n"
	.string "bichos tiritando de vida!\p"
	.string "¿Ibas a hacer el pull así? ¡Te van\n"
	.string "a wipear la party en fase 1!\p"
	.string "Espera, ¿yo te iba a dar algo o te\n"
	.string "iba a curar? Bueno, ¡primero barra\l"
	.string "llena, mi gente!$"

VioletCity_Gym_Text_Manolin_Healed:
	.string "¡Full vida y maná arriba!\p"
	.string "Toma un par de Pociones por si el\n"
	.string "combate se alarga… Aunque oye,\l"
	.string "¿no te las había dado ya? En fin.$"

VioletCity_Gym_Text_Manolin_OfferChoices:
	.string "A ver, como dice souzacarlos: ¡esto\n"
	.string "es un trameo de los buenos!\p"
	.string "Para tirarle el boss a PEGASO sin\n"
	.string "sustos necesitas equipo bis.\p"
	.string "Tengo dos objetos competitivos.\n"
	.string "¿Prefieres meter dps con precisión\l"
	.string "o esquivar ataques como un ninja?$"

VioletCity_Gym_Text_Manolin_WideLensExplain:
	.string "¡La LUPA! Si vas a meterle ataques\n"
	.string "de Roca o Rayo que suelen fallar,\l"
	.string "esto te asegura el hit limpio.\p"
	.string "¡Ni el Rey Exánime aguantaría\n"
	.string "un burst tan fino!$"

VioletCity_Gym_Text_Manolin_BrightPowderExplain:
	.string "¡POLVO BRILLO! Hace que el rival\n"
	.string "falle golpes clave.\p"
	.string "Cuando PEGASO intente el burst,\n"
	.string "¡se va a comer un miss legendario!$"

VioletCity_Gym_Text_Manolin_NoChoice:
	.string "¿No te decides? No te preocupes,\n"
	.string "que yo a veces olvido\l"
	.string "qué clase soy.\p"
	.string "Pásate cuando quieras equiparte.$"

VioletCity_Gym_Text_Manolin_AfterItem:
	.string "¡Vamos, mi gente! Entra ahí,\n"
	.string "tramea las mecánicas y sácale\l"
	.string "la medalla a PEGASO.\p"
	.string "Nos vemos en la siguiente raid…\n"
	.string "si me acuerdo de qué pueblo era.$"
