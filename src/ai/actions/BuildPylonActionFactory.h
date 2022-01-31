#ifndef AI_BUILDPYLON_ACTIONFACTORY_H
#define AI_BUILDPYLON_ACTIONFACTORY_H

#include <Godot.hpp>
#include "AIActionFactory.h"

#include <vector>
#include <memory>

namespace godot
{

    class BuildPylonActionFactory : public AIActionFactory
    {
    public:
        BuildPylonActionFactory();
        virtual ~BuildPylonActionFactory(); // virtual because deleting derived class via base ptr
        virtual void FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard) override;
    };

}

#endif