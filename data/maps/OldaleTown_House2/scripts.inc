OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "I taught MUNCHLAX BODYSLAM...\l"
	.string "And it evolved!$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "I caught a MUNCHLAX for it's LEFTOVERS\n"
	.string "But it only had an ORAN BERRY.\l"
	.string "Such a bummer!\l"
	.string "My mother is now looking after it.$"

