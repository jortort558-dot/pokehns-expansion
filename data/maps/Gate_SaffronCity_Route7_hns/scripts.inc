Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "¿Te has enterado del incidente\n"
	.string "en la CENTRAL ENERGÍA?\p"
	.string "Está situada al este, cerca\n"
	.string "de PUEBLO LAVANDA.$"

Route7_Text_SaffronGuard_Serious:
	.string "Me tomo muy en serio mi trabajo\n"
	.string "de GUARDIA.\p"
	.string "¡Vaya! Tienes una POKéDEX.\p"
	.string "De acuerdo. ¡Puedes pasar!$"
