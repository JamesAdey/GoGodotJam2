#include "Player.h"
#include "buildings/Building.h"
#include "buildings/CoalMine.h"

#include "gamedata/GameData.h"
#include "gamedata/CoalMineData.h"

using namespace godot;

const char *Player::SIGNAL_STEP_GAIN_INCOME = "step_gain_income";
const char *Player::SIGNAL_STEP_PAY_COST = "step_pay_cost";
const char *Player::SIGNAL_STEP_BEGIN_PLAY = "step_begin_play";
const char *Player::SIGNAL_STEP_RUN_PRODUCTION = "step_run_production";

void Player::_register_methods()
{
    register_method("gain_income_phase", &Player::GainIncomePhase);
    register_method("pay_cost_phase", &Player::PayCostPhase);
    register_method("run_production_phase", &Player::RunProductionPhase);
    register_method("begin_play_phase",&Player::BeginPlayPhase);
    // signals
    register_signal<Player>(SIGNAL_STEP_GAIN_INCOME);
    register_signal<Player>(SIGNAL_STEP_PAY_COST);
    register_signal<Player>(SIGNAL_STEP_BEGIN_PLAY);
    register_signal<Player>(SIGNAL_STEP_RUN_PRODUCTION);
    // expose variables
    register_property("colour",&Player::colour,Color(1,1,1,1));
    register_property("coalAmount",&Player::coalAmount,0);
    register_property("energyAmount",&Player::energyAmount,0);
    register_property("moneyAmount",&Player::moneyAmount,0);
    register_property("coalIncome",&Player::coalIncome,0);
    register_property("energyIncome",&Player::energyIncome,0);
    register_property("moneyIncome",&Player::moneyIncome,0);

}

Player::Player()
{
    
}

Player::~Player()
{
}

void Player::_init()
{
    colour = Color(1,1,1,1);
    moneyAmount = 10;
    energyAmount = 0;
    coalAmount = 0;

    coalIncome = 0;
    energyIncome = 0;
    moneyIncome = 0;
}

void Player::CreateBuilding(Ref<BuildingData> data, TileMap *tilemap, Vector2 pos)
{
    auto scene = data->packedScene;
    Node *newBuilding = scene->instance();

    add_child(newBuilding);
    Building *building = Object::cast_to<Building>(newBuilding);
    building->set_position(pos);
    building->ParseEnvironment(tilemap);    // read tile data
    building->ClearFootprint(tilemap);  // set tiles to invalid
    building->AddToPlayer(this);
    building->PayBuildCost(this);

    // broadcast update player UI
    auto gc = get_node("/root/GameController");
    gc->call("FullUIUpdate",this);

}

void Player::GainIncomePhase()
{
    emit_signal(SIGNAL_STEP_GAIN_INCOME);
}

void Player::PayCostPhase()
{
    emit_signal(SIGNAL_STEP_PAY_COST);
}

void Player::RunProductionPhase()
{
    emit_signal(SIGNAL_STEP_RUN_PRODUCTION);
}

void Player::BeginPlayPhase(){
    emit_signal(SIGNAL_STEP_BEGIN_PLAY);
}