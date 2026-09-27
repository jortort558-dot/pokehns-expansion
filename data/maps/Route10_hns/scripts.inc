Route10_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route10_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route10_EventScript_Surge::
    lock
    faceplayer
    msgbox Route10_Text_Surge, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_PLANT_SURGE
    removeobject LOCALID_ROUTE10_SURGE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SURGE
    release
    end

Route10_Text_Surge:
    .string "¡Eh, chaval!\p"
	.string "¡No bajes la guardia! Este lugar\n"
	.string "está cargado de electricidad.\p"
	.string "Si quieres la revancha, ve al\n"
	.string "DOJO-KARATE.$"

Route10_EventScript_Item_Rock_Polish::
    finditem ITEM_TM_ROCK_POLISH
    end

Route10_EventScript_Jim::
	trainerbattle_single TRAINER_JIM_HNS, Route10_Text_HikerJimSeen, Route10_Text_HikerJimBeaten
	msgbox Route10_Text_HikerJimAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_HNS, Route10_Text_PokefanmRobertSeen, Route10_Text_PokefanmRobertBeaten
	msgbox Route10_Text_PokefanmRobertAfter, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_EventScript_PPSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route10_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE10_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Route10_EventScript_ZapdosRan::
	release
	end


Route10_Text_HikerJimSeen:
	.string "Hahahah!$"

Route10_Text_HikerJimBeaten:
	.string "Hahaha-hachoo!$"

Route10_Text_HikerJimAfter:
	.string "¡La alergia me hace estornudar!\n"
	.string "Ahahah-CHOO!$"

Route10_Text_PokefanmRobertSeen:
	.string "Te gustan los"
	.string "\nPOKéMON, ¿verdad?"
	.string "\p$¡A mí también!"
Route10_Text_PokefanmRobertBeaten:
	.string "Debo admitir mi"
	.string "\n$derrota."
Route10_Text_PokefanmRobertAfter:
	.string "Mira lo que le has"
	.string "\nhecho a mi"
	.string "\lPOKéMON."
	.string "\p$No lo olvidaré…"
Route10_Text_PowerPlant:
	.string "¿Has oído lo del"
	.string "\naccidente de la"
	.string "\lCENTRAL ENERGÍA?"
	.string "\pSe encuentra al"
	.string "\nEste, cerca de"
	.string "\l$PUEBLO LAVANDA."
Route10_Text_Sign:
	.string "RUTA 10"
	.string "\pCIUDAD CELESTE -"
	.string "\n$PUEBLO LAVANDA"
