#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject;

class RigidBody {
public:
    RigidBody(GameObject& gameObject, const std::vector<char>& map, int mapWidth);

    void BeforeUpdate();
    void Update(float dt);
    bool IsInAir();
    void Move(const sf::Vector2f& dir);
    
    std::vector<GameObject> GetCollidingObjects();
private:
    const std::vector<char>& _map;
    GameObject& _gameObject;
    sf::Vector2f _velocity;
    int _mapWidth;
};
