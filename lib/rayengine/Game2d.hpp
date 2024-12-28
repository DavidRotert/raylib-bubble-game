#ifndef RAYENGINE_GAME2D_HPP
#define RAYENGINE_GAME2D_HPP

#include <string>
#include <optional>

#include "entt.hpp"
#include "raylib.h"

#include "./TextureManager.hpp"

namespace rayengine {

class Game2d {
    public:
        Game2d(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags):
            windowTitle(windowTitle), configFlags(configFlags), windowWidth(windowWidth), windowHeight(windowHeight), targetFps(targetFps.value_or(0)) {};
        Game2d(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps):
            Game2d(windowTitle, windowWidth, windowHeight, targetFps, std::nullopt) {};

        int gameLoop();

        int getWindowHeight() const;
        int getWindowWidth() const;
        int getTargetFps() const;
        int getFrameCounter() const;
        float calcMovementSpeed(float multiplier = 1.0f) const;
    protected:
        virtual void init() = 0;
        virtual void frameCode() = 0;
        virtual void drawFrame() = 0;
        virtual void cleanUp() = 0;

        entt::registry registry = {};
        TextureManager textureManager = {};
        std::string windowTitle;
        std::optional<unsigned int> configFlags;
        int windowWidth;
        int windowHeight;
        int targetFps;
        float deltaTime;
        int frameCounter = 0;
};

}

#endif
