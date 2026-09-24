OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "La gente viene a entrenar a este\nFARO.\pNo es nada fácil subir con todos\nlos\lEntrenadores que esperan dentro.$"
OlivineLighthouse_Text_1FPokefanF:
	.string "En tiempos pasados, los POKéMON\niluminaban el mar de OLIVO de\lnoche.\pEste FARO se construyó en honor a\nesos nobles POKéMON.$"
@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "¡Los hombres de mar siempre estamos\ncon\lganas de pelea!$"
OlivineLighthouse_Text_SailorHueyBeaten:
	.string "¡Urf!\n¡He perdido!$"
OlivineLighthouse_Text_SailorHueyAfter:
	.string "¡Vaya fuerza! ¿Qué te parecería\nsalir\la surcar los mares conmigo?$"
OlivineLighthouse_Text_HueyRegister:
	.string "¡Vaya fuerza! ¿Qué te parecería\nsalir\la surcar los mares conmigo?$"
OlivineLighthouse_Text_HueyRematchIntro:
	.string "¡Los hombres de mar siempre estamos\ncon\lganas de pelea!$"
OlivineLighthouse_Text_HueyRematchDefeat:
	.string "¡Urf!\n¡He perdido!$"
OlivineLighthouse_Text_HueyPostRematch:
	.string "¡Vaya fuerza! ¿Qué te parecería\nsalir\la surcar los mares conmigo?$"
OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "¿Eh? Este no es sitio para juegos\nde\lcríos.$"
OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "¡Ah! Ya veo que vas completamente\nen\lserio.$"
OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Arriba del todo hay un POKéMON que\nmantiene iluminado el FARO.\pPero he oído que ha caído enfermo y\nno\lpueden curarlo con medicinas\lnormales.$"
@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "¿Qué haces aquí? ¿Vienes de\nmirones?\l¡Pues te sugiero que te marches!$"
OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "De verdad te preocupas por el\nPOKéMON\lenfermo…$"
OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "¿Cómo demonios se sube?\pQuiero ver al POKéMON enfermo, pero\nno encuentro la forma de llegar…$"
OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Los marineros somos tan nobles como\nfuertes. ¿Y tú qué tal?$"
OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Eres igual de noble y fuerte…$"
OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Cada vez que regreso a OLIVO visito\nel GIMNASIO.\pEl tipo de POKéMON de la LÍDER\ncambió\lsin que me diese ni cuenta.$"
OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Viajo por todo el mundo entrenando\na mis\lPOKéMON. Deseo medir mis fuerzas\lcontigo.$"
OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…Suspiro… Debo entrenar todavía\nmás…$"
OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "Antes, YASMINA utilizaba POKéMON de\ntipo ROCA, como ONIX.$"
@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "YASMINA debe de estar destrozada\npor el\lPOKéMON de aquí.\pÚltimamente ni siquiera sonríe.$"
OlivineLighthouse_Text_SailorKentBeaten:
	.string "A mí tampoco me sale una sonrisa…$"
OlivineLighthouse_Text_SailorKentAfter:
	.string "Hablando de enfermos, he oído que\nhay una\lbuena FARMACIA en CIUDAD ORQUÍDEA.$"
OlivineLighthouse_Text_LassConnieSeen:
	.string "YASMINA es la LÍDER de esta ciudad.\pHe venido a hacer que regrese al\nGIMNASIO.\l¡Más vale que nadie se interponga!$"
OlivineLighthouse_Text_LassConnieBeaten:
	.string "¡Aaaah! ¡Mis POKéMON!$"
OlivineLighthouse_Text_LassConnieAfter:
	.string "Es normal. Cualquiera se\npreocuparía si\lsu propio POKéMON estuviera\lsufriendo.\pRezaré por el POKéMON del FARO para\nque YASMINA pueda volver al\lGIMNASIO.$"
@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Quería desafiar a YASMINA, pero\nahora\lno tiene cuerpo para combates.\pY bien, ¿luchas tú conmigo?$"
OlivineLighthouse_Text_SailorErnestBeaten:
	.string "¡Vaya, vaya! ¡Eres imparable!$"
OlivineLighthouse_Text_SailorErnestAfter:
	.string "Un LÍDER de GIMNASIO no solo debe\nser\lfuerte.\pUn buen LÍDER también necesita\ntener\lcompasión en el corazón.$"
OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "Estamos bastante altos aquí. Mis\nPOKéMON\lpájaro están en su salsa.$"
OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Ups… Han caído en picado…$"
OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mis POKéMON aprendieron VUELO en\nCIUDAD ORQUÍDEA.\pBueno, como he perdido, me iré\nVOLANDO sobre el mar…$"
@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "YASMINA: …Este POKéMON siempre\nmantenía\lel mar iluminado durante la noche…\p…Pero enfermó de repente… Apenas\npuede respirar…\p…He oído que hay una FARMACIA\nmagnífica\len CIUDAD ORQUÍDEA…\pPero hay que cruzar el mar… Y no\npuedo\ldejar a AMPHY solo y desatendido…$"
OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…¿Podrías hacerme el favor de\ntraerme\lla medicina? ¿Por favor?$"
OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Hay una FARMACIA maravillosa en\nCIUDAD\lORQUÍDEA…\pPero hay que cruzar el mar… Y no\npuedo\ldejar a AMPHY desatendido…\p…¿Podrías traerme esa medicina?\n¿Por favor?$"
OlivineLighthouse_Text_JasmineCureAmphy:
	.string "YASMINA: …¿Esa medicina logrará\ncurar\la AMPHY?$"
OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "¡{PLAYER} le entregó la\nPOCIÓN SECRETA a YASMINA!$"
OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "YASMINA: …Esto... Por favor, no te\nlo\ltomes a mal…\p…AMPHY desconfía y no acepta nada\nde\lnadie que no sea yo…$"
OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "YASMINA: …\pAMPHY, ¿cómo te encuentras?$"
OlivineLighthouse_Text_JasmineThankYou:
	.string "YASMINA: …¡Ay, qué alivio tan\ngrande!\pEs sencillamente maravilloso…\pMuchísimas, muchísimas gracias.\p…Ahora podré volver al GIMNASIO…\pTe advierto de que el tipo ACERO es\nmuy resistente y poderoso.$"
OlivineLighthouse_Text_JasmineISee:
	.string "YASMINA: …Ya veo…\n…¡AMPHY, aguanta por favor!$"
OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: …\n…Pa… paluuu…$"
OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Le cuesta muchísimo respirar…$"
OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: ¡Palu! ¡Palulu!$"
