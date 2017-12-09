#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace GameColor {
    const sf::Color Blue = {48, 60, 116};
    const sf::Color LightBlue = {48, 60, 116};
    const sf::Color DarkBlue = {48, 60, 116};
    
    const sf::Color Green = {132, 161, 54};
    const sf::Color LightGreen = {220, 241, 161};
    const sf::Color DarkGreen = {59, 80, 0};
    
    const sf::Color Red = {157, 52, 75};
    const sf::Color LightRed = {236, 157, 174};
    const sf::Color DarkRed = {79, 0, 17};
}

namespace FilePaths {
    const std::string ResourceDir   = "/Users/przemekbanasiak/Projects/Platformer/Platformer/Resources";
    const std::string SplashScreen  = ResourceDir + "/Images/Splash.png";
    const std::string MenuFont      = ResourceDir + "/Fonts/VCR_OSD_MONO.ttf";
    const std::string Level1        = ResourceDir + "/Levels/Mapa1.json";
}

const float SPLASH_SCREEN_TIME = 0.0f;
const float PLAYER_SPEED = 10.0f;

std::string JoinUrls(std::string url1, std::string url2);

namespace Physics {
    const sf::Vector2f Gravity = {0.0f, 98.0f};
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
