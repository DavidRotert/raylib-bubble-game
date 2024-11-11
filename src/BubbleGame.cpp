#include "raylib.h"
#include "BubbleGame.hpp"

namespace bubblegame {

BubbleGame::BubbleGame():
rayengine2d::Game("Bubble Game", BUBBLEGAME_WINDOW_WIDTH, BUBBLEGAME_WINDOW_HEIGHT, BUBBLEGAME_FPS) {}

void BubbleGame::frameCode() {
    if (this->circlePositionY < (this->windowHeight - this->circleRadius - 1)) {
        this->circlePositionY += (this->animationDeltaPerSecond / this->targetFps);
    } else {
        this->circlePositionY = this->circleRadius;
    }
}

void BubbleGame::drawFrame() {
    ClearBackground(RAYWHITE);
    DrawCircle(this->circleRadius + this->circleMarginLeft, this->circlePositionY, this->circleRadius, MAROON);
}

}
