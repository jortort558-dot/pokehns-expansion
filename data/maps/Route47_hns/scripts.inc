Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Echar de menos a otros es…\n"
	.string "lo que tiene.\p"
	.string "Pero un combate es un combate,\n"
	.string "¡así que adelante!$"

Route47_Text_HikerBeaten::
	.string "¡Ja, ja, ja!$"

Route47_Text_HikerAfter::
	.string "¡Después de combatir, hay que\n"
	.string "despedirse con una carcajada!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "No soporto las multitudes, así que\n"
	.string "¡estoy acampando aquí con mis\l"
	.string "POKéMON!$"

Route47_Text_CamperBeaten::
	.string "Supongo que debería adentrarme más\n"
	.string "en la montaña…$"

Route47_Text_CamperAfter::
	.string "¡Nos vemos!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM: Uno más uno son dos. Pero\n"
	.string "¡juntos somos mucho más\l"
	.string "fuertes!\p"
	.string "KAE: ¡No somos una pareja\n"
	.string "cualquiera!$"

Route47_Text_Couple1Beaten::
	.string "THOM: No era lo que esperaba.\l"
	.string "KAE: ¡Tú tampoco eres normal!$"

Route47_Text_Couple1After1::
	.string "THOM: ¡Parece imposible predecir\n"
	.string "tu poder!$"

Route47_Text_Couple1After2::
	.string "KAE: Creí que eras un Entrenador\n"
	.string "solitario cualquiera. ¡Qué error!$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF: ¡Cuidar de mi novia hace\n"
	.string "que mi corazón vuele!\p"
	.string "EDA: ¡Lo que siento por mi novio\n"
	.string "es tan ancho y profundo como\l"
	.string "el océano!$"

Route47_Text_Couple2Beaten::
	.string "DUFF: No estuve a tu altura…\l"
	.string "EDA: Eres realmente increíble…$"

Route47_Text_Couple2After1::
	.string "DUFF: ¡Gracias por este combate\n"
	.string "impresionante! ¡Adiós!$"

Route47_Text_Couple2After2::
	.string "EDA: ¡Tú también deberías buscar\n"
	.string "una pareja maravillosa!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "¡Vaya, hola!\p"
	.string "Dicen que tras este agujero había\n"
	.string "una enorme torre que se alzaba\l"
	.string "hasta el cielo.\p"
	.string "Era una torre bastante extraña,\n"
	.string "con la mitad incrustada\l"
	.string "en el acantilado.\p"
	.string "No solo se elevaba hacia el cielo,\n"
	.string "¡también se hundía en las\l"
	.string "profundidades de la tierra!\p"
	.string "¡Se rumorea que llegaba incluso\n"
	.string "al fondo del océano!\p"
	.string "En resumen, las ruinas conectaban\n"
	.string "el cielo, la tierra y el mar\l"
	.string "entre sí…\p"
	.string "La mayor parte se ha derrumbado.\n"
	.string "Solo quedan la entrada y sus salas,\l"
	.string "donde verás dibujos extraños.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "CHINCHOU: ¡Chou!$"
