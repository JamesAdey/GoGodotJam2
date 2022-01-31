#include "BuildTurbineActionFactory.h"
#include "BuildTurbineAction.h"
#include "../AIBlackboard.h"
#include "../../gamedata/GameData.h"

using namespace godot;

BuildTurbineActionFactory::BuildTurbineActionFactory()
{
}
BuildTurbineActionFactory::~BuildTurbineActionFactory()
{
}

void BuildTurbineActionFactory::FillInstancedActions(std::unique_ptr<AIBlackboard> &blackboard)
{
    auto *tilemap = blackboard->tilemap;

    auto turbineData = GameData::GetSingleton()->turbineData;

    if (!turbineData->CanAfford(blackboard->coalAmount, blackboard->energyAmount, blackboard->moneyAmount))
    {
        return;
    }

    // query the tilemap for best tiles, pick best tile
    auto grassCells = tilemap->get_used_cells_by_id(GameData::GetSingleton()->GRASS_TILE_NUM);

    grassCells.shuffle();

    auto desiredIndex = -1;
    auto bestCoord = Vector2::ZERO;

    for (int i = 0; i < grassCells.size(); i++)
    {
        auto cellPos = Vector2(grassCells[i]);

        // skip if invalid placement
        if (!turbineData->CanPlaceInTile(tilemap, cellPos))
        {
            continue;
        }
        desiredIndex = i;
        bestCoord = cellPos;
        break;
    }

    if (desiredIndex >= 0)
    {
        auto worldPos = tilemap->map_to_world(bestCoord);
        worldPos = tilemap->to_global(worldPos);

        auto action = std::make_unique<BuildTurbineAction>(worldPos);
        blackboard->actions.push_back(std::move(action));
    }
}