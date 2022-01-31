tool
extends PanelContainer
class_name ResourcePanel

export var img : Texture

var label : Label
var textureRect : TextureRect

# Called when the node enters the scene tree for the first time.
func _ready():
	label = get_node("HBox/Label")
	textureRect = get_node("HBox/TextureRect")
	SetImg(img)
	pass # Replace with function body.

func SetAmount (amount : int):
	label.text = str(amount)

func SetImg(texture : Texture):
	textureRect.texture = texture
