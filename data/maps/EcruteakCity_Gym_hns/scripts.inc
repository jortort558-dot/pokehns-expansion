EcruteakCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Gym_OnTransition
	.byte 0

EcruteakCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_HideManolin
	clearflag FLAG_HIDE_MANOLIN_IRIS
	end

EcruteakCity_Gym_HideManolin::
	setflag FLAG_HIDE_MANOLIN_IRIS
	end

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	call GymToken_EventScript_Award
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	call Common_EventScript_AwardRandomMint
	giveitem ITEM_FESTIVAL_TICKET, 1
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	goto_if_set FLAG_VIOLET_KALOS_CALL_TRIGGERED, EcruteakCity_Gym_EventScript_Morty_SkipCall
	setflag FLAG_VIOLET_KALOS_CALL_TRIGGERED
	playse SE_POKENAV_CALL
	waitse
	pokenavcall EcruteakCity_Gym_Text_PokegearKalosRumorCall
	waitmessage
	delay 30
EcruteakCity_Gym_EventScript_Morty_SkipCall::
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD IRIS$"
EcruteakCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD IRIS\p"
	.string "ENTRENADORES CERTIFICADOS POR\n"
	.string "MORTI: {PLAYER}$"
MortyIntroText:
	.string "Has hecho bien en venir.\p"
	.string "Aquí, en CIUDAD IRIS, siempre se\n"
	.string "ha venerado a los POKéMON.\p"
	.string "Dice la leyenda que un POKéMON\n"
	.string "con los colores del arcoíris\l"
	.string "bajará para mostrarse ante un\l"
	.string "verdadero Entrenador.\p"
	.string "Yo creí en ese relato, así que\n"
	.string "he entrenado aquí en secreto.\p"
	.string "Como resultado, ahora puedo ver\n"
	.string "lo que otros no pueden.\p"
	.string "Solo un poco más...\p"
	.string "Con solo un poco más, podré ver\n"
	.string "el futuro en el que me encuentro\l"
	.string "con los POKéMON arcoíris.\p"
	.string "¡Tú vas a ayudarme a alcanzar\n"
	.string "ese nivel!$"
MortyWinLossText:
	.string "Aún no soy lo bastante bueno...\p"
	.string "De acuerdo. Esta MEDALLA es\n"
	.string "tuya.$"
Text_ReceivedFogBadge:
	.string "¡{PLAYER} recibió la MEDALLA\n"
	.string "NIEBLA!$"
MortyText_FogBadgeSpeech:
	.string "Con la MEDALLA NIEBLA, los\n"
	.string "POKéMON hasta nivel 50 te\l"
	.string "obedecerán.\p"
	.string "Además, cualquier POKéMON que\n"
	.string "sepa SURF podrá usarlo cuando\l"
	.string "quieras fuera del combate.\p"
	.string "Quiero que te lleves esto\n"
	.string "también.$"
MortyText_ShadowBallSpeech:
	.string "Es BOLA SOMBRA. Causa daño y a\n"
	.string "veces reduce la DEF. ESP. del\l"
	.string "rival.\p"
	.string "Úsala si te parece conveniente.$"
MortyFightDoneText:
	.string "Ya veo...\p"
	.string "Tu viaje te ha llevado a lugares\n"
	.string "muy lejanos.\p"
	.string "Has presenciado muchas más cosas\n"
	.string "de las que yo jamás he visto.\p"
	.string "Te tengo cierta envidia por\n"
	.string "ello...$"
MortyRematchText:
	.string "¡Ah, el CAMPEÓN de JOHTO! Has\n"
	.string "hecho bien en venir.\p"
	.string "Has demostrado gran fuerza,\n"
	.string "pero... ¿has crecido desde\l"
	.string "nuestro combate?\p"
	.string "He entrenado con mis POKéMON de\n"
	.string "tipo FANTASMA sin descanso.\p"
	.string "Veamos si puedes volver a\n"
	.string "superar las sombras.\p"
	.string "¿Quieres una revancha?$"
Morty_RematchDefeatText:
	.string "Aún no soy lo bastante bueno...\p"
	.string "Has presenciado muchas más cosas\n"
	.string "de las que yo jamás he visto.\p"
	.string "Te tengo cierta envidia por\n"
	.string "ello...$"
SageJeffreySeenText:
	.string "Pasé la primavera con mis\n"
	.string "POKéMON.\p"
	.string "Luego el verano, el otoño y el\n"
	.string "invierno...\p"
	.string "Y la primavera volvió a llegar.\n"
	.string "¡Llevamos juntos una eternidad!$"
SageJeffreyBeatenText:
	.string "Victorias y derrotas... He\n"
	.string "conocido ambas caras.$"
SageJeffreyAfterBattleText:
	.string "¿De dónde salieron los POKéMON?$"
SagePingSeenText:
	.string "¿Puedes causarle algún daño a\n"
	.string "nuestros POKéMON?$"
SagePingBeatenText:
	.string "¡Ah! ¡Bien hecho!$"
SagePingAfterBattleText:
	.string "Usamos POKéMON de tipo FANTASMA.\p"
	.string "¡Los ataques de tipo NORMAL no\n"
	.string "pueden hacerles nada!$"
MediumMarthaSeenText:
	.string "¡La victoria será mía!$"
MediumMarthaBeatenText:
	.string "¡P-pero si... he perdido!$"
MediumMarthaAfterBattleText:
	.string "¡El que más desea ganar es quien\n"
	.string "acaba alzándose con la victoria!$"
MediumGraceSeenText:
	.string "¿Perdido en nuestros pasillos\n"
	.string "oscuros? ¡Vénceme si quieres una\l"
	.string "pista!$"
MediumGraceBeatenText:
	.string "¿C-cómo?$"
MediumGraceAfterBattleText:
	.string "Vale, te contaré el secreto de\n"
	.string "las sombras.\p"
	.string "¡El camino está justo delante de\n"
	.string "tus propios ojos!$"
EcruteakCity_GymGuideText:
	.string "¡Ey, futuro CAMPEÓN! ¡Ya vas\n"
	.string "casi por la mitad del camino!\p"
	.string "Aquí usan POKéMON de tipo\n"
	.string "FANTASMA y SINIESTRO.\p"
	.string "Aunque MORTI es experto en\n"
	.string "FANTASMA, ten mucho cuidado con\l"
	.string "su ciervo místico.\p"
	.string "¡Dicen que provoca pesadillas\n"
	.string "muy chungas!$"
EcruteakCity_GymGuideWinText:
	.string "¡Uf, {PLAYER}! ¡Lo has bordado!\p"
	.string "¡Yo estaba acojonado en una\n"
	.string "esquina temblando de puro miedo!$"
EcruteakCity_GymClosedText:
	.string "MORTI, el LÍDER de GIMNASIO, no\n"
	.string "está aquí ahora mismo.\p"
	.string "Lo siento, pero tendrás que\n"
	.string "marcharte.\p"
	.string "Jojojojo.$"

EcruteakCity_Gym_EventScript_Manolin::
	lock
	faceplayer
	goto_if_set FLAG_MANOLIN_ITEM_IRIS, EcruteakCity_Gym_EventScript_Manolin_AfterItem
	msgbox EcruteakCity_Gym_Text_Manolin_Intro, MSGBOX_DEFAULT
	goto_if_set FLAG_MANOLIN_HEAL_IRIS, EcruteakCity_Gym_EventScript_Manolin_ChooseItem
	msgbox EcruteakCity_Gym_Text_Manolin_CheckHealth, MSGBOX_DEFAULT
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	giveitem ITEM_HYPER_POTION
	setflag FLAG_MANOLIN_HEAL_IRIS
	msgbox EcruteakCity_Gym_Text_Manolin_Healed, MSGBOX_DEFAULT

EcruteakCity_Gym_EventScript_Manolin_ChooseItem::
	msgbox EcruteakCity_Gym_Text_Manolin_OfferChoices, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MANOLIN_IRIS, FALSE
	switch VAR_RESULT
	case 0, EcruteakCity_Gym_EventScript_Manolin_GiveLumBerry
	case 1, EcruteakCity_Gym_EventScript_Manolin_GiveScopeLens
	case MULTI_B_PRESSED, EcruteakCity_Gym_EventScript_Manolin_NoChoice
	end

EcruteakCity_Gym_EventScript_Manolin_GiveLumBerry::
	giveitem ITEM_LUM_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_IRIS
	msgbox EcruteakCity_Gym_Text_Manolin_LumBerryExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Manolin_GiveScopeLens::
	giveitem ITEM_SCOPE_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MANOLIN_ITEM_IRIS
	msgbox EcruteakCity_Gym_Text_Manolin_ScopeLensExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Manolin_NoChoice::
	msgbox EcruteakCity_Gym_Text_Manolin_NoChoice, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Manolin_AfterItem::
	msgbox EcruteakCity_Gym_Text_Manolin_AfterItem, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_Manolin_Intro:
	.string "¡Hostia tú! ¡Sigues vivo en\n"
	.string "el locke, qué grande!\p"
	.string "Oye, este sitio da un mal rollo…\n"
	.string "¡Parece las Tierras de la Peste!\p"
	.string "¿El boss no era de tipo eléctrico?\n"
	.string "Ah, no… ¡que aquí está MORTI con\l"
	.string "los fantasmas y las sombras!$"

EcruteakCity_Gym_Text_Manolin_CheckHealth:
	.string "¡Pero si traes la party temblando!\n"
	.string "¡Un Mal de Ojo y te vas al hoyo!\p"
	.string "Deja que te tire una cura rápida\n"
	.string "antes de pisar las sombras.$"

EcruteakCity_Gym_Text_Manolin_Healed:
	.string "¡Party restaurada al cien por cien!\p"
	.string "Toma esta Hiperpoción por si las\n"
	.string "pesadillas se complican.$"

EcruteakCity_Gym_Text_Manolin_OfferChoices:
	.string "Para los fantasmas de MORTI tengo\n"
	.string "dos objetos bis muy finos.\p"
	.string "¿Prefieres disipar estados\n"
	.string "alterados o meter críticos salvajes\l"
	.string "con probabilidad aumentada?$"

EcruteakCity_Gym_Text_Manolin_LumBerryExplain:
	.string "¡BAYA ZIUELA! Te limpia al instante\n"
	.string "cualquier sueño, quemadura o peste.\p"
	.string "¡Que no te duerman en fase 1!$"

EcruteakCity_Gym_Text_Manolin_ScopeLensExplain:
	.string "¡PERISCOPIO! Sube la probabilidad\n"
	.string "de asestar golpes críticos.\p"
	.string "¡Revienta a ese Gengar con un\n"
	.string "burst que lo mande al lobby!$"

EcruteakCity_Gym_Text_Manolin_NoChoice:
	.string "Tranqui, que a oscuras yo también\n"
	.string "me pierdo en los menús.$"

EcruteakCity_Gym_Text_Manolin_AfterItem:
	.string "¡Cuidado dónde pisas! ¡No te caigas\n"
	.string "al foso que reinicias el pull!$"

EcruteakCity_Gym_Text_PokegearKalosRumorCall:
	.string "POKéGEAR: ¡Bip, bip!\p"
	.string "BOLETÍN RADIO JOHTO:\n"
	.string "“¡Interrumpimos la emisión!\p"
	.string "Llegan rumores desde CIUDAD MALVA\n"
	.string "sobre viajeros de KALOS.\p"
	.string "¡Mueve el dial hasta el final\n"
	.string "a SECRETOS DE JOHTO para oírlos!”$"
