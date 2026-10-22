EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Common_EventScript_PokegearMomAmuletCoinNotice::
	lockall
	setflag FLAG_MOM_AMULET_COIN_CALLED
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Mom_Text_AmuletCoinCall
	waitmessage
	delay 30
	releaseall
	end

Mom_Text_AmuletCoinCall:
	.string "MAMÁ: ¡Enhorabuena, cariño!\p"
	.string "¡Ya eres CAMPEÓN de KANTO!\n"
	.string "Estoy muy orgullosa de ti.\p"
	.string "Tengo un regalo especial\n"
	.string "esperándote en casa.\p"
	.string "Ven a verme cuando puedas.\n"
	.string "¡Cuídate mucho!$"

Mom_Text_GiftCall_Item:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "He comprado algo bonito\n"
	.string "para ti con tus ahorros.\p"
	.string "Lo he enviado a tu PC.\n"
	.string "¡Cuídate!$"

Mom_Text_GiftCall_Berry:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "He encontrado unas BAYAS\n"
	.string "muy buenas para ti.\p"
	.string "Las he enviado a tu PC.\n"
	.string "¡Cuídate!$"

Mom_Text_GiftCall_Decoration:
	.string "MAMÁ: ¡Hola, cariño!\p"
	.string "He comprado un MUÑECO POKéMON\n"
	.string "muy mono para tu habitación.\p"
	.string "Mira tus ADORNOS cuando vuelvas\n"
	.string "a casa. ¡Cuídate!$"
