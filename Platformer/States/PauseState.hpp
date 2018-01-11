#pragma once
#include "State.hpp"
#include "../MenuButtons.hpp"
#include <SFML/Graphics.hpp>

struct Managers;

class PauseState: public State {
public:
    PauseState(Managers& managers);

    void Init() override;
    void Cleanup() override;

    void Pause() override;
    void Resume() override;

    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
private:
    Managers& _managers;
    sf::Texture _texture;
    sf::Sprite _background;
    MenuButtons _menuButtons;
};