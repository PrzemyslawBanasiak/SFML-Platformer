#include "InputManager.hpp"

using namespace sf;

Vector2f InputManager::GetInputAxis() {
    Vector2f in(0,0);
    if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
        in += {0, -1};
    if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
        in += {0, 1};
    if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
        in += {-1, 0};
    if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        in += {1, 0};
    return in;
}
