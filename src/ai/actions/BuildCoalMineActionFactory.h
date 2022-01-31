#ifndef AI_BUILDCOALMINE_ACTIONFACTORY_H
#define AI_BUILDCOALMINE_ACTIONFACTORY_H

#include <Godot.hpp>
#include "AIActionFactory.h"

#include <vector>
#include <memory>

namespace godot
{

    class BuildCoalMineActionFactory : public AIActionFactory
    {
    public:
        BuildCoalMineActionFactory();
        virtual ~BuildCoalMineActionFactory(); // virtual because deleting derived class via base ptr
        virtual void FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard) override;
    };

}

#endif