#include "Player.hpp"

namespace bubblegame {

Player::Player(const engine2d::Game& game, Vector2 position): Entity(position), game(game) {}

void Player::drawEntity() {
    DrawCircleV(this->position, PLAYER_CIRCLE_RADIUS, MAROON);
}

float Player::calcMovementSpeed() const {
    return (60.0f / this->game.getTargetFps()) * 4;
}

void Player::moveUp() {
    int newY = this->position.y - this->calcMovementSpeed();
    this->position.y = std::max(PLAYER_CIRCLE_RADIUS, newY);
}

void Player::moveDown() {
    int newY = this->position.y + this->calcMovementSpeed();
    this->position.y = std::min(newY, this->game.getWindowHeight() - PLAYER_CIRCLE_RADIUS);
}

}
