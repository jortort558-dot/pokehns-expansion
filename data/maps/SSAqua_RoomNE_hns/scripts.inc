SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "¿Estás solo?\n"
    .string "¡Entonces combatamos!$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "¡Esto me viene grande!$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "¿Habrá montañas en KANTO\n"
    .string "que merezca la pena escalar?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "¿Conoces a LILY?\n"
    .string "Es una DJ muy famosa en KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "¡Gyaaaah!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LILY está bien, ¡pero MARY\n"
    .string "es la mejor!\p"
    .string "¡Quiero escuchar los programas\n"
    .string "de radio de JOHTO!$"
