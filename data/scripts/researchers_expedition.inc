Common_EventScript_Researchers_Interact::
	lock
	faceplayer
	copyvar VAR_0x8007, VAR_RESEARCHERS_ACQUAINTANCE_HNS
	switch VAR_0x8004
	case 32, Common_EventScript_Researchers_RememberRoute32
	case 38, Common_EventScript_Researchers_RememberRoute38
	case 41, Common_EventScript_Researchers_RememberRoute41
	case 43, Common_EventScript_Researchers_RememberRoute43
	case 45, Common_EventScript_Researchers_RememberRoute45
	goto Common_EventScript_Researchers_CheckRoute

Common_EventScript_Researchers_RememberRoute32::
	goto_if_ge VAR_RESEARCHERS_ACQUAINTANCE_HNS, 1, Common_EventScript_Researchers_CheckRoute
	setvar VAR_RESEARCHERS_ACQUAINTANCE_HNS, 1
	goto Common_EventScript_Researchers_CheckRoute

Common_EventScript_Researchers_RememberRoute38::
	goto_if_ge VAR_RESEARCHERS_ACQUAINTANCE_HNS, 2, Common_EventScript_Researchers_CheckRoute
	setvar VAR_RESEARCHERS_ACQUAINTANCE_HNS, 2
	goto Common_EventScript_Researchers_CheckRoute

Common_EventScript_Researchers_RememberRoute41::
	goto_if_ge VAR_RESEARCHERS_ACQUAINTANCE_HNS, 3, Common_EventScript_Researchers_CheckRoute
	setvar VAR_RESEARCHERS_ACQUAINTANCE_HNS, 3
	goto Common_EventScript_Researchers_CheckRoute

Common_EventScript_Researchers_RememberRoute43::
	goto_if_ge VAR_RESEARCHERS_ACQUAINTANCE_HNS, 4, Common_EventScript_Researchers_CheckRoute
	setvar VAR_RESEARCHERS_ACQUAINTANCE_HNS, 4
	goto Common_EventScript_Researchers_CheckRoute

Common_EventScript_Researchers_RememberRoute45::
	goto_if_ge VAR_RESEARCHERS_ACQUAINTANCE_HNS, 5, Common_EventScript_Researchers_CheckRoute
	setvar VAR_RESEARCHERS_ACQUAINTANCE_HNS, 5

Common_EventScript_Researchers_CheckRoute::
	special CheckRouteTrainersDefeated
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_Researchers_Complete
	buffernumberstring STR_VAR_1, VAR_0x8006
	switch VAR_0x8004
	case 32, Common_EventScript_Researchers_PendingRoute32
	case 38, Common_EventScript_Researchers_PendingRoute38
	case 41, Common_EventScript_Researchers_PendingRoute41
	case 43, Common_EventScript_Researchers_PendingRoute43
	case 45, Common_EventScript_Researchers_PendingRoute45
	release
	end

Common_EventScript_Researchers_PendingRoute32::
	setspeaker SP_NAME_JOSE
	goto_if_eq VAR_0x8007, 0, Common_EventScript_Researchers_FirstRoute32
	msgbox Common_Text_Researchers_Jose_Route32_Return, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route32_Return, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd
Common_EventScript_Researchers_FirstRoute32::
	msgbox Common_Text_Researchers_Jose_Route32_First, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route32_First, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd

Common_EventScript_Researchers_PendingRoute38::
	setspeaker SP_NAME_JOSE
	goto_if_eq VAR_0x8007, 0, Common_EventScript_Researchers_FirstRoute38
	msgbox Common_Text_Researchers_Jose_Route38_Return, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route38_Return, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd
Common_EventScript_Researchers_FirstRoute38::
	msgbox Common_Text_Researchers_Jose_Route38_First, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route38_First, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd

Common_EventScript_Researchers_PendingRoute41::
	setspeaker SP_NAME_JOSE
	goto_if_eq VAR_0x8007, 0, Common_EventScript_Researchers_FirstRoute41
	msgbox Common_Text_Researchers_Jose_Route41_Return, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route41_Return, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd
Common_EventScript_Researchers_FirstRoute41::
	msgbox Common_Text_Researchers_Jose_Route41_First, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route41_First, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd

Common_EventScript_Researchers_PendingRoute43::
	setspeaker SP_NAME_JOSE
	goto_if_eq VAR_0x8007, 0, Common_EventScript_Researchers_FirstRoute43
	msgbox Common_Text_Researchers_Jose_Route43_Return, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route43_Return, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd
Common_EventScript_Researchers_FirstRoute43::
	msgbox Common_Text_Researchers_Jose_Route43_First, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route43_First, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd

Common_EventScript_Researchers_PendingRoute45::
	setspeaker SP_NAME_JOSE
	goto_if_eq VAR_0x8007, 0, Common_EventScript_Researchers_FirstRoute45
	msgbox Common_Text_Researchers_Jose_Route45_Return, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route45_Return, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_PendingEnd
Common_EventScript_Researchers_FirstRoute45::
	msgbox Common_Text_Researchers_Jose_Route45_First, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route45_First, MSGBOX_DEFAULT

Common_EventScript_Researchers_PendingEnd::
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
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE32, Common_EventScript_Researchers_DoneRoute32
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route32_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route32_Reward, MSGBOX_DEFAULT
	giveitem ITEM_FESTIVAL_TICKET, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE32
	msgbox Common_Text_Researchers_Pilar_PostRoute32, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route38::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE38, Common_EventScript_Researchers_DoneRoute38
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route38_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route38_Reward, MSGBOX_DEFAULT
	call Common_EventScript_AwardRandomMint
	setflag FLAG_REWARD_RESEARCHERS_ROUTE38
	msgbox Common_Text_Researchers_Pilar_PostRoute38, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route41::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE41, Common_EventScript_Researchers_DoneRoute41
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
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE43, Common_EventScript_Researchers_DoneRoute43
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route43_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_Route43_Reward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE43
	msgbox Common_Text_Researchers_Pilar_PostRoute43, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_EventScript_Researchers_Route45::
	goto_if_set FLAG_REWARD_RESEARCHERS_ROUTE45, Common_EventScript_Researchers_DoneRoute45
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_Route45_Clear, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_PatchReward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH, 1
	setflag FLAG_REWARD_RESEARCHERS_ROUTE45
	msgbox Common_Text_Researchers_Pilar_PostRoute45, MSGBOX_DEFAULT
	closemessage
	release
	end


Common_EventScript_Researchers_DoneRoute32::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_DoneRoute32, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_DoneRoute32, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_DoneEnd

Common_EventScript_Researchers_DoneRoute38::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_DoneRoute38, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_DoneRoute38, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_DoneEnd

Common_EventScript_Researchers_DoneRoute41::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_DoneRoute41, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_DoneRoute41, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_DoneEnd

Common_EventScript_Researchers_DoneRoute43::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_DoneRoute43, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_DoneRoute43, MSGBOX_DEFAULT
	goto Common_EventScript_Researchers_DoneEnd

Common_EventScript_Researchers_DoneRoute45::
	setspeaker SP_NAME_JOSE
	msgbox Common_Text_Researchers_Jose_DoneRoute45, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_PILAR
	msgbox Common_Text_Researchers_Pilar_DoneRoute45, MSGBOX_DEFAULT

Common_EventScript_Researchers_DoneEnd::
	closemessage
	release
	end

Common_Text_Researchers_Jose_Route32_First:
	.string "¡Saludos! Somos JOSE y PILAR,\n"
	.string "investigadores itinerantes.\p"
	.string "Medimos cómo influye el terreno\n"
	.string "en los combates de la RUTA 32.\p"
	.string "Aún faltan {STR_VAR_1} muestras.$"

Common_Text_Researchers_Pilar_Route32_First:
	.string "Por muestras quiere decir\n"
	.string "entrenadores. JOSE dramatiza.\p"
	.string "Véncelos: necesitamos datos.$"

Common_Text_Researchers_Jose_Route32_Return:
	.string "¡Nuestro sujeto de campo!\n"
	.string "En la RUTA 32 todavía quedan\n"
	.string "{STR_VAR_1} entrenadores.\p"
	.string "La muestra exige rigor.$"

Common_Text_Researchers_Pilar_Route32_Return:
	.string "Traducción: no vale esquivarlos.\n"
	.string "Ya conoces el procedimiento.$"

Common_Text_Researchers_Jose_Route38_First:
	.string "Somos JOSE y PILAR. Estudiamos\n"
	.string "la conducta de los entrenadores.\p"
	.string "El viento de la RUTA 38 altera\n"
	.string "su selección de movimientos.\p"
	.string "Nos faltan {STR_VAR_1} combates.$"

Common_Text_Researchers_Pilar_Route38_First:
	.string "La hipótesis es suya. Yo creo\n"
	.string "que solo presumen ante las vacas.\p"
	.string "Derrótalos y saldremos de dudas.$"

Common_Text_Researchers_Jose_Route38_Return:
	.string "¡Otra vez tú! Tu consistencia\n"
	.string "ya resulta estadísticamente rara.\p"
	.string "Nos faltan {STR_VAR_1} sujetos.$"

Common_Text_Researchers_Pilar_Route38_Return:
	.string "Te reconoce, que ya es bastante.\n"
	.string "JOSE olvida hasta dónde acampa.$"

Common_Text_Researchers_Jose_Route41_First:
	.string "Somos JOSE y PILAR. Analizamos\n"
	.string "batallas en entornos acuáticos.\p"
	.string "Las corrientes de la RUTA 41\n"
	.string "elevan la fatiga un 23 por ciento.\p"
	.string "Faltan {STR_VAR_1} casos.$"

Common_Text_Researchers_Pilar_Route41_First:
	.string "Ese porcentaje se lo ha inventado.\n"
	.string "Pero el agua sí pasa factura.\p"
	.string "Ve preparado contra nadadores.$"

Common_Text_Researchers_Jose_Route41_Return:
	.string "¡Nuestro colaborador recurrente!\n"
	.string "Ya formas parte del estudio.\p"
	.string "Quedan {STR_VAR_1} combates.$"

Common_Text_Researchers_Pilar_Route41_Return:
	.string "Y procura no tragar agua.\n"
	.string "Eso falsearía nuestros datos.$"

Common_Text_Researchers_Jose_Route43_First:
	.string "Somos JOSE y PILAR. Medimos el\n"
	.string "efecto del LAGO DE LA FURIA.\p"
	.string "Su ecosistema está alterando\n"
	.string "la agresividad de toda la zona.\p"
	.string "Faltan {STR_VAR_1} entrenadores.$"

Common_Text_Researchers_Pilar_Route43_First:
	.string "No todo es culpa del GYARADOS.\n"
	.string "La presencia humana también pesa.\p"
	.string "Derrota a todos y compararemos.$"

Common_Text_Researchers_Jose_Route43_Return:
	.string "¡Nuestro sujeto estrella!\n"
	.string "Tu historial ya llena dos tablas.\p"
	.string "Aquí nos faltan {STR_VAR_1} casos.$"

Common_Text_Researchers_Pilar_Route43_Return:
	.string "Tres tablas. JOSE no cuenta la\n"
	.string "que perdió bajo la lluvia.$"

Common_Text_Researchers_Jose_Route45_First:
	.string "Somos JOSE y PILAR. Estudiamos\n"
	.string "combates a gran altitud.\p"
	.string "La menor presión favorece las\n"
	.string "decisiones impulsivas.\p"
	.string "Quedan {STR_VAR_1} sujetos.$"

Common_Text_Researchers_Pilar_Route45_First:
	.string "O quizá la gente se despeña por\n"
	.string "mirar la libreta mientras camina.\p"
	.string "Tú mira bien por dónde bajas.$"

Common_Text_Researchers_Jose_Route45_Return:
	.string "¡Colega de campo! Esta es nuestra\n"
	.string "investigación más ambiciosa.\p"
	.string "Solo quedan {STR_VAR_1} combates.$"

Common_Text_Researchers_Pilar_Route45_Return:
	.string "Si completas esta ruta, admitiré\n"
	.string "que ya eres parte del equipo.$"

Common_Text_Researchers_Jose_Route32_Clear:
	.string "¡Muestra completa! La RUTA 32\n"
	.string "confirma mi teoría del terreno.$"

Common_Text_Researchers_Jose_Route38_Clear:
	.string "¡Resultado concluyente! En la\n"
	.string "RUTA 38 nadie resistió tu ritmo.$"

Common_Text_Researchers_Jose_Route41_Clear:
	.string "¡Hazaña acuática confirmada!\n"
	.string "Has limpiado toda la RUTA 41.$"

Common_Text_Researchers_Jose_Route43_Clear:
	.string "¡Extraordinario! Ni la tensión\n"
	.string "del lago ha alterado tu patrón.$"

Common_Text_Researchers_Jose_Route45_Clear:
	.string "¡Descenso perfecto! Has ganado\n"
	.string "cada duelo de la RUTA 45.$"

Common_Text_Researchers_Pilar_Route32_Reward:
	.string "Como primera muestra fiable,\n"
	.string "mereces una entrada al festival.$"

Common_Text_Researchers_Pilar_Route38_Reward:
	.string "Los datos sobre el viento sirven.\n"
	.string "Te daremos una MENTA aleatoria.$"

Common_Text_Researchers_Pilar_Route43_Reward:
	.string "El lago exige adaptarse deprisa.\n"
	.string "Esta CÁPSULA te ayudará.$"

Common_Text_Researchers_Pilar_BigReward:
	.string "Para una ruta tan larga, te\n"
	.string "hemos reservado un destilado.$"

Common_Text_Researchers_Pilar_PostTufillo:
	.string "El TUFILLO JUNIOR garantiza\n"
	.string "que el siguiente POKéMON\l"
	.string "salvaje sea variocolor.$"

Common_Text_Researchers_Pilar_PatchReward:
	.string "¡Te has ganado el premio gordo!\n"
	.string "Un PARCHE HABILIDAD para tu\l"
	.string "labor de combate.$"

Common_Text_Researchers_Pilar_PostRoute32:
	.string "Guárdala. Nuestra siguiente base\n"
	.string "estará mucho más al oeste.$"

Common_Text_Researchers_Pilar_PostRoute38:
	.string "No preguntes qué naturaleza toca.\n"
	.string "El azar también es una variable.$"

Common_Text_Researchers_Pilar_PostRoute43:
	.string "Una habilidad distinta puede\n"
	.string "cambiar por completo un combate.$"

Common_Text_Researchers_Pilar_PostRoute45:
	.string "Queda registrado: ya eres miembro\n"
	.string "honorífico de la expedición.$"

Common_Text_Researchers_Jose_DoneRoute32:
	.string "La RUTA 32 ya está catalogada.\n"
	.string "El suelo arcilloso era la clave.$"

Common_Text_Researchers_Pilar_DoneRoute32:
	.string "Era barro, JOSE. Pero los datos\n"
	.string "de tus combates sí son buenos.$"

Common_Text_Researchers_Jose_DoneRoute38:
	.string "La RUTA 38 confirma que el viento\n"
	.string "favorece estrategias ofensivas.$"

Common_Text_Researchers_Pilar_DoneRoute38:
	.string "O confirma que pegaste primero.\n"
	.string "Aún estamos revisando eso.$"

Common_Text_Researchers_Jose_DoneRoute41:
	.string "La muestra marina está cerrada.\n"
	.string "Tu resistencia fue excepcional.$"

Common_Text_Researchers_Pilar_DoneRoute41:
	.string "También impermeabilizamos las\n"
	.string "libretas. Progreso científico.$"

Common_Text_Researchers_Jose_DoneRoute43:
	.string "Los datos del lago son fascinantes.\n"
	.string "Hay una anomalía evidente.$"

Common_Text_Researchers_Pilar_DoneRoute43:
	.string "Y no, la anomalía no eres tú.\n"
	.string "Aunque aparezcas en cada informe.$"

Common_Text_Researchers_Jose_DoneRoute45:
	.string "Cinco expediciones contigo.\n"
	.string "Ya eres una constante científica.$"

Common_Text_Researchers_Pilar_DoneRoute45:
	.string "Yo diría colega, no constante.\n"
	.string "Nos alegra volver a verte.$"

Common_EventScript_PokegearLevelCapUpdateNotice::
	lockall
	setflag FLAG_POKEGEAR_LEVEL_CAP_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearLevelCapUpdateNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearLevelCapUpdateNotice:
	.string "¡ATENCIÓN ENTRENADOR!\n"
	.string "Aviso del AYUDANTE DEL LOCKE:\p"
	.string "Se ha actualizado el límite de\n"
	.string "nivel y los ataques a la versión\l"
	.string "oficial de España.\p"
	.string "Recuerda que tus Pokémon no\n"
	.string "superarán el nivel del próximo líder\l"
	.string "en combate ni con caramelos.\p"
	.string "Para consultar el límite exacto,\n"
	.string "visítame en el CENTRO POKéMON\l"
	.string "de CIUDAD TRIGAL. ¡Ánimo!$"

Common_EventScript_PokegearEvoUpdateNotice::
	lockall
	setflag FLAG_POKEGEAR_EVO_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearEvoUpdateNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearEvoUpdateNotice:
	.string "¡ATENCIÓN ENTRENADOR!\n"
	.string "Aviso del AYUDANTE DEL LOCKE:\p"
	.string "¡Actualización de evoluciones!\n"
	.string "Todos los Pokémon con métodos\l"
	.string "extraños o complicados (movimientos,\l"
	.string "pasos o formas de otras regiones)\l"
	.string "ahora cuentan con un método directo\l"
	.string "por NIVEL o por PIEDRA.\p"
	.string "Especies como Annihilape, Wyrdeer,\n"
	.string "Overqwil, Basculegion, Sirfetch'd\l"
	.string "o Dudunsparce ya pueden evolucionar\l"
	.string "subiendo de nivel con normalidad.\p"
	.string "¡Mucha suerte en tu aventura!$"

Common_EventScript_PokegearMegaExchangeNotice_Call::
	setflag FLAG_POKEGEAR_MEGA_EXCHANGE_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearMegaExchangeNotice
	waitmessage
	delay 30
	return

Common_Text_PokegearMegaExchangeNotice:
	.string "¡Aviso del AYUDANTE DEL LOCKE!\p"
	.string "Ya tienes tu primera MEGAPIEDRA.\n"
	.string "Si encuentras alguna repetida,\l"
	.string "te la cambio gratis por una que\l"
	.string "todavía no tengas.\p"
	.string "Me encontrarás en el CENTRO\n"
	.string "POKéMON de CIUDAD TRIGAL.$"

Common_EventScript_PokegearSaturdayResetNotice::
	lockall
	setflag FLAG_POKEGEAR_SATURDAY_RESET_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearSaturdayResetNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearSaturdayResetNotice:
	.string "¡Aviso del POKéGEAR!\n"
	.string "RENOVACIÓN DE LOS SÁBADOS:\p"
	.string "Hoy se han reabierto las capturas\n"
	.string "semanales de la ZONA SAFARI de\l"
	.string "JOHTO, la ZONA SAFARI de FUCSIA\l"
	.string "y el CONCURSO DE CAZA DE BICHOS\l"
	.string "del PARQUE NACIONAL.\p"
	.string "¡Aprovecha el sábado para capturar\n"
	.string "nuevos compañeros de equipo!$"

Common_EventScript_PokegearAdvancedMetamorphosisNotice::
	lockall
	setflag FLAG_POKEGEAR_ADVANCED_METAMORPHOSIS_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearAdvancedMetamorphosisNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearAdvancedMetamorphosisNotice:
	.string "¡Aviso del DOCTORE FERNAN!\p"
	.string "¡Has reunido las 16 MEDALLAS!\n"
	.string "Gracias a tu dominio como CAMPEÓN,\l"
	.string "he perfeccionado mi máquina en\l"
	.string "el CENTRO POKéMON de la ZONA\l"
	.string "SAFARI.\p"
	.string "¡Ahora puedo adaptar formas\n"
	.string "complejas como OGERPON y URSHIFU!\p"
	.string "¡Pásate por el CENTRO POKéMON de\n"
	.string "la ZONA SAFARI cuando quieras!$"

