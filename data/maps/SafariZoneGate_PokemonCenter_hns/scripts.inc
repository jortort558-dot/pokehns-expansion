SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Quienes vienen al CENTRO POKéMON\n"
	.string "suelen cuidar bien de sus POKéMON.\p"
	.string "¿No crees?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Tras cruzar la montaña buscando\n"
	.string "un CENTRO POKéMON, cuando estás\l"
	.string "a punto de caer rendido…\p"
	.string "¡Encontrarlo parece el paraíso!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, qué diversión.\n"
	.string "Safari, safari, ¡qué emoción!\p"
	.string "¡Muchos POKéMON nos esperan!\p"
	.string "…Es una canción que me inventé.\n"
	.string "La canto dentro de la ZONA SAFARI.$"

SafariZoneGate_PokemonCenter_EventScript_DoctoreFernan::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_FernanIntro, MSGBOX_DEFAULT
	checkmoney 20000
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_PokemonCenter_EventScript_FernanNoMoney
	msgbox SafariZoneGate_PokemonCenter_Text_FernanPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SafariZoneGate_PokemonCenter_EventScript_FernanDeclined
SafariZoneGate_PokemonCenter_EventScript_FernanChooseMon:
	msgbox SafariZoneGate_PokemonCenter_Text_FernanChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, SafariZoneGate_PokemonCenter_EventScript_FernanDeclined
	special DoctoreFernan_CheckAndPrepareForms
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_PokemonCenter_EventScript_FernanNoForms
	msgbox SafariZoneGate_PokemonCenter_Text_FernanSelectForm, MSGBOX_DEFAULT
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, SafariZoneGate_PokemonCenter_EventScript_FernanDeclined
	goto_if_eq VAR_RESULT, SPECIES_NONE, SafariZoneGate_PokemonCenter_EventScript_FernanDeclined
	copyvar VAR_0x8005, VAR_RESULT
	bufferspeciesname STR_VAR_2, VAR_0x8005
	msgbox SafariZoneGate_PokemonCenter_Text_FernanConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SafariZoneGate_PokemonCenter_EventScript_FernanDeclined
	removemoney 20000
	playse SE_SHOP
	updatemoneybox
	playse SE_BALL_TRADE
	waitse
	special DoctoreFernan_ApplyFormChange
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox SafariZoneGate_PokemonCenter_Text_FernanDone, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_FernanNoMoney::
	msgbox SafariZoneGate_PokemonCenter_Text_FernanNoMoney, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_FernanNoForms::
	msgbox SafariZoneGate_PokemonCenter_Text_FernanNoForms, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_FernanDeclined::
	msgbox SafariZoneGate_PokemonCenter_Text_FernanDeclined, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_DoctoriniBea::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_BeaIntro, MSGBOX_DEFAULT
	checkmoney 20000
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_PokemonCenter_EventScript_BeaNoMoney
	msgbox SafariZoneGate_PokemonCenter_Text_BeaPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SafariZoneGate_PokemonCenter_EventScript_BeaDeclined
SafariZoneGate_PokemonCenter_EventScript_BeaChooseMon:
	msgbox SafariZoneGate_PokemonCenter_Text_BeaChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, SafariZoneGate_PokemonCenter_EventScript_BeaDeclined
	special DoctoriniBea_CheckGender
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_PokemonCenter_EventScript_BeaCannotChange
	msgbox SafariZoneGate_PokemonCenter_Text_BeaConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SafariZoneGate_PokemonCenter_EventScript_BeaDeclined
	removemoney 20000
	playse SE_SHOP
	updatemoneybox
	playse SE_BALL_TRADE
	waitse
	special DoctoriniBea_ApplyGenderChange
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox SafariZoneGate_PokemonCenter_Text_BeaDone, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_BeaNoMoney::
	msgbox SafariZoneGate_PokemonCenter_Text_BeaNoMoney, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_BeaCannotChange::
	msgbox SafariZoneGate_PokemonCenter_Text_BeaCannotChange, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_EventScript_BeaDeclined::
	msgbox SafariZoneGate_PokemonCenter_Text_BeaDeclined, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_PokemonCenter_Text_FernanIntro:
	.string "¡Salute! ¡Soy Il Doctore Fernan!\n"
	.string "Gran genio de la metamorfosis.\p"
	.string "Puedo alterar la adaptación morfológica\n"
	.string "o regional de cualquier espécimen.\l"
	.string "¡Formas Alola, Galar, Hisui o Paldea,\l"
	.string "y todas las variantes florales!\p"
	.string "Cada alteración genética molecular\n"
	.string "cuesta exactamente 20.000¥.$"

SafariZoneGate_PokemonCenter_Text_FernanPrompt:
	.string "¿Te apetece una mutación de forma\n"
	.string "para alguno de tus POKéMON?$"

SafariZoneGate_PokemonCenter_Text_FernanChooseMon:
	.string "¡Fantástico! Elige al paciente\n"
	.string "que va a someterse a mi método.$"

SafariZoneGate_PokemonCenter_Text_FernanSelectForm:
	.string "¿A qué variante o adaptación\n"
	.string "deseas transformar a {STR_VAR_1}?$"

SafariZoneGate_PokemonCenter_Text_FernanConfirm:
	.string "¿Confirmas metamorfosear a tu\n"
	.string "{STR_VAR_1} en {STR_VAR_2}\l"
	.string "por la módica tarifa de 20.000¥?$"

SafariZoneGate_PokemonCenter_Text_FernanDone:
	.string "¡Magnífico! ¡Un éxito rotundo!\n"
	.string "¡{STR_VAR_1} ahora es {STR_VAR_2}!\p"
	.string "La ciencia siempre triunfa, amico.$"

SafariZoneGate_PokemonCenter_Text_FernanNoMoney:
	.string "Mamma mia… ¡La ciencia puntera\n"
	.string "requiere reactivos caros!\l"
	.string "Vuelve cuando tengas los 20.000¥.$"

SafariZoneGate_PokemonCenter_Text_FernanNoForms:
	.string "Mmm… Me temo que {STR_VAR_1}\n"
	.string "no posee variantes morfológicas\l"
	.string "ni adaptaciones regionales conocidas.$"

SafariZoneGate_PokemonCenter_Text_FernanDeclined:
	.string "Una lástima. ¡Il Doctore Fernan\n"
	.string "estará aquí cuando busques el cambio!$"

SafariZoneGate_PokemonCenter_Text_BeaIntro:
	.string "¡Buenas! Soy La Doctorini Bea.\n"
	.string "Especialista en endocrinología\l"
	.string "y reprogramación cromosómica.\p"
	.string "Puedo cambiar el sexo de tu POKéMON\n"
	.string "de forma limpia, segura y definitiva.\p"
	.string "La intervención cuesta 20.000¥.$"

SafariZoneGate_PokemonCenter_Text_BeaPrompt:
	.string "¿Quieres reasignar el sexo biológico\n"
	.string "de alguno de tus compañeros?$"

SafariZoneGate_PokemonCenter_Text_BeaChooseMon:
	.string "Indícame qué POKéMON pasará\n"
	.string "por mi consulta especializada.$"

SafariZoneGate_PokemonCenter_Text_BeaConfirm:
	.string "{STR_VAR_1} actualmente es {STR_VAR_2}.\n"
	.string "¿Quieres reasignarlo a {STR_VAR_3}\l"
	.string "a cambio de 20.000¥?$"

SafariZoneGate_PokemonCenter_Text_BeaDone:
	.string "¡Cirugía celular impecable!\n"
	.string "¡{STR_VAR_1} ahora es {STR_VAR_2}!\l"
	.string "Trátalo con todo el cariño del mundo.$"

SafariZoneGate_PokemonCenter_Text_BeaNoMoney:
	.string "Vaya… Mis instrumentos de precisión\n"
	.string "no se calibran gratis.\l"
	.string "Necesitarás 20.000¥ para el servicio.$"

SafariZoneGate_PokemonCenter_Text_BeaCannotChange:
	.string "Oh, lo siento mucho. {STR_VAR_1}\n"
	.string "no tiene sexo biológico reasignable\l"
	.string "(o pertenece a una especie de sexo único).$"

SafariZoneGate_PokemonCenter_Text_BeaDeclined:
	.string "Sin problema. ¡Para cualquier ajuste\n"
	.string "vital, la Doctorini Bea está a tu orden!$"

