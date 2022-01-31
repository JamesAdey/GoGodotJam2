#ifndef BOTINPUT_H
#define BOTINPUT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include "PlayerInput.h"
#include "Player.h"

#include "ai/AIState.h"
#include "ai/AIBlackboard.h"
#include "ai/actions/AIActionFactory.h"
#include <vector>
#include <memory>

namespace godot
{

    enum BotState
    {
        Thinking,
        InstanceActions,
        ChooseActions,
        EnactActions
    };

    class BotInput : public PlayerInput
    {
        GODOT_CLASS(BotInput, PlayerInput)
    public:
        static void _register_methods();
        BotInput();
        ~BotInput();

        void _init(); // our initializer called by Godot

        void _process(float delta);

        virtual void OnStartPlayPhase() override;

        const std::vector<std::unique_ptr<AIActionFactory>> &GetActionFactories()
        {
            return actionFactories;
        }

    protected:
        bool isTurn;

        // ai thinking variables
        std::vector<AIState *> turnStack;
        std::unique_ptr<AIBlackboard> blackboard;
        std::vector<std::unique_ptr<AIActionFactory>> actionFactories;
    };

}

#endif