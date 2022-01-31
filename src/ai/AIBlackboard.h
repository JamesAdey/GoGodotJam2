#ifndef AI_BLACKBOARD_H
#define AI_BLACKBOARD_H

#include <Godot.hpp>
#include <TileMap.hpp>
#include "actions/AIAction.h"

#include <vector>
#include <memory>

namespace godot
{
    class AIAction;

    class AIBlackboard
    {
    public:
        AIBlackboard();
        ~AIBlackboard();

        void Wipe();

        
        std::vector<std::unique_ptr<AIAction>> actions;
        TileMap *tilemap;
        uint32_t coalAmount;
        uint32_t energyAmount;
        uint32_t moneyAmount;
    };

}

#endif