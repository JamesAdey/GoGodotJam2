extends PanelContainer
class_name VictoryPanel

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var MENU_SCENE : PackedScene = load("res://levels/MainMenu.tscn") 
var label : Label

# Called when the node enters the scene tree for the first time.
func _ready():
	label = get_node("CenterContainer/VBoxContainer/Label")
	pass # Replace with function body.

func DisplayWinner(winner : String):
	label.text = winner + " wins!"

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass


func _on_MainMenuButton_pressed():
	get_tree().change_scene_to(MENU_SCENE)
	pass # Replace with function body.
