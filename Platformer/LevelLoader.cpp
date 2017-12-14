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
        t.tilecount = j.at("tilecount").get<int>();
        t.columns = j.at("columns").get<int>();
        t.margin = j.at("margin").get<int>();
        t.spacing = j.at("spacing").get<int>();
        t.tilewidth = j.at("tilewidth").get<int>();
        t.tileheight = j.at("tileheight").get<int>();

        t.image = j.at("image").get<std::string>();
        t.name = j.at("name").get<std::string>();
        t.tiles = j.at("tiles").get<std::map<std::string, tile>>();
    }

    void from_json(const nlohmann::json& j, layerObject& l) {
        l.x = j.at("x").get<int>();
        l.y = j.at("y").get<int>();
        l.id = j.at("id").get<int>();
        l.gid = j.at("gid").get<int>();
        l.visible = j.at("visible").get<bool>();
        l.rotation = j.at("rotation").get<int>();
        l.name = j.at("name").get<std::string>();
        l.type = j.at("type").get<std::string>();
    }
    
    void from_json(const nlohmann::json& j, layer& l) {
        l.name = j.at("name").get<std::string>();
        l.type = j.at("type").get<std::string>();
        if (j.find("data") != j.end())
            l.data = j.at("data").get<std::vector<int>>();
        if (j.find("objects") != j.end())
            l.objects = j.at("objects").get<std::vector<layerObject>>();
    }

    void from_json(const nlohmann::json& j, tile& t) {
        t.type = j.at("type").get<std::string>();
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


