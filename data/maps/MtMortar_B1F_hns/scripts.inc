MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "¡Eh!\p¡Soy el REY DEL KÁRATE!\n¡Entreno solo aquí en la oscuridad!\p¡Tú! ¡Combate conmigo!\n¡¡¡Juaaaargh!!!$"
MountMortar4_Text_KiyoWin:
	.string "¡¡¡Uaaaargh!!!\n¡Me has vencido!$"
MountMortar4_Text_KiyoTyrogueReward:
	.string "Me… Me has destrozado…\pMi entrenamiento aún no es\nsuficiente…\pPero una derrota es una derrota.\nLo admito.\pComo prueba de que me has vencido,\nte daré un POKéMON de tipo LUCHA\lmuy especial.$"
MountMortar4_Text_ReceiveTyrogue:
	.string "¡{PLAYER} recibió a TYROGUE!$"
MountMortar4_Text_KiyoGotTyrogue:
	.string "TYROGUE es de tipo LUCHA.\pEvoluciona en un POKéMON\nmás fuerte.\pSigue esforzándote.\nYo también continuaré entrenando.\p¡Hasta siempre!$"
MountMortar4_Text_KiyoFullParty:
	.string "¡No tienes sitio en el equipo!$"
