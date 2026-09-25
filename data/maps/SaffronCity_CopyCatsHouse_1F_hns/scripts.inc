SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "A mi hija le gusta imitar a otros.\p"
	.string "Sus imitaciones le han valido\n"
	.string "el apodo de COPIONA.$"

CopycatsHouse1F_Text_PokefanF:
	.string "Mi hija es muy egocéntrica…\p"
	.string "Tiene muy pocos amigos.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "Hace poco perdió el POKé MUÑECO\n"
	.string "que un chico le regaló hace tres\l"
	.string "años.\p"
	.string "Desde entonces ha mejorado aún más\n"
	.string "sus imitaciones…$"

CopycatsHouse1F_Text_Blissey:
	.string "BLISSEY: ¡Bliisii!$"
