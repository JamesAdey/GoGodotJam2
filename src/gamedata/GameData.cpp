#include "GameData.h"
#include <ResourceLoader.hpp>
using namespace godot;

GameData *GameData::_singleton = nullptr;

void GameData::_register_methods()
{
}

GameData::GameData()
{
}
GameData::~GameData()
{
}
void GameData::_init()
{
    _singleton = this;
    coalMineData.instance();
    turbineData.instance();
    pylonData.instance();
    coalTexture = ResourceLoader::get_singleton()->load("res://gfx/tiles/coal.png");
    energyTexture = ResourceLoader::get_singleton()->load("res://gfx/energy.png");
    moneyTexture = ResourceLoader::get_singleton()->load("res://gfx/money.png");
}