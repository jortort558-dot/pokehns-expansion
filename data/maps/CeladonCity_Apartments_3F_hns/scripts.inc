CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "¿Ah, sí?\p"
	.string "¡Soy el DISEÑADOR DEL JUEGO!\p"
	.string "Completar la POKéDEX es difícil,\n"
	.string "¡pero no te rindas!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "¡Uau! ¡Excelente! ¡Has\n"
	.string "completado la POKéDEX!\p"
	.string "¡Enhorabuena!$"

GameFreak_Text_GraphicArtist:
	.string "Soy el DISEÑADOR\n"
	.string "GRÁFICO.\p"
	.string "¡Yo te he\n"
	.string "dibujado!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Soy el DISEÑADOR GRÁFICO.\p"
	.string "¿Has completado la POKéDEX?\p"
	.string "¿Quieres que imprima tu\n"
	.string "DIPLOMA?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Avísame si quieres\n"
	.string "que te imprima tu\l"
	.string "DIPLOMA.$"

GameFreak_Text_GraphicArtistError:
	.string "Algo va mal.\n"
	.string "Tengo que cancelar\l"
	.string "la impresión.$"

GameFreak_Text_Programmer:
	.string "¿Quién? ¿Yo? Soy\n"
	.string "el PROGRAMADOR.\p"
	.string "¡Juega a las\n"
	.string "tragaperras!$"

GameFreak_Text_CharacterDesigner:
	.string "¿A que las GEMELAS\n"
	.string "son adorables?\p"
	.string "Y YASMINA también\n"
	.string "es muy guapa.\p"
	.string "¡Me encantan!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "SALA DE DESARROLLO\n"
	.string "DE GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "Es un dibujo\n"
	.string "detallado de una\l"
	.string "chica guapa.$"

CeladonMansion3F_Text_GameProgram:
	.string "Es el programa del\n"
	.string "juego. ¡No lo\p"
	.string "toques! ¡Podrías\n"
	.string "estropearlo!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "Está lleno de material de\n"
	.string "consulta. Hasta hay un\l"
	.string "POKé MUÑECO.$"
