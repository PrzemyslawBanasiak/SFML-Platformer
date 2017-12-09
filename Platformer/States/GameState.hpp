#pragma once
#include <string>
#include "State.hpp"
#include "../Camera.hpp"
#include "../LevelLoader.hpp"
#include "../GameObjects/Player.hpp"

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
    std::vector<sf::Sprite> _map;
    std::vector<bool> _colliders;
    
    Managers& _managers;
    Camera _camera;
    LevelLoader _loader;
    Player _player;
    float playerSpeed = 100.0f;
};


