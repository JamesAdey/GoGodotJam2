extends PanelContainer

class_name ScoreLabel

var label : Label

export var colour : Color

# Called when the node enters the scene tree for the first time.
func _ready():
	label = get_node("HBox/Label")
	self_modulate = colour
	pass # Replace with function body.


func UpdateScore(name : String, score : float):
	var txt = name + " : "+str(score)
	label.text = txt
	pass
