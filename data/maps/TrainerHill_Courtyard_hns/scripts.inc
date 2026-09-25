TrainerHill_Courtyard_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "¡Hala, la COLINA DESAFÍO es enorme!\p"
	.string "¡Dentro debe de haber muchas clases\n"
	.string "de POKéMON!$"

BattleTowerOutsideBeautyText:
	.string "En las CARPAS DE BATALLA solo\n"
	.string "puedes usar tres POKéMON.\p"
	.string "Es muy difícil decidir qué\n"
	.string "tres llevar al combate…$"

BattleTowerOutsideSailorText:
	.string "Je, je, me he escapado del trabajo.\p"
	.string "¡No puedo irme hasta que gane!\p"
	.string "¡Tengo que ganarlo todo!$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} ENTRADA A COLINA DESAFÍO\p"
	.string "«¡Alcanzad la cima, Entrenadores\n"
	.string "apasionados!»\p"
	.string "{RIGHT_ARROW} CARPAS DE BATALLA$"

BattleTower_Battle_Tent_Text_Factory:
	.string "CARPA DE BATALLA: FÁBRICA\n"
	.string "«¡Encuentra al POKéMON definitivo!»$"

BattleTower_Battle_Tent_Text_Palace:
	.string "CARPA DE BATALLA: PALACIO\n"
	.string "«¡Deleita tu vista con combates!»$"

BattleTower_Battle_Tent_Text_Arena:
	.string "CARPA DE BATALLA: ESTADIO\n"
	.string "«¡Que vengan los mejores equipos!»$"

BattleTowerOutsideText_Closed:
	.string "La COLINA DESAFÍO está cerrada\n"
	.string "por reformas.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_ElementalMoveTutor
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PowerClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "¡Hola! Si buscas el INTERCAMBIO\n"
	.string "PRODIGIOSO, ahora está disponible\l"
	.string "en todos los CENTROS POKéMON.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hola. Este es el RINCÓN DEL\n"
	.string "SERVICIO DE CANJE.\p"
	.string "Cambiamos tus Puntos de Batalla\n"
	.string "por fantásticos premios.\p"
	.string "Elige un premio de la lista.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "¡Oh, son preciosos!\n"
	.string "¡Ojalá los tuviera!\l"
	.string "¡Cojines adorables!\l"
	.string "¡MUÑECOS de peluche grandes!\l"
	.string "¡MUÑECOS de peluche pequeños!\l"
	.string "¡Ojalá pudiera tenerlos todos!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "¡Déjaselo a mamá!\p"
	.string "Si quieres algo, haré lo que sea\n"
	.string "para conseguírtelo, cariño.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si consigo los objetos de aquí,\n"
	.string "mis POKéMON se harán más fuertes.\p"
	.string "¡Claro que sí!\n"
	.string "¡No me cabe duda!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "¿Eh?\n"
	.string "¿Qué miras?\p"
	.string "No me gusta que observes así mi\n"
	.string "muñeco de peluche.\p"
	.string "¡Si quieres uno, consíguelo tú!\n"
	.string "¿Verdad, SMOOCHUM?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "¿Lo sabías?\p"
	.string "Si alargas tu racha en cualquier\n"
	.string "instalación de BATALLA, empiezan a\l"
	.string "darte más Puntos de Batalla.$"
