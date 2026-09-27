Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "Vine a explorar el TÚNEL ROCA.$"

Route9_Text_CamperDeanBeaten:
	.string "Whoa! Danger, man.$"

Route9_Text_CamperDeanAfter:
	.string "Mis POKéMON se hirieron antes de\n"
	.string "entrar en el TÚNEL ROCA.\p"
	.string "Será mejor llevarlos enseguida\n"
	.string "a un CENTRO POKéMON.$"

Route9_Text_PicnickerHeidiSeen:
	.string "¿Has ido alguna"
	.string "\nvez de picnic?"
	.string "\l$¡Es muy divertido!"
Route9_Text_PicnickerHeidiBeaten:
	.string "Ohhhh!$"

Route9_Text_PicnickerHeidiAfter:
	.string "Preparamos dulces y los repartimos\n"
	.string "entre todos.\p"
	.string "¡Están deliciosos!$"

Route9_Text_CamperSidSeen:
	.string "¡Eh, tú!"
	.string "\n$¡No tires basura!"
Route9_Text_CamperSidBeaten:
	.string "Sólo estaba"
	.string "\n$diciendo que…"
Route9_Text_CamperSidAfter:
	.string "Perdón. No estabas"
	.string "\ntirando basura."
	.string "\l$Me he equivocado."
Route9_Text_PicnickerEdnaSeen:
	.string "People shouldn't leave any litter\n"
	.string "behind.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "$¡Ohh…! Perdí…"
Route9_Text_PicnickerEdnaAfter:
	.string "Ahorrar energía es"
	.string "\nimportante, pero"
	.string "\pel entorno aún lo"
	.string "\n$es más."
Route9_Text_HikerTimSeen:
	.string "Cuando venga, rodeará el MONTE\n"
	.string "PLATEADO…\p"
	.string "Está en JOHTO, ¿verdad?$"

Route9_Text_HikerTimBeaten:
	.string "Estaba ocupado"
	.string "\n$cantando…"
Route9_Text_HikerTimAfter:
	.string "Los combates son"
	.string "\ncuestión de"
	.string "\l$concentración."
Route9_Text_HikerSidneySeen:
	.string "Te contaré un"
	.string "\nsecreto."
	.string "\pPero primero,"
	.string "\n$¡luchemos!"
Route9_Text_HikerSidneyBeaten:
	.string "¡Caray!"
	.string "\n$He perdido…"
Route9_Text_HikerSidneyAfter:
	.string "La CENTRAL ENERGÍA"
	.string "\nestá al otro lado"
	.string "\l$de un riachuelo."
Route9_Text_Sign:
	.string "RUTA 9"
	.string "\pCIUDAD CELESTE -"
	.string "\n$TÚNEL ROCA"
