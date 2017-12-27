#include "AssetManager.hpp"

void AssetManager::LoadTexture(const std::string& name, const std::string& filePath) {
    if(_textures.find(name) != _textures.end()) {
        return;
    }
    
    sf::Texture tex;
    if(tex.loadFromFile(filePath)) {
        _textures[name] = tex;
    }
}

void AssetManager::LoadAudio(const std::string& name, const std::string& filePath) {
    if(_sounds.find(name) != _sounds.end()) {
        return;
    }
    
    sf::SoundBuffer sb;
    sf::Sound sound;
    if(sb.loadFromFile(filePath)) {
        sound.setBuffer(sb);
        _sounds[name] = sound;
    }
}

void AssetManager::LoadFont(const std::string& name, const std::string& filePath) {
    if(_fonts.find(name) != _fonts.end()) {
        return;
    }
    
    sf::Font font;
    if(font.loadFromFile(filePath)) {
        _fonts[name] = font;
    }
}

sf::Texture& AssetManager::GetTexture(const std::string& name) {
    return _textures.at(name);
}

sf::Font& AssetManager::GetFont(const std::string& name) {
    return _fonts.at(name);
}

sf::Sound& AssetManager::GetAudio(const std::string& name) {
    return _sounds.at(name);
}
