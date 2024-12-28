#include "./BubbleGame.hpp"

#include "raymath.h"

namespace bubblegame {

void BubbleGame::init() {
    this->textureManager.load("player", "resources/submarine.png");

    this->player = Player::create(this->windowHeight);
}

void BubbleGame::frameCode() {
    // Move player
    std::array movementKeys = std::array{(int) KEY_W, (int) KEY_S, (int) KEY_UP, (int) KEY_DOWN};
    int key = GetKeyPressed();
    bool isMovementKey = key != 0 && std::find(movementKeys.begin(), movementKeys.end(), key) != movementKeys.end();
    if (isMovementKey || IsKeyReleased(this->keyPressed)) {
        this->keyPressed = key;
    }

    switch (this->keyPressed) {
        case KEY_W:
        case KEY_UP:
            this->player.moveUp(this->deltaTime);
            break;
        case KEY_S:
        case KEY_DOWN:
            this->player.moveDown(this->windowHeight, this->deltaTime);
            break;
    }

    /*if (this->frameCounter == 0) {
        int radius = GetRandomValue(5, 40);
        int y = GetRandomValue(radius, this->windowHeight - radius);
        float speed = 1 + (GetRandomValue(0, 10) * 0.1);
        this->bubbles.emplace_back(this, Vector2{(float) this->windowWidth + radius, (float) y}, radius, speed);
    }*/
}

void BubbleGame::drawFrame() {
    ClearBackground(SKYBLUE);
    DrawFPS(10, 10);

    int seaFloorHeight = 40;
    DrawRectangle(0, this->getWindowHeight() - seaFloorHeight, this->getWindowWidth(), seaFloorHeight, BROWN);

    DrawCircleV(Vector2{90, 90}, 40, MAROON);

    this->player.render(this->textureManager);
}

void BubbleGame::cleanUp() {

}

}
