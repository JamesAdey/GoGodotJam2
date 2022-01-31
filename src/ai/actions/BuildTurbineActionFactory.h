#ifndef AI_BUILDTURBINE_ACTIONFACTORY_H
#define AI_BUILDTURBINE_ACTIONFACTORY_H

#include <Godot.hpp>
#include "AIActionFactory.h"

#include <vector>
#include <memory>

namespace godot
{

    class BuildTurbineActionFactory : public AIActionFactory
    {
    public:
        BuildTurbineActionFactory();
        virtual ~BuildTurbineActionFactory(); // virtual because deleting derived class via base ptr
        virtual void FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard) override;
    };

}

#endif