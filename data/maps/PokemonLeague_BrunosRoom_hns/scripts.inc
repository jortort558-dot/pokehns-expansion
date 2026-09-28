PokemonLeague_BrunosRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC

PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_POSTOBC_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "BRUNO: Has vuelto, digno oponente.\p"
    .string "Nuestro riguroso entrenamiento\n"
    .string "nos ha hecho más fuertes.\p"
    .string "Mi voluntad de piedra es ahora\n"
    .string "todavía más firme e inquebrantable.\p"
    .string "¿Puedes afrontar un desafío mayor?\p"
    .string "Muéstrame el fruto de tu esfuerzo.\p"
    .string "¡Ja, ja!$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "Soy BRUNO, miembro del ALTO MANDO.\p"
    .string "Entreno siempre al límite porque\n"
    .string "creo en nuestro potencial.\p"
    .string "Así es como nos hicimos fuertes.\n"
    .string "¿Podrás soportar nuestro poder?\p"
    .string "¿Mmm? No veo miedo en tus ojos.\n"
    .string "¡Tu determinación es perfecta!\p"
    .string "¿Todo listo, {PLAYER}? Cederás\n"
    .string "ante nuestro poder arrollador!\p"
    .string "¡Ja, ja!$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "¿Cómo hemos podido perder?$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "Tras perder, no tengo derecho\n"
    .string "a decir nada…\p"
    .string "¡Ve y afronta tu próximo desafío!$"
