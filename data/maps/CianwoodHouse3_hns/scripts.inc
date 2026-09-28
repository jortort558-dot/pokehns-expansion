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
	.string "¡E-estoy en shock!\pUn tipo de tu edad, mirada fiera\ny el pelo largo, entró aquí.\p¡Me asustó tanto que le di mi\nquerido POKéMON!\pAún me queda uno, pero ¿y si\nvuelve?\pPareces fuerte. ¿Podrías cuidar de\nmi POKéMON una temporada?$"
CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "¡Muchas gracias!\p¡Cuídalo mucho, por favor!$"
CianwoodCity_Text_ManiacGotShuckle:
	.string "¡{PLAYER} recibió un POKéMON!$"
CianwoodCity_Text_ManiacPartyFull:
	.string "Tu equipo POKéMON está lleno.$"
CianwoodCity_Text_ManiacIfHeComesBack:
	.string "¡Ay, no! ¿Qué haré si\nvuelve?…$"
CianwoodCity_Text_ManiacHowsdoing:
	.string "¡Hola! ¿Cómo le va a mi POKéMON?$"
CianwoodCity_Text_ManiacAskReturn:
	.string "¡Hola! ¿Cómo está mi POKéMON?\pCreo que ya estoy a salvo. ¿Me lo\npodrías devolver?$"
CianwoodCity_Text_ManiacThankYou:
	.string "¡Muchas gracias!$"
CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Oye, no llevas a mi POKéMON\ncontigo.$"
CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Mi POKéMON te ha cogido cariño.\pDe acuerdo, deberías quedártelo.\p¡Pero prométeme que lo cuidarás!$"
CianwoodCity_Text_ManiacRobbed:
	.string "Eh, algo no cuadra aquí.$"
CianwoodCity_Text_ManiacRobbed2:
	.string "No, no… Eso es igual que\nrobarme.$"
CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Para un POKéMON, la felicidad es\nestar con quien lo trata bien.$"
CianwoodCity_Text_ManiacLastMon:
	.string "Si recupero mi POKéMON,\n¿qué vas a usar tú\lpara combatir?$"
CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} le devolvió a SHUCKIE.$"
