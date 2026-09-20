CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "¿Vienes desde OLIVO?\p¿Recuerdas las cuatro islas que hay\nde\lcamino?\pHe oído que en su interior se\nesconde\luna criatura marina legendaria.$"
CianwoodCity_Text_LugiaHouseLass:
	.string "Dicen que solo podrás verla si\nllevas\lcontigo un ALA PLATEADA.\pDebe de desprender el mismo aroma\nque\lesa criatura.$"
CianwoodCity_Text_LugiaHouseTwin:
	.string "He oído que los remolinos que\nrodean\llas islas los provoca esa bestia\lmarina.\pSeguro que necesitas un movimiento\nespecial para sortearlos.$"
