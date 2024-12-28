#include "./player.hpp"

#include "raylib.h"
#include "raymath.h"

#include "rayengine/components/2d/Moving.hpp"

#include <iostream>

namespace bubblegame {

entt::entity createPlayerInRegistry(entt::registry& registry, int windowHeight) {
    entt::entity entityId = registry.create();
    Vector2 positionVector = Vector2{PLAYER_COLLISION_RADIUS + PLAYER_POSITION_LEFT_MARGIN, (float) windowHeight / 2};
    registry.emplace<Player>(entityId);
    registry.emplace<rayengine_2d::Position>(entityId, positionVector);
    registry.emplace<rayengine_2d::CollisionCircle>(entityId, positionVector, PLAYER_COLLISION_RADIUS);
    registry.emplace<rayengine_2d::Moving<rayengine_2d::Position&, rayengine_2d::CollisionCircle&>>(entityId, registry.get<rayengine_2d::Position>(entityId), registry.get<rayengine_2d::CollisionCircle>(entityId));

    return entityId;
}

void movePlayerToY(float y, rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision) {
    position.position.y = y;
    collision.center.y = y;
}

void movePlayerUp(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, float deltaTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * deltaTime;
    float newY = std::max((float) (collision.radius + PLAYER_MAX_POSITION_UPPER_MARGIN), position.position.y - delta);
    movePlayerToY(newY, position, collision);
}

void movePlayerDown(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, int windowHeight, float deltaTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * deltaTime;
    float newY = std::min(position.position.y + delta, (float) (windowHeight - (collision.radius + PLAYER_MAX_POSITION_LOWER_MARGIN)));
    movePlayerToY(newY, position, collision);
}

void renderPlayer(rayengine_2d::Position& position, rayengine::TextureManager& textureManager) {
    Texture2D playerTexture = textureManager.get("submarine");
    DrawTextureEx(playerTexture, Vector2Subtract(position.position, Vector2{PLAYER_COLLISION_RADIUS, PLAYER_COLLISION_RADIUS}), 0, (PLAYER_COLLISION_RADIUS * 2) / playerTexture.height, WHITE);
}

}
