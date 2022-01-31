#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <Godot.hpp>
#include <Node.hpp>
#include "Player.h"

namespace godot
{
    class PlayerInput : public Node
    {
        GODOT_CLASS(PlayerInput, Node)
    public:
        static void _register_methods();
        PlayerInput();
        ~PlayerInput();

        void _init(); // our initializer called by Godot

        void AssignPlayer(Player *player);
        Player *GetPlayerPtr() { return playerPtr; }

        void UpdateWorldInfo(TileMap *tiles);

        virtual void OnStartPlayPhase(){};

        void BuildCoalMineHelper(Vector2 buildPosition);
        void BuildTurbineHelper(Vector2 buildPosition);
        void BuildPylonHelper(Vector2 buildPosition);

        TileMap *GetTileMap()
        {
            return tilemap;
        }

    protected:
        void EndTurn();

        Player *playerPtr;
        TileMap *tilemap;
    };

}

#endif