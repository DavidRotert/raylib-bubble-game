#include "Game.hpp"
#include "raylib.h"

namespace rayengine2d {

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps) {
    this->windowTitle = windowTitle;
    this->windowHeight = 400;
    this->windowWidth = 800;
    this->targetFps = 60;

    InitWindow(this->windowWidth, this->windowHeight, windowTitle.c_str());
    SetTargetFPS(this->targetFps);
}

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps, unsigned int configFlags) {
    this->windowTitle = windowTitle;
    this->windowHeight = 400;
    this->windowWidth = 800;
    this->targetFps = 60;

    SetConfigFlags(configFlags);
    InitWindow(this->windowWidth, this->windowHeight, windowTitle.c_str());
    SetTargetFPS(this->targetFps);
}

int Game::gameLoop() {
    while (!WindowShouldClose()) {
        this->frameCode();

        BeginDrawing();
        this->drawFrame();
        EndDrawing();

        this->frameCounter = (this->frameCounter + 1) % this->targetFps;
    }

    CloseWindow();
    return 0;
}

}
