#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager {
public:
    void LoadTexture(const std::string& name, const std::string& filePath);
    void LoadAudio(const std::string& name, const std::string& filePath);
    void LoadFont(const std::string& name, const std::string& filePath);
    
    sf::Texture& GetTexture(const std::string& name);
    sf::Font& GetFont(const std::string& name);
    sf::Sound& GetAudio(const std::string& name);
private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Sound> _sounds;
    std::map<std::string, sf::Font> _fonts;
};
