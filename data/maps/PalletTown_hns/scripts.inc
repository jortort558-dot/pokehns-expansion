PalletTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_EventScript_HoennLegendsNPC::
	lock
	faceplayer
	setvar VAR_0x8008, 0

PalletTown_EventScript_CheckKyogre:
	checkspecies SPECIES_KYOGRE
	goto_if_eq VAR_RESULT, FALSE, PalletTown_EventScript_CheckGroudon
	goto_if_set FLAG_RECEIVED_BLUE_ORB_HNS, PalletTown_EventScript_CheckGroudon
	msgbox PalletTown_Text_SeenKyogreGiveBlueOrb, MSGBOX_DEFAULT
	checkitemspace ITEM_BLUE_ORB, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_BLUE_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BLUE_ORB_HNS
	msgbox PalletTown_Text_BlueOrbExplain, MSGBOX_DEFAULT
	addvar VAR_0x8008, 1

PalletTown_EventScript_CheckGroudon:
	checkspecies SPECIES_GROUDON
	goto_if_eq VAR_RESULT, FALSE, PalletTown_EventScript_CheckRayquaza
	goto_if_set FLAG_RECEIVED_RED_ORB_HNS, PalletTown_EventScript_CheckRayquaza
	msgbox PalletTown_Text_SeenGroudonGiveRedOrb, MSGBOX_DEFAULT
	checkitemspace ITEM_RED_ORB, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_RED_ORB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_RED_ORB_HNS
	msgbox PalletTown_Text_RedOrbExplain, MSGBOX_DEFAULT
	addvar VAR_0x8008, 1

PalletTown_EventScript_CheckRayquaza:
	checkspecies SPECIES_RAYQUAZA
	goto_if_eq VAR_RESULT, FALSE, PalletTown_EventScript_CheckFinished
	msgbox PalletTown_Text_AskTeachDragonAscent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_EventScript_DragonAscentDeclined
	setvar VAR_0x8005, MOVE_DRAGON_ASCENT
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_RESULT, FALSE, PalletTown_EventScript_DragonAscentDeclined
	msgbox PalletTown_Text_DragonAscentTaught, MSGBOX_DEFAULT
	release
	end

PalletTown_EventScript_CheckFinished:
	goto_if_ne VAR_0x8008, 0, PalletTown_EventScript_EndConversation
	checkspecies SPECIES_KYOGRE
	goto_if_eq VAR_RESULT, TRUE, PalletTown_EventScript_PraiseLegendaries
	checkspecies SPECIES_GROUDON
	goto_if_eq VAR_RESULT, TRUE, PalletTown_EventScript_PraiseLegendaries
	checkspecies SPECIES_RAYQUAZA
	goto_if_eq VAR_RESULT, TRUE, PalletTown_EventScript_PraiseLegendaries
	msgbox PalletTown_Text_HoennLegendsIntro, MSGBOX_DEFAULT
	release
	end

PalletTown_EventScript_PraiseLegendaries:
	msgbox PalletTown_Text_HoennLegendsHonored, MSGBOX_DEFAULT
	release
	end

PalletTown_EventScript_EndConversation:
	release
	end

PalletTown_EventScript_DragonAscentDeclined:
	msgbox PalletTown_Text_DragonAscentDeclined, MSGBOX_DEFAULT
	release
	end

PalletTown_Text_HoennLegendsIntro:
	.string "Vengo de la lejana región de\n"
	.string "Hoenn siguiendo antiguas leyendas.\p"
	.string "Cuentan que los colosos de la\n"
	.string "tierra, el mar y los cielos…\p"
	.string "despiertan su poder primigenio al\n"
	.string "entrar en contacto con reliquias\l"
	.string "del pasado.\p"
	.string "Si alguna vez viajas con Groudon,\n"
	.string "Kyogre o Rayquaza en tu equipo,\l"
	.string "ven a verme.$"

PalletTown_Text_SeenKyogreGiveBlueOrb:
	.string "¡Increíble! ¡Ese que te acompaña\n"
	.string "es nada menos que Kyogre!\p"
	.string "He custodiado esta reliquia de los\n"
	.string "océanos durante años…\p"
	.string "En tus manos alcanzará su pleno\n"
	.string "potencial.$"

PalletTown_Text_BlueOrbExplain:
	.string "Ese Prisma Azul despertará la\n"
	.string "Regresión Primigenia de Kyogre\l"
	.string "si lo lleva equipado en combate.$"

PalletTown_Text_SeenGroudonGiveRedOrb:
	.string "¡Por todos los volcanes!\n"
	.string "¡Llevas contigo al gran Groudon!\p"
	.string "Conservo esta gema milenaria de\n"
	.string "la tierra profunda…\p"
	.string "Te pertenece por derecho.$"

PalletTown_Text_RedOrbExplain:
	.string "Ese Prisma Rojo liberará la\n"
	.string "Regresión Primigenia de Groudon\l"
	.string "si lo lleva equipado en combate.$"

PalletTown_Text_AskTeachDragonAscent:
	.string "¡Increíble! El soberano de los\n"
	.string "cielos, Rayquaza, vuela a tu lado!\p"
	.string "Conozco el arte ancestral del\n"
	.string "movimiento Ascenso Draco.\p"
	.string "Con él, Rayquaza podrá alcanzar la\n"
	.string "Megaevolución durante el combate.\p"
	.string "¿Quieres que se lo enseñe ahora?$"

PalletTown_Text_DragonAscentTaught:
	.string "¡Maravilloso! Rayquaza ha\n"
	.string "dominado Ascenso Draco.\p"
	.string "¡Su rugido rasgará los cielos\n"
	.string "con el poder de la Megaevolución!$"

PalletTown_Text_DragonAscentDeclined:
	.string "Entiendo. Si decides que Rayquaza\n"
	.string "aprenda Ascenso Draco, aquí estaré.$"

PalletTown_Text_HoennLegendsHonored:
	.string "Es todo un honor contemplar a los\n"
	.string "titanes de Hoenn junto a ti.\p"
	.string "¡Cuida bien de ellos y de sus\n"
	.string "poderes primigenios!$"	

PalletTown_Text_Teacher:
	.string "También crío POKéMON.\p"
	.string "Me sirven de guardaespaldas.$"

PalletTown_Text_Fisher:
	.string "¡La tecnología es increíble!\p"
	.string "Puedes intercambiar POKéMON en el\n"
	.string "tiempo como si fueran correos.$"

PalletTown_Text_Sign:
	.string "PUEBLO PALETA\p"
	.string "Un lugar tranquilo de paz\n"
	.string "y pureza$"

PalletTown_Text_RedsHouseSign:
	.string "CASA DE ROJO$"

PalletTown_Text_OaksLabSign:
	.string "LABORATORIO POKéMON\n"
	.string "DE OAK$"

PalletTown_Text_BluesHouseSign:
	.string "CASA DE AZUL$"
