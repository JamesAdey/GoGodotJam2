#include "PylonData.h"

#include <ResourceLoader.hpp>
#include "GameData.h"
using namespace godot;

void PylonData::_register_methods()
{
}

void PylonData::_init()
{
    energyCost = 3;
    texture = ResourceLoader::get_singleton()->load("res://gfx/buildings/pylon_ghost.png");
    packedScene = ResourceLoader::get_singleton()->load("res://buildings/Pylon.tscn");
    size = Vector2(2,2);
}

bool PylonData::CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition)
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

int32_t PylonData::CalcIncome(TileMap *tilemap, Vector2 mapPosition)
{
    return 0;
}