Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "He estado recopilando datos de\n"
	.string "POKéMON por la radio. ¡Estoy listo!$"

Route35_Text_CamperIvanBeaten:
	.string "¡Me rindo!$"

Route35_Text_CamperIvanAfter:
	.string "La música de la radio influye en el\n"
	.string "comportamiento de los salvajes.$"

Route35_Text_CamperElliotSeen:
	.string "¡Voy a demostrarle a mi novia lo\n"
	.string "fuerte que soy!$"

Route35_Text_CamperElliotBeaten:
	.string "Ojalá te hubieses dejado ganar…$"

Route35_Text_CamperElliotAfter:
	.string "Menudo ridículo he hecho delante de\n"
	.string "mi chica…$"

Route35_Text_PicnickerBrookeSeen:
	.string "Mi novio es un blandengue, no me\n"
	.string "puedo fiar de él en combate.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "¡Madre mía! ¡Qué fuerza tienes!$"

Route35_Text_PicnickerBrookeAfter:
	.string "Puedo confiar más en mis POKéMON\nque\l"
	.string "en mi novio.$"

Route35_Text_PicnickerKimSeen:
	.string "¿Vas al GIMNASIO? ¡Yo también!$"

Route35_Text_PicnickerKimBeaten:
	.string "Vaya… No ha habido suerte…$"

Route35_Text_PicnickerKimAfter:
	.string "Las MEDALLAS de GIMNASIO son una\n"
	.string "monada. ¡Las colecciono todas!$"

Route35_Text_BirdKeeperBryanSeen:
	.string "¿Qué clase de BALLS sueles usar?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "¡Uf! ¡No he sido lo bastante\nrápido!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Hay POKéMON que huyen al instante.\p"
	.string "Prueba a atraparlos con la RAPID\n"
	.string "BALL de CÉSAR.\p"
	.string "Cada vez que encuentro una BAYA\n"
	.string "PERASI, se la llevo a él.\p"
	.string "¡Y te fabrica una BALL especial!$"

Route35_Text_JugglerIrwinSeen:
	.string "¡Admira mi gracia y soltura con las\n"
	.string "BALLS!$"

Route35_Text_JugglerIrwinBeaten:
	.string "¡Uf! ¡Vaya sacudida me has dado!$"

Route35_Text_JugglerIrwinAfter:
	.string "Iba a deslumbrarte con mis POKéMON\n"
	.string "estrella.\p"
	.string "¡Pero tu destreza me ha dejado de\n"
	.string "piedra!$"

Route35_Text_BugCatcherArnieSeen:
	.string "Voy adonde haga falta con tal de\n"
	.string "encontrar POKéMON bicho.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "¿Eh? No esperaba perder esto…$"

Route35_Text_BugCatcherArnieAfter:
	.string "Gané el Concurso de Captura de\nBichos\l"
	.string "del PARQUE NACIONAL con mi VENONAT.$"

Route35_Text_IrwinRegister:
	.string "¡Avísame por el POKéGEAR si quieres\n"
	.string "volver a ver mis malabares!$"

Route35_Text_ArnieRegister:
	.string "¡Te llamaré si veo bichos raros por\n"
	.string "el PARQUE NACIONAL!$"

Route35_Text_ArnieRematchIntro:
	.string "¡Vamos con otro combate bichero!$"

Route35_Text_ArnieRematchDefeat:
	.string "¿Otra vez he caído?$"

Route35_Text_ArniePostRematch:
	.string "Tengo que entrenar mejor a mis\nbichos\l"
	.string "para la próxima.$"

Route35_Text_BugCatcherArnieYanma:
	.string "¡Hala…! ¡Mira cuántos YANMA!\p"
	.string "¡Es tan alucinante que no puedo ni\n"
	.string "moverme!$"

Route35_Text_FirebreatherWaltSeen:
	.string "Estoy ensayando mi número de\n"
	.string "escupefuegos.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "¡Ay! ¡Me he chamuscado la punta de\nla\l"
	.string "nariz!$"

Route35_Text_FirebreatherWaltAfter:
	.string "La Marcha POKéMON de la radio atrae\n"
	.string "a los salvajes como un imán.$"

Route35_Text_OfficerDirkSeen:
	.string "¡El peligro acecha en la noche!$"

Route35_Text_OfficerDirkBeaten:
	.string "¡Ostras!$"

Route35_Text_OfficerDirkAfter:
	.string "La noche tiene su encanto para\n"
	.string "entrenar, pero no te descuides.$"

Route35_Text_OfficerDirkTough:
	.string "Tus POKéMON imponen respeto. Puedes\n"
	.string "viajar tranquilamente.$"

Route35_Text_Sign:
	.string "RUTA 35$"

Route35_Text_Sign2:
	.string "ACCESO AL PARQUE NACIONAL$"
