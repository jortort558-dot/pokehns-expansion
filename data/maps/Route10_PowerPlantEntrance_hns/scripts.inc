Route10_PowerPlantEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PowerPlantEntrance_OnTransition
	.byte 0

Route10_PowerPlantEntrance_OnTransition::
	call Route10_PowerPlantEntrance_EventScript_UpdateSitoVisibility
	end

Route10_PowerPlantEntrance_EventScript_UpdateSitoVisibility::
	goto_if_set FLAG_SITO_POWER_PLANT_DEFEATED, Route10_PowerPlantEntrance_EventScript_HideSito
	goto_if_set FLAG_MOHEDANO_QUEST_STARTED, Route10_PowerPlantEntrance_EventScript_ShowSito

Route10_PowerPlantEntrance_EventScript_HideSito::
	setflag FLAG_HIDE_POWER_PLANT_SITO
	return

Route10_PowerPlantEntrance_EventScript_ShowSito::
	clearflag FLAG_HIDE_POWER_PLANT_SITO
	return

Route10_PowerPlantEntrance_EventScript_Cop::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopAfterDone
	msgbox Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopDuringRocket::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopAfterDone::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_Engineer1::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer1Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer1Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer2Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Cop2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Cop2Done
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious, MSGBOX_NPC
	end
Route10_PowerPlantEntrance_EventScript_Cop2Done::
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer3Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_Trigger_Cop::
	lock
	playse SE_POKENAV_CALL
	applymovement2 LOCALID_POWERPLANT_COP, Common_Movement_ExclamationMark
	waitse
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkToPlayer
	waitmovement 0
	turnobject LOCALID_POWERPLANT_ENGINEER, DIR_SOUTH
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_POWERPLANT_COP, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkBack
	waitmovement 0
	setvar VAR_KANTO_ROCKET_STORY_STATE, 2
	clearflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	release
	end

Route10_PowerPlantEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route10_PowerPlantEntrance_Movement_WalkBack:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn:
	.string "Entró un ladrón en la\n"
	.string "CENTRAL DE ENERGÍA…\p"
	.string "¿Adónde vamos a ir a parar?$"
Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter:
	.string "Tengo noticias de CIUDAD CELESTE.\p"
	.string "Parece que un tipo sospechoso\n"
	.string "ha estado merodeando por allí.$"
Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation:
	.string "¿Puedo pedirte ayuda?$"
Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity:
	.string "Tendremos que reforzar las\n"
	.string "medidas de seguridad.$"
Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart:
	.string "Alguien robó una pieza esencial\n"
	.string "del generador.\p"
	.string "¡Sin ella, el nuevo generador\n"
	.string "no sirve para nada!$"

Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning:
	.string "El generador vuelve a funcionar.\n"
	.string "¡Produce electricidad de sobra!$"

Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning:
	.string "Esta CENTRAL ENERGÍA estuvo\n"
	.string "abandonada durante años.\p"
	.string "La reabrimos para suministrar\n"
	.string "energía al MAGNETOTRÉN.$"

Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain:
	.string "¡El generador vuelve a funcionar!$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious:
	.string "El DIRECTOR está en la sala del\n"
	.string "fondo, junto al generador.\p"
	.string "Desde que lo sabotearon está\n"
	.string "triste y furioso…$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful:
	.string "Desde que arreglaron el generador,\n"
	.string "el DIRECTOR está muy contento.$"

Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity:
	.string "El MAGNETOTRÉN consume muchísima\n"
	.string "electricidad.\p"
	.string "No puede moverse si el nuevo\n"
	.string "generador no funciona.$"

Route10_PowerPlantEntrance_EventScript_Lorenzo::
	lock
	faceplayer
	goto_if_set FLAG_POWERPLANT_NPC_TRADE_COMPLETED, Route10_PowerPlantEntrance_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MAGNETON, Route10_PowerPlantEntrance_Text_WantToTrade, Route10_PowerPlantEntrance_EventScript_DeclineTrade, Route10_PowerPlantEntrance_EventScript_NotRequestedMon, Route10_PowerPlantEntrance_Text_TakeCare
	setflag FLAG_POWERPLANT_NPC_TRADE_COMPLETED
	release
	end

Route10_PowerPlantEntrance_EventScript_DeclineTrade::
	msgbox Route10_PowerPlantEntrance_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route10_PowerPlantEntrance_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_TradeCompleted::
	msgbox Route10_PowerPlantEntrance_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_Text_WantToTrade:
	.string "Trabajo en la CENTRAL ENERGÍA.\n"
	.string "MAGNETON lleva años conmigo.\p"
	.string "Pero siempre he querido un\n"
	.string "{STR_VAR_1}.\p"
	.string "¿Lo cambiarías por mi\n"
	.string "{STR_VAR_2}?$"

Route10_PowerPlantEntrance_Text_TakeCare:
	.string "¡Gracias! ¡Cuida bien de\n"
	.string "MAGGIE!$"

Route10_PowerPlantEntrance_Text_DeclineTrade:
	.string "¿No? Qué pena.\n"
	.string "Mi MAGNETON es muy trabajador.$"

Route10_PowerPlantEntrance_Text_NotRequestedMon:
	.string "Mmm… Eso no es un {STR_VAR_1}.\n"
	.string "No era lo que tenía en mente.$"

Route10_PowerPlantEntrance_Text_TradeCompleted:
	.string "¿Cómo está MAGGIE?\n"
	.string "¡Le encantan los campos magnéticos!$"

Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning:
	.string "¡Bien! ¡Por fin podremos poner\n"
	.string "en marcha el MAGNETOTRÉN!$"

Route10_PowerPlantEntrance_EventScript_Sito::
	lock
	faceplayer
	goto_if_defeated TRAINER_SITO_POWER_PLANT_HNS, Route10_PowerPlantEntrance_EventScript_SitoReward
	msgbox Route10_PowerPlantEntrance_Text_SitoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SITO_POWER_PLANT_HNS, Route10_PowerPlantEntrance_Text_SitoDefeated

Route10_PowerPlantEntrance_EventScript_SitoReward::
	checkitemspace ITEM_MIMINUCLEO_TARAFANTASTICO, 1
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantEntrance_EventScript_SitoBagFull
	msgbox Route10_PowerPlantEntrance_Text_SitoAfter, MSGBOX_DEFAULT
	giveitem ITEM_MIMINUCLEO_TARAFANTASTICO
	setflag FLAG_SITO_POWER_PLANT_DEFEATED
	setflag FLAG_HIDE_POWER_PLANT_SITO
	removeobject VAR_LAST_TALKED
	release
	end

Route10_PowerPlantEntrance_EventScript_SitoBagFull::
	msgbox Route10_PowerPlantEntrance_Text_SitoBagFull, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_Text_SitoIntro:
	.string "¡Anda! ¡Si es el recadero de\n"
	.string "Silph!\p"
	.string "Este cacharro daba unos chispazos\n"
	.string "guapísimos, así que me lo llevé.\p"
	.string "Mis chicas y yo nos lo estamos\n"
	.string "pasando de miedo.\p"
	.string "¿Lo quieres? ¡Pues tendrás que\n"
	.string "quitárnoslo!$"

Route10_PowerPlantEntrance_Text_SitoDefeated:
	.string "¡Pero si mis perras tenían el\n"
	.string "combate controladísimo!$"

Route10_PowerPlantEntrance_Text_SitoAfter:
	.string "Vale, vale... Toma el cacharro.\p"
	.string "Yo no he estado aquí y tú no me\n"
	.string "has visto. ¡Hasta luego!$"

Route10_PowerPlantEntrance_Text_SitoBagFull:
	.string "¡No te cabe el cacharro!\n"
	.string "Haz sitio y vuelve.$"
