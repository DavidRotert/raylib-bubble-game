#include <iostream>

#include "raylib.h"

#include "BubbleGame.hpp"

namespace bubblegame {

BubbleGame::BubbleGame()
: engine2d::Game("Bubble Game", BUBBLEGAME_WINDOW_WIDTH, BUBBLEGAME_WINDOW_HEIGHT, BUBBLEGAME_FPS, FLAG_MSAA_4X_HINT),
player(Player(*this, Vector2{PLAYER_CIRCLE_RADIUS + 30, BUBBLEGAME_WINDOW_HEIGHT / 2})) {
    this->bubbles.reserve(10);
}

void BubbleGame::init() {
    SetMousePosition(BUBBLEGAME_WINDOW_WIDTH / 2, BUBBLEGAME_WINDOW_HEIGHT / 2);
    HideCursor();
    SetWindowFocused();
}

void BubbleGame::frameCode() {
    // Move player
    if (IsKeyPressed(KEY_W) || IsKeyPressedRepeat(KEY_W)) {
        this->player.moveUp();
    } else if (IsKeyPressed(KEY_S) || IsKeyPressedRepeat(KEY_S)) {
        this->player.moveDown();
    }

    // Move bubbles
    for (Bubble& bubble: this->bubbles) {
        bubble.move();
    }

    // Despawn bubbles
    std::erase_if(this->bubbles, [](Bubble& bubble) {
        return bubble.pos.x < -bubble.radius;
    });

    // Spawn bubbles
    if (this->frameCounter == 0) {
        int radius = (rand() % 40) + 5;
        int y = (rand() % (this->windowHeight - radius)) + radius;
        this->bubbles.emplace_back(this, Vector2{(float) this->windowWidth + radius, (float) y}, radius);
    }
}

void BubbleGame::drawFrame() {
    ClearBackground(SKYBLUE);

    for (Bubble& bubble: this->bubbles) {
        bubble.drawEntity();
    }

    this->player.drawEntity();
}

}
