#ifndef GAME_HPP
#define GAME_HPP

#include <string>

namespace rayengine2d {

class Game {
protected:
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
    int targetFps;
    int frameCounter;
    virtual void frameCode() = 0;
    virtual void drawFrame() = 0;

public:
    Game(std::string windowTitle, int windowWight, int windowHeight, int targetFps);
    Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps, unsigned int configFlags);

    int gameLoop();
};

}

#endif
