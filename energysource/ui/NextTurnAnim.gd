extends AnimationPlayer

class_name NextTurnAnim

# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var label : Label

# Called when the node enters the scene tree for the first time.
func _ready():
	label = get_node("../Label")
	pass # Replace with function body.

func SetPlayerName(name : String):
	label.text = name + "'s Turn"
# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
