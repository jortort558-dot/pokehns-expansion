CherrygroveCity_CartographersHouse_hns_MapScripts::
	.byte 0

CherrygroveCity_CartographersHouse_EventScript_AtlasFragment::
	lock
	faceplayer
	msgbox CherrygroveCity_CartographersHouse_Text_AtlasFragment, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_JOHTO_SECRET_ATLAS_STARTED
	setflag FLAG_HIDE_CHERRYGROVE_ATLAS_FRAGMENT
	removeobject LOCALID_CARTOGRAPHER_ATLAS_FRAGMENT
	release
	end

CherrygroveCity_CartographersHouse_EventScript_Desk::
	msgbox CherrygroveCity_CartographersHouse_Text_Desk, MSGBOX_SIGN
	end

CherrygroveCity_CartographersHouse_EventScript_Map::
	msgbox CherrygroveCity_CartographersHouse_Text_Map, MSGBOX_SIGN
	end

CherrygroveCity_CartographersHouse_Text_AtlasFragment:
	.string "Hay un cilindro sellado con sal.\p"
	.string "Dentro aparece un mapa de Johto\n"
	.string "cubierto de rutas imposibles.\p"
	.string "Tres figuras idénticas vigilan\n"
	.string "una gruta de CIUDAD ORQUÍDEA.\p"
	.string "Guardas el FRAGMENTO DEL ATLAS\n"
	.string "entre los archivos del POKéGEAR.$"

CherrygroveCity_CartographersHouse_Text_Desk:
	.string "El escritorio pertenece a NEREO,\n"
	.string "un cartógrafo desaparecido.\p"
	.string "La última nota habla de tres\n"
	.string "hermanos que escuchan el mar.$"

CherrygroveCity_CartographersHouse_Text_Map:
	.string "Las rutas están marcadas con sal.\p"
	.string "Todas convergen en ORQUÍDEA.$"
