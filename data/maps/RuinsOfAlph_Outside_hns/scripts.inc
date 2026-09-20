RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "¿Mmm? Eso es una POKéDEX, ¿verdad?\n"
	.string "¿Podría verla un segundo?\p"
	.string "Hay tantísimas especies de\n"
	.string "POKéMON…\p"
	.string "¿Eh? ¿Y esto?\p"
	.string "¿Qué clase de POKéMON es este?\p"
	.string "Se parece un montón a los extraños\n"
	.string "escritos en los muros de las\p"
	.string "RUINAS.\p"
	.string "Si esos jeroglíficos son POKéMON\n"
	.string "de verdad, ¡debe haber muchísimos!\p"
	.string "¡Ya sé! Déjame actualizar tu\n"
	.string "POKéDEX. ¡Sígueme!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "¿Qué quieres? Estoy estudiando,\n"
	.string "¡así que no me desconcentres!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Perdón… Me frustra no comprender\n"
	.string "el misterio de estas ruinas…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Las RUINAS datan de hace unos\n"
	.string "1.500 años.\p"
	.string "Nadie sabe a ciencia cierta quién\n"
	.string "las construyó.\p"
	.string "Tampoco sabemos si sus estatuas\n"
	.string "tienen un significado oculto.\p"
	.string "Es todo un auténtico enigma…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Mmm… Este lugar emite una energía\n"
	.string "muy peculiar.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "Me gusta meditar y pensar aquí.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "CÁMARA DEL PANEL DE PIEDRA\nMISTERIOSO$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINAS ALFA\n"
	.string "BIENVENIDOS VISITANTES$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "CENTRO DE INVESTIGACIÓN DE RUINAS\nALFA\p"
	.string "LA MÁXIMA AUTORIDAD EN EL ESTUDIO\n"
	.string "DE LAS RUINAS ALFA$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "Mientras explorábamos las RUINAS,\nde\l"
	.string "repente sentimos una extraña\npresencia…\p"
	.string "¡Nos pegamos un susto de muerte y\nsalimos\l"
	.string "corriendo! ¡Ten mucho cuidado!$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "¡Las RUINAS ocultan un gran enigma!\p"
	.string "… O eso creo…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Hay tantas formas de UNOWN que las\n"
	.string "usamos para crear mensajes\nsecretos.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "D… E… L… A… N… T… E… Mmm…\p"
	.string "¿Qué?\p"
	.string "¡Estoy descifrando este mensaje!$"
