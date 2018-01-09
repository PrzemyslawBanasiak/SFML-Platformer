#pragma once
#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera();
    void Update();
    void Render(sf::RenderWindow& window);
    void SetFollowTarget(const sf::Sprite& target);
private:
    sf::Vector2f min(sf::Vector2f a, sf::Vector2f b);
    const sf::Vector2f offset;
    const sf::Vector2f boundries;
    const sf::Sprite* followTarget;
    sf::View view;
};
