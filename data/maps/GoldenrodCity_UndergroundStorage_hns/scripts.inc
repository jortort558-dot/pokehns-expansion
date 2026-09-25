GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
	.string "¿Cómo has llegado tan lejos?\pNo queda otra. Me desharé de ti.$"
RadioTowerBasement_Text_GruntM24Beaten:
	.string "¡El borrado he sido yo…!$"
RadioTowerBasement_Text_GruntM24After:
	.string "El TEAM ROCKET seguirá adelante,\nesperando el regreso de GIOVANNI.\pHaremos lo que sea necesario.$"
RadioTowerBasement_Text_GruntM14Seen:
	.string "¡No pasarás de aquí!\pNo tengo piedad con mis enemigos,\n¡ni siquiera con los críos!$"
RadioTowerBasement_Text_GruntM14Beaten:
	.string "¡Maldita sea!$"
RadioTowerBasement_Text_GruntM14After:
	.string "He perdido…\p¡Perdóname, GIOVANNI!$"
RadioTowerBasement_Text_GruntM15Seen:
	.string "¡Jia, jia! ¡Mira quién está aquí!\p¿Listo? ¡Ahora soy muy fuerte!$"
RadioTowerBasement_Text_GruntM15Beaten:
	.string "¡Jia, jia, jia! ¡Eres muy bueno!\pEl TEAM ROCKET es solo un trabajo,\npero veo que hace daño a otros.\pSe acabó, me marcho.\p¡Gracias! ¡Lo siento, GIOVANNI!$"
RadioTowerBasement_Text_GruntM15After:
	.string "¡Jia, jia, jia! ¡Qué gran combate!\n¡Me acordaré de ti!$"
RadioTowerBasement_Text_DirectorIntro:
	.string "DIRECTOR: ¿Quién? ¿Qué? ¿Has venido\na rescatarme?\p¡Gracias!\p¡La TORRE RADIO!\p¿Qué ocurre allí?\p¿La tomó el TEAM ROCKET?\pToma esta LLAVE MAGNÉTICA.$"
RadioTowerBasement_Text_DirectorCardKey:
	.string "DIRECTOR: Úsala para abrir las\ncompuertas de la 3P.$"
RadioTowerBasement_Text_DirectorAfter:
	.string "Te suplico que nos ayudes.\pNo sabemos qué harán si controlan\nel transmisor.\p¡Podrían controlar a los POKéMON\ncon una señal especial!\pEres la única persona a quien\npuedo recurrir.\pSalva la TORRE RADIO, por favor…\p¡Y a todos los POKéMON del país!$"
