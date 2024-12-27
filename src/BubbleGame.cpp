#include "./BubbleGame.hpp"

#include "raymath.h"
#include "./player.hpp"

namespace bubblegame {

void BubbleGame::init() {
    this->textures.load("submarine", "resources/submarine.png");

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
            movePlayerUp(playerPosition, playerCollision);
        } else if (this->keyPressed == KEY_S || this->keyPressed == KEY_DOWN) {
            movePlayerDown(playerPosition, playerCollision, this->getWindowHeight());
        }
    }
}

void BubbleGame::drawFrame() {
    ClearBackground(SKYBLUE);
    DrawFPS(10, 10);

    int seaFloorHeight = 40;
    DrawRectangle(0, this->getWindowHeight() - seaFloorHeight, this->getWindowWidth(), seaFloorHeight, BROWN);

    DrawCircleV(Vector2{90, 90}, 40, MAROON);

    auto [playerPosition, playerCollision] = this->registry.get<rayengine_2d::Position, rayengine_2d::CollisionCircle>(this->playerEntityId);

    Texture2D playerTexture = this->textures.get("submarine");
    DrawTextureEx(playerTexture, Vector2Subtract(playerPosition.position, Vector2{PLAYER_COLLISION_RADIUS, PLAYER_COLLISION_RADIUS}), 0, (PLAYER_COLLISION_RADIUS * 2) / playerTexture.height, WHITE);
}

void BubbleGame::cleanUp() {
    this->textures.unloadAll();
}

}
