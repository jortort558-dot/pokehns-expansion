GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Me encantan los POKéMON fuertes.\p"
    .string "Les doy PROTEÍNAS para aumentar\n"
    .string "su ATAQUE.$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "El HIERRO aumenta la DEFENSA\n"
    .string "de tus POKéMON.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "Se decía que ciertos POKéMON solo\n"
    .string "evolucionaban al intercambiarlos\l"
    .string "mediante un cable Game Link.\p"
    .string "Pfff… ¡Menuda desinformación!\p"
    .string "Conozco algunos de esos POKéMON:\n"
    .string "MACHOKE, KADABRA, HAUNTER y…\l"
    .string "GRAVELER.\p"
    .string "Pero aquí todos evolucionan\n"
    .string "al subir de nivel.$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
    .string "¡FORTALECE A TUS POKéMON!\p"
    .string "4.ª PLANTA: BOTIQUÍN$"
