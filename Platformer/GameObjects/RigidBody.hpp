#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject;
class GameMap;
enum ColliderType;

class RigidBody {
public:
    RigidBody(GameObject& gameObject, GameMap& map);

    void BeforeUpdate();
    void Update(float dt);
    bool IsInAir();
    void Move(const sf::Vector2f& dir);
    const sf::Vector2f& GetVelocity();

    void Jump();
    
    std::vector<GameObject> GetCollidingObjects();
private:

    void ApplyFalling(float dt);
    void ClearCollisions();
    const sf::Vector2f & limitMove(const sf::Vector2f & vec);
    void moveAlongX();
    float fallingSpeed = 0.0f;

    GameMap& _map;
    GameObject& _gameObject;
    sf::Vector2f _newPos;
    sf::Vector2f _velocity;
};
