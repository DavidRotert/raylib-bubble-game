#ifndef RAYENGINE_COMPONENTS_2D_COLLISION_HPP
#define RAYENGINE_COMPONENTS_2D_COLLISION_HPP

namespace rayengine_2d {

enum CollisionType : unsigned char {
    RECTANGLE,
    CIRCLE
};

struct Collision {
    virtual bool checkCollision(Collision& other) = 0;
};

}

#endif
