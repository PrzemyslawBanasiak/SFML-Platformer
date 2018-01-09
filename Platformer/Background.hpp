#pragma once
#include <SFML\Graphics.hpp>

struct Managers;
class GameMap;

class Background {
public:
    Background(Managers& managers);
    void Draw();

private:
    Managers& _managers;
    sf::Sprite _background;
    sf::Vector2f _offset;
};

