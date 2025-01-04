#ifndef RAYENGINE_COMPONENTS_2D_MOVABLECOMPONENT_HPP
#define RAYENGINE_COMPONENTS_2D_MOVABLECOMPONENT_HPP

#include "raylib.h"
#include "raymath.h"

namespace rayengine_2d {

struct MovableComponent {
    virtual void moveTo(Vector2 position) = 0;

    virtual void move(Vector2 by) = 0;

    void moveLeft(float by) {
        this->move(Vector2{-by, 0});
    }

    void moveRight(float by) {
        this->move(Vector2{by, 0});
    }

    void moveUp(float by) {
        this->move(Vector2{0, -by});
    }

    void moveDown(float by) {
        this->move(Vector2{0, by});
    }
};

}

#endif
