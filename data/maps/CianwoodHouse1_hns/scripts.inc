CianwoodHouse1_hns_MapScripts:: .byte 0 CianwoodHouse1_EventScript_Hermit:: lock
faceplayer msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT goto_if_eq
VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh checkitem
ITEM_TIDAL_BELL goto_if_eq VAR_RESULT, TRUE,
CianwoodHouse1_EventScript_HermitTidalBell msgbox
CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT closemessage release end
CianwoodHouse1_EventScript_HermitTidalBell:: msgbox
CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT closemessage release end
CianwoodHouse1_EventScript_HermitHooh:: checkitem ITEM_CLEAR_BELL goto_if_eq
VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell msgbox
CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT closemessage release end
CianwoodHouse1_EventScript_HermitClearBell:: msgbox
CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT closemessage release end
CianwoodCity_Text_OldManIntro: .string "No recuerdo la última vez\nque alguien
vino a visitarme.\pDe joven también fui\nEntrenador POKéMON.\lIntenté llegar a
la torre y\lsumergirme en el océano.\pPuse mucho empeño en muchas\ncosas.\pAhora
me lo tomo con calma,\nescuchando las olas y el viento\len esta playa.$"
CianwoodCity_Text_BellTowerStory: .string "¿Has oído hablar de la
TORRE\nHOJALATA de CIUDAD IRIS?\pEn lo alto están las llamadas\nCampanas
Claras.\pNo emiten ni un sonido, ni siquiera\ncon vientos fuertes.\pSolo hay una
forma de hacerlas\nsonar.\pEs conseguir otra CAMPANA CLARA\ncomo las que hay en
lo alto de la\ltorre.\pLa busqué cuando era joven,\npero nunca conseguí una...$"
CianwoodCity_Text_WhirlIslandsStory: .string "¿Has oído hablar de las\nISLAS
REMOLINO?\pEn la poza de su cascada están las\nllamadas Campanas Oleaje.\pNo
emiten ni un sonido con el\nembate de las olas.\pSolo hay una forma de
hacerlas\nsonar.\pEs conseguir otra Campana Oleaje\ncomo las de la poza de
la\lcascada.\pLa busqué cuando era joven,\npero nunca conseguí una...$"
CianwoodCity_Text_ClearBellReaction: .string "¡Oh! ¿Has conseguido una\nCAMPANA
CLARA?\pAquel viejo sueño de juventud...\nYa veo...\pLo has
logrado...\n...\l¡Puedo oírlo!\pEl tañido de las campanas al viento\nllega desde
la dirección de la\lTORRE HOJALATA...$" CianwoodCity_Text_TidalBellReaction:
.string "¡Oh! ¿Has conseguido una\nCampana Oleaje?\pAquel viejo sueño de
juventud...\nYa veo...\pLo has logrado...\n...\l¡Puedo oírlo!\pEl tañido en la
brisa marina llega\ndesde la dirección de las\lISLAS REMOLINO...$"
