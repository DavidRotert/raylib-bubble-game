#include "Player.hpp"

namespace bubblegame {

Player::Player(engine2d::Game& game, Vector2 pos): Entity(pos), game(game) {}

void Player::drawEntity() {
    DrawCircleV(this->pos, PLAYER_CIRCLE_RADIUS, MAROON);
}

void Player::moveUp() {
    int newY = this->pos.y - KEYPRESS_MOVEMENT_SPEED;
    this->pos.y = std::max(PLAYER_CIRCLE_RADIUS, newY);
}

void Player::moveDown() {
    int newY = this->pos.y + KEYPRESS_MOVEMENT_SPEED;
    this->pos.y = std::min(newY, this->game.getWindowHeight() - PLAYER_CIRCLE_RADIUS);
}

}
