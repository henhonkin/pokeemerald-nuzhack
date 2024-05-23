.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_ChoiceSpecs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_PokemonCenter_1F_EventScript_GiveChoiceSpecs
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_NotGiveChoiceSpecs
	end

OldaleTown_PokemonCenter_1F_EventScript_GiveChoiceSpecs::
	msgbox OldaleTown_PokemonCenter_1F_Text_GiveChoiceSpecs, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_NotGiveChoiceSpecs::
	msgbox OldaleTown_PokemonCenter_1F_Text_NotGiveChoiceSpecs, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "It has expanded item space.\p"
	.string "If you fill it anyways,\p"
	.string "STOP HOARDING!$"

OldaleTown_PokemonCenter_1F_Text_ChoiceSpecs:
	.string "I got some CHOICE SPECS.\n"
	.string "Do you want to have them?$"
	
OldaleTown_PokemonCenter_1F_Text_GiveChoiceSpecs:
	.string "Haha.\p"
	.string "No.\p"
	.string "I went to so much trouble getting\n"
	.string "them, I'm not giving them away\l"
	.string "for free.$"
	
OldaleTown_PokemonCenter_1F_Text_NotGiveChoiceSpecs:
	.string "Really? You don't want them?$"
	
OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.\p"
	.string "Supposedly.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.\p"
        .string "Supposedly.$"

