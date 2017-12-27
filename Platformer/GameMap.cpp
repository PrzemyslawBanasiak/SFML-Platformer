#include "GameMap.hpp"
#include "Definitions.hpp"


/*void GameMap::AddLayer(const std::vector<int>& layerData)
    for (size_t i = 0; i < l.data.size(); ++i) {
        sf::Sprite s;
        s.setPosition((i % _loader.GetMap().width) * tileset.tilewidth,
            (i / _loader.GetMap().width) * tileset.tileheight);
        if (l.data[i] != 0) {
            s.setTexture(_managers.asset.GetTexture("tileset"));
            int tileType = l.data[i] - 1;
            s.setTextureRect({tileType % tileset.columns * 130, tileType / tileset.columns * 130,
                tileset.tilewidth, tileset.tileheight});
        }

        if (tileset.tiles[std::to_string(l.data[i])].type == "Terrain")
            _colliders[i] = ETerrain;
        else if (tileset.tiles[std::to_string(l.data[i])].type == "Kill")
            _colliders[i] = EKiller;
        else
            _colliders[i] = ENone; //assuming only one tile can be at given place
        _map.push_back(s);
    }
}*/

void GameMap::LoadMap(const LoaderStruct::map & map) {}

void GameMap::AddLayer(const std::vector<int>& layerData) {}
