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
	.string "GIMNASIO POKéMON DE CIUDAD IRIS\pENTRENADORES CERTIFICADOS POR\nMORTI:\l{PLAYER}$"
MortyIntroText:
	.string "Has hecho bien en venir.\pAquí, en CIUDAD IRIS, siempre se ha\nvenerado a los POKéMON.\pDice la leyenda que un POKéMON con\nlos colores del arcoíris bajará\lpara\lmostrarse ante un verdadero\lEntrenador.\pYo creí en ese relato, así que he\nentrenado aquí en secreto.\pComo resultado, ahora puedo ver lo\nque otros no pueden.\pSolo un poco más...\pCon solo un poco más, podré ver el\nfuturo en el que me encuentro con\llos POKéMON arcoíris.\p¡Tú vas a ayudarme a alcanzar ese\nnivel!$"
MortyWinLossText:
	.string "Aún no soy lo bastante bueno...\pDe acuerdo. Esta MEDALLA es tuya.$"
Text_ReceivedFogBadge:
	.string "¡{PLAYER} recibió la MEDALLA NIEBLA!$"
MortyText_FogBadgeSpeech:
	.string "Con la MEDALLA NIEBLA, los POKéMON\nhasta nivel 50 te obedecerán.\pAdemás, cualquier POKéMON que sepa\nSURF podrá usarlo cuando quieras\lfuera\ldel combate.\pQuiero que te lleves esto también.$"
MortyText_ShadowBallSpeech:
	.string "Es BOLA SOMBRA.\nCausa daño y a veces reduce la\lDEF. ESP. del rival.\pÚsala si te parece conveniente.$"
MortyFightDoneText:
	.string "Ya veo...\pTu viaje te ha llevado a lugares\nmuy lejanos.\pHas presenciado muchas más cosas\nde las que yo jamás he visto.\pTe tengo cierta envidia por ello...$"
MortyRematchText:
	.string "¡Ah, el CAMPEÓN de JOHTO!\nHas hecho bien en venir.\pHas demostrado gran fuerza, pero...\n¿has crecido desde nuestro combate?\pHe entrenado con mis POKéMON de\ntipo FANTASMA sin descanso.\pVeamos si puedes volver a superar\nlas\lsombras.\p¿Quieres una revancha?$"
Morty_RematchDefeatText:
	.string "Aún no soy lo bastante bueno...\pHas presenciado muchas más cosas\nde las que yo jamás he visto.\pTe tengo cierta envidia por ello...$"
SageJeffreySeenText:
	.string "Pasé la primavera con mis POKéMON.\pLuego el verano, el otoño y el\ninvierno...\pY la primavera volvió a llegar.\n¡Llevamos juntos una eternidad!$"
SageJeffreyBeatenText:
	.string "Victorias y derrotas... He conocido\nambas caras.$"
SageJeffreyAfterBattleText:
	.string "¿De dónde salieron los POKéMON?$"
SagePingSeenText:
	.string "¿Puedes causarle algún daño a\nnuestros POKéMON?$"
SagePingBeatenText:
	.string "¡Ah! ¡Bien hecho!$"
SagePingAfterBattleText:
	.string "Usamos POKéMON de tipo FANTASMA.\p¡Los ataques de tipo NORMAL no\npueden\lhacerles nada!$"
MediumMarthaSeenText:
	.string "¡La victoria será mía!$"
MediumMarthaBeatenText:
	.string "¡P-pero si... he perdido!$"
MediumMarthaAfterBattleText:
	.string "¡El que más desea ganar es quien\nacaba\lalzándose con la victoria!$"
MediumGraceSeenText:
	.string "¿Perdido en nuestros pasillos\noscuros?\l¡Vénceme si quieres una pista!$"
MediumGraceBeatenText:
	.string "¿C-cómo?$"
MediumGraceAfterBattleText:
	.string "Vale, te contaré el secreto de las\nsombras.\p¡El camino está justo delante de\ntus\lpropios ojos!$"
EcruteakCity_GymGuideText:
	.string "¡Ey, futuro CAMPEÓN! ¡Ya vas casi\npor la mitad del camino!\pAquí usan POKéMON de tipo FANTASMA\ny SINIESTRO.\pAunque MORTI es experto en\nFANTASMA,\lten mucho cuidado con su ciervo\lmístico.\p¡Dicen que provoca pesadillas muy\nchungas!$"
EcruteakCity_GymGuideWinText:
	.string "¡Uf, {PLAYER}! ¡Lo has bordado!\p¡Yo estaba acojonado en una esquina\ntemblando de puro miedo!$"
EcruteakCity_GymClosedText:
	.string "MORTI, el LÍDER de GIMNASIO, no\nestá aquí ahora mismo.\pLo siento, pero tendrás que\nmarcharte.\pJojojojo.$"
