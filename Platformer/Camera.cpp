#include "Camera.hpp"

Camera::Camera()
: view(sf::FloatRect(0, 0, 800, 600)) {
    
}

void Camera::Update() {
    if(followTarget)
        view.setCenter(followTarget->getPosition());
}

void Camera::Render(sf::RenderWindow& window) {
    window.setView(view);
}

void Camera::SetFollowTarget(const sf::Sprite& target) {
    followTarget = &target;
}
