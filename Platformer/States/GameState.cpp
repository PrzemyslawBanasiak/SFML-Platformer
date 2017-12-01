#include "GameState.hpp"
#include "../GameEngine.hpp"
#include "../Definitions.hpp"

GameState::GameState(std::string level, Managers& managers)
    : _managers(managers)
    , _loader(FilePaths::Level1)
{
    
}

void GameState::Init() {
    int max = 0;
    for(auto tileset: _loader.GetTilesets()) {
        for(auto tile : tileset.tiles) {
            _managers.asset.LoadTexture(tile.first, tile.second.image);
        }
    }
    
    
    
    _sprites.resize(max);
    for(auto tileset: _loader.GetTilesets()) {
        for(auto tile : tileset.tiles) {
            _sprites[stoi(tile.first)] = sf::Sprite();
        }
    }
    
}

void GameState::Cleanup() {
    
}

void GameState::Pause() {
    
}

void GameState::Resume() {
    
}

void GameState::HandleInput() {
    sf::Event event;
    while (_managers.window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            _managers.window.close();
        }
    }
}

void GameState::Update(float dt) {
    
}

void GameState::Draw(float dt) {
    
}

