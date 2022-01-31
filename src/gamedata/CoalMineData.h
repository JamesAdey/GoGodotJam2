#ifndef COALMINEDATA_H
#define COALMINEDATA_H

#include <Godot.hpp>
#include "BuildingData.h"

namespace godot
{

    class CoalMineData : public BuildingData
    {
        GODOT_CLASS(CoalMineData, BuildingData)

    public:
        static void _register_methods();
        CoalMineData(){};
        ~CoalMineData(){};
        void _init(); // our initializer called by Godot

        virtual bool CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition) override;
        virtual int32_t CalcIncome(TileMap *tilemap, Vector2 position);
    };

}

#endif