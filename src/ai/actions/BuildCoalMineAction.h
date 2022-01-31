#ifndef AI_BUILDCOALMINE_ACTION_H
#define AI_BUILDCOALMINE_ACTION_H

#include <Godot.hpp>
#include "AIAction.h"

namespace godot
{
    

    class BuildCoalMineAction : public AIAction
    {
    public:
        BuildCoalMineAction(Vector2 pos);
        ~BuildCoalMineAction(); // virtual because deleting derived class via base ptr
        virtual float Evaluate(AIBlackboard *blackboard) override;
        virtual void Execute(PlayerInput *inputs) override;
        virtual const char *GetName() override { return "Build coal mine"; }

    protected:
        Vector2 worldBuildPosition;
    };

}

#endif