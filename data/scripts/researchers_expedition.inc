Common_EventScript_Researchers_Interact::
	lock
	faceplayer
	special CheckRouteTrainersDefeated
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_Researchers_Complete
	@ Undefeated trainers remain
	setspeaker SP_NAME_JOSE
	buffernumberstring STR_VAR_1, VAR_0x8006
	msgbox Common_Text_Researchers_Jose_Intro, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Advice, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Complete::
	switch VAR_0x8004
	case 32, Common_EventScript_Researchers_Route32
	case 38, Common_EventScript_Researchers_Route38
	case 41, Common_EventScript_Researchers_Route41
	case 43, Common_EventScript_Researchers_Route43
	case 45, Common_EventScript_Researchers_Route45
	release
	end

Common_EventScript_Researchers_Route32::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE32, Common_EventScript_Researchers_AlreadyRewarded
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route32_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Reward, MSGBOX_DEFAULT
	giveitem ITEM_FESTIVAL_TICKET, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE32
	msgbox Common_Text_Researchers_Pilar_PostReward, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route38::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE38, Common_EventScript_Researchers_AlreadyRewarded
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route38_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Reward, MSGBOX_DEFAULT
	call Common_EventScript_AwardRandomMint
	setflag FLAG_REWARD_RESEARCHERS_ROUTE38
	msgbox Common_Text_Researchers_Pilar_PostReward, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route41::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE41, Common_EventScript_Researchers_AlreadyRewarded
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route41_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_BigReward, MSGBOX_DEFAULT
	giveitem ITEM_TUFILLO_JUNIOR, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE41
	msgbox Common_Text_Researchers_Pilar_PostTufillo, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route43::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE43, Common_EventScript_Researchers_AlreadyRewarded
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route43_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Reward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE43
	msgbox Common_Text_Researchers_Pilar_PostReward, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route45::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE45, Common_EventScript_Researchers_AlreadyRewarded
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route45_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_PatchReward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE45
	msgbox Common_Text_Researchers_Pilar_PostReward, MSGBOX_DEFAULT
	closemessage
	release
	end


Common_EventScript_Researchers_AlreadyRewarded::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Done, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Done, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_Text_Researchers_Jose_Intro:
	.string "¡Saludos! Somos JOSE y PILAR,\n"
	.string "un equipo de investigación.\p"
	.string "Documentamos el nivel de los\n"
	.string "entrenadores de esta ruta.\p"
	.string "Según nuestras notas, aún\n"
	.string "te faltan {STR_VAR_1} por vencer.$"


Common_Text_Researchers_Pilar_Advice:
	.string "Exacto. Una muestra no vale\n"
	.string "si esquivas los combates.\p"
	.string "¡Vuelve cuando derrotes a todos\n"
	.string "y te daremos una gratificación!$"

Common_Text_Researchers_Jose_Route32_Clear:
	.string "¡Excelente trabajo! Has barrido\n"
	.string "a todos los de la RUTA 32.$"

Common_Text_Researchers_Jose_Route38_Clear:
	.string "¡Gran ritmo! Ni un entrenador\n"
	.string "de la RUTA 38 sigue en pie.$"

Common_Text_Researchers_Jose_Route41_Clear:
	.string "¡Vaya hazaña acuática! Has\n"
	.string "vencido a todos en la RUTA 41.$"

Common_Text_Researchers_Jose_Route43_Clear:
	.string "¡Extraordinario! Todos los\n"
	.string "entrenadores han caído aquí.$"

Common_Text_Researchers_Jose_Route45_Clear:
	.string "¡Imponente descenso! Has ganado\n"
	.string "cada duelo de la RUTA 45.$"

Common_Text_Researchers_Pilar_Reward:
	.string "Nuestra base de datos de campo\n"
	.string "está completa. ¡Toma esto!$"

Common_Text_Researchers_Pilar_BigReward:
	.string "Para una ruta tan larga, te\n"
	.string "hemos reservado un destilado.$"

Common_Text_Researchers_Pilar_PostTufillo:
	.string "El TUFILLO JUNIOR atrae\n"
	.string "Pokémon raros y variocolor\l"
	.string "con mucha más frecuencia.$"

Common_Text_Researchers_Pilar_PatchReward:
	.string "¡Te has ganado el premio gordo!\n"
	.string "Un PARCHE HABILIDAD para tu\l"
	.string "labor de combate.$"

Common_Text_Researchers_Pilar_PostReward:
	.string "¡Sigue así en otras rutas!\n"
	.string "La ciencia nunca descansa.$"

Common_Text_Researchers_Jose_Done:
	.string "Los datos están completos.\n"
	.string "¡Nos vemos en otra ruta!$"

Common_Text_Researchers_Pilar_Done:
	.string "¡Gracias por colaborar con\n"
	.string "nuestra labor científica!$"

