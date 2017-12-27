#pragma once
#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera();
    void Update();
    void Render(sf::RenderWindow& window);
    void SetFollowTarget(const sf::Sprite& target);
private:
    const sf::Sprite* followTarget;
    sf::View view;
};
