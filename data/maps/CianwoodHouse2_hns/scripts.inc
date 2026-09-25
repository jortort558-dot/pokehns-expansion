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
	.string "¿Vienes desde OLIVO?\p¿Recuerdas las cuatro islas que hay\npor el camino?\pDicen que una criatura marina\nlegendaria se oculta en ellas.$"
CianwoodCity_Text_LugiaHouseLass:
	.string "Dicen que solo podrás verla si\nllevas un ALA PLATEADA.\pDebe de tener el mismo aroma que\nla criatura.$"
CianwoodCity_Text_LugiaHouseTwin:
	.string "Dicen que la criatura marina causa\nlos remolinos que rodean las\lislas.\pQuizá necesites un movimiento\nespecial para superarlos.$"
