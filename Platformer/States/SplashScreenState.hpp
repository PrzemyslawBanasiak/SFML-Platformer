#pragma once
#include "State.hpp"
#include "../GameEngine.hpp"

class SplashScreenState: public State {
public:
    SplashScreenState(Managers& managers);
    
    void Init() override;
    void Cleanup() override;
    
    void Pause() override;
    void Resume() override;
    
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
private:
    Managers& _managers;
    sf::Sprite _splash;
    sf::Clock _clock;
};
