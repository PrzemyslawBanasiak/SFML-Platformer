#include "SplashScreenState.hpp"
#include "MainMenuState.hpp"
#include "../Definitions.hpp"
#include "../GameEngine.hpp"

SplashScreenState::SplashScreenState(Managers& managers) : _managers(managers){
}

void SplashScreenState::Init() {
    _managers.asset.LoadTexture("splash", FilePaths::SplashScreen);
    _splash.setTexture(_managers.asset.GetTexture("splash"));
    _splash.setOrigin(_splash.getGlobalBounds().width / 2.0f,
                     _splash.getGlobalBounds().height / 2.0f);
    _splash.setPosition(_managers.window.getSize().x / 2.0f,
                       _managers.window.getSize().y / 2.0f);
    _clock.restart();
}

void SplashScreenState::Cleanup() {
}

void SplashScreenState::Pause() {
    
}

void SplashScreenState::Resume() {
    _clock.restart();
}

void SplashScreenState::HandleInput() {
    sf::Event event;
    while (_managers.window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _managers.window.close();
        }
    }
}

void SplashScreenState::Update(float dt) {
    if(_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_TIME) {
        _managers.state.ChangeState(std::unique_ptr<State>(new MainMenuState(_managers)));
    }
}

void SplashScreenState::Draw(float dt) {
    _managers.window.clear(GameColor::LightBlue);
    _managers.window.draw(_splash);
    _managers.window.display();
}
