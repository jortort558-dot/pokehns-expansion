NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "¡Hola, {PLAYER}! Mi marido está\n"
	.string "muy ocupado… Espero que esté bien.\p"
	.string "Cuando se centra en investigar\n"
	.string "sobre POKéMON, hasta se\l"
	.string "olvida de comer.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "¡Cuando sea mayor, voy a\n"
	.string "ayudar a mi papá!\p"
	.string "¡Voy a ser un gran\n"
	.string "profesor POKéMON!$"
