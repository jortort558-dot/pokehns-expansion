DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
	.string "{PLAYER}… Así que estás aquí.\p"
	.string "Si crees poder seguir mi ritmo,\n"
	.string "ven al DOJO KARATE de AZAFRÁN.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
	.string "DÉBORA: ¡ESPERA!\p"
	.string "Siento lo ocurrido.\n"
	.string "Toma esto como disculpa.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
	.string "PULSO DRAGÓN es una especie de…\n"
	.string "¡Bah, olvídalo!\p"
	.string "Es una enorme descarga de energía.\p"
	.string "Si no la quieres, no tienes por qué\n"
	.string "aceptarla.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
	.string "¿Qué ocurre? ¿No ibas hacia la\n"
	.string "LIGA POKéMON?\p"
	.string "Cuando seas CAMPEÓN, podrás volver\n"
	.string "a desafiar a cualquier LÍDER.\p"
	.string "Ve a la LIGA POKéMON.\p"
	.string "¿Sabes cómo llegar?\p"
	.string "Ve desde aquí a PUEBLO PRIMAVERA.\p"
	.string "Después usa SURF hacia el este.\n"
	.string "La ruta es muy dura.\p"
	.string "¡Ni se te ocurra perder en la\n"
	.string "LIGA POKéMON!\p"
	.string "¡Si pierdes, me sentará aún peor\n"
	.string "haber sido derrotada por ti!\p"
	.string "Dalo todo.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
	.string "TEMPLO DRAGÓN\p"
	.string "Templo dedicado a los POKéMON\n"
	.string "dragón que, según cuentan, vivían\l"
	.string "en la GUARIDA DRAGÓN.$"

DragonsDen_Cavern_Text_SilverTraining1:
	.string "…\n"
	.string "¿Qué? ¿{PLAYER}?\p"
	.string "…No, ahora no combatiré contigo…\p"
	.string "Mis POKéMON aún no están listos\n"
	.string "para derrotarte.\p"
	.string "No puedo exigirles demasiado.\p"
	.string "Debo ser disciplinado para llegar\n"
	.string "a ser el mejor Entrenador…$"

DragonsDen_Cavern_Text_SilverTraining2:
	.string "…\p"
	.string "Uf…\p"
	.string "Aprende a no meterte en mi camino…$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
	.string "¡Tú! ¿Cómo te atreves a entrar\n"
	.string "sin permiso?$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
	.string "¡Q-qué fuerte!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
	.string "En el TEMPLO vive el MAESTRO de\n"
	.string "nuestro clan dragón.\p"
	.string "¡No puedes entrar sin más!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
	.string "¡No deberías estar aquí!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
	.string "¡Ay! ¡He perdido!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
	.string "Pronto obtendré el permiso del\n"
	.string "MAESTRO para usar dragones.\p"
	.string "Entonces seré una admirable maestra\n"
	.string "dragón y me ganaré su aprobación.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
	.string "Es una persona desconocida.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
	.string "Ay.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
	.string "Ha sido como combatir contra\n"
	.string "LANCE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
	.string "¿Quién eres?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
	.string "Qué malo eres.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
	.string "Se lo contaremos al MAESTRO.\p"
	.string "Se enfadará contigo.$"
