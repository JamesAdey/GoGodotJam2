#include "BotInput.h"

#include <OS.hpp>

#include "ai/EnactActionState.h"
#include "ai/ChooseActionState.h"
#include "ai/InstanceActionState.h"

#include "ai/actions/BuildCoalMineActionFactory.h"
#include "ai/actions/BuildTurbineActionFactory.h"
#include "ai/actions/BuildPylonActionFactory.h"

using namespace godot;

void BotInput::_register_methods()
{
    register_method("_process", &BotInput::_process);
}

BotInput::BotInput()
{
}

BotInput::~BotInput()
{
}

void BotInput::_process(float delta)
{
    if (!isTurn)
    {
        return;
    }

    if (turnStack.empty())
    {
        isTurn = false;
        blackboard->Wipe();
        EndTurn();
    }
    else{
        // read current action
        auto currentAction = turnStack.back();
        // check for completion
        if(currentAction->IsComplete()){
            turnStack.pop_back();
            delete currentAction;   // delete once done
        }
        else{
            // execute action otherwise
            //Godot::print("processing...");
            //Godot::print(currentAction->GetName());
            currentAction->ProcessAction(this,blackboard);
        }
    }
}

void BotInput::_init()
{
    isTurn = false;
    blackboard = std::make_unique<AIBlackboard>();
    // fill factory
    auto buildCoalMine = std::make_unique<BuildCoalMineActionFactory>();
    actionFactories.push_back(std::move(buildCoalMine));
    auto buildTurbine = std::make_unique<BuildTurbineActionFactory>();
    actionFactories.push_back(std::move(buildTurbine));
    auto buildPylon = std::make_unique<BuildPylonActionFactory>();
    actionFactories.push_back(std::move(buildPylon));
}

void BotInput::OnStartPlayPhase()
{
    Godot::print("bot beginning turn");
    // update blackboard
    blackboard->tilemap = tilemap;
    blackboard->coalAmount = playerPtr->coalAmount;
    blackboard->energyAmount = playerPtr->energyAmount;
    blackboard->moneyAmount = playerPtr->moneyAmount;
    // fill state machine stack
    isTurn = true;
    auto enactActions = new EnactActionState();
    turnStack.push_back(enactActions);
    auto chooseActions = new ChooseActionState();
    turnStack.push_back(chooseActions);
    auto instanceActions = new InstanceActionState();
    turnStack.push_back(instanceActions);
}