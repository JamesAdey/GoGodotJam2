#ifndef TURBINE_H
#define TURBINE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "Building.h"

namespace godot
{

    class Turbine : public Building
    {
        GODOT_CLASS(Turbine, godot::Building)

    public:
        static void _register_methods();
        Turbine(){};
        ~Turbine(){};
        void _init(); // our initializer called by Godot

        void OnRunProduction();

        virtual void AddToPlayer(Player *player) override;
        virtual void ParseEnvironment(TileMap *tilemap) override;
        virtual void ClearFootprint(TileMap *tilemap) override;
        virtual void PayBuildCost(Player *player) override;
    };

}

#endif