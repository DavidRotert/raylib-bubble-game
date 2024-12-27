#include "./Game2d.hpp"
#include "raylib.h"

namespace rayengine {

int Game2d::gameLoop() {
    if (this->configFlags.has_value()) {
        SetConfigFlags(this->configFlags.value());
    }
    InitWindow(this->windowWidth, this->windowHeight, windowTitle.c_str());
    if (this->targetFps >= 0) {
        SetTargetFPS(this->targetFps);
    }
    this->init();

    BeginDrawing();
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

int Game2d::getWindowHeight() const {
    return this->windowHeight;
}

int Game2d::getWindowWidth() const {
    return this->windowWidth;
}

int Game2d::getTargetFps() const {
    return this->targetFps;
}

int Game2d::getFrameCounter() const {
    return this->frameCounter;
}

float Game2d::calcMovementSpeed(float multiplier) const {
    return (this->frameTime <= 0 ? 1: this->frameTime) * multiplier;
}

}
