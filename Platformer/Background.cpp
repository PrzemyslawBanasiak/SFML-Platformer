#include "Background.hpp"
#include "GameMap.hpp"
#include "Definitions.hpp"
#include "GameEngine.hpp"


Background::Background(Managers& managers)
    : _managers(managers) {
    _managers.asset.LoadTexture("background", FilePaths::Background);
    _background.setTexture(_managers.asset.GetTexture("background"));
    float scale = std::fmaxf(_background.getTextureRect().height / screen_height,
        _background.getTextureRect().width / screen_width);
    _background.setScale(scale, scale);
    _offset = _managers.window.getView().getSize() * 0.5f;
}


void Background::Draw() {
    _background.setPosition(_managers.window.getView().getCenter() - _offset);
    _managers.window.clear(GameColor::LightBlue);
    _managers.window.draw(_background);
}

