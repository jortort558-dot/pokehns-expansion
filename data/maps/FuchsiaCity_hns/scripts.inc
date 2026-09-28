FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "DIRECTOR BAOBA: ¡{PLAYER}!\p"
	.string "Soy el DIRECTOR BAOBA.\p"
	.string "¡Ha ocurrido algo terrible!\n"
	.string "¡Compraron mi antigua ZONA SAFARI\l"
	.string "de FUCSIA y acaban de reabrirla!\p"
	.string "¡Y al parecer tienen nuevos POKéMON\n"
	.string "exóticos!\p"
	.string "¡Eso perjudicará mi negocio!\p"
	.string "{PLAYER}, debes entrar en la nueva\n"
	.string "ZONA SAFARI y atrapar un POKéMON\l"
	.string "y enseñármelo. Debo averiguar qué\l"
	.string "tienen de “exóticos”.\p"
	.string "¡Por favor, {PLAYER}, mi negocio\n"
	.string "depende de ti!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Uno del ALTO MANDO fue LÍDER del\n"
	.string "GIMNASIO de FUCSIA.$"

FuchsiaCity_Text_PokefanM:
	.string "La hija de KOGA lo sustituyó como\n"
	.string "LÍDER cuando él entró en el\l"
	.string "ALTO MANDO.$"

FuchsiaCity_Text_Teacher:
	.string "La ZONA SAFARI tiene una nueva\n"
	.string "dirección.\p"
	.string "¡Y montones de POKéMON nuevos!$"

FuchsiaCity_Text_Sign:
	.string "CIUDAD FUCSIA\p"
	.string "¡Contempla el rosa pasión!$"

FuchsiaCity_Text_GymSign:
	.string "GIMNASIO POKéMON DE FUCSIA\n"
	.string "LÍDER: JANINE\p"
	.string "La maestra ninja venenosa$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Hay un aviso…\p"
	.string "La OFICINA de la ZONA SAFARI está\n"
	.string "cerrada hasta nuevo aviso.$"

FuchsiaCity_Text_SafariZone:
	.string "ZONA SAFARI\n"
	.string "PROPIEDAD DE\l"
	.string "DEVON S. A.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "El GUARDA está de viaje.\p"
	.string "Por eso, la ZONA SAFARI está\n"
	.string "cerrada.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No tires basura.\p"
	.string "Llévate tus residuos, por favor.$"
