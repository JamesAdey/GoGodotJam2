#ifndef AI_INSTANCEACTIONSTATE_H
#define AI_INSTANCEACTIONSTATE_H

#include <Godot.hpp>
#include "AIState.h"


namespace godot
{

    class InstanceActionState : public AIState
    {
    public:
        InstanceActionState();
        ~InstanceActionState();
        virtual bool IsComplete();
        virtual void ProcessAction(BotInput *inputs, std::unique_ptr<AIBlackboard> &blackboard);
        virtual const char *GetName() { return "InstanceActionState"; }
    };

}

#endif