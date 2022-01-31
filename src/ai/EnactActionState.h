#ifndef AI_ENACTACTIONSSTATE_H
#define AI_ENACTACTIONSSTATE_H

#include <Godot.hpp>
#include "AIState.h"

namespace godot
{

    class EnactActionState : public AIState
    {
    public:
        EnactActionState();
        ~EnactActionState();
        virtual bool IsComplete();
        virtual void ProcessAction(BotInput *inputs,std::unique_ptr<AIBlackboard> &blackboard);
        virtual const char *GetName() { return "EnactActionState"; }
    };

}

#endif