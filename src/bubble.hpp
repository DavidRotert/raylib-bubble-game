#ifndef BUBBLEGAME_BUBBLE_HPP
#define BUBBLEGAME_BUBBLE_HPP

#include "entt.hpp"

#include "rayengine/components/2d/Position.hpp"
#include "rayengine/components/2d/CollisionCircle.hpp"

namespace bubblegame {

struct Bubble {};

entt::entity spawnBubble(entt::registry& registry, int windowHeight, int windowWidth);

}

#endif
