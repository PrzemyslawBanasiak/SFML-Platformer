#include "PauseState.hpp"
#include "../GameEngine.hpp"
#include "MainMenuState.hpp"
#include "../Definitions.hpp"

PauseState::PauseState(Managers& managers)
    : _managers(managers)
    , _menuButtons(managers) {

}

void PauseState::Init() {
    _texture.loadFromImage(_managers.window.capture());
    _background.setTexture(_texture);
    _menuButtons.AddButton("Continue", 0.5f, 0.5f, [&]() {
        _managers.state.PopState();
    });

    _menuButtons.AddButton("Main Menu", 0.5f, 0.6f, [&]() {
        _managers.state.ReplaceStates(std::unique_ptr<State>(new MainMenuState(_managers)));
    });

    _menuButtons.AddButton("Exit", 0.5f, 0.7f, [&]() {
        _managers.window.close();
    });

    _managers.window.setView(sf::View({0, 0, (float)screen_width,  (float)screen_height}));
}

void PauseState::Cleanup() {}
void PauseState::Pause() {}
void PauseState::Resume() {}

void PauseState::HandleInput() {
    sf::Event event;
    while (_managers.window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _managers.window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _managers.state.PopState();
            break;
        }
    }
}

void PauseState::Update(float dt) {
    _menuButtons.Update();
}

void PauseState::Draw(float dt) {
    _managers.window.clear();
    _managers.window.draw(_background);
    _menuButtons.Draw();
    _managers.window.display();
}