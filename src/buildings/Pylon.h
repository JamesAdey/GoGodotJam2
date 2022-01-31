#ifndef PYLON_H
#define PYLON_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include "Building.h"

namespace godot
{

    class Pylon : public Building
    {
        GODOT_CLASS(Pylon, godot::Building)

    public:
        static void _register_methods();
        Pylon(){};
        ~Pylon(){};
        void _init(); // our initializer called by Godot

        void OnPayCost();

        virtual void AddToPlayer(Player *player) override;
        virtual void ParseEnvironment(TileMap *tilemap) override;
        virtual void ClearFootprint(TileMap *tilemap) override;
        virtual void PayBuildCost(Player *player) override;
    };

}

#endif