#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "raylib.h"

namespace engine2d {

struct Entity {
    Vector2 position;

    Entity(Vector2 position);
    virtual ~Entity() {};
    
    virtual void drawEntity() = 0;
};

}

#endif
