#ifndef RAYENGINE_COMPONENTS_2D_COLLISIONCIRCLE_HPP
#define RAYENGINE_COMPONENTS_2D_COLLISIONCIRCLE_HPP

#include "./AbstractCollision.hpp"
#include "./MovableComponent.hpp"
#include "raylib.h"

namespace rayengine_2d {

struct CollisionCircle: public AbstractCollision, public MovableComponent {
    CollisionCircle(Vector2 center, float radius): center(center), radius(radius) {};

    bool checkCollision(AbstractCollision& other) override;

    void moveTo(Vector2 position) override {
        this->center = position;
    }

    void move(Vector2 by) override {
        this->center = Vector2Add(this->center, by);
    }

    Vector2 center;
    float radius;
};

}

#endif
