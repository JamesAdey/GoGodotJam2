#include "BuildTurbineAction.h"

using namespace godot;

BuildTurbineAction::BuildTurbineAction(Vector2 worldPos)
{
    worldBuildPosition = worldPos;
}
BuildTurbineAction::~BuildTurbineAction()
{
}
float BuildTurbineAction::Evaluate(AIBlackboard *blackboard)
{
    return 1;
}
void BuildTurbineAction::Execute(PlayerInput *inputs)
{
    inputs->BuildTurbineHelper(worldBuildPosition);
}