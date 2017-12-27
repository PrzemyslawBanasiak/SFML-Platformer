#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "RigidBody.hpp"
#include "PlayerAnimation.hpp"

class GameObject {
public:
    GameObject(std::string tag = "Uninitalized");
    void BeforeUpdate();
    virtual void Update(float dt) = 0;    
    
    const std::string& GetTag();
    sf::Sprite& GetSprite();
    void SetSprite(sf::Sprite& sprite);
    void Move(const sf::Vector2f& dir);

    void SetRigidbody(std::unique_ptr<RigidBody> rigidBody);
    void SetAnimation(std::unique_ptr<PlayerAnimation> animation);
protected:
    std::string _tag;
    sf::Sprite _sprite;

    std::unique_ptr<RigidBody> _rigidbody;
    std::unique_ptr<PlayerAnimation> _animation;
};
