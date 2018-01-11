#include "MenuButtons.hpp"
#include "Managers/InputManager.hpp"
#include "GameEngine.hpp"
#include "Definitions.hpp"

MenuButtons::MenuButtons(Managers& managers) 
    : _managers(managers) {
    _managers.asset.LoadFont("kenvector", FilePaths::MenuFont);
    _managers.asset.LoadTexture("UIPack", FilePaths::UIPack);
}

void MenuButtons::AddButton(std::string text, float x, float y, std::function<void()> handler) {
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

void MenuButtons::Update() {
    for (auto& button : _buttons) {
        if (InputManager::IsPressed(button.first, _managers.window)) {
            return button.second();
        }
    }
}

void MenuButtons::Draw() {
    for (auto& button : _buttons)
        _managers.window.draw(button.first);
    for (auto& text : _texts)
        _managers.window.draw(text);
}


