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
	.string "¡Vaya! ¡Excelente! ¡Has completado\n"
	.string "la POKéDEX!\p"
	.string "¡Enhorabuena!$"

GameFreak_Text_GraphicArtist:
	.string "Soy el DISEÑADOR GRÁFICO.\p"
	.string "¡Yo te dibujé!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Soy el DISEÑADOR GRÁFICO.\p"
	.string "¿Has completado la POKéDEX?\p"
	.string "¿Quieres que imprima tu\n"
	.string "DIPLOMA?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Avísame si quieres que imprima tu\n"
	.string "DIPLOMA.$"

GameFreak_Text_GraphicArtistError:
	.string "Algo va mal. Tendré que cancelar\n"
	.string "la impresión.$"

GameFreak_Text_Programmer:
	.string "¿Quién, yo? Soy el PROGRAMADOR.\p"
	.string "¡Prueba las tragaperras!$"

GameFreak_Text_CharacterDesigner:
	.string "¿A que las GEMELAS son adorables?\p"
	.string "Y YASMINA también es muy guapa.\p"
	.string "¡Me encantan!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "SALA DE DESARROLLO DE GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "Es un dibujo detallado de una\n"
	.string "chica guapa.$"

CeladonMansion3F_Text_GameProgram:
	.string "Es el código del juego. ¡Tocarlo\n"
	.string "podría introducir algún error!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "Está lleno de material de\n"
	.string "consulta. Hasta hay un\l"
	.string "POKé MUÑECO.$"
