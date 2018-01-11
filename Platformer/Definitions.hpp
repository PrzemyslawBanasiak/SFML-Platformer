#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

const int screen_width = 1024;
const int screen_height = 768;

namespace GameColor {
    const sf::Color Blue = {48, 60, 116};
    const sf::Color LightBlue = {94, 127, 141};
    const sf::Color DarkBlue = {48, 60, 116};
    
    const sf::Color Green = {132, 161, 54};
    const sf::Color LightGreen = {220, 241, 161};
    const sf::Color DarkGreen = {59, 80, 0};
    
    const sf::Color Red = {157, 52, 75};
    const sf::Color LightRed = {236, 157, 174};
    const sf::Color DarkRed = {79, 0, 17};
}

namespace FilePaths {
#ifdef  __OSX__
    const std::string ResourceDir = "/Users/przemekbanasiak/Projects/Platformer/Platformer/Resources";
#else
    const std::string ResourceDir = "C:\\Users\\zellu\\Desktop\\Projects\\platformer\\Platformer\\Resources";
#endif
    const std::string SplashScreen  = ResourceDir + "/Images/Splash.png";
    const std::string MenuFont      = ResourceDir + "/Fonts/kenvector_future.ttf";
    const std::string UIPack        = ResourceDir + "/Images/UIPack.png";
    const std::string Level1        = ResourceDir + "/Levels/Mapa1.json";
    const std::string Player        = ResourceDir + "/Images/character/sheet/walk_sheet.png";
    const std::string Background    = ResourceDir + "/Images/bg.png";
}

const float SPLASH_SCREEN_TIME = 0.0f;

const float PLAYER_SPEED = 200.0f; //px/s
const float JUMP_SPEED = 320.0f;  //px/s
const float FRAME_TIME = 0.1f;
const int TILE_WIDTH = 128;

std::string JoinUrls(std::string url1, std::string url2);

namespace Physics {
    const sf::Vector2f Gravity = {0.0f, 320.0f};
    const int CharCollWidth = 80;
    const int CharCollHeight = 120;
    const float maxMovePerFrame = 62.0f;
}

namespace Custom {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }
}


enum ColliderType {
    ENone = 0,
    ETerrain,
    EKiller
};

void Info(std::string info);
void Warning(std::string info);
void Error(std::string error);
bool IsError();