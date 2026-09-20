NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "¡Mira! ¡Fíjate en mi mochila!\pHe impreso las fotos de mis POKéMON\nfavoritos de la POKéDEX y las he\lpegado por todas partes.$"
NationalPark_Normal_Text_PokefanF:
	.string "Esta es una CARTA que me mandó mi\nhija.\l¡Me alegra el día cada vez que la\lleo!$"
NationalPark_Normal_Text_Teacher1:
	.string "¡Presten atención, por favor!\p...¡Uy! Tengo que dejar de hablar\ncomo\luna profesora a todas horas.\pTú debes de entrenar POKéMON,\n¿verdad?\pComo te estás esforzando tanto,\nquiero\lque te quedes con esto.$"
NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Equípale esa GARRA RÁPIDA a un\nPOKéMON.\pA veces le permitirá atacar primero\nen\lcombate.$"
NationalPark_Normal_Text_Youngster1:
	.string "Estoy jugando con las pegatinas que\nhe\limpreso de mi POKéDEX.$"
NationalPark_Normal_Text_Youngster2:
	.string "Si le gano, me quedo con las\npegatinas\lde la POKéDEX de mi colega.$"
NationalPark_Normal_Text_Teacher2:
	.string "Paseo por el PARQUE a menudo, pero\nnunca\lme meto en la hierba alta.\pLos Entrenadores siempre tienen\nganas de\lpelea...\pSeguro que has librado muchos\ncombates.\lDeja que cure a tus POKéMON.$"
NationalPark_Normal_Text_Persian:
	.string "PERSIAN: ¡Fufushaa!$"
NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "El mundo de los POKéMON es inmenso.\pAún hay montones de cosas que nadie\nsabe.\p¡Pero yo sé mucho más que tú!$"
NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "¿C-cómo? ¡No puede ser!$"
NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Hay muchísimo que aprender.\pPor ejemplo...\pExisten 92 tipos de MT distintas.\pLos POKéMON intercambiados suben de\nnivel mucho más rápido.$"
NationalPark_Normal_Text_JackRegister:
	.string "Hay muchísimo que aprender.\pPor ejemplo...\pExisten 92 tipos de MT distintas.\pLos POKéMON intercambiados suben de\nnivel mucho más rápido.$"
NationalPark_Normal_Text_JackRematchIntro:
	.string "¡He aprendido un montón desde la\núltima\lvez! ¡Vamos a combatir!$"
NationalPark_Normal_Text_JackRematchDefeat:
	.string "¿C-cómo? ¡No me lo creo!$"
NationalPark_Normal_Text_JackPostRematch:
	.string "Hay muchísimo que aprender.\pPor ejemplo...\pExisten 92 tipos de MT distintas.\pLos POKéMON intercambiados suben de\nnivel mucho más rápido.$"
NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mis POKéMON son un auténtico\nprimor.\pDéjame contarte lo orgullosa que me\nsiento de mis ricuras.$"
NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Podré ganarte en orgullo, pero...$"
NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Debo admitir que tus POKéMON\ntambién\lson bastante monos.$"
NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "Adoramos a nuestros POKéMON,\n¡incluso si\lnos tienen un poco de manía!\pDe eso trata ser un buen FAN.$"
NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "¡M-mis POKéMON!$"
NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "He perdido el combate, pero mis\nPOKéMON\lse llevan el premio a los más\ladorables.$"
NationalPark_Normal_Text_LassKrise_Seen:
	.string "¿Hola? ¿Por qué te me quedas\nmirando?\p¿Acaso quieres un combate?$"
NationalPark_Normal_Text_LassKrise_Beaten:
	.string "...Mmm...$"
NationalPark_Normal_Text_LassKrise_After:
	.string "¡Pensaba que te me quedabas mirando\nporque soy una monada!$"
NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "PLAZA DEL DESCANSO\nPARQUE NACIONAL$"
NationalPark_Normal_Text_Sign_BattleNotice:
	.string "¿Qué dice este aviso?\pSe ruega combatir únicamente en la\nhierba.\pOFICINA DEL GUARDA DEL PARQUE\nNACIONAL$"
NationalPark_Normal_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\pImprime una CARTA abriéndola y\npulsando\lel botón START.$"
NationalPark_Normal_Text_BeverlyRegister:
	.string "Debo admitir que tus POKéMON\ntambién\lson bastante monos.$"
NationalPark_Normal_Text_BeverlyHasItem:
	.string "¡Hola! Tengo un detalle para ti.\p¡Por favor, acéptalo como muestra\nde mi\lagradecimiento!$"
NationalPark_Normal_Text_BeverlyGaveItem:
	.string "¡Mis adorables POKéMON y yo te\nestaremos animando!$"
NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Vaya, llevas la MOCHILA a tope.\pVuelve cuando tengas algo de hueco.$"
