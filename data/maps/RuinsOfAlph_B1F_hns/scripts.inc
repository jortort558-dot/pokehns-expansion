RuinsOfAlph_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_B1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnTransition::
	call RuinsOfAlph_B1F_EventScript_SetupAvatarVoces
	end

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_GSBALL::
	finditem ITEM_GS_BALL
	end

RuinsOfAlph_B1F_Text_Presence:
	.string "Se percibe una presencia extraña.$"

RuinsOfAlph_B1F_Text_Hiker:
	.string "Esta sala es enorme, pero no hay\n"
	.string "nada aquí.$"

RuinsOfAlph_B1F_Text_Teacher:
	.string "Este lugar desprende un aura\n"
	.string "mística.\p"
	.string "Parece incluso de otro mundo.$"

RuinsOfAlph_B1F_Text_Gramps:
	.string "Los edificios antiguos eran\n"
	.string "a menudo tumbas de reyes.\p"
	.string "Como las pirámides, por ejemplo.$"

RuinsOfAlph_B1F_EventScript_SetupAvatarVoces::
	goto_if_unset FLAG_JOHTO_AVATAR_DRAGON_DEFEATED, RuinsOfAlph_B1F_EventScript_HideAvatarVoces
	goto_if_set FLAG_JOHTO_AVATAR_VOICES_DEFEATED, RuinsOfAlph_B1F_EventScript_HideAvatarVoces
	clearflag FLAG_HIDE_JOHTO_AVATAR_VOICES
	return

RuinsOfAlph_B1F_EventScript_HideAvatarVoces::
	setflag FLAG_HIDE_JOHTO_AVATAR_VOICES
	return

RuinsOfAlph_B1F_EventScript_AvatarVoces::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_AvatarVocesIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AVATAR_VOCES_HNS, RuinsOfAlph_B1F_Text_AvatarVocesDefeat
	setflag FLAG_JOHTO_AVATAR_VOICES_DEFEATED
	setflag FLAG_HIDE_JOHTO_AVATAR_VOICES
	msgbox RuinsOfAlph_B1F_Text_AvatarVocesAfter, MSGBOX_DEFAULT
	removeobject 16
	release
	end

RuinsOfAlph_B1F_Text_AvatarVocesIntro:
	.string "Entre los grabados de las paredes\n"
	.string "susurran las mil voces del pasado.\p"
	.string "Has descifrado los misterios y\n"
	.string "caminas bajo la guía del ATLAS.\p"
	.string "¡Muestra si tu mente resiste\n"
	.string "el peso del saber arcano!$"

RuinsOfAlph_B1F_Text_AvatarVocesDefeat:
	.string "Las voces reconocen tu templanza...$"

RuinsOfAlph_B1F_Text_AvatarVocesAfter:
	.string "Has superado la prueba del\n"
	.string "AVATAR DE LAS MIL VOCES.\p"
	.string "La armonía de JOHTO se consolida.\n"
	.string "Vuelve con el SABIO de ORQUÍDEA\l"
	.string "para conocer tu próximo destino.$"


