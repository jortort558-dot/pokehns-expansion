LavenderTown_SoulHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_SoulHouse_OnTransition
	.byte 0

LavenderTown_SoulHouse_OnTransition::
	call LavenderTown_SoulHouse_EventScript_SetupAvatarAlmas
	end

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "SR. FUJI: Te doy la bienvenida.\p"
	.string "Mmm… Parece que crías a tus\n"
	.string "POKéMON con cariño y bondad.\p"
	.string "Los amantes de los POKéMON vienen\n"
	.string "aquí para honrar a los que ya\l"
	.string "partieron.\p"
	.string "Presenta tus respetos a sus almas.\n"
	.string "Seguro que eso las hará felices.$"
SoulHouse_Text_Teacher:
	.string "Creo que aquí hay más tumbas de\n"
	.string "POKéMON.\p"
	.string "Hay muchas cámaras a las que solo\n"
	.string "puede entrar el SR. FUJI.$"
SoulHouse_Text_Lass:
	.string "He venido con mi madre a visitar\n"
	.string "las tumbas de los POKéMON…$"
SoulHouse_Text_Granny:
	.string "A los POKéMON que vivían conmigo…\p"
	.string "Los quería como a mis nietos…$"

LavenderTown_SoulHouse_EventScript_SetupAvatarAlmas::
	goto_if_unset FLAG_JOHTO_AVATAR_VOICES_DEFEATED, LavenderTown_SoulHouse_EventScript_HideAvatarAlmas
	goto_if_set FLAG_JOHTO_AVATAR_SOULS_DEFEATED, LavenderTown_SoulHouse_EventScript_HideAvatarAlmas
	clearflag FLAG_HIDE_JOHTO_AVATAR_SOULS
	return

LavenderTown_SoulHouse_EventScript_HideAvatarAlmas::
	setflag FLAG_HIDE_JOHTO_AVATAR_SOULS
	return

LavenderTown_SoulHouse_EventScript_AvatarAlmas::
	lock
	faceplayer
	msgbox LavenderTown_SoulHouse_Text_AvatarAlmasIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AVATAR_ALMAS_HNS, LavenderTown_SoulHouse_Text_AvatarAlmasDefeat
	setflag FLAG_JOHTO_AVATAR_SOULS_DEFEATED
	setflag FLAG_HIDE_JOHTO_AVATAR_SOULS
	msgbox LavenderTown_SoulHouse_Text_AvatarAlmasAfter, MSGBOX_DEFAULT
	removeobject 5
	release
	end

LavenderTown_SoulHouse_Text_AvatarAlmasIntro:
	.string "El silencio de este santuario\n"
	.string "guarda el descanso de las almas.\p"
	.string "Has viajado de JOHTO a KANTO\n"
	.string "siguiendo la llamada del ATLAS.\p"
	.string "¡Muestra si tu corazón disipa\n"
	.string "las sombras del más allá!$"

LavenderTown_SoulHouse_Text_AvatarAlmasDefeat:
	.string "La luz de tu alma calma el pesar...$"

LavenderTown_SoulHouse_Text_AvatarAlmasAfter:
	.string "Has apaciguado al AVATAR DE LAS\n"
	.string "ALMAS.\p"
	.string "El lazo regional vibra con fuerza.\n"
	.string "Habla con el SABIO de ORQUÍDEA\l"
	.string "para alcanzar el origen de todo.$"
