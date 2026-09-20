CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "¡E-estoy en shock!\pUn tipo con mirada fiera y melena\nlarga\lentró aquí como una furia.\l¡Me amenazó tanto que tuve que\ldarle\la mi querido POKéMON!\pAún me queda uno, pero... ¿y si\nvuelve?\lSe te ve fuerte. ¿Podrías cuidar de\lmi\lPOKéMON una temporada?$"
CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "¡Muchísimas gracias!\n¡Por favor, cuídalo con mucho\lcariño!$"
CianwoodCity_Text_ManiacGotShuckle:
	.string "¡{PLAYER} recibió un POKéMON!$"
CianwoodCity_Text_ManiacPartyFull:
	.string "Tu equipo POKéMON está lleno.$"
CianwoodCity_Text_ManiacIfHeComesBack:
	.string "¡Ay, no! ¿Qué voy a hacer si\nvuelve?…$"
CianwoodCity_Text_ManiacHowsdoing:
	.string "¡Hola! ¿Cómo le va a mi POKéMON?$"
CianwoodCity_Text_ManiacAskReturn:
	.string "¡Hola! ¿Cómo está mi POKéMON?\pCreo que ya no corro peligro, así\nque\l¿me lo podrías devolver?$"
CianwoodCity_Text_ManiacThankYou:
	.string "¡Muchas gracias!$"
CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Oye, si no llevas a mi POKéMON\ncontigo.$"
CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Mi POKéMON ha terminado\nencariñándose\lcontigo.\pDe acuerdo, quédatelo tú.\n¡Pero prométeme que lo tratarás muy\lbien!$"
CianwoodCity_Text_ManiacRobbed:
	.string "Eh, algo no cuadra aquí.$"
CianwoodCity_Text_ManiacRobbed2:
	.string "No, no, no… ¡Eso es lo mismo que si\nme estuvieras robando!$"
CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Para un POKéMON, la auténtica\nfelicidad\les estar con alguien que lo trata\lbien.$"
CianwoodCity_Text_ManiacLastMon:
	.string "Si me quedo con mi POKéMON, ¿qué\nvas a\lusar tú para combatir?$"
CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} le devolvió a SHUCKIE.$"
