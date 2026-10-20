.set LOCALID_TOXICOLOGIST, 22
.set LOCALID_KALIGULA, 23

FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	call FuchsiaCity_EventScript_UpdatePoisoningActors
	end

FuchsiaCity_EventScript_UpdatePoisoningActors::
	goto_if_unset FLAG_SILPH_CO_ZYGARDE_CUBE_RECEIVED, FuchsiaCity_EventScript_HidePoisoningActors
	goto_if_set FLAG_FUCHSIA_BLACK_SLUDGE_RECEIVED, FuchsiaCity_EventScript_HidePoisoningActors
	clearflag FLAG_HIDE_FUCHSIA_TOXICOLOGIST
	goto_if_set FLAG_FUCHSIA_KALIGULA_EXPOSED, FuchsiaCity_EventScript_HideKaligula
	clearflag FLAG_HIDE_FUCHSIA_KALIGULA
	return

FuchsiaCity_EventScript_HidePoisoningActors::
	setflag FLAG_HIDE_FUCHSIA_TOXICOLOGIST

FuchsiaCity_EventScript_HideKaligula::
	setflag FLAG_HIDE_FUCHSIA_KALIGULA
	return

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "DIRECTOR BAOBA: ¡{PLAYER}!\p"
	.string "Soy el DIRECTOR BAOBA.\p"
	.string "¡Ha ocurrido algo terrible!\n"
	.string "¡Compraron mi antigua ZONA SAFARI\l"
	.string "de FUCSIA y acaban de reabrirla!\p"
	.string "¡Y al parecer tienen nuevos POKéMON\n"
	.string "exóticos!\p"
	.string "¡Eso perjudicará mi negocio!\p"
	.string "{PLAYER}, debes entrar en la nueva\n"
	.string "ZONA SAFARI y atrapar un POKéMON\l"
	.string "y enseñármelo. Debo averiguar qué\l"
	.string "tienen de “exóticos”.\p"
	.string "¡Por favor, {PLAYER}, mi negocio\n"
	.string "depende de ti!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	goto_if_unset FLAG_FUCHSIA_POISONING_STARTED, FuchsiaCity_EventScript_FinishSample
	goto_if_set FLAG_FUCHSIA_WATER_SAMPLE, FuchsiaCity_EventScript_FinishSample
	msgbox FuchsiaCity_Text_WaterSample, MSGBOX_DEFAULT
	setflag FLAG_FUCHSIA_WATER_SAMPLE

FuchsiaCity_EventScript_FinishSample::
	release
	end

FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	goto_if_unset FLAG_FUCHSIA_POISONING_STARTED, FuchsiaCity_EventScript_FinishSample
	goto_if_set FLAG_FUCHSIA_BERRY_SAMPLE, FuchsiaCity_EventScript_FinishSample
	msgbox FuchsiaCity_Text_BerrySample, MSGBOX_DEFAULT
	setflag FLAG_FUCHSIA_BERRY_SAMPLE
	goto FuchsiaCity_EventScript_FinishSample

FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	goto_if_unset FLAG_FUCHSIA_POISONING_STARTED, FuchsiaCity_EventScript_FinishSample
	goto_if_set FLAG_FUCHSIA_MUD_SAMPLE, FuchsiaCity_EventScript_FinishSample
	msgbox FuchsiaCity_Text_MudSample, MSGBOX_DEFAULT
	setflag FLAG_FUCHSIA_MUD_SAMPLE
	goto FuchsiaCity_EventScript_FinishSample

FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Toxicologist::
	lock
	faceplayer
	goto_if_set FLAG_FUCHSIA_KALIGULA_EXPOSED, FuchsiaCity_EventScript_ToxicologistReward
	goto_if_set FLAG_FUCHSIA_POISONING_STARTED, FuchsiaCity_EventScript_ToxicologistProgress
	msgbox FuchsiaCity_Text_ToxicologistIntro, MSGBOX_DEFAULT
	setflag FLAG_FUCHSIA_POISONING_STARTED
	release
	end

FuchsiaCity_EventScript_ToxicologistProgress::
	goto_if_unset FLAG_FUCHSIA_WATER_SAMPLE, FuchsiaCity_EventScript_ToxicologistMissingSamples
	goto_if_unset FLAG_FUCHSIA_BERRY_SAMPLE, FuchsiaCity_EventScript_ToxicologistMissingSamples
	goto_if_unset FLAG_FUCHSIA_MUD_SAMPLE, FuchsiaCity_EventScript_ToxicologistMissingSamples
	msgbox FuchsiaCity_Text_ToxicologistKaligula, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_EventScript_ToxicologistMissingSamples::
	msgbox FuchsiaCity_Text_ToxicologistProgress, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_EventScript_ToxicologistReward::
	checkitemspace ITEM_BLACK_SLUDGE, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_EventScript_ToxicologistBagFull
	msgbox FuchsiaCity_Text_ToxicologistReward, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_SLUDGE
	msgbox FuchsiaCity_Text_ToxicologistDepart, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_TEMP_0, 23, FuchsiaCity_EventScript_ToxicologistRunUpWest
	applymovement LOCALID_TOXICOLOGIST, FuchsiaCity_Movement_ToxicologistRunWest
	waitmovement LOCALID_TOXICOLOGIST
	goto FuchsiaCity_EventScript_ToxicologistFinishDepart

FuchsiaCity_EventScript_ToxicologistRunUpWest::
	applymovement LOCALID_TOXICOLOGIST, FuchsiaCity_Movement_ToxicologistRunUpWest
	waitmovement LOCALID_TOXICOLOGIST

FuchsiaCity_EventScript_ToxicologistFinishDepart::
	removeobject LOCALID_TOXICOLOGIST
	setflag FLAG_FUCHSIA_BLACK_SLUDGE_RECEIVED
	setflag FLAG_HIDE_FUCHSIA_TOXICOLOGIST
	release
	end

FuchsiaCity_Movement_ToxicologistRunWest:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

FuchsiaCity_Movement_ToxicologistRunUpWest:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

FuchsiaCity_EventScript_ToxicologistBagFull::
	msgbox FuchsiaCity_Text_ToxicologistBagFull, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_EventScript_Kaligula::
	lock
	faceplayer
	goto_if_unset FLAG_FUCHSIA_POISONING_STARTED, FuchsiaCity_EventScript_KaligulaCover
	goto_if_unset FLAG_FUCHSIA_WATER_SAMPLE, FuchsiaCity_EventScript_KaligulaMislead
	goto_if_unset FLAG_FUCHSIA_BERRY_SAMPLE, FuchsiaCity_EventScript_KaligulaMislead
	goto_if_unset FLAG_FUCHSIA_MUD_SAMPLE, FuchsiaCity_EventScript_KaligulaMislead
	msgbox FuchsiaCity_Text_KaligulaExposed, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KALIGULA_FUCHSIA_HNS, FuchsiaCity_Text_KaligulaDefeated
	msgbox FuchsiaCity_Text_KaligulaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KALIGULA, FuchsiaCity_Movement_KaligulaRunAway
	waitmovement LOCALID_KALIGULA
	removeobject LOCALID_KALIGULA
	setflag FLAG_FUCHSIA_KALIGULA_EXPOSED
	setflag FLAG_HIDE_FUCHSIA_KALIGULA
	release
	end

FuchsiaCity_Movement_KaligulaRunAway:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

FuchsiaCity_EventScript_KaligulaCover::
	msgbox FuchsiaCity_Text_KaligulaCover, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_EventScript_KaligulaMislead::
	msgbox FuchsiaCity_Text_KaligulaMislead, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Text_WaterSample:
	.string "El agua tiene un brillo aceitoso.\p"
	.string "Has recogido una muestra.$"

FuchsiaCity_Text_BerrySample:
	.string "Hay bayas ennegrecidas junto al\n"
	.string "Kangaskhan.\p"
	.string "Has recogido una muestra.$"

FuchsiaCity_Text_MudSample:
	.string "El lodo desprende un olor químico.\p"
	.string "Has recogido una muestra.$"

FuchsiaCity_Text_ToxicologistIntro:
	.string "Soy toxicóloga de la ZONA SAFARI.\p"
	.string "Alguien ha contaminado el agua y\n"
	.string "varios Pokémon están enfermos.\p"
	.string "Necesito muestras del agua, de las\n"
	.string "bayas y del lodo de los estanques.\p"
	.string "Examina a Dratini, Kangaskhan y\n"
	.string "Omanyte, por favor.$"

FuchsiaCity_Text_ToxicologistProgress:
	.string "Aún faltan muestras del agua, las\n"
	.string "bayas o el lodo.\p"
	.string "Revisa a Dratini, Kangaskhan y\n"
	.string "Omanyte.$"

FuchsiaCity_Text_ToxicologistKaligula:
	.string "Las tres muestras contienen el\n"
	.string "mismo compuesto artificial.\p"
	.string "El científico que merodea junto a\n"
	.string "los recintos oculta algo.$"

FuchsiaCity_Text_ToxicologistReward:
	.string "¡Kaligula era el saboteador!\p"
	.string "He neutralizado el veneno y los\n"
	.string "Pokémon se recuperarán.\p"
	.string "Este Lodo Negro quedó purificado.\n"
	.string "Quédatelo.$"

FuchsiaCity_Text_ToxicologistDepart:
	.string "Iré a entregar las muestras a los\n"
	.string "agentes de la ciudad y terminar el\l"
	.string "tratamiento de los recintos.\p"
	.string "¡Gracias por tu ayuda, Entrenador!$"

FuchsiaCity_Text_ToxicologistBagFull:
	.string "No tienes sitio para el Lodo Negro.\n"
	.string "Haz hueco y vuelve.$"

FuchsiaCity_Text_KaligulaCover:
	.string "Solo estudio el deterioro causado\n"
	.string "por la gestión privada del parque.$"

FuchsiaCity_Text_KaligulaMislead:
	.string "La contaminación es el precio de\n"
	.string "poner el beneficio por encima de\l"
	.string "la vida.\p"
	.string "Busca pruebas antes de acusar.$"

FuchsiaCity_Text_KaligulaExposed:
	.string "Así que has seguido el rastro...\p"
	.string "Soy Kaligula. Silph envenena el\n"
	.string "mundo y luego privatiza la cura.\p"
	.string "Yo solo he acelerado la verdad.\n"
	.string "¡La ciencia será del pueblo!\p"
	.string "¡Te demostraré la auténtica fuerza\n"
	.string "del veneno!$"

FuchsiaCity_Text_KaligulaDefeated:
	.string "¡Maldita sea! ¿Cómo puedes tener\n"
	.string "semejante compenetración?$"

FuchsiaCity_Text_KaligulaPostBattle:
	.string "La ciencia no tiene dueño...\n"
	.string "Al menos en eso tenía razón.\p"
	.string "Pero no me atraparás aquí.$"

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Uno del ALTO MANDO fue LÍDER del\n"
	.string "GIMNASIO de FUCSIA.$"

FuchsiaCity_Text_PokefanM:
	.string "La hija de KOGA lo sustituyó como\n"
	.string "LÍDER cuando él entró en el\l"
	.string "ALTO MANDO.$"

FuchsiaCity_Text_Teacher:
	.string "La ZONA SAFARI tiene una nueva\n"
	.string "dirección.\p"
	.string "¡Y montones de POKéMON nuevos!$"

FuchsiaCity_Text_Sign:
	.string "CIUDAD FUCSIA\p"
	.string "¡Contempla el rosa pasión!$"

FuchsiaCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE FUCSIA\n"
	.string "LÍDER: JANINE\p"
	.string "La maestra ninja venenosa$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Hay un aviso…\p"
	.string "La OFICINA de la ZONA SAFARI está\n"
	.string "cerrada hasta nuevo aviso.$"

FuchsiaCity_Text_SafariZone:
	.string "ZONA SAFARI\n"
	.string "PROPIEDAD DE\l"
	.string "DEVON S. A.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "El GUARDA está de viaje.\p"
	.string "Por eso, la ZONA SAFARI está\n"
	.string "cerrada.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No tires basura.\p"
	.string "Llévate tus residuos, por favor.$"
