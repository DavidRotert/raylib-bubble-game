#ifndef RAYENGINE_COMPONENTS_2D_POSITION_HPP
#define RAYENGINE_COMPONENTS_2D_POSITION_HPP

#include "raylib.h"
#include "./Movable.hpp"

namespace rayengine_2d {

typedef unsigned int z_index;

struct Position: public Movable {
    Position(Vector2 position): position(position) {};
    ~Position() {};

    Vector2 position;

    virtual void move(Vector2 add) override {
        Vector2Add(this->position, add);
    }
};

}

#endif
