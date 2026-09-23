TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Según cuenta la leyenda…\p"
	.string "Cuando las almas de humanos y\n"
	.string "POKéMON entran en armonía, un\l"
	.string "POKéMON de colores arcoíris\l"
	.string "desciende desde los cielos…\p"
	.string "¿Será que los POKéMON\n"
	.string "legendarios nos están poniendo a\l"
	.string "prueba?$"

TinTower_1F_Sage2_Text:
	.string "Cuando ardió la TORRE LATÓN,\n"
	.string "tres POKéMON sin nombre\l"
	.string "murieron.\p"
	.string "Fue una auténtica tragedia…\p"
	.string "Sin embargo, un POKéMON de\n"
	.string "colores arcoíris…\p"
	.string "HO-OH descendió del cielo y\n"
	.string "devolvió la vida a los tres.\p"
	.string "Eran SUICUNE, ENTEI y RAIKOU.\p"
	.string "Eso es lo que se cuenta.$"

TinTower_1F_Sage3_Text:
	.string "Dicen que las dos TORRES se\n"
	.string "alzaron para fomentar la amistad\l"
	.string "entre personas y POKéMON.\p"
	.string "Fue hace 700 años, pero ese\n"
	.string "ideal sigue siendo importante\l"
	.string "hoy.$"

TinTower_1F_Sage4_Text1:
	.string "¡Parece que HO-OH ha descendido\n"
	.string "sobre la TORRE HOJALATA!$"

TinTower_1F_Sage4_Text2:
	.string "Los POKéMON legendarios encarnan\n"
	.string "tres poderes…\p"
	.string "El rayo que alcanzó la TORRE, el\n"
	.string "fuego que la consumió y la\l"
	.string "lluvia que lo apagó…$"

TinTower_1F_Sage6_Text2:
	.string "De los POKéMON legendarios,\n"
	.string "SUICUNE es el más próximo a\l"
	.string "HO-OH.\p"
	.string "También dicen que existe un\n"
	.string "vínculo con los POKéMON llamados\l"
	.string "UNOWN.\p"
	.string "Los UNOWN deben de mantener una\n"
	.string "relación especial con SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "¡Lo sabía!\p"
	.string "Sabía que verías al POKéMON de\n"
	.string "colores arcoíris, <PLAYER>.\p"
	.string "Ha ocurrido tal como lo imaginé.\n"
	.string "¡Mi investigación no iba mal!\p"
	.string "Seguiré estudiando a los POKéMON\n"
	.string "¡hasta ser un POKéMANÍACO\l"
	.string "famoso!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: ¡Ha sido increíble!\n"
	.string "¡Nunca había visto algo así!\p"
	.string "Ha sido realmente inspirador.\n"
	.string "SUICUNE era fuerte, pero tú lo\l"
	.string "fuiste aún más, <PLAYER>.\p"
	.string "Dicen que el poder de SUICUNE\n"
	.string "invoca a un POKéMON arcoíris.\p"
	.string "Quizá lo ocurrido hoy provoque\n"
	.string "que ese POKéMON aparezca.\p"
	.string "Seguiré estudiando las leyendas.\n"
	.string "Gracias por tan gran combate.\p"
	.string "¡Hasta luego, <PLAYER>!$"
