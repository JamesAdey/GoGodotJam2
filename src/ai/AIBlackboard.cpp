#include "AIBlackboard.h"

using namespace godot;

AIBlackboard::AIBlackboard()
{
}
AIBlackboard::~AIBlackboard()
{
    
    Wipe();
}

void AIBlackboard::Wipe(){
    Godot::print("Wiping blackboard...");

    actions.clear();

}