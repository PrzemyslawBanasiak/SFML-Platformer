#include "GameState.hpp"
#include <iostream>
#include "../LevelLoader.hpp"
#include "../GameEngine.hpp"
#include "../Definitions.hpp"

GameState::GameState(std::string level, Managers& managers)
    : _level(level)
    , _managers(managers)
    , _map(managers)
{}

void GameState::Init() {
    LevelLoader loader(FilePaths::Level1);
    _managers.asset.LoadTexture("tileset", JoinUrls(FilePaths::Level1, loader.GetTilesets()[0].image));
    _map.LoadMap(std::move(loader.GetMap()));


    GameObject* p = _map.getPlayer();
    if (!p) {
        return Error("Map doesn't contain Player");
    }
    _camera.SetFollowTarget(p->GetSprite());
    p->SetRigidbody(Custom::make_unique<RigidBody>(*p, _map));
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
    _map.getPlayer()->BeforeUpdate();
    _map.getPlayer()->Update(dt);
    _camera.Update();
}

void GameState::Draw(float dt) {
    _camera.Render(_managers.window);
    _managers.window.clear(GameColor::LightBlue);
    for(const auto& s : _map.getSprites())
        _managers.window.draw(s);
    _managers.window.draw(_map.getPlayer()->GetSprite());
    _managers.window.display();
    
}

