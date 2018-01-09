#include "RigidBody.hpp"
#include "GameObject.hpp"
#include "../GameMap.hpp"
#include "../Definitions.hpp"
#include "../Lib/json.h"
#include <iostream>

std::vector<int> getAllDividableInRangeIndices(int from, int to, int divider) {
    std::vector<int> indices = {};
    for (int i = from / divider; i * divider < to; ++i) {
        indices.push_back(i);
    }
    return indices;
}

RigidBody::RigidBody(GameObject& gameObject, GameMap& map)
: _gameObject(gameObject)
, _map(map)
, _velocity({0.0f, 0.0f})
{
    
}

void RigidBody::BeforeUpdate() {
    _newPos = _gameObject.GetSprite().getPosition();
    _velocity = {0.0f, 0.0f};
}

void RigidBody::Update(float dt) {
    ApplyFalling(dt);
    
    _newPos += _velocity;
    _newPos.y += fallingSpeed;
    ClearCollisions();
    _gameObject.GetSprite().setPosition(_newPos);
}

void RigidBody::ApplyFalling(float dt) {
    if (IsInAir() || fallingSpeed < 0)
        fallingSpeed += Physics::Gravity.y * dt;
    else
        fallingSpeed = 0.0f;
}

void RigidBody::ClearCollisions() {
    auto goPos = _gameObject.GetSprite().getPosition();
    auto _vel = _newPos - goPos;
    float dir = _vel.x > 0.0f ? 1.0f : -1.0f;
    //if (_vel.y > 0)
        if (_map.tileAt({goPos.x, _newPos.y}) == ETerrain)
            _newPos.y = (int)_newPos.y / _map.tileHeight() * _map.tileHeight() + 1;
    if (_map.tileAt({_newPos.x + Physics::CharCollWidth/2 * dir, _newPos.y - 10}) == ETerrain)
        _newPos.x = goPos.x;

    _velocity = limitMove(_newPos - _gameObject.GetSprite().getPosition());
    _gameObject.GetSprite().move(_velocity);
}

sf::Vector2f RigidBody::limitMove(sf::Vector2f vec) {
    return {
        std::fmin(Physics::maxMovePerFrame, vec.x),
        std::fmin(Physics::maxMovePerFrame, vec.y)
    };
}

void RigidBody::moveAlongX() {
}

bool RigidBody::IsInAir() {
    const auto& bounds = _gameObject.GetSprite().getGlobalBounds();
    float centerX = bounds.left + 0.5f * bounds.width;
    sf::Vector2f leftBot =  {centerX - Physics::CharCollWidth/2, bounds.top + bounds.height + 1};
    sf::Vector2f rightBot = {centerX + Physics::CharCollWidth/2, bounds.top + bounds.height + 1};
    return _map.tileAt(leftBot) != ETerrain && _map.tileAt(rightBot) != ETerrain;
}

std::vector<GameObject> RigidBody::GetCollidingObjects() {
    return {};
}

void RigidBody::Move(const sf::Vector2f &dir) {
    _velocity += dir;
}

const sf::Vector2f & RigidBody::GetVelocity() {
    return _velocity;
}

void RigidBody::Jump() {
    fallingSpeed = -JUMP_SPEED;
}
