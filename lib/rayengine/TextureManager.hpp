#ifndef RAYENGINE_TEXTUREMANAGER_HPP
#define RAYENGINE_TEXTUREMANAGER_HPP

#include <unordered_map>
#include <string>
#include "raylib.h"

namespace rayengine {

struct TextureManager {
    void load(const std::string& name, const char* fileName);
    void unload(const std::string& name);
    Texture2D get(const std::string& name);
    void unloadAll();

    private:
        std::unordered_map<std::string, Texture2D> textures = {};
};

}

#endif
