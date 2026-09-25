OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "El MARINERO del CAFÉ DE OLIVO de\nal lado es muy generoso.\pLe enseñó FUERZA a mi POKéMON.\pAhora mueve rocas enormes\nsin apenas esfuerzo.$"
OlivineCity_Text_PokecenterTeacher:
	.string "Hay alguien al otro lado del mar,\nen CIUDAD ORQUÍDEA.\pDicen que no para de presumir de\nsus POKéMON raros.$"
