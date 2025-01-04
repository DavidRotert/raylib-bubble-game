#ifndef RAYENGINE_COMPONENTS_2D_POSITION_HPP
#define RAYENGINE_COMPONENTS_2D_POSITION_HPP

#include "raylib.h"
#include "./MovableComponent.hpp"

namespace rayengine_2d {

typedef unsigned int z_index;

struct Position: public MovableComponent {
    Position(Vector2 position): position(position) {};
    ~Position() {};

    Vector2 position;

    void moveTo(Vector2 position) override {
        this->position = position;
    }

    void move(Vector2 by) override {
        this->position = Vector2Add(this->position, by);
    }
};

}

#endif
