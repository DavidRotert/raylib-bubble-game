#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"

namespace engine2d {

struct Entity {
    Vector2 pos;

    Entity(Vector2 pos);
    
    virtual void drawEntity() = 0;
};

}

#endif
