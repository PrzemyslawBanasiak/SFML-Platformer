#pragma once
#include <SFML/Graphics.hpp>
#include "LevelLoader.hpp"
#include <vector>


class GameMap {
public:
    GameMap();
    void LoadMap(const LoaderStruct::map& map);
    void AddLayer(const std::vector<int>& layerData);

private:
    std::vector<sf::Sprite> _map;
    std::vector<char> _colliders;
};
