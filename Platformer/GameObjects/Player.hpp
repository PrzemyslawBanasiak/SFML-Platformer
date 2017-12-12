#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObject.hpp"
#include "RigidBody.hpp"

class Player: public GameObject {
public:
    Player();
    void Update(float dt) override;
    void SetRigidbody(std::unique_ptr<RigidBody> rigidBody);
private:
    std::unique_ptr<RigidBody> _rigidbody;
};
