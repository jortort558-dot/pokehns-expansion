CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "En cuanto a POKéMON de agua,\n¡TENTACOOL\les el amo por una milla náutica!$"
CianwoodPokemoncenter_Text_Fisher2:
	.string "Parece que te vendría bien un\nPOKéMON de\lagua.\p¡Toma, quédate con éste, tengo de\nsobra!$"
CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "¿Has conocido al POKéMANÍACO?\nSiempre está fardando de sus\lPOKéMON\lraros.$"
CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Los del GIMNASIO de aquí son unos\nmachotes\lbrabucones.\pSi me acerco mucho, igual la toman\nconmigo.\lUn consejo: el LÍDER usa el tipo\lLUCHA.\pAsí que deberías marearlo con\nPOKéMON de\ltipo PSÍQUICO.\lAcaba con ellos antes de que usen\lsu\lfuerza bruta.\p¿Y las rocas del centro del\nGIMNASIO?\lSi no las empujas bien, no llegarás\lhasta\lel LÍDER.\lSi te atascas, sal fuera y vuelve a\lentrar.$"
CianwoodCity_Text_GymGuideWin:
	.string "¡{PLAYER}! ¡Has ganado!\n¡Se te nota en la cara nada más\lverte!$"
CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "Me encanta lucir a los POKéMON que\nhe\lcriado con tanto esmero.\l¿A ti no?\l¡Pienso meterme en mil combates\lpara\lpresumir de equipo!$"
