SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "CÉSAR: ¡Hola, {PLAYER}!\p"
	.string "El guardia de arriba huyó en\n"
	.string "cuanto le pegué cuatro gritos.\p"
	.string "¡Pero me he resbalado al entrar\n"
	.string "en este maldito pozo!\p"
	.string "Me he hecho polvo la espalda y no\n"
	.string "me puedo ni mover… ¡Maldición!\p"
	.string "Si estuviera entero, mis POKéMON\n"
	.string "les habrían dado un buen escarmiento.\p"
	.string "En fin, no queda otra.\p"
	.string "¡{PLAYER}, demuestra tu valor y\n"
	.string "dales su merecido por mí!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "CÉSAR: ¡Así se hace, {PLAYER}!\p"
	.string "¡El TEAM ROCKET se ha dado\n"
	.string "a la fuga!\p"
	.string "Parece que la espalda ya me duele\n"
	.string "algo menos. ¡Salgamos de aquí!$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "¡Maldita sea! Estaba de guardia\n"
	.string "arriba cuando un viejo me gritó.\p"
	.string "¡Me dio tal susto que me caí al\n"
	.string "fondo del pozo!\p"
	.string "¡Ahora pagarás tú los platos rotos!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "¡Aaargh! ¡Hoy no es mi día!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Sí, les cortamos las colas a los\n"
	.string "SLOWPOKE para venderlas.\p"
	.string "Todo lo que hacemos es por dinero.\p"
	.string "¡Somos el TEAM ROCKET y haremos\n"
	.string "lo que sea por hacernos ricos!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "¿Pero qué quieres tú ahora?\p"
	.string "¡Si te atreves a interrumpir\n"
	.string "nuestro trabajo, no esperes piedad!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Hoy te ha salido bien la jugada,\n"
	.string "¡pero no cantes victoria tan pronto!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Sí, el TEAM ROCKET fue disuelto\n"
	.string "hace tres años.\p"
	.string "El jefe se ocultó en las sombras.\p"
	.string "¡Pero nosotros seguimos operando\n"
	.string "desde la clandestinidad!\p"
	.string "Un estorbo como tú jamás detendrá\n"
	.string "nuestros gloriosos planes.\p"
	.string "¡Tiembla ante lo que está a punto\n"
	.string "de suceder en JOHTO!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "¡Ja, ja, ja!\n"
	.string "¿Que dejemos las COLASLOWPOKE?\p"
	.string "¡Estás de broma!\p"
	.string "¡Si te hiciéramos caso, arruinarías\n"
	.string "la reputación del TEAM ROCKET!$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Argh…\n"
	.string "¡Demasiada fuerza…!$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "Necesitamos la pasta, ¿pero vender\n"
	.string "COLASLOWPOKE?\p"
	.string "¡Qué dura es la vida del recluta!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "¿Dejar en paz sus colas?\p"
	.string "¡A ver si tienes lo que hay que\n"
	.string "tener para vencernos a todos!$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "¡Mocoso impertinente!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "¡Las COLASLOWPOKE crecen enseguida!\p"
	.string "¿Qué tiene de malo que saquemos\ntajada?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un SLOWPOKE con la COLA cortada…\p"
	.string "¿Eh? Lleva una CARTA.\n"
	.string "¿Quieres leerla?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} leyó la CARTA.\p"
	.string "Sé buena y cuida de la casa con\n"
	.string "el abuelo y SLOWPOKE.\p"
	.string "Con cariño, Papá.$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un pobre SLOWPOKE con la COLA\ncortada…$"
