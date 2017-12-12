#include "GameState.hpp"
#include "../GameEngine.hpp"
#include "../Definitions.hpp"

GameState::GameState(std::string level, Managers& managers)
    : _managers(managers)
    , _loader(FilePaths::Level1)
{}

void GameState::Init() {
    for(auto tileset: _loader.GetTilesets()) {
        for(auto tile : tileset.tiles) {
            _managers.asset.LoadTexture(tile.first, JoinUrls(FilePaths::Level1, tile.second.image));
        }
    }
    _map.resize(_loader.GetMap().height * _loader.GetMap().width);
    for(auto l: _loader.GetLayers()){
        for(size_t i = 0; i < l.data.size(); ++i) {
            sf::Sprite s;
            s.setPosition((float)(i % _loader.GetMap().width) * 70, (float)((i / _loader.GetMap().width) * 70));
            if(l.data[i] != 0) {
                s.setTexture(_managers.asset.GetTexture(std::to_string(l.data[i]-1)));
            }
            _map[i] = s;
        }
    }
    
    _colliders.resize(_map.size());
    std::transform(_map.begin(), _map.end(), _colliders.begin(), [](const sf::Sprite& s){
        return s.getTexture() != 0;
    });
    
    sf::Sprite player;
    player.setPosition(70, 1260);
    player.setTexture(_managers.asset.GetTexture("31"));
    _player.SetSprite(player);
    _player.SetRigidbody(Custom::make_unique<RigidBody>(_player, _colliders, _loader.GetMap().width));
    _camera.SetFollowTarget(_player.GetSprite());
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
    _player.Update(dt);
    _camera.Update();
}

void GameState::Draw(float dt) {
    _camera.Render(_managers.window);
    _managers.window.clear(GameColor::LightBlue);
    for(auto s : _map)
        _managers.window.draw(s);
    _managers.window.draw(_player.GetSprite());
    _managers.window.display();
    
}

