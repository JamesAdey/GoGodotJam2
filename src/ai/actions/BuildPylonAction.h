#ifndef AI_BUILDPYLON_ACTION_H
#define AI_BUILDPYLON_ACTION_H

#include <Godot.hpp>
#include "AIAction.h"

namespace godot
{
    

    class BuildPylonAction : public AIAction
    {
    public:
        BuildPylonAction(Vector2 pos);
        ~BuildPylonAction(); // virtual because deleting derived class via base ptr
        virtual float Evaluate(AIBlackboard *blackboard) override;
        virtual void Execute(PlayerInput *inputs) override;
        virtual const char *GetName() override { return "Build pylon"; }

    protected:
        Vector2 worldBuildPosition;
    };

}

#endif