#include "CoalMine.h"
#include "../gamedata/GameData.h"

using namespace godot;

void CoalMine::_register_methods()
{
    register_method("OnGainIncome", &CoalMine::OnGainIncome);
}

void CoalMine::_init()
{
    coalIncome = 0;
}

void CoalMine::AddToPlayer(Player *player)
{
    player->connect(Player::SIGNAL_STEP_GAIN_INCOME, this, "OnGainIncome");
    owningPlayerPtr = player;
    set_self_modulate(player->colour);
}

void CoalMine::ParseEnvironment(TileMap *tilemap)
{
    auto data = GameData::GetSingleton()->coalMineData;
    auto localPos = tilemap->to_local(get_global_position());
    auto mapPos = tilemap->world_to_map(localPos);
    coalIncome = data->CalcIncome(tilemap, mapPos);
    //Godot::print(String::num_int64(coalIncome));
}

void CoalMine::ClearFootprint(TileMap *tilemap)
{
    auto data = GameData::GetSingleton()->coalMineData;
    auto localPos = tilemap->to_local(get_global_position());
    auto mapPos = tilemap->world_to_map(localPos);
    data->ClearFootprint(tilemap, mapPos);
}

void CoalMine::PayBuildCost(Player *player)
{
    auto data = GameData::GetSingleton()->coalMineData;
    player->moneyAmount -= data->moneyCost; // reduce money

    auto gc = get_node("/root/GameController");
    auto moneyTexture = GameData::GetSingleton()->moneyTexture;
    gc->call("SpawnFloatyText", get_global_position(), moneyTexture, (float)-data->moneyCost, 0); // remove money
}

void CoalMine::OnGainIncome()
{
    owningPlayerPtr->coalAmount += coalIncome;
    auto gc = get_node("/root/GameController");
    auto coalTexture = GameData::GetSingleton()->coalTexture;
    gc->call("SpawnFloatyText", get_global_position(), coalTexture, (float)coalIncome, 0); // remove coal
}

