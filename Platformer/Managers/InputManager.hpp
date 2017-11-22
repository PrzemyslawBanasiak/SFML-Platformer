#pragma once
#include <SFML/Graphics.hpp>

class InputManager {
public:
    template<typename T>
    static bool IsPressed(const T& sprite,
                          const sf::RenderWindow& window,
                          sf::Mouse::Button button = sf::Mouse::Left) {
            return sf::Mouse::isButtonPressed(button) && sprite.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    }
};
