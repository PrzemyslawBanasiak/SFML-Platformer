#pragma once
#include <SFML/Graphics.hpp>

class InputManager {
public:
    template<typename T>
    static bool IsPressed(const T& sprite,
                          const sf::RenderWindow& window,
                          sf::Mouse::Button button = sf::Mouse::Left) {
        return sf::Mouse::isButtonPressed(button)
            && sprite.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
    }
    
    static sf::Vector2f GetInputAxis();
};
