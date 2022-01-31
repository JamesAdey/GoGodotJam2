#include "Turbine.h"
#include "../gamedata/GameData.h"

using namespace godot;

void Turbine::_register_methods()
{
    register_method("OnRunProduction",&Turbine::OnRunProduction);
}

void Turbine::_init()
{
}

void Turbine::AddToPlayer(Player *player)
{
    player->connect(Player::SIGNAL_STEP_RUN_PRODUCTION, this,"OnRunProduction");
    owningPlayerPtr = player;
    set_self_modulate(player->colour);
}

void Turbine::ParseEnvironment(TileMap *tilemap)
{
}

void Turbine::ClearFootprint(TileMap *tilemap)
{
    auto data = GameData::GetSingleton()->turbineData;
    auto localPos = tilemap->to_local(get_global_position());
    auto mapPos = tilemap->world_to_map(localPos);
    data->ClearFootprint(tilemap, mapPos);
}

void Turbine::PayBuildCost(Player *player)
{
    auto data = GameData::GetSingleton()->turbineData;
    player->coalAmount -= data->coalCost; // reduce money

    auto gc = get_node("/root/GameController");
    auto coalTexture = GameData::GetSingleton()->coalTexture;
    gc->call("SpawnFloatyText", get_global_position(), coalTexture, (float)-data->coalCost, 0); // remove money
}

void Turbine::OnRunProduction()
{
    if(owningPlayerPtr->coalAmount >= 3){
        owningPlayerPtr->coalAmount -=3;
        owningPlayerPtr->energyAmount +=1;
        auto globals = get_node("/root/GameController");
        auto coalTexture = GameData::GetSingleton()->coalTexture;
        auto energyTexture = GameData::GetSingleton()->energyTexture;
        globals->call("SpawnFloatyText",get_global_position(),coalTexture,-3.0f,0);    // remove coal
        globals->call("SpawnFloatyText",get_global_position(),energyTexture,1.0f,1000);    // add energy
    }
}