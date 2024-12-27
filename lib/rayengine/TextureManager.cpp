#include "./TextureManager.hpp"

namespace rayengine {

void TextureManager::load(const char* name, const char* fileName) {
    Texture2D texture = LoadTexture(fileName);
    this->textures[name] = texture;
}

void TextureManager::unload(const char* name) {
    UnloadTexture(this->textures[name]);
    this->textures.erase(name);
}

Texture2D TextureManager::get(const char* name) {
    return this->textures[name];
}

void TextureManager::unloadAll() {
    for (auto textureEntry: this->textures) {
        UnloadTexture(textureEntry.second);
    }
    this->textures.clear();
}

}
