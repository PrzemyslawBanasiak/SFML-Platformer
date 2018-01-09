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
    _animation = std::make_unique<PlayerAnimation>(*this, managers);
}

void Player::Update(float dt){
    auto input = InputManager::GetInputAxis() * PLAYER_SPEED * dt;

    Jump(input);
    Move(input);
    
    if (_rigidbody)
        _rigidbody->Update(dt);
    if (_animation)
        _animation->Update(dt, _rigidbody->GetVelocity());
}

void Player::Jump(sf::Vector2f& input) {
    if (!_rigidbody->IsInAir()) {
        canJump = true;
        canDoubleJump = true;
    } else {
        canJump = false;
    }
    if (input.y == 0)
        spaceReleased = true;
    if (input.y < 0 && canJump) {
        _rigidbody->Jump();
        canJump = false;
        spaceReleased = false;
    } else if(input.y < 0 && canDoubleJump && spaceReleased) {
        _rigidbody->Jump();
        canDoubleJump = false;
    }
    input.y = 0;
}

