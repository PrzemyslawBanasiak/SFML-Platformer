#include "GameObject.hpp"
#include "RigidBody.hpp"

GameObject::GameObject(std::string tag) :
    _tag(tag) {
}

void GameObject::BeforeUpdate() {
    if (_rigidbody)
        _rigidbody->BeforeUpdate();
}

sf::Sprite& GameObject::GetSprite() {
    return _sprite;
}

void GameObject::SetSprite(sf::Sprite &sprite) {
    _sprite = sprite;
}

const std::string& GameObject::GetTag() {
    return _tag;
}

void GameObject::Move(const sf::Vector2f &dir) {
    if (_rigidbody) {
        _rigidbody->Move(dir);
    } else {
        _sprite.move(dir);
    }
}

void GameObject::SetRigidbody(std::unique_ptr<RigidBody> rigidbody) {
    _rigidbody = std::move(rigidbody);
}

void GameObject::SetAnimation(std::unique_ptr<PlayerAnimation> animation) {
    _animation = std::move(animation);
}
