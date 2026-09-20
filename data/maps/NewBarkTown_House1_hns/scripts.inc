NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU es un POKéMON evolucionado.\p"
	.string "Me asombraron los hallazgos del\n"
	.string "PROF. ELM.\p"
	.string "Es muy famoso por sus\ninvestigaciones\l"
	.string "sobre la evolución POKéMON.\p"
	.string "… Suspiro…\p"
	.string "Ojalá pudiera ser una investigadora\n"
	.string "como él…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Mi hija está decidida a convertirse\n"
	.string "en la ayudante del PROF. ELM.\p"
	.string "¡Le encantan los POKéMON!\p"
	.string "¡Aunque a mí también me encantan!$"

