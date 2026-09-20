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
	.string "GIMNASIO POKéMON DE PUEBLO CAOBA\nENTRENADORES CERTIFICADOS POR\lFREDO:\l{PLAYER}$"
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
	.string "Los POKéMON atraviesan muchas\nvivencias a\llo largo de sus vidas, igual que\lnosotros.\lYo también he presenciado y\lpadecido mucho\len este mundo.\lComo soy tu mayor, déjame enseñarte\la qué\lme refiero.\lConvivo con los POKéMON desde antes\lde que\ltú nacieras.\lNo soy alguien a quien se venza con\lfacilidad.\l¡Yo, FREDO, el maestro del\linvierno,\lte mostraré mi auténtico poder!$"
MahoganyTown_Gym_Text_PryceImpressed:
	.string "Ah, me quito el sombrero ante tu\ndestreza.\lCon esa férrea voluntad que posees,\lsuperarás\ltodos los obstáculos de la vida.\l¡Eres digno de portar esta MEDALLA!$"
MahoganyTown_Gym_Text_ReceivedBadge:
	.string "¡{PLAYER} recibió la MEDALLA GLACIAR!$"
MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "Esa MEDALLA aumentará el ATAQUE\nESPECIAL\lde tus POKéMON.\lTambién les permitirá usar\lTORBELLINO para\lcruzar remolinos salvajes en el\lagua.\lY toma... ¡esto es un obsequio de\lmi parte!$"
MahoganyTown_Gym_Text_HailSpeech:
	.string "Esa MT contiene GRANIZO.\nCausa daño continuo en cada turno\ldurante\lcinco turnos.\lEs una muestra de la crudeza del\linvierno.$"
MahoganyTown_Gym_Text_CherishPokemon:
	.string "Cuando el hielo y la nieve se\nderriten,\lla primavera florece de nuevo.\lTus POKéMON y tú estaréis juntos\ldurante\lmuchos años venideros.\l¡Atesora cada instante a su lado!$"
MahoganyTown_Gym_Text_PryceRematch:
	.string "¡Ah, el mismísimo CAMPEÓN de JOHTO!\nTu talento es verdaderamente\lformidable.\lEstoy impresionado.\lPero incluso ahora, aún tenemos\lmucho que\laprender el uno del otro.\lYo, FREDO, el maestro del invierno,\ltodavía\lguardo algún que otro as en la\lmanga.\l¿Aceptas una revancha conmigo?$"
MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "Ah, una vez más me rindo ante tu\ntalento.\lCon esa férrea voluntad que posees,\lsuperarás\ltodos los obstáculos que te depare\lla vida.$"
MahoganyTown_Gym_Text_Guide:
	.string "FREDO es todo un veterano que lleva\nunos\l50 años entrenando POKéMON.\lTiene un plantel solidísimo para\lfrenar lo que\lsea que le tires encima.\lEl fuego es una gran opción para\lempezar,\l¡pero ten cuidado si hace llover!$"
MahoganyTown_Gym_Text_GuideWin:
	.string "FREDO es un fenómeno, ¡pero tú eres\nde otra\lgalaxia!\l¡Ha sido un combate que ha\lderretido la\lbrecha generacional!$"
MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "¡Voy a congelar a tus POKéMON para\nque no\lpuedas mover ni un dedo!$"
MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "Mecachis. No he podido hacer nada.$"
MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "Creo que hay un movimiento que los\nPOKéMON\lpueden usar incluso estando\lcongelados.$"
MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "Este GIMNASIO tiene una pista\nresbaladiza.\lEs divertido, ¿verdad?\l¡Pero oye, que no hemos venido a\ljugar!$"
MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "¿Ves lo en serio que vamos?$"
MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "Este GIMNASIO es la caña.\n¡Me flipa patinar con mis POKéMON!$"
MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "Me sé el secreto de FREDO.$"
MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "Vale. Te contaré el secreto de\nFREDO.$"
MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "El secreto tras la fuerza de FREDO…\nMedita todos los días bajo una\lcascada\lhelada para templar cuerpo y mente.$"
MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "Para llegar hasta FREDO, nuestro\nLÍDER,\ltienes que pensar muy bien antes de\ldeslizarte.$"
MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "¡Esquiando no te dejaría ganarme!$"
MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "Si no esquías con precisión\nmilimétrica,\lno llegarás muy lejos en este\lGIMNASIO.$"
MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "¡Mira qué viraje en paralelo me\nmarco!$"
MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "¡Nooo! ¡Me has hecho darme un\nleñazo!$"
MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "No debí haberme tirado tantas\nflores con\lmi técnica de esquí…$"
