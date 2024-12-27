#ifndef BUBBLEGAME_PLAYER_HPP
#define BUBBLEGAME_PLAYER_HPP

#define PLAYER_COLLISION_RADIUS 30
#define PLAYER_MAX_POSITION_UPPER_MARGIN 0
#define PLAYER_MAX_POSITION_LOWER_MARGIN 0
#define PLAYER_POSITION_LEFT_MARGIN 30
#define PLAYER_KEYPRESS_MOVEMENT_SPEED 0.5

#include "entt.hpp"

#include "rayengine/components/2d/Position.hpp"
#include "rayengine/components/2d/CollisionCircle.hpp"

namespace bubblegame {

entt::entity createPlayerInRegistry(entt::registry& registry, int windowHeight);

void movePlayerToY(int y, rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision);

void movePlayerUp(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, float frameTime = 1);

void movePlayerDown(rayengine_2d::Position& position, rayengine_2d::CollisionCircle& collision, int windowHeight, float frameTime = 1);

void renderPlayer();
}

#endif
