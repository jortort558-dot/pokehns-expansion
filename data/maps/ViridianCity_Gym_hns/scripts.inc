ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "AZUL: ¿Ya quieres más?\p"
	.string "Si quieres otra oportunidad,\n"
	.string "¡ven al DOJO KARATE!$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "AZUL: ¡Eh! Al fin llegas, ¿no?\p"
	.string "En CANELA no tenía ganas,\p"
	.string "pero ahora estoy listo para luchar.\p"
	.string "…\p"
	.string "¿Dices que venciste en todos los\n"
	.string "GIMNASIOS de JOHTO?\p"
	.string "¡Je! Serán bastante patéticos.\p"
	.string "Pero no te preocupes.\p"
	.string "Sabré si eres bueno luchando\n"
	.string "contigo ahora mismo.\p"
	.string "¿Listo, CAMPEÓN de JOHTO?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "AZUL: ¿Qué?\p"
	.string "¿Cómo demonios he perdido?\p"
	.string "…\p"
	.string "Tch, vale… Toma esto. Es la\n"
	.string "MEDALLA TIERRA.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} recibió la MEDALLA TIERRA.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "AZUL: …\p"
	.string "Vale, me equivoqué. Eres de verdad.\n"
	.string "Eres un buen Entrenador.\p"
	.string "Pero algún día te derrotaré.\p"
	.string "¡No lo olvides!$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "Llévate esto.$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "Es ESPACIO RARO.\p"
	.string "Cambia el orden de velocidad.\n"
	.string "Los lentos actúan antes.\p"
	.string "Úsalo para invertir el combate.$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "AZUL: Escucha.\p"
	.string "No pierdas hasta que yo te venza.\n"
	.string "¿Entendido?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "¡Hola, futuro CAMPEÓN!\p"
	.string "¿Qué tal? Parece que vas en racha.\p"
	.string "El LÍDER luchó contra el CAMPEÓN\n"
	.string "hace tres años.\p"
	.string "No es nada fácil.\p"
	.string "¡Dalo todo!$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Caray, eres muy duro…\p"
	.string "Ha sido un combate inspirador.\n"
	.string "Me ha hecho llorar.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CIUDAD VERDE\n"
	.string "LÍDER: AZUL\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CIUDAD VERDE\n"
	.string "LÍDER: AZUL\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED, {PLAYER}$"

ViridianCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_VERDE, ViridianCity_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_VERDE, ViridianCity_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_VERDE
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

ViridianCity_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_VERDE, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_Gym_EventScript_Manolin_GiveRedCard
	case 1, ViridianCity_Gym_EventScript_Manolin_GiveChopleBerry
	case MULTI_B_PRESSED, ViridianCity_Gym_EventScript_Manolin_NoChoice
	end

ViridianCity_Gym_EventScript_Manolin_GiveRedCard::
	giveitem ITEM_RED_CARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_VERDE
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_RedCardExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_Manolin_GiveChopleBerry::
	giveitem ITEM_CHOPLE_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_VERDE
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_ChopleBerryExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox ViridianCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_Manolin_Intro:
	.string "¡Qué pasa mi gente! ¡Menudo templo!\p"
	.string "Se supone que este es el GIMNASIO\n"
	.string "de Ciudad Petalia frente a Norman,\l"
	.string "¿a que sí?\p"
	.string "¿Pero por qué me encuentro a un chaval\n"
	.string "vacilón de pelo castaño diciendo que\l"
	.string "es el antiguo Campeón?\p"
	.string "Este tío no parece el padre de nadie…\n"
	.string "¡Vaya boss mítico de final de raid!$"

ViridianCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Frena las rotaciones, hermano!\n"
	.string "¡Llevas a tu escuadrón tiritando!\p"
	.string "Este boss tiene cobertura para todo y\n"
	.string "un equipo de élite.\l"
	.string "Barra verde al completo y a meter dps.$"

ViridianCity_Gym_Text_Manolin_Healed:
	.string "¡Party full de salud y consumible\n"
	.string "de raid definitivo a la mochila!$"

ViridianCity_Gym_Text_Manolin_OfferChoices:
	.string "Contra un boss de esta categoría no vale\n"
	.string "ir con baratijas. ¡Toma equipo bis!\l"
	.string "¿Con cuál te la juegas?$"

ViridianCity_Gym_Text_Manolin_RedCardExplain:
	.string "¡La TARJETA ROJA es un trameo de locos!\n"
	.string "Si el rival te pega, ¡lo expulsas del\l"
	.string "campo y entra otro Pokémon al azar!\l"
	.string "Le arruinas el boost en un segundo.$"

ViridianCity_Gym_Text_Manolin_ChopleBerryExplain:
	.string "¡La BAYA OCA mitiga a la mitad el daño\n"
	.string "de tipo Lucha si te sacuden!\l"
	.string "Esencial para salvar a un tipo Normal\l"
	.string "o Acero de un golpe demoledor.$"

ViridianCity_Gym_Text_Manolin_NoChoice:
	.string "Piénsatelo bien, que este es el boss\n"
	.string "más tocho antes de la Liga.$"

ViridianCity_Gym_Text_Manolin_AfterItem:
	.string "No dejes que te vacile con sus poses,\n"
	.string "¡y a tirarle la torre al boss, mi gente!$"
