#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects\Player.hpp"
#include "LevelLoader.hpp"
#include <memory>
#include <vector>

enum ColliderType;
class GameObject;
struct Managers;
namespace LoaderStruct {
    struct map;
    struct layer;
}

class GameMap {
public:
    GameMap(Managers& managers);
    void LoadMap(const LoaderStruct::map& map);
    const std::vector<sf::Sprite>& getSprites();
    const std::vector<char>& getColliders();
    GameObject* getPlayer();
    ColliderType tileAt(float x, float y);
    ColliderType tileAt(const sf::Vector2f& pos);
    ColliderType tileAtIndex(int x, int y);

    int tileWidth();
    int tileHeight();
    int mapHeight();
private:
    void LoadLayer(const LoaderStruct::layer & layer);
    void loadTileLayer(const LoaderStruct::layer & layer);
    void loadObjectLayer(const LoaderStruct::layer & layer);

    Managers& _managers;
    std::vector<sf::Sprite> _map;
    std::vector<char> _colliders;
    std::vector<std::unique_ptr<GameObject>> _gameObjects;
    LoaderStruct::map _mapstruct;
};
