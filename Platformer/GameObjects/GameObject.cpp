#include "GameObject.hpp"

GameObject::GameObject(std::string tag) :
    _tag(tag) {
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
    _sprite.move(dir);
}
