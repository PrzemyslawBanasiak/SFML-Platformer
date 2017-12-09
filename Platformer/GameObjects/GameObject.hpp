#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GameObject {
public:
    GameObject(std::string tag = "Uninitalized");
    virtual void Update(float dt) = 0;
    
    
    const std::string& GetTag();
    sf::Sprite& GetSprite();
    void SetSprite(sf::Sprite& sprite);
    void Move(const sf::Vector2f& dir);
protected:
    std::string _tag;
    sf::Sprite _sprite;
};
