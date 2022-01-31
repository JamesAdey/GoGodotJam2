#include "BuildPylonAction.h"

using namespace godot;

BuildPylonAction::BuildPylonAction(Vector2 worldPos)
{
    worldBuildPosition = worldPos;
}
BuildPylonAction::~BuildPylonAction()
{
}
float BuildPylonAction::Evaluate(AIBlackboard *blackboard)
{
    return 1;
}
void BuildPylonAction::Execute(PlayerInput *inputs)
{
    inputs->BuildPylonHelper(worldBuildPosition);
}