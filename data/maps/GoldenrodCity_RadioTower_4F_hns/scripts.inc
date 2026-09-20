GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "PROTÓN: ¡Alto ahí un segundo!\n¿No eres tú quien nos estorbó en el\lPOZO\lSLOWPOKE?\lYa veo... Haces todo esto porque te\ldivierte\lhacerme rabiar. ¡Mucho cuidado!\lPero ya que tanto lo deseas, ¡te\lmostraré la\lcolosal furia de un EJECUTIVO DEL\lTEAM ROCKET!$"
GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Uf...$"
GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "PROTÓN: Puede que hayas ganado esta\nvez...\lPero lo único que has conseguido es\lque la\lfuria del TEAM ROCKET arda con más\lfuerza.$"
GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "Estuve escuchando la radio mientras\nvisitaba\llas RUINAS.\lSe coló una emisión rarísima por\lallí.$"
GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "ROSA: ¿Por qué? ¿Por qué me tiene\nque pasar\lesto a mí?\l¡MEOWTH, ayúdame!$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "ROSA: ¡Oh! ¡Mi pequeño salvador!\n¿Aceptarías esto como\lagradecimiento?$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "ROSA: Va genial para esquivar los\nataques del\lenemigo.$"
GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "ROSA: ¡Por favor, sintonízame en LA\nHORA DEL\lPROFESOR OAK!$"
GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MEOWTH: ¡Meowth…!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "¿Planeas rescatar al DIRECTOR?\n¡Pues lo llevas claro, porque\lpienso borrarte\ldel mapa!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "¡No! ¡Increíble!$"
GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "¡No me lo puedo creer! ¡Me ha\nvencido!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "¡Alto! ¡Me conocen como la\nfortaleza del\lTEAM ROCKET!\l¡De aquí no vas a pasar!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "¡La fortaleza se ha desmoronado!$"
GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Te has ganado mi respeto, así que\nescucha un\lbuen consejo.\lNo es tarde. Todavía estás a tiempo\lde darte\lla vuelta.$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "¿Que si los POKéMON me parecen\nmonos?\l¡Mis POKéMON me parecerán divinos\len cuanto\lle revienten los morros a los\ltuyos!$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "¡Ay, no! ¡Menuda panda de inútiles!$"
GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "¡Yo solo me amo a mí misma y a mi\nbelleza!\l¿A quién le importan los POKéMON?$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Sencillamente magistral.\nEsta TORRE RADIO culminará nuestro\lgrandioso\lplan.$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Mmm…\nTodo gran plan tiene sus pequeños\ltropiezos.$"
GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "¿De verdad eres tan iluso como para\ncreer que\lpuedes detener al TEAM ROCKET?$"
GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4P PRODUCCIÓN$"
GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4P ESTUDIO 2$"
