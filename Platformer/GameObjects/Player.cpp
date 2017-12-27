#include "Player.hpp"
#include "../Managers/InputManager.hpp"
#include "../Definitions.hpp"
#include "../GameEngine.hpp"
#include "RigidBody.hpp"

Player::Player(Managers& managers, const sf::Vector2f& pos)
    : GameObject("Player") {
    sf::Sprite sprite;
    sprite.setPosition(pos);
    this->SetSprite(sprite);
}

void Player::Update(float dt){
    if(_rigidbody)
        _rigidbody->Update(dt);

    auto input = InputManager::GetInputAxis();
    input.y = std::fmax(0, input.y * JUMP_SPEED); //Fix jumping
    Move(InputManager::GetInputAxis() * PLAYER_SPEED * dt);

    if (_animation) {
        _animation->Update(dt, input.x >= 0);
    }
}

