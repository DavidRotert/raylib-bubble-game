#include "Game.hpp"
#include "raylib.h"

namespace engine2d {

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps) {
    this->windowTitle = windowTitle;
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
    this->targetFps = targetFps;
}

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, int targetFps, std::optional<unsigned int> configFlags)
: Game(windowTitle, windowWidth, windowHeight, targetFps) {
    this->configFlags = configFlags;
}

int Game::gameLoop() {
    if (this->configFlags.has_value()) {
        SetConfigFlags(this->configFlags.value());
    }
    InitWindow(this->windowWidth, this->windowHeight, windowTitle.c_str());
    SetTargetFPS(this->targetFps);
    this->init();

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

int Game::getWindowHeight() const {
    return this->windowHeight;
}

int Game::getWindowWidth() const {
    return this->windowWidth;
}

int Game::getTargetFps() const {
    return this->targetFps;
}

int Game::getFrameCounter() const {
    return this->frameCounter;
}

float Game::calcMovementSpeed(float multiplier) const {
    return (60.0f / this->getTargetFps()) * multiplier;
}

}
