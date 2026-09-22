gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} fue enviado al\n"
	.string "PC DE ALGUIEN.\p"
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} fue enviado al\n"
#if IS_FRLG || IS_HNS
	.string "PC DE BILL.\p"
#else
	.string "PC DE LANETTE.\p"
#endif
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "La CAJA “{STR_VAR_3}” del\n"
	.string "PC DE ALGUIEN estaba llena.\p"
	.string "{STR_VAR_2} fue enviado a la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "La CAJA “{STR_VAR_3}” del\n"
#if IS_FRLG || IS_HNS
	.string "PC DE BILL estaba llena.\p"
#else
	.string "PC DE LANETTE estaba llena.\p"
#endif
	.string "{STR_VAR_2} fue enviado a la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} fue enviado al\n"
	.string "PC de {B_PC_CREATOR_NAME}.\p"
	.string "Se guardó en la\n"
	.string "CAJA “{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "¡{PLAYER} obtuvo\n"
	.string "{STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "¡No hay sitio para más POKéMON!\p"
	.string "¡Todas las CAJAS están llenas!$"

gText_NicknameThisPokemon::
	.string "¿Quieres ponerle un mote a\n"
	.string "{STR_VAR_1}?$"
