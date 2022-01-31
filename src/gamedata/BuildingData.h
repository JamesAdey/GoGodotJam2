#ifndef BUILDINGDATA_H
#define BUILDINGDATA_H

#include <Godot.hpp>
#include <Texture.hpp>
#include <PackedScene.hpp>
#include <Vector2.hpp>
#include <TileMap.hpp>

namespace godot
{

    class BuildingData : public Reference
    {
        GODOT_CLASS(BuildingData, Reference)

    public:
        static void _register_methods();
        BuildingData();
        ~BuildingData();
        void _init(); // our initializer called by Godot

        Ref<Texture> texture;
        Ref<PackedScene> packedScene;
        int32_t energyCost;
        int32_t moneyCost;
        int32_t coalCost;
        Vector2 size;

        bool CanAfford(int32_t coalAmount, int32_t energyAmount, int32_t moneyAmount);
        virtual bool CanPlaceInTile(TileMap *tilemap,Vector2 position) { return true;}
        void ClearFootprint(TileMap *tilemap, Vector2 mapPosition);
    };

}

#endif