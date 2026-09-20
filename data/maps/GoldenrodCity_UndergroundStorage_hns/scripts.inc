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
	.string "¿Cómo has llegado tan lejos?\nSupongo que no queda otra: te\lborraré de\len medio.$"
RadioTowerBasement_Text_GruntM24Beaten:
	.string "¡El borrado he sido yo…!$"
RadioTowerBasement_Text_GruntM24After:
	.string "El TEAM ROCKET seguirá en pie\naguardando el\lregreso de GIOVANNI.\lHaremos lo que haga falta.$"
RadioTowerBasement_Text_GruntM14Seen:
	.string "¡De aquí no pasas!\n¡No tengo piedad con mis enemigos,\lni aunque\lsean unos mocosos!$"
RadioTowerBasement_Text_GruntM14Beaten:
	.string "¡Maldita sea!$"
RadioTowerBasement_Text_GruntM14After:
	.string "He perdido…\n¡Perdóneme, señor GIOVANNI!$"
RadioTowerBasement_Text_GruntM15Seen:
	.string "¡Jia, jia, jia! ¡Mira quién anda\npor aquí!\l¿Listo? ¡Ahora soy un hueso duro de\lroer!$"
RadioTowerBasement_Text_GruntM15Beaten:
	.string "¡Jia, jia, jia! ¡Eres buenísimo!\nEsto del TEAM ROCKET es solo un\ltrabajo, pero\lveo que hace daño a los demás.\lSe acabó, me largo de aquí.\lMuchas gracias. ¡Lo siento,\lGIOVANNI!$"
RadioTowerBasement_Text_GruntM15After:
	.string "¡Jia, jia, jia! ¡Vaya pasada de\ncombate!\l¡Me acordaré de ti!$"
RadioTowerBasement_Text_DirectorIntro:
	.string "DIRECTOR: ¿Quién? ¿Cómo? ¿Has\nvenido a\lrescatarme?\l¡Muchísimas gracias!\l¡La TORRE RADIO!\l¿Qué está pasando allí?\l¿Tomada por el TEAM ROCKET?\l¡Toma, llévate esta LLAVE\lMAGNÉTICA!$"
RadioTowerBasement_Text_DirectorCardKey:
	.string "DIRECTOR: Úsala para abrir las\ncompuertas\lde la 3P.$"
RadioTowerBasement_Text_DirectorAfter:
	.string "Te suplico que nos ayudes.\nQuién sabe qué harán si controlan\lla antena.\l¡Podrían someter a todos los\lPOKéMON con una\lseñal especial!\lEres la única persona a la que\lpuedo recurrir.\l¡Por favor, salva la TORRE RADIO…\ly a todos los POKéMON de la nación!$"
