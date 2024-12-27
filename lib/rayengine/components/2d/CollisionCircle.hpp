#ifndef RAYENGINE_COMPONENTS_2D_COLLISIONCIRCLE_HPP
#define RAYENGINE_COMPONENTS_2D_COLLISIONCIRCLE_HPP

#include "./Collision.hpp"
#include "raylib.h"

namespace rayengine_2d {

struct CollisionCircle: public Collision {
    CollisionCircle(Vector2 center, float radius): center(center), radius(radius) {};

    bool checkCollision(Collision& other) override;

    Vector2 center;
    float radius;
};

}

#endif