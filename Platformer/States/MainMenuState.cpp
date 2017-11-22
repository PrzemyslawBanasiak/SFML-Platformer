#include "../Definitions.hpp"
#include "../GameEngine.hpp"
#include "MainMenuState.hpp"

MainMenuState::MainMenuState(Managers& managers) : _managers(managers) {
}

void MainMenuState::Init() {
    _managers.asset.LoadFont("vcr", FilePaths::MenuFont);
    Title.setFont(_managers.asset.GetFont("vcr"));
    NewGame.setFont(_managers.asset.GetFont("vcr"));
    Exit.setFont(_managers.asset.GetFont("vcr"));
    Title.setString("Platformer");
    NewGame.setString("New Game");
    Exit.setString("Exit");
    Title.setOrigin(Title.getGlobalBounds().width/2, Title.getGlobalBounds().height/2);
    NewGame.setOrigin(NewGame.getGlobalBounds().width/2, NewGame.getGlobalBounds().height/2);
    Exit.setOrigin(Exit.getGlobalBounds().width/2, Exit.getGlobalBounds().height/2);
    
    Title.setPosition(_managers.window.getSize().x * 0.5f, _managers.window.getSize().y * 0.1f);
    NewGame.setPosition(_managers.window.getSize().x * 0.2f, _managers.window.getSize().y * 0.5f);
    Exit.setPosition(NewGame.getPosition().x, NewGame.getPosition().y + 50.0f);
}

void MainMenuState::Cleanup() {

}

void MainMenuState::Pause() {
    
}

void MainMenuState::Resume() {
    activeSelection = 0;
}

void MainMenuState::HandleInput() {
    sf::Event event;
    while (_managers.window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _managers.window.close();
        }
        if(InputManager::IsPressed(Exit, _managers.window)) {
            _managers.window.close();
        }
    }
}

void MainMenuState::Update(float dt) {

}

void MainMenuState::Draw(float dt) {
    _managers.window.clear(GameColor::LightBlue);
    _managers.window.draw(Title);
    _managers.window.draw(NewGame);
    _managers.window.draw(Exit);
    _managers.window.display();
}

