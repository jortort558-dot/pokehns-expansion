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
	.string "Entre los POKéMON de agua,\n¡TENTACOOL es el mejor con una\lmilla náutica de ventaja!$"
CianwoodPokemoncenter_Text_Fisher2:
	.string "Parece que necesitas un POKéMON\nde agua.\p¡Toma este, tengo de sobra!$"
CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "¿Has conocido al POKéMANÍACO?\pSiempre presume de sus\nPOKéMON raros.$"
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
	.string "Los Entrenadores de este GIMNASIO\nson unos machotes bravucones.\pSi me quedo, quizá vengan a por mí.\pUn consejo: el LÍDER usa POKéMON\nde tipo LUCHA.\pDesconcértalo con POKéMON de tipo\nPSÍQUICO.\pAcaba con ellos antes de que usen\nsu fuerza física.\p¿Y las rocas del centro del\nGIMNASIO?\pSi no las mueves bien, no llegarás\nal LÍDER.\pSi te atascas, sal fuera.$"
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
	.string "Me encanta presumir de los POKéMON\nque he criado.\p¿A ti no?\p¡Voy a librar muchos combates para\npresumir de mis POKéMON!$"
