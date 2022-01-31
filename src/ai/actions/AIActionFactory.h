#ifndef AI_ACTIONFACTORY_H
#define AI_ACTIONFACTORY_H

#include <Godot.hpp>
#include <TileMap.hpp>
#include "AIAction.h"

#include <vector>
#include <memory>

namespace godot
{

    class AIActionFactory
    {
    public:
        AIActionFactory(){}
        virtual ~AIActionFactory(){} // virtual because deleting derived class via base ptr
        virtual void FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard) = 0;
    };

}

#endif