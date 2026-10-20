SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	setvar VAR_0x8008, 15
	special CheckGymTrainersDefeated
	goto_if_eq VAR_RESULT, FALSE, SeafoamIslands_Gym_EventScript_Blaine_NotReady
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

SeafoamIslands_Gym_EventScript_Blaine_NotReady::
	msgbox SeafoamIslands_Gym_Text_Blaine_NotReady, MSGBOX_DEFAULT
	release
	end

SeafoamIslands_Gym_Text_Blaine_NotReady:
	.string "BLAINE: ¡Buaaa!\n"
	.string "¡El fuego no espera a nadie!\p"
	.string "Si pretendes medirte a mi calor,\n"
	.string "¡primero derrota a mis chicos!$"

SeafoamIslands_Gym_EventScript_Lowell::
	trainerbattle_single TRAINER_LOWELL_HNS, SeafoamIslands_Gym_Text_LowellSeen, SeafoamIslands_Gym_Text_LowellBeaten
	msgbox SeafoamIslands_Gym_Text_LowellAfter, MSGBOX_AUTOCLOSE
	end

SeafoamIslands_Gym_Text_LowellSeen:
	.string "¡Esta cueva estará helada, pero\n"
	.string "mi espíritu arde al rojo vivo!$"

SeafoamIslands_Gym_Text_LowellBeaten:
	.string "¡Me has apagado la llama!$"

SeafoamIslands_Gym_Text_LowellAfter:
	.string "BLAINE es una auténtica leyenda.\n"
	.string "¡Su pasión jamás se extinguirá!$"

SeafoamIslands_Gym_EventScript_Daniel::
	trainerbattle_single TRAINER_DANIEL_SEAFOAM_HNS, SeafoamIslands_Gym_Text_DanielSeen, SeafoamIslands_Gym_Text_DanielBeaten
	msgbox SeafoamIslands_Gym_Text_DanielAfter, MSGBOX_AUTOCLOSE
	end

SeafoamIslands_Gym_Text_DanielSeen:
	.string "¡No dejaré que nadie interrumpa\n"
	.string "el entrenamiento del maestro!$"

SeafoamIslands_Gym_Text_DanielBeaten:
	.string "¡Uf! ¡Qué sofocón!$"

SeafoamIslands_Gym_Text_DanielAfter:
	.string "Perdimos nuestro GIMNASIO, pero\n"
	.string "seguimos unidos junto a BLAINE.$"

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
	.string "ENTRENADORES GANADORES:\n"
	.string "AZUL, ROJO$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
	.string "GIMNASIO POKéMON DE CANELA\n"
	.string "LÍDER: BLAINE\p"
	.string "ENTRENADORES GANADORES:\n"
	.string "AZUL, ROJO, {PLAYER}$"

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

SeafoamIslands_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_ESPUMA, SeafoamIslands_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_ESPUMA, SeafoamIslands_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_ESPUMA
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

SeafoamIslands_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_ESPUMA, FALSE
	switch VAR_RESULT
	case 0, SeafoamIslands_Gym_EventScript_Manolin_GiveEjectButton
	case 1, SeafoamIslands_Gym_EventScript_Manolin_GiveIcyRock
	case MULTI_B_PRESSED, SeafoamIslands_Gym_EventScript_Manolin_NoChoice
	end

SeafoamIslands_Gym_EventScript_Manolin_GiveEjectButton::
	giveitem ITEM_EJECT_BUTTON
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_ESPUMA
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_EjectButtonExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Manolin_GiveIcyRock::
	giveitem ITEM_ICY_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_ESPUMA
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_IcyRockExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox SeafoamIslands_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafoamIslands_Gym_Text_Manolin_Intro:
	.string "¡Brrr! ¡Qué pasa mi gente!\n"
	.string "¡Vaya rasca hace aquí!\p"
	.string "¿Pero esto no era la cima del\n"
	.string "volcán de Monte Cenizo?\p"
	.string "¿Por qué hace este frío polar y hay\n"
	.string "un señor calvo con gafas de sol\l"
	.string "tirando llamaradas en el hielo?\p"
	.string "Vaya bug en el decorado…\n"
	.string "Casi me da un síncope térmico.$"

SeafoamIslands_Gym_Text_Manolin_CheckHealth:
	.string "¡Quieto parao! ¡Tienes a tus\n"
	.string "bichos tiritando y chamuscados!\p"
	.string "Un Envite Ígneo y vas al lobby.\n"
	.string "Trago reconstituyente para todos.$"

SeafoamIslands_Gym_Text_Manolin_Healed:
	.string "¡Salud recuperada y consumible top\n"
	.string "para que no te falte cuerda!$"

SeafoamIslands_Gym_Text_Manolin_OfferChoices:
	.string "Para sobrevivir a este contraste\n"
	.string "tengo dos objetos fetén.\l"
	.string "¿Cuál te mola más?$"

SeafoamIslands_Gym_Text_Manolin_EjectButtonExplain:
	.string "¡El BOTÓN ESCAPE es puro trameo!\n"
	.string "Si recibes daño, ¡tu Pokémon sale\l"
	.string "y metes a otro gratis al instante!\l"
	.string "Cambias de tanque sin perder turno.$"

SeafoamIslands_Gym_Text_Manolin_IcyRockExplain:
	.string "¡La ROCA HELADA alarga el Granizo\n"
	.string "o Nieve a 8 turnazos completos!\l"
	.string "Sube Defensa a tipos Hielo y\l"
	.string "desgasta a los bichos de fuego.$"

SeafoamIslands_Gym_Text_Manolin_NoChoice:
	.string "Entra en calor y decide cuando\n"
	.string "estés listo. ¡Aquí no hay prisa!$"

SeafoamIslands_Gym_Text_Manolin_AfterItem:
	.string "Cuidado con los cambios térmicos,\n"
	.string "¡y a reventar al boss, mi gente!$"
