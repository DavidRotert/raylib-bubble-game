#include "./TextureManager.hpp"

namespace rayengine {

void TextureManager::load(const std::string& name, const char* fileName) {
    Texture2D texture = LoadTexture(fileName);
    this->textures[name] = texture;
}

void TextureManager::unload(const std::string& name) {
    UnloadTexture(this->textures[name]);
    this->textures.erase(name);
}

Texture2D TextureManager::get(const std::string& name) {
    auto tex = this->textures.at(name);
    return tex;
}

void TextureManager::unloadAll() {
    for (auto textureEntry: this->textures) {
        UnloadTexture(textureEntry.second);
    }
    this->textures.clear();
}

}
