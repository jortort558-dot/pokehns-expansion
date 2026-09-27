Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "Somos el grupo de"
	.string "\nentrenadores de la"
	.string "\pFEDERACIÓN POKéMON"
	.string "\nde KANTO."
	.string "\p¡Te vamos a"
	.string "\n$arrollar!"
Route8_Text_BikerDwayneBeaten:
	.string "$¡Lo… lo siento!"
Route8_Text_BikerDwayneAfter:
	.string "¡Viva la"
	.string "\nFEDERACIÓN"
	.string "\l$POKéMON de KANTO!"
Route8_Text_BikerHarrisSeen:
	.string "La policía ha"
	.string "\ncerrado la VÍA"
	.string "\pSUBTERRÁNEA."
	.string "\n$¡Qué fastidio!"
Route8_Text_BikerHarrisBeaten:
	.string "¡P-perdóname!$"

Route8_Text_BikerHarrisAfter:
	.string "Destruido por"
	.string "\n$alguien de JOHTO…"
Route8_Text_BikerZekeSeen:
	.string "Somos la"
	.string "\nFEDERACIÓN"
	.string "\pPOKéMON de KANTO."
	.string "\n$¡Allá vamos!"
Route8_Text_BikerZekeBeaten:
	.string "$¡Vaya! ¡Perdona!"
Route8_Text_BikerZekeAfter:
	.string "Intentaremos no"
	.string "\nmolestar a nadie"
	.string "\l$a partir de ahora."
Route8_Text_SupernerdSamSeen:
	.string "¿Cómo funciona el"
	.string "\n$MAGNETOTRÉN?"
Route8_Text_SupernerdSamBeaten:
	.string "Quiero ver el"
	.string "\n$MAGNETOTRÉN…"
Route8_Text_SupernerdSamAfter:
	.string "¡El poder magnético es increíble!$"

Route8_Text_SupernerdTomSeen:
	.string "Mmm… Tienes muchas"
	.string "\nMEDALLAS de"
	.string "\l$GIMNASIO."
Route8_Text_SupernerdTomBeaten:
	.string "Tal y como pensé…"
	.string "\n$¡Eres fuerte!"
Route8_Text_SupernerdTomAfter:
	.string "Las MEDALLAS de"
	.string "\nGIMNASIO te dan"
	.string "\pventaja en los"
	.string "\n$combates."
Route8_Text_LockedDoor:
	.string "Está cerrado…$"

Route8_Text_UndergroundPathSign:
	.string "El cartel está"
	.string "\nroto."
	.string "\pEs imposible"
	.string "\n$leerlo…"
