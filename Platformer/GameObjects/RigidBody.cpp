#include "RigidBody.hpp"
#include "GameObject.hpp"
#include "../Definitions.hpp"

RigidBody::RigidBody(GameObject& gameObject, const std::vector<char>& map, int mapWidth)
: _gameObject(gameObject)
, _map(map)
, _velocity({0.0f, 0.0f})
, _mapWidth(mapWidth) {
    
}

void RigidBody::BeforeUpdate() {
    _velocity = {0.0f, 0.0f};
}

void RigidBody::Update(float dt) {
    _gameObject.GetSprite().move(_velocity * dt);
    if(IsInAir()) {
        _velocity += Physics::Gravity * dt;
    } else {
        _velocity = {0.0f, 0.0f};
    }
}

//Player's origin is in left top
bool RigidBody::IsInAir() {
    const auto& bounds = _gameObject.GetSprite().getGlobalBounds();
    int y = (int)(bounds.top + bounds.height) / 128 * _mapWidth;
    return !_map[(int) (y + bounds.left / 128)] || !_map[(int) (y + (bounds.left + bounds.width) / 128)];
}

std::vector<GameObject> RigidBody::GetCollidingObjects() {
    return {};
}

void RigidBody::Move(const sf::Vector2f &dir) {
    _velocity += dir;
}
