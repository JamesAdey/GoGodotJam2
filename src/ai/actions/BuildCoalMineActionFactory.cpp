#include "BuildCoalMineActionFactory.h"
#include "BuildCoalMineAction.h"
#include "../AIBlackboard.h"
#include "../../gamedata/GameData.h"

using namespace godot;

BuildCoalMineActionFactory::BuildCoalMineActionFactory()
{
}
BuildCoalMineActionFactory::~BuildCoalMineActionFactory()
{
}

void BuildCoalMineActionFactory::FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard)
{
    auto *tilemap = blackboard->tilemap;

    auto coalMineData = GameData::GetSingleton()->coalMineData;

    if (!coalMineData->CanAfford(blackboard->coalAmount, blackboard->energyAmount, blackboard->moneyAmount))
    {
        return;
    }

    // query the tilemap for best tiles, pick best tile
    auto coalCells = tilemap->get_used_cells_by_id(GameData::GetSingleton()->COAL_TILE_NUM);

    float bestValue = -1;
    Vector2 bestCoord = Vector2::ZERO;

    for (int i = 0; i < coalCells.size(); i++)
    {
        auto cellPos = Vector2(coalCells[i]);
        // skip if invalid placement
        if (!coalMineData->CanPlaceInTile(tilemap, cellPos))
        {
            continue;
        }
        // compute possible value
        auto value = coalMineData->CalcIncome(tilemap, cellPos);
        if (value > bestValue)
        {
            bestValue = value;
            bestCoord = cellPos;
        }
    }

    if (bestValue > 0)
    {
        auto worldPos = tilemap->map_to_world(bestCoord);
        worldPos = tilemap->to_global(worldPos);

        auto action = std::make_unique<BuildCoalMineAction>(worldPos);
        blackboard->actions.push_back(std::move(action));
    }
}