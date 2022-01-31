extends CanvasLayer
class_name GameController

signal UpdatePlayerUI




var players : Array = []
var currentPlayerNum : int = -1
var playerInputMapping : Dictionary
var scoreLabelMapping : Dictionary

const PLAYER_SCENE = preload("res://Player.tscn")

var playerUI : CanvasLayer
var victoryPanel
var nextTurnAnim : NextTurnAnim

const FLOATY_TEXT_SCENE : PackedScene = preload("res://ui/FloatyText.tscn")
# Called when the node enters the scene tree for the first time.
func _ready():
	var tilemap = get_node("TileMap")
	
	
	var humanInput = get_node("HumanInput")
	var hum : Player = create_player("Player 1",Color(0,0.5,1,1))
	Globals.localPlayerNumber = 0
	humanInput.AssignPlayer(hum)
	humanInput.UpdateWorldInfo(tilemap)
	playerInputMapping[hum] = humanInput
	scoreLabelMapping[hum] = get_node("PlayerUI/ObjectiveContainer/VBoxContainer/P1Score")
	
	var botInput = get_node("BotInput")
	var bot : Player = create_player("Player 2",Color(1,0,0,1))
	botInput.AssignPlayer(bot)
	botInput.UpdateWorldInfo(tilemap)
	playerInputMapping[bot] = botInput
	scoreLabelMapping[bot] = get_node("PlayerUI/ObjectiveContainer/VBoxContainer/P2Score")
	
	UpdateScoreForPlayer(hum)
	UpdateScoreForPlayer(bot)
	
	victoryPanel = get_node("PlayerUI/VictoryPanel")
	victoryPanel.visible = false
	
	nextTurnAnim = get_node("PlayerUI/TurnSwipe/NextTurnAnim")
	
	playerUI = get_node("PlayerUI")
	
	call_deferred("start_game")
	pass # Replace with function body.

func create_player(name: String, colour : Color):
	var p = PLAYER_SCENE.instance()
	p.name = name
	p.colour = colour
	add_child(p)
	register_new_player(p)
	return p

func register_new_player(player : Player):
	players.append(player)

func start_game():
	currentPlayerNum = -1
	next_turn()

func end_game():
	# current player is winning player?
	var winningPlayer = players[currentPlayerNum]
	victoryPanel.DisplayWinner(winningPlayer.name)
	victoryPanel.visible = true


func next_turn():
	currentPlayerNum +=1
	currentPlayerNum = currentPlayerNum % len(players)
	var player = players[currentPlayerNum]
	# hackyhack don't hardcode this!
	toggle_ui(false)
		# do anim & wait
	nextTurnAnim.SetPlayerName(player.name)
	nextTurnAnim.play("new_turn_anim")
	yield(nextTurnAnim,"animation_finished")
	toggle_ui(currentPlayerNum == 0)
	start_turn_for_player(player)

func toggle_ui(toggle : bool):
	for child in playerUI.get_children():
		if(child is MarginContainer):
			child.visible = toggle

func start_turn_for_player(player):
	
	player.gain_income_phase()
	player.pay_cost_phase()
	
	print("starting turn for "+player.name)
	emit_signal("UpdatePlayerUI",player)
	UpdateScoreForPlayer(player)
	if(CheckWinner(player)):
		end_game()
	else:
		player.begin_play_phase()
	
func end_turn_for_player(player):
	# ignore unless current player
	if(player != players[currentPlayerNum]):
		return
	
	player.run_production_phase()
	FullUIUpdate(player)
	if(CheckWinner(player)):
		end_game()
	else:
		next_turn()
	

func CheckWinner(player : Player):
	if(player.moneyAmount >= 100):
		return true
	return false

func SpawnFloatyText(pos: Vector2, texture : Texture, amount : float, delayMsec : int):
	var f: FloatyText = FLOATY_TEXT_SCENE.instance()
	add_child(f)
	f.set_global_position(pos)
	f.BeginFloating(texture,amount, delayMsec)

func FullUIUpdate(player : Player):
	emit_signal("UpdatePlayerUI",player)
	UpdateScoreForPlayer(player)

func UpdateScoreForPlayer(player : Player):
	var scoreLabel : ScoreLabel = scoreLabelMapping[player]
	scoreLabel.UpdateScore(player.name,player.moneyAmount)

