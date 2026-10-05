NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveWooperPaldea
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveWooperPaldea::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersWooper MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WOOPER_PALDEA
    bufferspeciesname STR_VAR_1, SPECIES_WOOPER_PALDEA
    givemon SPECIES_WOOPER_PALDEA, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVEWOOPER
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
    .string "¡Hola, {PLAYER}!\p"
	.string "¿Has venido desde tan lejos,\n"
	.string "desde PUEBLO PRIMAVERA?\p"
	.string "Tengo una petición para alguien tan\n"
	.string "viajero como tú.\l"
	.string "Verás, mi POKéMON preferido de\l"
	.string "todo el mundo es el POKéMON\l"
	.string "singular llamado CELEBI.\p"
	.string "Si tienes uno, ¿te importaría\n"
	.string "enseñármelo?$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
    .string "Es un POKéMON maravilloso, pero\n"
	.string "no es exactamente lo que estaba\l"
	.string "buscando…$"

NewSinjoh_House1_OffersWooper:
    .string "¡Es él! ¡¡Un CELEBI de verdad!!\p"
	.string "Muchísimas gracias por traerlo tan\n"
	.string "al norte para que pudiera verlo.\p"
    .string "Toma, mi novia capturó de más\n"
	.string "en su viaje a una región lejana…\p"
    .string "Por favor, quédate con este WOOPER\n"
	.string "tan especial en agradecimiento.$"

NewSinjoh_House1_Text_Decline:
	.string "Vaya, qué pena. Tenía muchísimas\n"
	.string "ganas de verlo.$"

NewSinjoh_House1_Text_TakeCareOfWooper:
    .string "Cuida muy bien de ese WOOPER,\n"
	.string "¿de acuerdo?$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain, MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
    .string "¡Me alegro de verte otra vez,\n"
	.string "{PLAYER}!\p"
	.string "¿Cómo está portándose ese WOOPER?$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text, MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
    .string "¡Es una estantería repleta de\n"
	.string "videojuegos y cómics!$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
    .string "¡Evoii, evoii!$"
