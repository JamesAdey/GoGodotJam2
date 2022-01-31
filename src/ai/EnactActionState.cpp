#include "EnactActionState.h"

using namespace godot;

EnactActionState::EnactActionState()
{
}
EnactActionState::~EnactActionState()
{
}
bool EnactActionState::IsComplete()
{
    return isComplete;
}
void EnactActionState::ProcessAction(BotInput *inputs,std::unique_ptr<AIBlackboard> &blackboard)
{
    isComplete = true;
}