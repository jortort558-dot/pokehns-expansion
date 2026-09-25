SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Quienes vienen al CENTRO POKéMON\n"
	.string "suelen cuidar bien de sus POKéMON.\p"
	.string "¿No crees?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Tras cruzar la montaña buscando\n"
	.string "un CENTRO POKéMON, cuando estás\l"
	.string "a punto de caer rendido…\p"
	.string "¡Encontrarlo parece el paraíso!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, qué diversión.\n"
	.string "Safari, safari, ¡qué emoción!\p"
	.string "¡Muchos POKéMON nos esperan!\p"
	.string "…Es una canción que me inventé.\n"
	.string "La canto dentro de la ZONA SAFARI.$"
