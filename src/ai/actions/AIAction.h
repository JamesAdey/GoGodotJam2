#ifndef AI_ACTION_H
#define AI_ACTION_H

#include <Godot.hpp>
#include "../../PlayerInput.h"
//#include "../AIBlackboard.h"

#include <vector>
#include <memory>

namespace godot
{

    class AIBlackboard;

    class AIAction
    {
    public:
        AIAction() {}
        virtual ~AIAction(){} // virtual because deleting derived class via base ptr
        virtual float Evaluate(AIBlackboard *blackboard) = 0;
        virtual void Execute(PlayerInput *inputs) = 0;
        virtual const char *GetName() = 0;
    };

}

#endif