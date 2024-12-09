#include <iostream>
#include <algorithm>
#include <array>

#include "raylib.h"

#include "BubbleGame.hpp"

namespace bubblegame {

BubbleGame::BubbleGame(int windowWidth, int windowHeight, int targetFps)
: engine2d::Game("Bubble Game", windowWidth, windowHeight, targetFps, FLAG_MSAA_4X_HINT),
player(Player(*this, Vector2{PLAYER_CIRCLE_RADIUS + 30, (float) windowHeight / 2})) {
    this->bubbles.reserve(20);
}

void BubbleGame::init() {
    SetMousePosition(this->getWindowWidth() / 2, this->getWindowHeight() / 2);
    DisableCursor();
    SetWindowFocused();
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
        if (this->keyPressed == KEY_W || this->keyPressed == KEY_UP) {
            this->player.moveUp();
        } else if (this->keyPressed == KEY_S || this->keyPressed == KEY_DOWN) {
            this->player.moveDown();
        }
    }

    // Move bubbles
    for (Bubble& bubble: this->bubbles) {
        bubble.move();
    }

    // Despawn bubbles
    std::erase_if(this->bubbles, [](Bubble& bubble) {
        return bubble.position.x < -bubble.radius;
    });

    // Spawn bubbles
    if (this->frameCounter == 0) {
        int radius = GetRandomValue(5, 40);
        int y = GetRandomValue(radius, this->windowHeight - radius);
        float speed = 1 + (GetRandomValue(0, 10) * 0.1);
        this->bubbles.emplace_back(this, Vector2{(float) this->windowWidth + radius, (float) y}, radius, speed);
    }
}

void BubbleGame::drawFrame() {
    ClearBackground(SKYBLUE);

    int seaFloorHeight = 40;
    DrawRectangle(0, this->getWindowHeight() - seaFloorHeight, this->getWindowWidth(), seaFloorHeight, BROWN);

    for (Bubble& bubble: this->bubbles) {
        bubble.drawEntity();
    }

    this->player.drawEntity();
}

}
