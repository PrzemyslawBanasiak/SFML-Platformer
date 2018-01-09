#pragma once
#include <SFML/Graphics.hpp>

struct Managers;
class GameObject;

class PlayerAnimation {
public:
    PlayerAnimation(GameObject& gameObject, Managers& managers);
    void Update(float dt, const sf::Vector2f& vel);
    void ChangeState();
    void Rotate(const sf::Vector2f & vel);
    void UpdateVariable(sf::Vector2f velocity);
private:
    sf::Vector2f _velocity;
    GameObject& _gameObject;
    Managers& _managers;

    int _frame;
    float _frameTime;
    float _rotation;
};