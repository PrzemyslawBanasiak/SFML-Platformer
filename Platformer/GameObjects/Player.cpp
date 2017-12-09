#include "Player.hpp"
#include "../Managers/InputManager.hpp"
#include "../Definitions.hpp"
#include "RigidBody.hpp"

Player::Player()
    : GameObject("Player") {
}

void Player::Update(float dt){
    if(_rigidbody)
        _rigidbody->Update(dt);
    Move(InputManager::GetInputAxis() * PLAYER_SPEED * dt);
}

void Player::SetRigidbody(std::unique_ptr<RigidBody> rigidbody) {
    _rigidbody = std::move(rigidbody);
}

