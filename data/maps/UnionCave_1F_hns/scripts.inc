UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "Vas hacia PUEBLO AZALEA, ¿no?\p"
	.string "Deja que mis POKéMON comprueben si\n"
	.string "eres digno de combatir.$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "¡Oh, oh, oh!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "¡Muy bien! ¡Ya lo he decidido!\p"
	.string "¡No me iré hasta que mis POKéMON\n"
	.string "sean más fuertes!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Viajo por todas partes en busca de\n"
	.string "POKéMON.\p"
	.string "¿Tú también buscas POKéMON?\p"
	.string "¡Entonces somos rivales a la hora\n"
	.string "de coleccionar!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "Ay… Mis pobres POKéMON…$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "A veces se oyen rugidos de POKéMON\n"
	.string "desde el fondo de la cueva.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "¡Vaya! ¡Qué sorpresa!\p"
	.string "¡No esperaba ver a nadie aquí!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "¡Vaya! ¡Me has dado una paliza!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "Me engañaron para que comprara una\n"
	.string "COLASLOWPOKE.\p"
	.string "Me da pena el pobre POKéMON.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "El SUPERSÓNICO de ZUBAT confunde\n"
	.string "a mis POKéMON.\p"
	.string "¡Eso me enfada muchísimo!$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "¡Me he quedado sin llama!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Los fines de semana se oyen\n"
	.string "rugidos extraños desde el fondo\l"
	.string "de la cueva.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "Con luz, una cueva no da miedo.\p"
	.string "Si eres fuerte, los POKéMON tampoco\n"
	.string "dan miedo.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "¡DESTELLO!$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "El fuego de mi POKéMON es lo que\n"
	.string "ilumina esta cueva.$"
