#include "GameEngine.hpp"
#include "Definitions.hpp"
#include "States/SplashScreenState.hpp"

GameEngine::GameEngine(std::string name) {
    _managers.window.create(sf::VideoMode(800, 600), "Plarformer", sf::Style::Close | sf::Style::Titlebar);
    _managers.state.ChangeState(std::unique_ptr<State>(new SplashScreenState(_managers)));
}

GameEngine::~GameEngine() {
    
}

void GameEngine::Run() {
    float dt;
    sf::Clock clock;
    _managers.window.setFramerateLimit(10);
    while(_managers.window.isOpen()) {
        if (IsError())
            return Error("Error met, escaping game loop");
        dt = clock.restart().asSeconds();
    
        _managers.state.GetActiveState()->HandleInput();
        _managers.state.GetActiveState()->Update(dt);
        _managers.state.GetActiveState()->Draw(dt);
    }
}

