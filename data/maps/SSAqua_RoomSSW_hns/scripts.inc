SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "¡Voy a KANTO a dar espectáculos\n"
    .string "escupiendo fuego!$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Fsss… La llama es diminuta…$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "Supongo que el fuego pierde fuerza\n"
    .string "en el mar. ¿Que da igual? ¿Seguro?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "¡Voy a visitar a mi abuela\n"
    .string "y a capturar bichos!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "¡Oh! ¡Vaya, eres fuerte!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "¡En los árboles de JOHTO se\n"
    .string "encuentran muchos POKéMON!$"
