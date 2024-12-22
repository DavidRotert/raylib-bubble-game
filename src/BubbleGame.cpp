#include <iostream>
#include <algorithm>
#include <array>
#include <optional>
#include <format>
#include <ctime>

#include "raylib.h"

#include "BubbleGame.hpp"

namespace bubblegame {

BubbleGame::BubbleGame(int windowWidth, int windowHeight, std::optional<int> targetFps, std::optional<unsigned int> configFlags)
: engine2d::Game("Bubble Game", windowWidth, windowHeight, targetFps, configFlags),
player(Player(*this, Vector2{PLAYER_CIRCLE_RADIUS + 30, (float) windowHeight / 2})) {
    this->bubbles.reserve(25);
}

void BubbleGame::init() {
    SetMousePosition(this->getWindowWidth() / 2, this->getWindowHeight() / 2);
    SetWindowFocused();

    this->endTime = std::time(nullptr) + 120;
}

void BubbleGame::frameCode() {
    time_t timeLeft = this->endTime - std::time(nullptr);
    if (timeLeft <= 0) {
        return;
    }

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

    // Despawn bubbles and handle collision
    std::erase_if(this->bubbles, [this](Bubble& bubble) {
        bool bubbleIsOutsideOfScreen = bubble.position.x < -bubble.radius;

        bool bubbleCollidedWithPlayer = CheckCollisionCircles(this->player.position, PLAYER_CIRCLE_RADIUS, bubble.position, bubble.radius);
        if (bubbleCollidedWithPlayer) {
            this->points += bubble.radius / 5 + bubble.speed / 2;
        }

        return bubbleIsOutsideOfScreen || bubbleCollidedWithPlayer;
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
    time_t timeLeft = this->endTime - std::time(nullptr);
    if (timeLeft <= 0) {
        ClearBackground(SKYBLUE);

        std::string gameOverText = std::format("Game Over!\nPoints: {}", this->points);
        const char* gameOverTextChar_p = gameOverText.c_str();
        int gameOverFontSize = 50;
        DrawText(gameOverTextChar_p, this->windowWidth / 2 - (MeasureText(gameOverTextChar_p, gameOverFontSize) / 2), this->windowHeight / 2 - gameOverFontSize, gameOverFontSize, RED);

        return;
    }

    ClearBackground(SKYBLUE);

    int seaFloorHeight = 40;
    DrawRectangle(0, this->getWindowHeight() - seaFloorHeight, this->getWindowWidth(), seaFloorHeight, BROWN);

    for (Bubble& bubble: this->bubbles) {
        bubble.drawEntity();
    }

    this->player.drawEntity();

    DrawFPS(10, 10);

    int fontSize = 30;

    std::string pointsText = std::format("Points: {}", this->points);
    const char* pointsTextChar_p = pointsText.c_str();
    DrawText(pointsTextChar_p, this->windowWidth / 2 - (MeasureText(pointsTextChar_p, fontSize) / 2), 10, fontSize, WHITE);
    
    std::string timeLeftText = std::format("Time left: {}", timeLeft);
    const char* timeLeftTextChar_p = timeLeftText.c_str();
    DrawText(timeLeftTextChar_p, this->windowWidth - MeasureText(timeLeftTextChar_p, fontSize) - 10, 10, fontSize, WHITE);
}

}
