.set LOCALID_JUANRA_TABLE, 1
.set LOCALID_JUANRA_SECRET, 2

GoldenrodCity_House4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_House4_OnTransition
	.byte 0

GoldenrodCity_House4_OnTransition::
	setflag FLAG_HIDE_JUANRA_SECRET
	compare VAR_JUANRA_STATE, 2
	goto_if_eq GoldenrodCity_House4_EventScript_ReturnJuanraToTable
	clearflag FLAG_HIDE_JUANRA_TABLE
	end

GoldenrodCity_House4_EventScript_ReturnJuanraToTable::
	setvar VAR_JUANRA_STATE, 3
	clearflag FLAG_HIDE_JUANRA_TABLE
	end

GoldenrodCity_House4_EventScript_JuanraTable::
	lock
	faceplayer
	compare VAR_JUANRA_STATE, 0
	goto_if_eq GoldenrodCity_House4_EventScript_JuanraStory
	compare VAR_JUANRA_STATE, 3
	goto_if_eq GoldenrodCity_House4_EventScript_JuanraApology
	compare VAR_JUANRA_STATE, 4
	goto_if_eq GoldenrodCity_House4_EventScript_JuanraAfterReward
	msgbox GoldenrodCity_House4_Text_JuanraAfterStory, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House4_EventScript_JuanraStory::
	msgbox GoldenrodCity_House4_Text_JuanraStory, MSGBOX_DEFAULT
	checkitemspace ITEM_FESTIVAL_TICKET, 1
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_House4_EventScript_NoRoom
	giveitem ITEM_FESTIVAL_TICKET, 1
	setvar VAR_JUANRA_STATE, 1
	msgbox GoldenrodCity_House4_Text_FirstTicket, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House4_EventScript_JuanraApology::
	msgbox GoldenrodCity_House4_Text_JuanraApology, MSGBOX_DEFAULT
	checkitemspace ITEM_FESTIVAL_TICKET, 5
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_House4_EventScript_NoRoom
	giveitem ITEM_FESTIVAL_TICKET, 5
	setvar VAR_JUANRA_STATE, 4
	msgbox GoldenrodCity_House4_Text_CubataTicket, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House4_EventScript_NoRoom::
	msgbox GoldenrodCity_House4_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House4_EventScript_JuanraAfterReward::
	msgbox GoldenrodCity_House4_Text_JuanraAfterReward, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_House4_EventScript_MainTelevision::
	compare VAR_JUANRA_STATE, 1
	goto_if_lt GoldenrodCity_House4_EventScript_TelevisionOff
	warp MAP_GOLDENROD_CITY_HOUSE4_HNS, 19, 17
	waitstate
	end

GoldenrodCity_House4_EventScript_SecretTelevision::
	warp MAP_GOLDENROD_CITY_HOUSE4_HNS, 2, 2
	waitstate
	end

GoldenrodCity_House4_EventScript_TelevisionOff::
	msgbox GoldenrodCity_House4_Text_TelevisionOff, MSGBOX_SIGN
	end

GoldenrodCity_House4_EventScript_Secrets::
	compare VAR_JUANRA_STATE, 1
	goto_if_eq GoldenrodCity_House4_EventScript_StartJuanraBattle
	msgbox GoldenrodCity_House4_Text_SecretsAfterBattle, MSGBOX_SIGN
	end

GoldenrodCity_House4_EventScript_StartJuanraBattle::
	lockall
	msgbox GoldenrodCity_House4_Text_ReadSecrets, MSGBOX_DEFAULT
	setvar VAR_JUANRA_STATE, 2
	setflag FLAG_HIDE_JUANRA_TABLE
	clearflag FLAG_HIDE_JUANRA_SECRET
	addobject LOCALID_JUANRA_SECRET
	applymovement LOCALID_JUANRA_SECRET, GoldenrodCity_House4_Movement_JuanraLeavesTelevision
	waitmovement 0
	msgbox GoldenrodCity_House4_Text_JuanraChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JUANRA_HNS, GoldenrodCity_House4_Text_JuanraDefeated
	setvar VAR_JUANRA_STATE, 3
	setflag FLAG_HIDE_JUANRA_SECRET
	removeobject LOCALID_JUANRA_SECRET
	clearflag FLAG_HIDE_JUANRA_TABLE
	addobject LOCALID_JUANRA_TABLE
	msgbox GoldenrodCity_House4_Text_JuanraWon, MSGBOX_DEFAULT
	releaseall
	end

GoldenrodCity_House4_EventScript_JuanraSecret::
	msgbox GoldenrodCity_House4_Text_JuanraChallenge, MSGBOX_NPC
	end

GoldenrodCity_House4_Movement_JuanraLeavesTelevision:
	walk_down
	step_end

GoldenrodCity_House4_Text_JuanraStory:
	.string "¿Sabes quién tienes delante?\p"
	.string "Soy JUANRA, campeón de la\n"
	.string "primera POKéMITOS CUP.\p"
	.string "Cuando era joven, nadie podía\n"
	.string "seguir mi ritmo en combate.\p"
	.string "Aquella final fue una locura.\n"
	.string "Se decidió con mi último POKéMON\l"
	.string "y todo el público en pie.\p"
	.string "Después celebramos la victoria\n"
	.string "en 'Los cubos', junto al\l"
	.string "cementerio. ¡Qué gran época!$"

GoldenrodCity_House4_Text_FirstTicket:
	.string "Toma, un vale de chupito.\p"
	.string "Y escucha este viejo acertijo:\p"
	.string "'La ventana que ni abre ni cierra\n"
	.string "guarda mis victorias bajo tierra'.\p"
	.string "Brinda por los viejos campeones.$"

GoldenrodCity_House4_Text_JuanraAfterStory:
	.string "Recuerda: la ventana que ni abre\n"
	.string "ni cierra guarda mis victorias\l"
	.string "bajo tierra.$"

GoldenrodCity_House4_Text_JuanraApology:
	.string "Perdona por lo de antes.\p"
	.string "A veces me dan arrebatos de ira\n"
	.string "al recordar aquellos combates.\p"
	.string "No debí pagarlo contigo.$"

GoldenrodCity_House4_Text_CubataTicket:
	.string "Acepta estos cinco vales.\p"
	.string "Con ellos podrás pedir un cubata\n"
	.string "y olvidar el mal trago.$"

GoldenrodCity_House4_Text_NoRoom:
	.string "Haz hueco en la mochila y vuelve.\n"
	.string "Esto merece un brindis.$"

GoldenrodCity_House4_Text_JuanraAfterReward:
	.string "Los campeones también debemos\n"
	.string "saber pedir perdón.$"

GoldenrodCity_House4_Text_TelevisionOff:
	.string "La televisión está apagada.$"

GoldenrodCity_House4_Text_ReadSecrets:
	.string "'Los secretos de sus victorias'.\p"
	.string "El primer capítulo habla de...$"

GoldenrodCity_House4_Text_JuanraChallenge:
	.string "¡Eh! ¿Quién te ha dado permiso\n"
	.string "para leer eso?\p"
	.string "¡Los secretos de un campeón se\n"
	.string "ganan combatiendo!$"

GoldenrodCity_House4_Text_JuanraDefeated:
	.string "Aún conservas fuerzas...\n"
	.string "Impresionante.$"

GoldenrodCity_House4_Text_JuanraWon:
	.string "Has ganado. Regresaré a la mesa\n"
	.string "para recuperar el aliento.$"

GoldenrodCity_House4_Text_SecretsAfterBattle:
	.string "Las páginas solo contienen fotos\n"
	.string "de JUANRA levantando un trofeo.$"
