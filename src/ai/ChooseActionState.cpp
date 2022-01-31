#include "ChooseActionState.h"

#include "../BotInput.h"

using namespace godot;

ChooseActionState::ChooseActionState()
{
}
ChooseActionState::~ChooseActionState()
{
}
bool ChooseActionState::IsComplete()
{
    return isComplete;
}
void ChooseActionState::ProcessAction(BotInput *inputs,std::unique_ptr<AIBlackboard> &blackboard)
{
    if(blackboard->actions.size() == 0){
        isComplete = true;
        return;
    }
    auto numActions = blackboard->actions.size();
    auto actionNum = rand() % numActions;
    
    blackboard->actions[actionNum]->Execute(inputs);
    isComplete = true;
}