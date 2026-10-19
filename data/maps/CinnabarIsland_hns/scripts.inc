CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	setflag FLAG_HIDE_MOHEDANO_CINNABAR_BATEMAGICO
	call_if_set FLAG_BILL_MOHEDANO_TERMINAL_READ, CinnabarIsland_EventScript_CheckMohedanoChapter
	end

CinnabarIsland_EventScript_CheckMohedanoChapter::
	goto_if_set FLAG_MOHEDANO_CINNABAR_COMPLETE, CinnabarIsland_EventScript_CheckMohedanoEnd
	clearflag FLAG_HIDE_MOHEDANO_CINNABAR_BATEMAGICO
CinnabarIsland_EventScript_CheckMohedanoEnd::
	return

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
	.string "BLAINE: ¡No me rendiré hasta\n"
	.string "reconstruir el\l"
	.string "GIMNASIO CANELA!\p"
	.string "Mientras tanto estaré en el\n"
	.string "DOJO KARATE.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "¿Quién eres?\p"
	.string "Está claro que eres\n"
	.string "ENTRENADOR…\p"
	.string "Me llamo BLUE.\p"
	.string "Una vez fui CAMPEÓN, aunque solo\n"
	.string "durante muy poco tiempo…\p"
	.string "Ese entrometido de RED me venció…\p"
	.string "En fin, ¿qué quieres? ¿Pretendes\n"
	.string "desafiarme o algo así?\p"
	.string "…Me fastidia decirlo, pero ahora\n"
	.string "no me apetece combatir.\p"
	.string "Mira bien a tu alrededor…\p"
	.string "Un volcán entra en erupción y, de\n"
	.string "pronto, desaparece todo un pueblo.\p"
	.string "Podemos ganar y perder con los\n"
	.string "POKéMON, pero si la naturaleza se\l"
	.string "agita, perdemos en un instante.\p"
	.string "…\p"
	.string "Así son las cosas…\p"
	.string "Pero sigo siendo ENTRENADOR.\p"
	.string "Cuando veo a un rival fuerte,\n"
	.string "me entran ganas de combatir.\p"
	.string "Si quieres luchar conmigo, antes\n"
	.string "necesitarás 15 MEDALLAS.\p"
	.string "Entonces aceptaré tu desafío.$"

CinnabarIsland_Text_Blue:
	.string "¿Quién eres?\p"
	.string "Está claro que eres\n"
	.string "ENTRENADOR…\p"
	.string "Me llamo BLUE.\p"
	.string "Una vez fui CAMPEÓN, aunque solo\n"
	.string "durante muy poco tiempo…\p"
	.string "Ese entrometido de RED me venció…\p"
	.string "En fin, ¿qué quieres? ¿Pretendes\n"
	.string "desafiarme o algo así?\p"
	.string "…Me fastidia decirlo, pero ahora\n"
	.string "no me apetece combatir.\p"
	.string "Mira bien a tu alrededor…\p"
	.string "Un volcán entra en erupción y, de\n"
	.string "pronto, desaparece todo un pueblo.\p"
	.string "Podemos ganar y perder con los\n"
	.string "POKéMON, pero si la naturaleza se\l"
	.string "agita, perdemos en un instante.\p"
	.string "…\p"
	.string "Así son las cosas…\p"
	.string "Pero sigo siendo ENTRENADOR.\p"
	.string "Cuando veo a un rival fuerte,\n"
	.string "me entran ganas de combatir.\p"
	.string "Si quieres luchar conmigo, ven al\n"
	.string "GIMNASIO VERDE.\p"
	.string "Allí aceptaré tu desafío.$"

CinnabarIsland_EventScript_Sign::
	goto_if_set FLAG_BILL_MOHEDANO_TERMINAL_READ, CinnabarIsland_EventScript_VolcanoClue
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_VolcanoClue::
	setflag FLAG_MOHEDANO_CINNABAR_CLUE_VOLCANO
	msgbox CinnabarIsland_Text_VolcanoClue, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	goto_if_set FLAG_BILL_MOHEDANO_TERMINAL_READ, CinnabarIsland_EventScript_LabClue
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_LabClue::
	setflag FLAG_MOHEDANO_CINNABAR_CLUE_LAB
	msgbox CinnabarIsland_Text_LabClue, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_Batemagico::
	lock
	faceplayer
	setspeaker SP_NAME_BATEMAGICO
	goto_if_unset FLAG_MOHEDANO_CINNABAR_CLUE_VOLCANO, CinnabarIsland_EventScript_BatemagicoMissingClues
	goto_if_unset FLAG_MOHEDANO_CINNABAR_CLUE_LAB, CinnabarIsland_EventScript_BatemagicoMissingClues
	goto_if_defeated TRAINER_MOHEDANO_EXPERIMENT_HNS, CinnabarIsland_EventScript_BatemagicoAfterExperiment
	msgbox CinnabarIsland_Text_BatemagicoExperiment, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MOHEDANO_EXPERIMENT_HNS, CinnabarIsland_Text_ExperimentDefeated
CinnabarIsland_EventScript_BatemagicoAfterExperiment::
	setspeaker SP_NAME_BATEMAGICO
	msgbox CinnabarIsland_Text_BatemagicoSilph, MSGBOX_DEFAULT
	setflag FLAG_MOHEDANO_CINNABAR_COMPLETE
	setflag FLAG_HIDE_MOHEDANO_CINNABAR_BATEMAGICO
	closemessage
	removeobject LOCALID_CINNABAR_BATEMAGICO
	release
	end

CinnabarIsland_EventScript_BatemagicoMissingClues::
	msgbox CinnabarIsland_Text_BatemagicoMissingClues, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Text_GymSign:
	.string "Hay un aviso…\p"
	.string "El GIMNASIO CANELA se ha trasladado\n"
	.string "a las ISLAS ESPUMA.\p"
	.string "BLAINE$"

CinnabarIsland_Text_Sign:
	.string "ISLA CANELA\p"
	.string "El pueblo del ardiente deseo$"

CinnabarIsland_Text_VolcanoClue:
	.string "Entre la ceniza hay una placa.\p"
	.string "PROYECTO TABULA RASA.\n"
	.string "Fuente térmica: CANELA.\p"
	.string "Alguien ha raspado la firma.$"

CinnabarIsland_Text_LabClue:
	.string "Bajo el aviso hay un informe.\p"
	.string "FUJI rechazó el ensayo final.\n"
	.string "La muestra fue enviada a SILPH.\p"
	.string "Una nota añade: BILL sabe.$"

CinnabarIsland_Text_BatemagicoMissingClues:
	.string "Las ruinas hablan, pero hay que\n"
	.string "saber dónde mirar.\p"
	.string "Revisa los dos carteles.$"

CinnabarIsland_Text_BatemagicoExperiment:
	.string "Has unido las piezas.\p"
	.string "MOHEDANO usó el calor volcánico\n"
	.string "para calcinar los registros\l"
	.string "del PROYECTO TABULA RASA.\p"
	.string "¡Cuidado! Ese investigador...\n"
	.string "¡Es el custodio de MOHEDANO y\l"
	.string "viene a silenciarnos!$"

CinnabarIsland_Text_ExperimentDefeated:
	.string "Los datos... ya han sido\n"
	.string "transferidos a SILPH...$"

CinnabarIsland_Text_BatemagicoSilph:
	.string "Ese sujeto intentaba destruir\n"
	.string "hasta la última prueba.\p"
	.string "Pero lo logramos: el informe\n"
	.string "confirma que BILL descubrió la\l"
	.string "red secreta de MOHEDANO.\p"
	.string "Por eso lo tienen retenido.\p"
	.string "¡Rápido! Nos vemos en la sede\n"
	.string "de SILPH S.A., en AZAFRÁN.$"
