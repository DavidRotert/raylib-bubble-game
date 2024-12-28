#include "./Player.hpp"

namespace bubblegame {

Player Player::create(int windowHeight) {
    return Player(Vector2{PLAYER_COLLISION_RADIUS + PLAYER_POSITION_LEFT_MARGIN, (float) windowHeight / 2});
}

void Player::moveUp(float deltaTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * deltaTime;
    float newY = std::max((float) (this->collisionComponent.radius + PLAYER_MAX_POSITION_UPPER_MARGIN), this->positionComponent.position.y - delta);
    this->setPosition(Vector2{this->positionComponent.position.x, newY});
}

void Player::moveDown(int windowHeight, float deltaTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * deltaTime;
    float newY = std::min(this->positionComponent.position.y + delta, (float) (windowHeight - (this->collisionComponent.radius + PLAYER_MAX_POSITION_LOWER_MARGIN)));
    this->setPosition(Vector2{this->positionComponent.position.x, newY});
}

void Player::render(rayengine::TextureManager& textureManager) {
    Texture2D playerTexture = textureManager.get("player");
    DrawTextureEx(playerTexture, Vector2Subtract(this->positionComponent.position, Vector2{this->collisionComponent.radius, this->collisionComponent.radius}), 0, (this->collisionComponent.radius * 2) / playerTexture.height, WHITE);
}

}
