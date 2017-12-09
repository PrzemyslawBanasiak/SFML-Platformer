#include "GameEngine.hpp"
#include "SplashScreenState.hpp"

GameEngine::GameEngine(std::string name) {
    _managers.window.create(sf::VideoMode(800, 600), "Plarformer", sf::Style::Close | sf::Style::Titlebar);
    _managers.state.ChangeState(std::unique_ptr<State>(new SplashScreenState(_managers)));
}

GameEngine::~GameEngine() {
    
}

void GameEngine::Run() {
    float dt;
    sf::Clock clock;
    while(_managers.window.isOpen()) {
        dt = clock.restart().asSeconds();
    
        _managers.state.GetActiveState()->HandleInput();
        _managers.state.GetActiveState()->Update(dt);
        _managers.state.GetActiveState()->Draw(dt);
    }
}

