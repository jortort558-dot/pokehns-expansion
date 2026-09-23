EcruteakCity_Gym_hns_MapScripts::
	.byte 0

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
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
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
