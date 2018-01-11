#include <iostream>
#include "../Definitions.hpp"
#include "../GameEngine.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

MainMenuState::MainMenuState(Managers& managers) 
    : _managers(managers)
    , _background(managers) {
}

void MainMenuState::Init() {
    _managers.asset.LoadFont("kenvector", FilePaths::MenuFont);
    _managers.asset.LoadTexture("UIPack", FilePaths::UIPack);

    SpawnButton("New Game", 0.2f, 0.5f, [&]() {
        _managers.state.ChangeState(std::unique_ptr<State>(new GameState("level1", _managers)));
    });


    SpawnButton("Exit", 0.2f, 0.6f, [&]() {
        _managers.window.close();
    });

    sf::Text Title;
    Title.setFont(_managers.asset.GetFont("kenvector"));
    Title.setString("Platformer");
    Title.setOrigin(Title.getGlobalBounds().width/2, Title.getGlobalBounds().height/2);    
    Title.setPosition(_managers.window.getSize().x * 0.5f, _managers.window.getSize().y * 0.1f);
    _texts.push_back(Title);
}

void MainMenuState::SpawnButton(std::string text, float x, float y, std::function<void()> handler) {
    sf::Text ButtonText;
    sf::Sprite Button;

    ButtonText.setFont(_managers.asset.GetFont("kenvector"));
    ButtonText.setString(text);
    ButtonText.setOrigin(ButtonText.getGlobalBounds().width / 2, ButtonText.getGlobalBounds().height / 2);
    ButtonText.setPosition(_managers.window.getSize().x * x, _managers.window.getSize().y * y - 15);

    Button.setTexture(_managers.asset.GetTexture("UIPack"));
    Button.setTextureRect({190, 45, 190, 49});
    Button.setOrigin(Button.getGlobalBounds().width / 2, Button.getGlobalBounds().height / 2);
    Button.setScale({1.2f, 1.0f});
    Button.setPosition(_managers.window.getSize().x * x, _managers.window.getSize().y * y);

    _texts.push_back(ButtonText);
    _buttons.push_back({Button, handler});
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
        if(event.mouseButton.button == sf::Mouse::Left) {
            for (auto& button : _buttons) {
                if (InputManager::IsPressed(button.first, _managers.window)) {
                    button.second();
                    return;
                }
            }
        }
    }
}

void MainMenuState::Update(float dt) {

}

void MainMenuState::Draw(float dt) {
    _background.Draw();
    for (auto& button : _buttons)
        _managers.window.draw(button.first);
    for (auto& text : _texts)
        _managers.window.draw(text);
    _managers.window.display();
}

