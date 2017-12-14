#pragma once
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

namespace LoaderStruct {
    
    struct tile {
        std::string type;
    };
    
    struct tileset {
        int tilecount;
        int columns;
        int margin;
        int spacing;
        int tilewidth;
        int tileheight;
        std::string image;
        std::string name;
        std::map<std::string, tile> tiles;
    };

    struct layerObject {
        int gid;
        int id;
        int x;
        int y;
        int rotation;
        bool visible;
        std::string name;
        std::string type;
    };
     
    struct layer {
        std::vector<int> data;
        std::vector<layerObject> objects;
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
    const std::vector<LoaderStruct::tileset>& GetTilesets(); //only one tileset is supported for now
    const std::vector<LoaderStruct::layer>& GetLayers();
private:
    LoaderStruct::map _map;
};
