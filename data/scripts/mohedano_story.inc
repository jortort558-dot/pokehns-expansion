Common_EventScript_PokegearSilphEmergencyNotice::
	lockall
	setflag FLAG_POKEGEAR_SILPH_EMERGENCY_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearSilphEmergencyNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearSilphEmergencyNotice:
	.string "AVISO URGENTE DE SILPH S.A.\p"
	.string "Buscamos a un entrenador avalado\n"
	.string "por la LIGA POKéMON.\p"
	.string "Un intruso ha robado un prototipo\n"
	.string "de nuestro laboratorio de AZAFRÁN.\p"
	.string "Acude a la planta baja de SILPH.\n"
	.string "El equipo científico te pondrá\l"
	.string "al corriente de la situación.$"

Common_EventScript_PokegearFuchsiaPoisoningNotice::
	lockall
	setflag FLAG_POKEGEAR_FUCHSIA_POISONING_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearFuchsiaPoisoningNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearFuchsiaPoisoningNotice:
	.string "TOXICÓLOGA DE LA ZONA SAFARI:\p"
	.string "SILPH me facilitó tu contacto.\n"
	.string "Varios Pokémon de CIUDAD FUCSIA\l"
	.string "han enfermado de forma repentina.\p"
	.string "El agua y los recintos presentan\n"
	.string "signos de contaminación.\p"
	.string "Te necesito en la ZONA SAFARI.\n"
	.string "Ven cuanto antes.$"

Common_EventScript_PokegearPewterMuseumNotice::
	lockall
	setflag FLAG_POKEGEAR_PEWTER_MUSEUM_NOTICE
	playse SE_POKENAV_CALL
	waitse
	pokenavcall Common_Text_PokegearPewterMuseumNotice
	waitmessage
	delay 30
	releaseall
	end

Common_Text_PokegearPewterMuseumNotice:
	.string "MUSEO DE CIUDAD PLATEADA:\p"
	.string "La toxicóloga de FUCSIA nos ha\n"
	.string "facilitado tu contacto.\p"
	.string "Alguien ha alterado el registro\n"
	.string "de nuestras muestras antiguas.\p"
	.string "Una visitante ronda la exposición\n"
	.string "de la segunda planta.\p"
	.string "Necesitamos una mirada discreta.\n"
	.string "Ven al museo cuanto antes.$"
