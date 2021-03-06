#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

struct Managers;
class Player: public GameObject {
public:
    Player(Managers& managers, const sf::Vector2f& pos);
    void Update(float dt) override;
private:

    void Jump(sf::Vector2f& input);
    bool canJump, canDoubleJump;
    bool spaceReleased;
};
