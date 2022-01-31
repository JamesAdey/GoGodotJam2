#include "TurbineData.h"

#include <ResourceLoader.hpp>
#include "GameData.h"
using namespace godot;

void TurbineData::_register_methods()
{
}

void TurbineData::_init()
{
    coalCost = 4;
    texture = ResourceLoader::get_singleton()->load("res://gfx/buildings/turbine_ghost.png");
    packedScene = ResourceLoader::get_singleton()->load("res://buildings/Turbine.tscn");
    size = Vector2(2,2);
}

bool TurbineData::CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition)
{
    auto startX = (int)mapPosition.x;
    auto startY = (int)mapPosition.y;
    
    auto endX = (int)(mapPosition.x + size.x);
    auto endY = (int)(mapPosition.y + size.y);

    for (int x = startX; x < endX; x++)
    {
        for (int y = startY; y < endY; y++)
        {
            auto val = tilemap->get_cell(x,y);
            if(val == GameData::OCCUPIED_TILE_NUM || val == GameData::INVALID_TILE_NUM){
                return false;   // immediately false if tile is invalid
            }
        }
    }
    return true;
}

int32_t TurbineData::CalcIncome(TileMap *tilemap, Vector2 mapPosition)
{
    return 0;
}