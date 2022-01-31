#include "HumanInput.h"
using namespace godot;

void HumanInput::_register_methods()
{
    register_method("BuildCoalMineAction",&HumanInput::BuildCoalMineAction);
    register_method("BuildTurbineAction",&HumanInput::BuildTurbineAction);
    register_method("BuildPylonAction",&HumanInput::BuildPylonAction);
    register_method("EndTurnAction",&HumanInput::EndTurnAction);
}

HumanInput::HumanInput()
{
}

HumanInput::~HumanInput()
{
}

void HumanInput::_init()
{
}

void HumanInput::OnStartPlayPhase(){
    Godot::print("human starting play!");
}

void HumanInput::BuildCoalMineAction(Vector2 pos){
    Godot::print("BUILDING COAL MINE");
    BuildCoalMineHelper(pos);
}

void HumanInput::BuildTurbineAction(Vector2 pos){
    Godot::print("BUILDING TURBINE");
    BuildTurbineHelper(pos);
}

void HumanInput::BuildPylonAction(Vector2 pos){
    Godot::print("BUILDING PYLON");
    BuildPylonHelper(pos);
}

void HumanInput::EndTurnAction(){
    EndTurn();
}