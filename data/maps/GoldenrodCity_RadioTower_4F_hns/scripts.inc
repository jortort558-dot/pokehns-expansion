GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "PROTÓN: ¡Espera un segundo!\p¿No eres quien se interpuso en\nnuestro camino en el POZO SLOWPOKE?\pYa veo… Haces todo esto porque\nquieres enfadarme. ¡Ten cuidado!\pYa que lo deseas, ¡te mostraré\ntoda la furia de un EJECUTIVO del\lTEAM ROCKET!$"
GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Uf...$"
GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "PROTÓN: Puede que hayas ganado esta\nvez… Pero solo has conseguido que\lla furia del TEAM ROCKET aumente.$"
GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "Escuchaba la radio mientras estaba\nen las RUINAS.\pOí allí una emisión extraña.$"
GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "ROSA: ¿Por qué tengo que sufrir\nyo todo esto?\p¡MEOWTH, ayúdame!$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "ROSA: ¡Oh! ¡Mi pequeño salvador!\p¿Aceptarías esto como gratitud?$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "ROSA: Sirve para esquivar los\nataques del rival.$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "ROSA: ¡Escúchame en LA HORA DEL\nPROF. OAK!$"
GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MEOWTH: ¡Meowth…!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "¿Planeas rescatar al DIRECTOR?\p¡No podrás, porque voy a vencerte!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "¡No! ¡Increíble!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "¡No me lo puedo creer! ¡Me ha\nvencido!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "¡Alto! ¡Soy la fortaleza\ndel TEAM ROCKET!\p¡No darás ni un paso más!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "¡La fortaleza se ha desmoronado!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Te has ganado mi respeto, así que\nte daré un consejo.\pAún estás a tiempo de volver atrás.$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "¿Que si los POKéMON son adorables?\p¡Los míos me parecerán adorables\ndespués de vencer a los tuyos!$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "¡Ay, no! ¡Son unos inútiles!$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "¡Me amo a mí y a mi belleza!\p¿A quién le importan los POKéMON?$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Sencillamente magistral.\pEsta TORRE RADIO culminará nuestro\ngran plan.$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Mmm…\pTodo gran plan tiene tropiezos.$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "¿De verdad crees que puedes detener\nal TEAM ROCKET?$"
GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4P PRODUCCIÓN$"
GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4P ESTUDIO 2$"
