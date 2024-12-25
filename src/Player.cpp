#include "Player.hpp"
#include "raymath.h"

namespace bubblegame {

const int Player::playerCircleRadius = PLAYER_CIRCLE_RADIUS;

void Player::drawEntity() {
    DrawTextureEx(this->texture, Vector2Subtract(this->position, Vector2{Player::playerCircleRadius, Player::playerCircleRadius}), 0, Player::playerCircleRadius * 2 / this->texture.height, WHITE);
}

void Player::moveUp() {
    const int newY = this->position.y - this->game->calcMovementSpeed(4);
    this->position.y = std::max(Player::playerCircleRadius, newY);
}

void Player::moveDown() {
    const int newY = this->position.y + this->game->calcMovementSpeed(4);
    this->position.y = std::min(newY, this->game->getWindowHeight() - Player::playerCircleRadius);
}

}
