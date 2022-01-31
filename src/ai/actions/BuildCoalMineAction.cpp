#include "BuildCoalMineAction.h"

using namespace godot;

BuildCoalMineAction::BuildCoalMineAction(Vector2 worldPos)
{
    worldBuildPosition = worldPos;
}
BuildCoalMineAction::~BuildCoalMineAction()
{
}
float BuildCoalMineAction::Evaluate(AIBlackboard *blackboard)
{
    return 1;
}
void BuildCoalMineAction::Execute(PlayerInput *inputs)
{
    inputs->BuildCoalMineHelper(worldBuildPosition);
}