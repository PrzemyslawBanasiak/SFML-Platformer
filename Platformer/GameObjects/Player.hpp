#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObject.hpp"
#include "RigidBody.hpp"
#include "PlayerAnimation.hpp"

struct Managers;

class Player: public GameObject {
public:
    Player(Managers& managers, const sf::Vector2f& pos);
    void Update(float dt) override;
    void SetRigidbody(std::unique_ptr<RigidBody> rigidBody);
    void SetAnimation(std::unique_ptr<PlayerAnimation> animation);
private:
    std::unique_ptr<RigidBody> _rigidbody;
    std::unique_ptr<PlayerAnimation> _animation;
};
