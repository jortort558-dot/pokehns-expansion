Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "MAGIKARP: Kaaaarp.$"

Route12_Text_NewFisher:
	.string "Cuidado, algo feroz vive en estas\n"
	.string "aguas.$"

Route12_Text_FisherMartinSeen:
	.string "La paciencia es la"
	.string "\nclave para pescar"
	.string "\l$y criar POKéMON."
Route12_Text_FisherMartinBeaten:
	.string "Gwaaah!$"

Route12_Text_FisherMartinAfterBattle:
	.string "Soy demasiado impaciente para\n"
	.string "pescar…$"

Route12_Text_FisherStephenSeen:
	.string "Me encanta pescar mientras escucho\n"
	.string "música en la radio.$"

Route12_Text_FisherStephenBeaten:
	.string "¡Mi estúpida radio me distrajo!$"

Route12_Text_FisherStephenAfterBattle:
	.string "¿Conoces las"
	.string "\nemisoras de"
	.string "\pradio de KANTO?"
	.string "\n$Tenemos muchas."
Route12_Text_FisherBarneySeen:
	.string "¿Qué es lo más"
	.string "\nimportante en"
	.string "\l$nuestras vidas?"
Route12_Text_FisherBarneyBeaten:
	.string "¡La respuesta"
	.string "\n$vendrá luego!"
Route12_Text_FisherBarneyAfterBattle:
	.string "Creo que la"
	.string "\nelectricidad es lo"
	.string "\pmás importante en"
	.string "\nnuestras vidas."
	.string "\pSi no lo fuera, no"
	.string "\nse habría montado"
	.string "\ptanto follón"
	.string "\ncuando se estropeó"
	.string "\pla CENTRAL"
	.string "\n$ENERGÍA."
Route12_Text_KyleRegister:
	.string "No olvidaré esto.\n"
	.string "¡Dame tu número!$"

Route12_Text_KyleRematchIntro:
	.string "¿Te habías olvidado?\n"
	.string "¡Vamos a comprobarlo!$"

Route12_Text_KyleRematchDefeat:
	.string "Te acordabas.$"

Route12_Text_KylePostRematch:
	.string "¡La emoción de luchar casi iguala\n"
	.string "a la de una gran captura!$"

Route12_Text_FisherKyleSeen:
	.string "$¿Te acuerdas?"
Route12_Text_FisherKyleBeaten:
	.string "$Te acuerdas, ¿no?"
Route12_Text_FisherKyleAfterBattle:
	.string "El tirón de la"
	.string "\nCAÑA cuando ha"
	.string "\lpicado un POKéMON…"
	.string "\pÉsa es la mejor"
	.string "\nsensación para un"
	.string "\l$pescador como yo."
Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "RUTA 12"
	.string "\pPUEBLO LAVANDA"
	.string "\n$HACIA EL NORTE"
Route12_Text_FishingSpotSign:
	.string "FISHING SPOT$"
