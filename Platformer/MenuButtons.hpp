#pragma once
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>

struct Managers;

class MenuButtons {
public:
    MenuButtons(Managers& managers);
    void AddButton(std::string text, float x, float y, std::function<void()> handler);

    void Update();
    void Draw();
private:
    Managers& _managers;

    std::vector<sf::Text> _texts;
    std::vector<std::pair<sf::Sprite, std::function<void()>>> _buttons;
};

