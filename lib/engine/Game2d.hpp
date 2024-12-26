#ifndef GAME2D_HPP
#define GAME2D_HPP

#include <string>
#include <optional>

#include "entt.hpp"

namespace engine {

class Game2d {
    public:
        Game2d(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags):
            windowTitle(windowTitle), windowHeight(windowHeight), windowWidth(windowWidth), targetFps(targetFps.value_or(0)), configFlags(configFlags) {};
        Game2d(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps):
            Game2d(windowTitle, windowWidth, windowHeight, targetFps, std::nullopt) {};

        int gameLoop();

        int getWindowHeight() const;
        int getWindowWidth() const;
        int getTargetFps() const;
        int getFrameCounter() const;
        float calcMovementSpeed(float multiplier = 1.0f) const;
    protected:
        virtual void frameCode() = 0;
        virtual void drawFrame() = 0;
        virtual void init() = 0;
        virtual void cleanUp() = 0;

        std::string windowTitle;
        int windowWidth;
        int windowHeight;
        int targetFps;
        int frameTime;
        std::optional<unsigned int> configFlags;
        int frameCounter = 0;

        entt::registry registry = {};
};

}

#endif
