#include <iostream>
#include <fstream>

#include "LevelLoader.hpp"
#include "Lib/json.h"

namespace LoaderStruct {
    void from_json(const nlohmann::json& j, map& m) {
        m.width     = j.at("width").get<int>();
        m.height    = j.at("height").get<int>();
        m.tilewidth = j.at("tilewidth").get<int>();
        m.tileheight= j.at("tileheight").get<int>();
        m.tilesets  = j.at("tilesets").get<std::vector<tileset>>();
        m.layers    = j.at("layers").get<std::vector<layer>>();
    }
    
    void from_json(const nlohmann::json& j, tileset& t) {
        t.name = j.at("name").get<std::string>();
        t.tiles = j.at("tiles").get<std::map<std::string, tile>>();
    }
    
    void from_json(const nlohmann::json& j, tile& t) {
        t.image = j.at("image").get<std::string>();
        t.imagewidth = j.at("imagewidth").get<int>();
        t.imageheight = j.at("imageheight").get<int>();
    }
    
    void from_json(const nlohmann::json& j, layer& l) {
        l.data = j.at("data").get<std::vector<int>>();
        l.name = j.at("name").get<std::string>();
    }
}

LevelLoader::LevelLoader(const std::string& levelFilePath) {
    nlohmann::json j;
    std::ifstream i(levelFilePath);
    i >> j;
    _map = j;
}


const LoaderStruct::map& LevelLoader::GetMap() {
    return _map;
}

const std::vector<LoaderStruct::tileset>& LevelLoader::GetTilesets() {
    return _map.tilesets;
}

const std::vector<LoaderStruct::layer>& LevelLoader::GetLayers() {
    return _map.layers;
}


