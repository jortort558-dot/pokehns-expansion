CeladonCity_DepartmentStore_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonDept3_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonDept3_Pokemart:
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_CAPTIVATE
	.2byte ITEM_TM_STEALTH_ROCK
	.2byte ITEM_TM_BRINE
	.2byte ITEM_TM_AVALANCHE
	.2byte ITEM_TM_DARK_PULSE
	.2byte ITEM_TM_GYRO_BALL
	.2byte ITEM_TM_DREAM_EATER
	.2byte ITEM_TM_GIGA_IMPACT
	.2byte ITEM_TM_ENDURE
	pokemartlistend

CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "No sé en qué\n"
	.string "POKéMON debería\l"
	.string "utilizar esta MT…$"

CeladonDeptStore3F_Text_GameboyKid1:
	.string "¡Oh, oh! Cambié\n"
	.string "mis POKéMON sin\p"
	.string "quitarles la\n"
	.string "MEJORA.$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "¡Sí! ¡Ya tengo\n"
	.string "un PORYGON!\p"
	.string "Se me dan muy mal\n"
	.string "las tragaperras.\p"
	.string "¡Jamás ganaría\n"
	.string "bastantes fichas!\p"
	.string "¿Ehh…?\p"
	.string "¡El PORYGON que he\n"
	.string "cambiado se ha\p"
	.string "convertido en otro\n"
	.string "POKéMON!$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "En la TIENDA DE MT\n"
	.string "hay movimientos\l"
	.string "raros.$"

CeladonDeptStore3F_Text_Directory:
	.string "P2: TIENDA DE MT\p"
	.string "¡Fortalece a tus\n"
	.string "POKéMON!$"
