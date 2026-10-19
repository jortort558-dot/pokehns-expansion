MtSilver_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_MT_SILVER
	call MtSilver_Outside_EventScript_SetupEvents
	end

MtSilver_Outside_EventScript_SetupEvents::
	goto_if_unset FLAG_JOHTO_AVATAR_SOULS_DEFEATED, MtSilver_Outside_EventScript_HideAvatarOrigen
	goto_if_set FLAG_JOHTO_AVATAR_ORIGIN_DEFEATED, MtSilver_Outside_EventScript_HideAvatarOrigen
	clearflag FLAG_HIDE_JOHTO_AVATAR_ORIGIN
	goto MtSilver_Outside_EventScript_CheckPapis
MtSilver_Outside_EventScript_HideAvatarOrigen::
	setflag FLAG_HIDE_JOHTO_AVATAR_ORIGIN
MtSilver_Outside_EventScript_CheckPapis::
	goto_if_unset FLAG_JOHTO_AVATAR_ORIGIN_DEFEATED, MtSilver_Outside_EventScript_HidePapis
	goto_if_set FLAG_JOHTO_LOS_PAPIS_DEFEATED, MtSilver_Outside_EventScript_HidePapis
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCIENTIST_M_HNS
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SCIENTIST_F_HNS
	clearflag FLAG_HIDE_JOHTO_LOS_PAPIS
	return
MtSilver_Outside_EventScript_HidePapis::
	setflag FLAG_HIDE_JOHTO_LOS_PAPIS
	return

MtSilver_Outside_EventScript_Sign::
	msgbox MtSilver_Outside_Text_Sign, MSGBOX_SIGN
	end

MtSilver_Outside_Text_Sign:
	.string "MT. SILVER$"

MtSilver_Outside_EventScript_AvatarOrigen::
	lock
	faceplayer
	msgbox MtSilver_Outside_Text_AvatarOrigenIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AVATAR_ORIGEN_HNS, MtSilver_Outside_Text_AvatarOrigenDefeat
	setflag FLAG_JOHTO_AVATAR_ORIGIN_DEFEATED
	setflag FLAG_HIDE_JOHTO_AVATAR_ORIGIN
	msgbox MtSilver_Outside_Text_AvatarOrigenAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 14
	fadescreen FADE_FROM_BLACK
	goto MtSilver_Outside_EventScript_SceneLosPapis
	end

MtSilver_Outside_EventScript_SceneLosPapis::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCIENTIST_M_HNS
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SCIENTIST_F_HNS
	clearflag FLAG_HIDE_JOHTO_LOS_PAPIS
	addobject 15
	addobject 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	playbgm MUS_HG_VS_CHAMPION, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_JOSE
	msgbox MtSilver_Outside_Text_ResearchersRevealIntro, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox MtSilver_Outside_Text_ResearchersRevealPilar, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 15
	removeobject 16
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GENTLEMAN_HNS
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_YOUNGSTER_HNS
	addobject 15
	addobject 16
	fadescreen FADE_FROM_BLACK
	setspeaker SP_NAME_NONE
	msgbox MtSilver_Outside_Text_PapisAparicion, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	playse SE_USE_ITEM
	waitse
	msgbox MtSilver_Outside_Text_PapisHeal, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LOS_PAPIS_HNS, MtSilver_Outside_Text_PapisDefeat
	setflag FLAG_JOHTO_LOS_PAPIS_DEFEATED
	msgbox MtSilver_Outside_Text_PapisAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_JOHTO_LOS_PAPIS
	removeobject 15
	removeobject 16
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	msgbox MtSilver_Outside_Text_PapisClimax, MSGBOX_DEFAULT
	release
	end

MtSilver_Outside_EventScript_Giuseppe::
	lock
	faceplayer
	msgbox MtSilver_Outside_Text_GiuseppeStandalone, MSGBOX_DEFAULT
	release
	end

MtSilver_Outside_EventScript_Pilarito::
	lock
	faceplayer
	msgbox MtSilver_Outside_Text_PilaritoStandalone, MSGBOX_DEFAULT
	release
	end

MtSilver_Outside_Text_AvatarOrigenIntro:
	.string "En la cumbre donde convergen JOHTO\n"
	.string "y KANTO, late el corazón del mundo.\p"
	.string "Has apaciguado las seis energías\n"
	.string "primordiales del ATLAS ANCESTRAL.\p"
	.string "¡Yo soy el AVATAR DEL ORIGEN!\n"
	.string "¡Muéstrame la plenitud de tu poder!$"

MtSilver_Outside_Text_AvatarOrigenDefeat:
	.string "El lazo primigenio ha despertado...$"

MtSilver_Outside_Text_AvatarOrigenAfter:
	.string "Has demostrado la comunión\n"
	.string "absoluta con tus POKéMON.\p"
	.string "Los sellos del ATLAS están en paz.\n"
	.string "El equilibrio ha vuelto...$"

MtSilver_Outside_Text_PapisAparicion:
	.string "GIUSEPPE: ¡Bravo! Durante todo\n"
	.string "este tiempo me conociste como\l"
	.string "el aplicado JOSE.\p"
	.string "PILARITO: Y la brillante PILAR\n"
	.string "solo era mi papel, chavalote.\p"
	.string "GIUSEPPE: Necesitábamos que\n"
	.string "alguien liberara la resonancia\l"
	.string "total de los AVATARES.\p"
	.string "PILARITO: ¡Exacto! ¡Los PAPIS vamos\n"
	.string "siempre un paso por delante!\p"
	.string "¡Esa fuerza cósmica es nuestra!\n"
	.string "¡Si la quieres de vuelta, tendrás\l"
	.string "que luchar contra los dos juntos!$"

MtSilver_Outside_Text_ResearchersRevealIntro:
	.string "JOSE: Magnífico, {PLAYER}.\n"
	.string "Cada ruta, cada muestra...\l"
	.string "Todo nos condujo hasta aquí.\p"
	.string "Aunque quizá ya sea hora de que\n"
	.string "dejes de llamarme JOSE.$"

MtSilver_Outside_Text_ResearchersRevealPilar:
	.string "PILAR: Ay, socio... Tanto medir\n"
	.string "mareas y aún no ha visto venir\l"
	.string "la más importante.\p"
	.string "Los investigadores se arrancan\n"
	.string "sus disfraces de un tirón.$"

MtSilver_Outside_Text_PapisHeal:
	.string "GIUSEPPE: No queremos excusas.\n"
	.string "Tus POKéMON vuelven a estar\l"
	.string "completamente recuperados.\p"
	.string "PILARITO: ¡Ahora sí, campeón!\n"
	.string "¡Que empiece la función!$"

MtSilver_Outside_Text_PapisDefeat:
	.string "GIUSEPPE: ¡¿Pero qué clase de\n"
	.string "monstruo hemos despertado?!\p"
	.string "PILARITO: ¡No me lo puedo creer!\n"
	.string "¡Nos han pasado por encima!$"

MtSilver_Outside_Text_PapisAfter:
	.string "GIUSEPPE: Imposible... Tanta\n"
	.string "táctica y preparación...\p"
	.string "PILARITO: Hay que admitirlo, socio.\n"
	.string "Este chaval tiene algo especial.\p"
	.string "GIUSEPPE: Bien jugado. Quédate la\n"
	.string "bendición de los AVATARES.\p"
	.string "PILARITO: ¡Nos vemos, campeón!\n"
	.string "¡Los PAPIS se van con estilo!$"

MtSilver_Outside_Text_PapisClimax:
	.string "La energía del ATLAS ANCESTRAL\n"
	.string "brilla en tu pecho con fuerza.\p"
	.string "Una profunda sensación de paz\n"
	.string "cubre el MONTE PLATEADO.\p"
	.string "¡El SABIO de ORQUÍDEA estará\n"
	.string "orgulloso de esta proeza!$"

MtSilver_Outside_Text_GiuseppeStandalone:
	.string "GIUSEPPE: El poder del ATLAS\n"
	.string "supera cualquier cálculo.$"

MtSilver_Outside_Text_PilaritoStandalone:
	.string "PILARITO: ¡Acepta el reto cuando\n"
	.string "estés preparado!$"
