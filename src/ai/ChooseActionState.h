#ifndef AI_CHOOSEACTIONSTATE_H
#define AI_CHOOSEACTIONSTATE_H

#include <Godot.hpp>
#include "AIState.h"

namespace godot
{

    class ChooseActionState : public AIState
    {
    public:
        ChooseActionState();
        ~ChooseActionState();
        virtual bool IsComplete();
        virtual void ProcessAction(BotInput *inputs,std::unique_ptr<AIBlackboard> &blackboard);
        virtual const char *GetName() { return "ChooseActionState"; }
    };

}

#endif