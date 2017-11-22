#pragma once
#include "State.hpp"

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
    Managers& _managers;
    int activeSelection = 0;
    sf::Text Title;
    sf::Text NewGame;
    sf::Text Exit;
};

