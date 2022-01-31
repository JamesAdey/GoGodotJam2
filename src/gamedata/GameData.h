#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <Godot.hpp>
#include <Node.hpp>

#include "CoalMineData.h"
#include "TurbineData.h"
#include "PylonData.h"
namespace godot
{

    class GameData : public Node
    {
        GODOT_CLASS(GameData, Node)

    public:
        static void _register_methods();
        GameData();
        ~GameData();
        void _init(); // our initializer called by Godot

        static GameData *GetSingleton(){
            return _singleton;
        }

        const static int64_t INVALID_TILE_NUM = -1;
        const static int64_t GRASS_TILE_NUM = 0;
        const static int64_t COAL_TILE_NUM = 2;
        const static int64_t OCCUPIED_TILE_NUM = 3;
        Ref<CoalMineData> coalMineData;
        Ref<TurbineData> turbineData;
        Ref<PylonData> pylonData;
        Ref<Texture> coalTexture;
        Ref<Texture> energyTexture;
        Ref<Texture> moneyTexture;
    private:
        static GameData *_singleton;  // apparently the name _singleton can't be used here
    };

}

#endif