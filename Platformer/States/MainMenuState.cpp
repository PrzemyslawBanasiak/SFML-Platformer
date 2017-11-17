#include "../Definitions.hpp"
#include "MainMenuState.hpp"

MainMenuState::MainMenuState(Managers& managers) : _managers(managers){
}

void MainMenuState::Init() {
    
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

}

void MainMenuState::Draw(float dt) {
    _managers.window.clear(GameColor::LightBlue);
    _managers.window.display();
}

