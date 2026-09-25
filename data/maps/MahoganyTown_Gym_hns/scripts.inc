MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE PUEBLO CAOBA$"
MahoganyTown_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE PUEBLO CAOBA\pCERTIFICADOS POR FREDO:\n{PLAYER}$"
MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
	.string "Los POKéMON viven muchas cosas,\nigual que nosotros.\pYo también he visto y sufrido\nmucho en mi vida.\pComo soy tu mayor, déjame enseñarte\na qué me refiero.\pLlevo con los POKéMON desde antes\nde que tú nacieras.\pNo pierdo con facilidad.\p¡Yo, FREDO, maestro del invierno,\nte mostraré mi poder!$"
MahoganyTown_Gym_Text_PryceImpressed:
	.string "Ah, me impresiona tu\ndestreza.\pCon esa férrea voluntad, sé que\nsuperarás cualquier obstáculo.\p¡Mereces esta MEDALLA!$"
MahoganyTown_Gym_Text_ReceivedBadge:
	.string "¡{PLAYER} recibió la\nMEDALLA GLACIAR!$"
MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "Esa MEDALLA aumenta el ATAQUE\nESPECIAL de los POKéMON.\pTambién les permite usar TORBELLINO\npara cruzar remolinos reales.\pY esto… ¡Es un regalo mío!$"
MahoganyTown_Gym_Text_HailSpeech:
	.string "Esa MT contiene GRANIZO.\pDaña en cada turno durante\ncinco turnos.\pDemuestra la crudeza\ndel invierno.$"
MahoganyTown_Gym_Text_CherishPokemon:
	.string "Al fundirse el hielo y la nieve,\nllega la primavera.\pTus POKéMON y tú seguiréis juntos\ndurante muchos años.\p¡Atesora vuestro tiempo juntos!$"
MahoganyTown_Gym_Text_PryceRematch:
	.string "¡Ah, CAMPEÓN DE JOHTO!\pTu talento es verdaderamente\nformidable.\pEstoy impresionado.\pPero aún tenemos mucho que aprender\nel uno del otro.\pYo, FREDO, maestro del invierno,\naún guardo algún as en la manga.\p¿Quieres una revancha conmigo?$"
MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "Ah, vuelves a impresionarme con\ntu destreza.\pCon esa férrea voluntad, sé que\nsuperarás cualquier obstáculo.$"
MahoganyTown_Gym_Text_Guide:
	.string "FREDO es un veterano que lleva\nunos 50 años entrenando POKéMON.\pTiene un equipo sólido capaz de\nresponder a cualquier rival.\pEl fuego es un buen comienzo,\n¡pero cuidado con la lluvia!$"
MahoganyTown_Gym_Text_GuideWin:
	.string "FREDO es increíble, ¡pero tú lo\neres aún más!\p¡Ese combate ardiente ha unido\na dos generaciones!$"
MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "¡Congelaré a tus POKéMON para que\nno puedas hacer nada!$"
MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "Mecachis. No he podido hacer nada.$"
MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "Creo que hay un movimiento que un\nPOKéMON puede usar congelado.$"
MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "Este GIMNASIO tiene suelo helado.\pEs divertido, ¿verdad?\p¡Pero no estamos aquí para jugar!$"
MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "¿Ves lo en serio que vamos?$"
MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "Este GIMNASIO es genial.\n¡Me encanta patinar con ellos!$"
MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "Me sé el secreto de FREDO.$"
MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "Vale. Te contaré el secreto de\nFREDO.$"
MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "El secreto del poder de FREDO…\pMedita a diario bajo una cascada\npara fortalecer cuerpo y mente.$"
MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "Para llegar hasta FREDO, nuestro\nLÍDER, piensa antes de deslizarte.$"
MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "¡Esquiando no te dejaría ganarme!$"
MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "Si no patinas con precisión,\nno avanzarás en este GIMNASIO.$"
MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "¡Mira mi giro en paralelo!$"
MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "¡Nooo! ¡Me has hecho caer!$"
MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "No debí presumir tanto de mi\ntécnica de esquí…$"
