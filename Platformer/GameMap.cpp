#include "GameMap.hpp"
#include "GameEngine.hpp"
#include "LevelLoader.hpp"
#include <map>
#include "Definitions.hpp"
#include <iostream>


GameMap::GameMap(Managers& managers)
    : _managers(managers)
{
}

void GameMap::LoadMap(const LoaderStruct::map & map) {
    _mapstruct = map;
    _colliders.resize(map.width * map.height);
    for (const auto& layer : map.layers)
        LoadLayer(layer);
}

void GameMap::LoadLayer(const LoaderStruct::layer & layer) {
    if (layer.type == "tilelayer")
        loadTileLayer(layer);
    else if (layer.type == "objectgroup")
        loadObjectLayer(layer);
}

const std::vector<sf::Sprite>& GameMap::getSprites() {
    return _map;
}

const std::vector<char>& GameMap::getColliders() {
    return _colliders;
}

GameObject* GameMap::getPlayer() {
    return std::find_if(_gameObjects.begin(), _gameObjects.end(), [](std::unique_ptr<GameObject>& ga) {
        return ga->GetTag() == "Player";
    })->get();
}

ColliderType GameMap::tileAt(float x1, float y1) {
    int x = (int)x1 / _mapstruct.tilewidth; 
    int y = (int)y1 / _mapstruct.tileheight;
    return (ColliderType)_colliders[x + y * _mapstruct.width];
}

ColliderType GameMap::tileAt(const sf::Vector2f & pos) {
    return tileAt(pos.x, pos.y);
}

ColliderType GameMap::tileAtIndex(int x, int y) {
    return (ColliderType)_colliders[x + y * _mapstruct.width];
}

int GameMap::tileWidth() {
    return _mapstruct.tilewidth;
}

int GameMap::tileHeight() {
    return _mapstruct.tileheight;
}

int GameMap::mapHeight() {
    return _mapstruct.height;
}

void GameMap::loadTileLayer(const LoaderStruct::layer & layer) {
    const auto tileset = _mapstruct.tilesets[0];
    int tileSetTileWidth = tileset.tilewidth + tileset.spacing;
    for (size_t i = 0; i < layer.data.size(); ++i) {
        sf::Sprite s;
        int tile = layer.data[i]-1;
        s.setPosition((float)(i % _mapstruct.width * _mapstruct.tilewidth), (float)(i / _mapstruct.width * _mapstruct.tilewidth));
        if (tile != -1) {
            s.setTexture(_managers.asset.GetTexture("tileset"));
            s.setTextureRect({  tile % tileset.columns * tileSetTileWidth, 
                                tile / tileset.columns * tileSetTileWidth, 
                                tileset.tilewidth, 
                                tileset.tileheight});
        }
        if(tile == -1)
            _colliders[i] = ENone;
        else if (tileset.tiles.at(std::to_string(tile)).type == "Terrain")
            _colliders[i] = ETerrain;
        else if (tileset.tiles.at(std::to_string(tile)).type == "Kill")
            _colliders[i] = EKiller;
        else
            _colliders[i] = ENone;
        _map.push_back(s);
    }
}

void GameMap::loadObjectLayer(const LoaderStruct::layer & layer) {
    for (const auto& i : layer.objects) {
        if (i.type == "Player") {
            _gameObjects.emplace_back(new Player(_managers, sf::Vector2f((float)i.x, (float)i.y)));
        }
    }
}
