#ifndef BUILDING_H
#define BUILDING_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <TileMap.hpp>
#include "../Player.h"

namespace godot
{

    class Building : public Sprite
    {
        GODOT_CLASS(Building, Sprite)

    public:
        static void _register_methods();
        Building();
        ~Building();
        void _init(); // our initializer called by Godot

        virtual void AddToPlayer(Player *player) {};  // not allowed pure virtual methods in gdnative :(
        virtual void ParseEnvironment(TileMap *tilemap) {};
        virtual void ClearFootprint(TileMap *tilemap){};
        virtual void PayBuildCost(Player *player){};

    protected:
        Player *owningPlayerPtr;
    };

}

#endif