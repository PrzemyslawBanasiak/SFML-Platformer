#include "GameState.hpp"
#include "../GameEngine.hpp"
#include "../Definitions.hpp"

GameState::GameState(std::string level, Managers& managers)
    : _managers(managers)
    , _loader(FilePaths::Level1)
    , _player(managers, {0, 0})
{}

void GameState::Init() {
    _managers.asset.LoadTexture("tileset", JoinUrls(FilePaths::Level1, _loader.GetTilesets()[0].image));
    _colliders.resize(_loader.GetMap().height * _loader.GetMap().width);
    for(auto l: _loader.GetLayers()){
        if (l.type == "tilelayer") {
            LoadTileLayer(l);
        } else {
            LoadObjectLayer(l);
        }
    }
    
    //_player.SetRigidbody(Custom::make_unique<RigidBody>(_player, _colliders, _loader.GetMap().width));
   // _camera.SetFollowTarget(_player.GetSprite());
}

void GameState::LoadTileLayer(const LoaderStruct::layer& l) {
    auto tileset = _loader.GetTilesets()[0];
    for (size_t i = 0; i < l.data.size(); ++i) {
        sf::Sprite s;
        s.setPosition((i % _loader.GetMap().width) * tileset.tilewidth,
            (i / _loader.GetMap().width) * tileset.tileheight);
        if (l.data[i] != 0) {
            s.setTexture(_managers.asset.GetTexture("tileset"));
            int tileType = l.data[i] -1;
            s.setTextureRect({tileType % tileset.columns * 130, tileType / tileset.columns * 130,
                tileset.tilewidth, tileset.tileheight});
        }

        if (tileset.tiles[std::to_string(l.data[i])].type == "Terrain")
            _colliders[i] = ETerrain;
        else if (tileset.tiles[std::to_string(l.data[i])].type == "Kill")
            _colliders[i] = EKiller;
        else
            _colliders[i] = ENone; //assuming only one tile can be at given place
        _map.push_back(s);
    }
}

void GameState::LoadObjectLayer(const LoaderStruct::layer& l) {
    for (auto o : l.objects) {
        if (o.type == "Player") {
            _player = Player(_managers, {(float)o.x, (float)o.y});
            _player.SetRigidbody(Custom::make_unique<RigidBody>(_player, _colliders, _loader.GetMap().width));
            _player.SetAnimation(Custom::make_unique<PlayerAnimation>(_player, _managers));
            _camera.SetFollowTarget(_player.GetSprite());
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

