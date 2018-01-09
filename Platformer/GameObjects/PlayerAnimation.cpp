#include "PlayerAnimation.hpp"
#include "GameObject.hpp"
#include "../Definitions.hpp"
#include "../GameEngine.hpp"

const sf::IntRect walk[] = {
    {0, 258, 128, 256},
    {0, 0,   128, 256}
};


const sf::IntRect idle[] = {
    {0, 1032, 128, 256}
};

const sf::IntRect jump[] = {
    {0, 1290, 128, 256}
};

const sf::IntRect duck[] = {
    {130, 258, 128, 256}
};


PlayerAnimation::PlayerAnimation(GameObject& gameObject, Managers& managers)
    : _gameObject(gameObject)
    , _managers(managers) 
    , _velocity({0.0f, 0.0f})
    , _frame(0)
    , _frameTime(0)
{
    _gameObject.GetSprite().setTexture(_managers.asset.GetTexture("tileset"));
    _gameObject.GetSprite().setTextureRect(walk[_frame]);
    _gameObject.GetSprite().setOrigin({_gameObject.GetSprite().getTextureRect().width / 2.0f,
                                      (float)_gameObject.GetSprite().getTextureRect().height});
}

void PlayerAnimation::Update(float dt, const sf::Vector2f& vel) {
    _frameTime += dt;
    if (FRAME_TIME < _frameTime) {
        _frame = (_frame + 1) % 2;
        _frameTime = 0;
    }
    _gameObject.GetSprite().setScale(vel.x > 0 ? 1.0f : -1.0f, 1.0f);
    _gameObject.GetSprite().setTextureRect(walk[_frame]);
}

void PlayerAnimation::UpdateVariable(sf::Vector2f velocity) {
    _velocity = velocity;
}