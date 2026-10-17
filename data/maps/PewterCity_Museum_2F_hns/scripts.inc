PewterCity_Museum_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Museum_2F_OnTransition
	.byte 0

PewterCity_Museum_2F_OnTransition::
	setweather WEATHER_NONE
	doweather
	call PewterCity_Museum_2F_UpdateYami
	call PewterCity_Museum_2F_UpdateJP
	end

PewterCity_Museum_2F_UpdateYami::
	goto_if_unset FLAG_FUCHSIA_BLACK_SLUDGE_RECEIVED, PewterCity_Museum_2F_HideYami
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_HideYami
	clearflag FLAG_HIDE_PEWTER_MUSEUM_YAMI
	return

PewterCity_Museum_2F_HideYami::
	setflag FLAG_HIDE_PEWTER_MUSEUM_YAMI
	return

PewterCity_Museum_2F_UpdateJP::
	goto_if_unset FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_HideJP
	goto_if_set FLAG_PEWTER_MUSEUM_JP_DEFEATED, PewterCity_Museum_2F_HideJP
	clearflag FLAG_HIDE_PEWTER_MUSEUM_JP
	return

PewterCity_Museum_2F_HideJP::
	setflag FLAG_HIDE_PEWTER_MUSEUM_JP
	return

PewterCity_Museum_2F_EventScript_Yami::
	lockall
	faceplayer
	goto_if_set FLAG_YAMI_SUPER_TRAINING_UNLOCKED, PewterCity_Museum_2F_EventScript_YamiKnown
	msgbox PewterCity_Museum_2F_Text_YamiUnknown, MSGBOX_DEFAULT
	goto PewterCity_Museum_2F_EventScript_Blackout

PewterCity_Museum_2F_EventScript_YamiKnown::
	setspeaker SP_NAME_YAMI
	msgbox PewterCity_Museum_2F_Text_YamiKnown, MSGBOX_DEFAULT

PewterCity_Museum_2F_EventScript_Blackout::
	closemessage
	setspeaker SP_NAME_NONE
	applymovement LOCALID_MUSEUM_2F_YAMI, PewterCity_Museum_2F_Movement_YamiFacesExhibit
	waitmovement LOCALID_MUSEUM_2F_YAMI
	playse SE_SWITCH
	waitse
	delay 20
	fadescreenspeed FADE_TO_BLACK, 2
	setweather WEATHER_SHADE
	doweather
	setflag FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE
	setflag FLAG_HIDE_PEWTER_MUSEUM_YAMI
	removeobject LOCALID_MUSEUM_2F_YAMI
	playse SE_ICE_BREAK
	waitse
	delay 45
	fadescreenspeed FADE_FROM_BLACK, 2
	msgbox PewterCity_Museum_2F_Text_Blackout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_2F_NERD, PewterCity_Museum_2F_Movement_NerdChecksExhibit
	waitmovement LOCALID_MUSEUM_2F_NERD
	playse SE_SWITCH
	waitse
	fadescreenspeed FADE_TO_BLACK, 2
	setweather WEATHER_NONE
	doweather
	fadescreenspeed FADE_FROM_BLACK, 2
	msgbox PewterCity_Museum_2F_Text_LightsReturn, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_PEWTER_MUSEUM_JP
	addobject LOCALID_MUSEUM_2F_JP
	releaseall
	end

PewterCity_Museum_2F_EventScript_JP::
	trainerbattle_single TRAINER_JP_MUSEUM_HNS, PewterCity_Museum_2F_Text_JPIntro, PewterCity_Museum_2F_Text_JPDefeat, PewterCity_Museum_2F_EventScript_JPDefeated
	msgbox PewterCity_Museum_2F_Text_JPAfter, MSGBOX_AUTOCLOSE
	end

PewterCity_Museum_2F_EventScript_JPDefeated::
	special PlayerFaceTrainerAfterBattle
	setflag FLAG_PEWTER_MUSEUM_JP_DEFEATED
	msgbox PewterCity_Museum_2F_Text_JPEscape, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_PEWTER_MUSEUM_JP
	removeobject LOCALID_MUSEUM_2F_JP
	releaseall
	end

PewterCity_Museum_2F_Movement_YamiFacesExhibit:
	face_up
	step_end

PewterCity_Museum_2F_Movement_NerdChecksExhibit:
	face_left
	step_end

PewterCity_Museum_2F_EventScript_Nerd::
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_EventScript_NerdAfterRobbery
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_NerdAfterRobbery::
	msgbox PewterCity_Museum_2F_Text_NerdAfterRobbery, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_EventScript_DaughterAfterRobbery
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_DaughterAfterRobbery::
	msgbox PewterCity_Museum_2F_Text_DaughterAfterRobbery, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Dad::
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_EventScript_DadAfterRobbery
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_DadAfterRobbery::
	msgbox PewterCity_Museum_2F_Text_DadAfterRobbery, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Meteor::
	goto_if_set FLAG_PEWTER_MUSEUM_ROBBERY_COMPLETE, PewterCity_Museum_2F_EventScript_MeteorStolen
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_EventScript_MeteorStolen::
	msgbox PewterCity_Museum_2F_Text_MeteorStolen, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "Dicen que cayeron meteoritos en\n"
	.string "ISLA ORIGEN.\p"
	.string "Nos encantaría exponerlos aquí,\n"
	.string "pero…\p"
	.string "Dicen que emiten una energía\n"
	.string "extraña y no pueden transportarse…$"

PewterCity_Museum_2F_Text_YamiUnknown:
	.string "La seguridad siempre vigila las\n"
	.string "puertas. Es una costumbre cómoda.\p"
	.string "Nadie mira aquello que alimenta\n"
	.string "las luces.$"

PewterCity_Museum_2F_Text_YamiKnown:
	.string "Nos volvemos a encontrar.\n"
	.string "Qué pequeño resulta el mundo\l"
	.string "cuando sabes dónde colocarte.\p"
	.string "Hoy aprenderás otra disciplina:\n"
	.string "desaparecer antes del ruido.$"

PewterCity_Museum_2F_Text_Blackout:
	.string "La sala queda casi a oscuras.\p"
	.string "Se oye un cristal al quebrarse,\n"
	.string "dos pasos sobre una vitrina…\l"
	.string "y una ventana que se cierra.$"

PewterCity_Museum_2F_Text_LightsReturn:
	.string "Las luces vuelven.\p"
	.string "La visitante y la muestra lunar\n"
	.string "han desaparecido.$"

PewterCity_Museum_2F_Text_JPIntro:
	.string "JP: YAMI ya tiene la muestra.\p"
	.string "Mi trabajo es asegurar que nadie\n"
	.string "recuerde por dónde salió.$"

PewterCity_Museum_2F_Text_JPDefeat:
	.string "Demasiado ruido para un ninja…$"

PewterCity_Museum_2F_Text_JPEscape:
	.string "JP: DANI cubre la planta baja.\p"
	.string "Si puedes alcanzarlo, quizá aún\n"
	.string "veas cómo trabaja nuestro grupo.$"

PewterCity_Museum_2F_Text_JPAfter:
	.string "JP no aparta la vista de la\n"
	.string "escalera.$"

PewterCity_Museum_2F_Text_NerdAfterRobbery:
	.string "¡Se ha llevado la muestra lunar!\p"
	.string "En el pedestal solo ha dejado\n"
	.string "una credencial falsificada.$"

PewterCity_Museum_2F_Text_DaughterAfterRobbery:
	.string "Papá… Esa señora saltó por encima\n"
	.string "de la vitrina sin hacer ruido.$"

PewterCity_Museum_2F_Text_DadAfterRobbery:
	.string "Eso no lo consigue una ladrona\n"
	.string "corriente. Estaba muy entrenada.$"

PewterCity_Museum_2F_Text_MeteorStolen:
	.string "El pedestal está vacío.\p"
	.string "Queda una lámina negra marcada\n"
	.string "con una M plateada.$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "¡Quiero un PIKACHU!\n"
    .string "¡Es tan mono!\p"
    .string "¡Le pedí a papá que atrape uno!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Sí, pronto tendrás uno. ¡Prometido!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Transbordador espacial$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "Un meteorito caído en MT. MOON.\n"
    .string "Se cree que es una PIEDRA LUNAR.$"
