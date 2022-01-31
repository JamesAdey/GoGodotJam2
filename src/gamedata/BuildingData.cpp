#include "BuildingData.h"
#include "GameData.h"

using namespace godot;

void BuildingData::_register_methods()
{
    register_method("CanPlaceInTile", &BuildingData::CanPlaceInTile);
    register_method("CanAfford", &BuildingData::CanAfford);

    register_property("energyCost", &BuildingData::energyCost, 10);
    register_property("texture", &BuildingData::texture, Ref<Texture>());
    register_property("packedScene", &BuildingData::packedScene, Ref<PackedScene>());
    register_property("size", &BuildingData::size, Vector2::ZERO);
}

BuildingData::BuildingData()
{
    coalCost = 0;
    energyCost = 0;
    moneyCost = 0;
}

BuildingData::~BuildingData()
{
}

void BuildingData::_init()
{
    
}

bool BuildingData::CanAfford(int32_t coalAmount, int32_t energyAmount, int32_t moneyAmount)
{
    if (coalAmount < coalCost)
    {
        return false;
    }
    if (energyAmount < energyCost)
    {
        return false;
    }
    if (moneyAmount < moneyCost)
    {
        return false;
    }
    return true;
}

void BuildingData::ClearFootprint(TileMap *tilemap, Vector2 mapPosition)
{
    auto startX = (int)mapPosition.x;
    auto startY = (int)mapPosition.y;
    auto endX = (int)(mapPosition.x + size.x);
    auto endY = (int)(mapPosition.y + size.y);

    for (int x = startX; x < endX; x++)
    {
        for (int y = startY; y < endY; y++)
        {
            tilemap->set_cell(x, y, GameData::INVALID_TILE_NUM);
        }
    }
}