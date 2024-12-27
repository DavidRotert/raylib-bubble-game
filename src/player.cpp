#include "./player.hpp"

#include "raylib.h"

#include <iostream>

namespace bubblegame {

entt::entity createPlayerInRegistry(entt::registry& registry, int windowHeight) {
    entt::entity entityId = registry.create();
    Vector2 positionVector = Vector2{PLAYER_COLLISION_RADIUS + PLAYER_POSITION_LEFT_MARGIN, (float) windowHeight / 2};
    registry.emplace<rayengine_2d::Position>(entityId, positionVector);
    registry.emplace<rayengine_2d::CollisionCircle>(entityId, positionVector, PLAYER_COLLISION_RADIUS);

    return entityId;
}

void movePlayerToY(int y, rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision) {
    position.position.y = y;
    collision.center.y = y;
}

void movePlayerUp(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, float frameTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * frameTime;
    float newY = std::max((float) (collision.radius + PLAYER_MAX_POSITION_UPPER_MARGIN), position.position.y - delta);
    std::cout << "New Y (up): " << newY << std::endl;
    movePlayerToY(newY, position, collision);
}

void movePlayerDown(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, int windowHeight, float frameTime) {
    float delta = PLAYER_KEYPRESS_MOVEMENT_SPEED * frameTime;
    float newY = std::min((float) (windowHeight - (collision.radius + PLAYER_MAX_POSITION_LOWER_MARGIN)), position.position.y + delta);
    //float newY = position.position.y + delta;
    std::cout << "New Y (down): " << newY << std::endl;
    movePlayerToY(newY, position, collision);
}

}
