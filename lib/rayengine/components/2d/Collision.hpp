#ifndef RAYENGINE_COMPONENTS_2D_COLLISION_HPP
#define RAYENGINE_COMPONENTS_2D_COLLISION_HPP

namespace rayengine_2d {

struct Collision {
    virtual bool checkCollision(Collision& other) = 0;
};

}

#endif
