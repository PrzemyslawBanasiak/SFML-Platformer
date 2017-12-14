#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

struct Managers;

class PlayerAnimation {
public:
    PlayerAnimation(GameObject& gameObject, Managers& managers);
    void Update(float dt, bool lookRight);
    void UpdateVariable(sf::Vector2f velocity);
private:
    sf::Vector2f _velocity;
    GameObject& _gameObject;
    Managers& _managers;

    int _frame;
    float _frameTime;
};