#ifndef POSITION2D_COMPONENT_HPP
#define POSITION2D_COMPONENT_HPP

#include "raylib.h"

namespace engine {

struct Position2d {
    Vector2 position;

    Position2d(Vector2 position): position(position) {};
};

}

#endif
