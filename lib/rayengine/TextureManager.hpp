#ifndef RAYENGINE_TEXTUREMANAGER_HPP
#define RAYENGINE_TEXTUREMANAGER_HPP

#include <unordered_map>
#include "raylib.h"

namespace rayengine {

struct TextureManager {
    void load(const char* name, const char* fileName);
    void unload(const char* name);
    Texture2D get(const char* name);
    void unloadAll();

    private:
        std::unordered_map<const char*, Texture2D> textures = {};
};

}

#endif
