#pragma once
#include <string>
#include "State.hpp"
#include "../Background.hpp"
#include "../Camera.hpp"
#include "../GameObjects/Player.hpp"
#include "../GameMap.hpp"

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
    std::string _level;
    Background _background;
    GameMap _map;
    Managers& _managers;
    Camera _camera;
    float playerSpeed = 100.0f;
};


