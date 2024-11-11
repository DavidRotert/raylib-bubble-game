#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <optional>

namespace engine2d {

class Game {
    protected:
        std::string windowTitle;
        int windowWidth;
        int windowHeight;
        int targetFps;
        std::optional<unsigned int> configFlags = std::nullopt;

        int frameCounter = 0;
        
        virtual void frameCode() = 0;
        virtual void drawFrame() = 0;

    public:
        Game(std::string windowTitle, int windowWight, int windowHeight, int targetFps);
        Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps, std::optional<unsigned int> configFlags);

        int gameLoop();
};

}

#endif
