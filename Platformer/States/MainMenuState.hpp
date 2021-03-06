#pragma once
#include <functional>
#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "../MenuButtons.hpp"
#include "../Background.hpp"

struct Managers;

class MainMenuState: public State {
public:
    MainMenuState(Managers& managers);
    
    void Init() override;
    void Cleanup() override;
    
    void Pause() override;
    void Resume() override;
    
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
private:
    void SpawnButton(std::string text, float x, float y, std::function<void()> handler);
    Managers& _managers;
    Background _background;
    MenuButtons _menuButtons;

    sf::Text Title;
};

