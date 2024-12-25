#include "Game.hpp"
#include "raylib.h"

namespace engine2d {

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps) {
    this->windowTitle = windowTitle;
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
    this->targetFps = targetFps.value_or(0);
}

Game::Game(std::string windowTitle, int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags)
: Game(windowTitle, windowWidth, windowHeight, targetFps) {
    this->configFlags = configFlags;
}

int Game::gameLoop() {
    if (this->configFlags.has_value()) {
        SetConfigFlags(this->configFlags.value());
    }
    InitWindow(this->windowWidth, this->windowHeight, windowTitle.c_str());
    if (this->targetFps <= 0) {
        SetTargetFPS(this->targetFps);
    }
    this->init();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    EndDrawing();

    while (!WindowShouldClose()) {
        this->frameCode();

        BeginDrawing();
        this->drawFrame();
        EndDrawing();

        this->targetFps = GetFPS();
        this->frameCounter = (this->frameCounter + 1) % this->targetFps;
        this->frameTime = GetFrameTime();
    }

    this->cleanUp();

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
    return (this->frameTime <= 0 ? 1: this->frameTime) * multiplier;
}

}
