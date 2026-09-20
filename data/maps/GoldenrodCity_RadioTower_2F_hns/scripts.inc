GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA: ¿Eh? ¿La contraseña de hoy?\n¡SOCORRO, por supuesto!$"
GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "Puedes escuchar la radio en\ncualquier\lrincón. ¡Sintonízala!$"
GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Acceso restringido a partir de este\npunto.$"
GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Las nanas de la radio pueden hacer\nque los\lPOKéMON se queden dormidos.$"
GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "¿Para qué querrán apoderarse de la\nTORRE RADIO?$"
GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "JIGGLYPUFF: ¡Jiggly…!$"
GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Lo siento. Solo personal autorizado\na partir\lde esta puerta.\lAntes no era así de estricto.\lAl DIRECTOR le pasa algo muy raro…$"
GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Siéntete libre de mirar por donde\nquieras.\lEl DIRECTOR vuelve a ser tan majo\lcomo\lsiempre.$"
GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "¡Hace tres años obligaron al TEAM\nROCKET a\ldisolverse!\l¡Pero aquí y ahora marcamos nuestro\lregreso!$"
GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "¡Gwaaah! ¡No te pases de listo!$"
GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "¡No permitiremos que arruines\nnuestros planes\lde renacimiento!$"
GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "¡Somos el TEAM ROCKET, los amos que\nexplotan\la los POKéMON!\l¡Nos flipa ser malos! ¿Tiemblas de\lmiedo?$"
GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "¿Pero tú te crees algún héroe de\ncuento?$"
GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "No siempre somos malvados.\nSimplemente hacemos\llo que nos sale de las narices.$"
GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "¡Ehh, tú! ¡Quítate de en medio!$"
GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Aaaargh. Me rindo.$"
GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Nuestros EJECUTIVOS están ocupando\ntodo el\ledificio.\lTienen un plan gigantesco. ¿Cuál\lserá?$"
GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "¡Jajaja!\nQué aburrimiento. ¡Tomar este sitio\lha sido\ldemasiado fácil!\l¡Venga, entreténme un rato!$"
GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "¿P-pero quién eres tú?$"
GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "Me has ganado, ¡pero no pienso\nolvidarlo!$"
GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: ¡Sintoniza mi SHOW DE LA\nCONTRASEÑA!\l¡Escúchalo para enterarte de la\lclave de hoy!$"
GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "BUENA: ¡Hola, hola!\n¿Sabes ya la contraseña de hoy?\n¡Muy bien! ¿Cuál es?$"
GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "BUENA: ¡La has clavado!\n¡Toma este {STR_VAR_1} como premio!$"
GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "BUENA: ¡Error! ¡Qué lástima!\n¡Prueba suerte mañana!$"
GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "BUENA: ¿No lo tienes claro?\n¡Vuelve cuando estés preparado!$"
GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "BUENA: ¡Ya acertaste la clave de\nhoy!\l¡Vuelve a sintonizarnos mañana!$"
GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "BUENA: ¡Has acertado, pero tienes\nla\lMOCHILA llena!\l¡Haz hueco y ven a hablarme otra\lvez!$"
GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2P VENTAS$"
GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "LA HORA DEL PROF. OAK\n¡El programa más escuchado de las\londas!$"
GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "Radio POKéMON: donde sea y cuando\nsea$"
