SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
	.string "GIMNASIO POKéMON DE CANELA\n"
	.string "LÍDER: BLAINE\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CANELA\n"
	.string "LÍDER: BLAINE\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED, {PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "¡Llévate esto también!$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "¡Esta MT contiene el increíble\n"
	.string "SOFOCO!\p"
	.string "Su calor abrasa al rival, pero\n"
	.string "después reduce tu potencia.\p"
	.string "¡Espero que tu próximo rival tenga\n"
	.string "un ANTIQUEMAR extra! ¡Buaaa!$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "BLAINE: ¡Buaaa!\p"
	.string "Mi GIMNASIO de CANELA se quemó.\p"
	.string "Mis POKéMON de fuego y yo nos\n"
	.string "quedamos sin hogar por el volcán.\p"
	.string "¡Buaaa!\p"
	.string "Pero vuelvo a ejercer de LÍDER\n"
	.string "aquí, en esta cueva.\p"
	.string "Si me vences, te daré\n"
	.string "una MEDALLA.\p"
	.string "¡Ja! ¡Más te vale tener ANTIQUEMAR!$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "BLAINE: Increíble. Me he consumido…\p"
	.string "¡Te has ganado la MEDALLA VOLCÁN!$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} recibió la MEDALLA VOLCÁN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "BLAINE: Esta vez he perdido, pero\n"
	.string "la próxima ganaré.\p"
	.string "Cuando reconstruya mi GIMNASIO,\n"
	.string "tendremos la revancha.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "BLAINE: Mis POKéMON de fuego serán\n"
	.string "aún más fuertes.\p"
	.string "¡Ya lo verás!$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "BLAINE: ¡Vaya!\p"
	.string "¡Veo que eres el CAMPEÓN\n"
	.string "de KANTO!\p"
	.string "¡Eso sí que arde!\p"
	.string "Tus habilidades son excelentes.\p"
	.string "Siempre estoy listo para combatir.\p"
	.string "¿Quieres una revancha conmigo?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "BLAINE: ¡Tu habilidad arde!\p"
	.string "Has quemado todas\n"
	.string "mis defensas.$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "¡Hola!\p"
	.string "… ¿Eh? ¿Ya ha terminado?\p"
	.string "¡Perdona, perdona!\p"
	.string "Al desaparecer el GIMNASIO CANELA,\n"
	.string "no sabía dónde encontrarte.\p"
	.string "Pero eres fuerte sin mis consejos.\n"
	.string "¡Sabía que ganarías!$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Un GIMNASIO POKéMON puede estar\n"
	.string "donde esté su LÍDER.\p"
	.string "No hace falta ningún edificio.$"
