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
	.string "La gente entrena en este FARO.\pNo es fácil subir con tantos\nEntrenadores esperando dentro.$"
OlivineLighthouse_Text_1FPokefanF:
	.string "Antaño, los POKéMON iluminaban\nel mar de OLIVO por la noche.\pEste FARO se construyó en honor\na aquellos nobles POKéMON.$"
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
	.string "¡Los hombres de mar siempre tenemos\nganas de una buena pelea!$"
OlivineLighthouse_Text_SailorHueyBeaten:
	.string "¡Urf!\n¡Pierdo!$"
OlivineLighthouse_Text_SailorHueyAfter:
	.string "¡Qué fuerza! ¿Te gustaría surcar\nlos mares conmigo?$"
OlivineLighthouse_Text_HueyRegister:
	.string "¡Qué fuerza! ¿Te gustaría surcar\nlos mares conmigo?$"
OlivineLighthouse_Text_HueyRematchIntro:
	.string "¡Los hombres de mar siempre tenemos\nganas de una buena pelea!$"
OlivineLighthouse_Text_HueyRematchDefeat:
	.string "¡Urf!\n¡Pierdo!$"
OlivineLighthouse_Text_HueyPostRematch:
	.string "¡Qué fuerza! ¿Te gustaría surcar\nlos mares conmigo?$"
OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "¿Eh? Este no es lugar para\njugar.$"
OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "¡Ah! Ya veo que vas\nen serio.$"
OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "En lo alto hay un POKéMON que\nmantiene encendido el FARO.\pPero dicen que está enfermo y\nno pueden curarlo normalmente.$"
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
	.string "¿Qué haces aquí? ¿Solo vienes a\nmirar? ¡Te sugiero que te vayas!$"
OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "De verdad te preocupa el\nPOKéMON enfermo…$"
OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "¿Cómo demonios se sube?\pQuiero ver al POKéMON enfermo,\npero no consigo llegar…$"
OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Los marineros somos buenos y\nfuertes. ¿Y tú?$"
OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "También eres bueno y fuerte…$"
OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Siempre que regreso a OLIVO,\nvisito el GIMNASIO.\pEl tipo de POKéMON de la LÍDER\ncambió sin que me diera cuenta.$"
OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Viajo por el mundo entrenando a\nmis POKéMON. Quiero luchar contigo.$"
OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…Suspiro… Debo entrenar más…$"
OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "Antes, YASMINA usaba POKéMON de\ntipo ROCA, como ONIX.$"
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
	.string "YASMINA está muy preocupada\npor el POKéMON de aquí.\pÚltimamente ni siquiera sonríe.$"
OlivineLighthouse_Text_SailorKentBeaten:
	.string "A mí tampoco me sale una sonrisa…$"
OlivineLighthouse_Text_SailorKentAfter:
	.string "Hablando de enfermedades, dicen que\nhay una gran FARMACIA en ORQUÍDEA.$"
OlivineLighthouse_Text_LassConnieSeen:
	.string "YASMINA es la LÍDER de esta ciudad.\pHe venido a llevarla al GIMNASIO.\p¡Más vale que nadie se interponga!$"
OlivineLighthouse_Text_LassConnieBeaten:
	.string "¡Aaaah! ¡Mis POKéMON!$"
OlivineLighthouse_Text_LassConnieAfter:
	.string "Es normal. Cualquiera se preocupa\nsi hieren a su propio POKéMON.\pRezaré por el POKéMON del FARO para\nque YASMINA vuelva al GIMNASIO.$"
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
	.string "Quería luchar con YASMINA, pero\nahora no está para combates.\pAsí que ¿qué tal tú?$"
OlivineLighthouse_Text_SailorErnestBeaten:
	.string "¡Vaya, vaya! ¡Eres arrollador!$"
OlivineLighthouse_Text_SailorErnestAfter:
	.string "Ser LÍDER de GIMNASIO no consiste\nsolo en ser fuerte.\pUn buen LÍDER también debe ser\ncompasivo.$"
OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "Estamos muy alto. Mis POKéMON\npájaro están en plena forma.$"
OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Ups… Han caído en picado…$"
OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mis POKéMON aprendieron VUELO en\nCIUDAD ORQUÍDEA.\pBueno, como he perdido, cruzaré\nel mar VOLANDO…$"
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
	.string "YASMINA: …Este POKéMON siempre\n"
	.string "iluminaba el mar por la noche.\p"
	.string "…Pero enfermó de repente…\n"
	.string "Le cuesta mucho respirar…\p"
	.string "…Sé que hay una gran FARMACIA\n"
	.string "en CIUDAD ORQUÍDEA…\p"
	.string "Pero está al otro lado del mar…\n"
	.string "Y no puedo dejar solo a AMPHY.$"
OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…¿Podrías traerme una medicina?\n"
	.string "Por favor…$"
OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Hay una gran FARMACIA\n"
	.string "en CIUDAD ORQUÍDEA…\p"
	.string "Pero está al otro lado del mar…\n"
	.string "Y no puedo dejar solo a AMPHY.\p"
	.string "…¿Podrías traerme una medicina?\n"
	.string "Por favor…$"
OlivineLighthouse_Text_JasmineCureAmphy:
	.string "YASMINA: …¿Esa medicina podrá\n"
	.string "curar a AMPHY?$"
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
	.string "YASMINA: …Esto… No te lo tomes\n"
	.string "a mal…\p"
	.string "…AMPHY no acepta nada de nadie\n"
	.string "que no sea yo.$"
OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "YASMINA: …\p"
	.string "AMPHY, ¿cómo te encuentras?$"
OlivineLighthouse_Text_JasmineThankYou:
	.string "YASMINA: …Qué alivio…\p"
	.string "Es sencillamente maravilloso…\p"
	.string "Muchísimas gracias de verdad.\p"
	.string "…Volveré al GIMNASIO…\p"
	.string "También te advierto: los de ACERO\n"
	.string "son muy poderosos.$"
OlivineLighthouse_Text_JasmineISee:
	.string "YASMINA: …Entiendo…\n"
	.string "…¡Resiste, AMPHY!$"
OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: …\n…Pa… paluuu…$"
OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Le cuesta muchísimo\n"
	.string "respirar…$"
OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: ¡Palu! ¡Palulu!$"
