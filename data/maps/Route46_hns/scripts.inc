Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "¡Muy bien! ¡Te voy a enseñar el\n"
	.string "poder de los POKéMON de montaña!$"

Route46_Text_HikerBaileyBeaten:
	.string "¡Piedad! ¡Me has demostrado\n"
	.string "tu tremenda fuerza!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "Se acabó el combate. No me importa.\n"
	.string "Los MONTAÑEROS somos así de duros.$"

Route46_Text_CamperTedSeen:
	.string "¡Yo también estoy criando POKéMON!\p"
	.string "¿Quieres echar un combate conmigo?$"

Route46_Text_CamperTedBeaten:
	.string "¿C-cómo…?$"

Route46_Text_CamperTedAfterBattle:
	.string "Lo di todo, pero me faltaron\n"
	.string "fuerzas.\p"
	.string "Sin excusas: admito que he perdido.$"

Route46_Text_PicnickerErinSeen:
	.string "¡Yo también entreno POKéMON!\p"
	.string "¿Te apetece echar un combate?$"

Route46_Text_PicnickerErinBeaten:
	.string "¡Vaya, porras!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "He visitado muchos GIMNASIOS,\n"
	.string "pero el de CIUDAD TRIGAL es\l"
	.string "mi favorito.\p"
	.string "¡Está repleto de flores preciosas!$"

Route46_Text_ErinRegister:
	.string "He visitado muchos GIMNASIOS,\n"
	.string "pero el de CIUDAD TRIGAL es\l"
	.string "mi favorito.\p"
	.string "¡Está repleto de flores preciosas!$"

Route46_Text_ErinRematchIntro:
	.string "¡Sigo entrenando con mis POKéMON!\p"
	.string "¿Luchamos otra vez?$"

Route46_Text_ErinRematchDefeat:
	.string "¡Vaya, porras!$"

Route46_Text_ErinPostRematch:
	.string "He visitado muchos GIMNASIOS,\n"
	.string "pero el de CIUDAD TRIGAL es\l"
	.string "mi favorito.\p"
	.string "¡Está repleto de flores preciosas!$"

Route46_Text_PicnickerErin2Beaten:
	.string "¡Ooh… no paro de perder contigo!\p"
	.string "¡Tendré que esforzarme aún más!\n"
	.string "En fin, gracias por combatir\l"
	.string "conmigo tantas veces.\p"
	.string "¡Toma este regalo que te prometí!$"

Route46_Text_Sign:
	.string "RUTA 46\n"
	.string "CAMINO DE LA MONTAÑA MÁS ADELANTE$"
