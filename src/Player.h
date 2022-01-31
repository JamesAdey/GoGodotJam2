#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include "gamedata/BuildingData.h"

namespace godot
{
    class BuildingData; // forward declare

    class Player : public Node2D
    {
        GODOT_CLASS(Player, Node2D)
    public:
        const static char *SIGNAL_STEP_GAIN_INCOME;
        const static char *SIGNAL_STEP_PAY_COST;
        const static char *SIGNAL_STEP_BEGIN_PLAY;
        const static char *SIGNAL_STEP_RUN_PRODUCTION;

        static void _register_methods();
        Player();
        ~Player();

        void _init(); // our initializer called by Godot

        void CreateBuilding(Ref<BuildingData> data, TileMap *tilemap, Vector2 pos);

        void GainIncomePhase();
        void PayCostPhase();
        void BeginPlayPhase();
        void RunProductionPhase();


        Color colour;
        int32_t coalAmount;
        int32_t energyAmount;
        int32_t moneyAmount;

        int32_t coalIncome;
        int32_t energyIncome;
        int32_t moneyIncome;

    };

}

#endif