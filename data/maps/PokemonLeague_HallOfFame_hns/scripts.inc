PokemonLeague_HallOfFame_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	clearflag FLAG_ITEM_GS_BALL
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_IS_KANTO_CHAMPION
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	call_if_ge VAR_VIRIDIAN_FOREST_PICHU, 4, PokemonLeague_HallOfFame_EventScript_SpawnPichu
	call_if_ge VAR_ALOLA_STATE, 4, PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons
	call PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons
	call_if_ge VAR_SINJOH_STORYLINE, 13 PokemonLeague_HallOfFame_EventScript_SpawnArceus
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_SUMMONED_MTMOON_JIRACHI
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons::
	clearflag FLAG_HIDE_TAPU_BULU
	clearflag FLAG_HIDE_TAPU_FINI
	clearflag FLAG_HIDE_TAPU_KOKO
	clearflag FLAG_HIDE_TAPU_LELE
	clearflag FLAG_HIDE_DUGTRIO_ALOLA
	clearflag FLAG_HIDE_MAROWAK_ALOLA
	clearflag FLAG_HIDE_EXEGGUTOR_ALOLA
	clearflag FLAG_HIDE_SANDSLASH_ALOLA
	clearflag FLAG_HIDE_NINETALES_ALOLA
	clearflag FLAG_HIDE_MUK_ALOLA
	clearflag FLAG_HIDE_RAICHU_ALOLA
	clearflag FLAG_HIDE_GOLEM_ALOLA
	return

PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons::
	clearflag FLAG_HIDE_SINJOHRUINS_REGIROCK
	clearflag FLAG_HIDE_SINJOHRUINS_REGICE
	clearflag FLAG_HIDE_SINJOHRUINS_REGISTEEL
	clearflag FLAG_HIDE_SINJOHRUINS_REGIELEKI
	clearflag FLAG_HIDE_SINJOHRUINS_REGIDRAGO
	clearflag FLAG_HIDE_SINJOHRUINS_REGIGIGAS
	return

PokemonLeague_HallOfFame_EventScript_SpawnArceus::
	clearflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_ARCEUS
	return

PokemonLeague_HallOfFame_EventScript_SpawnPichu::
	clearflag FLAG_HIDE_VIRIDIAN_FOREST_SPIKY_EARED_PICHU
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	special InitRoamer
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON_HNS
	special InitKantoRoamers
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "LANCE: Hace mucho que no venía.\p"
    .string "Aquí honramos para la eternidad\n"
    .string "a los CAMPEONES de la LIGA.\p"
    .string "Sus valientes POKéMON también\n"
    .string "quedan inscritos.\p"
    .string "Hoy hemos presenciado el nacimiento\n"
    .string "de un nuevo CAMPEÓN de la LIGA:\p"
    .string "un Entrenador que siente afecto\n"
    .string "y confianza por todos los POKéMON.\p"
    .string "Un Entrenador que triunfó gracias\n"
    .string "a su constancia y determinación.\p"
    .string "¡Un nuevo CAMPEÓN destinado\n"
    .string "a alcanzar la grandeza!\p"
    .string "{PLAYER}, permíteme inscribiros\n"
    .string "a ti y a tus compañeros\l"
    .string "como CAMPEONES.$"

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "LANCE: Recuerdo que no hace mucho\n"
    .string "te recibí aquí como CAMPEÓN\l"
    .string "de JOHTO.\p"
    .string "Y aquí estamos otra vez, en este\n"
    .string "lugar sagrado donde honramos a\l"
    .string "los mejores y a sus POKéMON.\p"
    .string "Hoy has demostrado tu valía no solo\n"
    .string "en JOHTO, sino también en KANTO,\l"
    .string "venciendo a mi equipo más fuerte.\p"
    .string "Has mostrado un afecto y confianza\n"
    .string "extraordinarios en tus POKéMON.\p"
    .string "Ese vínculo te ha conducido\n"
    .string "a la victoria una y otra vez.\p"
    .string "Tu viaje, marcado por la constancia\n"
    .string "y determinación inquebrantables,\l"
    .string "revela tu verdadero espíritu\l"
    .string "como Entrenador.\p"
    .string "Estás destinado a ser uno de los\n"
    .string "grandes, quizá el mejor.\p"
    .string "{PLAYER}, es un honor inscribiros\n"
    .string "de nuevo a ti y a tus fieles\l"
    .string "compañeros como CAMPEONES.$"
