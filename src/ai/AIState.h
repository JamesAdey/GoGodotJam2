#ifndef AI_STATE_H
#define AI_STATE_H

#include <Godot.hpp>
#include "AIBlackboard.h"
#include <vector>
#include <memory>



namespace godot
{

    class BotInput;

    class AIState
    {
    public:
        AIState();
        virtual ~AIState(); // virtual because deleting derived class via base ptr
        virtual bool IsComplete() = 0;
        virtual void ProcessAction(BotInput *inputs, std::unique_ptr<AIBlackboard> &blackboard) = 0;
        virtual const char* GetName() = 0;

    protected:
        bool isComplete;
    };

}

#endif