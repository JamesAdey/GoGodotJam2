extends CanvasLayer

const PYLON_DESC : String = "Pylon:\n Converts 2 energy to 6 money!"
const TURBINE_DESC : String = "Turbine:\n Converts 3 coal to 1 energy."
const COALMINE_DESC : String = "Coal Mine:\n Extracts 1 to 4 coal based on the number of coal tiles it is placed over. The more coal tiles, the higher the output!"

# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var tilemap : TileMap


var inputs

var buildAction : FuncRef

var ghostSprite : Sprite
var ghostData


var coalDisplay : ResourcePanel
var energyDisplay : ResourcePanel
var moneyDisplay : ResourcePanel

var buildInfoBox : Label



# Called when the node enters the scene tree for the first time.
func _ready():
	inputs = get_node("../HumanInput")
	ghostSprite = get_node("../GhostSprite")
	tilemap = get_node("../TileMap")
	# ui panels
	buildInfoBox = get_node("BuildMenu/InfoBox")
	coalDisplay = get_node("ResourceContainer/HBoxContainer/CoalPanel")
	energyDisplay = get_node("ResourceContainer/HBoxContainer/EnergyPanel")
	moneyDisplay = get_node("ResourceContainer/HBoxContainer/MoneyPanel")
	var gc : GameController = get_node("/root/GameController")
	gc.connect("UpdatePlayerUI",self,"UpdateForPlayer")
	print(inputs)
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(buildAction != null):
		
		UpdateBuildingGhost()
	pass

func GetTilemapMousePos():
	var localMousePos = tilemap.get_local_mouse_position()
	return tilemap.world_to_map(localMousePos)
	

func UpdateBuildingGhost():
	ghostSprite.texture = ghostData.texture
	var mapPos = GetTilemapMousePos()

	var worldPos = tilemap.map_to_world(mapPos)
	ghostSprite.position = worldPos
	if(CanPlaceHelper(tilemap,mapPos,inputs.GetPlayerPtr())):
		ghostSprite.modulate = Color(1,1,1,0.75)
	else:
		ghostSprite.modulate = Color(1,0,0,0.75)
	
	pass

func _unhandled_input(event):
	if(event is InputEventMouseButton):
		if(event.button_index == BUTTON_LEFT && !event.is_pressed()):
			FinishAction(event)

func FinishAction(event : InputEventMouseButton):
	if(buildAction != null):
		var result : bool = buildAction.call_func(event)
		if(result):
			buildAction = null
			ghostSprite.texture = null
			buildInfoBox.text = ""


func _on_BuildCoalMineButton_pressed():
	ghostData = Globals.coalMineData
	buildAction = funcref(self,"BuildCoalMine")
	buildInfoBox.text = COALMINE_DESC
	

func _on_BuildTurbineButton_pressed():
	ghostData = Globals.turbineData
	buildAction = funcref(self,"BuildTurbine")
	buildInfoBox.text = TURBINE_DESC

func _on_BuildPylonButton_pressed():
	ghostData = Globals.pylonData
	buildAction = funcref(self,"BuildPylon")
	buildInfoBox.text = PYLON_DESC
	pass # Replace with function body.


func BuildCoalMine(event : InputEventMouseButton):
	var mapPos = GetTilemapMousePos()
	var worldPos = tilemap.map_to_world(mapPos)
	worldPos = tilemap.to_global(worldPos)
	
	if(CanPlaceHelper(tilemap,mapPos,inputs.GetPlayerPtr())):
		inputs.BuildCoalMineAction(worldPos)
		return true
	else:
		return false

func BuildTurbine(event : InputEventMouseButton):
	var mapPos = GetTilemapMousePos()
	var worldPos = tilemap.map_to_world(mapPos)
	worldPos = tilemap.to_global(worldPos)
	
	if(CanPlaceHelper(tilemap,mapPos,inputs.GetPlayerPtr())):
		inputs.BuildTurbineAction(worldPos)
		return true
	else:
		return false

func BuildPylon(event : InputEventMouseButton):
	var mapPos = GetTilemapMousePos()
	var worldPos = tilemap.map_to_world(mapPos)
	worldPos = tilemap.to_global(worldPos)
	
	if(CanPlaceHelper(tilemap,mapPos,inputs.GetPlayerPtr())):
		inputs.BuildPylonAction(worldPos)
		return true
	else:
		return false


func _on_EndTurnButton_pressed():
	inputs.EndTurnAction()
	pass # Replace with function body
	
func UpdateForPlayer(player):
	coalDisplay.SetAmount(player.coalAmount)
	energyDisplay.SetAmount(player.energyAmount)
	moneyDisplay.SetAmount(player.moneyAmount)

func CanPlaceHelper(tilemap : TileMap ,mapPos : Vector2, player : Player):
	var canAfford = ghostData.CanAfford(player.coalAmount,player.energyAmount,player.moneyAmount)
	var canPlace = ghostData.CanPlaceInTile(tilemap,mapPos)
	return (canAfford && canPlace)


