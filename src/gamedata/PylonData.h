#ifndef PYLONDATA_H
#define PYLONDATA_H

#include <Godot.hpp>
#include "BuildingData.h"

namespace godot
{

    class PylonData : public BuildingData
    {
        GODOT_CLASS(PylonData, BuildingData)

    public:
        static void _register_methods();
        PylonData(){};
        ~PylonData(){};
        void _init(); // our initializer called by Godot

        virtual bool CanPlaceInTile(TileMap *tilemap, Vector2 mapPosition);
        virtual int32_t CalcIncome(TileMap *tilemap, Vector2 position);
    };

}

#endif