MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "¡Esta vez no pienso morder el\npolvo!$"
MountMortar2_Text_PokemaniacMillerBeaten:
	.string "¿He perdido contra un crío...?$"
MountMortar2_Text_PokemaniacMillerAfter:
	.string "Hace poco pasó por aquí un karateka\ncon\lganas de pelea.\pEra insultantemente bueno.\nNos dio una tunda que para qué\lcontarte.\pSe adentró en la cueva diciendo que\nera\lparte de su riguroso entrenamiento.\l¿Cómo le irá? $"
MountMortar2_Text_SupernerdMarkusSeen:
	.string "¡Ey! ¡HUGH!$"
MountMortar2_Text_SupernerdMarkusBeaten:
	.string "Te confundí con otra persona…$"
MountMortar2_Text_SupernerdMarkusAfter:
	.string "Vine a explorar el MONTE MORTERO,\npero me separé de mi compañero…\p¿Te has cruzado con un Entrenador\nque lleva un SEADRA con CASCADA?$"
