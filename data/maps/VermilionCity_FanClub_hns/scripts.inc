VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Soy el PRESIDENTE del CLUB\n"
	.string "DE FANS DE POKéMON.\p"
	.string "He criado más de 150 POKéMON.\p"
	.string "Soy muy exigente con todo\n"
	.string "lo relacionado con los POKéMON.\p"
	.string "¿Has venido solo para oírme hablar\n"
	.string "de mis POKéMON?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "¡Bien! ¡Escucha con atención!\p"
	.string "Verás… Mi RAPIDASH favorito…\p"
	.string "Es… mono… adorable… listo…\n"
	.string "irresistible…\l"
	.string "Y… asombroso… Ah… ¿Tú también\l"
	.string "lo crees?…\l"
	.string "Demasiado… salvaje… hermoso…\l"
	.string "amable…\l"
	.string "¡Me encanta!\p"
	.string "Cuando duerme… lo abrazo… Es\n"
	.string "cálido y mimoso…\l"
	.string "Y además… espectacular…\l"
	.string "fascinante… sencillamente divino…\p"
	.string "¡Uy! ¡Mira qué hora es!\n"
	.string "¡Te he entretenido demasiado!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Gracias por escucharme.\n"
	.string "¡Quiero que te quedes con esto!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "Es un CARAMELO RARO que fortalece\n"
	.string "a los POKéMON.\p"
	.string "Yo prefiero fortalecer a mis\n"
	.string "POKéMON combatiendo, así que\l"
	.string "puedes quedártelo.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "¡Hola, {PLAYER}!\p"
	.string "¿Has vuelto para que te hable\n"
	.string "de mis POKéMON?\p"
	.string "¿No? Vaya… Tenía más historias\n"
	.string "que contarte…$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "Qué decepción…\p"
	.string "Vuelve si quieres escucharme.$"

PokemonFanClub_Text_Receptionist:
	.string "Nuestro PRESIDENTE habla mucho\n"
	.string "cuando se trata de POKéMON…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "Me encanta cómo mueve CLEFAIRY\n"
	.string "el dedo cuando intenta usar\l"
	.string "METRÓNOMO.\p"
	.string "¡Es adorable!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "Me encanta CLEFAIRY, pero nunca\n"
	.string "he conseguido capturar uno.\p"
	.string "Así que me conformo con un\n"
	.string "POKé MUÑECO que encontré.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Ya entiendo. La niña que perdió\n"
	.string "este POKé MUÑECO está triste…\p"
	.string "¿Puedes devolverle el POKé MUÑECO\n"
	.string "a esa pobre niña?\p"
	.string "Algún día me haré amigo de un\n"
	.string "CLEFAIRY de verdad. ¡No te apures!$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "Ya verás. Conseguiré que un\n"
	.string "CLEFAIRY de verdad sea mi amigo.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "¡Mira a mi precioso BAYLEEF!\p"
	.string "¡La hoja de su cabeza es monísima!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "¡Es un CLEFAIRY! ¿Eh?\p"
	.string "Ah, cierto. Es un POKé MUÑECO\n"
	.string "de CLEFAIRY.$"

PokemonFanClub_Text_Bayleef:
	.string "BAYLEEF: ¡Lii, liif!$"

PokemonFanClub_Text_Listen:
	.string "Escuchemos con educación\n"
	.string "a los demás entrenadores.$"

PokemonFanClub_Text_Bragging:
	.string "¡Si alguien presume, presume tú\n"
	.string "también!$"
