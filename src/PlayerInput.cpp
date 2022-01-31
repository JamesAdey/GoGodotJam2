#include "PlayerInput.h"
#include "gamedata/GameData.h"

using namespace godot;

void PlayerInput::_register_methods()
{
    register_method("AssignPlayer", &PlayerInput::AssignPlayer);
    register_method("GetPlayerPtr",&PlayerInput::GetPlayerPtr);
    register_method("UpdateWorldInfo",&PlayerInput::UpdateWorldInfo);
    register_method("OnStartPlayPhase", &PlayerInput::OnStartPlayPhase);
}

PlayerInput::PlayerInput()
{
}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::_init()
{
    tilemap = nullptr;
    playerPtr = nullptr;
}

void PlayerInput::AssignPlayer(Player *player)
{
    playerPtr = player;
    player->connect(Player::SIGNAL_STEP_BEGIN_PLAY, this, "OnStartPlayPhase");
    Godot::print("assigned player");
}

void PlayerInput::UpdateWorldInfo(TileMap *tiles){
    tilemap = tiles;
}

void PlayerInput::EndTurn()
{
    Godot::print(get_name());
    Godot::print("ending turn for above player ^");
    auto gc = get_node("/root/GameController");
    gc->call("end_turn_for_player", playerPtr);
}

void PlayerInput::BuildCoalMineHelper(Vector2 buildPosition)
{
    auto data = GameData::GetSingleton()->coalMineData;
    playerPtr->CreateBuilding(data,tilemap, buildPosition);
}

void PlayerInput::BuildTurbineHelper(Vector2 buildPosition)
{
    auto data = GameData::GetSingleton()->turbineData;
    playerPtr->CreateBuilding(data,tilemap, buildPosition);
}

void PlayerInput::BuildPylonHelper(Vector2 buildPosition){
    auto data = GameData::GetSingleton()->pylonData;
    playerPtr->CreateBuilding(data,tilemap, buildPosition);
}