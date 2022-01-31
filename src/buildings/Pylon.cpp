#include "Pylon.h"
#include "../gamedata/GameData.h"

using namespace godot;

void Pylon::_register_methods()
{
    register_method("OnPayCost",&Pylon::OnPayCost);
}

void Pylon::_init()
{
}

void Pylon::AddToPlayer(Player *player)
{
    player->connect(Player::SIGNAL_STEP_PAY_COST, this,"OnPayCost");
    owningPlayerPtr = player;
    set_self_modulate(player->colour);
}

void Pylon::ParseEnvironment(TileMap *tilemap)
{

}

void Pylon::ClearFootprint(TileMap *tilemap)
{
    auto data = GameData::GetSingleton()->pylonData;
    auto localPos = tilemap->to_local(get_global_position());
    auto mapPos = tilemap->world_to_map(localPos);
    data->ClearFootprint(tilemap, mapPos);
}

void Pylon::PayBuildCost(Player *player)
{
    auto data = GameData::GetSingleton()->pylonData;
    player->energyAmount -= data->energyCost; // reduce money

    auto gc = get_node("/root/GameController");
    auto energyTexture = GameData::GetSingleton()->energyTexture;
    gc->call("SpawnFloatyText", get_global_position(), energyTexture, (float)-data->energyCost, 0); // remove money
}

void Pylon::OnPayCost()
{
    if(owningPlayerPtr->energyAmount >= 2){
        owningPlayerPtr->energyAmount -=2;
        owningPlayerPtr->moneyAmount +=6;
        auto globals = get_node("/root/GameController");
        
        auto energyTexture = GameData::GetSingleton()->energyTexture;
        auto moneyTexture = GameData::GetSingleton()->moneyTexture;
        globals->call("SpawnFloatyText",get_global_position(),energyTexture,-2.0f,0);    // remove coal
        globals->call("SpawnFloatyText",get_global_position(),moneyTexture,6.0f,1000);    // add energy
    }
}