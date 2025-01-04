#ifndef RAYENGINE_COMPONENTS_2D_ABSTRACTCOLLISION_HPP
#define RAYENGINE_COMPONENTS_2D_ABSTRACTCOLLISION_HPP

namespace rayengine_2d {

struct AbstractCollision {
    virtual bool checkCollision(AbstractCollision& other) = 0;
};

}

#endif
