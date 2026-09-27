CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

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
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "Hay un aviso…\p"
	.string "El GIMNASIO CANELA se ha trasladado\n"
	.string "a las ISLAS ESPUMA.\p"
	.string "BLAINE$"

CinnabarIsland_Text_Sign:
	.string "ISLA CANELA\p"
	.string "El pueblo del ardiente deseo$"
