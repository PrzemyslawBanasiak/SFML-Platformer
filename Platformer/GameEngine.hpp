#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Managers/StateMachine.hpp"
#include "Managers/InputManager.hpp"
#include "Managers/AssetManager.hpp"

struct Managers {
    StateMachine state;
    sf::RenderWindow window;
    AssetManager asset;
    InputManager input;
};

class GameEngine {
public:
    GameEngine(std::string name);
    ~GameEngine();
    
    void Run();
private:
    Managers _managers;
};
