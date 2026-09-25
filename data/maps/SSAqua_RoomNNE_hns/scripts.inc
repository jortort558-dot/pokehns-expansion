SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "Voy a KANTO para poner a prueba\n"
    .string "mis habilidades.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "¡Quería ganar!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "Los entrenadores de JOHTO pueden\n"
    .string "retarse con los LÍDERES de\l"
    .string "GIMNASIO de KANTO.$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "¡Entreno para convertirme\n"
    .string "en CAMPEONA!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "¿Qué diferencia hay\n"
    .string "entre nosotros?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "¡Algún día te venceré!$"
