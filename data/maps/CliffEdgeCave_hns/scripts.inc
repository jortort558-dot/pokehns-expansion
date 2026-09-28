CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Si ves una bifurcación dentro de\n"
	.string "una cueva, seguramente un camino\l"
	.string "sea el correcto y el otro acabe\l"
	.string "en un callejón sin salida.\p"
	.string "Pero todos acaban probando ambos.$"
