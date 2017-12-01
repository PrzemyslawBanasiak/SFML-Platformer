#pragma once
#include <string>
#include "State.hpp"
#include "../LevelLoader.hpp"

struct Managers;

class GameState: public State {
public:
    GameState(std::string level, Managers& managers);
    
    void Init() override;
    void Cleanup() override;
    
    void Pause() override;
    void Resume() override;
    
    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;
private:
    Managers& _managers;
    LevelLoader _loader;
    std::vector<sf::Sprite> _sprites;
};


