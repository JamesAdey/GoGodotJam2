#ifndef COALMINE_H
#define COALMINE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "Building.h"

namespace godot
{

    class CoalMine : public Building
    {
        GODOT_CLASS(CoalMine, godot::Building)

    public:
        static void _register_methods();
        CoalMine(){};
        ~CoalMine(){};
        void _init(); // our initializer called by Godot

        void OnGainIncome();

        virtual void AddToPlayer(Player *player) override;
        virtual void ParseEnvironment(TileMap *tilemap) override;
        virtual void ClearFootprint(TileMap *tilemap) override;
        virtual void PayBuildCost(Player *player) override;

        int32_t coalIncome;
    };

}

#endif