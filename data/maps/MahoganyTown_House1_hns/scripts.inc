MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
	.string "He oído que ha aparecido un\nGYARADOS rojo\len el LAGO.\pEs rarísimo, porque hasta los\nGYARADOS\lnormales son escasos en esas aguas…$"
MahoganyRedGyaradosHouse_Text_Teacher:
	.string "¿Mi programa de radio preferido?\nSin duda, MÚSICA POKéMON.$"
MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
	.string "Llevo oyendo unas risas tétricas\npor la\lradio…\pQué mal rollo dan.$"
