PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "Dicen que cayeron meteoritos en\n"
	.string "ISLA ORIGEN.\p"
	.string "Nos encantaría exponerlos aquí,\n"
	.string "pero…\p"
	.string "Dicen que emiten una energía\n"
	.string "extraña y no pueden transportarse…$"

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
