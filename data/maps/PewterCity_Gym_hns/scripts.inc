PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "BROCK: Vaya, no solemos recibir\n"
	.string "aspirantes de JOHTO.\p"
	.string "Soy BROCK, LÍDER de PLATEADA.\p"
	.string "Soy experto en POKéMON tipo ROCA.\p"
	.string "Mis POKéMON resisten casi todos\n"
	.string "los ataques físicos.\p"
	.string "¡Vamos!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "BROCK: Los potentes ataques de tus\n"
	.string "POKéMON vencieron mi dura defensa…\p"
	.string "Eres más fuerte de lo esperado…\p"
	.string "Adelante, toma esta MEDALLA.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} recibió la MEDALLA ROCA.$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "Toma también esta MT.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "Contiene AVALANCHA.\p"
	.string "Arroja rocas y puede hacer\n"
	.string "retroceder al rival.\p"
	.string "Úsala para frenarlo en seco.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "BROCK: Gracias, {PLAYER}. Disfruté\n"
	.string "el combate, aunque me fastidie.\p"
	.string "La MEDALLA ROCA hará aún más\n"
	.string "poderosos a tus POKéMON.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "BROCK: El mundo es enorme. Aún hay\n"
	.string "muchos Entrenadores fuertes.\p"
	.string "Ya verás. Yo también me haré\n"
	.string "mucho más fuerte.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Los Entrenadores de este GIMNASIO\n"
	.string "usan POKéMON tipo ROCA.\p"
	.string "El tipo ROCA tiene gran DEFENSA.\p"
	.string "Los combates pueden alargarse.\n"
	.string "¿Estás listo?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Tengo que ganar estos combates…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "¡Eh, Entrenador de JOHTO! BROCK es\n"
	.string "duro. Te castigará si te confías.$"

PewterCity_Gym_Text_Guide:
	.string "¡Hola, futuro CAMPEÓN! Vas genial.\p"
	.string "¿Desafías a los LÍDERES de KANTO?\p"
	.string "Son fuertes y entregados, como los\n"
	.string "LÍDERES de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "¡Futuro CAMPEÓN! Este GIMNASIO\n"
	.string "no te ha dado problemas.\p"
	.string "Tu dominio ha sido inspirador.\n"
	.string "Lo digo en serio.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "GIMNASIO POKéMON DE PLATEADA\n"
    .string "LÍDER: BROCK\p"
	.string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "GIMNASIO POKéMON DE PLATEADA\n"
    .string "LÍDER: BROCK\p"
    .string "ENTRENADORES VENCEDORES:\n"
	.string "BLUE, RED, {PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "BROCK: Hola, {PLAYER}. Encontré a\n"
	.string "este BONSLY entrenando en el monte.\p"
	.string "Es mono, pero creo que necesita\n"
	.string "otro tipo de Entrenador.\p"
	.string "¿Cambiarías un {STR_VAR_1}\n"
	.string "por mi {STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "BROCK: ¡Gracias! ¡Cuida bien de\n"
	.string "WOODY por mí!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "BROCK: ¿No? Está bien.\n"
	.string "WOODY y yo seguiremos entrenando.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "BROCK: Ese no es un {STR_VAR_1}.\n"
	.string "No es lo que busco.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "BROCK: ¿Cómo está WOODY?\n"
	.string "¡BONSLY es más duro de lo que ves!$"

PewterCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_PLATEADA, PewterCity_Gym_EventScript_Manolin_AfterItem
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_PLATEADA, PewterCity_Gym_EventScript_Manolin_ChooseItem
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_FULL_RESTORE
	setflag FLAG_MANOLIN_HEAL_PLATEADA
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

PewterCity_Gym_EventScript_Manolin_ChooseItem::
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_PLATEADA, FALSE
	switch VAR_RESULT
	case 0, PewterCity_Gym_EventScript_Manolin_GiveHeavyDutyBoots
	case 1, PewterCity_Gym_EventScript_Manolin_GiveSmoothRock
	case MULTI_B_PRESSED, PewterCity_Gym_EventScript_Manolin_NoChoice
	end

PewterCity_Gym_EventScript_Manolin_GiveHeavyDutyBoots::
	giveitem ITEM_HEAVY_DUTY_BOOTS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_PLATEADA
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_HeavyDutyBootsExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_EventScript_Manolin_GiveSmoothRock::
	giveitem ITEM_SMOOTH_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_PLATEADA
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_SmoothRockExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_EventScript_Manolin_NoChoice::
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_EventScript_Manolin_AfterItem::
	setspeaker SP_NAME_MANOLIN
	msgbox PewterCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_Gym_Text_Manolin_Intro:
	.string "¡Qué pasa mi gente! ¡Menudo canchal!\p"
	.string "Esta es Ciudad Férrica de toda la vida,\n"
	.string "pero… ¿qué le ha pasado a la líder Petra?\l"
	.string "¿Se ha puesto mazada, se ha quitado la\l"
	.string "falda y se ha dejado tupé?\p"
	.string "Un cambio de skin muy loco, tú…\n"
	.string "Aunque las piedras pegan igual de duro.$"

PewterCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Pausa el combate, hermano!\n"
	.string "¡Que tienes a tus bichos casi en el pozo!\p"
	.string "Te cae una Avalancha encima y no lo\n"
	.string "cuenta ni el apuntador.\l"
	.string "Poción de sanación al canto.$"

PewterCity_Gym_Text_Manolin_Healed:
	.string "¡Salud restaurada al máximo y cura\n"
	.string "de reserva para el macuto!$"

PewterCity_Gym_Text_Manolin_OfferChoices:
	.string "Para no partirte los piños contra\n"
	.string "estas rocas hay que equiparse bien.\l"
	.string "¿Qué objeto bis te viene mejor?$"

PewterCity_Gym_Text_Manolin_HeavyDutyBootsExplain:
	.string "¡Las BOTAS GRUESAS son Dios en patinete!\n"
	.string "Inmunidad total a Trampa Rocas, Púas\l"
	.string "y porquerías en el suelo.\l"
	.string "Entras a la raid como si nada.$"

PewterCity_Gym_Text_Manolin_SmoothRockExplain:
	.string "¡La ROCA SUAVE alarga la Tormenta de\n"
	.string "Arena a 8 turnazos completos!\l"
	.string "Sube la Defensa Especial de tus tipos\l"
	.string "Roca y desgasta al rival sin piedad.$"

PewterCity_Gym_Text_Manolin_NoChoice:
	.string "Piénsatelo bien, que las piedras no se\n"
	.string "van a desgastar por esperar.$"

PewterCity_Gym_Text_Manolin_AfterItem:
	.string "No te confíes con la robustez del boss,\n"
	.string "¡y a romperle la defensa, mi gente!$"
