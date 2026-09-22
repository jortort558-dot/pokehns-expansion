Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "¡Ey! ¡Estoy buscando un MANKEY!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "¡Derrotado por alguien que pasaba!$"

Route34_Text_YoungsterSamuel_After:
	.string "Voy a entrenar mucho más duro.\p"
	.string "¡Algún día seré un LÍDER DE\n"
	.string "GIMNASIO!$"

Route34_Text_YoungsterIan_Seen:
	.string "¡Soy el número uno de mi clase en\n"
	.string "combates POKéMON!$"

Route34_Text_YoungsterIan_Beaten:
	.string "¡No puede ser! Hay gente mejor…$"

Route34_Text_YoungsterIan_After:
	.string "Me esfuerzo a tope para seguir\n"
	.string "siendo el crack de mi clase.$"

Route34_Text_CamperTodd_Seen:
	.string "Confío plenamente en cómo crío a\nmis\l"
	.string "POKéMON.\p"
	.string "¿Quieres comprobarlo?$"

Route34_Text_CamperTodd_Beaten:
	.string "¿Habré fallado en el entrenamiento?$"

Route34_Text_CamperTodd_After:
	.string "Quizá debería dejarlo en la\n"
	.string "GUARDERÍA o usar más objetos…$"

Route34_Text_ToddRegister:
	.string "¡Dame un toque si quieres combatir\nde\l"
	.string "nuevo cuando mejore a mi equipo!$"

Route34_Text_ToddRematchIntro:
	.string "¡Mis POKéMON han mejorado una\n"
	.string "barbaridad! ¿Listo para la\lrevancha?$"

Route34_Text_ToddRematchDefeat:
	.string "¿Otra vez he perdido?$"

Route34_Text_ToddPostRematch:
	.string "Tendré que seguir investigando cómo\n"
	.string "potenciar sus puntos fuertes…$"

Route34_Text_GinaRegister:
	.string "¡Me encantaría volver a retarte en\n"
	.string "cuanto mis POKéMON sean más\lfuertes!$"

Route34_Text_PicnickerGina_Seen:
	.string "¿Eres entrenador?\p"
	.string "¡Hagamos un combate de práctica!$"

Route34_Text_PicnickerGina_Beaten:
	.string "¡Vaya por Dios! No hay manera…$"

Route34_Text_PicnickerGina_After:
	.string "Eres demasiado fuerte para ser solo\n"
	.string "un compañero de prácticas.$"

Route34_Text_OfficerKeith_Seen:
	.string "¡Alto ahí! ¿Quién anda ahí?\n"
	.string "¿Qué tramas a estas horas?$"

Route34_Text_OfficerKeith_Win:
	.string "Caray, no te andas con chiquitas.$"

Route34_Text_OfficerKeith_After:
	.string "Bien, todo en orden por aquí.\p"
	.string "Pórtate bien y no te metas en líos.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Estoy patrullando en busca de gente\n"
	.string "sospechosa.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Acabo de recoger a mi POKéMON de la\n"
	.string "GUARDERÍA.\p"
	.string "¡Veamos cuánto ha mejorado!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "¿Por qué siempre acabo perdiendo?$"

Route34_Text_PokefanBrandon_After:
	.string "Mi POKéMON aprendió movimientos\n"
	.string "nuevos y me ha descolocado por\l"
	.string "completo en el combate.$"

Route34_Text_Sign_IlexForest:
	.string "ENCINAR\n"
	.string "CRUZANDO EL PUESTO FRONTERIZO$"

Route34_Text_Sign_Route34:
	.string "RUTA 34\n"
	.string "CIUDAD TRIGAL - PUEBLO AZALEA\p"
	.string "EL ENCINAR QUEDA DE CAMINO$"

Route34_Text_TrainerTips:
	.string "PISTAS PARA ENTRENADORES\p"
	.string "Los árboles de BAYAS dan fruto\n"
	.string "varias veces a lo largo del día.\p"
	.string "Fíjate bien en qué árboles crece\n"
	.string "cada tipo de BAYA.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "IRENE: ¡¿Y tú quién eres?!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE: ¡Ostras! ¡Qué fiera!$"

Route34_Text_CooltrainerIrene_After1:
	.string "IRENE: ¡Mi hermana KATE te va a dar\n"
	.string "para el pelo!$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE: ¿A que esta playita mola?\p"
	.string "¡Es nuestro rincón secreto!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "JENN: ¡¿Pero qué…?!\n"
	.string "¿Qué haces merodeando por aquí?$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN: ¡Lo siento, IRENE! ¡Hermana!$"

Route34_Text_CooltrainerJenn_After1:
	.string "JENN: ¡No te crezcas! ¡Mi hermana\n"
	.string "KATE sí que reparte leña!$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN: Tomar el solecito sienta de\n"
	.string "maravilla al cuerpo.$"

Route34_Text_CooltrainerKate_Seen:
	.string "KATE: ¡Vas a pagar por haber\nvencido\l"
	.string "a mis hermanas!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "KATE: ¡No me lo creo! ¿He perdido?$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "KATE: Eres increíble.\n"
	.string "Hemos perdido limpiamente…\p"
	.string "¡Toma, te has ganado esto!$"

Route34_Text_CooltrainerKate_After:
	.string "KATE: Perdona por abalanzarnos\nsobre\l"
	.string "ti.\p"
	.string "No esperábamos que nadie encontrara\n"
	.string "esta cala. ¡Vaya susto nos diste!$"


Route34_Text_Sign_DayCare:
	.string "GUARDERÍA POKéMON\p"
	.string "¡CUIDAMOS DE TUS POKéMON CON AMOR!$"
