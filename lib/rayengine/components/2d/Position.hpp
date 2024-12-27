#ifndef RAYENGINE_COMPONENTS_2D_POSITION_HPP
#define RAYENGINE_COMPONENTS_2D_POSITION_HPP

#include "raylib.h"

namespace rayengine_2d {

typedef unsigned int z_index;

struct Position {
    Position(Vector2 position): position(position) {};

    Vector2 position;
};

}

#endif
