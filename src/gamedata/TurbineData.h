#ifndef TURBINEDATA_H
#define TURBINEDATA_H

#include <Godot.hpp>
#include "BuildingData.h"

namespace godot
{

    class TurbineData : public BuildingData
    {
        GODOT_CLASS(TurbineData, BuildingData)

    public:
        static void _register_methods();
        TurbineData(){};
        ~TurbineData(){};
        void _init(); // our initializer called by Godot

        virtual bool CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition);
        virtual int32_t CalcIncome(TileMap *tilemap, Vector2 position);
    };

}

#endif