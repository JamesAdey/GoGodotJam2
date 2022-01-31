#include "InstanceActionState.h"

#include "../BotInput.h"

using namespace godot;

InstanceActionState::InstanceActionState()
{
}
InstanceActionState::~InstanceActionState()
{
}
bool InstanceActionState::IsComplete()
{
    return isComplete;
}
void InstanceActionState::ProcessAction(BotInput *inputs, std::unique_ptr<AIBlackboard> &blackboard)
{
    auto &actionFactories = inputs->GetActionFactories();
    // iterate over all actions available
    for (int i = 0; i < actionFactories.size(); i++)
    {
        actionFactories[i]->FillInstancedActions(blackboard);
    }

    isComplete = true;
}