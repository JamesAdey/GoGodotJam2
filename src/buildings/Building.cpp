#include "Building.h"

using namespace godot;

void Building::_register_methods()
{
    register_method("AddToPlayer", &Building::AddToPlayer);
    //register_method("ParseEnvironment",&Building::ParseEnvironment);
}

Building::Building()
{
}

Building::~Building()
{
}

void Building::_init()
{
}