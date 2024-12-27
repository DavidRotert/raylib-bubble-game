#include "./CollisionCircle.hpp"

#include "rayengine/utils.hpp"

namespace rayengine_2d {

bool CollisionCircle::checkCollision(Collision& other) {
    if (rayengine::instanceof<CollisionCircle>(other)) {
        CollisionCircle& castedOther = (CollisionCircle&) other;
        return CheckCollisionCircles(castedOther.center, castedOther.radius, this->center, this->radius);
    } else {
        return false;
    }
}

}
