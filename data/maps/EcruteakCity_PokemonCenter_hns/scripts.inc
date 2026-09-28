EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "¡Hola! Soy BILL. ¿Y tú quién\n"
	.string "eres?\p"
	.string "Hmm, ¿{PLAYER}? Vaya, has\n"
	.string "llegado en el momento justo.$"
EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Acabo de terminar de ajustar el\n"
	.string "Sistema de Almacenamiento de\l"
	.string "POKéMON.\p"
	.string "Como estabas usando mi invento,\n"
	.string "pensé en venir a saludarte en\l"
	.string "persona.\p"
	.string "Tengo que volver a mi casa en\n"
	.string "CIUDAD TRIGAL con mi familia.\p"
	.string "¡Nos vemos luego!$"
EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "El camino hacia el GIMNASIO\n"
	.string "flota en la oscuridad.\p"
	.string "Dicen que si te desvías del\n"
	.string "sendero, te caes y vuelves a la\l"
	.string "entrada.$"
EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Quieres combatir con más gente,\n"
	.string "¿verdad?\p"
	.string "Dicen que hay un lugar donde se\n"
	.string "reúnen muchos ENTRENADORES.\p"
	.string "¿Dónde? Algo más allá de OLIVO.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTI, el LÍDER de GIMNASIO, es\n"
	.string "un tipo misterioso y genial.\p"
	.string "Sus POKéMON son súper fuertes,\n"
	.string "¡me dejó alucinada en combate!$"
EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "El LAGO DE LA FURIA...\p"
	.string "La repentina aparición de una\n"
	.string "plaga de GYARADOS...\p"
	.string "Aquí hay gato encerrado. ¡Huelo\n"
	.string "una conspiración fijo!$"
