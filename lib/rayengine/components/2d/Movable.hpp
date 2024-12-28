#ifndef RAYENGINE_COMPONENTS_2D_MOVABLE_HPP
#define RAYENGINE_COMPONENTS_2D_MOVABLE_HPP

#include "raylib.h"
#include "raymath.h"

namespace rayengine_2d {

struct Movable {
    virtual void move(Vector2 add) = 0;

    void moveLeftBy(float by) {
        this->move(Vector2{-by, 0});
    }

    void moveRightBy(float by) {
        this->move(Vector2{by, 0});
    }

    void moveUpBy(float by) {
        this->move(Vector2{0, -by});
    }

    void moveDown(float by) {
        this->move(Vector2{0, by});
    }
};

}

#endif
