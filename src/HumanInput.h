#ifndef HUMANINPUT_H
#define HUMANINPUT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include "PlayerInput.h"
#include "Player.h"

namespace godot
{
    class HumanInput : public PlayerInput
    {
        GODOT_CLASS(HumanInput, PlayerInput)
    public:
        static void _register_methods();
        HumanInput();
        ~HumanInput();

        void _init(); // our initializer called by Godot

        void BuildCoalMineAction(Vector2 pos);
        void BuildTurbineAction(Vector2 pos);
        void BuildPylonAction(Vector2 pos);
        void EndTurnAction();

        virtual void OnStartPlayPhase() override;

        
    };

}

#endif