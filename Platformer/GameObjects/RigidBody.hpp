#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class RigidBody {
public:
    RigidBody(GameObject& gameObject, const std::vector<bool>& map, int mapWidth);
    void Update(float dt);
    bool IsInAir();
    std::vector<GameObject> GetCollidingObjects();
    void AddForce(const sf::Vector2f& dir);
private:
    const std::vector<bool>& _map;
    GameObject& _gameObject;
    sf::Vector2f _velocity;
    int _mapWidth;
};
