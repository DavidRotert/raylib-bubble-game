#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <optional>

namespace engine2d {

class Game {
    public:
        Game(std::string windowTitle, int windowWight, int windowHeight, std::optional<int> targetFps);
        Game(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags);

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
        std::optional<unsigned int> configFlags = std::nullopt;
        int frameCounter = 0;
};

}

#endif
