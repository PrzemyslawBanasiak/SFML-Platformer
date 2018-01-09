#include "Camera.hpp"
#include "Definitions.hpp"


Camera::Camera()
: view(sf::FloatRect(0, 0, screen_width, screen_height))
, offset(0, -60)
, boundries(screen_width/2, screen_height/2) {
    
}

void Camera::Update() {
    if(followTarget)
        view.setCenter(min(boundries, followTarget->getPosition() + offset));
}

sf::Vector2f Camera::min(sf::Vector2f a, sf::Vector2f b) {
    return {
        std::fmaxf(a.x, b.x),
        std::fmaxf(a.y, b.y)
    };
}

void Camera::Render(sf::RenderWindow& window) {
    window.setView(view);
}

void Camera::SetFollowTarget(const sf::Sprite& target) {
    followTarget = &target;
}
