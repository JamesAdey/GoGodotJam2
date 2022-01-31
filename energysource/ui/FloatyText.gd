extends HBoxContainer

class_name FloatyText

# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var isFloating = false
var endTick :int = 0


func BeginFloating(texture : Texture, amount : float, delayMsec : int):
	if(delayMsec > 0):
		visible = false
		yield(get_tree().create_timer(delayMsec/1000.0),"timeout")
		visible = true
	isFloating = true
	endTick = OS.get_ticks_msec() + 1500
	var label : Label = get_node("Label")
	var img : TextureRect = get_node("TextureRect")
	var prefix : String = ""
	if(amount < 0):
		label.modulate = Color(1,0.5,0.5,1)
	else:
		label.modulate = Color(0.5,1,0.5,1)
		prefix = "+"
	label.text = prefix + str(amount)
	img.texture = texture
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(!isFloating):
		return
	
	if(OS.get_ticks_msec() > endTick):
		queue_free()
	rect_global_position += (delta * Vector2.UP * 30)
	pass
