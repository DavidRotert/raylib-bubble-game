#include "./BubbleGame.hpp"

#include "raymath.h"
#include "./player.hpp"

namespace bubblegame {

void BubbleGame::init() {
    this->textureManager.load("submarine", "resources/submarine.png");

    this->playerEntityId = createPlayerInRegistry(this->registry, this->windowHeight);
}

void BubbleGame::frameCode() {
    // Move player
    std::array movementKeys = std::array{(int) KEY_W, (int) KEY_S, (int) KEY_UP, (int) KEY_DOWN};
    int key = GetKeyPressed();
    bool isMovementKey = key != 0 && std::find(movementKeys.begin(), movementKeys.end(), key) != movementKeys.end();
    if (isMovementKey || IsKeyReleased(this->keyPressed)) {
        this->keyPressed = key;
    }

    if (this->keyPressed != 0) {
        auto [playerPosition, playerCollision] = this->registry.get<rayengine_2d::Position, rayengine_2d::CollisionCircle>(this->playerEntityId);

        if (this->keyPressed == KEY_W || this->keyPressed == KEY_UP) {
            movePlayerUp(playerPosition, playerCollision, this->frameTime);
        } else if (this->keyPressed == KEY_S || this->keyPressed == KEY_DOWN) {
            movePlayerDown(playerPosition, playerCollision, this->getWindowHeight(), this->frameTime);
        }
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

    rayengine_2d::Position playerPosition = this->registry.get<rayengine_2d::Position>(this->playerEntityId);
    renderPlayer(playerPosition, this->textureManager);
}

void BubbleGame::cleanUp() {
    this->textureManager.unloadAll();
}

}
