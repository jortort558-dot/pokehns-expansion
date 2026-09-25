Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "¡Debes prepararte para todo!\p"
    .string "¡Veamos si has criado bien\n"
    .string "a tus POKéMON!$"

Route45_Text_HikerErikBeaten:
    .string "¡Vaya, he perdido!$"

Route45_Text_HikerErikAfter:
    .string "Volveré a la RUTA HELADA de\n"
    .string "ENDRINO para seguir entrenando.$"

Route45_Text_HikerMichaelSeen:
    .string "¡Eh! ¡Tienes agallas! ¿Pero sabes\n"
    .string "qué?\p"
    .string "¡Si hablamos de puro coraje,\n"
    .string "yo soy el rey!$"

Route45_Text_HikerMichaelBeaten:
    .string "¡A mis POKéMON les faltó coraje!$"

Route45_Text_HikerMichaelAfter:
    .string "¡Me encanta el MÁS PS! ¡Qué rico!\p"
    .string "¡Siempre me bebo el de mis POKéMON!\p"
    .string "¡No puedo evitarlo!$"

Route45_Text_HikerParrySeen:
    .string "¡Mis POKéMON rebosan poder!$"

Route45_Text_HikerParryBeaten:
    .string "¡Jajaja! ¡He perdido a lo grande!$"

Route45_Text_HikerParryAfter:
    .string "Pensar no se me da muy bien.\p"
    .string "¡Así que avanzo usando la fuerza!$"

Route45_Text_ParryRegister:
    .string "Pensar no se me da muy bien.\p"
    .string "¡Así que avanzo usando la fuerza!$"

Route45_Text_ParryRematchIntro:
    .string "¡Mis POKéMON rebosan poder!$"

Route45_Text_ParryRematchDefeat:
    .string "¡Jajaja! ¡He perdido a lo grande!$"

Route45_Text_ParryPostRematch:
    .string "Pensar no se me da muy bien.\p"
    .string "¡Así que avanzo usando la fuerza!$"

Route45_Text_HikerTimothySeen:
    .string "¿Por qué escalo montañas?\p"
    .string "Porque están ahí.\p"
    .string "¿Por qué entreno POKéMON?\p"
    .string "¡Porque están ahí!$"

Route45_Text_HikerTimothyBeaten:
    .string "Las derrotas… ¡También están ahí!$"

Route45_Text_HikerTimothyAfter:
    .string "Lo mejor que me ha pasado jamás\n"
    .string "fue descubrir a los POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "¡No encuentro la forma de ganar!\p"
    .string "¡Sigue así!\p"
    .string "Ah, toma esto. Es el regalo que\n"
    .string "no pudiste llevarte la última vez.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Estaba entrenando aquí solo.\p"
    .string "¡Contempla el fruto de mi esfuerzo!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "¡Aaaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Esto exige medidas extremas.\p"
    .string "Debo ir a la montaña y entrenar\n"
    .string "en soledad.$"

Route45_Text_KenjiRegister:
    .string "Esto exige medidas extremas.\p"
    .string "Debo ir a la montaña y entrenar\n"
    .string "en soledad.$"

Route45_Text_KenjiRematchIntro:
    .string "Estaba entrenando aquí solo.\p"
    .string "¡Contempla el fruto de mi esfuerzo!$"

Route45_Text_KenjiRematchDefeat:
    .string "¡Aaaaargh!$"

Route45_Text_KenjiPostRematch:
    .string "Esto exige medidas extremas.\p"
    .string "Debo ir a la montaña y entrenar\n"
    .string "en soledad.$"

Route45_Text_KenjiHasItem:
    .string "¡Eh! Estoy descansando un poco.\p"
    .string "Encontré algo bueno ahí fuera.\n"
    .string "¡Toma, es para ti!$"

Route45_Text_KenjiGaveItem:
    .string "¡Úsalo bien!\p"
    .string "Debo volver a entrenar.\n"
    .string "¡Oooooaaaaarrrgh!$"

Route45_Text_KenjiNoRoom:
    .string "Mmm, tienes la BOLSA llena.\p"
    .string "Vuelve cuando tengas sitio.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Entrenaré un poco más antes\n"
    .string "de parar para comer.$"

Route45_Text_BlackbeltKenjiNight:
    .string "Descansamos bien durante la comida.\p"
    .string "¡Ya estamos listos para seguir!\n"
    .string "¡Volvamos a entrenar!$"

Route45_Text_CooltrainermRyanSeen:
    .string "¿Qué opinas sobre la crianza\n"
    .string "de POKéMON?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Te has ganado mi respeto.$"

Route45_Text_CooltrainermRyanAfter:
    .string "Veo que crías a tus POKéMON\n"
    .string "con mucho cariño.\p"
    .string "Ese vínculo te salvará cuando\n"
    .string "las cosas se pongan difíciles.$"

Route45_Text_CooltrainerfKellySeen:
    .string "¿Cuál es tu estrategia de combate?\p"
    .string "Usar ataques fuertes sin pensar\n"
    .string "es una necedad.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Está bien. He perdido.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "No me gustan los movimientos\n"
    .string "excesivamente potentes.\p"
    .string "Quiero ganar, pero tampoco quiero\n"
    .string "hacer daño a los POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "¡Soy muy, pero que muy fuerte!$"

Route45_Text_CamperQuentinBeaten:
    .string "En la COLINA DESAFÍO era fuerte…$"

Route45_Text_CamperQuentinAfter:
    .string "¿Has ido a la COLINA DESAFÍO?\p"
    .string "Allí nunca pierdo, pero…$"

Route45_Text_Sign:
    .string "RUTA 45\n"
    .string "MÁS ADELANTE: SENDA MONTAÑOSA$"
