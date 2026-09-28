SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "Intento olvidar mis penas.\n"
    .string "¡Combatamos!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Me llora el corazón…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Nada como un viaje para superar\n"
    .string "un corazón roto.\p"
    .string "Pero este barco es demasiado\n"
    .string "rápido para olvidar las penas.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Voy a presentar mis canciones\n"
    .string "en la TORRE RADIO de TRIGAL.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "¡Vaya! ¡Distorsión total!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "Iba a debutar en la TORRE BATALLA…\p"
    .string "Debería volver a CIUDAD CARMÍN\n"
    .string "y empezar a entrenar de nuevo…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "Hablando de la TORRE RADIO,\n"
    .string "¿cuál es el número de la suerte\l"
    .string "de esta semana?$"
