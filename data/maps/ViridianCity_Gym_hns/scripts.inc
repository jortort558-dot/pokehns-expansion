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
