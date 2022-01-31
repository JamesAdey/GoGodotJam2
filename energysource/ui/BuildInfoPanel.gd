extends PanelContainer

export var buttonPath : NodePath

var button : BaseButton
func _ready():
	button = get_node(buttonPath)

func _process(delta):
	visible = button.is_hovered()
