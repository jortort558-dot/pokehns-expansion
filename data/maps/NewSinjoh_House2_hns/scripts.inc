NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text, MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
    .string "Hola, criatura…\p"
	.string "Te doy la bienvenida a la…\n"
	.string "bueno, podrías llamarlo biblioteca\l"
	.string "de Nuevo Sinjoh.\p"
	.string "En realidad, aquí guardamos la\n"
	.string "crónica histórica del pueblo,\l"
	.string "así como libros que traemos\l"
	.string "de otras regiones…$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "¡Tooor!$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North, MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
    .string "Está repleta de libros antiguos\n"
	.string "con encuadernación de cuero.\p"
	.string "El idioma resulta irreconocible.$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South, MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
    .string "Está repleta de libros\n"
	.string "sobre POKéMON.\p"
	.string "Estos parecen más recientes\n"
	.string "y familiares.$"
