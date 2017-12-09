#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class InputManager {
public:
    template<typename T>
    static bool IsPressed(const T& sprite,
                          const sf::RenderWindow& window,
                          sf::Mouse::Button button = sf::Mouse::Left) {
        return sf::Mouse::isButtonPressed(button)
            && sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    }
    
    static sf::Vector2f GetInputAxis();
};
