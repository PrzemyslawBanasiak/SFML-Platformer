#include <iostream>
#include "../Definitions.hpp"
#include "../GameEngine.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

MainMenuState::MainMenuState(Managers& managers) 
    : _managers(managers)
    , _background(managers)
    , _menuButtons(managers) {
}

void MainMenuState::Init() {
    _menuButtons.AddButton("New Game", 0.2f, 0.5f, [&]() {
        _managers.state.ChangeState(std::unique_ptr<State>(new GameState("level1", _managers)));
    });

    _menuButtons.AddButton("Exit", 0.2f, 0.6f, [&]() {
        _managers.window.close();
    });
    Title.setFont(_managers.asset.GetFont("kenvector"));
    Title.setString("Platformer");
    Title.setOrigin(Title.getGlobalBounds().width/2, Title.getGlobalBounds().height/2);    
    Title.setPosition(_managers.window.getSize().x * 0.5f, _managers.window.getSize().y * 0.1f);
}

void MainMenuState::SpawnButton(std::string text, float x, float y, std::function<void()> handler) {

}

void MainMenuState::Cleanup() {

}

void MainMenuState::Pause() {
    
}

void MainMenuState::Resume() {
}

void MainMenuState::HandleInput() {
    sf::Event event;
    while (_managers.window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _managers.window.close();
        }
    }
}

void MainMenuState::Update(float dt) {
    _menuButtons.Update();
}

void MainMenuState::Draw(float dt) {
    _background.Draw();
    _menuButtons.Draw();
    _managers.window.draw(Title);
    _managers.window.display();
}

