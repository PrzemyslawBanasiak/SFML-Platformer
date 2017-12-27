#pragma once
#include <string>
#include "State.hpp"
#include "../Camera.hpp"
#include "../LevelLoader.hpp"
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
    void LoadTileLayer(const LoaderStruct::layer& l);
    void LoadObjectLayer(const LoaderStruct::layer& l);

    GameMap _map;


    //std::vector<sf::Sprite> _map;
    //std::vector<char> _colliders;
    
    Managers& _managers;
    Camera _camera;
    LevelLoader _loader;
    Player _player;
    float playerSpeed = 100.0f;
};


