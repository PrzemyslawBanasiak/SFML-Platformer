#pragma once
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

namespace LoaderStruct {
    
    struct tile {
        std::string image;
        int imageheight;
        int imagewidth;
    };
    
    struct tileset {
        int tilecount;
        std::string name;
        std::map<std::string, tile> tiles;
    };
     
    struct layer {
        std::vector<int> data;
        std::string name;
        std::string type;
    };
    
    struct map {
        int width;
        int height;
        int tilewidth;
        int tileheight;
        std::string orientation;
        std::vector<layer> layers;
        std::vector<tileset> tilesets;
    };
}

class LevelLoader {
public:
    LevelLoader(const std::string& levelFilePath);
    const LoaderStruct::map& GetMap();
    const std::vector<LoaderStruct::tileset>& GetTilesets();
    const std::vector<LoaderStruct::layer>& GetLayers();
private:
    LoaderStruct::map _map;
};
