#include "CoalMineData.h"

#include <ResourceLoader.hpp>
#include "GameData.h"
using namespace godot;

void CoalMineData::_register_methods()
{
    register_method("CalcIncome", &CoalMineData::CalcIncome);
}

void CoalMineData::_init()
{
    moneyCost = 5;
    texture = ResourceLoader::get_singleton()->load("res://gfx/buildings/coalmine_ghost.png");
    packedScene = ResourceLoader::get_singleton()->load("res://buildings/CoalMine.tscn");
    size = Vector2(2, 2);
}



bool CoalMineData::CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition)
{
    auto startX = (int)mapPosition.x;
    auto startY = (int)mapPosition.y;

    auto endX = (int)(mapPosition.x + size.x);
    auto endY = (int)(mapPosition.y + size.y);

    bool hasCoal = false;
    for (int x = startX; x < endX; x++)
    {
        for (int y = startY; y < endY; y++)
        {
            auto val = tilemap->get_cell(x, y);
            if (val == GameData::OCCUPIED_TILE_NUM || val == GameData::INVALID_TILE_NUM)
            {
                return false; // immediately false if tile is invalid
            }
            // remember if have coal
            hasCoal |= val == GameData::COAL_TILE_NUM;
        }
    }
    return hasCoal;
}

int32_t CoalMineData::CalcIncome(TileMap *tilemap, Vector2 mapPosition)
{
    auto startX = (int)mapPosition.x;
    auto startY = (int)mapPosition.y;
    auto endX = (int)(mapPosition.x + size.x);
    auto endY = (int)(mapPosition.y + size.y);

    int32_t coal = 0;
    for (int x = startX; x < endX; x++)
    {
        for (int y = startY; y < endY; y++)
        {
            auto val = tilemap->get_cell(x, y);
            // remember if have coal
            if (val == GameData::COAL_TILE_NUM)
            {
                coal += 1;
            }
        }
    }
    return coal;
}