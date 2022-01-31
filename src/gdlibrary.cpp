#include "Player.h"

// input generators
#include "HumanInput.h"
#include "BotInput.h"

// data folders
#include "gamedata/GameData.h"
#include "gamedata/CoalMineData.h"
#include "gamedata/TurbineData.h"
#include "gamedata/PylonData.h"
#include "buildings/CoalMine.h"
#include "buildings/Turbine.h"
#include "buildings/Pylon.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::GameData>();
    godot::register_class<godot::Player>();

    // input + ai
    godot::register_class<godot::PlayerInput>();
    godot::register_class<godot::HumanInput>();
    godot::register_class<godot::BotInput>();

    // buildings
    godot::register_class<godot::Building>();
    godot::register_class<godot::CoalMine>();
    godot::register_class<godot::Turbine>();
    godot::register_class<godot::Pylon>();

    // building data
    godot::register_class<godot::BuildingData>();
    godot::register_class<godot::CoalMineData>();
    godot::register_class<godot::TurbineData>();
    godot::register_class<godot::PylonData>();

}
